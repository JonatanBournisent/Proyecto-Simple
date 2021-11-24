//---------------------------------------------------------------------------

#ifndef uCuentasH
#define uCuentasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
//---------------------------------------------------------------------------
class TfCuentas : public TForm
{
__published:	// IDE-managed Components
	TMonthCalendar *MC;
	TSQLQuery *Query1;
	TSQLConnection *SQLConnection1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TButton *Button1;
	TSQLQuery *QueryAux;
	TSQLQuery *QueryUpdate;
	TPopupMenu *PopupMenu1;
	TMenuItem *Ingresaruntem1;
	TMenuItem *Eliminarestetem1;
	TButton *Button2;
	TButton *Button3;
	TPanel *Panel1;
	TMonthCalendar *MC2;
	TButton *Button4;
	TButton *Button5;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button6;
	TShape *Shape1;
	TButton *Button7;
	TLabel *Label7;
	TSQLQuery *Query3;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *CDS3;
	TDataSource *DataSource3;
	TIntegerField *CDSidCuentaCorriente;
	TDateField *CDSfecha;
	TIntegerField *CDSrefCliente;
	TIntegerField *CDSrefPedido;
	TWideStringField *CDScompAsociado;
	TFMTBCDField *CDSimporte;
	TIntegerField *CDS3idPagoRecibido;
	TDateField *CDS3fecha;
	TIntegerField *CDS3refCliente;
	TIntegerField *CDS3codMedio;
	TFMTBCDField *CDS3importe;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TEdit *Edit1;
	TLabel *Label2;
	TComboBox *ComboBox1;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit2;
	TWideStringField *CDS3comentario;
	TWideStringField *CDS3medioPago;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDataset1;
	TfrxDBDataset *frxDBDataset2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Ingresaruntem1Click(TObject *Sender);
	void __fastcall CDSvalorPedidoChange(TField *Sender);
	void __fastcall CDSpagoRecibidoChange(TField *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Eliminarestetem1Click(TObject *Sender);
	void __fastcall CDScomentarioChange(TField *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfCuentas(TComponent* Owner);

	int refCliente;
	void mostrar(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfCuentas *fCuentas;
//---------------------------------------------------------------------------
#endif
