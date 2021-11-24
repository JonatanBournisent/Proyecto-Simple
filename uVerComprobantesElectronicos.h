//---------------------------------------------------------------------------

#ifndef uVerComprobantesElectronicosH
#define uVerComprobantesElectronicosH
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include "frxClass.hpp"
#include "frxBarcode.hpp"
#include <Vcl.Dialogs.hpp>
#include "frxExportPDF.hpp"
#include "frxExportBaseDialog.hpp"
//---------------------------------------------------------------------------
class TfVerComprobantesElectronicos : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label3;
	TDBGrid *DBGrid1;
	TEdit *Edit1;
	TMonthCalendar *MC1;
	TButton *Button1;
	TButton *Button2;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TIntegerField *CDS1idComprobanteElectronico;
	TWideStringField *CDS1cliente;
	TWideStringField *CDS1cuitCliente;
	TWideStringField *CDS1cfIVA;
	TDateField *CDS1fecha;
	TWideStringField *CDS1tipoComp;
	TWideStringField *CDS1nroComp;
	TFMTBCDField *CDS1netoGravado;
	TFMTBCDField *CDS1iva21;
	TDataSource *DataSource1;
	TFMTBCDField *CDS1iva105;
	TFMTBCDField *CDS1final;
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryUpdate;
	TPopupMenu *PopupMenu1;
	TMenuItem *Eliminarestafactura1;
	TSQLQuery *Query2;
	TButton *Button3;
	TLabel *Label12;
	TComboBox *cbRubro;
	TSQLQuery *QueryCB;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TShape *Shape2;
	TMonthCalendar *MC2;
	TMenuItem *AnularestecomprobanteEmitirNC1;
	TfrxReport *frxReport1;
	TfrxBarCodeObject *frxBarCodeObject1;
	TSQLQuery *QueryAux;
	TPanel *Panel1;
	TDateTimePicker *DTP;
	TMemo *Memo1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label13;
	TLabel *Label14;
	TButton *Button4;
	TButton *Button5;
	TCheckBox *CheckBox1;
	TfrxPDFExport *frxPDFExport1;
	TSaveDialog *SD1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall MC1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Eliminarestafactura1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall cbRubroChange(TObject *Sender);
	void __fastcall MC2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AnularestecomprobanteEmitirNC1Click(TObject *Sender);
	void __fastcall CDS1cuitClienteGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TfVerComprobantesElectronicos(TComponent* Owner);

	bool omitir;
};
//---------------------------------------------------------------------------
extern PACKAGE TfVerComprobantesElectronicos *fVerComprobantesElectronicos;
//---------------------------------------------------------------------------
#endif
