//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uSorteo.h"
#include "Math.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfSorteo *fSorteo;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfSorteo::TfSorteo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Button1Click(TObject *Sender)
{
		QueryUpdate->Close();
		CDS->Active = false;
		Query1->Close();
		Label1->Visible = false;
   Image1->Visible = false;
   Panel1->Visible = false;
   Panel3->Visible = false;
   DBText1->Visible = false;
   Label2->Visible = true;
   Label2->Caption = "";

	  Label2->Caption = "Primero lo primero... ¡¡A mezclar!!";
	  Label2->Repaint();
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("DELETE FROM sorteo");
	  QueryUpdate->ExecSQL();

	  TStringList *Lista;
	  Lista = new TStringList();

	  ListaHistorias = new TStringList();

	  Lista->LoadFromFile("Lista.txt");
	  int d = 0;
	  while(d < Lista->Count)
	  {
		 if(Lista->Strings[d].Pos("Foto del perfil") == 1)
		 {
			d = d + 1;
			QueryUpdate->Close();
			QueryUpdate->SQL->Clear();
			QueryUpdate->SQL->Add("INSERT INTO sorteo (nombre) VALUES (:nombre)");
			QueryUpdate->ParamByName("nombre")->AsString = Lista->Strings[d];
			QueryUpdate->ExecSQL();
			d = d + 2;
		 }
		 d++;
	  }

	  d = 0;
	  while(d < Lista->Count)
	  {
		 if(Lista->Strings[d] == "$%HISTORIAS")
		 {
			d = d + 1;
			while(Lista->Strings[d] != "$%FINHISTORIAS")
			{
			   QueryUpdate->Close();
			   QueryUpdate->SQL->Clear();
			   QueryUpdate->SQL->Add("INSERT INTO sorteo (nombre) VALUES (:nombre)");
			   QueryUpdate->ParamByName("nombre")->AsString = Lista->Strings[d].Delete(1,1);
			   QueryUpdate->ExecSQL();
			   ListaHistorias->Add(Lista->Strings[d].Delete(1,1));
			   d++;
			   if(d >= Lista->Count)
			      break;
			}
		 }
		 d++;
	  }


	  delete Lista;

      Label2->Color = clRed;

//	  for(int k = 0; k < 25 ; k++)
//	  {
//		  CDS->Active = false;
//		  Query1->Close();
//		  Query1->SQL->Clear();
//		  Query1->SQL->Add("SELECT nombre FROM sorteo ORDER BY RAND()");
//		  Query1->Open();
//		  CDS->Active = true;
//
//		  DBGrid1->Repaint();
//		  DBGrid1->Refresh();
//
//
//
//		  Sleep(100);
//	  }

	  k = 0;
	  Timer6->Enabled = true;

//	  Label2->Visible = false;
//	  DBText1->Visible = true;
//
//
//	  limite = random(CDS->RecordCount * 0.5 + aleatorio);
//
//	  ih = 0;
//	  Panel3->Visible = true;
//	  Panel3->Refresh();
//	  Panel3->Repaint();
//	  Timer5->Enabled = true;

//	  ShowMessage(limite);
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Button2Click(TObject *Sender)
{
   Timer1->Interval = 30;
   i = 0;
   j = 0;
   Timer2->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer1Timer(TObject *Sender)
{
   if(Timer1->Interval < 500)
   {
	  CDS->Next();
//	  Timer1->Interval = 1000 * (1 - Exp(i * -0.05)) + 50;
	  if((510 - Timer1->Interval) > 300)
		 Timer1->Interval = Timer1->Interval + ((510 - Timer1->Interval) / 15);
	  else if((510 - Timer1->Interval) > 200)
		 Timer1->Interval = Timer1->Interval + ((510 - Timer1->Interval) / 10);
	  else if((510 - Timer1->Interval) > 100)
		 Timer1->Interval = Timer1->Interval + ((510 - Timer1->Interval) / 5);
	  else
	     Timer1->Interval = Timer1->Interval + ((510 - Timer1->Interval) / 2);
	  i++;

	  if(CDS->Eof)
		 CDS->First();
   }
   else
   {
	  Timer1->Enabled = false;
	  Label1->Visible = true;
	  Image1->Visible = true;
	  Timer3->Enabled = true;
	  Panel1->Visible = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer2Timer(TObject *Sender)
{
   if(j < limite)
   {
//	  Timer2->Interval = 30 + ((j / limite) * 50);
	  CDS->Next();
	  j++;
	  if(CDS->Eof)
		 CDS->First();
   }
   else
   {
	  Timer2->Enabled = false;
	  Timer1->Enabled = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::FormShow(TObject *Sender)
{
   Label1->Visible = false;
   Image1->Visible = false;
   Panel1->Visible = false;
   Panel3->Visible = false;
   DBText1->Visible = false;
   Label2->Visible = true;
   Label2->Caption = "";

}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer3Timer(TObject *Sender)
{
   if(Label1->Visible)
	  Label1->Visible = false;
   else
      Label1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::FormCreate(TObject *Sender)
{
   aleatorio = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer4Timer(TObject *Sender)
{
   aleatorio++;
   if(aleatorio >= (limite / 2))
      aleatorio = random(limite);
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer5Timer(TObject *Sender)
{
   if(ih < ListaHistorias->Count)
   {
	  Label4->Caption = ListaHistorias->Strings[ih];
	  Label4->Refresh();
	  Label4->Repaint();
	  ih++;
   }
   else
   {
	  Timer5->Enabled = false;
	  Panel3->Visible = false;
	  Button2Click(Button2);
   }
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete ListaHistorias;
   QueryUpdate->Close();
   CDS->Active = false;
   Query1->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfSorteo::Timer6Timer(TObject *Sender)
{
   if(k < 25)
   {
		  CDS->Active = false;
		  Query1->Close();
		  Query1->SQL->Clear();
		  Query1->SQL->Add("SELECT nombre FROM sorteo ORDER BY RAND()");
		  Query1->Open();
		  CDS->Active = true;

		  DBGrid1->Repaint();
		  DBGrid1->Refresh();
		  k++;
   }
   else
   {
	  Timer6->Enabled = false;
      Label2->Visible = false;
	  DBText1->Visible = true;


	  limite = random(CDS->RecordCount * 0.5 + aleatorio);

	  ih = 0;
	  Panel3->Visible = true;
	  Label4->Caption = "";
	  Panel3->Refresh();
	  Panel3->Repaint();

	  Sleep(750);
	  Timer5->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfSorteo::Label2Click(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

