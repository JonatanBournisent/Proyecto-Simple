//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uVerProveedores.h"
#include "uBuscarProveedor.h"
#include "uBuscarCliente.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfVerProveedores *fVerProveedores;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfVerProveedores::TfVerProveedores(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfVerProveedores::FormShow(TObject *Sender)
{
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT idRelacionProveedor, codigo, precio, "
					"(SELECT nombre FROM proveedores WHERE relacionproveedores.refProveedor = proveedores.idProveedor LIMIT 1) AS nombre, "
					"(SELECT domicilio FROM proveedores WHERE relacionproveedores.refProveedor = proveedores.idProveedor LIMIT 1) AS domicilio, "
					"(SELECT telefono FROM proveedores WHERE relacionproveedores.refProveedor = proveedores.idProveedor LIMIT 1) AS telefono, "
					"(SELECT celular FROM proveedores WHERE relacionproveedores.refProveedor = proveedores.idProveedor LIMIT 1) AS celular, "
					"(SELECT cuit FROM proveedores WHERE relacionproveedores.refProveedor = proveedores.idProveedor LIMIT 1) AS cuit "
					"FROM relacionproveedores WHERE refArticulo = :idArticulo ORDER BY nombre");
   Query1->ParamByName("idArticulo")->AsInteger = idArticulo;
   Query1->Open();
   CDS1->Active = true;

   Button1->Enabled = true;
   Panel1->Visible = false;

   Panel1->Left = (fVerProveedores->Width - Panel1->Width) / 2;
   Panel1->Top = (fVerProveedores->Height - Panel1->Height) / 2;
}
//---------------------------------------------------------------------------
void __fastcall TfVerProveedores::Quitaresteproveedordelalista1Click(TObject *Sender)

{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM relacionproveedores WHERE idRelacionProveedor = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = CDS1->FieldByName("idRelacionProveedor")->AsInteger;
   QueryAux->ExecSQL();
   CDS1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfVerProveedores::Button1Click(TObject *Sender)
{
   fBuscarProveedor->ShowModal();

   if(fBuscarProveedor->idSeleccionado == 0)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRelacionProveedor FROM relacionproveedores WHERE refArticulo = :refArticulo AND refProveedor = :refProveedor LIMIT 1");
   QueryAux->ParamByName("refArticulo")->AsInteger = idArticulo;
   QueryAux->ParamByName("refProveedor")->AsInteger = fBuscarProveedor->idSeleccionado;
   QueryAux->Open();
   if(!QueryAux->IsEmpty())
   {
	  Application->MessageBox(L"Este proveedor ya se encuentra asignado a este artículo",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  fBuscarProveedor->idSeleccionado = 0;
	  QueryAux->Close();
	  return;
   }
   QueryAux->Close();

   Button1->Enabled = false;
   Edit1->Text = "0";
   Edit3->Text = "0,00";
   Panel1->Visible = true;
   Edit1->SetFocus();
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::Button2Click(TObject *Sender)
{
   if(Edit1->Text == "" || fBuscarProveedor->idSeleccionado == 0)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES "
					  "(:refArticulo, :refProveedor, :codigo, :escala)");
   QueryAux->ParamByName("refProveedor")->AsInteger = fBuscarProveedor->idSeleccionado;
   QueryAux->ParamByName("refArticulo")->AsInteger = idArticulo;
   QueryAux->ParamByName("codigo")->AsString = Edit1->Text;
   QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit3->Text);
   QueryAux->ExecSQL();

   Button1->Enabled = true;
   Panel1->Visible = false;

   CDS1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::Button3Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->Active = false;
   Query1->Close();
   QueryAux->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfVerProveedores::Edit3Exit(TObject *Sender)
{
   String s = dynamic_cast<TEdit *>(Sender)->Text;

   try
   {
	  StrToFloat(s);
   }
   catch(...)
   {
      s = "0,00";
   }

   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("0.00", StrToFloat(s));
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfVerProveedores::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

