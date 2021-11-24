//---------------------------------------------------------------------------

#ifndef uSeleccionarArticuloH
#define uSeleccionarArticuloH
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
#include <Vcl.Mask.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfSeleccionarArticulo : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit2;
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSource *DataSource1;
	TClientDataSet *CDS;
	TDataSetProvider *DataSetProvider1;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label16;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TIntegerField *CDSidArticulo;
	TWideStringField *CDScategoria;
	TWideStringField *CDStipo;
	TWideStringField *CDSmarca;
	TWideStringField *CDSmodelo;
	TWideStringField *CDStamano;
	TWideStringField *CDScolor;
	TWideStringField *CDSdiseno;
	TWideStringField *CDScantidad;
	TWideStringField *CDSunidadMedida;
	TIntegerField *CDSstock;
	TFMTBCDField *CDSprecioCompra;
	TFMTBCDField *CDSmargenUtilidad;
	TFMTBCDField *CDSiva;
	TSQLQuery *QueryUpdate;
	TLabel *Label2;
	TFMTBCDField *CDSprecioVenta;
	TDBEdit *DBEdit3;
	TLabel *Label3;
	TDBEdit *DBEdit4;
	TFMTBCDField *CDSprecioVentaCIVA;
	TDBEdit *DBEdit5;
	TCheckBox *CheckBox1;
	TShape *Shape1;
	TShape *Shape2;
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall CDSprecioCompraChange(TField *Sender);
	void __fastcall CDSmargenUtilidadChange(TField *Sender);
	void __fastcall CDSivaChange(TField *Sender);
	void __fastcall DBEdit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall DBEdit1Exit(TObject *Sender);
	void __fastcall DBEdit1Enter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBEdit5KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall DBEdit5Exit(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfSeleccionarArticulo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSeleccionarArticulo *fSeleccionarArticulo;
//---------------------------------------------------------------------------
#endif
