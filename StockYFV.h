//---------------------------------------------------------------------------

#ifndef StockYFVH
#define StockYFVH
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
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfStockYFV : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TIntegerField *CDSidArticulo;
	TWideStringField *CDSnombre;
	TDateField *CDSproximoVencimiento;
	TIntegerField *CDSstock;
	TSpinEdit *SpinEdit1;
	TSpinEdit *SpinEdit2;
	TRadioGroup *RG1;
	TSQLQuery *QueryCB;
	TLabel *Label12;
	TComboBox *cbRubro;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall RG1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall CDSproximoVencimientoGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall SpinEdit2Change(TObject *Sender);
	void __fastcall cbRubroChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfStockYFV(TComponent* Owner);

	void buscar(int filtro, String orden);
	bool blockSE;
};
//---------------------------------------------------------------------------
extern PACKAGE TfStockYFV *fStockYFV;
//---------------------------------------------------------------------------
#endif
