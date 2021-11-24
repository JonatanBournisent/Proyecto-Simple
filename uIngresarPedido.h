//---------------------------------------------------------------------------

#ifndef uIngresarPedidoH
#define uIngresarPedidoH
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
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Vcl.Mask.hpp>
#include <Vcl.Dialogs.hpp>
#include "frxExportPDF.hpp"
#include "frxBarcode.hpp"
#include "frxBarcode2D.hpp"
#include <Vcl.ComCtrls.hpp>
#include "frxExportBaseDialog.hpp"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdMessage.hpp>
#include <IdMessageClient.hpp>
#include <IdSMTP.hpp>
#include <IdSMTPBase.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TfIngresarPedido : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TDataSource *DataSource1;
	TSQLQuery *Query1;
	TSQLQuery *QueryAux;
	TIntegerField *CDS1refArticulo;
	TIntegerField *CDS1cantidad;
	TFMTBCDField *CDS1precioUnitario;
	TFMTBCDField *CDS1subtotal;
	TWideStringField *CDS1descripcion;
	TIntegerField *CDS1idArticuloPedido;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TSQLQuery *Query3;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *ClientDataSet3;
	TDataSource *DataSource3;
	TWideStringField *ClientDataSet3nombreCompleto;
	TIntegerField *ClientDataSet3idArticulo;
	TButton *Button3;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDataset1;
	TSQLQuery *Query4;
	TDataSetProvider *DataSetProvider4;
	TClientDataSet *CDS4;
	TDataSource *DataSource4;
	TfrxDBDataset *frxDBDataset2;
	TButton *Button4;
	TWideStringField *CDS4nombre;
	TWideStringField *CDS4razonSocial;
	TWideStringField *CDS4domicilio;
	TWideStringField *CDS4cuit;
	TWideStringField *CDS4condfiva;
	TWideStringField *CDS4apellido;
	TFMTBCDField *CDS1iva;
	TPanel *Panel2;
	TEdit *Edit1;
	TDBGrid *DBGrid3;
	TEdit *edCantidad;
	TEdit *edPCIVA;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *edPSIVA;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TEdit *edSCIVA;
	TEdit *edSSIVA;
	TButton *Button5;
	TLabel *Label19;
	TEdit *edCodigo;
	TButton *Button6;
	TFMTBCDField *ClientDataSet3iva;
	TLabel *Label20;
	TEdit *edIVA;
	TLabel *Label21;
	TFMTBCDField *ClientDataSet3precioVenta;
	TLabel *Label22;
	TPopupMenu *PopupMenu1;
	TMenuItem *ModificarItem1;
	TMenuItem *AgregarItem1;
	TMenuItem *EliminarItem1;
	TLabel *Label23;
	TButton *Button7;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *Button8;
	TShape *Shape1;
	TButton *Button9;
	TShape *Shape2;
	TPanel *Panel3;
	TEdit *Edit2;
	TButton *Button1;
	TLabel *Label13;
	TPanel *Panel4;
	TClientDataSet *CDS2;
	TDataSource *DataSource2;
	TSQLQuery *Query2;
	TDataSetProvider *DataSetProvider2;
	TDBGrid *DBGrid2;
	TLabel *Label24;
	TButton *Button2;
	TIntegerField *CDS2refArticulo;
	TIntegerField *CDS2cantidad;
	TWideStringField *CDS2nombre;
	TLargeintField *CDS2stock;
	TButton *Button10;
	TLabel *lblStock;
	TIntegerField *ClientDataSet3stock;
	TDateField *CDS4fechaPedido;
	TfrxReport *frxReport2;
	TButton *Button11;
	TButton *Button12;
	TfrxReport *frxReport3;
	TButton *Button13;
	TCheckBox *CheckBox1;
	TLabel *Label25;
	TSaveDialog *SD1;
	TfrxPDFExport *frxPDFExport1;
	TfrxBarCodeObject *frxBarCodeObject1;
	TSQLQuery *QueryFactura;
	TDataSetProvider *DataSetProvider5;
	TClientDataSet *CDSFactura;
	TIntegerField *IntegerField1;
	TIntegerField *IntegerField2;
	TWideStringField *WideStringField1;
	TFMTBCDField *FMTBCDField1;
	TFMTBCDField *FMTBCDField2;
	TIntegerField *IntegerField3;
	TFMTBCDField *FMTBCDField3;
	TDataSource *DataSource5;
	TfrxDBDataset *frxDBDataset3;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TFMTBCDField *ClientDataSet3descuentoPromo;
	TLargeintField *ClientDataSet3cantidadPromo;
	TButton *Button14;
	TButton *Button15;
	TPanel *Panel5;
	TShape *Shape3;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label36;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TComboBox *CB;
	TButton *Button16;
	TButton *Button17;
	TEdit *Edit6;
	TfrxReport *frxReport4;
	TDateTimePicker *MC1;
	TShape *Shape4;
	TLabel *Label37;
	TCheckBox *CheckBox2;
	TShape *Shape5;
	TfrxPDFExport *frxPDFExport2;
	TButton *Button18;
	TIdSMTP *IdSMTP1;
	TIdMessage *IdMessage1;
	TPanel *Panel6;
	TButton *Button19;
	TButton *Button20;
	TEdit *Edit7;
	TCheckBox *CheckBox3;
	TLabel *Label38;
	TPanel *Panel7;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid3DblClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall edCodigoExit(TObject *Sender);
	void __fastcall edCantidadExit(TObject *Sender);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall edCantidadChange(TObject *Sender);
	void __fastcall edCantidadKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edPCIVAChange(TObject *Sender);
	void __fastcall edPCIVAEnter(TObject *Sender);
	void __fastcall edPCIVAExit(TObject *Sender);
	void __fastcall edPCIVAKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall edCodigoKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ModificarItem1Click(TObject *Sender);
	void __fastcall EliminarItem1Click(TObject *Sender);
	void __fastcall AgregarItem1Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall CDS4fechaPedidoGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall CBChange(TObject *Sender);
	void __fastcall MC1Change(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall CheckBox6Click(TObject *Sender);
	void __fastcall CheckBox7Click(TObject *Sender);
	void __fastcall CheckBox8Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfIngresarPedido(TComponent* Owner);



	int llamador; // 1 - LLamo desde uPedidos
	int idCliente;
	int idPedido;
	int idArticulo, cantidad, cantidadPromo, descuentoPromo;
	bool aplicaPromo;
	float precio, iva;
	int stock;
	bool blockEdit1;
	void actualizarPresupuesto(int id, int estadoPedido, String ordAsoc);
	void calcularGanancia(void);
	bool agregado;
	bool modificandoItem;
	int idItemModificado;
	int refEstadoPedido;
	String ordenAsociada;
	float maximoFactSD;
	bool modificarOrdenAsociada;
	float artONCE;
	float totalCompraSIVA, IVAcompra;

	float totalCIVA, totalSIVA, descuentoAplicado, IVAventa21CDTO, IVAventa105CDTO, final, IVAcompraONCE;
	float factorDto;
	float baseImp21, baseImp105;
	TDate UltimaFactura;
};
//---------------------------------------------------------------------------
extern PACKAGE TfIngresarPedido *fIngresarPedido;
//---------------------------------------------------------------------------
#endif
