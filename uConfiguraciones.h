//---------------------------------------------------------------------------

#ifndef uConfiguracionesH
#define uConfiguracionesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfConfiguraciones : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label20;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TComboBox *cboPrinterPresupuestos;
	TComboBox *cboPrinterEtiquetas;
	TComboBox *cboPrinterPDF;
	TButton *Button2;
	TGroupBox *GroupBox1;
	TLabel *Label12;
	TEdit *Edit1;
	TButton *Button8;
	TEdit *Edit2;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Edit2Enter(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfConfiguraciones(TComponent* Owner);

	TPrinter *printer;
	String DirFacturas;
};
//---------------------------------------------------------------------------
extern PACKAGE TfConfiguraciones *fConfiguraciones;
//---------------------------------------------------------------------------
#endif
