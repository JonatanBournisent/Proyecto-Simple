//---------------------------------------------------------------------------

#ifndef uAgregarClienteH
#define uAgregarClienteH
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
class TfAgregarCliente : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TButton *Button1;
	TButton *Button2;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TButton *Button3;
	TLabel *Label9;
	TEdit *Edit9;
	TLabel *Label10;
	TComboBox *ComboBox1;
	TTimer *Timer1;
	TButton *Button4;
	TShape *Shape1;
	TEdit *Edit10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit11;
	TEdit *Edit12;
	TLabel *Label13;
	TLabel *Label14;
	TEdit *Edit13;
	TEdit *Edit14;
	TLabel *Label15;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit8Click(TObject *Sender);
	void __fastcall Edit8Enter(TObject *Sender);
	void __fastcall Edit8Exit(TObject *Sender);
	void __fastcall Edit8KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit7KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit7KeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit7Exit(TObject *Sender);
	void __fastcall Edit7KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfAgregarCliente(TComponent* Owner);

	bool modificando;
	int idClienteMod;
	bool cuitOK;
	bool desligarRZ;
	bool registraConDNI;
	bool paraModificar;
};
//---------------------------------------------------------------------------
extern PACKAGE TfAgregarCliente *fAgregarCliente;
//---------------------------------------------------------------------------
#endif
