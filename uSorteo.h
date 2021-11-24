//---------------------------------------------------------------------------

#ifndef uSorteoH
#define uSorteoH
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TfSorteo : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TButton *Button2;
	TTimer *Timer1;
	TWideStringField *CDSnombre;
	TTimer *Timer2;
	TDBText *DBText1;
	TSQLQuery *QueryUpdate;
	TTimer *Timer3;
	TPanel *Panel1;
	TLabel *Label1;
	TDataSetProvider *DataSetProvider1;
	TImage *Image1;
	TDBText *DBText2;
	TPanel *Panel2;
	TLabel *Label2;
	TTimer *Timer4;
	TTimer *Timer5;
	TPanel *Panel3;
	TLabel *Label3;
	TLabel *Label4;
	TImage *Image2;
	TShape *Shape1;
	TTimer *Timer6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Timer5Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer6Timer(TObject *Sender);
	void __fastcall Label2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfSorteo(TComponent* Owner);

	int i;
	int j;

	int limite;
	int aleatorio;
	TStringList *ListaHistorias;
	int ih;
	int k;
};
//---------------------------------------------------------------------------
extern PACKAGE TfSorteo *fSorteo;
//---------------------------------------------------------------------------
#endif
