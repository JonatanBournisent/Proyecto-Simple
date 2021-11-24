//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("uPedidos.cpp", fPedidos);
USEFORM("uPrincipal.cpp", Form1);
USEFORM("uIngresarPedido.cpp", fIngresarPedido);
USEFORM("uControlDePrecios.cpp", fControlDePrecios);
USEFORM("uCuentas.cpp", fCuentas);
USEFORM("uVerProveedores.cpp", fVerProveedores);
USEFORM("uVerComprobantesElectronicos.cpp", fVerComprobantesElectronicos);
USEFORM("uSeleccionarArticulo.cpp", fSeleccionarArticulo);
USEFORM("uSorteo.cpp", fSorteo);
USEFORM("uConfiguraciones.cpp", fConfiguraciones);
USEFORM("uActualizarPrecios.cpp", fActualizarPrecios);
USEFORM("uAgregarArticulo.cpp", fAgregarArticulo);
USEFORM("StockYFV.cpp", fStockYFV);
USEFORM("uBuscarCliente.cpp", fBuscarCliente);
USEFORM("uBuscarProveedor.cpp", fBuscarProveedor);
USEFORM("uBuscarArticulo.cpp", fBuscarArticulo);
USEFORM("uAgregarCliente.cpp", fAgregarCliente);
USEFORM("uAgregarProveedor.cpp", fAgregarProveedor);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TfAgregarArticulo), &fAgregarArticulo);
		Application->CreateForm(__classid(TfBuscarArticulo), &fBuscarArticulo);
		Application->CreateForm(__classid(TfActualizarPrecios), &fActualizarPrecios);
		Application->CreateForm(__classid(TfAgregarCliente), &fAgregarCliente);
		Application->CreateForm(__classid(TfBuscarCliente), &fBuscarCliente);
		Application->CreateForm(__classid(TfAgregarProveedor), &fAgregarProveedor);
		Application->CreateForm(__classid(TfBuscarProveedor), &fBuscarProveedor);
		Application->CreateForm(__classid(TfIngresarPedido), &fIngresarPedido);
		Application->CreateForm(__classid(TfVerProveedores), &fVerProveedores);
		Application->CreateForm(__classid(TfSeleccionarArticulo), &fSeleccionarArticulo);
		Application->CreateForm(__classid(TfPedidos), &fPedidos);
		Application->CreateForm(__classid(TfCuentas), &fCuentas);
		Application->CreateForm(__classid(TfConfiguraciones), &fConfiguraciones);
		Application->CreateForm(__classid(TfStockYFV), &fStockYFV);
		Application->CreateForm(__classid(TfVerComprobantesElectronicos), &fVerComprobantesElectronicos);
		Application->CreateForm(__classid(TfControlDePrecios), &fControlDePrecios);
		Application->CreateForm(__classid(TfSorteo), &fSorteo);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
