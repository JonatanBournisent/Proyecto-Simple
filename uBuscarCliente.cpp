//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uBuscarCliente.h"
#include "uAgregarCliente.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfBuscarCliente *fBuscarCliente;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfBuscarCliente::TfBuscarCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarCliente::Edit1Change(TObject *Sender)
{
   if(Edit1->Text != "")
   {
	  CDS->Active = false;
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT * FROM clientes WHERE UPPER(nombre) LIKE _utf8 :texto COLLATE utf8_general_ci OR UPPER(apellido) LIKE _utf8 :texto COLLATE utf8_general_ci OR UPPER(razonSocial) LIKE _utf8 :texto COLLATE utf8_general_ci ORDER BY apellido");
	  Query1->ParamByName("texto")->AsString = "%" + Edit1->Text.UpperCase() + "%";
	  Query1->Open();
	  CDS->Active = true;
   }
   else
   {
      CDS->Active = false;
	  Query1->Close();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarCliente::DBGrid1DblClick(TObject *Sender)
{
   if(CDS->Active)
   {
	  idSeleccionado = CDS->FieldByName("idCliente")->AsInteger;
	  fBuscarCliente->Close();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarCliente::FormShow(TObject *Sender)
{
   idSeleccionado = 0;
   CheckBox1->Checked = false;
   Edit1->Clear();
   CDS->Active = false;
   Query1->Close();
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfBuscarCliente::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS->Active = false;
   Query1->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN && CDS->Active)
   {
	  idSeleccionado = CDS->FieldByName("idCliente")->AsInteger;
	  fBuscarCliente->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::Edit1Enter(TObject *Sender)
{
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_DOWN && CDS->Active)
	  DBGrid1->SetFocus();
   else if(Key == VK_RETURN && CDS->RecordCount == 1)
   {
	  idSeleccionado = CDS->FieldByName("idCliente")->AsInteger;
	  fBuscarCliente->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::Button1Click(TObject *Sender)
{
   fAgregarCliente->paraModificar = false;
   fAgregarCliente->ShowModal();
   Edit1Change(fBuscarCliente);
   if(CDS->Active)
	  DBGrid1->SetFocus();
   else
	  Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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


void __fastcall TfBuscarCliente::DBGrid1TitleClick(TColumn *Column)
{
   if(!CDS->Active)
	  return;

   String a = Column->Field->Name;
   a = a.Delete(1,3);

   String q;

   if(CheckBox1->Checked)
   {
	  q = "SELECT * FROM clientes ";
   }
   else
   {
	  q = "SELECT * FROM clientes WHERE UPPER(nombre) LIKE _utf8 :texto COLLATE utf8_general_ci OR UPPER(apellido) LIKE _utf8 :texto COLLATE utf8_general_ci OR UPPER(razonSocial) LIKE _utf8 :texto COLLATE utf8_general_ci ";
   }

   q = q + "ORDER BY " + a;


   CDS->Active = false;
   Query1->Close();

   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   if(!CheckBox1->Checked)
      Query1->ParamByName("texto")->AsString = "%" + Edit1->Text.UpperCase() + "%";
   Query1->Open();
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
   {
	  Edit1->Clear();
	  Edit1->Enabled = false;

	  CDS->Active = false;
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT * FROM clientes");
	  Query1->Open();
      CDS->Active = true;
   }
   else
   {
	  Edit1->Enabled = true;
	  Edit1Change(Edit1);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfBuscarCliente::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

