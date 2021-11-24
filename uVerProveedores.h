//---------------------------------------------------------------------------

#ifndef uVerProveedoresH
#define uVerProveedoresH
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
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfVerProveedores : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TWideStringField *CDS1nombre;
	TWideStringField *CDS1domicilio;
	TWideStringField *CDS1telefono;
	TWideStringField *CDS1celular;
	TWideStringField *CDS1cuit;
	TSQLQuery *QueryAux;
	TIntegerField *CDS1idRelacionProveedor;
	TPopupMenu *PopupMenu1;
	TMenuItem *Quitaresteproveedordelalista1;
	TWideStringField *CDS1codigo;
	TButton *Button1;
	TPanel *Panel1;
	TEdit *Edit1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label2;
	TFMTBCDField *CDS1precio;
	TEdit *Edit3;
	TLabel *Label3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Quitaresteproveedordelalista1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfVerProveedores(TComponent* Owner);

	int idArticulo;
};
//---------------------------------------------------------------------------
extern PACKAGE TfVerProveedores *fVerProveedores;
//---------------------------------------------------------------------------
#endif
