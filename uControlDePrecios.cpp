//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uControlDePrecios.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfControlDePrecios *fControlDePrecios;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfControlDePrecios::TfControlDePrecios(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfControlDePrecios::mostrar(void)
{
   String q;

   q = "SELECT * FROM (SELECT idArticulo, refRubro, precioCompra, stock, (SELECT IFNULL(refProveedor, 0) FROM relacionproveedores WHERE articulos.idArticulo = relacionproveedores.refArticulo LIMIT 1) AS refProveedor, (SELECT IFNULL((SELECT nombre FROM proveedores WHERE idProveedor = (SELECT refProveedor FROM relacionproveedores WHERE articulos.idArticulo = relacionproveedores.refArticulo) LIMIT 1), 'N/A')) AS nombreProv, "
	   "(IFNULL((SELECT codigo FROM relacionproveedores WHERE relacionproveedores.refArticulo = articulos.idArticulo LIMIT 1), '0')) AS codigoProv, "
	   "(IFNULL((SELECT escala FROM relacionproveedores WHERE relacionproveedores.refArticulo = articulos.idArticulo LIMIT 1), 1)) AS escala, "
	   "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombre "
	   "FROM articulos)t ";

   if(ComboBox1->ItemIndex > 0)
      q = q + " WHERE t.refProveedor = (SELECT idProveedor FROM proveedores WHERE proveedores.nombre = :nombre LIMIT 1) ";

   if(ComboBox1->ItemIndex > 0 && ComboBox2->ItemIndex > 0)
	  q = q + " AND t.refRubro = " + IntToStr(ComboBox2->ItemIndex);
   else if(ComboBox2->ItemIndex > 0)
	  q = q + " WHERE t.refRubro = " + IntToStr(ComboBox2->ItemIndex);


   q = q + " ORDER BY nombre ";

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);

   if(ComboBox1->ItemIndex > 0)
	  Query1->ParamByName("nombre")->AsString = ComboBox1->Items->Strings[ComboBox1->ItemIndex];

   Query1->Open();
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);

   if(CDS->IsEmpty())
   {
	  CDS->Active = false;
	  Query1->Close();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::FormShow(TObject *Sender)
{
   Panel6->Visible = false;
   CheckBox1->Checked = false;
   CheckBox2->Checked = false;
   CDS->Fields->Fields[6]->ReadOnly = true;
   CDS->Fields->Fields[7]->ReadOnly = true;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT nombre FROM proveedores ORDER BY nombre");
   QueryAux->Open();

   ComboBox1->Clear();
   ComboBox3->Clear();
   QueryAux->First();
   ComboBox1->Items->Add("");
   while(!QueryAux->Eof)
   {
	  ComboBox1->Items->Add(QueryAux->FieldByName("nombre")->AsString);
	  ComboBox3->Items->Add(QueryAux->FieldByName("nombre")->AsString);
	  QueryAux->Next();
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT * FROM rubros ORDER BY idRubro");
   QueryAux->Open();

   ComboBox2->Clear();
   QueryAux->First();
   ComboBox2->Items->Add("");
   while(!QueryAux->Eof)
   {
	  ComboBox2->Items->Add(QueryAux->FieldByName("descripcion")->AsString);
	  QueryAux->Next();
   }
   QueryAux->Close();

   ComboBox1->ItemIndex = -1;
   ComboBox2->ItemIndex = -1;

   Panel1->Visible = false;
   ChB->Checked = false;
   CDS->Active = false;

   mostrar();
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS->Active = false;
   Query1->Close();

   CDS2->Active = false;
   Query2->Close();

   QueryUpdate->Close();
   QueryAux->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::CDScodigoProvChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRelacionProveedor from relacionproveedores WHERE refArticulo = :refArticulo LIMIT 1");
   QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES (:refArticulo, :refProveedor, :codigoProv, :escala)");
	  QueryUpdate->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryUpdate->ParamByName("refProveedor")->AsInteger = CDS->FieldByName("refProveedor")->AsInteger;
	  QueryUpdate->ParamByName("escala")->AsFloat = CDS->FieldByName("escala")->AsFloat;
	  QueryUpdate->ParamByName("codigoProv")->AsString = CDS->FieldByName("codigoProv")->AsString;
	  QueryUpdate->ExecSQL();
   }
   else
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE relacionproveedores SET codigo = :codigoProv WHERE idRelacionProveedor = :idRelacionProveedor LIMIT 1");
	  QueryUpdate->ParamByName("idRelacionProveedor")->AsInteger = QueryAux->FieldByName("idRelacionProveedor")->AsInteger;
	  QueryUpdate->ParamByName("codigoProv")->AsString = CDS->FieldByName("codigoProv")->AsString;
	  QueryUpdate->ExecSQL();
   }
   QueryAux->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::CDSescalaChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRelacionProveedor from relacionproveedores WHERE refArticulo = :refArticulo LIMIT 1");
   QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES (:refArticulo, :refProveedor, :codigoProv, :escala)");
	  QueryUpdate->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryUpdate->ParamByName("refProveedor")->AsInteger = CDS->FieldByName("refProveedor")->AsInteger;
	  QueryUpdate->ParamByName("escala")->AsFloat = CDS->FieldByName("escala")->AsFloat;
	  QueryUpdate->ParamByName("codigoProv")->AsString = CDS->FieldByName("codigoProv")->AsString;
	  QueryUpdate->ExecSQL();
   }
   else
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE relacionproveedores SET escala = :escala WHERE idRelacionProveedor = :idRelacionProveedor LIMIT 1");
	  QueryUpdate->ParamByName("idRelacionProveedor")->AsInteger = QueryAux->FieldByName("idRelacionProveedor")->AsInteger;
	  QueryUpdate->ParamByName("escala")->AsFloat = CDS->FieldByName("escala")->AsFloat;
	  QueryUpdate->ExecSQL();
   }
   QueryAux->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::Button1Click(TObject *Sender)
{
   TStringList *codigosProv;
   TStringList *preciosProv;
   TStringList *archivo;

   codigosProv = new TStringList();
   preciosProv = new TStringList();
   archivo = new TStringList();

   String linea, palabra;
   int idx_codigo = StrToInt(Edit1->Text) - 1;
   int idx_precio = StrToInt(Edit2->Text) - 1;
   bool encontrado = false;
   errores = 0;

   archivo->Clear();
   Application->MessageBox(L"Indique la ubicación de la nueva lista de precios",L"Seleccionar origen de datos",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   if(OD1->Execute())
   {
	  archivo->LoadFromFile(OD1->FileName);
   }
   else
   {
	  ShowMessage("ERROR: No se pudo importar");
	  return;
   }

   preciosProv->Clear();
   codigosProv->Clear();
   float valor;

   for(int j = 1; j < archivo->Count; j++)
   {
	  linea = archivo->Strings[j] + ";";
	  for(int c = 0; c < idx_codigo; c++)
	  {
		 linea = linea.Delete(1, linea.Pos(";"));
	  }
	  palabra = linea.SubString(1, linea.Pos(";") - 1);
	  codigosProv->Add(palabra);

	  linea = archivo->Strings[j] + ";";
	  for(int c = 0; c < idx_precio; c++)
	  {
		 linea = linea.Delete(1, linea.Pos(";"));
	  }
	  palabra = linea.SubString(1, linea.Pos(";") - 1);
	  if(palabra.Pos(".") > 0)
		 palabra = palabra.Delete(palabra.Pos("."),1);

	  preciosProv->Add(palabra);
   }

   CDS2->Active = false;

   String q;

   q = "SELECT * FROM (SELECT idArticulo, precioCompra AS precioActual, (SELECT IFNULL(refProveedor, 0) FROM relacionproveedores WHERE articulos.idArticulo = relacionproveedores.refArticulo LIMIT 1) AS refProveedor, (SELECT IFNULL((SELECT nombre FROM proveedores WHERE idProveedor = (SELECT refProveedor FROM relacionproveedores WHERE articulos.idArticulo = relacionproveedores.refArticulo) LIMIT 1), 'N/A')) AS nombreProv, "
	   "(IFNULL((SELECT codigo FROM relacionproveedores WHERE relacionproveedores.refArticulo = articulos.idArticulo LIMIT 1), '0')) AS codigoProv, "
	   "(IFNULL((SELECT escala FROM relacionproveedores WHERE relacionproveedores.refArticulo = articulos.idArticulo LIMIT 1), 1)) AS escala, "
	   "(SELECT 000000.00) AS precioProv, "
	   "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombre "
	   "FROM articulos WHERE refRubro = 1)t WHERE codigoProv <> '0' AND refProveedor = 1 ORDER BY nombre";
                                            //WHERE codigoProv <> '0'
   Query2->Close();
   Query2->SQL->Clear();
   Query2->SQL->Add(q);
   Query2->Open();
   CDS2->Active = true;

   if(CDS2->IsEmpty())
   {
	  CDS2->Active = false;
	  Query2->Close();
	  return;
   }

   CDS2->First();

   while(!CDS2->Eof)
   {
	  CDS2->Edit();

	  if(codigosProv->IndexOf(CDS2->FieldByName("codigoProv")->AsString) >= 0)
	  {
		 valor  = StrToFloat(preciosProv->Strings[codigosProv->IndexOf(CDS2->FieldByName("codigoProv")->AsString)]);
		 valor = valor * (1 - (StrToFloat(Edit3->Text.SubString(1,Edit3->Text.Pos(" ") - 1)) / 100.0));
		 valor = valor / CDS2->FieldByName("escala")->AsFloat;
		 CDS2->FieldByName("precioProv")->AsFloat = valor;
	  }
	  else
	  {
         CDS2->FieldByName("precioProv")->AsFloat = -1;
	  }
	  CDS2->Next();
   }

   ShowMessage("Cantidad de registros: " + IntToStr(CDS2->RecordCount));

   delete preciosProv;
   delete codigosProv;
   delete archivo;
}
//---------------------------------------------------------------------------
void __fastcall TfControlDePrecios::DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect,
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

   if(CDS2->FieldByName("precioActual")->AsFloat != CDS2->FieldByName("precioProv")->AsFloat)
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clRed;

   if(CDS2->FieldByName("precioProv")->AsFloat == -1)
   {
      dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clBlue;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Style = TFontStyles() << fsBold;
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button2Click(TObject *Sender)
{
   Panel1->Visible = false;
   CDS2->Active = false;
   Query2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button3Click(TObject *Sender)
{
   Panel1->Visible = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b')
      Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b')
      Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit3Enter(TObject *Sender)
{
   if(dynamic_cast<TEdit *>(Sender)->Text.Pos("%") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = dynamic_cast<TEdit *>(Sender)->Text.Delete(dynamic_cast<TEdit *>(Sender)->Text.Length()-1,2);
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit3Exit(TObject *Sender)
{
   String s = Edit3->Text;

   try
   {
	  if(s.Pos("%") > 0)
		 s = s.SubString(1,s.Length() - 2);

	  StrToFloat(s);
   }
   catch(...)
   {
	  s = "0,00";
   }

   Edit3->Text = FormatFloat("0.00 %", StrToFloat(s));
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button4Click(TObject *Sender)
{
   if(!CDS2->Active)
	  return;

   if(Application->MessageBox(L"Se van a actualizar TODOS los precios. Es recomentable realizar antes un respaldo de la base de datos. Realmente desea continuar con la actualización?",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   if(Application->MessageBox(L"Desea actualizar TODOS los precios? (Doble verificación)",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   DBGrid2->Enabled = false;
   CDS2->First();
   while(!CDS2->Eof)
   {
	  if(CDS2->FieldByName("precioProv")->AsFloat > 0.0)
	  {
		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add("UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :idArticulo LIMIT 1");
		 QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS2->FieldByName("idArticulo")->AsInteger;
		 QueryUpdate->ParamByName("precioCompra")->AsFloat = CDS2->FieldByName("precioProv")->AsFloat;
		 QueryUpdate->ExecSQL();
      }
	  CDS2->Next();
   }
   DBGrid2->Enabled = true;
   CDS2->Active = false;
   CDS2->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::DBGrid2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(!CDS2->Active)
	  return;

   if(ChB->Checked && Key == '+' && CDS2->FieldByName("precioProv")->AsFloat > 0.0)
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :idArticulo LIMIT 1");
	  QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS2->FieldByName("idArticulo")->AsInteger;
	  QueryUpdate->ParamByName("precioCompra")->AsFloat = CDS2->FieldByName("precioProv")->AsFloat;
	  QueryUpdate->ExecSQL();

	  CDS2->Edit();
	  CDS2->FieldByName("precioActual")->AsFloat = CDS2->FieldByName("precioProv")->AsFloat;
	  CDS2->Post();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button5Click(TObject *Sender)
{
   float porc = 0.0;
   float acumPorc = 0.0;
   int cant = 0;
   CDS2->First();
   while(!CDS2->Eof)
   {
	  if(CDS2->FieldByName("precioProv")->AsFloat > 0.0)
	  {
		 porc =  CDS2->FieldByName("precioProv")->AsFloat / CDS2->FieldByName("precioActual")->AsFloat;
		 porc = (porc - 1) * 100.0;
		 acumPorc = acumPorc + porc;
		 cant++;
	  }
	  CDS2->Next();
   }
   ShowMessage("Aumento promedio: " + FormatFloat("0.00 %", (acumPorc/(cant * 1.0))));
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button6Click(TObject *Sender)
{
//   TStringList *lista;
//   lista = new TStringList();
//
//   CDS->First();
//   while(!CDS->Eof)
//   {
//	  if(CDS->FieldByName("codigoProv")->AsString != "0")
//	  lista->Add(CDS->FieldByName("idArticulo")->AsString + "," + CDS->FieldByName("codigoProv")->AsString + "," + CDS->FieldByName("escala")->AsString);
//	  CDS->Next();
//   }
//
//
//   lista->SaveToFile("archivo");
//
//   delete lista;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button7Click(TObject *Sender)
{
//   TStringList *lista;
//   lista = new TStringList();
//   lista->LoadFromFile("archivo");
//
//   String a;
//
//   String b, c, d;
//   for(int i = 0; i < lista->Count; i++)
//   {
//	  a = lista->Strings[i];
//	  b = a.SubString(1,a.Pos(",") - 1);
//	  a = a.Delete(1,a.Pos(","));
//	  c = a.SubString(1,a.Pos(",") - 1);
//	  a = a.Delete(1,a.Pos(","));
//	  d = a;
//
//         QueryAux->Close();
//   QueryAux->SQL->Clear();
//   QueryAux->SQL->Add("SELECT idRelacionProveedor from relacionproveedores WHERE refArticulo = :refArticulo LIMIT 1");
//   QueryAux->ParamByName("refArticulo")->AsInteger = StrToInt(b);
//   QueryAux->Open();
//   if(QueryAux->IsEmpty())
//   {
//	  QueryUpdate->Close();
//	  QueryUpdate->SQL->Clear();
//	  QueryUpdate->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES (:refArticulo, :refProveedor, :codigoProv, :escala)");
//	  QueryUpdate->ParamByName("refArticulo")->AsInteger = StrToInt(b);
//	  QueryUpdate->ParamByName("refProveedor")->AsInteger = 1;
//	  QueryUpdate->ParamByName("escala")->AsFloat = StrToFloat(d);
//	  QueryUpdate->ParamByName("codigoProv")->AsString = c;
//	  QueryUpdate->ExecSQL();
//   }
//   QueryAux->Close();
//
//   }
//
//
//   delete lista;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::ComboBox1Click(TObject *Sender)
{
   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::ComboBox2Change(TObject *Sender)
{
   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::AsociarCambiarproveedor1Click(TObject *Sender)

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
	  ComboBox3->ItemIndex = -1;
	  Edit9->Text = "0";
	  Edit10->Text = "0,00";
	  modificandoProveedor = false;
   }
   else
   {
	  modificandoProveedor = true;
	  ComboBox3->ItemIndex = ComboBox3->Items->IndexOf(QueryAux->FieldByName("nombre")->AsString);
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
   ComboBox3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button14Click(TObject *Sender)
{
   if(ComboBox3->ItemIndex == -1 || Edit9->Text == "" || Edit10->Text == "0,00")
   {
	  Application->MessageBox(L"Para poder guardar los cambios debe: \nEspecificar un proveedor\nIntroducir un código\nProporcionar un factor de escala mayor a cero",L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      return;
   }

   int recSel = CDS->RecNo;

   Panel6->Visible = false;
   if(modificandoProveedor)
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("UPDATE relacionproveedores SET refProveedor = (SELECT idProveedor FROM proveedores WHERE nombre = :nombre), codigo = :codigo, escala = :escala WHERE refArticulo = :refArticulo");
	  QueryAux->ParamByName("refArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryAux->ParamByName("nombre")->AsString = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
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
	  QueryAux->ParamByName("nombre")->AsString = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
	  QueryAux->ParamByName("codigo")->AsString = Edit9->Text;
	  QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit10->Text);
	  QueryAux->ExecSQL();
   }

   mostrar();

   if(!CDS->Active)
      return;

   if(recSel < CDS->RecordCount)
	  CDS->RecNo = recSel;
   else
      CDS->Last();

}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Button15Click(TObject *Sender)
{
   Panel6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::Edit10Exit(TObject *Sender)
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

void __fastcall TfControlDePrecios::Edit10KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(DBGrid1->SelectedIndex == 5)
   {
	  if(Key == '.')
		 Key = ',';
	  if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
		 Key = NULL;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::CDSprecioCompraChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("precioCompra")->AsFloat = CDS->FieldByName("precioCompra")->AsFloat;
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
   {
	  CDS->Fields->Fields[6]->ReadOnly = false;
   }
   else
	  CDS->Fields->Fields[6]->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::CheckBox2Click(TObject *Sender)
{
   if(CheckBox2->Checked)
   {
	  CDS->Fields->Fields[7]->ReadOnly = false;
   }
   else
	  CDS->Fields->Fields[7]->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::CDSstockChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET stock = :stock WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("stock")->AsFloat = CDS->FieldByName("stock")->AsFloat;
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfControlDePrecios::FormCreate(TObject *Sender)
{
   Panel1->Top = DBGrid1->Top;
   Panel1->Left = DBGrid1->Left;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

