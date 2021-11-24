//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uSeleccionarArticulo.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfSeleccionarArticulo *fSeleccionarArticulo;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfSeleccionarArticulo::TfSeleccionarArticulo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::Edit2Change(TObject *Sender)
{
   if(Edit2->Text == "")
	  return;

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT *, (ROUND(precioVenta * (1 + (iva / 100.0)))) AS precioVentaCIVA FROM articulos WHERE codigo LIKE :codigo OR REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') LIKE _utf8 :nc COLLATE utf8_general_ci ORDER BY nombreCompleto");
   Query1->ParamByName("nc")->AsString = "%" + Edit2->Text.UpperCase() + "%";
   Query1->ParamByName("codigo")->AsString = "%" + Edit2->Text + "%";
   Query1->Open();
   CDS->Active = true;

//   if(CDS->IsEmpty())
//   {
//      DBEdit1->Enabled = false;
////	  DBEdit5->Enabled = false;
//   }
//   else
//   {
//	  DBEdit1->Enabled = true;
////	  DBEdit5->Enabled = true;
//   }

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::CDSprecioCompraChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET precioCompra = :precioCompra WHERE idArticulo = :idArticulo LIMIT 1");
   QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ParamByName("precioCompra")->AsFloat = DBEdit1->Field->AsFloat;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::CDSmargenUtilidadChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET margenUtilidad = :margenUtilidad WHERE idArticulo = :idArticulo LIMIT 1");
   QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ParamByName("margenUtilidad")->AsFloat = DBEdit2->Field->AsFloat;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::CDSivaChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE articulos SET iva = :iva WHERE idArticulo = :idArticulo LIMIT 1");
   QueryUpdate->ParamByName("idArticulo")->AsInteger = CDS->FieldByName("idArticulo")->AsInteger;
   QueryUpdate->ParamByName("iva")->AsFloat = DBEdit5->Field->AsFloat;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::DBEdit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarArticulo::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS->Active = false;
   Query1->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
   Edit2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::DBGrid1TitleClick(TColumn *Column)
{
   if(Edit2->Text == "")
	  return;

   String a = Column->Field->Name;
   a = a.Delete(1,3);

   if(a == "idArticulo")
	  a = "idArticulo, categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "categoria")
	  a = "categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "tipo")
	  a = "tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "marca")
	  a = "marca, modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "modelo")
	  a = "modelo, tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "tamano")
	  a = "tamano, color, diseno, cantidad, unidadMedida, stock";
   else if(a == "color")
	  a = "color, diseno, cantidad, unidadMedida, stock";
   else if(a == "diseno")
	  a = "diseno, cantidad, unidadMedida, stock";
   else if(a == "cantidad")
	  a = "cantidad, unidadMedida, stock";
   else if(a == "unidadMedida")
	  a = "unidadMedida, stock";

   String q = "SELECT *, (ROUND(precioVenta * (1 + (iva / 100.0)))) AS precioVentaCIVA FROM articulos WHERE nombreCompleto LIKE _utf8 :nc COLLATE utf8_general_ci ORDER BY " + a;

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   Query1->ParamByName("nc")->AsString = "%" + Edit2->Text.UpperCase() + "%";
   Query1->Open();
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------


void __fastcall TfSeleccionarArticulo::DBEdit1Exit(TObject *Sender)
{
//   if(CDS->Active)
//      CDS->Edit();
//
//   String s = DBEdit1->Text;
//
//   if(s == "")
//	  return;
//
//   float mg, pc;
//   if(s.Pos("$") > 0)
//	  pc = StrToFloat(s.SubString(3,s.Length()-3));
//   else
//	  pc = StrToFloat(s);
//
//   if(pc < 15)        //2
//	  mg = 2;
//   else if(pc < 35)   //1.6
//	  mg = 2.3 - 0.02 * pc;
//   else if(pc < 65)   //1.5
//	  mg = 1.7166666666667 - 0.0033333333333 * pc;
//   else if(pc < 100)  //1.4
//	  mg = 1.685714659 - 0.00285714286 * pc;
//   else
//	  mg = 1.4;
//
//   CDS->FieldByName("margenUtilidad")->AsFloat = (mg - 1) * 100;
//   DBEdit4->Field->AsFloat = DBEdit1->Field->AsFloat * (1 + (DBEdit2->Field->AsFloat / 100.0)) * (1 + (DBEdit5->Field->AsFloat / 100.0));
//   DBEdit3->Field->AsFloat = DBEdit1->Field->AsFloat * (1 + (DBEdit2->Field->AsFloat / 100.0));
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::DBEdit1Enter(TObject *Sender)
{
//   if(CDS->Active)
//	  CDS->Edit();
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::FormShow(TObject *Sender)
{
   Edit2->SetFocus();
//   DBEdit1->Enabled = false;
//   DBEdit5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfSeleccionarArticulo::DBEdit5KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::DBEdit5Exit(TObject *Sender)
{
//   if(CDS->Active)
//	  CDS->Edit();
//
//   DBEdit4->Field->AsFloat = DBEdit1->Field->AsFloat * (1 + (DBEdit2->Field->AsFloat / 100.0)) * (1 + (DBEdit5->Field->AsFloat / 100.0));
//   DBEdit3->Field->AsFloat = DBEdit1->Field->AsFloat * (1 + (DBEdit2->Field->AsFloat / 100.0));
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarArticulo::CheckBox1Click(TObject *Sender)
{
//   if(CheckBox1->Checked)
//	  DBEdit5->Enabled = true;
//   else
//      DBEdit5->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TfSeleccionarArticulo::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

