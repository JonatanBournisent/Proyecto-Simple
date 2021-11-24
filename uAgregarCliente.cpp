//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAgregarCliente.h"
#include "uBuscarCliente.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAgregarCliente *fAgregarCliente;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfAgregarCliente::TfAgregarCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarCliente::FormShow(TObject *Sender)
{
   Edit1->Text = "";
   Edit2->Text = "";
   Edit3->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit10->Text = "";
   Edit11->Text = "";
   Edit12->Text = "";
   Edit13->Text = "";
   Edit14->Text = "";
   Edit7->Text = "__-________-_";
   Edit8->Text = "0,00 %";
   Edit9->Text = "";
   modificando = false;
   cuitOK = false;
   Edit7->Color = clWindow;
   desligarRZ = false;
   registraConDNI = false;

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT descripcion FROM condicionesfrenteiva ORDER BY idCondicionFrenteIVA");
   Query1->Open();

   Query1->First();
   ComboBox1->Clear();
   while(!Query1->Eof)
   {
	  ComboBox1->Items->Add(Query1->FieldByName("descripcion")->AsString);
	  Query1->Next();
   }
   Query1->Close();
   ComboBox1->ItemIndex = -1;
   Edit1->SetFocus();
   Button1->Enabled = true;

   if(paraModificar)
	  Button3Click(fAgregarCliente);
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarCliente::Button1Click(TObject *Sender)
{
   if(!cuitOK || ComboBox1->ItemIndex == -1)
	  return;

   if(Edit7->Text.Pos(" "))
   {
	  Application->MessageBox(L"El DNI no puede contener espacios", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(registraConDNI && Edit7->Text.Length() != 8)
   {
	  Application->MessageBox(L"El DNI debe tener 8 dígitos de longitud, complete con ceros a la izquierda en caso de ser necesario", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(!modificando && (!registraConDNI || Edit7->Text != "00000000"))
   {
      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT idCliente FROM clientes WHERE cuit = :cuit LIMIT 1");
	  Query1->ParamByName("cuit")->AsString = Edit7->Text;
	  Query1->Open();

	  if(!Query1->IsEmpty())
	  {
		 Query1->Close();
		 if(registraConDNI)
			Application->MessageBox(L"Ya existe un cliente con este DNI", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		 else
            Application->MessageBox(L"Ya existe un cliente con este CUIT", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		 return;
	  }
	  Query1->Close();
   }



   if(modificando)
   {
      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("UPDATE clientes SET "
					   "nombre = :nombre, apellido = :apellido, "
					   "razonSocial = :razonSocial, domicilio = :domicilio, "
					   "telefono = :telefono, telefono2 = :telefono2, telefono3 = :telefono3, "
					   "interno1 = :interno1, interno2 = :interno2, interno3 = :interno3, "
					   "celular = :celular, cuit = :cuit, "
					   "descuento = :descuento, email = :email, "
					   "refcondicionFrenteIva = :refcondicionFrenteIva "
					   "WHERE idCliente = :id LIMIT 1");

	  Query1->ParamByName("id")->AsInteger = idClienteMod;

	  modificando = false;
   }
   else
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("INSERT INTO clientes (nombre, apellido, razonSocial, "
					   "domicilio, telefono, telefono2, telefono3, interno1, interno2, interno3, celular, cuit, descuento, email, refcondicionFrenteIva) "
					   "VALUES ("
					   ":nombre, :apellido, :razonSocial, "
					   ":domicilio, :telefono, :telefono2, :telefono3, :interno1, :interno2, :interno3, :celular, :cuit, :descuento, :email, :refcondicionFrenteIva)");
   }

   Query1->ParamByName("nombre")->AsString = Edit1->Text;
   Query1->ParamByName("apellido")->AsString = Edit2->Text;
   Query1->ParamByName("razonSocial")->AsString = Edit3->Text;
   Query1->ParamByName("domicilio")->AsString = Edit4->Text;
   Query1->ParamByName("telefono")->AsString = Edit5->Text;
   Query1->ParamByName("telefono2")->AsString = Edit11->Text;
   Query1->ParamByName("telefono3")->AsString = Edit13->Text;
   Query1->ParamByName("interno1")->AsString = Edit10->Text;
   Query1->ParamByName("interno2")->AsString = Edit12->Text;
   Query1->ParamByName("interno3")->AsString = Edit14->Text;
   Query1->ParamByName("celular")->AsString = Edit6->Text;
   Query1->ParamByName("cuit")->AsString = Edit7->Text;
   Query1->ParamByName("descuento")->AsFloat = StrToFloat(Edit8->Text.SubString(1,Edit8->Text.Length()-2));
   Query1->ParamByName("email")->AsString = Edit9->Text;
   Query1->ParamByName("refcondicionFrenteIva")->AsInteger = ComboBox1->ItemIndex + 1;
   Query1->ExecSQL();


   Edit1->Text = "";
   Edit2->Text = "";
   Edit3->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit7->Text = "";
   Edit10->Text = "";
   Edit11->Text = "";
   Edit12->Text = "";
   Edit13->Text = "";
   Edit14->Text = "";
   Edit8->Text = "0,00 %";
   Edit9->Text = "";
   ComboBox1->ItemIndex = -1;
   desligarRZ = false;
   Label7->Caption = "Cuit";
   registraConDNI = false;
   Edit7->Text = "__-________-_";
   Edit1->SetFocus();

   paraModificar = false;
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarCliente::Button3Click(TObject *Sender)
{
   fBuscarCliente->ShowModal();
   if(fBuscarCliente->idSeleccionado > 0)
   {
	  idClienteMod = fBuscarCliente->idSeleccionado;

      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT * FROM clientes WHERE idCliente = :id LIMIT 1");
	  Query1->ParamByName("id")->AsInteger = idClienteMod;
	  Query1->Open();

	  Edit1->Text = Query1->FieldByName("nombre")->AsString;
	  Edit2->Text = Query1->FieldByName("apellido")->AsString;
	  Edit3->Text = Query1->FieldByName("razonSocial")->AsString;
	  Edit4->Text = Query1->FieldByName("domicilio")->AsString;
	  Edit5->Text = Query1->FieldByName("telefono")->AsString;
	  Edit11->Text = Query1->FieldByName("telefono2")->AsString;
	  Edit13->Text = Query1->FieldByName("telefono3")->AsString;
	  Edit10->Text = Query1->FieldByName("interno1")->AsString;
	  Edit12->Text = Query1->FieldByName("interno2")->AsString;
	  Edit14->Text = Query1->FieldByName("interno3")->AsString;
	  Edit6->Text = Query1->FieldByName("celular")->AsString;
	  Edit7->Text = Query1->FieldByName("cuit")->AsString;
	  Edit8->Text = Query1->FieldByName("descuento")->AsString;
	  Edit9->Text = Query1->FieldByName("email")->AsString;
	  ComboBox1->ItemIndex = Query1->FieldByName("refCondicionFrenteIVA")->AsInteger - 1;

	  Edit8Exit(Edit8);
	  Query1->Close();
	  modificando = true;
	  desligarRZ = true;

	  if(ComboBox1->ItemIndex == 2)
	  {
		 Label7->Caption = "DNI";
		 registraConDNI = true;
		 cuitOK = true;
	  }
	  else
	  {
		 Label7->Caption = "Cuit";
		 registraConDNI = false;
		 Edit7Exit(Edit7);
	  }
   }
   else
   {
	  //Application->MessageBox(L"Debe seleccionar un cliente!",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  Button1->Enabled = false;
	  Timer1->Enabled = true;
   }

}
//---------------------------------------------------------------------------
void __fastcall TfAgregarCliente::Button2Click(TObject *Sender)
{
	if(Edit1->Text != "" || Edit2->Text != "" || Edit3->Text != "" || Edit4->Text != "" || Edit5->Text != "" || Edit6->Text != "" || Edit7->Text != "__-________-_")
	  if(Application->MessageBox(L"Algunos datos no fueron guardados aún. Desea descartarlos?",L"Descartar datos?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  {
		 return;
	  }

   Edit1->Text = "";
   Edit2->Text = "";
   Edit3->Text = "";
   Edit4->Text = "";
   Edit5->Text = "";
   Edit6->Text = "";
   Edit7->Text = "__-________-_";
   Edit8->Text = "0,00 %";
   Edit9->Text = "";
   modificando = false;
   cuitOK = false;
   Edit7->Color = clWindow;
   desligarRZ = false;
   registraConDNI = false;
   ComboBox1->ItemIndex = -1;
   Edit1->SetFocus();
   Button1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit8Click(TObject *Sender)
{
   Edit8->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit8Enter(TObject *Sender)
{
   if(Edit8->Text.Pos(" %") == Edit8->Text.Length() - 1)
	  Edit8->Text = Edit8->Text.Delete(Edit8->Text.Length()-1,2);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit8Exit(TObject *Sender)
{
   try
   {
	  StrToFloat(Edit8->Text);
   }
   catch(...)
   {
	  Edit8->Text = "0,00";
   }

   Edit8->Text = FormatFloat("0.00 %", StrToFloat(Edit8->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit8KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(registraConDNI)
	  return;

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

void __fastcall TfAgregarCliente::Edit7KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(registraConDNI)
	  return;

   if(Edit7->SelStart == 2 || Edit7->SelStart == 11)
	  Edit7->SelStart++;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit7Exit(TObject *Sender)
{
   if(registraConDNI)
   {
	  Edit7->Color = clWindow;
	  Edit7->ShowHint = false;
	  cuitOK = true;
	  return;
   }

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

void __fastcall TfAgregarCliente::Edit7KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(registraConDNI)
	  return;

   Edit7->SelLength = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::FormClose(TObject *Sender, TCloseAction &Action)

{
   if(Edit1->Text != "" || Edit2->Text != "" || Edit3->Text != "" || Edit4->Text != "" || Edit5->Text != "" || Edit6->Text != "" || Edit7->Text != "__-________-_")
	  if(Application->MessageBox(L"Algunos datos no fueron guardados aún. Desea descartarlos y salir de todos modos?",L"Descartar datos y salir?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  {
		 Action = caNone;
		 return;
	  }


   desligarRZ = false;
   registraConDNI = false;
   Query1->Close();
   SQLConnection1->Close();
   paraModificar = false;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   desligarRZ = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit1Change(TObject *Sender)
{
   if(!desligarRZ)
   {
	  if(Edit2->Text == "")
		 Edit3->Text = Edit1->Text;
	  else
	     Edit3->Text = Edit1->Text + " " + Edit2->Text;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Edit2Change(TObject *Sender)
{
   if(!desligarRZ)
   {
	  if(Edit1->Text == "")
		 Edit3->Text = Edit2->Text;
	  else
	     Edit3->Text = Edit1->Text + " " + Edit2->Text;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::ComboBox1Change(TObject *Sender)
{
   if(ComboBox1->ItemIndex == 2)
   {
	  Label7->Caption = "DNI";
	  registraConDNI = true;
	  Edit7->Text = "";
   }
   else
   {
	  Label7->Caption = "Cuit";
	  registraConDNI = false;
	  Edit7->Text = "__-________-_";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::FormCreate(TObject *Sender)
{
   paraModificar = false;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------


void __fastcall TfAgregarCliente::Timer1Timer(TObject *Sender)
{
   Timer1->Enabled = false;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Button4Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

