//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "StockYFV.h"
#include "uPrincipal.h"
#include "uPedidos.h"
#include "uBuscarCliente.h"
#include "uBuscarProveedor.h"
#include "uCuentas.h"
#include "uConfiguraciones.h"
#include "uSeleccionarArticulo.h"
#include "uAgregarArticulo.h"
#include "uActualizarPrecios.h"
#include "uAgregarCliente.h"
#include "uAgregarProveedor.h"
#include "uIngresarPedido.h"
#include "uBuscarArticulo.h"
#include "uVerComprobantesElectronicos.h"
#include "uControlDePrecios.h"
#include "uSorteo.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxExportMail"
#pragma resource "*.dfm"
TForm1 *Form1;

String servidor;      //variable externa declarada en VariablesGlobales.h
String dbName;      //variable externa declarada en VariablesGlobales.h
String userName;      //variable externa declarada en VariablesGlobales.h
String pass;      //variable externa declarada en VariablesGlobales.h

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm1::modificarPrecio(String SKU, String nuevoPrecio)
{
   int idx;
   idx = Contenedor->IndexOf(SKU) + 1;
   if(idx == 0)
   {
      Memo2->Lines->Add(SKU);
	  errores++;
	  return;
   }
   String original = archivo->Strings[idx];
   String parcial = "";
   String aux = original;

   for(int c = 0; c < idx_Precio; c++)
   {
	  parcial = parcial + aux.SubString(1, aux.Pos(";"));
      aux = aux.Delete(1, aux.Pos(";"));
   }
   aux = aux.Delete(1, aux.Pos(";"));
   parcial = parcial + nuevoPrecio + ";" + aux;
   archivo->Strings[idx] = parcial;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Agregaruncliente1Click(TObject *Sender)
{
   fAgregarCliente->paraModificar = false;
   fAgregarCliente->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Modificaruncliente1Click(TObject *Sender)
{
   fAgregarCliente->paraModificar = true;
   fAgregarCliente->ShowModal();
   fAgregarCliente->paraModificar = false;     //por las dudas
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Agregarunproveedor1Click(TObject *Sender)
{
   fAgregarProveedor->paraModificar = false;
   fAgregarProveedor->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Modificarunproveedor1Click(TObject *Sender)
{
   fAgregarProveedor->paraModificar = true;
   fAgregarProveedor->ShowModal();
   fAgregarProveedor->paraModificar = false;     //por las dudas
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Agregarunartculo1Click(TObject *Sender)
{
   fAgregarArticulo->refRubro = 1;
   fAgregarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Modificarunartculo1Click(TObject *Sender)
{
   fAgregarArticulo->refRubro = 2;
   fAgregarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Agregarunartculodebreak1Click(TObject *Sender)
{
   fAgregarArticulo->refRubro = 3;
   fAgregarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AgregarunartculodeHigieneyLimpieza1Click(TObject *Sender)

{
   fAgregarArticulo->refRubro = 4;
   fAgregarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Modificardatosdeunartculo1Click(TObject *Sender)
{
   fAgregarArticulo->paraModificar = true;
   fAgregarArticulo->ShowModal();
   fAgregarArticulo->paraModificar = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Modificarpreciosstocketc1Click(TObject *Sender)
{
   fBuscarArticulo->soloBusqueda = false;
   fBuscarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Verpedidos1Click(TObject *Sender)
{
   fPedidos->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
//   Panel2->Visible = false;
//   Button15->Visible = false;
   String q;
   q = "SELECT idArticulo, REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto, proximoVencimiento "
   	   "FROM articulos WHERE proximoVencimiento <= :fRef ORDER BY proximoVencimiento";

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   Query1->ParamByName("fRef")->AsDateTime = IncDay(Now(), 30);
   Query1->Open();
   CDS->Active = true;

   Panel2->Visible = false;

   if(CDS->RecordCount > 0)
	  Panel1->Visible = true;
   else
   {
	  Panel1->Visible = false;
	  CDS->Active = false;
	  Query1->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
   Panel1->Visible = false;
   CDS->Active = false;
   Query1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TForm1::Exportarlistado1Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT LPAD(idArticulo,5,'0') AS idArticulo, "
					  "(SELECT descripcion FROM rubros WHERE idRubro = refRubro LIMIT 1) AS rubro, "
					  "(SELECT descripcion FROM subrubros WHERE idSubRubro = refSubRubro LIMIT 1) AS subRubro, "
					  "categoria, tipo, marca, modelo, tamano, color, diseno, cantidad, unidadMedida, descripcion, "
					  "codigo, precioCompra, margenUtilidad, stock, stockCritico, "
					  "precioVenta, iva, proximoVencimiento, "
					  "REPLACE(REPLACE(REPLACE(REPLACE(REPLACE(nombreCompleto, '      ', ' '), '     ',' '), '    ', ' '), '   ', ' '), '  ', ' ') AS nombreCompleto FROM articulos ORDER BY idArticulo");
   QueryAux->Open();

   TStringList *lista;
   lista = new TStringList();
   lista->Clear();

   QueryAux->First();
   lista->Add("CÓDIGO INTERNO;RUBRO;SUBRUBRO;CATEGORÍA;TIPO;MARCA;MODELO;TAMAÑO;COLOR;DISEÑO;CANTIDAD;UNIDAD DE MEDIDIA;CÓDIGO DE BARRA;PRECIO DE COMPRA;MARGEN DE UTILIDAD;STOCK;STOCK CRÍTICO;PRECIO DE VENTA;IVA;FECHA DE VENCIMIENTO;NOMBRE COMPLETO");

   while(!QueryAux->Eof)
   {
	  lista->Add(QueryAux->FieldByName("idArticulo")->AsString + ";" +
						QueryAux->FieldByName("rubro")->AsString + ";" +
						QueryAux->FieldByName("subrubro")->AsString + ";" +
						QueryAux->FieldByName("categoria")->AsString + ";" +
						QueryAux->FieldByName("tipo")->AsString + ";" +
						QueryAux->FieldByName("marca")->AsString + ";" +
						QueryAux->FieldByName("modelo")->AsString + ";" +
						QueryAux->FieldByName("tamano")->AsString + ";" +
						QueryAux->FieldByName("color")->AsString + ";" +
						QueryAux->FieldByName("diseno")->AsString + ";" +
						QueryAux->FieldByName("cantidad")->AsString + ";" +
						QueryAux->FieldByName("unidadMedida")->AsString + ";" +
						//QueryAux->FieldByName("descripcion")->AsString + ";" +
						QueryAux->FieldByName("codigo")->AsString + ";" +
						QueryAux->FieldByName("precioCompra")->AsString + ";" +
						QueryAux->FieldByName("margenUtilidad")->AsString + ";" +
						QueryAux->FieldByName("stock")->AsString + ";" +
						QueryAux->FieldByName("stockCritico")->AsString + ";" +
						QueryAux->FieldByName("precioVenta")->AsString + ";" +
						QueryAux->FieldByName("iva")->AsString + ";" +
						QueryAux->FieldByName("proximoVencimiento")->AsString + ";" +
						QueryAux->FieldByName("nombreCompleto")->AsString
	  				   );
	  QueryAux->Next();
   }
   QueryAux->Close();

   if(SD1->Execute())
   {
	  lista->SaveToFile(SD1->FileName);
	  Application->MessageBox(L"Los artículos fueron exportados en la ubicación indicada",L"Artículos exportados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
   }
   else
	  ShowMessage("ERROR: No se pudo exportar");

   delete lista;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Actualizarpreciosymrgenes1Click(TObject *Sender)
{
   fSeleccionarArticulo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Panel1->Left = 1;
   Panel1->Top = 1;
   Form1->Width = Panel1->Width + 2;
   Form1->Height = Panel1->Height + 50;
   Panel2->Left = (Form1->Width - Panel2->Width) / 2;
   Panel2->Top = (Form1->Height - Panel2->Height) / 2;
   Image1->Left = (Form1->Width - Image1->Width) / 2;
   Image1->Top = ((Form1->Height - Image1->Height) / 2) - 20;

   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   servidor = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   dbName = "dbsimple";
   userName = "soysimple";
   pass = "sscj1004";


   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
   delete Configuraciones;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Actualizarprecios1Click(TObject *Sender)
{
   Contenedor = new TStringList();
   archivo = new TStringList();

   Memo2->Clear();
   Memo2->Lines->Add("SKU no encontrados:");
   Memo2->Lines->Add("");

   String linea, palabra;
   int idx_SKU;
   bool encontrado = false;
   errores = 0;

   archivo->Clear();
   Application->MessageBox(L"Indique la ubicación de la lista de artículoas a actualizar",L"Seleccionar origen de datos",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   if(OD1->Execute())
   {
	  archivo->LoadFromFile(OD1->FileName);
   }
   else
   {
	  ShowMessage("ERROR: No se pudo importar");
	  return;
   }

   linea = archivo->Strings[0];
   linea = linea + ";";
   idx_SKU = 1;
   while(linea.Pos(";") > 0)
   {
	  palabra = linea.SubString(1, linea.Pos(";") - 1);
	  if(palabra == "SKU")
	  {
		 encontrado = true;
		 break;
	  }
	  linea = linea.Delete(1, linea.Pos(";"));
	  idx_SKU++;
   }
   if(!encontrado)
   {
	  ShowMessage("No pude localizar el campo SKU");
	  return;
   }

   linea = archivo->Strings[0];
   linea = linea + ";";
   idx_Precio = 1;
   while(linea.Pos(";") > 0)
   {
	  palabra = linea.SubString(1, linea.Pos(";") - 1);
	  if(palabra == "Precio")
	  {
		 encontrado = true;
		 break;
	  }
	  linea = linea.Delete(1, linea.Pos(";"));
	  idx_Precio++;
   }
   if(!encontrado)
   {
	  ShowMessage("No pude localizar el campo Precio");
	  return;
   }

   idx_SKU = idx_SKU - 1;
   idx_Precio = idx_Precio - 1;

   Contenedor->Clear();

   for(int j = 1; j < archivo->Count; j++)
   {
	  linea = archivo->Strings[j] + ";";
	  for(int c = 0; c < idx_SKU; c++)
	  {
		 linea = linea.Delete(1, linea.Pos(";"));
	  }
	  palabra = linea.SubString(1, linea.Pos(";") - 1);
	  Contenedor->Add(palabra);
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idArticulo, (precioVenta * (1 + (iva / 100.0))) AS pv FROM articulos");
   QueryAux->Open();
   String precio;
   int p;
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  precio = FormatFloat("0", QueryAux->FieldByName("pv")->AsFloat);
	  while(precio.Pos("."))
	     precio = precio.Delete(precio.Pos("."), 1);
	  p = precio.Pos(",");
	  if(p > 0)
	  {
		 precio = precio.Insert(".", p);
		 precio = precio.Delete(p + 1, 1);
      }
	  modificarPrecio(QueryAux->FieldByName("idArticulo")->AsString, precio);
	  QueryAux->Next();
   }
   QueryAux->Close();

   if(errores > 0)
   {
	  String msg = "El SKU de " + IntToStr(errores) + " artículos no pudo ser localizado. Verifique los errores.";
	  ShowMessage(msg);
      Panel2->Visible = true;
   }

   Application->MessageBox(L"A continuación indique un nombre y ubicación para la lista actualizada",L"Seleccionar destino",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   if(SD1->Execute())
   {
	  archivo->SaveToFile(SD1->FileName);
	  Application->MessageBox(L"Los precios fueron actualizados correctamente.",L"Precios actualizados",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
   }
   else
	  ShowMessage("ERROR: No se pudo exportar");

   delete Contenedor;
   delete archivo;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
//   QueryAux->Close();
//   QueryAux->SQL->Clear();
//   QueryAux->SQL->Add("UPDATE articulos SET margenUtilidad = 80 WHERE precioCompra < 10");
//   QueryAux->ExecSQL();
//
//   QueryAux->Close();
//   QueryAux->SQL->Clear();
//   QueryAux->SQL->Add("UPDATE articulos SET margenUtilidad = (((1.0 / LN(precioCompra)) * 185.0) - (precioCompra / 20.0)) WHERE precioCompra >= 10 AND precioCompra <= 100");
//   QueryAux->ExecSQL();
//
//   QueryAux->Close();
//   QueryAux->SQL->Clear();
//   QueryAux->SQL->Add("UPDATE articulos SET margenUtilidad = 35 WHERE precioCompra > 100");
//   QueryAux->ExecSQL();
//
//   QueryAux->Close();
//   QueryAux->SQL->Clear();
//   QueryAux->SQL->Add("UPDATE articulos SET margenUtilidad = 35 WHERE refRubro = 3 OR refRubro = 4");
//   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Configurar1Click(TObject *Sender)
{
   fConfiguraciones->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Estadodecuentas1Click(TObject *Sender)
{
   fCuentas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Consultarstockyfechadevencimiento1Click(TObject *Sender)
{
   fStockYFV->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Eliminaruncliente1Click(TObject *Sender)
{
   fBuscarCliente->ShowModal();
   int clienteEliminar;
   if(fBuscarCliente->idSeleccionado > 0)
   {
	  clienteEliminar = fBuscarCliente->idSeleccionado;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT idComprobanteElectronico FROM comprobanteselectronicos WHERE refCliente = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->Open();

	  if(!QueryAux->IsEmpty())
	  {
		 QueryAux->Close();
		 Application->MessageBox(L"Se emitieron facturas a nombre de este cliente. Deberá eliminarlas manualmente antes de continuar.",L"¡ATENCIÓN!",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
         return;
	  }
	  QueryAux->Close();

	  if(Application->MessageBox(L"Realmente desea eliminar este cliente? Se eliminarán también todos los pedidos, remitos y cuentas corrientes asociados a este cliente.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
		 return;

      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM remitos WHERE refPedido IN (SELECT idPedido FROM pedidos WHERE refCliente = :id)");
      QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM articulosPedidos WHERE refPedido IN (SELECT idPedido FROM pedidos WHERE refCliente = :id)");
	  QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM pedidosFacturados WHERE refPedido IN (SELECT idPedido FROM pedidos WHERE refCliente = :id)");
	  QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM pedidos WHERE refCliente = :id");
	  QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM clientes WHERE idCliente = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = clienteEliminar;
	  QueryAux->ExecSQL();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Eliminarunproveedor1Click(TObject *Sender)
{
   fBuscarProveedor->ShowModal();
   int proveedorEliminar;
   if(fBuscarProveedor->idSeleccionado > 0)
   {
	  proveedorEliminar = fBuscarProveedor->idSeleccionado;

	  if(Application->MessageBox(L"Realmente desea eliminar este proveedor? Si las hubiera, se eliminarán también todas las relaciones a los productos ofrecidos por el mismo.",L"ATENCIÓN!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
		 return;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM relacionproveedores WHERE refProveedor = :id");
	  QueryAux->ParamByName("id")->AsInteger = proveedorEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM relacioncodigosproveedores WHERE refProveedor = :id");
	  QueryAux->ParamByName("id")->AsInteger = proveedorEliminar;
	  QueryAux->ExecSQL();

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM proveedores WHERE idProveedor = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = proveedorEliminar;
	  QueryAux->ExecSQL();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Vercomprobantesemitidos1Click(TObject *Sender)
{
   fVerComprobantesElectronicos->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Controldeprecios1Click(TObject *Sender)
{
   fControlDePrecios->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender)
{
   Panel2->Visible = false;
//   Button15->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
   fSorteo->Show();
}
//---------------------------------------------------------------------------


