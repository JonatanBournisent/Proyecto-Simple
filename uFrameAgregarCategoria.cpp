//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrameAgregarCategoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAgregarCategoria *fAgregarCategoria;
//---------------------------------------------------------------------------
__fastcall TfAgregarCategoria::TfAgregarCategoria(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void TfAgregarCategoria::inicializarFrame(String nomDB)
{
   nombreDB = nomDB;
   Edit1->Clear();
   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT descripcion FROM " + nombreDB);
   Query1->Open();
   CDS->Active = true;
}

//---------------------------------------------------------------------------
void __fastcall TfAgregarCategoria::Edit1Change(TObject *Sender)
{
   if(Edit1->Text != "")
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT descripcion FROM " + nombreDB + " WHERE UPPER(descripcion) LIKE :d");
	  Query1->ParamByName("d")->AsString = "%" + Edit1->Text.UpperCase() + "%";
	  Query1->Open();

	  CDS->Refresh();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCategoria::Button1Click(TObject *Sender)
{
   if(Application->MessageBox(L"Se va a agregar un nuevo ítem en esta categoría. Desea continuar?",L"Agregar nuevo ítem?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
      return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO " + nombreDB + " VALES(NULL, :d)");
   QueryAux->ParamByName("d")->AsString = Edit1->Text;
   QueryAux->ExecSQL();

   CDS->Refresh();
}
//---------------------------------------------------------------------------

