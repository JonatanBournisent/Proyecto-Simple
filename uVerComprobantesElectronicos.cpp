//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.hpp>
#include <IniFiles.hpp>
#pragma hdrstop

#include "uVerComprobantesElectronicos.h"
#include "uBuscarCliente.h"
#include "FEAFIPLib_TLB.hpp"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxBarcode"
#pragma link "frxExportPDF"
#pragma link "frxExportBaseDialog"
#pragma resource "*.dfm"
TfVerComprobantesElectronicos *fVerComprobantesElectronicos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfVerComprobantesElectronicos::TfVerComprobantesElectronicos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::FormShow(TObject *Sender)
{
   omitir = true;
   Edit1->Clear();
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT idComprobanteElectronico, IF(cuitCliente = '00000000000', '-', cuitCliente) AS cuitCliente, fecha, netoGravado, iva21, iva105, final, "
	   "(SELECT razonSocial FROM clientes WHERE comprobantesElectronicos.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
	   "(SELECT descripcion FROM condicionesFrenteIVA WHERE comprobantesElectronicos.refCondicionFrenteIVA = condicionesFrenteIVA.idCondicionFrenteIVA LIMIT 1) AS cfIVA, "
	   "(SELECT ELT(refTipoComp, 'Factura A', 'Nota de Débito A', 'Nota de Crédito A', '','','Factura B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobanteselectronicos ORDER BY idComprobanteElectronico DESC LIMIT 50";

   Query1->SQL->Add(q);
//   Query1->ParamByName("refCliente")->AsInteger = idCliente;

   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }

   Panel1->Visible = false;
   DBGrid1->Enabled = true;


   CDS1->Active = true;
   MC1->Enabled = true;
   Button1->Enabled = true;

   MC1->MultiSelect = false;
   MC1->Date = Now();
   MC1->EndDate = Now();
   MC1->MultiSelect = true;

   MC2->MultiSelect = false;
   MC2->Date = Now();
   MC2->EndDate = Now();
   MC2->MultiSelect = true;

   Label2->Caption = "Neto gravado al 21%: Calcular";
   Label4->Caption = "IVA al 21%: Calcular";
   Label5->Caption = "Neto gravado al 10,5%: Calcular";
   Label6->Caption = "IVA al 10,5%: Calcular";

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);

   QueryCB->Close();
   QueryCB->SQL->Clear();
   QueryCB->SQL->Add("SELECT * FROM rubros ORDER BY idRubro");
   QueryCB->Open();

   QueryCB->First();
   cbRubro->Clear();
   while(!QueryCB->Eof)
   {
	  cbRubro->Items->Add(QueryCB->FieldByName("descripcion")->AsString);
	  QueryCB->Next();
   }
   QueryCB->Close();
   cbRubro->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::DBGrid1DrawColumnCell(TObject *Sender,
          const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State)

{
   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);
       else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::Edit1Change(TObject *Sender)
{
   if(omitir)
   {
	  omitir = false;
	  return;
   }
   if(Edit1->Text.Length() == 0)
   {
       CDS1->Active = false;
	   Query1->Close();
	   Query1->SQL->Clear();
	   String q;
	   q = "SELECT idComprobanteElectronico, IF(cuitCliente = '00000000000', '-', cuitCliente) AS cuitCliente, fecha, netoGravado, iva21, iva105, final, "
	   "(SELECT razonSocial FROM clientes WHERE comprobantesElectronicos.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
	   "(SELECT descripcion FROM condicionesFrenteIVA WHERE comprobantesElectronicos.refCondicionFrenteIVA = condicionesFrenteIVA.idCondicionFrenteIVA LIMIT 1) AS cfIVA, "
	   "(SELECT ELT(refTipoComp, 'Factura A', 'Nota de Débito A', 'Nota de Crédito A', '','','Factura B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobantesElectronicos ORDER BY idComprobanteElectronico DESC LIMIT 50";

	   Query1->SQL->Add(q);
	   Query1->Open();

	   if(Query1->IsEmpty())
	   {
		  Query1->Close();
		  return;
	   }

	   CDS1->Active = true;

	   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);

	   MC1->Enabled = true;
	   Button1->Enabled = true;

   }
   else
   {
	   CDS1->Active = false;
	   Query1->Close();
	   Query1->SQL->Clear();
	   String q;
	   q = "SELECT idComprobanteElectronico, nroComprobante, IF(cuitCliente = '00000000000', '-', cuitCliente) AS cuitCliente, fecha, netoGravado, iva21, iva105, final, "
	   "(SELECT razonSocial FROM clientes WHERE comprobantesElectronicos.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
	   "(SELECT descripcion FROM condicionesFrenteIVA WHERE comprobantesElectronicos.refCondicionFrenteIVA = condicionesFrenteIVA.idCondicionFrenteIVA LIMIT 1) AS cfIVA, "
	   "(SELECT ELT(refTipoComp, 'Factura A', 'Nota de Débito A', 'Nota de Crédito A', '','','Factura B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobantesElectronicos WHERE nroComprobante = :nroComprobante ORDER BY idComprobanteElectronico DESC LIMIT 50";

	   Query1->SQL->Add(q);
	   Query1->ParamByName("nroComprobante")->AsInteger = StrToInt(Edit1->Text);

	   Query1->Open();

	   if(Query1->IsEmpty())
	   {
		  Query1->Close();
		  return;
	   }

	   CDS1->Active = true;

	   MC1->Enabled = false;
	   Button1->Enabled = false;

	   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
   }
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::MC1Click(TObject *Sender)
{
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT idComprobanteElectronico, IF(cuitCliente = '00000000000', '-', cuitCliente) AS cuitCliente, fecha, netoGravado, iva21, iva105, final, "
	   "(SELECT razonSocial FROM clientes WHERE comprobantesElectronicos.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
	   "(SELECT descripcion FROM condicionesFrenteIVA WHERE comprobantesElectronicos.refCondicionFrenteIVA = condicionesFrenteIVA.idCondicionFrenteIVA LIMIT 1) AS cfIVA, "
	   "(SELECT ELT(refTipoComp, 'Factura A', 'Nota de Débito A', 'Nota de Crédito A', '','','Factura B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobantesElectronicos WHERE fecha >= :fi AND fecha <= :ff ORDER BY idComprobanteElectronico DESC LIMIT 50";

   Query1->SQL->Add(q);
   Query1->ParamByName("fi")->AsDate = MC1->Date;
   Query1->ParamByName("ff")->AsDate = MC1->EndDate;

   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }
   omitir = true;
   Edit1->Clear();

   CDS1->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::Button1Click(TObject *Sender)
{
   fBuscarCliente->ShowModal();
   if(fBuscarCliente->idSeleccionado <= 2)
	  return;

   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   String q;
	  q = "SELECT idComprobanteElectronico, refCliente, IF(cuitCliente = '00000000000', '-', cuitCliente) AS cuitCliente, fecha, netoGravado, iva21, iva105, final, "
	   "(SELECT razonSocial FROM clientes WHERE comprobantesElectronicos.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
	   "(SELECT descripcion FROM condicionesFrenteIVA WHERE comprobantesElectronicos.refCondicionFrenteIVA = condicionesFrenteIVA.idCondicionFrenteIVA LIMIT 1) AS cfIVA, "
	   "(SELECT ELT(refTipoComp, 'Factura A', 'Nota de Débito A', 'Nota de Crédito A', '','','Factura B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobantesElectronicos WHERE refCliente = :refCliente ORDER BY idComprobanteElectronico DESC LIMIT 50";

   Query1->SQL->Add(q);
   Query1->ParamByName("refCliente")->AsInteger = fBuscarCliente->idSeleccionado;

   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }

   omitir = true;
   Edit1->Clear();
   MC1->Date = Now();

   CDS1->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::Button2Click(TObject *Sender)
{
   FormShow(Button1);
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b')
      Key = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfVerComprobantesElectronicos::Eliminarestafactura1Click(TObject *Sender)

{
   if(Application->MessageBox(L"Realmente desea eliminar este registro de la base de datos?. El mismo ya no será tenido en cuenta en posibles informes.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM comprobanteselectronicos WHERE idComprobanteElectronico = :idComprobanteElectronico LIMIT 1");
   QueryUpdate->ParamByName("idComprobanteElectronico")->AsInteger = CDS1->FieldByName("idComprobanteElectronico")->AsInteger;
   QueryUpdate->ExecSQL();

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM pedidosfacturados WHERE refFactura = :idComprobanteElectronico LIMIT 1");
   QueryUpdate->ParamByName("idComprobanteElectronico")->AsInteger = CDS1->FieldByName("idComprobanteElectronico")->AsInteger;
   QueryUpdate->ExecSQL();

   CDS1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Button3Click(TObject *Sender)
{
   Query2->Close();
   Query2->SQL->Clear();
   String q;

   q = "SELECT * FROM("
		  "SELECT refArticulo, refPedido, cantidad, iva, (cantidad * (precioUnitario / (1 + (iva / 100.0)))) AS neto, "
		  "(SELECT descuentoAplicado FROM pedidos WHERE refPedido = idPedido LIMIT 1) AS descuento, "
		  "(SELECT refRubro FROM articulos WHERE refArticulo = idArticulo LIMIT 1) AS rubro "
		  "FROM articulospedidos WHERE refPedido IN (SELECT refPedido FROM pedidosFacturados WHERE fecha >= :fi AND fecha <= :ff) "
		") t "
		"WHERE rubro = :rubro";

   Query2->SQL->Add(q);
   Query2->ParamByName("fi")->AsDate = MC2->Date;
   Query2->ParamByName("ff")->AsDate = MC2->EndDate;
   Query2->ParamByName("rubro")->AsInteger = cbRubro->ItemIndex + 1;

   Query2->Open();
   float sumaNETO105 = 0.0;
   float sumaNETO21 = 0.0;
   float acumIVA105 = 0.0;
   float acumIVA21 = 0.0;
   Query2->First();
   while(!Query2->Eof)
   {
	  if(Query2->FieldByName("iva")->AsFloat == 10.50)
	  {
		 sumaNETO105 = sumaNETO105 + RoundTo(Query2->FieldByName("neto")->AsFloat,-2) * (1.0 - RoundTo(Query2->FieldByName("descuento")->AsFloat,-2) / 100.0);
		 acumIVA105 = acumIVA105 + RoundTo(Query2->FieldByName("neto")->AsFloat,-2) *  (1.0 - RoundTo(Query2->FieldByName("descuento")->AsFloat,-2) / 100.0) * 0.105;
	  }
	  else if(Query2->FieldByName("iva")->AsFloat == 21.00)
	  {
		 sumaNETO21 = sumaNETO21 + RoundTo(Query2->FieldByName("neto")->AsFloat,-2) *  (1.0 - RoundTo(Query2->FieldByName("descuento")->AsFloat,-2) / 100.0);
		 acumIVA21 = acumIVA21 + RoundTo(Query2->FieldByName("neto")->AsFloat,-2) *  (1.0 - RoundTo(Query2->FieldByName("descuento")->AsFloat,-2) / 100.0) * 0.21;

	  }
	  Query2->Next();
   }
   Query2->Close();

   Label2->Caption = "NG 21%: $ " + FormatFloat("#,##0.00", sumaNETO21);
   Label4->Caption = "IVA 21%: $ " + FormatFloat("#,##0.00", acumIVA21);
   Label5->Caption = "NG 10,5%: $ " + FormatFloat("#,##0.00", sumaNETO105);
   Label6->Caption = "IVA 10,5%: $ " + FormatFloat("#,##0.00", acumIVA105);
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::cbRubroChange(TObject *Sender)
{
   Label2->Caption = "NG 21%: Calcular";
   Label4->Caption = "IVA 21%: Calcular";
   Label5->Caption = "NG al 10,5%: Calcular";
   Label6->Caption = "IVA 10,5%: Calcular";
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::MC2Click(TObject *Sender)
{
   Label2->Caption = "NG 21%: Calcular";
   Label4->Caption = "IVA 21%: Calcular";
   Label5->Caption = "NG al 10,5%: Calcular";
   Label6->Caption = "IVA 10,5%: Calcular";
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->Active = false;
   Query1->Close();
   Query2->Close();
   QueryCB->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::AnularestecomprobanteEmitirNC1Click(TObject *Sender)

{
   Memo1->Text = "Nota de Crédito por anulación de " + CDS1->FieldByName("tipoComp")->AsString + " N° " + CDS1->FieldByName("nroComp")->AsString;
   Edit2->Text = FormatFloat("0.00", CDS1->FieldByName("netoGravado")->AsFloat);
   Edit3->Text = FormatFloat("0.00", CDS1->FieldByName("iva21")->AsFloat);
   Edit4->Text = FormatFloat("0.00", CDS1->FieldByName("iva105")->AsFloat);
   Edit5->Text = FormatFloat("0.00", CDS1->FieldByName("final")->AsFloat);
   Label13->Caption = "Comprobante asociado: " + CDS1->FieldByName("tipoComp")->AsString + " N° " + CDS1->FieldByName("nroComp")->AsString;

   DTP->Date = Now();
   DBGrid1->Enabled = false;
   CheckBox1->Checked = true;
   Panel1->Visible = true;
}
//---------------------------------------------------------------------------



void __fastcall TfVerComprobantesElectronicos::CDS1cuitClienteGetText(TField *Sender,
		  UnicodeString &Text, bool DisplayText)
{
   if(Sender->AsString == "00000000")
	  Text = "";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit2Change(TObject *Sender)
{
   if(Edit2->Text.Length() > 0)
	  Edit5->Text = FormatFloat("0.00", StrToFloat(Edit2->Text) + StrToFloat(Edit3->Text) + StrToFloat(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit3Change(TObject *Sender)
{
   if(Edit3->Text.Length() > 0)
	  Edit5->Text = FormatFloat("0.00", StrToFloat(Edit2->Text) + StrToFloat(Edit3->Text) + StrToFloat(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit4Change(TObject *Sender)
{
   if(Edit4->Text.Length() > 0)
	  Edit5->Text = FormatFloat("0.00", StrToFloat(Edit2->Text) + StrToFloat(Edit3->Text) + StrToFloat(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit2Exit(TObject *Sender)
{
   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("0.00", StrToFloat(dynamic_cast<TEdit *>(Sender)->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit3Exit(TObject *Sender)
{
   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("0.00", StrToFloat(dynamic_cast<TEdit *>(Sender)->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit4Exit(TObject *Sender)
{
   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("0.00", StrToFloat(dynamic_cast<TEdit *>(Sender)->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Edit4KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Button4Click(TObject *Sender)
{
   Panel1->Visible = false;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idCliente, domicilio, refCondicionFrenteIVA FROM clientes WHERE idCliente = (SELECT refCliente FROM comprobanteselectronicos WHERE idComprobanteElectronico = :idComp LIMIT 1)");
   QueryAux->ParamByName("idComp")->AsInteger = CDS1->FieldByName("idComprobanteElectronico")->AsInteger;
   QueryAux->Open();
   int refCondicionFrenteIVA = QueryAux->FieldByName("refCondicionFrenteIVA")->AsInteger;
   String cuit, razonSocial, domicilio, condFrenteIVA;
   cuit = CDS1->FieldByName("cuitCliente")->AsString;
   razonSocial = CDS1->FieldByName("cliente")->AsString;
   domicilio = QueryAux->FieldByName("domicilio")->AsString;
   refCondicionFrenteIVA = QueryAux->FieldByName("refCondicionFrenteIVA")->AsInteger;
   condFrenteIVA = CDS1->FieldByName("cfIVA")->AsString;
   int idCliente = QueryAux->FieldByName("idCliente")->AsInteger;
   TDate fechaAsoc;
   fechaAsoc = CDS1->FieldByName("fecha")->AsDateTime;
   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo9"))->Text = razonSocial;
   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo10"))->Text = cuit;
   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo11"))->Text = condFrenteIVA;
   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo12"))->Text = domicilio;
   QueryAux->Close();

   DBGrid1->Enabled = true;


   float final = StrToFloat(Edit5->Text);
   float totalSIVA = StrToFloat(Edit2->Text);
   float IVAventa21CDTO = StrToFloat(Edit3->Text);
   float IVAventa105CDTO = StrToFloat(Edit4->Text);;
   float baseImp21 = IVAventa21CDTO / 0.21;
   float baseImp105 = IVAventa105CDTO / 0.105;
   float descuentoAplicado = 0.0; //para adaptacion de codigo copiado desde uIngresarPedido

   String numCompAsoc = CDS1->FieldByName("nroComp")->AsString;

   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo42"))->Text = CDS1->FieldByName("tipoComp")->AsString + " N° " + numCompAsoc;



   int PtoVentaAsoc = StrToInt(numCompAsoc.SubString(1,numCompAsoc.Pos("-") - 1));
   numCompAsoc = numCompAsoc.Delete(1,numCompAsoc.Pos("-"));
   double nroAsoc = StrToInt64(numCompAsoc);


   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo1"))->Text = Memo1->Text;



   String imp_actual;
   String DirFacturas;

   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   if(CheckBox1->Checked)
      imp_actual = Configuraciones->ReadString("Impresion","ImpresoraPDF","NO_CONFIGURADA");
   else
	  imp_actual = Configuraciones->ReadString("Impresion","ImpresoraPresupuestos","NO_CONFIGURADA");

   DirFacturas = Configuraciones->ReadString("Directorios","Facturas","NO_CONFIGURADA");


   int imp_index;

   if(DirFacturas == "NO_CONFIGURADA")
   {
	   delete Configuraciones;
	   Application->MessageBox(L"Antes de continuar debe configurar un directorio para guardar las copias de respaldo" ,L"Configurar directorio.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	   return;
   }

   if(imp_actual == "NO_CONFIGURADA")
   {
	  delete Configuraciones;
	  Application->MessageBox(L"Debe configurar una impresora antes de imprimir." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   else
   {
	   bool error = false;
	   TPrinter *printer;
	   printer = new TPrinter;
	   for(imp_index = 0; imp_index < printer->Printers->Count; imp_index++)
	   {
		  if(printer->Printers->Strings[imp_index] == imp_actual)
			 break;
	   }
	   if(imp_index < printer->Printers->Count)
		  error = false;
	   else
	   {
		  error = true;
		  if(CheckBox1->Checked)
			 Configuraciones->WriteString("Impresion","ImpresoraPDF","NO CONFIGURADA");
		  else
		     Configuraciones->WriteString("Impresion","ImpresoraPresupuestos","NO CONFIGURADA");
	   }
	   if(error)
	   {
		  delete Configuraciones;
	      String str;
		  str = "Se produjo un error al intentar localizar la impresora seleccionada.";
		  str = str + '\n';
		  str = str + "La reconfiguraracion de la impresora podria solucionar el problema.";

		  Application->MessageBox(str.w_str() ,L"Error", MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
          return;
	   }
   }
   delete Configuraciones;

// desde aca ya se que estoy en condiciones de imprimir
//
   bool sinDatos, conDNI;

   sinDatos = false;

   if(cuit.Pos("-") > 0)
   {
	  if(cuit == "00-00000000-0")
		 sinDatos = true;
   }
   else if(cuit == "")
	  sinDatos = true;
   else if(StrToInt64(cuit) == 0)
	  sinDatos = true;

   if(domicilio.Length() < 3)
	  sinDatos = true;
   else if(razonSocial.Length() < 3)
	  sinDatos = true;


   while(cuit.Pos("-") > 0)
	  cuit = cuit.Delete(cuit.Pos("-"), 1);  //quito los guones del cuit si existen

   if(cuit.Length() == 11)
	  conDNI = false;
   else if(cuit.Length() == 8)
	  conDNI = true;
   else
   {
	  Application->MessageBox(L"Error en la longitud del CUIT / DNI. Revise los datos del cliente", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   String s;

   if(refCondicionFrenteIVA == 2)
   {
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Text = "Subtotal: " + FormatFloat("$ 0.00", totalSIVA);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Text = "Descuento: " + FormatFloat("0.00 %", descuentoAplicado);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo29"))->Text = "Neto Gravado: " + FormatFloat("$ 0.00", totalSIVA * (1 - (descuentoAplicado / 100.0)));
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Text = "IVA 10,5%: " + FormatFloat("$ 0.00", IVAventa105CDTO);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Text = "IVA 21%: " + FormatFloat("$ 0.00", IVAventa21CDTO);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Text = "TOTAL: " + FormatFloat("$ 0.00", final);

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo29"))->Visible = true;
	  if(IVAventa105CDTO > 0)
		 dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Visible = true;
	  else
		 dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Visible = false;
	  if(IVAventa21CDTO > 0)
		 dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Visible = true;
	  else
		 dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Visible = false;

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Visible = true;

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo30"))->Text = "A";
      dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo37"))->Text = "COD. 03";

	  s = "NOTA DE CREDITO A";
   }
   else
   {
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Text = "Subtotal: " + FormatFloat("$ 0.00", totalSIVA + IVAventa105CDTO + IVAventa21CDTO);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Text = "Descuento: " + FormatFloat("0.00 %", descuentoAplicado);
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Text = "TOTAL: " + FormatFloat("$ 0.00", final);

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo29"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo30"))->Text = "B";
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo37"))->Text = "COD. 08";

	  s = "NOTA DE CREDITO B";
   }

   if(descuentoAplicado == 0)
	   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Visible = false;
   else
	   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Visible = true;

   float altMemo = dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Height;
   float m27 = dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo27"))->Top;


   if(refCondicionFrenteIVA == 2 && descuentoAplicado > 0)
   {
	  dynamic_cast <TfrxShapeView *> (fVerComprobantesElectronicos->frxReport1->FindObject("frxShapeView1"))->Height = altMemo * 9.8;

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo29"))->Top = m27 + altMemo * 3;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Top = m27 + altMemo * 4.5;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Top = m27 + altMemo * 6;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Top = m27 + altMemo * 7.5;
   }
   else if(refCondicionFrenteIVA == 2 && descuentoAplicado == 0)
   {

	  dynamic_cast <TfrxShapeView *> (fVerComprobantesElectronicos->frxReport1->FindObject("frxShapeView1"))->Height = altMemo * 8.3;

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo29"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo34"))->Top = m27 + altMemo * 3;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo39"))->Top = m27 + altMemo * 4.5;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Top = m27 + altMemo * 6;
   }
   else if(descuentoAplicado > 0)
   {
	  dynamic_cast <TfrxShapeView *> (fVerComprobantesElectronicos->frxReport1->FindObject("frxShapeView1"))->Height = altMemo * 5.3;

	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo28"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Top = m27 + altMemo * 3;
   }
   else
   {
	  dynamic_cast <TfrxShapeView *> (fVerComprobantesElectronicos->frxReport1->FindObject("frxShapeView1"))->Height = altMemo * 3.8;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo40"))->Top = m27 + altMemo * 1.5;
   }

   if(conDNI)
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo19"))->Text = "DNI:";
   else
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo19"))->Text = "CUIT:";

   dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo36"))->Text = FormatDateTime("dd/mm/yyyy", DTP->Date);

   if(sinDatos)
   {
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo9"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo10"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo12"))->Visible = true;
   }


//**************** CODIGOS SEGUN TABLA DE CODIGOS DE AFIP ************
//	001		FACTURA A                                                *
//	002		NOTA DE DEBITO A                                         *
//	003		NOTA DE CREDITO A                                        *
//                                                                   *
//	006		FACTURA B                                                *
//	007		NOTA DE DEBITO B                                         *
//	008		NOTA DE CREDIT B                                         *
//                                                                   *
//	011		FACTURA C                                                *
//	012		NOTA DE DEBITO C                                         *
//	013		NOTA DE CREDITO C                                        *
//                                                                   *
//**************** FIN CODIGOS SEGUN TABLA DE CODIGOS DE AFIP ********



//   URLs de autenticacion y negocio. Cambiarlas por las de producción al implementarlas en el cliente(abajo)
//   String URLWSAA = "https://wsaahomo.afip.gov.ar/ws/services/LoginCms"; //homologacion
//   String URLWSW = "https://wswhomo.afip.gov.ar/wsfev1/service.asmx";     //homologacion


   String URLWSAA = "https://wsaa.afip.gov.ar/ws/services/LoginCms";       //Produccion
   String URLWSW =  "https://servicios1.afip.gov.ar/wsfev1/service.asmx";   //Produccion

   WideString CAE = "";
   WideString Resultado = "";
   WideString Reproceso = "";
   WideString Vencimiento = "";
   WideString CUIT = "23323762589";
   double totalComp = StrToFloat(FormatFloat("0.00", final));
   double netoGravado = StrToFloat(FormatFloat("0.00", totalSIVA * (1 - (descuentoAplicado / 100.0))));
   double BASEIMP21 = StrToFloat(FormatFloat("0.00", baseImp21));
   double BASEIMP105 = StrToFloat(FormatFloat("0.00",baseImp105));
   double IVA21 = StrToFloat(FormatFloat("0.00",IVAventa21CDTO));
   double IVA105 = StrToFloat(FormatFloat("0.00",IVAventa105CDTO));

   bool error = false;

   double nro = 0;
   int PtoVta = 4;   //Punto de venta dado de alta en AFIP para Web Service

   int TipoComp;     //Codigo de Tipo de comprobante segun tabla de AFIP (resumen arriba)


   if(refCondicionFrenteIVA == 2)
	  TipoComp = 3;
   else
	  TipoComp = 8;

   String FechaComp = FormatDateTime("yyyyMMdd", DTP->Date);

   try
   {
	  StrToInt64(cuit);
   }
   catch(...)
   {
	  Application->MessageBox(L"Error al intentar converir el numero de CUIT del cliente a un valor entero", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }


   String tipoComp;

   if(TipoComp == 3)
	  tipoComp = "A";
   else if(TipoComp == 8)
	  tipoComp = "B";
   else
      return;

   String mensaje = "Se va a emitir una Nota de Crédito " + tipoComp + " a nombre de: \n\n";
   mensaje  = mensaje + "Razón Social: " + razonSocial;
   if(conDNI)
	  mensaje  = mensaje + "\nDNI: " + cuit;
   else
	  mensaje  = mensaje + "\nCUIT: " + cuit;
   mensaje  = mensaje + "\nCondición frente al IVA: " + condFrenteIVA;
   mensaje = mensaje + "\nNeto Gravado: " + FormatFloat("$ 0.00", netoGravado);
   mensaje = mensaje + "\nIVA 21%: " + FormatFloat("$ 0.00", IVA21);
   mensaje = mensaje + "\nIVA 10,5%: " + FormatFloat("$ 0.00", IVA105);
   mensaje = mensaje + "\nImporte TOTAL: " + FormatFloat("$ 0.00", totalComp);
   mensaje  = mensaje  + "\n\nRealmente desea continuar?";


   if(Application->MessageBox(L"Esta operación no puede cancelarse. Desea continuar?" ,L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  return;
   }

   if(Application->MessageBox(mensaje.w_str() ,L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  return;
   }


   bool comprobanteAutorizado = false;

   Twsfev1 *lwsfev1;
   lwsfev1 = new Twsfev1(Owner);
   lwsfev1->CUIT = StrToInt64(CUIT);
   lwsfev1->URL = URLWSW;

	if (lwsfev1->login("certificadosimple.crt", "clavesimple.key", URLWSAA))
	{
		if (lwsfev1->SFRecuperaLastCMP(PtoVta, TipoComp) == false)
		{
		   String msg = lwsfev1->ErrorDesc;
		   Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		   Application->MessageBox(L"Error al intentar recuperar desde AFIP el número del último comprobante emitido", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		   error = true;
		}
		else
		{
			nro = lwsfev1->SFLastCMP + 1;
			lwsfev1->Reset();

			if(sinDatos)
			   lwsfev1->AgregaFactura(1, 99, __int64(0), nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);
			else if(conDNI)
			   lwsfev1->AgregaFactura(1, 96, StrToInt64(cuit), nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);
			else
			   lwsfev1->AgregaFactura(1, 80, StrToInt64(cuit), nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);

			lwsfev1->AgregaCompAsoc(TipoComp, PtoVentaAsoc, nroAsoc, StrToInt64(CUIT), FormatDateTime("yyyyMMdd", fechaAsoc));
			WideString codOp = "22";
			WideString valOp = "S";	 //S es anulacion, N es ajuste
			lwsfev1->AgregaOpcional(codOp, valOp);	//define que es por anulacion
//
			if(IVA21 > 0)
			   lwsfev1->AgregaIVA(5, BASEIMP21, IVA21); //ir a http://www.bitingenieria.com.ar/codigos.html
			if(IVA105 > 0)
			   lwsfev1->AgregaIVA(4, BASEIMP105, IVA105);

			if (lwsfev1->Autorizar(PtoVta, TipoComp))
			{
				lwsfev1->AutorizarRespuesta(0, CAE, Vencimiento, Resultado, Reproceso);
				if (Resultado == "A")
				{
					//ShowMessage("Felicitaciones! Si ve este mensaje instalo correctamente FEAFIP. CAE y Vencimiento :" + CAE + " " + Vencimiento);
					comprobanteAutorizado = true;
				}
				else
				{
					String msg = lwsfev1->AutorizarRespuestaObs(0);
					Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
					Application->MessageBox(L"Hubo un error al intentar autorizar el comprobante", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
					error = true;
				}
			}
			else
			{
				String msg = lwsfev1->ErrorDesc;
				Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
			    error = true;
			}
		}
	}
	else
	{
		String msg = lwsfev1->ErrorDesc;
		Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		Application->MessageBox(L"Arror al intentar conectarse al Web Service de AFIP con las credenciales disponibles", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		error = true;
	}


   if(error)
   {
      delete lwsfev1;
	  return;
   }


//*********************SOLO PARA PRUEBAS, COMENTAR EN CASO CONTRARIO************
//   CAE = "70409912356908";
//   comprobanteAutorizado = true;      //para poder probar sin enviar a AFIP
//   Vencimiento = "20201008";
//   nro = 77;
//******************************************************************************

   String ptoDeVenta = IntToStr(PtoVta);
   while(ptoDeVenta.Length() < 5)
	  ptoDeVenta.Insert("0",1);

   String nroComp = IntToStr(__int64(nro));
   while(nroComp.Length() < 8)
	  nroComp.Insert("0",1);

   String tipoComprobante = IntToStr(TipoComp);

   while(tipoComprobante.Length() < 3)
	  tipoComprobante.Insert("0",1);


   String codigoBarra = CUIT + tipoComprobante + ptoDeVenta + CAE + Vencimiento; //cuit vendedor
   String fechaVencimiento = Vencimiento.SubString(7,2) + "/" + Vencimiento.SubString(5,2) + "/" + Vencimiento.SubString(1,4);

   frxPDFExport1->FileName = DirFacturas + "\\" + s + ptoDeVenta + "-" + nroComp + ".pdf";

   if(comprobanteAutorizado)
   {
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo38"))->Text = "ORIGINAL";
	  dynamic_cast <TfrxBarCodeView *> (fVerComprobantesElectronicos->frxReport1->FindObject("BarCode1"))->Text = codigoBarra;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("caeComp"))->Text = "N° de CAE: " + CAE;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("nroComp"))->Text = ptoDeVenta + " - " + nroComp;
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("vencComp"))->Text = "Fecha de Vto. de CAE: " + fechaVencimiento;
	  frxReport1->PrintOptions->Printer = imp_actual;
	  frxReport1->PrepareReport(true);
	  frxReport1->ShowReport(true);
//	  frxReport1->Print();
	  dynamic_cast <TfrxMemoView *> (fVerComprobantesElectronicos->frxReport1->FindObject("Memo38"))->Text = "DUPLICADO";
	  frxReport1->PrepareReport(true);

	  if(!frxReport1->Export(frxPDFExport1))
	  {
			Application->MessageBox(L"Especifique manualmente una ubicación (y nombre de archivo) donde guardar una copia del comprobante.", L"ATENCIÓN",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport1->FileName = SD1->FileName;
			frxReport1->Export(frxPDFExport1);
	  }


	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  String qy;

	  qy = "INSERT INTO comprobanteselectronicos ( "
		   "refCliente, cuitCliente, refCondicionFrenteIVA, fecha, refTipoComp, "
		   "ptoVenta, nroComprobante, netoGravado, iva105, iva21, final, CAE, vencimientoCAE) "
		   "VALUES ("
		   ":refCliente, :cuitCliente, :refCondicionFrenteIVA, :fecha, :refTipoComp, "
		   ":ptoVenta, :nroComprobante, :netoGravado, :iva105, :iva21, :final, :CAE, :vencimientoCAE) ";


	  QueryAux->SQL->Add(qy);
	  QueryAux->ParamByName("refCliente")->AsInteger = idCliente;
	  QueryAux->ParamByName("cuitCliente")->AsString = cuit;
	  QueryAux->ParamByName("refCondicionFrenteIVA")->AsInteger = refCondicionFrenteIVA;
	  QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
	  QueryAux->ParamByName("refTipoComp")->AsInteger = TipoComp; //Segun tablas de AFIP
	  QueryAux->ParamByName("ptoVenta")->AsInteger = PtoVta;
	  QueryAux->ParamByName("nroComprobante")->AsInteger = StrToInt(nroComp);
	  QueryAux->ParamByName("netoGravado")->AsFloat = netoGravado;
	  QueryAux->ParamByName("iva21")->AsFloat = IVA21;
	  QueryAux->ParamByName("iva105")->AsFloat = IVA105;
	  QueryAux->ParamByName("final")->AsFloat = totalComp;
	  QueryAux->ParamByName("CAE")->AsString = CAE;
	  QueryAux->ParamByName("vencimientoCAE")->AsDate = StrToDate(fechaVencimiento);
	  QueryAux->ExecSQL();

   }
   else
   {
	  Application->MessageBox(L"El comprobante no fue autorizado", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }

   delete lwsfev1;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::Button5Click(TObject *Sender)
{
   Panel1->Visible = false;
   DBGrid1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfVerComprobantesElectronicos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

