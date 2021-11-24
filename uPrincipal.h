//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include "frxClass.hpp"
#include "frxExportMail.hpp"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ExtActns.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Clientes1;
	TMenuItem *Proveedores1;
	TMenuItem *Articulos1;
	TMenuItem *Agregaruncliente1;
	TMenuItem *Modificaruncliente1;
	TMenuItem *Agregarunproveedor1;
	TMenuItem *Modificarunproveedor1;
	TMenuItem *Agregarunartculo1;
	TMenuItem *Modificarunartculo1;
	TMenuItem *Agregarunartculodebreak1;
	TMenuItem *AgregarunartculodeHigieneyLimpieza1;
	TMenuItem *Modificardatosdeunartculo1;
	TMenuItem *Modificarpreciosstocketc1;
	TMenuItem *Pedidos1;
	TMenuItem *Verpedidos1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TIntegerField *CDSidArticulo;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TWideStringField *CDSnombreCompleto;
	TPanel *Panel1;
	TLabel *Label1;
	TButton *Button14;
	TSQLQuery *QueryAux;
	TMenuItem *Exportarlistado1;
	TSaveDialog *SD1;
	TMenuItem *Actualizarpreciosymrgenes1;
	TImage *Image1;
	TDateField *CDSproximoVencimiento;
	TOpenDialog *OD1;
	TMenuItem *Actualizar1;
	TMenuItem *Actualizarprecios1;
	TButton *Button17;
	TMenuItem *Acercade1;
	TMenuItem *Configurar1;
	TMenuItem *Estadodecuentas1;
	TMenuItem *Consultarstockyfechadevencimiento1;
	TMenuItem *Eliminaruncliente1;
	TMenuItem *Eliminarunproveedor1;
	TMenuItem *Vercomprobantesemitidos1;
	TMenuItem *Controldeprecios1;
	TButton *Button16;
	TPanel *Panel2;
	TMemo *Memo2;
	TButton *Button15;
	void __fastcall Agregaruncliente1Click(TObject *Sender);
	void __fastcall Modificaruncliente1Click(TObject *Sender);
	void __fastcall Agregarunproveedor1Click(TObject *Sender);
	void __fastcall Modificarunproveedor1Click(TObject *Sender);
	void __fastcall Agregarunartculo1Click(TObject *Sender);
	void __fastcall Modificarunartculo1Click(TObject *Sender);
	void __fastcall Agregarunartculodebreak1Click(TObject *Sender);
	void __fastcall AgregarunartculodeHigieneyLimpieza1Click(TObject *Sender);
	void __fastcall Modificardatosdeunartculo1Click(TObject *Sender);
	void __fastcall Modificarpreciosstocketc1Click(TObject *Sender);
	void __fastcall Verpedidos1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Exportarlistado1Click(TObject *Sender);
	void __fastcall Actualizarpreciosymrgenes1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Actualizarprecios1Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Configurar1Click(TObject *Sender);
	void __fastcall Estadodecuentas1Click(TObject *Sender);
	void __fastcall Consultarstockyfechadevencimiento1Click(TObject *Sender);
	void __fastcall Eliminaruncliente1Click(TObject *Sender);
	void __fastcall Eliminarunproveedor1Click(TObject *Sender);
	void __fastcall Vercomprobantesemitidos1Click(TObject *Sender);
	void __fastcall Controldeprecios1Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	void modificarPrecio(String SKU, String nuevoPrecio);
	TStringList *Contenedor;
	TStringList *archivo;
	int idx_Precio;
	int errores;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
