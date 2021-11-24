//---------------------------------------------------------------------------

#ifndef uControlDePreciosH
#define uControlDePreciosH
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
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfControlDePrecios : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TSQLQuery *Query1;
	TSQLConnection *SQLConnection1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TSQLQuery *QueryAux;
	TSQLQuery *QueryUpdate;
	TWideStringField *CDSnombre;
	TIntegerField *CDSidArticulo;
	TWideStringField *CDSnombreProv;
	TWideStringField *CDScodigoProv;
	TLargeintField *CDSrefProveedor;
	TFMTBCDField *CDSescala;
	TPanel *Panel1;
	TButton *Button1;
	TOpenDialog *OD1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TSQLQuery *Query2;
	TDataSetProvider *DataSetProvider2;
	TClientDataSet *CDS2;
	TWideStringField *WideStringField1;
	TIntegerField *IntegerField1;
	TWideStringField *WideStringField2;
	TWideStringField *WideStringField3;
	TFMTBCDField *FMTBCDField1;
	TDataSource *DataSource2;
	TFMTBCDField *CDS2precioActual;
	TFMTBCDField *CDS2precioProv;
	TDBGrid *DBGrid2;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TCheckBox *ChB;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TLargeintField *CDS2refProveedor;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLabel *Label4;
	TLabel *Label5;
	TPanel *Panel6;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TButton *Button14;
	TButton *Button15;
	TEdit *Edit9;
	TEdit *Edit10;
	TComboBox *ComboBox3;
	TPopupMenu *PopupMenu1;
	TMenuItem *AsociarCambiarproveedor1;
	TFMTBCDField *CDSprecioCompra;
	TCheckBox *CheckBox1;
	TIntegerField *CDSstock;
	TCheckBox *CheckBox2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CDScodigoProvChange(TField *Sender);
	void __fastcall CDSescalaChange(TField *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3Enter(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall DBGrid2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall ComboBox1Click(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall AsociarCambiarproveedor1Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Edit10Exit(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall DBGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall CDSprecioCompraChange(TField *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CDSstockChange(TField *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfControlDePrecios(TComponent* Owner);

    void mostrar(void);

	int idx_Precio;
	int errores;
	bool modificandoProveedor;
};
//---------------------------------------------------------------------------
extern PACKAGE TfControlDePrecios *fControlDePrecios;
//---------------------------------------------------------------------------
#endif
