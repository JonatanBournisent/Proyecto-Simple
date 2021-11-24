//---------------------------------------------------------------------------

#ifndef uFrameAgregarCategoriaH
#define uFrameAgregarCategoriaH
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
//---------------------------------------------------------------------------
class TfAgregarCategoria : public TFrame
{
__published:	// IDE-managed Components
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TWideStringField *CDSdescripcion;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfAgregarCategoria(TComponent* Owner);



	void inicializarFrame(String nomDB);
	String nombreDB;
};
//---------------------------------------------------------------------------
extern PACKAGE TfAgregarCategoria *fAgregarCategoria;
//---------------------------------------------------------------------------
#endif
