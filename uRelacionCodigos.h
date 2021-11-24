//---------------------------------------------------------------------------

#ifndef uRelacionCodigosH
#define uRelacionCodigosH
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
//---------------------------------------------------------------------------
class TfRelacionCodigos : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TfRelacionCodigos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfRelacionCodigos *fRelacionCodigos;
//---------------------------------------------------------------------------
#endif
