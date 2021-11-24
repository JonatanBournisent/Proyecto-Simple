//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <FileCtrl.hpp>
#pragma hdrstop

#include "uConfiguraciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfConfiguraciones *fConfiguraciones;
//---------------------------------------------------------------------------
__fastcall TfConfiguraciones::TfConfiguraciones(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormShow(TObject *Sender)
{
	  TIniFile *Configuraciones;
	  String Dir = GetCurrentDir()+"//Config.ini";
      Configuraciones = new TIniFile(Dir);

      if(printer->Printers->Count != 0)
	  {
		 cboPrinterEtiquetas->Items->Assign(printer->Printers);
		 cboPrinterEtiquetas->ItemIndex = printer->PrinterIndex;
		 cboPrinterPresupuestos->Items->Assign(printer->Printers);
		 cboPrinterPresupuestos->ItemIndex = printer->PrinterIndex;
		 cboPrinterPDF->Items->Assign(printer->Printers);
		 cboPrinterPDF->ItemIndex = printer->PrinterIndex;
      }
      else
      {
		 Application->MessageBox(L"No hay impresoras instaladas en el sistema." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);

		 cboPrinterEtiquetas->Text = "SIN IMPRESORAS";
		 cboPrinterPresupuestos->Text = "SIN IMPRESORAS";
		 cboPrinterPDF->Text = "SIN IMPRESORAS";
		 Configuraciones->WriteString("Impresion","ImpresoraEtiquetas","NO CONFIGURADA");
		 Configuraciones->WriteString("Impresion","ImpresoraPresupuestos","NO CONFIGURADA");
		 Configuraciones->WriteString("Impresion","ImpresoraPDF","NO CONFIGURADA");
	  }

	  Label4->Caption = Configuraciones->ReadString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");
	  Label6->Caption = Configuraciones->ReadString("Impresion","ImpresoraPresupuestos","NO_CONFIGURADA");
	  Label18->Caption = Configuraciones->ReadString("Impresion","ImpresoraPDF","NO_CONFIGURADA");

	  cboPrinterEtiquetas->Text = Label4->Caption;
	  cboPrinterPresupuestos->Text = Label6->Caption;
	  cboPrinterPDF->Text = Label18->Caption;

	  DirFacturas = Configuraciones->ReadString("Directorios","Facturas", "NO_CONFIGURADA");
	  Edit2->Text = Configuraciones->ReadString("Facturas","maximoSinDatos", "$ 0,00");

	  Label20->Caption = "Actual: " + DirFacturas;


	  Edit1->Text = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");

	  delete Configuraciones;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button2Click(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Configuraciones->WriteString("Impresion","ImpresoraEtiquetas",cboPrinterEtiquetas->Text);
   Configuraciones->WriteString("Impresion","ImpresoraPresupuestos",cboPrinterPresupuestos->Text);
   Configuraciones->WriteString("Impresion","ImpresoraPDF",cboPrinterPDF->Text);

   Label4->Caption = cboPrinterEtiquetas->Text;
   Label6->Caption = cboPrinterPresupuestos->Text;
   Label18->Caption = cboPrinterPDF->Text;

   Configuraciones->WriteString("Directorios","Facturas", DirFacturas);
   Configuraciones->WriteString("Facturas","maximoSinDatos", Edit2->Text);

   Configuraciones->WriteString("MySQLServer","Servidor",Edit1->Text);


   delete Configuraciones;

   Application->MessageBox(L"Si realizó algún cambio en el nombre del servidor de base de datos deberá cerrar el programa y volver a iniciarlo." ,L"ATENCIÓN!",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormDestroy(TObject *Sender)
{
   delete printer;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormCreate(TObject *Sender)
{
   printer = new TPrinter;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button8Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Facturas","",dir) == true)
   {
	  Label20->Caption = "Actual: " + dir;
	  DirFacturas = dir;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Edit2Enter(TObject *Sender)
{
   if(dynamic_cast<TEdit *>(Sender)->Text.Pos("$ ") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = dynamic_cast<TEdit *>(Sender)->Text.Delete(1,2);
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Edit2Exit(TObject *Sender)
{
   String s = dynamic_cast<TEdit *>(Sender)->Text;

   try
   {
	  if(s.Pos("$") > 0)
		 s = s.Delete(1,2);

	  StrToFloat(s);
   }
   catch(...)
   {
	  s = "0,00";
   }

   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("$ 0.00", StrToFloat(s));
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = '.';
}
//---------------------------------------------------------------------------
