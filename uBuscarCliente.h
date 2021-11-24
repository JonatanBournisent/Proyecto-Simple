//---------------------------------------------------------------------------

#ifndef uBuscarClienteH
#define uBuscarClienteH
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
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfBuscarCliente : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TSQLQuery *Query1;
	TLabel *Label1;
	TEdit *Edit1;
	TDBGrid *DBGrid1;
	TWideStringField *CDSnombre;
	TWideStringField *CDSapellido;
	TWideStringField *CDSrazonSocial;
	TWideStringField *CDSdomicilio;
	TWideStringField *CDStelefono;
	TWideStringField *CDScelular;
	TWideStringField *CDScuit;
	TFMTBCDField *CDSdescuento;
	TIntegerField *CDSidCliente;
	TWideStringField *CDSemail;
	TSpeedButton *Button1;
	TCheckBox *CheckBox1;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfBuscarCliente(TComponent* Owner);
	int idSeleccionado;
};
//---------------------------------------------------------------------------
extern PACKAGE TfBuscarCliente *fBuscarCliente;
//---------------------------------------------------------------------------
#endif
