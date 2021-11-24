//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockYFV.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfStockYFV *fStockYFV;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfStockYFV::TfStockYFV(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TfStockYFV::buscar(int filtro, String orden)
{
   String q;

   if(filtro == 0)
   {
      q = "SELECT idArticulo, stock, proximoVencimiento, "
		  "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombre "
		  "FROM articulos WHERE nombreCompleto NOT LIKE '%SORPRESA%' ";

	  if(cbRubro->ItemIndex > 0)
	     q = q + " AND refRubro = " + IntToStr(cbRubro->ItemIndex);



	  if(orden != "")
	     q = q + " ORDER BY " + orden;

	  CDS->Active = false;
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);
	  Query1->Open();
	  CDS->Active = true;
   }
   else if(filtro == 1)
   {
	  q = "SELECT idArticulo, stock, proximoVencimiento, "
		  "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombre "
		  "FROM articulos WHERE stock <= :stock ";

      if(cbRubro->ItemIndex > 0)
	     q = q + " AND refRubro = " + IntToStr(cbRubro->ItemIndex);

	  q = q + " AND nombreCompleto NOT LIKE '%SORPRESA%' ";

	  if(orden != "")
		 q = q + " ORDER BY " + orden;

	  CDS->Active = false;
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);
	  Query1->ParamByName("stock")->AsInteger = SpinEdit1->Value;
	  Query1->Open();
	  CDS->Active = true;
   }
   else if(filtro == 2)
   {
	  q = "SELECT idArticulo, stock, proximoVencimiento, "
		  "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombre "
		  "FROM articulos WHERE stock = :stock ";

      if(cbRubro->ItemIndex > 0)
	     q = q + " AND refRubro = " + IntToStr(cbRubro->ItemIndex);

	  q = q + " AND nombreCompleto NOT LIKE '%SORPRESA%' ";
	  if(orden != "")
		 q = q + " ORDER BY " + orden;

	  CDS->Active = false;
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add(q);
	  Query1->ParamByName("stock")->AsInteger = SpinEdit2->Value;
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
void __fastcall TfStockYFV::FormShow(TObject *Sender)
{
   blockSE = true;

   RG1->ItemIndex = 0;
   SpinEdit1->Value = 0;
   SpinEdit1->Enabled = false;
   SpinEdit2->Value = 0;
   SpinEdit2->Enabled = false;

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT * FROM rubros ORDER BY idRubro");
   QueryCB->Open();

   QueryCB->First();
   cbRubro->Clear();
   cbRubro->Items->Add("TODAS");
   while(!QueryCB->Eof)
   {
	  cbRubro->Items->Add(QueryCB->FieldByName("descripcion")->AsString);
	  QueryCB->Next();
   }
   QueryCB->Close();
   cbRubro->ItemIndex = 0;


   blockSE = false;

   buscar(RG1->ItemIndex, "idArticulo");
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::RG1Click(TObject *Sender)
{
   blockSE = true;
   if(RG1->ItemIndex == 0)
   {
	  SpinEdit1->Value = 0;
	  SpinEdit2->Value = 0;
	  SpinEdit1->Enabled = false;
	  SpinEdit2->Enabled = false;
   }
   else if(RG1->ItemIndex == 1)
   {
      SpinEdit1->Value = 0;
	  SpinEdit2->Value = 0;
	  SpinEdit1->Enabled = true;
	  SpinEdit2->Enabled = false;
   }
   else if(RG1->ItemIndex == 2)
   {
      SpinEdit1->Value = 0;
	  SpinEdit2->Value = 0;
	  SpinEdit1->Enabled = false;
	  SpinEdit2->Enabled = true;
   }
   blockSE = false;

   buscar(RG1->ItemIndex, "idArticulo");
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::FormClose(TObject *Sender, TCloseAction &Action)
{
   CDS->Active = false;
   Query1->Close();
   QueryCB->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::DBGrid1TitleClick(TColumn *Column)
{
   if(!CDS->Active)
	  return;

   String a = Column->Field->Name;
   a = a.Delete(1,3);

   if(a == "idArticulo")
	  a = "idArticulo, nombre, stock, proximoVencimiento";
   else if(a == "nombre")
	  a = "nombre, stock, proximoVencimiento";
   else if(a == "stock")
	  a = "stock, nombre, proximoVencimiento";
   else if(a == "proximoVencimiento")
	  a = "proximoVencimiento, nombre, stock";

   buscar(RG1->ItemIndex, a);
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::CDSproximoVencimientoGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(Sender->AsString == "01/01/2100")
	  Text = "N/A";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfStockYFV::SpinEdit1Change(TObject *Sender)
{
   if(blockSE)
	  return;

   buscar(RG1->ItemIndex, "stock");
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::SpinEdit2Change(TObject *Sender)
{
   if(blockSE)
	  return;

   buscar(RG1->ItemIndex, "idArticulo");
}
//---------------------------------------------------------------------------
void __fastcall TfStockYFV::cbRubroChange(TObject *Sender)
{
   buscar(RG1->ItemIndex, "idArticulo");
}
//---------------------------------------------------------------------------

void __fastcall TfStockYFV::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

