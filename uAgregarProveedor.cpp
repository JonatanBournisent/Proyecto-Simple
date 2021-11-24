//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAgregarProveedor.h"
#include "uBuscarProveedor.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAgregarProveedor *fAgregarProveedor;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfAgregarProveedor::TfAgregarProveedor(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarProveedor::Button1Click(TObject *Sender)
{
   if(Edit1->Text == "")
   {
	  Application->MessageBox(L"Debe indicar una razón social",L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   if(!cuitOK)
   {
	  Application->MessageBox(L"El CUIT ingresado no es válido",L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(modificando)
   {
      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("UPDATE proveedores SET "
					   "nombre = :nombre, "
					   "domicilio = :domicilio, "
					   "telefono = :telefono, celular = :celular, cuit = :cuit, email = :email "
					   "WHERE idProveedor = :id LIMIT 1");

	  Query1->ParamByName("id")->AsInteger = idProveedorMod;
	  modificando = false;
   }
   else
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("INSERT INTO proveedores (nombre, "
					   "domicilio, telefono, celular, cuit, email) "
					   "VALUES ("
					   ":nombre, "
					   ":domicilio, :telefono, :celular, :cuit, :email)");

   }

   Query1->ParamByName("nombre")->AsString = Edit1->Text;
   Query1->ParamByName("domicilio")->AsString = Edit4->Text;
   Query1->ParamByName("telefono")->AsString = Edit5->Text;
   Query1->ParamByName("celular")->AsString = Edit6->Text;
   Query1->ParamByName("cuit")->AsString = Edit7->Text;
   Query1->ParamByName("email")->AsString = Edit9->Text;
   Query1->ExecSQL();

   Edit1->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit7->Text = "__-________-_";
   Edit9->Text = "";
   Edit1->SetFocus();
   paraModificar = false;

   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarProveedor::FormShow(TObject *Sender)
{
   Edit1->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit7->Text = "__-________-_";
   Edit9->Text = "";
   idProveedorMod = 0;
   cuitOK = false;
   Edit7->Color = clWindow;
   Edit1->SetFocus();
   Button1->Enabled = true;
   Button4->Enabled = true;

   if(paraModificar)
   {
	  Button3Click(fAgregarProveedor);
	  cuitOK = true;
	  Button4->Enabled = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Button3Click(TObject *Sender)
{
   fBuscarProveedor->ShowModal();
   if(fBuscarProveedor->idSeleccionado > 0)
   {
	  idProveedorMod = fBuscarProveedor->idSeleccionado;

      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT * FROM proveedores WHERE idProveedor = :id LIMIT 1");
	  Query1->ParamByName("id")->AsInteger = idProveedorMod;
	  Query1->Open();

	  Edit1->Text = Query1->FieldByName("nombre")->AsString;
	  Edit4->Text = Query1->FieldByName("domicilio")->AsString;
	  Edit5->Text = Query1->FieldByName("telefono")->AsString;
	  Edit6->Text = Query1->FieldByName("celular")->AsString;
	  Edit7->Text = Query1->FieldByName("cuit")->AsString;
	  Edit9->Text = Query1->FieldByName("email")->AsString;

	  Query1->Close();
	  modificando = true;
   }
   else
   {
	  //Application->MessageBox(L"Debe seleccionar un proveedor!",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  Timer1->Enabled = true;
      Button1->Enabled = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarProveedor::Button2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarProveedor::Edit7Exit(TObject *Sender)
{
   if(Edit7->Text != "__-________-_")
   {
	  if(Edit7->Text.Pos("_") == 0) //validacion de cuit
	  {
		 int v1 = StrToInt(Edit7->Text[1]) * 5;
		 v1 = v1 + StrToInt(Edit7->Text[2]) * 4;
		 v1 = v1 + StrToInt(Edit7->Text[4]) * 3;
		 v1 = v1 + StrToInt(Edit7->Text[5]) * 2;
		 v1 = v1 + StrToInt(Edit7->Text[6]) * 7;
		 v1 = v1 + StrToInt(Edit7->Text[7]) * 6;
		 v1 = v1 + StrToInt(Edit7->Text[8]) * 5;
		 v1 = v1 + StrToInt(Edit7->Text[9]) * 4;
		 v1 = v1 + StrToInt(Edit7->Text[10]) * 3;
		 v1 = v1 + StrToInt(Edit7->Text[11]) * 2;

		 int v2 = v1 % 11;

		 if(StrToInt(Edit7->Text[13]) == (11 - v2))
		 {
			Edit7->Color = clWindow;
			Edit7->ShowHint = false;
			cuitOK = true;
		 }
		 else if(StrToInt(Edit7->Text[13]) == 0 && (v2 == 0))
		 {
			Edit7->Color = clWindow;
			Edit7->ShowHint = false;
			cuitOK = true;
		 }
		 else
		 {
			Edit7->Hint = "El cuit ingresado no es válido";
			Edit7->ShowHint = true;
			Edit7->Color = clWebLightCoral;
			cuitOK = false;
		 }
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if(Key == VK_BACK)
   {
	  Key = NULL;
	  Edit7->Text = "___-________-_";
	  Edit7->SelStart = 0;
   }
   else if(Key == VK_DELETE)
   {
	  Key = NULL;
	  Edit7->Text = "__-________-_";
	  Edit7->SelStart = 0;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Edit7KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Edit7->SelStart == 2 || Edit7->SelStart == 11)
	  Edit7->SelStart++;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Edit7KeyPress(TObject *Sender, System::WideChar &Key)

{
   Edit7->SelLength = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::FormClose(TObject *Sender, TCloseAction &Action)

{
   if(Edit1->Text != "" || Edit4->Text != "" || Edit5->Text != "" || Edit6->Text != "" || Edit9->Text != "" || Edit7->Text != "__-________-_")
	  if(Application->MessageBox(L"Algunos datos no fueron guardados aún. Desea descartarlos y salir de todos modos?",L"Descartar datos y salir?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  {
		 Action = caNone;
		 return;
	  }

   Query1->Close();
   SQLConnection1->Close();
   paraModificar = false;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::FormCreate(TObject *Sender)
{
   paraModificar = false;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Timer1Timer(TObject *Sender)
{
   Timer1->Enabled = false;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarProveedor::Button4Click(TObject *Sender)
{
   if(Edit1->Text != "" || Edit4->Text != "" || Edit5->Text != "" || Edit6->Text != "" || Edit9->Text != "" || Edit7->Text != "__-________-_")
	  if(Application->MessageBox(L"Algunos datos no fueron guardados aún. Desea descartarlos?",L"Descartar datos?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  {
		 return;
	  }

   Edit1->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit7->Text = "__-________-_";
   Edit9->Text = "";
   Edit1->SetFocus();
   paraModificar = false;
}
//---------------------------------------------------------------------------

