//---------------------------------------------------------------------------

#ifndef uBuscarArticuloH
#define uBuscarArticuloH
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfBuscarArticulo : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSource *DataSource1;
	TClientDataSet *CDS;
	TDataSetProvider *DataSetProvider1;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *cbCategoria;
	TComboBox *cbTipo;
	TComboBox *cbMarca;
	TComboBox *cbModelo;
	TComboBox *cbTamano;
	TComboBox *cbColor;
	TComboBox *cbCantidad;
	TComboBox *cbUnidadMedida;
	TSQLQuery *QueryCB;
	TPopupMenu *PopupMenu1;
	TSQLQuery *QueryAux;
	TMenuItem *Verlistadeproveedores1;
	TMenuItem *Modificarstock1;
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit2;
	TLabel *Label11;
	TComboBox *cbRubro;
	TLabel *Label12;
	TIntegerField *CDSidArticulo;
	TWideStringField *CDScategoria;
	TWideStringField *CDStipo;
	TWideStringField *CDSmarca;
	TWideStringField *CDSmodelo;
	TWideStringField *CDStamano;
	TWideStringField *CDScolor;
	TWideStringField *CDSunidadMedida;
	TWideStringField *CDScantidad;
	TWideStringField *CDSdiseno;
	TIntegerField *CDSstock;
	TLabel *Label13;
	TComboBox *cbDiseno;
	TSpeedButton *Button3;
	TPanel *Panel2;
	TLabel *Label14;
	TEdit *Edit3;
	TButton *Button4;
	TButton *Button5;
	TPanel *Panel3;
	TLabel *Label15;
	TEdit *Edit4;
	TButton *Button6;
	TButton *Button7;
	TMenuItem *Actualizarprecio1;
	TMenuItem *Modificarmargendeganancia1;
	TSQLQuery *QueryUpdate;
	TPanel *Panel4;
	TLabel *Label16;
	TLabel *Label17;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TMenuItem *Actualizarvaloresdegrupo1;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TMenuItem *Modificarpreciodegrupo1;
	TMenuItem *Modificarmargendeutilidaddegrupo1;
	TMenuItem *Configurarpromocin1;
	TPanel *Panel5;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TShape *Shape1;
	TMenuItem *Eliminarartculo1;
	TPanel *Panel6;
	TButton *Button14;
	TButton *Button15;
	TEdit *Edit9;
	TEdit *Edit10;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TComboBox *ComboBox1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall cbCategoriaChange(TObject *Sender);
	void __fastcall cbTipoChange(TObject *Sender);
	void __fastcall cbMarcaChange(TObject *Sender);
	void __fastcall cbModeloChange(TObject *Sender);
	void __fastcall cbTamanoChange(TObject *Sender);
	void __fastcall cbColorChange(TObject *Sender);
	void __fastcall cbCantidadChange(TObject *Sender);
	void __fastcall cbUnidadMedidaChange(TObject *Sender);
	void __fastcall Verlistadeproveedores1Click(TObject *Sender);
	void __fastcall Modificarstock1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall cbRubroChange(TObject *Sender);
	void __fastcall cbDisenoChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Actualizarprecio1Click(TObject *Sender);
	void __fastcall Edit3Enter(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit4Enter(TObject *Sender);
	void __fastcall Edit4Exit(TObject *Sender);
	void __fastcall Edit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Modificarmargendeganancia1Click(TObject *Sender);
	void __fastcall Edit3Click(TObject *Sender);
	void __fastcall Edit4Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Actualizarvaloresdegrupo1Click(TObject *Sender);
	void __fastcall Edit6Exit(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit5KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit6KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Modificarpreciodegrupo1Click(TObject *Sender);
	void __fastcall Modificarmargendeutilidaddegrupo1Click(TObject *Sender);
	void __fastcall Configurarpromocin1Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Edit8KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit7KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit8Exit(TObject *Sender);
	void __fastcall Eliminarartculo1Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Edit10Exit(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfBuscarArticulo(TComponent* Owner);

	void buscar(String orden);
	void buscarVariantes(TComboBox *CB, String field);
	int llamador; //1: selecciona para modificar
	int idSeleccionado;
	int idPromocion;
	String comaToDot(String str);
	void formularioActivo(bool condicion);
	bool soloBusqueda;
	bool modificarGrupo;
	bool modificandoProveedor;
};
//---------------------------------------------------------------------------
extern PACKAGE TfBuscarArticulo *fBuscarArticulo;
//---------------------------------------------------------------------------
#endif
