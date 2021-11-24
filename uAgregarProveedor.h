//---------------------------------------------------------------------------

#ifndef uAgregarProveedorH
#define uAgregarProveedorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfAgregarProveedor : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit1;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TLabel *Label9;
	TEdit *Edit9;
	TTimer *Timer1;
	TButton *Button4;
	TShape *Shape1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit7Exit(TObject *Sender);
	void __fastcall Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit7KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit7KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfAgregarProveedor(TComponent* Owner);

	bool modificando;
	int idProveedorMod;
	bool cuitOK;
	bool paraModificar;
};
//---------------------------------------------------------------------------
extern PACKAGE TfAgregarProveedor *fAgregarProveedor;
//---------------------------------------------------------------------------
#endif
