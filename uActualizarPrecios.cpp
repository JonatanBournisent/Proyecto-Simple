//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uActualizarPrecios.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfActualizarPrecios *fActualizarPrecios;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;

//---------------------------------------------------------------------------
__fastcall TfActualizarPrecios::TfActualizarPrecios(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfActualizarPrecios::buscar(void)
{
   if(cbRubro->Text != "")
   {
	  CDS->Active = false;

	  String q = "SELECT COUNT(*) AS nroReg FROM articulos WHERE "
				 "rubro = :rubro ";

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
	  if(cbCantidad->Text != "")
		 q = q + "AND cantidad = :cantidad ";
	  if(cbUnidadMedida->Text != "")
		 q = q + "AND unidadMedida = :unidadMedida ";

	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);

	  Query1->ParamByName("rubro")->AsString = cbRubro->Text;

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
	  if(cbCantidad->Text != "")
		 Query1->ParamByName("cantidad")->AsString = cbCantidad->Text;
	  if(cbUnidadMedida->Text != "")
		 Query1->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

	  Query1->Open();

	  Label9->Caption = Query1->FieldByName("nroReg")->AsString + " registro(s) coincide(n) con este criterio de filtrado.";
      Query1->Close();


	  q = "SELECT idArticulo, rubro, tipo, marca, modelo, tamano, color, cantidad, unidadMedida FROM articulos WHERE "
				 "rubro = :rubro ";

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
	  if(cbCantidad->Text != "")
		 q = q + "AND cantidad = :cantidad ";
	  if(cbUnidadMedida->Text != "")
		 q = q + "AND unidadMedida = :unidadMedida ";

	  q = q + "LIMIT 15";

	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);

	  Query1->ParamByName("rubro")->AsString = cbRubro->Text;

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
	  if(cbCantidad->Text != "")
		 Query1->ParamByName("cantidad")->AsString = cbCantidad->Text;
	  if(cbUnidadMedida->Text != "")
		 Query1->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

	  Query1->Open();
	  CDS->Active = true;
   }
   else
   {
	  CDS->Active = false;
	  Query1->Close();
	  Label9->Caption = "";
   }
}
//---------------------------------------------------------------------------

String TfActualizarPrecios::comaToDot(String str)
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

void __fastcall TfActualizarPrecios::cbRubroChange(TObject *Sender)
{
   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT tipo FROM articulos  WHERE rubro = :rubro ORDER BY tipo");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbTipo->Clear();
   while(!QueryCB->Eof)
   {
	  cbTipo->Items->Add(QueryCB->FieldByName("tipo")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT marca FROM articulos  WHERE rubro = :rubro ORDER BY marca");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbMarca->Clear();
   while(!QueryCB->Eof)
   {
	  cbMarca->Items->Add(QueryCB->FieldByName("marca")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT modelo FROM articulos  WHERE rubro = :rubro ORDER BY modelo");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbModelo->Clear();
   while(!QueryCB->Eof)
   {
	  cbModelo->Items->Add(QueryCB->FieldByName("modelo")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT tamano FROM articulos  WHERE rubro = :rubro ORDER BY tamano");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbTamano->Clear();
   while(!QueryCB->Eof)
   {
	  cbTamano->Items->Add(QueryCB->FieldByName("tamano")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT color FROM articulos  WHERE rubro = :rubro ORDER BY color");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbColor->Clear();
   while(!QueryCB->Eof)
   {
	  cbColor->Items->Add(QueryCB->FieldByName("color")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT cantidad FROM articulos  WHERE rubro = :rubro ORDER BY cantidad");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbCantidad->Clear();
   while(!QueryCB->Eof)
   {
	  cbCantidad->Items->Add(QueryCB->FieldByName("cantidad")->AsString);
	  QueryCB->Next();
   }

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT unidadMedida FROM articulos  WHERE rubro = :rubro ORDER BY unidadMedida");
   QueryCB->ParamByName("rubro")->AsString = cbRubro->Text;
   QueryCB->Open();

   QueryCB->First();
   cbUnidadMedida->Clear();
   while(!QueryCB->Eof)
   {
	  cbUnidadMedida->Items->Add(QueryCB->FieldByName("unidadMedida")->AsString);
	  QueryCB->Next();
   }
   QueryCB->Close();

   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::FormShow(TObject *Sender)
{
   cbRubro->Clear();
   cbTipo->Clear();
   cbMarca->Clear();
   cbModelo->Clear();
   cbTamano->Clear();
   cbColor->Clear();
   cbCantidad->Clear();
   cbUnidadMedida->Clear();

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT DISTINCT rubro FROM articulos ORDER BY rubro");
   QueryCB->Open();

   QueryCB->First();
   cbRubro->Clear();
   while(!QueryCB->Eof)
   {
	  cbRubro->Items->Add(QueryCB->FieldByName("rubro")->AsString);
	  QueryCB->Next();
   }
   QueryCB->Close();

   cbRubro->ItemIndex = -1;
   Label9->Caption = "";

   Edit2->Text = "1,0000";
   Edit3->Text = "1,0000";
   cbRubro->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TfActualizarPrecios::Edit2Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit2->Text);
   }
   catch(...)
   {
	  Edit2->Text = "1,0000";
   }

   Edit2->Text = FormatFloat("0.0000", StrToFloat(Edit2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit3Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit3->Text);
   }
   catch(...)
   {
	  Edit3->Text = "1,0000";
   }

   Edit3->Text = FormatFloat("0.0000", StrToFloat(Edit3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit2Click(TObject *Sender)
{
   Edit2->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit3Click(TObject *Sender)
{
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button1Click(TObject *Sender)
{
   if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los precios de compra que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  if(CDS->Active)
	  {
		 String q = "UPDATE articulos SET precioCompra = (precioCompra * :fm) WHERE "
					"rubro = :rubro ";

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
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";

		 q = q + "LIMIT 15";

		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("rubro")->AsString = cbRubro->Text;

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
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

		 QueryUpdate->ParamByName("fm")->AsFloat = StrToFloat(Edit2->Text);

		 QueryUpdate->ExecSQL();

		 Application->MessageBox(L"Los precios de compra fueron actualizados correctamente",L"Precios actualizados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbTipoChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbMarcaChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbModeloChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbTamanoChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbColorChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbCantidadChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::cbUnidadMedidaChange(TObject *Sender)
{
   buscar();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button2Click(TObject *Sender)
{
   if(Application->MessageBox(L"¡ATENCION! Se van a actualizar los margenes de utilidad que coinciden con el criterio de filtrado. Desea continuar?",L"¡ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
      if(CDS->Active)
	  {
		 String q = "UPDATE articulos SET margenUtilidad = (margenUtilidad * :fm) WHERE "
					"rubro = :rubro ";

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
		 if(cbCantidad->Text != "")
			q = q + "AND cantidad = :cantidad ";
		 if(cbUnidadMedida->Text != "")
			q = q + "AND unidadMedida = :unidadMedida ";

		 q = q + "LIMIT 15";

		 QueryUpdate->Close();
		 QueryUpdate->SQL->Clear();
		 QueryUpdate->SQL->Add(q);

		 QueryUpdate->ParamByName("rubro")->AsString = cbRubro->Text;

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
		 if(cbCantidad->Text != "")
			QueryUpdate->ParamByName("cantidad")->AsString = cbCantidad->Text;
		 if(cbUnidadMedida->Text != "")
			QueryUpdate->ParamByName("unidadMedida")->AsString = cbUnidadMedida->Text;

		 QueryUpdate->ParamByName("fm")->AsFloat = StrToFloat(Edit3->Text);

		 QueryUpdate->ExecSQL();
		 Application->MessageBox(L"Los margenes fueron actualizados correctamente",L"Margenes actualizados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TfActualizarPrecios::Timer1Timer(TObject *Sender)
{
   if(Panel1->Width < 375 || Panel1->Height < 175)
   {
	  if(Panel1->Width < 375)
		 Panel1->Width = Panel1->Width + 9;
	  if(Panel1->Height < 175)
		 Panel1->Height = Panel1->Height + 4;
   }
   else
   {
	  Timer1->Enabled = false;
	  Label10->Visible = true;
	  Edit1->Visible = true;
      Button4->Visible = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit1Click(TObject *Sender)
{
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit1Enter(TObject *Sender)
{
   if(Edit1->Text.Pos("$ ") == 1)
	  Edit1->Text = Edit1->Text.Delete(1,2);
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit1Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit1->Text);
   }
   catch(...)
   {
	  Edit1->Text = "0,00";
   }

   Edit1->Text = FormatFloat("$ 0.00", StrToFloat(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button4Click(TObject *Sender)
{
   if(CDS->Active)
   {
	  String q = "UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :id LIMIT 1";

	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add(q);
	  QueryUpdate->ParamByName("precioCompra")->AsString = comaToDot(Edit1->Text.SubString(3,Edit1->Text.Length()));;
	  QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryUpdate->ExecSQL();

	  Application->MessageBox(L"El precio de compra fue actualizado correctamente",L"Precio actualizado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
      Panel1->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Actualizarprecio1Click(TObject *Sender)
{
   if(!CDS->Active)
      return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT precioCompra FROM articulos WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->Open();

   Edit1->Text = QueryUpdate->FieldByName("precioCompra")->AsString;
   QueryUpdate->Close();

   Edit1Exit(Edit1);


   Panel1->Left = (fActualizarPrecios->Width - Panel1->Width) / 2;
   Panel1->Top = (fActualizarPrecios->Height - Panel1->Height) / 2;
   Panel1->Visible = true;

   /*
   Panel1->Width = 10;
   Panel1->Height = 10;

   Label10->Visible = false;
   Edit1->Visible = false;
   Button4->Visible = false;
   Timer1->Enabled = true;
   */
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button5Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit4KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button6Click(TObject *Sender)
{
   if(CDS->Active)
   {
	  String q = "UPDATE articulos SET margenUtilidad = :margenUtilidad WHERE idArticulo = :id LIMIT 1";

	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add(q);
	  QueryUpdate->ParamByName("margenUtilidad")->AsFloat = 1.0 + StrToFloat(Edit4->Text.SubString(1,Edit4->Text.Length()-2)) / 100.0;
	  QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
	  QueryUpdate->ExecSQL();

	  Application->MessageBox(L"El margen de ganancia fue actualizado correctamente",L"Margen de ganancia actualizado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
      Panel2->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Button7Click(TObject *Sender)
{
   Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit4Enter(TObject *Sender)
{
   if(Edit4->Text.Pos(" %") == Edit4->Text.Length() - 1)
	  Edit4->Text = Edit4->Text.Delete(Edit4->Text.Length()-1,2);
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit4Exit(TObject *Sender)
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

void __fastcall TfActualizarPrecios::Actualizarmargendeganancia1Click(TObject *Sender)
{
   if(!CDS->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT margenUtilidad FROM articulos WHERE idArticulo = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->Open();

   Edit4->Text = FloatToStr((QueryUpdate->FieldByName("margenUtilidad")->AsFloat - 1) * 100);
   QueryUpdate->Close();

   Edit4Exit(Edit4);


   Panel2->Left = (fActualizarPrecios->Width - Panel2->Width) / 2;
   Panel2->Top = (fActualizarPrecios->Height - Panel2->Height) / 2;
   Panel2->Visible = true;
}
//---------------------------------------------------------------------------




void __fastcall TfActualizarPrecios::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS->Active = false;
   Query1->Close();
   QueryCB->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfActualizarPrecios::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      Button4Click(Edit1);
}
//---------------------------------------------------------------------------

void __fastcall TfActualizarPrecios::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
	  Button6Click(Edit2);
}
//---------------------------------------------------------------------------


void __fastcall TfActualizarPrecios::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

