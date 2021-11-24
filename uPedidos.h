//---------------------------------------------------------------------------

#ifndef uPedidosH
#define uPedidosH
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
#include "frxClass.hpp"
//---------------------------------------------------------------------------
class TfPedidos : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource2;
	TClientDataSet *CDS;
	TIntegerField *CDSidPedido;
	TWideStringField *CDScliente;
	TSQLTimeStampField *CDSmomento;
	TWideStringField *CDSestadoPedido;
	TIntegerField *CDSrefEstadoPedido;
	TDataSetProvider *DataSetProvider2;
	TSQLQuery *QueryPedido;
	TSQLQuery *QueryAux;
	TSQLConnection *SQLConnection1;
	TDBGrid *DBGrid1;
	TLabel *Label13;
	TRadioGroup *RG1;
	TIntegerField *CDSrefCliente;
	TButton *Button1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Verestaordendecompra1;
	TMenuItem *Eliminarestaordendecompra1;
	TMenuItem *Crearnuevaordendecompra1;
	TDateField *CDSfechaConfirmacion;
	TDateField *CDSfechaFinalizacion;
	TDateField *CDSfechaEntrega;
	TPanel *Panel1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TWideStringField *CDSordenAsociada;
	TMenuItem *ModificarOrdenasociada1;
	TPanel *Panel2;
	TEdit *Edit2;
	TLabel *Label2;
	TEdit *Edit3;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit4;
	TComboBox *CB;
	TLabel *Label5;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label6;
	TShape *Shape1;
	TfrxReport *frxReport1;
	TMenuItem *Imprimiretiquetadeentrega1;
	TEdit *Edit5;
	TRadioGroup *RG2;
	TButton *Button5;
	TMenuItem *CancelarEstadoconfirmado1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall RG1Click(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Crearnuevaordendecompra1Click(TObject *Sender);
	void __fastcall Verestaordendecompra1Click(TObject *Sender);
	void __fastcall Eliminarestaordendecompra1Click(TObject *Sender);
	void __fastcall CDSfechaConfirmacionGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall CDSfechaFinalizacionGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall CDSfechaEntregaGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ModificarOrdenasociada1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Imprimiretiquetadeentrega1Click(TObject *Sender);
	void __fastcall CBChange(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit5Enter(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall RG2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall CancelarEstadoconfirmado1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfPedidos(TComponent* Owner);

	void buscar(String orden);
	bool modificarOrdenAsociada;
};
//---------------------------------------------------------------------------
extern PACKAGE TfPedidos *fPedidos;
//---------------------------------------------------------------------------
#endif
