//---------------------------------------------------------------------------

#ifndef uActualizarPreciosH
#define uActualizarPreciosH
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
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfActualizarPrecios : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TDBGrid *DBGrid1;
	TComboBox *cbRubro;
	TComboBox *cbTipo;
	TComboBox *cbMarca;
	TComboBox *cbModelo;
	TComboBox *cbTamano;
	TComboBox *cbColor;
	TComboBox *cbCantidad;
	TComboBox *cbUnidadMedida;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSource *DataSource1;
	TClientDataSet *CDS;
	TDataSetProvider *DataSetProvider1;
	TLabel *Label1;
	TLabel *Label5;
	TSQLQuery *QueryCB;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TLabel *Label9;
	TSQLQuery *QueryUpdate;
	TPanel *Panel1;
	TTimer *Timer1;
	TLabel *Label10;
	TEdit *Edit1;
	TButton *Button4;
	TPopupMenu *PopupMenu1;
	TMenuItem *Actualizarprecio1;
	TMenuItem *Actualizarmargendeganancia1;
	TButton *Button5;
	TPanel *Panel2;
	TLabel *Label13;
	TEdit *Edit4;
	TButton *Button6;
	TButton *Button7;
	void __fastcall cbRubroChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit2Click(TObject *Sender);
	void __fastcall Edit3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall cbTipoChange(TObject *Sender);
	void __fastcall cbMarcaChange(TObject *Sender);
	void __fastcall cbModeloChange(TObject *Sender);
	void __fastcall cbTamanoChange(TObject *Sender);
	void __fastcall cbColorChange(TObject *Sender);
	void __fastcall cbCantidadChange(TObject *Sender);
	void __fastcall cbUnidadMedidaChange(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Actualizarprecio1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit4Enter(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Actualizarmargendeganancia1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfActualizarPrecios(TComponent* Owner);

	String comaToDot(String str);
	void buscar(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfActualizarPrecios *fActualizarPrecios;
//---------------------------------------------------------------------------
#endif
