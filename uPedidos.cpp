//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uPedidos.h"
#include "uIngresarPedido.h"
#include "uBuscarCliente.h"
#include "uBuscarArticulo.h"
#include "VariablesGlobales.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma resource "*.dfm"
TfPedidos *fPedidos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfPedidos::TfPedidos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfPedidos::buscar(String orden)
{
	  String q = "SELECT *, "
				 "(SELECT razonSocial AS cliente FROM clientes WHERE clientes.idCliente = pedidos.refCliente LIMIT 1) AS cliente, "
				 "(SELECT descripcion FROM estadospedidos WHERE estadospedidos.idEstadoPedido = pedidos.refEstadoPedido LIMIT 1) AS estadoPedido "
				 "FROM pedidos ";

	  if(RG1->ItemIndex == 1)
		 q = q + " WHERE refEstadoPedido = 1 ";
	  else if(RG1->ItemIndex == 2)
		 q = q + " WHERE refEstadoPedido = 2 ";
	  else if(RG1->ItemIndex == 3)
		 q = q + " WHERE refEstadoPedido = 3 ";
	  else if(RG1->ItemIndex == 4)
		 q = q + " WHERE refEstadoPedido = 4 ";
	  else if(RG1->ItemIndex == 5)
		 q = q + " WHERE refEstadoPedido = 5 ";


	  if(orden == "")
	  {
		 if(RG2->ItemIndex == 0)
			q = q + " ORDER BY momento DESC LIMIT 300 ";
		 else
			q = q + " ORDER BY momento ASC LIMIT 300 ";
	  }
	  else
	  {
		 if(RG2->ItemIndex == 0)
			q = q + " ORDER BY " + orden + " DESC ";
		 else
			q = q + " ORDER BY " + orden + " ASC ";
	  }

	  CDS->Active = false;
	  QueryPedido->Close();
	  QueryPedido->SQL->Clear();
	  QueryPedido->SQL->Add(q);
	  QueryPedido->Open();
	  CDS->Active = true;

	  ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}


//---------------------------------------------------------------------------
void __fastcall TfPedidos::FormShow(TObject *Sender)
{
   Panel1->Visible = false;
   Panel2->Visible = false;
   Button1->Enabled = true;
   RG1->ItemIndex = 0;
   RG2->ItemIndex = 0;
   buscar("");
}
//---------------------------------------------------------------------------
void __fastcall TfPedidos::RG1Click(TObject *Sender)
{
   buscar("");
}
//---------------------------------------------------------------------------
void __fastcall TfPedidos::DBGrid1TitleClick(TColumn *Column)
{
   String a = Column->Field->Name;
   a = a.Delete(1,3);

   buscar(a);
}
//---------------------------------------------------------------------------
void __fastcall TfPedidos::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000); //TColor(0x005E5EFF);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);     //0x00FFD9B3
	  else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);     //0x00FFF0E1
   }


   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid1DblClick(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   fIngresarPedido->refEstadoPedido = CDSrefEstadoPedido->AsInteger;
   fIngresarPedido->idPedido = CDSidPedido->AsInteger;
   fIngresarPedido->ordenAsociada = CDSordenAsociada->AsString;
   fIngresarPedido->ShowModal();
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button1Click(TObject *Sender)
{
   Button1->Enabled = false;
   modificarOrdenAsociada = false;
   Edit1->Text = "";
   Panel1->Visible = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Crearnuevaordendecompra1Click(TObject *Sender)
{
   if(Application->MessageBox(L"Se va a crear una nueva orden de compra. Desea continuar?",L"Crear nueva orden de compra?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  return;

   fBuscarCliente->ShowModal();
   int idCliente = fBuscarCliente->idSeleccionado;

   if(idCliente < 1)
   {
	  Application->MessageBox(L"Debe seleccionar un cliente!",L"Falta cliente!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO pedidos (momento, refCliente, refEstadoPedido, descuentoAplicado) "
					  "VALUES (NOW(), :id, 1, (SELECT descuento FROM clientes WHERE idCliente = :id LIMIT 1))");
   QueryAux->ParamByName("id")->AsInteger = idCliente;
   QueryAux->ExecSQL();

   CDS->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verestaordendecompra1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   fIngresarPedido->Show();
   fIngresarPedido->actualizarPresupuesto(CDSidPedido->AsInteger, CDSrefEstadoPedido->AsInteger, CDSordenAsociada->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Eliminarestaordendecompra1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   int pedidoEliminar = CDS->FieldByName("idPedido")->AsInteger;
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refPedido FROM articulosPedidos WHERE refPedido = :idPedido LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM remitos WHERE refPedido = :idPedido");
	  QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
	  QueryAux->ExecSQL();

      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM pedidos WHERE idPedido = :idPedido LIMIT 1");
	  QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
	  QueryAux->ExecSQL();
   }
   else
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT refEstadoPedido FROM pedidos WHERE idPedido = :idPedido LIMIT 1");
	  QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
	  QueryAux->Open();

	  if(QueryAux->FieldByName("refEstadoPedido")->AsInteger > 1)
	  {
		 if(Application->MessageBox(L"Este pedido ya fue confirmado. Tenga en cuenta que eliminar este pedido podría producir inconsistencias entre posibles órdenes/facturas impresas y los datos mostrados en este programa. Tembién se eliminarán las entradas de cuentas corrientes asociadas al pedido. Aún así, da su consentimiento para continuar eliminando?",L"IMPORTANTE!", MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
		 {
			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM articulosPedidos WHERE refPedido = :idPedido");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM remitos WHERE refPedido = :idPedido");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM cuentas WHERE refPedido = :idPedido");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM pedidosFacturados WHERE refPedido = :idPedido LIMIT 1");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM pedidos WHERE idPedido = :idPedido LIMIT 1");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();
		 }
	  }
	  else
	  {
		 if(Application->MessageBox(L"Realmente desea eliminar este pedido?\nSe van a quitar todos los items del mismo",L"ATENCIÓN!", MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
		 {
			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM articulosPedidos WHERE refPedido = :idPedido");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM remitos WHERE refPedido = :idPedido");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
			QueryAux->ExecSQL();

			QueryAux->Close();
			QueryAux->SQL->Clear();
			QueryAux->SQL->Add("DELETE FROM pedidos WHERE idPedido = :idPedido LIMIT 1");
			QueryAux->ParamByName("idPedido")->AsInteger = pedidoEliminar;
	  		QueryAux->ExecSQL();
		 }
		 else
		    return;
	  }
   }
   QueryAux->Close();
   CDS->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CDSfechaConfirmacionGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(Sender->AsString == "01/01/2100")
	  Text = "-";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CDSfechaFinalizacionGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(Sender->AsString == "01/01/2100")
	  Text = "-";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CDSfechaEntregaGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(Sender->AsString == "01/01/2100")
	  Text = "-";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button2Click(TObject *Sender)
{
   Panel1->Visible = false;
   Button1->Enabled = true;

   if(!modificarOrdenAsociada)
   {
	   if(Application->MessageBox(L"Se va a crear una nueva orden de compra. Desea continuar?",L"Crear nueva orden de compra?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
		  return;

	   fBuscarCliente->ShowModal();
	   int idCliente = fBuscarCliente->idSeleccionado;

	   if(idCliente < 1)
	   {
		  Application->MessageBox(L"Debe seleccionar un cliente!",L"Falta cliente!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		  return;
	   }

	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("INSERT INTO pedidos (momento, refCliente, refEstadoPedido, descuentoAplicado, fechaConfirmacion, fechaFinalizacion, fechaEntrega, ordenAsociada) "
						  "VALUES (NOW(), :id, 1, (SELECT descuento FROM clientes WHERE idCliente = :id LIMIT 1), DATE('2100-01-01'), DATE('2100-01-01'), DATE('2100-01-01'), :ordenAsociada)");
	   QueryAux->ParamByName("id")->AsInteger = idCliente;
	   QueryAux->ParamByName("ordenAsociada")->AsString = Edit1->Text;
	   QueryAux->ExecSQL();
   }
   else
   {
	   if(Application->MessageBox(L"Se va a modificar la orden de compra asociada, desea continuar?",L"Modificar orden asociada?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
		  return;

	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add(" UPDATE pedidos SET ordenAsociada = :ordenAsociada WHERE idPedido = :idPedido LIMIT 1");
	   QueryAux->ParamByName("idPedido")->AsInteger = CDS->FieldByName("idPedido")->AsInteger;
	   QueryAux->ParamByName("ordenAsociada")->AsString = Edit1->Text;
	   QueryAux->ExecSQL();
   }
   CDS->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::ModificarOrdenasociada1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT ordenAsociada FROM pedidos WHERE idPedido = :idPedido LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = CDS->FieldByName("idPedido")->AsInteger;
   QueryAux->Open();
   Edit1->Text =  QueryAux->FieldByName("ordenAsociada")->AsString;
   QueryAux->Close();

   modificarOrdenAsociada = true;
   Button1->Enabled = false;
   Panel1->Visible = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button3Click(TObject *Sender)
{
   if(CB->ItemIndex < 0)
	  return;

   String imp_actual;

   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   imp_actual = Configuraciones->ReadString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");

   int imp_index;

   if(imp_actual == "NO_CONFIGURADA")
   {
	  delete Configuraciones;
	  Application->MessageBox(L"Debe configurar una impresora antes de imprimir." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   else
   {
	   bool error = false;
	   TPrinter *printer;
	   printer = new TPrinter;
	   for(imp_index = 0; imp_index < printer->Printers->Count; imp_index++)
	   {
		  if(printer->Printers->Strings[imp_index] == imp_actual)
			 break;
	   }
	   if(imp_index < printer->Printers->Count)
		  error = false;
	   else
	   {
		  error = true;
		  Configuraciones->WriteString("Impresion","ImpresoraEtiquetas","NO CONFIGURADA");
	   }
	   if(error)
	   {
		  delete Configuraciones;
	      String str;
		  str = "Se produjo un error al intentar localizar la impresora seleccionada.";
		  str = str + '\n';
		  str = str + "La reconfiguraracion de la impresora podria solucionar el problema.";

		  Application->MessageBox(str.w_str() ,L"Error", MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
          return;
	   }
   }
   delete Configuraciones;

   frxReport1->PrintOptions->Printer = imp_actual;

   String no = CDS->FieldByName("idPedido")->AsString;
   while(no.Length() < 6)
      no = no.Insert("0",1);


   int c = StrToInt(Edit2->Text);
   for(int i = 1; i <= c; i++)
   {
	   dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo1"))->Text = Edit3->Text;
	   dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo2"))->Text = Edit4->Text;
	   dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo4"))->Text = no;

	   if(CB->ItemIndex == 0)
		  dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo3"))->Text = "PAGADO";
	   else if(CB->ItemIndex == 1)
		  dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo3"))->Text = "CUENTA CORRIENTE";
	   if(CB->ItemIndex == 2)
	   {
		  if(Edit5->Text.Pos("$ ") > 0)
			 dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo3"))->Text = Edit5->Text.Delete(1,2);
		  else
			 dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo3"))->Text = Edit5->Text;
       }
	   dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("Memo5"))->Text = "Bulto " + IntToStr(i) + " de " + IntToStr(c);

	   frxReport1->PrepareReport(true);
	   frxReport1->Print();
//       frxReport1->ShowReport();

   }

   Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Imprimiretiquetadeentrega1Click(TObject *Sender)
{
   if(!CDS->Active)
      return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT razonSocial AS cliente, domicilio, "

						 "(SELECT (totalCIVA * (1 - (descuentoAplicado / 100.0))) AS final FROM ("
						 "(SELECT SUM(cantidad * precioUnitario) AS totalCIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS totalCIVA, "
					     "(SELECT descuentoAplicado FROM pedidos WHERE idPedido = :idPedido) AS descuentoAplicado)) AS final "

					  "FROM clientes WHERE idCliente = :refCliente LIMIT 1");
   QueryAux->ParamByName("refCliente")->AsInteger = CDS->FieldByName("refCliente")->AsInteger;
   QueryAux->ParamByName("idPedido")->AsInteger = CDS->FieldByName("idPedido")->AsInteger;
   QueryAux->Open();
   Edit3->Text = QueryAux->FieldByName("cliente")->AsString;
   Edit4->Text = QueryAux->FieldByName("domicilio")->AsString;
   Edit5->Text = FormatFloat("$ 0.00", QueryAux->FieldByName("final")->AsFloat);
   QueryAux->Close();
   Edit2->Text = "1";
   CB->ItemIndex = -1;
   Edit5->Visible = false;
   Panel2->Visible = true;
   Edit2->SetFocus();
   Edit2->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CBChange(TObject *Sender)
{
   if(CB->ItemIndex == 2)
	  Edit5->Visible = true;
   else
      Edit5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit5Exit(TObject *Sender)
{
   String s = dynamic_cast<TEdit *>(Sender)->Text;

   try
   {
	   StrToFloat(s);
   }
   catch (...)
   {
	   s = "0,00";
   }
   float v = StrToFloat(s);
   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("$ 0.00", v);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit5Enter(TObject *Sender)
{
   String s = dynamic_cast<TEdit *>(Sender)->Text;
   if(s.Pos("$") > 0)
	  s = s.Delete(1,2);

   dynamic_cast<TEdit *>(Sender)->Text = s;

   dynamic_cast<TEdit *>(Sender)->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button4Click(TObject *Sender)
{
   Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
   if((Key < '0' || Key > '9') && Key != '\b')
      Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG2Click(TObject *Sender)
{
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::FormClose(TObject *Sender, TCloseAction &Action)
{

   QueryAux->Close();
   CDS->Active = false;
   QueryPedido->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button5Click(TObject *Sender)
{
   RG2->ItemIndex = 0;
   RG1->ItemIndex = 0;
   fBuscarArticulo->llamador = 1;
   fBuscarArticulo->soloBusqueda = true;
   fBuscarArticulo->ShowModal();
   fBuscarArticulo->soloBusqueda = false;
   int idContenido = fBuscarArticulo->idSeleccionado;

   String q = "SELECT *, "
				 "(SELECT razonSocial AS cliente FROM clientes WHERE clientes.idCliente = pedidos.refCliente LIMIT 1) AS cliente, "
				 "(SELECT descripcion FROM estadospedidos WHERE estadospedidos.idEstadoPedido = pedidos.refEstadoPedido LIMIT 1) AS estadoPedido "
				 "FROM pedidos WHERE idPedido IN (SELECT refPedido FROM articulospedidos WHERE refArticulo = :idContenido)";


   CDS->Active = false;
   QueryPedido->Close();
   QueryPedido->SQL->Clear();
   QueryPedido->SQL->Add(q);
   QueryPedido->ParamByName("idContenido")->AsInteger = idContenido;
   QueryPedido->Open();
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CancelarEstadoconfirmado1Click(TObject *Sender)
{
   if(CDS->FieldByName("refEstadoPedido")->AsInteger != 2)
   {
	  Application->MessageBox(L"Esta función solo esta disponible para pedidos en estado \"Confirmado\"." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(Application->MessageBox(L"Realmente desea revertir este pedido al estado \"NO CONFIRMADO\"? Esto provocará la restitución del stock de los artículos descontados al momento de confirmar el pedido.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE articulos SET stock = (stock + (SELECT cantidad FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)) "
   				      "WHERE idArticulo IN (SELECT refArticulo FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)");
   QueryAux->ParamByName("refPedido")->AsInteger = CDS->FieldByName("idPedido")->AsInteger;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET refEstadoPedido = 1, fechaConfirmacion = DATE('2100-01-01') WHERE idPedido = :idPedido AND refEstadoPedido = 2 LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = CDS->FieldByName("idPedido")->AsInteger;
   QueryAux->ExecSQL();

   CDS->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

