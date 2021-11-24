//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uBuscarArticulo.h"
#include "uAgregarArticulo.h"
#include "uVerProveedores.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfBuscarArticulo *fBuscarArticulo;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfBuscarArticulo::TfBuscarArticulo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

String TfBuscarArticulo::comaToDot(String str)
{
   if(str.Pos(",") == 0)
	  return str;
   if(str.Pos(".") > 0)
	  return "0";

   int p = str.Pos(",");
   str = str.Delete(p,1);
   return str.Insert(".",p);
}
//---------------------------------------------------------------------------

void TfBuscarArticulo::formularioActivo(bool condicion)
{
   if(condicion)
   {
	  cbRubro->Enabled = true;
	  cbCategoria->Enabled = true;
	  cbTipo->Enabled = true;
	  cbMarca->Enabled = true;
	  cbModelo->Enabled = true;
	  cbTamano->Enabled = true;
	  cbColor->Enabled = true;
	  cbDiseno->Enabled = true;
	  cbUnidadMedida->Enabled = true;
	  cbCantidad->Enabled = true;
	  Edit2->Enabled = true;
	  DBGrid1->Enabled = true;
	  Button3->Enabled = true;
   }
   else
   {
	  cbRubro->Enabled = false;
	  cbCategoria->Enabled = false;
	  cbTipo->Enabled = false;
	  cbMarca->Enabled = false;
	  cbModelo->Enabled = false;
	  cbTamano->Enabled = false;
	  cbColor->Enabled = false;
	  cbDiseno->Enabled = false;
	  cbUnidadMedida->Enabled = false;
	  cbCantidad->Enabled = false;
	  Edit2->Enabled = false;
	  DBGrid1->Enabled = false;
	  Button3->Enabled = false;
   }

   fBuscarArticulo->Repaint();
   DBGrid1->Repaint();
}

//---------------------------------------------------------------------------
void TfBuscarArticulo::buscarVariantes(TComboBox *CB, String field)
{
   if(cbRubro->ItemIndex > -1)
   {
	  Edit2->Text = "";
      CB->Clear();

	  String q = "SELECT DISTINCT " + field + " FROM articulos WHERE refRubro = :refRubro ";


      if(cbCategoria->Text != "")
		 q = q + "AND categoria = :categoria ";
	  if(cbTipo->Text != "")
		 q = q + "AND tipo = :tipo ";
	  if(cbMarca->Text != "")
		 q = q + "AND marca = :marca ";
	  if(cbModelo->Text != "")
		 q = q + "AND modelo = :modelo ";
	  if(cbTamano->Text != "")
		 q = q + "AND tamano = :tamano ";
	  if(cbColor->Text != "")
		 q = q + "AND color = :color ";
	  if(cbDiseno->Text != "")
		 q = q + "AND diseno = :diseno ";
	  if(cbUnidadMedida->Text != "")
		 q = q + "AND unidadMedida = :unidadMedida ";

	  q = q + " ORDER BY " + field;

	  QueryCB->Close();
	  QueryCB->SQL->Clear();
	  QueryCB->SQL->Add(q);

	  QueryCB->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

	  if(cbCategoria->Text != "")
		 QueryCB->ParamByName("categoria")->AsString = cbCategoria->Text;
	  if(cbTipo->Text != "")
		 QueryCB->ParamByName("tipo")->AsString = cbTipo->Text;
	  if(cbMarca->Text != "")
		 QueryCB->ParamByName("marca")->AsString = cbMarca->Text;
	  if(cbModelo->Text != "")
		 QueryCB->ParamByName("modelo")->AsString = cbModelo->Text;
	  if(cbTamano->Text != "")
		 QueryCB->ParamByName("tamano")->AsString = cbTamano->Text;
	  if(cbColor->Text != "")
		 QueryCB->ParamByName("color")->AsString = cbColor->Text;
	  if(cbDiseno->Text != "")
		 QueryCB->ParamByName("diseno")->AsString = cbColor->Text;
	  if(cbUnidadMedida->Text != "")
		 QueryCB->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;


	  QueryCB->Open();
	  QueryCB->First();

	  while(!QueryCB->Eof)
	  {
		 CB->Items->Add(QueryCB->FieldByName(field)->AsString);
		 QueryCB->Next();
	  }
	  QueryCB->Close();

	  if(CB->Items->Strings[0] != "")
	     CB->Items->Add("");
   }
   else
   {
	  cbCategoria->Clear();
	  cbTipo->Clear();
	  cbMarca->Clear();
	  cbModelo->Clear();
	  cbColor->Clear();
	  cbDiseno->Clear();
	  cbCantidad->Clear();
	  cbUnidadMedida->Clear();
   }

}
//---------------------------------------------------------------------------

void TfBuscarArticulo::buscar(String orden)
{
   if(cbRubro->ItemIndex > -1)
   {
	  Edit2->Text = "";

	  CDS->Active = false;

      String q = "SELECT COUNT(*) AS nroReg FROM articulos WHERE "
				 "refRubro = :refRubro ";

      if(cbCategoria->Text != "")
		 q = q + "AND categoria = :categoria ";
	  if(cbTipo->Text != "")
		 q = q + "AND tipo = :tipo ";
	  if(cbMarca->Text != "")
		 q = q + "AND marca = :marca ";
	  if(cbModelo->Text != "")
		 q = q + "AND modelo = :modelo ";
	  if(cbTamano->Text != "")
		 q = q + "AND tamano = :tamano ";
	  if(cbColor->Text != "")
		 q = q + "AND color = :color ";
	  if(cbDiseno->Text != "")
		 q = q + "AND diseno = :diseno ";
	  if(cbCantidad->Text != "")
		 q = q + "AND cantidad = :cantidad ";
	  if(cbUnidadMedida->Text != "")
		 q = q + "AND unidadMedida = :unidadMedida ";

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add(q);

	  QueryAux->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

	  if(cbCategoria->Text != "")
		 QueryAux->ParamByName("categoria")->AsString = cbCategoria->Text;
	  if(cbTipo->Text != "")
		 QueryAux->ParamByName("tipo")->AsString = cbTipo->Text;
	  if(cbMarca->Text != "")
		 QueryAux->ParamByName("marca")->AsString = cbMarca->Text;
	  if(cbModelo->Text != "")
		 QueryAux->ParamByName("modelo")->AsString = cbModelo->Text;
	  if(cbTamano->Text != "")
		 QueryAux->ParamByName("tamano")->AsString = cbTamano->Text;
	  if(cbColor->Text != "")
		 QueryAux->ParamByName("color")->AsString = cbColor->Text;
	  if(cbDiseno->Text != "")
		 QueryAux->ParamByName("diseno")->AsString = cbColor->Text;
	  if(cbCantidad->Text != "")
		 QueryAux->ParamByName("cantidad")->AsString = cbCantidad->Text;
	  if(cbUnidadMedida->Text != "")
		 QueryAux->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

	  QueryAux->Open();
	  int nroReg = QueryAux->FieldByName("nroReg")->AsInteger;
	  QueryAux->Close();

	  if(nroReg == 0)
		 Label18->Caption = "No hay registros que coincidan con este criterio de búsqueda";
	  else if(nroReg == 1)
		 Label18->Caption = "Solo un registro coincide con este criterio de búsqueda";
	  else
		 Label18->Caption = IntToStr(nroReg) + " registros coinciden con este criterio de búsqueda";






	  q = "SELECT idArticulo, categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock FROM articulos WHERE "
				 "refRubro = :refRubro ";

	  if(cbCategoria->Text != "")
		 q = q + "AND categoria = :categoria ";
	  if(cbTipo->Text != "")
		 q = q + "AND tipo = :tipo ";
	  if(cbMarca->Text != "")
		 q = q + "AND marca = :marca ";
	  if(cbModelo->Text != "")
		 q = q + "AND modelo = :modelo ";
	  if(cbTamano->Text != "")
		 q = q + "AND tamano = :tamano ";
	  if(cbColor->Text != "")
		 q = q + "AND color = :color ";
	  if(cbDiseno->Text != "")
		 q = q + "AND diseno = :diseno ";
	  if(cbCantidad->Text != "")
		 q = q + "AND cantidad = :cantidad ";
	  if(cbUnidadMedida->Text != "")
		 q = q + "AND unidadMedida = :unidadMedida ";

	  if(orden != "")
		 q = q + "ORDER BY " + orden;

	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);

	  Query1->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

	  if(cbCategoria->Text != "")
		 Query1->ParamByName("categoria")->AsString = cbCategoria->Text;
	  if(cbTipo->Text != "")
		 Query1->ParamByName("tipo")->AsString = cbTipo->Text;
	  if(cbMarca->Text != "")
		 Query1->ParamByName("marca")->AsString = cbMarca->Text;
	  if(cbModelo->Text != "")
		 Query1->ParamByName("modelo")->AsString = cbModelo->Text;
	  if(cbTamano->Text != "")
		 Query1->ParamByName("tamano")->AsString = cbTamano->Text;
	  if(cbColor->Text != "")
		 Query1->ParamByName("color")->AsString = cbColor->Text;
	  if(cbDiseno->Text != "")
		 Query1->ParamByName("diseno")->AsString = cbColor->Text;
	  if(cbCantidad->Text != "")
		 Query1->ParamByName("cantidad")->AsString = cbCantidad->Text;
	  if(cbUnidadMedida->Text != "")
		 Query1->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

	  Query1->Open();
	  CDS->Active = true;

	  if(cbCategoria->Text != "")
		 q = q + "AND categoria = :categoria ";
	  if(cbTipo->Text != "")
		 q = q + "AND tipo = :tipo ";
	  if(cbMarca->Text != "")
		 q = q + "AND marca = :marca ";

	  if(cbCategoria->Text != "" && cbTipo->Text != "" && cbMarca->Text != "")
	  {
		 Actualizarvaloresdegrupo1->Enabled = true;
		 Modificarpreciodegrupo1->Enabled = true;
		 Modificarmargendeutilidaddegrupo1->Enabled = true;
	  }
	  else
	  {
		 Actualizarvaloresdegrupo1->Enabled = false;
		 Modificarpreciodegrupo1->Enabled = false;
		 Modificarmargendeutilidaddegrupo1->Enabled = false;
	  }
	  ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
   }
   else
   {
	  CDS->Active = false;
	  Query1->Close();
	  Label18->Caption = "No hay registros que coincidan con este criterio de búsqueda";
	  Actualizarvaloresdegrupo1->Enabled = false;
	  Modificarpreciodegrupo1->Enabled = false;
	  Modificarmargendeutilidaddegrupo1->Enabled = false;
   }
}

//---------------------------------------------------------------------------
void __fastcall TfBuscarArticulo::FormShow(TObject *Sender)
{
   cbCategoria->Clear();
   cbTipo->Clear();
   cbMarca->Clear();
   cbModelo->Clear();
   cbTamano->Clear();
   cbColor->Clear();
   cbDiseno->Clear();
   cbCantidad->Clear();
   cbUnidadMedida->Clear();
   ComboBox1->Clear();
   Edit2->Clear();

   Panel1->Visible = false;
   Panel2->Visible = false;
   Panel3->Visible = false;
   Panel4->Visible = false;
   Panel5->Visible = false;
   Panel6->Visible = false;
   formularioActivo(true);

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT * FROM rubros ORDER BY idRubro");
   QueryCB->Open();

   QueryCB->First();
   cbRubro->Clear();
   while(!QueryCB->Eof)
   {
	  cbRubro->Items->Add(QueryCB->FieldByName("descripcion")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT nombre FROM proveedores ORDER BY nombre");
   QueryCB->Open();

   QueryCB->First();

   while(!QueryCB->Eof)
   {
	  ComboBox1->Items->Add(QueryCB->FieldByName("nombre")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   idSeleccionado = 0;
   Button3->Enabled = false;
   Button3->Caption = "Agregar un nuevo artículo";
   Label18->Caption = "";
   Actualizarvaloresdegrupo1->Enabled = false;
   Modificarpreciodegrupo1->Enabled = false;
   Modificarmargendeutilidaddegrupo1->Enabled = false;

   Edit2->SetFocus();

   if(soloBusqueda)
   {
	  fBuscarArticulo->Caption = "Seleccionar artículo para modificar...";
	  DBGrid1->PopupMenu = NULL;
	  Button3->Visible = false;
	  Label23->Visible = true;
   }
   else
   {
	  fBuscarArticulo->Caption = "Filtrar artículos para modificar valores...";
	  DBGrid1->PopupMenu = PopupMenu1;
	  Button3->Visible = true;
	  Label23->Visible = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarArticulo::DBGrid1DblClick(TObject *Sender)
{
   if(CDS->Active)
   {
	  if(llamador == 1)
	  {
		 idSeleccionado = CDS->FieldByName("idArticulo")->AsInteger;
		 CDS->Active = false;
		 Query1->Close();
		 Close();
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbCategoriaChange(TObject *Sender)
{

   buscarVariantes(cbTipo, "tipo");
   buscarVariantes(cbMarca, "marca");
   buscarVariantes(cbModelo, "modelo");
   buscarVariantes(cbTamano, "tamano");
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------


void __fastcall TfBuscarArticulo::cbTipoChange(TObject *Sender)
{
   buscarVariantes(cbMarca, "marca");
   buscarVariantes(cbModelo, "modelo");
   buscarVariantes(cbTamano, "tamano");
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbMarcaChange(TObject *Sender)
{
   buscarVariantes(cbModelo, "modelo");
   buscarVariantes(cbTamano, "tamano");
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbModeloChange(TObject *Sender)
{
   buscarVariantes(cbTamano, "tamano");
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbTamanoChange(TObject *Sender)
{
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbColorChange(TObject *Sender)
{
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbCantidadChange(TObject *Sender)
{
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbUnidadMedidaChange(TObject *Sender)
{
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Verlistadeproveedores1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT nombre FROM proveedores WHERE idProveedor = (SELECT refProveedor FROM relacionproveedores WHERE refArticulo = :refArticulo)");
   QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  ComboBox1->ItemIndex = -1;
	  Edit9->Text = "0";
	  Edit10->Text = "0,00";
	  modificandoProveedor = false;
   }
   else
   {
	  modificandoProveedor = true;
	  ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(QueryAux->FieldByName("nombre")->AsString);
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo, escala FROM relacionproveedores WHERE refArticulo = :refArticulo");
	  QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryAux->Open();
	  Edit9->Text = QueryAux->FieldByName("codigo")->AsString;
	  Edit10->Text = FormatFloat("0.00", QueryAux->FieldByName("escala")->AsFloat);
   }
   QueryAux->Close();

   Panel6->Visible = true;
   ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TfBuscarArticulo::Modificarstock1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT stock FROM articulos WHERE idArticulo = :idArticulo");
   QueryAux->ParamByName("idArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryAux->Open();
   Label9->Caption = "Stock actual: " + QueryAux->FieldByName("stock")->AsString;
   QueryAux->Close();

   Edit1->Text = "0";
   formularioActivo(false);

   Panel1->Left = (fBuscarArticulo->Width - Panel1->Width) / 2;
   Panel1->Top = (fBuscarArticulo->Height - Panel1->Height) / 2;
   Panel1->Visible = true;
   Edit1->SetFocus();
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button1Click(TObject *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET stock = (stock + :stock) WHERE idArticulo = :idArticulo");
   QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ParamByName("stock")->AsString = Edit1->Text;
   QueryUpdate->ExecSQL();

   Application->MessageBox(L"El stock se actualizo correctamente",L"Stock actualizado" ,MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   formularioActivo(true);
   Panel1->Visible = false;
   CDS->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button2Click(TObject *Sender)
{
   formularioActivo(true);
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarArticulo::Edit2Change(TObject *Sender)
{
   if(Edit2->Text.Length() < 3)
	  return;

   cbCategoria->Text = "";
   cbTipo->Text = "";
   cbMarca->Text = "";
   cbModelo->Text = "";
   cbTamano->Text = "";
   cbColor->Text = "";
   cbDiseno->Text = "";
   cbCantidad->Text = "";
   cbUnidadMedida->Text = "";
   Actualizarvaloresdegrupo1->Enabled = false;
   Modificarpreciodegrupo1->Enabled = false;
   Modificarmargendeutilidaddegrupo1->Enabled = false;

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT idArticulo, categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock FROM articulos WHERE codigo LIKE :codigo OR REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') LIKE _utf8 :nc COLLATE utf8_general_ci ORDER BY categoria");
   Query1->ParamByName("nc")->AsString = "%" + Edit2->Text.UpperCase() + "%";
   Query1->ParamByName("codigo")->AsString = "%" + Edit2->Text + "%";
   Query1->Open();
   CDS->Active = true;

   Label18->Caption = "Se muestran " + IntToStr(CDS->RecordCount) + " registros";
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::FormClose(TObject *Sender, TCloseAction &Action)
{
   CDS->Active = false;
   Query1->Close();
   QueryAux->Close();
   QueryUpdate->Close();
   QueryCB->Close();
   SQLConnection1->Close();
   soloBusqueda = false;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::DBGrid1TitleClick(TColumn *Column)
{
   if(!CDS->Active)
	  return;

   String a = Column->Field->Name;
   a = a.Delete(1,3);

   if(a == "idArticulo")
	  a = "idArticulo, categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "categoria")
	  a = "categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "tipo")
	  a = "tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "marca")
	  a = "marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "modelo")
	  a = "modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "tamano")
	  a = "tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "color")
	  a = "color, diseno, cantidad, unidadMedida, stock";
   else if(a == "diseno")
	  a = "diseno, cantidad, unidadMedida, stock";
   else if(a == "cantidad")
	  a = "cantidad, unidadMedida, stock";
   else if(a == "unidadMedida")
	  a = "unidadMedida, stock";


   if(Edit2->Text == "")
	  buscar(a);
   else
   {
       CDS->Active = false;
	   Query1->Close();
	   Query1->SQL->Clear();
	   Query1->SQL->Add("SELECT idArticulo, categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock FROM articulos WHERE codigo LIKE :codigo OR nombreCompleto LIKE _utf8 :nc COLLATE utf8_general_ci ORDER BY " + a);
	   Query1->ParamByName("nc")->AsString = "%" + Edit2->Text.UpperCase() + "%";
	   Query1->ParamByName("codigo")->AsString = "%" + Edit2->Text + "%";
	   Query1->Open();
	   CDS->Active = true;
   }

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbRubroChange(TObject *Sender)
{
   buscarVariantes(cbCategoria, "categoria");
   buscarVariantes(cbTipo, "tipo");
   buscarVariantes(cbMarca, "marca");
   buscarVariantes(cbModelo, "modelo");
   buscarVariantes(cbTamano, "tamano");
   buscarVariantes(cbColor, "color");
   buscarVariantes(cbDiseno, "diseno");
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");


   Button3->Enabled = true;

   if(cbRubro->ItemIndex != -1)
	  Button3->Caption = "Agregar un nuevo artículo de " + cbRubro->Text;
   else
   {
	  Button3->Enabled = false;
	  Button3->Caption = "Agregar un nuevo artículo";
   }

//   CDS->Active = false;
//   Actualizarvaloresdegrupo1->Enabled = false;
//   Label18->Caption = "Indicar criterios de búsqueda";
//   Query1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::cbDisenoChange(TObject *Sender)
{
   buscarVariantes(cbUnidadMedida, "unidadMedida");
   buscarVariantes(cbCantidad, "cantidad");
   buscar("");
}
//---------------------------------------------------------------------------



void __fastcall TfBuscarArticulo::Button3Click(TObject *Sender)
{
   if(cbRubro->ItemIndex == -1)
	  return;

   fAgregarArticulo->refRubro = cbRubro->ItemIndex + 1;
   fAgregarArticulo->paraModificar = false;
   fAgregarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Actualizarprecio1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT precioCompra FROM articulos WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->Open();

   Edit3->Text = QueryUpdate->FieldByName("precioCompra")->AsString;
   QueryUpdate->Close();

   Edit3Exit(Edit3);

   formularioActivo(false);
   Panel2->Left = (fBuscarArticulo->Width - Panel2->Width) / 2;
   Panel2->Top = (fBuscarArticulo->Height - Panel2->Height) / 2;
   Panel2->Visible = true;

   Edit3->SetFocus();
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit3Enter(TObject *Sender)
{
   if(Edit3->Text.Pos("$ ") == 1)
	  Edit3->Text = Edit3->Text.Delete(1,2);
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit3Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit3->Text);
   }
   catch(...)
   {
	  Edit3->Text = "0,00";
   }

   Edit3->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit4Enter(TObject *Sender)
{
   if(Edit4->Text.Pos(" %") == Edit4->Text.Length() - 1)
	  Edit4->Text = Edit4->Text.Delete(Edit4->Text.Length()-1,2);

   Edit4->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit4Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit4->Text);
   }
   catch(...)
   {
	  Edit4->Text = "0,00";
   }

   Edit4->Text = FormatFloat("0.00 %", StrToFloat(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit4KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button4Click(TObject *Sender)
{
   if(CDS->Active)
   {
	  if(!modificarGrupo)
	  {
		 String q = "UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :id LIMIT 1";

		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);
		 QueryUpdate->ParamByName("precioCompra")->AsFloat = StrToFloat(Edit3->Text.Delete(1,2));
		 QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
		 QueryUpdate->ExecSQL();
	  }
	  else
	  {
	     if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los precios de todos los artículos que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
			return;

		 String q = "UPDATE articulos SET precioCompra = :precioCompra WHERE "
					"refRubro = :refRubro ";

		 if(cbCategoria->Text != "")
			q = q + "AND categoria = :categoria ";
		 if(cbTipo->Text != "")
			q = q + "AND tipo = :tipo ";
		 if(cbMarca->Text != "")
			q = q + "AND marca = :marca ";
		 if(cbModelo->Text != "")
			q = q + "AND modelo = :modelo ";
		 if(cbTamano->Text != "")
			q = q + "AND tamano = :tamano ";
		 if(cbColor->Text != "")
			q = q + "AND color = :color ";
		 if(cbDiseno->Text != "")
			q = q + "AND diseno = :diseno ";
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";


		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

		 if(cbCategoria->Text != "")
		    QueryUpdate->ParamByName("categoria")->AsString = cbCategoria->Text;
		 if(cbTipo->Text != "")
			QueryUpdate->ParamByName("tipo")->AsString = cbTipo->Text;
		 if(cbMarca->Text != "")
			QueryUpdate->ParamByName("marca")->AsString = cbMarca->Text;
		 if(cbModelo->Text != "")
			QueryUpdate->ParamByName("modelo")->AsString = cbModelo->Text;
		 if(cbTamano->Text != "")
			QueryUpdate->ParamByName("tamano")->AsString = cbTamano->Text;
		 if(cbColor->Text != "")
			QueryUpdate->ParamByName("color")->AsString = cbColor->Text;
		 if(cbDiseno->Text != "")
			QueryUpdate->ParamByName("diseno")->AsString = cbColor->Text;
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;


		 QueryUpdate->ParamByName("precioCompra")->AsFloat = StrToFloat(Edit3->Text.Delete(1,2));

		 QueryUpdate->ExecSQL();
	  }

	  Application->MessageBox(L"El precio de compra fue actualizado correctamente",L"Precio actualizado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  Panel2->Visible = false;
	  formularioActivo(true);
	  CDS->Refresh();
   }
   modificarGrupo = false;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button5Click(TObject *Sender)
{
   Panel2->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button6Click(TObject *Sender)
{
   if(CDS->Active)
   {
	  if(!modificarGrupo)
	  {
		 String q = "UPDATE articulos SET margenUtilidad = :margenUtilidad WHERE idArticulo = :id LIMIT 1";
		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);
		 QueryUpdate->ParamByName("margenUtilidad")->AsFloat = StrToFloat(Edit4->Text.SubString(1,Edit4->Text.Length()-2));
		 QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
		 QueryUpdate->ExecSQL();
	  }
	  else
	  {
		 if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los márgenes de utilidad de todos los artículos que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
			return;

		 String q = "UPDATE articulos SET margenUtilidad = :margenUtilidad WHERE "
					"refRubro = :refRubro ";

		 if(cbCategoria->Text != "")
			q = q + "AND categoria = :categoria ";
		 if(cbTipo->Text != "")
			q = q + "AND tipo = :tipo ";
		 if(cbMarca->Text != "")
			q = q + "AND marca = :marca ";
		 if(cbModelo->Text != "")
			q = q + "AND modelo = :modelo ";
		 if(cbTamano->Text != "")
			q = q + "AND tamano = :tamano ";
		 if(cbColor->Text != "")
			q = q + "AND color = :color ";
		 if(cbDiseno->Text != "")
			q = q + "AND diseno = :diseno ";
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";


		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

		 if(cbCategoria->Text != "")
		    QueryUpdate->ParamByName("categoria")->AsString = cbCategoria->Text;
		 if(cbTipo->Text != "")
			QueryUpdate->ParamByName("tipo")->AsString = cbTipo->Text;
		 if(cbMarca->Text != "")
			QueryUpdate->ParamByName("marca")->AsString = cbMarca->Text;
		 if(cbModelo->Text != "")
			QueryUpdate->ParamByName("modelo")->AsString = cbModelo->Text;
		 if(cbTamano->Text != "")
			QueryUpdate->ParamByName("tamano")->AsString = cbTamano->Text;
		 if(cbColor->Text != "")
			QueryUpdate->ParamByName("color")->AsString = cbColor->Text;
		 if(cbDiseno->Text != "")
			QueryUpdate->ParamByName("diseno")->AsString = cbColor->Text;
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;


		 QueryUpdate->ParamByName("margenUtilidad")->AsFloat = StrToFloat(Edit4->Text.SubString(1,Edit4->Text.Length()-2));

		 QueryUpdate->ExecSQL();
	  }

	  Application->MessageBox(L"El margen de ganancia fue actualizado correctamente",L"Margen de ganancia actualizado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  Panel3->Visible = false;
	  formularioActivo(true);
	  CDS->Refresh();
   }
   modificarGrupo = false;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button7Click(TObject *Sender)
{
   Panel3->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Modificarmargendeganancia1Click(TObject *Sender)

{
   if(!CDS->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT margenUtilidad FROM articulos WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->Open();

   Edit4->Text = QueryUpdate->FieldByName("margenUtilidad")->AsString;
   QueryUpdate->Close();

   Edit4Exit(Edit4);

   formularioActivo(false);

   Panel3->Left = (fBuscarArticulo->Width - Panel3->Width) / 2;
   Panel3->Top = (fBuscarArticulo->Height - Panel3->Height) / 2;
   Panel3->Visible = true;

   Edit4->SetFocus();
   Edit4->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit3Click(TObject *Sender)
{
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit4Click(TObject *Sender)
{
   Edit4->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button8Click(TObject *Sender)
{
   if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los precios de compra que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  if(CDS->Active)
	  {
		 String q = "UPDATE articulos SET precioCompra = (precioCompra * :fm) WHERE "
					"refRubro = :refRubro ";

		 if(cbCategoria->Text != "")
			q = q + "AND categoria = :categoria ";
		 if(cbTipo->Text != "")
			q = q + "AND tipo = :tipo ";
		 if(cbMarca->Text != "")
			q = q + "AND marca = :marca ";
		 if(cbModelo->Text != "")
			q = q + "AND modelo = :modelo ";
		 if(cbTamano->Text != "")
			q = q + "AND tamano = :tamano ";
		 if(cbColor->Text != "")
			q = q + "AND color = :color ";
		 if(cbDiseno->Text != "")
			q = q + "AND diseno = :diseno ";
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";


		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

		 if(cbCategoria->Text != "")
		    QueryUpdate->ParamByName("categoria")->AsString = cbCategoria->Text;
		 if(cbTipo->Text != "")
			QueryUpdate->ParamByName("tipo")->AsString = cbTipo->Text;
		 if(cbMarca->Text != "")
			QueryUpdate->ParamByName("marca")->AsString = cbMarca->Text;
		 if(cbModelo->Text != "")
			QueryUpdate->ParamByName("modelo")->AsString = cbModelo->Text;
		 if(cbTamano->Text != "")
			QueryUpdate->ParamByName("tamano")->AsString = cbTamano->Text;
		 if(cbColor->Text != "")
			QueryUpdate->ParamByName("color")->AsString = cbColor->Text;
		 if(cbDiseno->Text != "")
			QueryUpdate->ParamByName("diseno")->AsString = cbColor->Text;
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;


		 QueryUpdate->ParamByName("fm")->AsFloat = StrToFloat(Edit2->Text);

		 QueryUpdate->ExecSQL();

		 Application->MessageBox(L"Los precios de compra fueron actualizados correctamente",L"Precios actualizados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
		 CDS->Refresh();
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button9Click(TObject *Sender)
{
 if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los margenes de utilidad que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  if(CDS->Active)
	  {
		 String q = "UPDATE articulos SET margenUtilidad = (margenUtilidad * :fm) WHERE "
					"refRubro = :refRubro ";

		 if(cbCategoria->Text != "")
			q = q + "AND categoria = :categoria ";
		 if(cbTipo->Text != "")
			q = q + "AND tipo = :tipo ";
		 if(cbMarca->Text != "")
			q = q + "AND marca = :marca ";
		 if(cbModelo->Text != "")
			q = q + "AND modelo = :modelo ";
		 if(cbTamano->Text != "")
			q = q + "AND tamano = :tamano ";
		 if(cbColor->Text != "")
			q = q + "AND color = :color ";
		 if(cbDiseno->Text != "")
			q = q + "AND diseno = :diseno ";
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";


		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("refRubro")->AsInteger = cbRubro->ItemIndex + 1;

		 if(cbCategoria->Text != "")
		    QueryUpdate->ParamByName("categoria")->AsString = cbCategoria->Text;
		 if(cbTipo->Text != "")
			QueryUpdate->ParamByName("tipo")->AsString = cbTipo->Text;
		 if(cbMarca->Text != "")
			QueryUpdate->ParamByName("marca")->AsString = cbMarca->Text;
		 if(cbModelo->Text != "")
			QueryUpdate->ParamByName("modelo")->AsString = cbModelo->Text;
		 if(cbTamano->Text != "")
			QueryUpdate->ParamByName("tamano")->AsString = cbTamano->Text;
		 if(cbColor->Text != "")
			QueryUpdate->ParamByName("color")->AsString = cbColor->Text;
		 if(cbDiseno->Text != "")
			QueryUpdate->ParamByName("diseno")->AsString = cbColor->Text;
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;


		 QueryUpdate->ParamByName("fm")->AsFloat = StrToFloat(Edit2->Text);

		 QueryUpdate->ExecSQL();

		 Application->MessageBox(L"Los margenes fueron actualizados correctamente",L"Margenes actualizados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
		 CDS->Refresh();
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button10Click(TObject *Sender)
{
   Panel4->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Actualizarvaloresdegrupo1Click(TObject *Sender)

{
   if(!CDS->Active)
      return;


   formularioActivo(false);

   Edit5->Text = "1,0000";
   Edit6->Text = "1,0000";

   Panel4->Left = (fBuscarArticulo->Width - Panel4->Width) / 2;
   Panel4->Top = (fBuscarArticulo->Height - Panel4->Height) / 2;
   Panel4->Visible = true;

   Edit5->SetFocus();
   Edit5->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit6Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit6->Text);
   }
   catch(...)
   {
	  Edit6->Text = "1,0000";
   }

   Edit6->Text = FormatFloat("0.0000", StrToFloat(Edit6->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit5Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit5->Text);
   }
   catch(...)
   {
	  Edit5->Text = "1,0000";
   }

   Edit5->Text = FormatFloat("0.0000", StrToFloat(Edit5->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit5KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit6KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::FormCreate(TObject *Sender)
{
   soloBusqueda = false;
   Panel5->Left = (fBuscarArticulo->Width - Panel5->Width) / 2;
   Panel5->Top = (fBuscarArticulo->Height - Panel5->Height) / 2;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
	  DBGrid1DblClick(DBGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_DOWN && CDS->Active)
	  DBGrid1->SetFocus();
   else if(Key == VK_RETURN && CDS->RecordCount == 1)
      DBGrid1DblClick(DBGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      Button8Click(Edit5);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit6KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      Button9Click(Edit6);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
   {
      Edit3Exit(Edit3);
	  Button4Click(Edit3);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
   {
	  Edit4Exit(Edit4);
	  Button6Click(Edit4);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == VK_RETURN)
      Button1Click(Edit1);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfBuscarArticulo::Modificarpreciodegrupo1Click(TObject *Sender)
{
   modificarGrupo = true;
   Actualizarprecio1Click(Modificarpreciodegrupo1);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Modificarmargendeutilidaddegrupo1Click(TObject *Sender)

{
   modificarGrupo = true;
   Modificarmargendeganancia1Click(Modificarmargendeutilidaddegrupo1);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Configurarpromocin1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT * FROM promociones WHERE refArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->Open();

   if(QueryUpdate->IsEmpty())
   {
	  if(Application->MessageBox(L"No existen promociones para este artículo. Desea crear una?",L"Crear promoción",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
	  {
		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add("INSERT INTO promociones (refArticulo, cantidadPromo, descuentoPromo) "
							   "VALUES (:refArticulo, 0, 0.00)");
		 QueryUpdate->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
//		 QueryUpdate->ParamByName("cantidadPromo")->AsInteger = StrToInt(Edit7->Text);
//		 QueryUpdate->ParamByName("descuentoPromo")->AsFloat = StrToFloat(Edit8->Text);
		 QueryUpdate->ExecSQL();

		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add("SELECT * FROM promociones WHERE refArticulo = :id LIMIT 1");
		 QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   		 QueryUpdate->Open();
	  }
	  else
	     return;
   }
   if(QueryUpdate->IsEmpty())
   {
	  ShowMessage("Se produjo un error importante");
	  return;
   }

   Edit7->Text = QueryUpdate->FieldByName("cantidadPromo")->AsString;
   Edit8->Text = FormatFloat("0.00", QueryUpdate->FieldByName("descuentoPromo")->AsFloat);
   idPromocion = QueryUpdate->FieldByName("idPromocion")->AsInteger;
   QueryUpdate->Close();

   formularioActivo(false);
   Panel5->Visible = true;

   Edit7->SetFocus();
   Edit7->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button11Click(TObject *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE promociones SET cantidadPromo = :cantidadPromo, descuentoPromo = :descuentoPromo "
						 "WHERE idPromocion = :idPromocion LIMIT 1");
   QueryUpdate->ParamByName("idPromocion")->AsInteger = idPromocion;
   QueryUpdate->ParamByName("cantidadPromo")->AsInteger = StrToInt(Edit7->Text);
   QueryUpdate->ParamByName("descuentoPromo")->AsFloat = StrToFloat(Edit8->Text);
   QueryUpdate->ExecSQL();

   Panel5->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------


void __fastcall TfBuscarArticulo::Button12Click(TObject *Sender)
{
   Panel5->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button13Click(TObject *Sender)
{
   if(Application->MessageBox(L"Realmente desea eliminar esta promoción?",L"¡ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM promociones WHERE idPromocion = :idPromocion LIMIT 1");
   QueryUpdate->ParamByName("idPromocion")->AsInteger = idPromocion;
   QueryUpdate->ExecSQL();

   Panel5->Visible = false;
   formularioActivo(true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit8KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';

   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit7KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b')
	  Key = NULL;
}
//---------------------------------------------------------------------------


void __fastcall TfBuscarArticulo::Edit8Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit8->Text);
   }
   catch(...)
   {
	  Edit8->Text = "0,00";
   }

   Edit8->Text = FormatFloat("0.00", StrToFloat(Edit8->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Eliminarartculo1Click(TObject *Sender)
{
   int idEliminar = CDS->FieldByName("idArticulo")->AsInteger;
   CDS->Active = false;

   if(Application->MessageBox(L"Realmente desea eliminar este artículo?",L"¡ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  CDS->Active = true;
	  return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idArticuloPedido FROM articulospedidos WHERE refArticulo = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = idEliminar;
   QueryAux->Open();

   if(!QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  if(Application->MessageBox(L"Hay órdenes de compra que incluyen este artículo entre sus ítems, eliminarlo provocará inconsistencias entre posibles órdenes/facturas impresas y los valores mostrados en este programa. Aún así da su consentimiento para eliminar el artúculo?",L"¡IMPORTANTE!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  {
		 CDS->Active = true;
		 return;
	  }

	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("DELETE FROM articulospedidos WHERE refArticulo = :id");
	  QueryUpdate->ParamByName("id")->AsInteger = idEliminar;
	  QueryUpdate->ExecSQL();
   }
   QueryAux->Close();

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM promociones WHERE refArticulo = :id");
   QueryUpdate->ParamByName("id")->AsInteger = idEliminar;
   QueryUpdate->ExecSQL();

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM relacionproveedores WHERE refArticulo = :id");
   QueryUpdate->ParamByName("id")->AsInteger = idEliminar;
   QueryUpdate->ExecSQL();

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM articulos WHERE idArticulo = :id");
   QueryUpdate->ParamByName("id")->AsInteger = idEliminar;
   QueryUpdate->ExecSQL();

   CDS->Active = true;
}
//---------------------------------------------------------------------------



void __fastcall TfBuscarArticulo::Button15Click(TObject *Sender)
{
   Panel6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Button14Click(TObject *Sender)
{
   if(ComboBox1->ItemIndex == -1 || Edit9->Text == "" || Edit10->Text == "0,00")
   {
	  Application->MessageBox(L"Para poder guardar los cambios debe: \nEspecificar un proveedor\nIntroducir un código\nProporcionar un factor de escala mayor a cero",L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      return;
   }

   Panel6->Visible = false;
   if(modificandoProveedor)
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("UPDATE relacionproveedores SET refProveedor = (SELECT idProveedor FROM proveedores WHERE nombre = :nombre), codigo = :codigo, escala = :escala WHERE refArticulo = :refArticulo");
	  QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryAux->ParamByName("nombre")->AsString = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
	  QueryAux->ParamByName("codigo")->AsString = Edit9->Text;
	  QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit10->Text);
	  QueryAux->ExecSQL();
   }
   else
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES (:refArticulo, (SELECT idProveedor FROM proveedores WHERE nombre = :nombre), :codigo, :escala)");
	  QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryAux->ParamByName("nombre")->AsString = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
	  QueryAux->ParamByName("codigo")->AsString = Edit9->Text;
	  QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit10->Text);
	  QueryAux->ExecSQL();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit10Exit(TObject *Sender)
{
   try
   {
	   StrToFloat(dynamic_cast<TEdit *>(Sender)->Text);
   }
   catch (...)
   {
	   dynamic_cast<TEdit *>(Sender)->Text = "0,0";
   }

   Edit10->Text = FormatFloat("0.00", StrToFloat(Edit10->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarArticulo::Edit10KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

