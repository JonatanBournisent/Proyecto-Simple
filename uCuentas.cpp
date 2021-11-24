//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uCuentas.h"
#include "uBuscarCliente.h"
#include "VariablesGlobales.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TfCuentas *fCuentas;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfCuentas::TfCuentas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfCuentas::mostrar(void)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT "
					"((SELECT IFNULL(SUM(importe), 0) AS impPedidos FROM cuentascorrientes WHERE refCliente = :refCliente) - (SELECT IFNULL(SUM(importe), 0) AS impPagos FROM pagosRecibidos WHERE refCliente = :refCliente)) AS saldo, "
					"((SELECT IFNULL(SUM(importe), 0) AS impPedidos FROM cuentascorrientes WHERE refCliente = :refCliente AND fecha <= :ff) - (SELECT IFNULL(SUM(importe), 0) AS impPagos FROM pagosRecibidos WHERE refCliente = :refCliente AND fecha <= :ff))AS saldoParcial, "
					"((SELECT IFNULL(SUM(importe), 0) AS impPedidos FROM cuentascorrientes WHERE refCliente = :refCliente AND fecha <= :ffa) - (SELECT IFNULL(SUM(importe), 0) AS impPagos FROM pagosRecibidos WHERE refCliente = :refCliente AND fecha <= :ffa))AS saldoAnterior, "
					"(SELECT IFNULL(SUM(importe), 0) AS pedidosPeriodo FROM cuentascorrientes WHERE refCliente = :refCliente AND fecha >= :fi AND fecha <= :ff) AS pedidosPeriodo, "
					"(SELECT IFNULL(SUM(importe), 0) AS pagosPeriodo FROM pagosRecibidos WHERE refCliente = :refCliente AND fecha >= :fi AND fecha <= :ff) AS pagosPeriodo");
   QueryAux->ParamByName("refCliente")->AsInteger = refCliente;
   QueryAux->ParamByName("fi")->AsDate = DateOf(MC->Date);
   QueryAux->ParamByName("ff")->AsDate = DateOf(MC->EndDate);
   QueryAux->ParamByName("ffa")->AsDate = DateOf(EndOfTheMonth(IncMonth(MC->EndDate, -1)));
   QueryAux->Open();

   Label3->Caption = "Saldo total: $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldo")->AsFloat);
   Label4->Caption = "Saldo a la fecha " + FormatDateTime("dd/mm/yy", DateOf(MC->EndDate)) + ": $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldoParcial")->AsFloat);
   Label5->Caption = "Monto de pedidos en el período observado: $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("pedidosPeriodo")->AsFloat);
   Label6->Caption = "Pagos realizados en el período observado: $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("pagosPeriodo")->AsFloat);

   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo28"))->Text = "$ " + FormatFloat("#,##0.00", QueryAux->FieldByName("pedidosPeriodo")->AsFloat);
   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo30"))->Text = "$ " + FormatFloat("#,##0.00", QueryAux->FieldByName("pagosPeriodo")->AsFloat);


   String sdoa;
   if(QueryAux->FieldByName("saldoAnterior")->AsFloat > 0.0)
	  sdoa = "Saldo anterior:  $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldoAnterior")->AsFloat);
   else if(QueryAux->FieldByName("saldoAnterior")->AsFloat < 0.0)
	  sdoa = "Saldo anterior a favor:  <font color=red>$ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldoAnterior")->AsFloat * -1.0) + "</font>";
   else
	  sdoa = "Saldo anterior: NO POSEE";
   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo8"))->Text = sdoa;


   String sdo;
   if(QueryAux->FieldByName("saldoParcial")->AsFloat > 0.0)
	  sdo = "Saldo a abonar hasta el " + FormatDateTime("dd/mm/yyyy", IncDay(EndOfTheMonth(MC->Date), 10)) + ":  $ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldoParcial")->AsFloat);
   else if(QueryAux->FieldByName("saldoParcial")->AsFloat < 0.0)
	  sdo = "Saldo a favor a la fecha " + FormatDateTime("dd/mm/yyyy", MC->EndDate) + ":  <font color=red>$ " + FormatFloat("#,##0.00", QueryAux->FieldByName("saldoParcial")->AsFloat * -1.0) + "</font>";
   else
	  sdo = "No hay saldos pendientes a la fecha: " + FormatDateTime("dd/mm/yyyy", MC->EndDate);

   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo31"))->Text = sdo;
   QueryAux->Close();

   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo5"))->Text = "Período: " + FormatDateTime("dd/mm/yyyy", MC->Date) + "  -  " + FormatDateTime("dd/mm/yyyy",MC->EndDate);//+ FormatDateTime("MMMM", MC->Date());


   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo32"))->Visible = false;
   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo33"))->Visible = false;

   CDS->Active = false;

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT * FROM cuentascorrientes WHERE refCliente = :refCliente AND fecha >= :fi AND fecha <= :ff ORDER BY fecha");
   Query1->ParamByName("refCliente")->AsInteger = refCliente;
   Query1->ParamByName("fi")->AsDate = MC->Date;
   Query1->ParamByName("ff")->AsDate = MC->EndDate;
   Query1->Open();
   CDS->Active = true;

   if(CDS->IsEmpty())
   {
	  CDS->Active = false;
	  Query1->Close();
	  dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo32"))->Visible = true;
   }

   CDS3->Active = false;
   Query3->Close();
   Query3->SQL->Clear();
   Query3->SQL->Add("SELECT *, (SELECT ELT(codMedio, 'Trasferencia Bancaria', 'Efectivo', 'Cheque', 'MercadoPago')) AS medioPago FROM pagosrecibidos WHERE refCliente = :refCliente AND fecha >= :fi AND fecha <= :ff ORDER BY fecha");
   Query3->ParamByName("refCliente")->AsInteger = refCliente;
   Query3->ParamByName("fi")->AsDate = MC->Date;
   Query3->ParamByName("ff")->AsDate = MC->EndDate;
   Query3->Open();
   CDS3->Active = true;

   if(CDS3->IsEmpty())
   {
	  CDS3->Active = false;
	  Query3->Close();
	  dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo33"))->Visible = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfCuentas::Button1Click(TObject *Sender)
{
   fBuscarCliente->ShowModal();
   if(fBuscarCliente->idSeleccionado < 1)
	  return;
   refCliente = fBuscarCliente->idSeleccionado;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT razonSocial FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   QueryAux->ParamByName("idCliente")->AsInteger = refCliente;
   QueryAux->Open();

   Label7->Caption = "Cliente analizado: " + QueryAux->FieldByName("razonSocial")->AsString;
   dynamic_cast <TfrxMemoView *> (fCuentas->frxReport1->FindObject("Memo2"))->Text = "Cliente: " + QueryAux->FieldByName("razonSocial")->AsString;
   QueryAux->Close();

   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Ingresaruntem1Click(TObject *Sender)
{
   if(refCliente <= 0)
	  return;

   MC2->Date = Now();
   Edit1->Text = "0,00";
   ComboBox1->ItemIndex = -1;
   Edit2->Text = "";
   Panel1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSvalorPedidoChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE cuentas SET valorPedido = :valorPedido WHERE idCuenta = :idCuenta");
   QueryUpdate->ParamByName("valorPedido")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("idCuenta")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSpagoRecibidoChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE cuentas SET pagoRecibido = :pagoRecibido WHERE idCuenta = :idCuenta");
   QueryUpdate->ParamByName("pagoRecibido")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("idCuenta")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormShow(TObject *Sender)
{
   refCliente = 0;
   Panel1->Visible = false;

   MC->MultiSelect = false;
   MC->Date = StartOfTheMonth(Now());
   MC->MultiSelect = true;
   MC->EndDate = EndOfTheMonth(Now());

   Label3->Caption = "";
   Label4->Caption = "";
   Label5->Caption = "";
   Label6->Caption = "";
   Label7->Caption = "SELECCIONAR CLIENTE";

   Button1Click(Button1);
   if(refCliente <= 0)
	  Application->MessageBox(L"Debe seleccionar un cliente para ver el estado de su Cuenta Corriente.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Eliminarestetem1Click(TObject *Sender)
{
   if(Application->MessageBox(L"Realmente desea eliminar este ítem. Esto podría modificar el estado de cuenta del cliente.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM pagosrecibidos WHERE idPagoRecibido = :idPagoRecibido LIMIT 1");
   QueryUpdate->ParamByName("idPagoRecibido")->AsInteger = CDS3->FieldByName("idPagoRecibido")->AsInteger;
   QueryUpdate->ExecSQL();

   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDScomentarioChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE cuentas SET comentario = :comentario WHERE idCuenta = :idCuenta");
   QueryUpdate->ParamByName("comentario")->AsString = Sender->AsString;
   QueryUpdate->ParamByName("idCuenta")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormClose(TObject *Sender, TCloseAction &Action)
{
   CDS->Active = false;
   CDS3->Active = false;
   Query1->Close();
   Query3->Close();
   QueryAux->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button2Click(TObject *Sender)
{
   MC->Date = StartOfTheMonth(IncDay(MC->Date, - 1));
   MC->EndDate = EndOfTheMonth(MC->Date);

   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button3Click(TObject *Sender)
{
   MC->EndDate = EndOfTheMonth(IncDay(MC->EndDate, 1));
   MC->Date = StartOfTheMonth(MC->EndDate);

   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button4Click(TObject *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("INSERT INTO pagosrecibidos (fecha, refCliente, codMedio, importe, comentario) VALUES (:fecha, :refCliente, :codMedio, :importe, :comentario)");
   QueryUpdate->ParamByName("fecha")->AsDate = MC2->Date;
   QueryUpdate->ParamByName("refCliente")->AsInteger = refCliente;
   QueryUpdate->ParamByName("codMedio")->AsInteger = ComboBox1->ItemIndex + 1;
   QueryUpdate->ParamByName("importe")->AsFloat = StrToFloat(Edit1->Text);
   QueryUpdate->ParamByName("comentario")->AsString = Edit2->Text;
   QueryUpdate->ExecSQL();

   mostrar();
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button5Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormCreate(TObject *Sender)
{
   Panel1->Left = (fCuentas->Width - Panel1->Width ) / 2;
   Panel1->Top = (fCuentas->Height - Panel1->Height ) / 2;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button6Click(TObject *Sender)
{
   mostrar();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button7Click(TObject *Sender)
{
//   CDSResumen->Active = false;
//
//   QueryResumen->Close();
//   QueryResumen->SQL->Clear();
//   QueryResumen->SQL->Add("SELECT refPedido AS nroPedido, fecha, valorPedido, pagoRecibido AS pagoRealizado FROM cuentas WHERE refCliente = :refCliente AND fecha >= :fi AND fecha <= :ff ORDER BY fecha ASC");
//   QueryResumen->ParamByName("refCliente")->AsInteger = refCliente;
//   QueryResumen->ParamByName("fi")->AsDate = MC->Date;
//   QueryResumen->ParamByName("ff")->AsDate = MC->EndDate;
//   QueryResumen->Open();
//
//   CDSResumen->Active = true;



   frxReport1->PrepareReport(true);
   frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Edit1Exit(TObject *Sender)
{
   Edit1->Text = FormatFloat("0.00", StrToFloat(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------


