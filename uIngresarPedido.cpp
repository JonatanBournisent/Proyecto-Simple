//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <DateUtils.hpp>
#include <System.NetEncoding.hpp>
#include <IdMessageBuilder.hpp>
#pragma hdrstop

#include "uIngresarPedido.h"
#include "uBuscarCliente.h"
#include "FEAFIPLib_TLB.hpp"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportPDF"
#pragma link "frxBarcode"
#pragma link "frxBarcode2D"
#pragma link "frxExportBaseDialog"
#pragma resource "*.dfm"
TfIngresarPedido *fIngresarPedido;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfIngresarPedido::TfIngresarPedido(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfIngresarPedido::actualizarPresupuesto(int id, int estadoPedido, String ordAsoc)
{
   idPedido = id;
   refEstadoPedido = estadoPedido;
   ordenAsociada = ordAsoc;
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();

   Query1->SQL->Add("SELECT idArticuloPedido, refArticulo, "
   					"(SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos WHERE idArticulo = refArticulo LIMIT 1) AS descripcion, "
					"iva, cantidad, precioUnitario, "
					"(cantidad * precioUnitario) AS subtotal "
					"FROM articulospedidos WHERE refPedido = :idPedido ORDER BY descripcion");

   Query1->ParamByName("idPedido")->AsInteger = id;
   Query1->Open();
   CDS1->Active = true;
   CDS1->Last();
   agregado = false;
   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refCliente FROM pedidos WHERE idPedido = :idPedido");
   QueryAux->ParamByName("idPedido")->AsInteger = id;
   QueryAux->Open();
   idCliente = QueryAux->FieldByName("refCliente")->AsInteger;
   QueryAux->Close();

   if(refEstadoPedido > 1)
   {
	  ModificarItem1->Enabled = false;
	  AgregarItem1->Enabled = false;
	  EliminarItem1->Enabled = false;

	  Button3->Enabled = false;
	  Button7->Enabled = false;
   }
   else
   {
	  ModificarItem1->Enabled = true;
	  AgregarItem1->Enabled = true;
	  EliminarItem1->Enabled = true;

	  Button3->Enabled = true;
	  Button7->Enabled = true;
   }

   if(CDS1->IsEmpty())
	  return;

   String q;

   q = "SELECT totalCIVA, totalSIVA, IVAcompra, IVAventa21, IVAventa105, totalCompraSIVA, descuentoAplicado, baseImp21, baseImp105, compra105SIVA, compra21SIVA, artONCE, IVAcompraONCE FROM ("
	   "(SELECT SUM(cantidad * precioUnitario) AS totalCIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS totalCIVA, "
	   "(SELECT SUM(cantidad * (precioUnitario / (1 + (iva / 100.0))) * (iva / 100.0)) AS IVAventa21 FROM articulosPedidos WHERE refPedido = :idPedido AND iva = 21.00) AS IVAventa21, "
	   "(SELECT SUM(cantidad * (precioUnitario / (1 + (iva / 100.0))) * (iva / 100.0)) AS IVAventa105 FROM articulosPedidos WHERE refPedido = :idPedido AND iva = 10.50) AS IVAventa105, "
	   "(SELECT SUM(cantidad * (precioUnitario / (1 + (iva / 100.0)))) AS totalSIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS totalSIVA, "
	   "(SELECT SUM(cantidad * (precioUnitario / (1 + (iva / 100.0)))) AS baseImp21 FROM articulosPedidos WHERE refPedido = :idPedido AND iva = 21.00) AS baseImp21, "
	   "(SELECT SUM(cantidad * (precioUnitario / (1 + (iva / 100.0)))) AS baseImp105 FROM articulosPedidos WHERE refPedido = :idPedido AND iva = 10.50) AS baseImp105, "
	   "(SELECT SUM(cantidad * (SELECT articulos.precioCompra * (articulos.iva / 100.0) FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo LIMIT 1)) AS IVAcompra FROM articulosPedidos WHERE refPedido = :idPedido) AS IVAcompra, "
	   "(SELECT SUM(cantidad * (SELECT articulos.precioCompra FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo LIMIT 1)) AS totalCompraSIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS totalCompraSIVA, "
	   "(SELECT SUM(cantidad * (SELECT articulos.precioCompra FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo AND iva = 10.50 LIMIT 1)) AS compra105SIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS compra105SIVA, "


	   "(SELECT SUM(cantidad * (SELECT articulos.precioCompra                             FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo AND iva = 21.00                                                                                                      LIMIT 1)) AS compra21SIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS compra21SIVA, "
	   "(SELECT SUM(cantidad * (SELECT (articulos.precioCompra * (1 + (iva / 100.0)) * 0.04) FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo AND articulos.idArticulo IN (SELECT refArticulo FROM relacionproveedores WHERE relacionproveedores.refProveedor = 1) LIMIT 1)) AS artONCE     FROM articulosPedidos WHERE refPedido = :idPedido) AS artONCE, "
	   "(SELECT SUM(cantidad * (SELECT articulos.precioCompra * (articulos.iva / 100.0) FROM articulos WHERE articulos.idArticulo = articulosPedidos.refArticulo  AND articulos.idArticulo IN (SELECT refArticulo FROM relacionproveedores WHERE relacionproveedores.refProveedor = 1) LIMIT 1)) AS IVAcompraONCE FROM articulosPedidos WHERE refPedido = :idPedido) AS IVAcompraONCE, "

	   "(SELECT descuentoAplicado FROM pedidos WHERE idPedido = :idPedido) AS descuentoAplicado ) ";

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idPedido")->AsInteger = id;
   QueryAux->Open();

   totalCIVA = QueryAux->FieldByName("totalCIVA")->AsFloat;
   totalSIVA = QueryAux->FieldByName("totalSIVA")->AsFloat;
   artONCE = QueryAux->FieldByName("artONCE")->AsFloat;
   IVAcompraONCE = QueryAux->FieldByName("IVAcompraONCE")->AsFloat * 0.20;
   float compra105SIVA = QueryAux->FieldByName("compra105SIVA")->AsFloat;
   float compra21SIVA = QueryAux->FieldByName("compra21SIVA")->AsFloat;
   baseImp21 = QueryAux->FieldByName("baseImp21")->AsFloat;
   baseImp105 = QueryAux->FieldByName("baseImp105")->AsFloat;
   IVAcompra = QueryAux->FieldByName("IVAcompra")->AsFloat;
   float IVAventa21 =  QueryAux->FieldByName("IVAventa21")->AsFloat;
   float IVAventa105 =  QueryAux->FieldByName("IVAventa105")->AsFloat;
   totalCompraSIVA = QueryAux->FieldByName("totalCompraSIVA")->AsFloat;
   descuentoAplicado = QueryAux->FieldByName("descuentoAplicado")->AsFloat;

   factorDto = (1 - (descuentoAplicado / 100.0));


   IVAventa21CDTO = IVAventa21 * factorDto;
   IVAventa105CDTO = IVAventa105 * factorDto;
   final = totalCIVA * factorDto;

//   float gananciaEstimada = (totalSIVA * factorDto) - totalCompraSIVA - ((baseImp21 * factorDto - compra21SIVA) * 0.21) - ((baseImp105 * factorDto - compra105SIVA) * 0.105);

   QueryAux->Close();

   if((totalSIVA - baseImp21 - baseImp105) > 0.03)        //supongo que si esta todo bien no deberia superar este valor
   {
	  ShowMessage("ERROR IMPORTANTE! SE DETECTO UN ERROR IMPORTANTE. POR FAVOR NO REALIZAR FACTURAS");
	  Button13->Enabled = false;
   }

   Label9->Caption = "Subtotal S/IVA: " + FormatFloat("$ #,##0.00", totalSIVA * factorDto);
   Label10->Caption = "Subtotal C/IVA: " + FormatFloat("$ #,##0.00", totalCIVA);
   Label11->Caption = "IVA 21%: " + FormatFloat("$ #,##0.00", IVAventa21CDTO);
   Label25->Caption = "IVA 10,5%: " + FormatFloat("$ #,##0.00", IVAventa105CDTO);
   if(descuentoAplicado > 0)
   {
	  Label12->Caption = "Descuento: " + FormatFloat("#,##0.00 %", descuentoAplicado);
   }
   else
   {
	  Label12->Caption = "No se aplican descuentos";
   }
   Edit2->Text = FormatFloat("#,##0.00", descuentoAplicado);

   Label22->Caption = "Total: " + FormatFloat("$ #,##0.00", final);
   calcularGanancia();
}
//---------------------------------------------------------------------------

void TfIngresarPedido::calcularGanancia(void)
{
   float ganancia = (totalSIVA * factorDto) - totalCompraSIVA - (IVAventa21CDTO + IVAventa105CDTO - IVAcompra);

   if (CheckBox4->Checked) {
	  CheckBox6->Checked = false;
	  ganancia = ganancia * 0.98;	// -2% tienda nube
   }
   if (CheckBox5->Checked) {
      CheckBox6->Checked = false;
      ganancia = ganancia * 0.98;	// -2% pago online (mercadoPago)
   }
   if (CheckBox6->Checked) {
	   CheckBox4->Checked = false;
	   CheckBox5->Checked = false;
	   ganancia = final - totalCompraSIVA - IVAcompra;
   }
   if (CheckBox7->Checked) {
	   ganancia = ganancia + artONCE;
   }
   if (CheckBox8->Checked) {
       ganancia = ganancia + IVAcompraONCE;
   }

   float gananciaEstimada = ganancia;

   float gananciaPorcentual;
   if((totalCompraSIVA + IVAcompra) != 0.0)
	  gananciaPorcentual =  (gananciaEstimada * 100.0) / (totalCompraSIVA + IVAcompra);
   else
	  gananciaPorcentual = 0.0;

   Label23->Caption = "Ganancia Estimada: " + FormatFloat("$ #,##0.00", gananciaEstimada) + " (" + FormatFloat("0.00 %)", gananciaPorcentual);
}

//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::FormClose(TObject *Sender, TCloseAction &Action)
{
   CDS1->Active = false;
   CDS2->Active = false;
   CDS4->Active = false;
   ClientDataSet3->Active = false;
   CDSFactura->Active = false;
   Query1->Close();
   Query2->Close();
   Query3->Close();
   Query4->Close();
   QueryAux->Close();
   QueryFactura->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfIngresarPedido::FormShow(TObject *Sender)
{
   blockEdit1 = false;

   Label1->Caption = "";
   Label2->Caption = "";
   Label3->Caption = "";
   Label4->Caption = "";
   Label5->Caption = "";
   Label6->Caption = "";
   Label7->Caption = "";
   Label8->Caption = "";
   Label9->Caption = "";
   Label10->Caption = "";
   Label11->Caption = "";
   Label12->Caption = "";
   Label22->Caption = "";
   Label23->Caption = "";
   Label25->Caption = "";
   Panel1->Visible = false;
   Panel2->Visible = false;
   Panel3->Visible = false;
   Panel4->Visible = false;
   Panel5->Visible = false;
   Panel6->Visible = false;
   modificandoItem = false;
   CheckBox1->Checked = true;
   CheckBox3->Checked = false;
   Edit7->Text = "";
   Edit7->Enabled = false;

   Button3->Enabled = false;
   DBGrid1->Enabled = true;
   MC1->Date = Now();

   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);

   if(DBGrid1->Enabled)
	  DBGrid1->SetFocus();


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT MAX(fecha) AS ultimo FROM comprobanteselectronicos");
   QueryAux->Open();
   UltimaFactura = QueryAux->FieldByName("ultimo")->AsDateTime;
   QueryAux->Close();

}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::DBGrid3DblClick(TObject *Sender)
{
   idArticulo = ClientDataSet3->FieldByName("idArticulo")->AsInteger;
   iva = ClientDataSet3->FieldByName("iva")->AsFloat;
   precio = StrToFloat(FormatFloat("0", ClientDataSet3->FieldByName("precioVenta")->AsFloat * (1 + (iva / 100.0))));
   cantidadPromo = ClientDataSet3->FieldByName("cantidadPromo")->AsInteger;
   descuentoPromo = ClientDataSet3->FieldByName("descuentoPromo")->AsFloat;

   cantidad = 1;
   aplicaPromo = false;
   Label31->Caption = "";

   blockEdit1 = true;
   Edit1->Text = ClientDataSet3->FieldByName("nombreCompleto")->AsString;
   stock = ClientDataSet3->FieldByName("stock")->AsInteger;
   ClientDataSet3->Active = false;
   Query3->Close();

   edCodigo->Text = IntToStr(idArticulo);
   edCantidad->Text = IntToStr(cantidad);
   Label21->Caption = "";
   lblStock->Caption = "Stock: " + IntToStr(stock);
   edIVA->Text = FormatFloat("0.00 %", iva);
   edPSIVA->Text = FormatFloat("$ 0.00", precio / (1 + (iva / 100.0)));
   edPCIVA->Text = FormatFloat("$ 0.00", precio);
   edSCIVA->Text = FormatFloat("$ 0.00", precio * cantidad);
   edSSIVA->Text = FormatFloat("$ 0.00", precio * cantidad / (1 + (iva / 100.0)));
   edCantidad->SetFocus();
   edCantidad->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Edit1Change(TObject *Sender)
{
   if(blockEdit1)
   {
      blockEdit1 = false;
	  return;
   }
   if(Edit1->Text == "")
   {
	  ClientDataSet3->Active = false;
	  Query3->Close();
	  precio = 0.0;
	  iva = 21.0;
	  cantidad = 1;
	  edCodigo->Text = "0";
	  Label21->Caption = "";
	  lblStock->Caption = "";
	  edCantidad->Text = "1";
	  edPCIVA->Text = "$ 0,00";
	  edPSIVA->Text = "$ 0,00";
	  edIVA->Text = "21,00";
	  edSCIVA->Text = "$ 0,00";
	  edSSIVA->Text = "$ 0,00";
	  cantidadPromo = 0;
	  descuentoPromo = 0.0;
	  aplicaPromo = false;
	  return;
   }

   ClientDataSet3->Active = false;
   Query3->Close();
   Query3->SQL->Clear();
   Query3->SQL->Add("SELECT idArticulo, precioVenta, iva, stock, REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto, "
					"(IFNULL((SELECT cantidadPromo FROM promociones WHERE refArticulo = idArticulo), 0)) AS cantidadPromo, "
					"(IFNULL((SELECT descuentoPromo FROM promociones WHERE refArticulo = idArticulo), 0.0)) AS descuentoPromo "
					" FROM articulos WHERE codigo LIKE :codigo OR REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') LIKE _utf8 :nc COLLATE utf8_general_ci ORDER BY nombreCompleto LIMIT 20");
   Query3->ParamByName("nc")->AsString = "%" + Edit1->Text.UpperCase() + "%";
   Query3->ParamByName("codigo")->AsString = "%" + Edit1->Text + "%";
   Query3->Open();
   ClientDataSet3->Active = true;
   ShowScrollBar(DBGrid3->Handle, SB_VERT, true);

   if(ClientDataSet3->IsEmpty())
   {
	  ClientDataSet3->Active = false;
	  Query3->Close();
	  precio = 0.0;
	  iva = 21.0;
	  cantidad = 1;
	  edCodigo->Text = "0";
	  Label21->Caption = "";
	  lblStock->Caption = "";
	  edCantidad->Text = "1";
	  edPCIVA->Text = "$ 0,00";
	  edPSIVA->Text = "$ 0,00";
	  edIVA->Text = "21,00";
	  edSCIVA->Text = "$ 0,00";
	  edSSIVA->Text = "$ 0,00";
	  cantidadPromo = 0;
	  descuentoPromo = 0.0;
	  aplicaPromo = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::DBGrid1DblClick(TObject *Sender)
{
   if(refEstadoPedido > 1)
      return;

   if(!CDS1->Active || CDS1->IsEmpty())
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT precioUnitario, iva, cantidad, refArticulo, aplicaPromo, "
					  "(SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos WHERE articulos.idArticulo = articulospedidos.refArticulo LIMIT 1) AS nombreCompleto, "
					  "(SELECT stock FROM articulos WHERE articulos.idArticulo = articulospedidos.refArticulo LIMIT 1) AS stock, "
					  "(IFNULL((SELECT cantidadPromo FROM promociones WHERE promociones.refArticulo = articulospedidos.refArticulo), 0)) AS cantidadPromo, "
					  "(IFNULL((SELECT descuentoPromo FROM promociones WHERE promociones.refArticulo = articulospedidos.refArticulo), 0.0)) AS descuentoPromo "
					  "FROM articulospedidos WHERE idArticuloPedido = :idArticuloPedido LIMIT 1");
   QueryAux->ParamByName("idArticuloPedido")->AsInteger = CDS1->FieldByName("idArticuloPedido")->AsInteger;
   QueryAux->Open();


   idArticulo = QueryAux->FieldByName("refArticulo")->AsInteger;
   iva = QueryAux->FieldByName("iva")->AsFloat;
   precio = QueryAux->FieldByName("precioUnitario")->AsFloat;
   cantidad = QueryAux->FieldByName("cantidad")->AsInteger;
   cantidadPromo = QueryAux->FieldByName("cantidadPromo")->AsInteger;
   descuentoPromo = QueryAux->FieldByName("descuentoPromo")->AsInteger;

   if(QueryAux->FieldByName("aplicaPromo")->AsInteger == 1)
	  aplicaPromo = true;
   else
      aplicaPromo = false;

   stock = QueryAux->FieldByName("stock")->AsInteger;
   blockEdit1 = true;
   Edit1->Text = QueryAux->FieldByName("nombreCompleto")->AsString;

   QueryAux->Close();

   edCodigo->Text = IntToStr(idArticulo);
   edCantidad->Text = IntToStr(cantidad);
   lblStock->Caption = "Stock: " + IntToStr(stock);
   edIVA->Text = FormatFloat("0.00 %", iva);
   edPSIVA->Text = FormatFloat("$ 0.00", precio / (1 + (iva / 100.0)));
   edPCIVA->Text = FormatFloat("$ 0.00", precio);
   edSCIVA->Text = FormatFloat("$ 0.00", precio * cantidad);
   edSSIVA->Text = FormatFloat("$ 0.00", precio * cantidad * (1 + (iva / 100.0)));

   Button5->Caption = "Guardar cambios";
   Button5->Enabled = true;
   Label21->Caption = "";

   if(aplicaPromo)
	  Label31->Caption = "Precio promocional. (" + FormatFloat("0.00 % OFF", descuentoPromo) + ")";
   else
	  Label31->Caption = "";

   idItemModificado = CDS1->FieldByName("idArticuloPedido")->AsInteger;
   modificandoItem = true;
   edCodigo->Enabled = false;
   Edit1->Enabled = false;
   Panel2->Visible = true;
   edCantidad->SetFocus();
   edCantidad->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button3Click(TObject *Sender)
{
   if(refEstadoPedido > 1)
	  return;


   CDS2->Active = false;
   Query2->Close();
   Query2->SQL->Clear();
   Query2->SQL->Add("SELECT g.refArticulo, g.cantidad, g.stock, g.nombre FROM (SELECT refArticulo, cantidad, "
					"(SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos WHERE articulosPedidos.refArticulo = articulos.idArticulo LIMIT 1) AS nombre, "
					"(SELECT stock FROM articulos WHERE articulosPedidos.refArticulo = articulos.idArticulo LIMIT 1) AS stock "
					"FROM articulosPedidos WHERE refPedido = :idPedido) g "
					"WHERE (g.cantidad - g.stock) > 0 ORDER BY g.nombre");
   Query2->ParamByName("idPedido")->AsInteger = idPedido;
   Query2->Open();
   CDS2->Active = true;
   ShowScrollBar(DBGrid2->Handle, SB_VERT, true);

   if(!CDS2->IsEmpty())
   {
	  Panel4->Visible = true;
	  return;
   }

   if(Application->MessageBox(L"Realmente desea confirmar pedido? Esto provocará el descuento de stock de los artículos incluídos y el pedido ya no podrá ser modificado.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE articulos SET stock = (stock - (SELECT cantidad FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)) "
   				      "WHERE idArticulo IN (SELECT refArticulo FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET refEstadoPedido = 2, fechaConfirmacion = DATE(NOW()) WHERE idPedido = :idPedido AND refEstadoPedido = 1 LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = idPedido;
   QueryAux->ExecSQL();

   refEstadoPedido = 2;
   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button4Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   CDS4->Active = false;
   Query4->Close();
   Query4->SQL->Clear();
   Query4->SQL->Add("SELECT *, (SELECT descripcion FROM condicionesFrenteIVA WHERE idCondicionFrenteIVA = refCondicionFrenteIVA LIMIT 1) AS condfiva, "
					"(SELECT fechaConfirmacion FROM pedidos WHERE idPedido = :idPedido LIMIT 1) AS fechaPedido "
					"FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   Query4->ParamByName("idCliente")->AsInteger = idCliente;
   Query4->ParamByName("idPedido")->AsInteger = idPedido;
   Query4->Open();
   CDS4->Active = true;

   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo27"))->Text = "Subtotal: " + FormatFloat("$ #,##0.00", totalCIVA);		//Label10->Caption;
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo28"))->Text = Label12->Caption;
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo29"))->Text = Label22->Caption;

   if(CheckBox2->Checked)
   {
      dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo37"))->Text = "Presupuesto válido hasta el: " + FormatDateTime("dd/mm/yyyy", IncDay(Now(), 10)) + ". Pasada esta fecha, los valores deberán ser actualizados.";
      dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo37"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo2"))->Text = "PRESUPUESTO";
   }
   else
   {
      dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo37"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo2"))->Text = "ORDEN DE COMPRA";
   }

   float altMemo = dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo27"))->Height;
   float m27 = dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo27"))->Top;

   if(descuentoAplicado == 0)
   {
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo28"))->Visible = false;
	   dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport1->FindObject("Shape1"))->Height = altMemo * 3.6;

	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo29"))->Top = m27 + altMemo * 1.5;
   }
   else
   {
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo28"))->Visible = true;

	   dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport1->FindObject("Shape1"))->Height = altMemo * 5.1;

	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo28"))->Top = m27 + altMemo * 1.5;
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo29"))->Top = m27 + altMemo * 3;
   }

   String nroPedido = IntToStr(idPedido);
   while(nroPedido.Length() < 6)
	  nroPedido.Insert("0",1);
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo34"))->Text = nroPedido;

   if(CDS4->FieldByName("cuit")->AsString.Length() < 9)
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo19"))->Text = "DNI:";
   else
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo19"))->Text = "CUIT:";

   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport1->FindObject("Memo30"))->Text = "Orden asociada: " + ordenAsociada;

   frxReport1->PrepareReport(true);
   frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
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

void __fastcall TfIngresarPedido::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(refEstadoPedido > 1)
	  return;


   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button5Click(TObject *Sender)
{
   if(edCantidad->Text == "0" || edCodigo->Text == "0")
	  return;

   if(StrToInt(edCantidad->Text) > stock)
   {
	  if(Application->MessageBox(L"La cantidad ingresada es mayor al stock actual. Desea continuar de todos modos?",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
		 return;
   }

   if(!modificandoItem)
   {
       QueryAux->Close();
       QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("SELECT refArticulo FROM articulosPedidos WHERE refPedido = :refPedido AND refArticulo = :refArticulo LIMIT 1");
	   QueryAux->ParamByName("refArticulo")->AsInteger = idArticulo; //StrToInt(edCodigo->Text);
	   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
	   QueryAux->Open();
	   if(!QueryAux->IsEmpty())
	   {
		   Application->MessageBox(L"Este artículo ya se encuentra agregado.",L"ERROR!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		   QueryAux->Close();
		   return;
	   }

	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("INSERT INTO articulospedidos (refArticulo, refPedido, cantidad, precioUnitario, iva, aplicaPromo) "
						  "VALUES (:refArticulo, :refPedido, :cantidad, :precioUnitario, :iva, :aplicaPromo)");
	   QueryAux->ParamByName("refArticulo")->AsInteger = idArticulo; //StrToInt(edCodigo->Text);
	   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
	   QueryAux->ParamByName("cantidad")->AsInteger = cantidad; //StrToInt(edCantidad->Text);
	   QueryAux->ParamByName("precioUnitario")->AsFloat = precio; //StrToFloat(edCantidad->Text) / (1 + (iva / 100.0));
	   QueryAux->ParamByName("iva")->AsFloat = iva;
	   if(aplicaPromo)
		  QueryAux->ParamByName("aplicaPromo")->AsInteger = 1;
	   else
		  QueryAux->ParamByName("aplicaPromo")->AsInteger = 0;

	   QueryAux->ExecSQL();
	   blockEdit1 = true;
	   Edit1->Clear();
	   Edit1->SetFocus();
   }
   else
   {
   	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("UPDATE articulospedidos SET refArticulo = :refArticulo, "
						  "cantidad = :cantidad, precioUnitario = :precioUnitario, iva = :iva, aplicaPromo = :aplicaPromo "
						  "WHERE idArticuloPedido = :idArticuloPedido LIMIT 1");
	   QueryAux->ParamByName("idArticuloPedido")->AsInteger = idItemModificado;
	   QueryAux->ParamByName("refArticulo")->AsInteger = idArticulo; //StrToInt(edCodigo->Text);
	   QueryAux->ParamByName("cantidad")->AsInteger = cantidad; //StrToInt(edCantidad->Text);
	   QueryAux->ParamByName("precioUnitario")->AsFloat = precio; //StrToFloat(edCantidad->Text) / (1 + (iva / 100.0));
	   QueryAux->ParamByName("iva")->AsFloat = iva;

	   if(aplicaPromo)
		  QueryAux->ParamByName("aplicaPromo")->AsInteger = 1;
	   else
		  QueryAux->ParamByName("aplicaPromo")->AsInteger = 0;

	   QueryAux->ExecSQL();

	   modificandoItem = false;
	   edCodigo->Enabled = true;
	   Edit1->Enabled = true;

	   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);
	   Panel2->Visible = false;
	   DBGrid1->SetFocus();
   }

   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);

   precio = 0.0;
   iva = 21.0;
   cantidad = 1;
   edCodigo->Text = "0";
   Label21->Caption = "";
   edCantidad->Text = "1";
   edPCIVA->Text = "$ 0,00";
   edPSIVA->Text = "$ 0,00";
   edIVA->Text = "21,00";
   edSCIVA->Text = "$ 0,00";
   edSSIVA->Text = "$ 0,00";
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edCodigoExit(TObject *Sender)
{
   try
   {
	   StrToInt(dynamic_cast<TEdit *>(Sender)->Text);
   }
   catch (...)
   {
       dynamic_cast<TEdit *>(Sender)->Text = "0";
   }

   if(edCodigo->Text.Length() >= 1)
   {
		QueryAux->Close();
		QueryAux->SQL->Clear();
		QueryAux->SQL->Add("SELECT idArticuloPedido FROM articulospedidos WHERE articulospedidos.refArticulo = :refArticulo AND articulospedidos.refPedido = :idPedido LIMIT 1");
		QueryAux->ParamByName("refArticulo")->AsInteger = StrToInt(edCodigo->Text);
		QueryAux->ParamByName("idPedido")->AsInteger = idPedido;
		QueryAux->Open();
		if(!QueryAux->IsEmpty())
		{
		  Button5->Enabled = false;
		  Label21->Caption = "Este artículo ya existe en el pedido";
		}
		else
		{
		  Button5->Enabled = true;
		  Label21->Caption = "";
		}

		QueryAux->Close();
		QueryAux->SQL->Clear();
		QueryAux->SQL->Add("SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto, "
						   "iva, stock, precioVenta, "
						   "(IFNULL((SELECT cantidadPromo FROM promociones WHERE refArticulo = :idArticulo), 0)) AS cantidadPromo, "
						   "(IFNULL((SELECT descuentoPromo FROM promociones WHERE refArticulo = :idArticulo), 0.0)) AS descuentoPromo "
						   "FROM articulos WHERE articulos.idArticulo = :idArticulo LIMIT 1");
		QueryAux->ParamByName("idArticulo")->AsInteger = StrToInt(edCodigo->Text);
		QueryAux->Open();
		if(QueryAux->IsEmpty() && !modificandoItem)   //si estoy modificando el idArticulo sera igual al que ya habia en el pedido
		{
		  Button5->Enabled = false;
		  Label21->Caption = "Este código no corresponde a un artículo registrado";
		  return;
		}
		else
		{
		   Button5->Enabled = true;
		   Label21->Caption = "";

		   blockEdit1 = true;
		   Edit1->Text = QueryAux->FieldByName("nombreCompleto")->AsString;

		   idArticulo = StrToInt(edCodigo->Text);
		   iva = QueryAux->FieldByName("iva")->AsFloat;
		   stock = QueryAux->FieldByName("stock")->AsInteger;
		   cantidadPromo = QueryAux->FieldByName("cantidadPromo")->AsInteger;
		   descuentoPromo = QueryAux->FieldByName("descuentoPromo")->AsInteger;
		   //precio = QueryAux->FieldByName("precioVenta")->AsFloat * (1 + (iva / 100.0));
		   precio = StrToFloat(FormatFloat("0", QueryAux->FieldByName("precioVenta")->AsFloat * (1 + (iva / 100.0))));
		   cantidad = 1;
		   aplicaPromo = false;
		   Label31->Caption = "";

		   edCodigo->Text = IntToStr(idArticulo);
		   edCantidad->Text = IntToStr(cantidad);
		   lblStock->Caption = "Stock: " + IntToStr(stock);
		   edIVA->Text = FormatFloat("0.00 %", iva);
		   edPSIVA->Text = FormatFloat("$ 0.00", precio / (1 + (iva / 100.0)));
		   edPCIVA->Text = FormatFloat("$ 0.00", precio);
		   edSCIVA->Text = FormatFloat("$ 0.00", precio * cantidad);
		   edSSIVA->Text = FormatFloat("$ 0.00", precio * cantidad / (1 + (iva / 100.0)));
		}
		QueryAux->Close();
   }
   else
   {
	  Button5->Enabled = false;
	  Label21->Caption = "";
   }
}
//---------------------------------------------------------------------------
void __fastcall TfIngresarPedido::edCantidadExit(TObject *Sender)
{
   try
   {
	   StrToInt(dynamic_cast<TEdit *>(Sender)->Text);
   }
   catch (...)
   {
	   dynamic_cast<TEdit *>(Sender)->Text = "0";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(refEstadoPedido > 1)
	  return;

   if(Key == VK_RETURN)
   {
	  precio = 0.0;
	  iva = 21.0;
	  cantidad = 1;
	  edCodigo->Text = "0";
	  Label21->Caption = "";
	  Label31->Caption = "";
	  lblStock->Caption = "";
	  edCantidad->Text = "1";
	  edPCIVA->Text = "$ 0,00";
	  edPSIVA->Text = "$ 0,00";
	  edIVA->Text = "21,00";
	  edSCIVA->Text = "$ 0,00";
	  edSSIVA->Text = "$ 0,00";
	  Button5->Caption = "Agregar este ítem al pedido";

	  Panel2->Visible = true;
	  Edit1->Clear();
	  Edit1->SetFocus();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button6Click(TObject *Sender)
{
   modificandoItem = false;
   edCodigo->Enabled = true;
   Edit1->Enabled = true;
   Panel2->Visible = false;
   DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edCantidadChange(TObject *Sender)
{
   if(edCantidad->Text.Length() > 0)
	  cantidad = StrToInt(edCantidad->Text);
   else
	  cantidad = 0;

   if(cantidadPromo > 0 && !aplicaPromo && cantidad >= cantidadPromo)
   {
	  aplicaPromo = true;
	  precio = precio * (1 - (descuentoPromo / 100.0));
	  Label31->Caption = "Precio promocional. (" + FormatFloat("0.00 % OFF", descuentoPromo) + ")";
   }
   else if(cantidadPromo > 0 && aplicaPromo && cantidad < cantidadPromo)
   {
	  aplicaPromo = false;
	  precio = precio / (1 - (descuentoPromo / 100.0));
	  Label31->Caption = "";
   }

   edPSIVA->Text = FormatFloat("$ 0.00", precio / (1 + (iva / 100.0)));
   edPCIVA->Text = FormatFloat("$ 0.00", precio);
   edSCIVA->Text = FormatFloat("$ 0.00", precio * cantidad);
   edSSIVA->Text = FormatFloat("$ 0.00", precio * cantidad / (1 + (iva / 100.0)));

}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edCantidadKeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edPCIVAChange(TObject *Sender)
{
   if(edPCIVA->Text.Pos("$") > 0)
	  precio = StrToFloat(edPCIVA->Text.Delete(1,2));
   else if(edPCIVA->Text.Length() > 0)
	  precio = StrToFloat(edPCIVA->Text);
   else
	  precio = 0.0;


   edPSIVA->Text = FormatFloat("$ 0.00", precio / (1 + (iva / 100.0)));
   edSCIVA->Text = FormatFloat("$ 0.00", precio * cantidad);
   edSSIVA->Text = FormatFloat("$ 0.00", precio * cantidad / (1 + (iva / 100.0)));
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edPCIVAEnter(TObject *Sender)
{
   if(edPCIVA->Text.Pos("$") > 0)
	  edPCIVA->Text = edPCIVA->Text.Delete(1,2);

   edPCIVA->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edPCIVAExit(TObject *Sender)
{
   try
   {
	   StrToFloat(dynamic_cast<TEdit *>(Sender)->Text);
   }
   catch (...)
   {
	   dynamic_cast<TEdit *>(Sender)->Text = "0,0";
   }

   if(edPCIVA->Text.Pos("$") == 0)
	  edPCIVA->Text = edPCIVA->Text.Insert("$ ", 1);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::edPCIVAKeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfIngresarPedido::edCodigoKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      edCodigoExit(edCodigo);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::FormCreate(TObject *Sender)
{
   Panel2->Left = (fIngresarPedido->Width - Panel2->Width ) / 2;
   Panel2->Top = (fIngresarPedido->Height - Panel2->Height ) / 8;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::ModificarItem1Click(TObject *Sender)
{
   DBGrid1DblClick(PopupMenu1);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::EliminarItem1Click(TObject *Sender)
{
   if(!CDS1->Active || CDS1->IsEmpty())
	  return;

   if(Application->MessageBox(L"Confirma que desea eliminar este ítem del pedido?",L"Eliminar?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM articulospedidos WHERE idArticuloPedido = :id");
   QueryAux->ParamByName("id")->AsInteger = CDS1idArticuloPedido->AsInteger;
   QueryAux->ExecSQL();

   CDS1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::AgregarItem1Click(TObject *Sender)
{
	  precio = 0.0;
	  iva = 21.0;
	  cantidad = 1;
	  edCodigo->Text = "0";
	  Label21->Caption = "";
	  Label31->Caption = "";
	  edCantidad->Text = "1";
	  edPCIVA->Text = "$ 0,00";
	  edPSIVA->Text = "$ 0,00";
	  edIVA->Text = "21,00";
	  edSCIVA->Text = "$ 0,00";
	  edSSIVA->Text = "$ 0,00";
	  Panel2->Visible = true;
	  Edit1->Clear();
	  Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button7Click(TObject *Sender)
{
//   if(Application->MessageBox(L"Realmente desea confirmar pedido? Esto provocará el descuento de stock de los artículos incluídos y el pedido ya no podrá ser modificado.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
//	  return;

    Panel3->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TfIngresarPedido::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(!ClientDataSet3->Active)
	  return;

   if(Key == VK_RETURN && ClientDataSet3->RecordCount == 1)
      DBGrid3DblClick(Edit1);

}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button8Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button9Click(TObject *Sender)
{

   if(idCliente > 0)
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT * FROM clientes WHERE idCliente = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = idCliente;
	  QueryAux->Open();

	  Label1->Caption = "Nombre: " + QueryAux->FieldByName("nombre")->AsString;
	  Label2->Caption = "Apellido: " + QueryAux->FieldByName("apellido")->AsString;
	  Label3->Caption = "Razon Social: " + QueryAux->FieldByName("razonSocial")->AsString;
	  Label4->Caption = "Domicilio: " + QueryAux->FieldByName("domicilio")->AsString;
	  Label5->Caption = "Telefono: " + QueryAux->FieldByName("telefono")->AsString;
	  Label6->Caption = "Celular: " + QueryAux->FieldByName("celular")->AsString;
	  Label7->Caption = "Cuit: " + QueryAux->FieldByName("cuit")->AsString;
	  Label8->Caption = "Descuento preestablecido: " + QueryAux->FieldByName("descuento")->AsString + " %";

	  QueryAux->Close();
	  Panel1->Visible = true;
   }
   else
   {
	  Application->MessageBox(L"Debe seleccionar un cliente!",L"Falta cliente!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button1Click(TObject *Sender)
{
   Panel3->Visible = false;
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET descuentoAplicado = :descuentoAplicado WHERE idPedido = :idPedido LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = idPedido;
   QueryAux->ParamByName("descuentoAplicado")->AsFloat = StrToFloat(Edit2->Text);
   QueryAux->ExecSQL();

   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button2Click(TObject *Sender)
{
   Panel4->Visible = false;
   Query2->Close();
   CDS2->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfIngresarPedido::Button10Click(TObject *Sender)
{
   if(Application->MessageBox(L"Desea confirmar este pedido aunque no disponga del stock necesario? Los artículos indicados pasarán a tener stock negativo.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   if(refEstadoPedido > 1)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE articulos SET stock = (stock - (SELECT cantidad FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)) "
   				      "WHERE idArticulo IN (SELECT refArticulo FROM articulosPedidos WHERE articulosPedidos.refPedido = :refPedido AND articulosPedidos.refArticulo = articulos.idArticulo)");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET refEstadoPedido = 2, fechaConfirmacion = DATE(NOW()) WHERE idPedido = :idPedido AND refEstadoPedido = 1 LIMIT 1");
   QueryAux->ParamByName("idPedido")->AsInteger = idPedido;
   QueryAux->ExecSQL();

   refEstadoPedido = 2;
   actualizarPresupuesto(idPedido, refEstadoPedido, ordenAsociada);

   Panel4->Visible = false;
   Query2->Close();
   CDS2->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TfIngresarPedido::CDS4fechaPedidoGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(Sender->AsString == "01/01/2100")
	  Text = "NO CONFIRMADO";
   else
	  Text = Sender->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button11Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRemito, fecha FROM remitos WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  Application->MessageBox(L"No hay remitos asociados a esta orden de compra. Deberá generar el remito primero.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }
   String nroRemito = QueryAux->FieldByName("idRemito")->AsString;
   String fecha = FormatDateTime("dd/mm/yyyy", QueryAux->FieldByName("fecha")->AsDateTime);
   QueryAux->Close();


   CDS4->Active = false;
   Query4->Close();
   Query4->SQL->Clear();
   Query4->SQL->Add("SELECT *, (SELECT descripcion FROM condicionesFrenteIVA WHERE idCondicionFrenteIVA = refCondicionFrenteIVA LIMIT 1) AS condfiva, "
					"(SELECT fechaConfirmacion FROM pedidos WHERE idPedido = :idPedido LIMIT 1) AS fechaPedido "
					"FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   Query4->ParamByName("idCliente")->AsInteger = idCliente;
   Query4->ParamByName("idPedido")->AsInteger = idPedido;
   Query4->Open();
   CDS4->Active = true;

   String nroPedido = IntToStr(idPedido);
   while(nroPedido.Length() < 6)
	  nroPedido.Insert("0",1);

   while(nroRemito.Length() < 6)
	  nroRemito.Insert("0",1);

   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport2->FindObject("Memo17"))->Text = nroPedido;
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport2->FindObject("Memo34"))->Text = nroRemito;
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport2->FindObject("Memo36"))->Text = fecha;

   if(CDS4->FieldByName("cuit")->AsString.Length() < 9)
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport2->FindObject("Memo19"))->Text = "DNI:";
   else
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport2->FindObject("Memo19"))->Text = "CUIT:";

   frxReport2->PrepareReport(true);
   frxReport2->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button12Click(TObject *Sender)
{
   if(refEstadoPedido < 2)
   {
	  Application->MessageBox(L"El pedido debe estar confirmado para poder generar un remito asociado.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRemito FROM remitos WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(!QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  Application->MessageBox(L"Ya hay un remito asociado a esta orden de pedido.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }


   if(Application->MessageBox(L"Se va a generar un remito con fecha de hoy para esta orden de compra. La fecha no podrá modificarse luego. Desea continuar?",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO remitos (refPedido, fecha) VALUES (:refPedido, DATE(NOW()))");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button13Click(TObject *Sender)
{
   if(refEstadoPedido < 2)
   {
	  Application->MessageBox(L"El pedido debe estar confirmado antes de ser facturado.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }

   if(totalCIVA < 0.0)
   {
	  Application->MessageBox(L"No es posible generar un comprobante electrónico con valor negativo." ,L"Error.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }
   else if(totalCIVA == 0.0)
   {
	  if(Application->MessageBox(L"Esta por generar un comprobante por un valor de $ 0,00. Realmente desea continuar?" ,L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  {
		 return;
	  }
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idPedidoFacturado FROM pedidosFacturados WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(!QueryAux->IsEmpty())
   {  //Por la forma en la que hay que mostrar la informacion en el resumen de cuenta corriente, facturar dos veces el mismo pedido traería complicaciones
	  Application->MessageBox(L"Este pedido ya fue facturado.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }

   String remitoAsociado;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRemito FROM remitos WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  if(Application->MessageBox(L"Aún no se generó un remito para esta orden de compra. Desea continuar?",L"ATENCIÓN",MB_YESNO | MB_ICONINFORMATION | MB_DEFBUTTON2) != IDYES)
		 return;
	  remitoAsociado = "";
   }
   else
   {
      remitoAsociado = QueryAux->FieldByName("idRemito")->AsString;
	  QueryAux->Close();
   }


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
   String mm = Configuraciones->ReadString("Facturas","maximoSinDatos", "$ 0,00");

   if(mm.Pos("$ ") > 0)
	  mm = mm.Delete(1,2);
   else
	  mm = "0,00";   //hay algun error

   maximoFactSD = StrToFloat(mm);


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

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT cuit, razonSocial, domicilio, refCondicionFrenteIVA, "
					  "(SELECT descripcion FROM condicionesFrenteIVA WHERE idCondicionFrenteIVA = refCondicionFrenteIVA LIMIT 1) AS condFrenteIVA "
					  " FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   QueryAux->ParamByName("idCliente")->AsInteger = idCliente;
   QueryAux->Open();
   String cuit, razonSocial, domicilio, condFrenteIVA;
   int refCondicionFrenteIVA;
   cuit = QueryAux->FieldByName("cuit")->AsString;
   razonSocial = QueryAux->FieldByName("razonSocial")->AsString;
   domicilio = QueryAux->FieldByName("domicilio")->AsString;
   refCondicionFrenteIVA = QueryAux->FieldByName("refCondicionFrenteIVA")->AsInteger;
   condFrenteIVA = QueryAux->FieldByName("condFrenteIVA")->AsString;
   QueryAux->Close();



   CDSFactura->Active = false;
   QueryFactura->Close();
   QueryFactura->SQL->Clear();
   String qFact;


   if(refCondicionFrenteIVA == 2)
   {
	  qFact = "SELECT idArticuloPedido, refArticulo, "
			  "(SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos WHERE idArticulo = refArticulo LIMIT 1) AS descripcion, "
			  "iva, cantidad, (precioUnitario / (1 + (iva / 100.0))) AS precioUnitario, "
			  "(cantidad * (precioUnitario / (1 + (iva / 100.0)))) AS subtotal "
			  "FROM articulospedidos WHERE refPedido = :idPedido ORDER BY descripcion";
   }
   else
   {
	  qFact = "SELECT idArticuloPedido, refArticulo, "
			  "(SELECT REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos WHERE idArticulo = refArticulo LIMIT 1) AS descripcion, "
			  "iva, cantidad, precioUnitario, "
			  "(cantidad * precioUnitario) AS subtotal "
			  "FROM articulospedidos WHERE refPedido = :idPedido ORDER BY descripcion";
   }

   QueryFactura->SQL->Add(qFact);

   QueryFactura->ParamByName("idPedido")->AsInteger = idPedido;
   QueryFactura->Open();
   CDSFactura->Active = true;


   if(!CDS1->Active)
	  return;

   CDS4->Active = false;
   Query4->Close();
   Query4->SQL->Clear();
   Query4->SQL->Add("SELECT *, (SELECT descripcion FROM condicionesFrenteIVA WHERE idCondicionFrenteIVA = refCondicionFrenteIVA LIMIT 1) AS condfiva, "
					"(SELECT fechaConfirmacion FROM pedidos WHERE idPedido = :idPedido LIMIT 1) AS fechaPedido "
					"FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   Query4->ParamByName("idCliente")->AsInteger = idCliente;
   Query4->ParamByName("idPedido")->AsInteger = idPedido;
   Query4->Open();
   CDS4->Active = true;

//   String s;

   bool sinDatos, conDNI;

   sinDatos = false;
   
   if(cuit.Pos("-") > 0)
   {
	  if(cuit == "00-00000000-0")
		 sinDatos = true;
   }
   else if(cuit == "")
	  sinDatos = true;
   else if(StrToInt(cuit) == 0)
	  sinDatos = true;

   if(domicilio.Length() < 3)
	  sinDatos = true;
   else if(razonSocial.Length() < 2)
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
	  
   if(sinDatos && (totalCIVA > maximoFactSD))
   {
	  String msg = "Error: para emitir facturas con monto mayor a: " + FormatFloat("$ 0.00", maximoFactSD);
	  msg = msg + " debe completar todos los datos del cliente\nCuit, Domicilio Fiscal y Razón Social o Nombre y Apellido";
	  Application->MessageBox(msg.w_str() ,L"ERROR!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);

	  return;
   }


   if(sinDatos && (refCondicionFrenteIVA == 2))
   {
	  String msg = "Error: para emitir facturas A debe completar todos los datos del cliente\nCuit, Domicilio Fiscal y Razón Social o Nombre y Apellido";
	  Application->MessageBox(msg.w_str() ,L"ERROR!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);

	  return;
   }

   String s;

   if(refCondicionFrenteIVA == 2)
   {
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Text = "Subtotal: " + FormatFloat("$ 0.00", totalSIVA);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Text = "Descuento: " + FormatFloat("0.00 %", descuentoAplicado);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo29"))->Text = "Neto Gravado: " + FormatFloat("$ 0.00", totalSIVA * factorDto);;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Text = "IVA 10,5%: " + FormatFloat("$ 0.00", IVAventa105CDTO);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Text = "IVA 21%: " + FormatFloat("$ 0.00", IVAventa21CDTO);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Text = "TOTAL: " + FormatFloat("$ 0.00", final);

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo29"))->Visible = true;
//	  if(IVAventa105CDTO > 0)
		 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Visible = true;
//	  else
//		 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Visible = false;
//	  if(IVAventa21CDTO > 0)
		 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Visible = true;
//	  else
//		 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Visible = false;

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Visible = true;


	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo30"))->Text = "A";
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo37"))->Text = "COD. 01";
	  s = "FACTURA A";
   }
   else
   {
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Text = "Subtotal: " + FormatFloat("$ 0.00", totalCIVA);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Text = "Descuento: " + FormatFloat("0.00 %", descuentoAplicado);
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Text = "TOTAL: " + FormatFloat("$ 0.00", final);

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo29"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Visible = false;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Visible = true;

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo30"))->Text = "B";
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo37"))->Text = "COD. 06";

	  s = "FACTURA B";
   }

   if(descuentoAplicado == 0)
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Visible = false;
   else
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Visible = true;


   if(remitoAsociado.Length() > 0)  //solo si hay remito asociado. Si no queda texto vacio
   {
	  while(remitoAsociado.Length() < 6)
		 remitoAsociado.Insert("0",1);
	  remitoAsociado = "Remito asociado: " + remitoAsociado;
   }
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo43"))->Text = remitoAsociado;

   String nroPedido = IntToStr(idPedido);
   while(nroPedido.Length() < 6)
	  nroPedido.Insert("0",1);

   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo42"))->Text = "Orden de compra asociada: " + nroPedido;

   float altMemo = dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Height;
   float m27 = dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo27"))->Top;


   if(refCondicionFrenteIVA == 2 && descuentoAplicado > 0)
   {
	  dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport3->FindObject("frxShapeView1"))->Height = altMemo * 9.8;

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo29"))->Top = m27 + altMemo * 3;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Top = m27 + altMemo * 4.5;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Top = m27 + altMemo * 6;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Top = m27 + altMemo * 7.5;
   }
   else if(refCondicionFrenteIVA == 2 && descuentoAplicado == 0)
   {

	  dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport3->FindObject("frxShapeView1"))->Height = altMemo * 8.3;

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo29"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo34"))->Top = m27 + altMemo * 3;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo39"))->Top = m27 + altMemo * 4.5;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Top = m27 + altMemo * 6;
   }
   else if(descuentoAplicado > 0)
   {
	  dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport3->FindObject("frxShapeView1"))->Height = altMemo * 5.3;

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo28"))->Top = m27 + altMemo * 1.5;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Top = m27 + altMemo * 3;
   }
   else
   {
	  dynamic_cast <TfrxShapeView *> (fIngresarPedido->frxReport3->FindObject("frxShapeView1"))->Height = altMemo * 3.8;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo40"))->Top = m27 + altMemo * 1.5;
   }

   if(conDNI)
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo19"))->Text = "DNI:";
   else
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo19"))->Text = "CUIT:";

//   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo36"))->Text = FormatDateTime("dd/mm/yyyy", Now());
   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo36"))->Text = FormatDateTime("dd/mm/yyyy", MC1->Date);




   if(sinDatos)
   {
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo9"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo10"))->Visible = true;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo12"))->Visible = true;
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
   double netoGravado = StrToFloat(FormatFloat("0.00", totalSIVA * factorDto));
   double BASEIMP21 = StrToFloat(FormatFloat("0.00",  baseImp21 * factorDto));
   double BASEIMP105 = StrToFloat(FormatFloat("0.00", baseImp105 * factorDto));
   double IVA21 = StrToFloat(FormatFloat("0.00", IVAventa21CDTO));
   double IVA105 = StrToFloat(FormatFloat("0.00", IVAventa105CDTO));

   bool error = false;

   double nro = 0;
   int PtoVta = 4;   //Punto de venta dado de alta en AFIP para Web Service

   int TipoComp;     //Codigo de Tipo de comprobante segun tabla de AFIP (resumen arriba)


   if(refCondicionFrenteIVA == 2)
	  TipoComp = 1;
   else
	  TipoComp = 6;

//   String FechaComp = FormatDateTime("yyyyMMdd", Now());
   String FechaComp = FormatDateTime("yyyyMMdd", MC1->Date);

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

   if(TipoComp == 1)
	  tipoComp = "A";
   else if(TipoComp == 6)
	  tipoComp = "B";
   else
      return;

   String mensaje = "Se va a emitir una factura " + tipoComp + " a nombre de: \n\n";
   mensaje  = mensaje + "Razón Social: " + razonSocial;
   if(conDNI)
	  mensaje  = mensaje + "\nDNI: " + cuit;
   else
	  mensaje  = mensaje + "\nCUIT: " + cuit;
   mensaje  = mensaje + "\nCondición frente al IVA: " + condFrenteIVA;
   mensaje = mensaje + "\n\nNeto Gravado: " + FormatFloat("$ #,##0.00", netoGravado);
   mensaje = mensaje + "\nIVA 21%: " + FormatFloat("$ #,##0.00", IVA21);
   mensaje = mensaje + "\nIVA 10,5%: " + FormatFloat("$ #,##0.00", IVA105);
   mensaje = mensaje + "\nImporte TOTAL: " + FormatFloat("$ #,##0.00", totalComp);
   mensaje = mensaje + "\n\nFecha del comprobante: " + FormatDateTime("dd/mm/yyyy", MC1->Date);
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

   frxPDFExport1->FileName = DirFacturas + "\\" + s + ptoDeVenta + "-" + nroComp + " - DUPLICADO.pdf";
   frxPDFExport2->FileName = DirFacturas + "\\" + s + ptoDeVenta + "-" + nroComp + ".pdf";

   if(comprobanteAutorizado)
   {
     String importe = FormatFloat("0.00",totalComp);
	 importe = importe.Delete(importe.Length() - 2, 1);
	 importe = importe.Insert(".", importe.Length() - 1);

	 if(importe.Pos(".00") > 0)
		importe = importe.SubString(1,importe.Pos(".00") - 1);

	 String json = "{\"ver\":1,\"fecha\":\"" + FormatDateTime("yyyy-mm-dd", MC1->Date);
	 json = json + "\",\"cuit\":" + CUIT + ",\"ptoVta\":" + IntToStr(PtoVta);
	 json = json + ",\"tipoCmp\":" + IntToStr(TipoComp) + ",\"nroCmp\":" + IntToStr(__int64(nro));
	 json = json + ",\"importe\":";
	 json = json + importe;
	 json = json + ",\"moneda\":\"PES\",\"ctz\":1";

	 if(sinDatos)
		json = json + "";
	 else if(conDNI)
		json = json + ",\"tipoDocRec\":96";
	 else
		json = json + ",\"tipoDocRec\":80";

	 String nDoc = cuit;
//		 nDoc = "20295355442";

	 if(conDNI && nDoc.Length() > 0)
	 {
		while(nDoc.Pos("0") == 1)
		   nDoc = nDoc.Delete(1,1);
	 }

	 if(!sinDatos)
		json = json + ",\"nroDocRec\":" + nDoc;


	 json = json + ",\"tipoCodAut\":\"E\",\"codAut\":";
	 json = json + CAE + "}";

	 String encJSON = "https://www.afip.gob.ar/fe/qr/?p=" + TNetEncoding::Base64->Encode(json);

	 while(encJSON.Pos('\r'))
		encJSON = encJSON.Delete(encJSON.Pos('\r'), 1);
	 while(encJSON.Pos('\n'))
		encJSON = encJSON.Delete(encJSON.Pos('\n'), 1);






	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo38"))->Text = "ORIGINAL";
	  dynamic_cast <TfrxBarCodeView *> (fIngresarPedido->frxReport3->FindObject("BarCode1"))->Text = codigoBarra;
	  dynamic_cast <TfrxBarcode2DView *> (fIngresarPedido->frxReport3->FindObject("Barcode2D1"))->Text = encJSON;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("caeComp"))->Text = "N° de CAE: " + CAE;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("nroComp"))->Text = ptoDeVenta + " - " + nroComp;
	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("vencComp"))->Text = "Fecha de Vto. de CAE: " + fechaVencimiento;
	  frxReport3->PrintOptions->Printer = imp_actual;
	  frxReport3->PrepareReport(true);
//	  frxReport3->ShowReport(true);
	  frxReport3->Print();

	  if(!frxReport3->Export(frxPDFExport2))	//GUARDA EL ORIGINAL EN LA PC
	  {
			Application->MessageBox(L"Especifique manualmente una ubicación (y nombre de archivo) donde guardar el comprobante ORIGINAL.", L"ATENCIÓN",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport2->FileName = SD1->FileName;
			frxReport3->Export(frxPDFExport2);
	  }

	  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport3->FindObject("Memo38"))->Text = "DUPLICADO";
	  frxReport3->PrepareReport(true);

	  if(!frxReport3->Export(frxPDFExport1))   //GUARDA EL DUPLICADO EN LA PC
	  {
			Application->MessageBox(L"Especifique manualmente una ubicación (y nombre de archivo) donde guardar una DUPLICADO del comprobante.", L"ATENCIÓN",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport1->FileName = SD1->FileName;
			frxReport3->Export(frxPDFExport1);
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
	  QueryAux->ParamByName("fecha")->AsDate = MC1->Date;
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


	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  qy = "SELECT MAX(idComprobanteElectronico) AS ultimo FROM comprobanteselectronicos";
	  QueryAux->SQL->Add(qy);
	  QueryAux->Open();
	  int ultimo = QueryAux->FieldByName("ultimo")->AsInteger;
	  QueryAux->Close();

	  QueryAux->SQL->Clear();
	  qy = "INSERT INTO pedidosFacturados (refPedido, refFactura, fecha) VALUES (:refPedido, :refFactura, :fecha)";
	  QueryAux->SQL->Add(qy);
	  QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
	  QueryAux->ParamByName("refFactura")->AsInteger = ultimo;
	  QueryAux->ParamByName("fecha")->AsDate = MC1->Date;
	  QueryAux->ExecSQL();


	  AnsiString compAso;

	  if(TipoComp == 1)
		 compAso = "FA";
	  else if(TipoComp == 2)
		 compAso = "ND A";
	  else if(TipoComp == 3)
		 compAso = "NC A";
	  else if(TipoComp == 6)
		 compAso = "FB";
	  else if(TipoComp == 7)
		 compAso = "ND B";
	  else if(TipoComp == 8)
		 compAso = "NC B";
	  else
	     compAso = "ERROR";

      compAso = compAso + " " + ptoDeVenta + "-" + nroComp;


      //Esto se ejecuta siempre pero solo afecta si el pedido estaba en cuenta corriente. En otro caso no modifica nada
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("UPDATE cuentascorrientes SET compAsociado = :compAsociado WHERE refPedido = :refPedido LIMIT 1");
	  QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
	  QueryAux->ParamByName("compAsociado")->AsString = compAso;
	  QueryAux->ExecSQL();

   }
   else
   {
	  Application->MessageBox(L"El comprobante no fue autorizado", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }

   CDS4->Active = false;
   Query4->Close();

   CDSFactura->Active = false;
   QueryFactura->Close();

   delete lwsfev1;
}
//---------------------------------------------------------------------------


void __fastcall TfIngresarPedido::Button14Click(TObject *Sender)
{
   if(refEstadoPedido < 2)
   {
	  Application->MessageBox(L"El pedido debe estar confirmado antes de generar una entrada en Cuentas Corrientes.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idCuentaCorriente FROM cuentascorrientes WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();

   if(!QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  Application->MessageBox(L"Ya hay una entrada en Cuentas Corrientes asociada a este pedido",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }

   AnsiString compAso = "-";
   int refFactura = 0;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refFactura FROM pedidosfacturados WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(!QueryAux->IsEmpty())
	  refFactura = QueryAux->FieldByName("refFactura")->AsInteger;

   if(refFactura > 0)
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT (SELECT ELT(refTipoComp, 'FA', 'ND A', 'NC A', '','','FB', 'ND B', 'NC B')) AS tipoComp, (SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp FROM comprobanteselectronicos WHERE idComprobanteElectronico = :idComprobanteElectronico LIMIT 1");
	  QueryAux->ParamByName("idComprobanteElectronico")->AsInteger = refFactura;
	  QueryAux->Open();

	  compAso = QueryAux->FieldByName("tipoComp")->AsString + " " + QueryAux->FieldByName("nroComp")->AsString;
   }


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO cuentascorrientes (fecha, refCliente, refPedido, compAsociado, importe) VALUES ((SELECT fechaConfirmacion FROM pedidos WHERE idPedido = :refPedido LIMIT 1), :refCliente, :refPedido, :compAsociado, :importe)");
   QueryAux->ParamByName("refCliente")->AsInteger = idCliente;
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->ParamByName("compAsociado")->AsString = compAso;
   QueryAux->ParamByName("importe")->AsFloat = final;
   QueryAux->ExecSQL();

   Application->MessageBox(L"La entrada en Cuentas Corrientes fue creada correctamente.",L"Información",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button15Click(TObject *Sender)
{
   if(!CDS1->Active)
      return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT razonSocial AS cliente, domicilio, "

						 "(SELECT (totalCIVA * (1 - (descuentoAplicado / 100.0))) AS final FROM ("
						 "(SELECT SUM(cantidad * precioUnitario) AS totalCIVA FROM articulosPedidos WHERE refPedido = :idPedido) AS totalCIVA, "
						 "(SELECT descuentoAplicado FROM pedidos WHERE idPedido = :idPedido) AS descuentoAplicado)) AS final "

					  "FROM clientes WHERE idCliente = :refCliente LIMIT 1");
   QueryAux->ParamByName("refCliente")->AsInteger = idCliente;
   QueryAux->ParamByName("idPedido")->AsInteger = idPedido;
   QueryAux->Open();
   Edit4->Text = QueryAux->FieldByName("cliente")->AsString;
   Edit5->Text = QueryAux->FieldByName("domicilio")->AsString;
   Edit6->Text = FormatFloat("$ 0.00", QueryAux->FieldByName("final")->AsFloat);
   QueryAux->Close();
   Edit3->Text = "1";
   CB->ItemIndex = -1;
   Edit6->Visible = false;
   Panel5->Visible = true;
   Edit3->SetFocus();
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button16Click(TObject *Sender)
{
   if(CB->ItemIndex < 0)
	  return;

   String imp_actual;

   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   imp_actual = Configuraciones->ReadString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");

   int imp_index;

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
		  Configuraciones->WriteString("Impresion","ImpresoraEtiquetas","NO CONFIGURADA");
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

   frxReport4->PrintOptions->Printer = imp_actual;

   String no = IntToStr(idPedido);
   while(no.Length() < 6)
	  no = no.Insert("0",1);


   int c = StrToInt(Edit3->Text);
   for(int i = 1; i <= c; i++)
   {
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo1"))->Text = Edit4->Text;
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo2"))->Text = Edit5->Text;
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo4"))->Text = no;

	   if(CB->ItemIndex == 0)
		  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo3"))->Text = "PAGADO";
	   else if(CB->ItemIndex == 1)
		  dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo3"))->Text = "CUENTA CORRIENTE";
	   if(CB->ItemIndex == 2)
	   {
		  if(Edit6->Text.Pos("$ ") > 0)
			 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo3"))->Text = Edit6->Text.Delete(1,2);
		  else
			 dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo3"))->Text = Edit6->Text;
	   }
	   dynamic_cast <TfrxMemoView *> (fIngresarPedido->frxReport4->FindObject("Memo5"))->Text = "Bulto " + IntToStr(i) + " de " + IntToStr(c);

	   frxReport4->PrepareReport(true);
	   frxReport4->Print();
//       frxReport1->ShowReport();

   }

   Panel5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button17Click(TObject *Sender)
{
   Panel5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CBChange(TObject *Sender)
{
   if(CB->ItemIndex == 2)
	  Edit6->Visible = true;
   else
      Edit6->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TfIngresarPedido::MC1Change(TObject *Sender)
{
   if(MC1->Date < UltimaFactura)
	  Application->MessageBox(L"Según los registros del sistema se realizaron facturas posteriores a esta fecha.\nEs posible que la misma sea rechazada por AFIP.",L"ATENCIÓN",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);

   if(MC1->Date > Now())
   {
	  Application->MessageBox(L"La fecha informada no puede ser posterior a la fecha actual.",L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  MC1->Date = Now();
   }
}
//---------------------------------------------------------------------------


void __fastcall TfIngresarPedido::Button18Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idPedidoFacturado, refFactura FROM pedidosFacturados WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   if(QueryAux->IsEmpty())
   {
	  Application->MessageBox(L"Este pedido aún no fue facturado. Debe generar la factura antes de poder enviarla.",L"ERROR",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
      QueryAux->Close();
	  return;
   }


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT email FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   QueryAux->ParamByName("idCliente")->AsInteger = idCliente;
   QueryAux->Open();


   CheckBox3->Checked = false;
   Edit7->Text = QueryAux->FieldByName("email")->AsString;
   Edit7->Enabled = false;
   QueryAux->Close();
   Panel6->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button19Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idPedidoFacturado, refFactura FROM pedidosFacturados WHERE refPedido = :refPedido LIMIT 1");
   QueryAux->ParamByName("refPedido")->AsInteger = idPedido;
   QueryAux->Open();
   int refFactura = QueryAux->FieldByName("refFactura")->AsInteger;
   QueryAux->Close();

   if(Application->MessageBox(L"Se va a enviar esta factura por email. Desea continuar?" ,L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  return;
   }


   QueryAux->SQL->Clear();
   String q;
	  q = "SELECT idComprobanteElectronico, "
	   "(SELECT ELT(refTipoComp, 'FACTURA A', 'Nota de Débito A', 'Nota de Crédito A', '','','FACTURA B', 'Nota de Débito B', 'Nota de Crédito B')) AS tipoComp, "
	   "(SELECT CONCAT(LPAD(ptoVenta,5,'0'),'-',LPAD(nroComprobante,8,'0'))) AS nroComp "
	   "FROM comprobantesElectronicos WHERE idComprobanteElectronico = :idComprobanteElectronico LIMIT 1";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idComprobanteElectronico")->AsInteger = refFactura;
   QueryAux->Open();
   String tipoComp = QueryAux->FieldByName("tipoComp")->AsString;
   String nroComp = QueryAux->FieldByName("nroComp")->AsString;
   QueryAux->Close();


   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   String DirFacturas = Configuraciones->ReadString("Directorios","Facturas","NO_CONFIGURADA");


   if(DirFacturas == "NO_CONFIGURADA")
   {
	   delete Configuraciones;
	   Application->MessageBox(L"Antes de continuar debe configurar un directorio para guardar las copias de respaldo" ,L"Configurar directorio.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	   return;
   }
   delete Configuraciones;

   String nombreFactura = DirFacturas + "\\" + tipoComp + nroComp + ".pdf";;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT razonSocial FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   QueryAux->ParamByName("idCliente")->AsInteger = idCliente;
   QueryAux->Open();

   String email = Edit7->Text;

   String usuario = email.SubString(1, email.Pos("@") - 1);
   String dominio = email.Delete(1, email.Pos("@"));
   String nombre = QueryAux->FieldByName("razonSocial")->AsString;

   IdMessage1->BccList->Items[0]->Address = usuario + "@" + dominio;
   IdMessage1->BccList->Items[0]->Domain = dominio;
   IdMessage1->BccList->Items[0]->Name = nombre;
   IdMessage1->BccList->Items[0]->Text = nombre + " <" + usuario + "@" + dominio + ">";
   IdMessage1->BccList->Items[0]->User = usuario;

   String nroPedido = IntToStr(idPedido);
   while(nroPedido.Length() < 5)
	  nroPedido = "0" + nroPedido;

   IdMessage1->Subject = "Factura OC #" + nroPedido;

   IdSMTP1->ConnectTimeout = 10000;
   IdSMTP1->Connect();
   IdMessage1->Body->LoadFromFile("plantillaMail.txt");

//   TIdMessageBuilderPlain *MyMessage;
//   MyMessage = new TIdMessageBuilderPlain();
//
//   MyMessage->Attachments->Add("D:\\Factura.pdf");
//   MyMessage->PlainText = Memo2->Lines;
//   MyMessage->FillMessage(IdMessage1);

   TIdMessageBuilderHtml *MyMessage;
   MyMessage = new TIdMessageBuilderHtml();

   MyMessage->Attachments->Add(nombreFactura);
   MyMessage->Html->LoadFromFile("plantillaMail.txt");
   MyMessage->FillMessage(IdMessage1);

   IdSMTP1->Send(IdMessage1);
   if(IdSMTP1->Connected())
	  IdSMTP1->Disconnect();


   delete MyMessage;

   Application->MessageBox(L"Email enviado.",L"Información",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
   Panel6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox3Click(TObject *Sender)
{
   if(CheckBox3->Checked)
	  Edit7->Enabled = true;
   else
      Edit7->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::Button20Click(TObject *Sender)
{
   Panel6->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox4Click(TObject *Sender)
{
   calcularGanancia();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox5Click(TObject *Sender)
{
   calcularGanancia();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox6Click(TObject *Sender)
{
   calcularGanancia();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox7Click(TObject *Sender)
{
   calcularGanancia();
}
//---------------------------------------------------------------------------

void __fastcall TfIngresarPedido::CheckBox8Click(TObject *Sender)
{
   calcularGanancia();
}
//---------------------------------------------------------------------------

