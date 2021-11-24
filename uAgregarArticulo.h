//---------------------------------------------------------------------------

#ifndef uAgregarArticuloH
#define uAgregarArticuloH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfAgregarArticulo : public TForm
{
__published:	// IDE-managed Components
	TComboBox *cbTipo;
	TComboBox *cbMarca;
	TComboBox *cbModelo;
	TComboBox *cbTamano;
	TComboBox *cbColor;
	TComboBox *cbCantidad;
	TComboBox *cbUnidadMedida;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TMemo *Memo1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TButton *Button3;
	TButton *Button1;
	TComboBox *cbIVA;
	TDateTimePicker *DTP;
	TLabel *Label14;
	TCheckBox *CheckBox1;
	TLabel *Label15;
	TEdit *Edit5;
	TLabel *Label16;
	TComboBox *cbCategoria;
	TLabel *Label17;
	TLabel *Label18;
	TComboBox *cbDiseno;
	TLabel *Label19;
	TComboBox *cbSubRubro;
	TButton *Button4;
	TPanel *Panel1;
	TTimer *Timer1;
	TButton *Button5;
	TSQLQuery *QueryAux;
	TPanel *Panel6;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TEdit *Edit9;
	TEdit *Edit10;
	TComboBox *ComboBox3;
	TCheckBox *CheckBox2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit2Enter(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit3Enter(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit3Click(TObject *Sender);
	void __fastcall Edit2Click(TObject *Sender);
	void __fastcall cbTipoExit(TObject *Sender);
	void __fastcall cbMarcaExit(TObject *Sender);
	void __fastcall cbModeloExit(TObject *Sender);
	void __fastcall cbTamanoExit(TObject *Sender);
	void __fastcall cbColorExit(TObject *Sender);
	void __fastcall cbUnidadMedidaExit(TObject *Sender);
	void __fastcall cbCantidadExit(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall cbDisenoExit(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbCategoriaEnter(TObject *Sender);
	void __fastcall cbTipoEnter(TObject *Sender);
	void __fastcall cbMarcaEnter(TObject *Sender);
	void __fastcall cbModeloEnter(TObject *Sender);
	void __fastcall cbTamanoEnter(TObject *Sender);
	void __fastcall cbColorEnter(TObject *Sender);
	void __fastcall cbDisenoEnter(TObject *Sender);
	void __fastcall cbUnidadMedidaEnter(TObject *Sender);
	void __fastcall cbCantidadEnter(TObject *Sender);
	void __fastcall cbCategoriaExit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall Edit10Exit(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, System::WideChar &Key);

private:	// User declarations
public:		// User declarations
	__fastcall TfAgregarArticulo(TComponent* Owner);

	void cargarComboBox(TComboBox *cb, TSQLQuery *Query, String DBTable);
	void agregarItem(TComboBox *cb, TSQLQuery *Query, String DBTable);

	void seleccionarItemIndex(TComboBox *cb, String texto);
	String comaToDot(String str);
	bool modificando;
	bool modificandoProveedor;
	int idModificado;

	void agregarItemCB(TComboBox *cb);

	int refRubro;

	bool blockCB;

	bool paraModificar;
};
//---------------------------------------------------------------------------
extern PACKAGE TfAgregarArticulo *fAgregarArticulo;
//---------------------------------------------------------------------------
#endif
