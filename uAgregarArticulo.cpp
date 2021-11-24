//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uAgregarArticulo.h"
#include "uBuscarArticulo.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAgregarArticulo *fAgregarArticulo;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfAgregarArticulo::TfAgregarArticulo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TfAgregarArticulo::agregarItemCB(TComboBox *cb)
{
   if(cb->Text == "" || cb->ItemIndex >= 0)
	  return;

   while(cb->Text.Pos(" ") == 1)
	  cb->Text = cb->Text.Delete(1,1);

   while(cb->Text.SubString(cb->Text.Length(),1) == " ")
	  cb->Text = cb->Text.Delete(cb->Text.Length(),1);

   String a = cb->Text.UpperCase();
   cb->Text = a;
   cb->Items->Add(a);
   cb->ItemIndex = cb->Items->IndexOf(a);
}

//---------------------------------------------------------------------------

String TfAgregarArticulo::comaToDot(String str)
{
   if(str.Pos(",") == 0)
	  return str;
   if(str.Pos(".") > 0)
	  return "0";

   int p = str.Pos(",");
   str = str.Delete(p,1);
   return str.Insert(".",p);
}

//---------------------------------------------------------------------------

void TfAgregarArticulo::cargarComboBox(TComboBox *cb, TSQLQuery *Query, String campo)
{
   Query->Close();
   Query->SQL->Clear();
   Query->SQL->Add("SELECT DISTINCT " + campo + " FROM articulos ORDER BY " + campo);
   Query->Open();

   Query->First();
   cb->Clear();
   while(!Query->Eof)
   {
	  if(Query->FieldByName(campo)->AsString != "")
		 cb->Items->Add(Query->FieldByName(campo)->AsString);

	  Query->Next();
   }
   Query->Close();

   cb->ItemIndex = -1;
}

//---------------------------------------------------------------------------


void __fastcall TfAgregarArticulo::Button2Click(TObject *Sender)
{
   if(refRubro == 1 && cbSubRubro->ItemIndex == -1)
   {
	  Application->MessageBox(L"Debe especificar el subrubro",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   bool nuevoArticulo = false;

   if(!modificando)
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT COUNT(*) AS existe FROM articulos WHERE "
					   " categoria = :desCategoria "
					   " AND tipo = :desTipo "
					   " AND marca = :desMarca "
					   " AND modelo = :desModelo "
					   " AND diseno = :desDiseno "
					   " AND tamano = :desTamano "
					   " AND color = :desColor "
					   " AND cantidad = :desCantidad "
					   " AND unidadMedida = :desUnidadMedida "
					   "LIMIT 1");

	  Query1->ParamByName("desCategoria")->AsString = cbCategoria->Text;
	  Query1->ParamByName("desTipo")->AsString = cbTipo->Text;
	  Query1->ParamByName("desMarca")->AsString = cbMarca->Text;
	  Query1->ParamByName("desModelo")->AsString = cbModelo->Text;
	  Query1->ParamByName("desDiseno")->AsString = cbDiseno->Text;
	  Query1->ParamByName("desTamano")->AsString = cbTamano->Text;
	  Query1->ParamByName("desColor")->AsString = cbColor->Text;
	  Query1->ParamByName("desCantidad")->AsString = cbCantidad->Text;
	  Query1->ParamByName("desUnidadMedida")->AsString = cbUnidadMedida->Text;

	  Query1->Open();

	  if(Query1->FieldByName("existe")->AsInteger > 0)
	  {
		 Query1->Close();
		 Application->MessageBox(L"Este producto ya se encuentra agregado",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		 return;
	  }
   }

   Query1->Close();
   Query1->SQL->Clear();

   if(!modificando)
   {
	  Query1->SQL->Add("INSERT INTO articulos (refRubro, refSubRubro, categoria, tipo, marca, modelo, tamano, "
					   "color, diseno, cantidad, unidadMedida, descripcion, "
					   "codigo, precioCompra, margenUtilidad, stock, stockCritico, iva, proximoVencimiento) VALUES ("
					   ":refRubro, :refSubRubro, :desCategoria, :desTipo, :desMarca, :desModelo, :desTamano, "
					   ":desColor, :desDiseno, :desCantidad, :desUnidadMedida, "
					   ":descripcion, :codigo, :precioCompra, :margenUtilidad, :stock, :stockCritico, :iva, :proximoVencimiento)");
      nuevoArticulo = true;
   }
   else
   {
	  Query1->SQL->Add("UPDATE articulos SET "
					   "refRubro = :refRubro, "
					   "refSubRubro = :refSubRubro, "
					   "categoria = :desCategoria, tipo = :desTipo, marca = :desMarca, "
					   "modelo = :desModelo, tamano = :desTamano,  "
					   "color = :desColor, diseno = :desDiseno, cantidad =  :desCantidad,  "
					   "unidadMedida = :desUnidadMedida,  "
					   "descripcion = :descripcion, codigo = :codigo, precioCompra = :precioCompra, "
					   "margenUtilidad = :margenUtilidad, stock = :stock, stockCritico = :stockCritico, iva = :iva, proximoVencimiento = :proximoVencimiento "
					   "WHERE idArticulo = :id LIMIT 1");

	   Query1->ParamByName("id")->AsInteger = idModificado;
   }

   Query1->ParamByName("refRubro")->AsInteger = refRubro;
   if(refRubro == 1)
	  Query1->ParamByName("refSubRubro")->AsInteger = cbSubRubro->ItemIndex + 2;
   else
	  Query1->ParamByName("refSubRubro")->AsInteger = 1;

   Query1->ParamByName("desCategoria")->AsString = cbCategoria->Text.UpperCase();
   Query1->ParamByName("desTipo")->AsString = cbTipo->Text.UpperCase();
   Query1->ParamByName("desMarca")->AsString = cbMarca->Text.UpperCase();
   Query1->ParamByName("desModelo")->AsString = cbModelo->Text.UpperCase();
   Query1->ParamByName("desTamano")->AsString = cbTamano->Text.UpperCase();
   Query1->ParamByName("desColor")->AsString = cbColor->Text.UpperCase();
   Query1->ParamByName("desDiseno")->AsString = cbDiseno->Text.UpperCase();
   Query1->ParamByName("desCantidad")->AsString = cbCantidad->Text.UpperCase();
   Query1->ParamByName("desUnidadMedida")->AsString = cbUnidadMedida->Text.UpperCase();
   Query1->ParamByName("descripcion")->AsString = Memo1->Text.UpperCase();
   Query1->ParamByName("codigo")->AsString = Edit1->Text;
   Query1->ParamByName("precioCompra")->AsString = comaToDot(Edit2->Text.SubString(3,Edit2->Text.Length()));
   Query1->ParamByName("margenUtilidad")->AsFloat = StrToFloat(Edit3->Text.SubString(1,Edit3->Text.Length()-2));
   Query1->ParamByName("stock")->AsString = Edit4->Text;
   Query1->ParamByName("stockCritico")->AsString = Edit5->Text;
   Query1->ParamByName("iva")->AsFloat = StrToFloat(cbIVA->Text.SubString(1,cbIVA->Text.Length() - 2));
   Query1->ParamByName("proximoVencimiento")->AsDateTime = DTP->DateTime;

   Query1->ExecSQL();
   modificando = false;



   if(CheckBox2->Checked)
   {
	   if(ComboBox3->ItemIndex > -1 && Edit9->Text != "" && Edit10->Text != "0,00")
	   {
		   if(!modificandoProveedor)
		   {
              QueryAux->Close();
			  QueryAux->SQL->Clear();
			  QueryAux->SQL->Add("SELECT MAX(idArticulo) AS ultimo FROM articulos");
			  QueryAux->Open();
		      int idUltimo = QueryAux->FieldByName("ultimo")->AsInteger;

			  QueryAux->Close();
			  QueryAux->SQL->Clear();
			  QueryAux->SQL->Add("INSERT INTO relacionproveedores (refArticulo, refProveedor, codigo, escala) VALUES (:refArticulo, (SELECT idProveedor FROM proveedores WHERE nombre = :nombre), :codigo, :escala)");
			  QueryAux->ParamByName("refArticulo")->AsInteger = idUltimo;
			  QueryAux->ParamByName("nombre")->AsString = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
			  QueryAux->ParamByName("codigo")->AsString = Edit9->Text;
			  QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit10->Text);
			  QueryAux->ExecSQL();
		   }
		   else
		   {
			  QueryAux->Close();
			  QueryAux->SQL->Clear();
			  QueryAux->SQL->Add("UPDATE relacionproveedores SET refProveedor = (SELECT idProveedor FROM proveedores WHERE nombre = :nombre LIMIT 1), codigo = :codigo, escala = :escala WHERE refArticulo = :refArticulo LIMIT 1");
			  QueryAux->ParamByName("refArticulo")->AsInteger = idModificado;
			  QueryAux->ParamByName("nombre")->AsString = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
			  QueryAux->ParamByName("codigo")->AsString = Edit9->Text;
			  QueryAux->ParamByName("escala")->AsFloat = StrToFloat(Edit10->Text);
			  QueryAux->ExecSQL();
		   }

	   }
	   else
	      Application->MessageBox(L"Para poder asociar un proveedor debe: \nEspecificar un proveedor\nIntroducir un código\nProporcionar un factor de escala mayor a cero \n\nNO SE ASOCIO UN PROVEEDOR",L"ADVERTENCIA",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);

   }


   if(Application->MessageBox(L"Los datos fueron guardados correctamente. Desea conservar el texto de los campos?",L"Datos guardados",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDNO)
   {
	  cbCategoria->Text = "";
	  cbTipo->Text = "";
	  cbMarca->Text = "";
	  cbModelo->Text = "";
	  cbTamano->Text = "";
	  cbColor->Text = "";
	  cbDiseno->Text = "";
	  cbCantidad->Text = "";
	  cbUnidadMedida->Text = "";

      cbSubRubro->ItemIndex = -1;
	  cbCategoria->ItemIndex = -1;
	  cbTipo->ItemIndex = -1;
	  cbMarca->ItemIndex = -1;
	  cbModelo->ItemIndex = -1;
	  cbTamano->ItemIndex = -1;
	  cbColor->ItemIndex = -1;
	  cbDiseno->ItemIndex = -1;
	  cbCantidad->ItemIndex = -1;
	  cbUnidadMedida->ItemIndex = -1;
   }

   Edit2->Text = "$ 0,00";
   Edit3->Text = "0,00 %";
   Edit4->Text = "0";
   Edit5->Text = "0";
   Edit1->Text = "";
   CheckBox1->Checked = false;
   DTP->DateTime = StrToDateTime("01/01/2100 00:00:00");
   cbIVA->ItemIndex = 1;
   Memo1->Clear();
   Panel6->Visible = false;
   CheckBox2->Checked = false;

   if(refRubro == 1)
	  cbSubRubro->SetFocus();
   else
	  cbCategoria->SetFocus();

   paraModificar = false;
   modificandoProveedor = false;
   Button3->Enabled = true;
   CheckBox2->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TfAgregarArticulo::FormShow(TObject *Sender)
{
   if(refRubro == 1)
	  Label17->Caption = "Rubro: Librería";
   else if(refRubro == 2)
	  Label17->Caption = "Rubro: Informática";
   else if(refRubro == 3)
	  Label17->Caption = "Rubro: Break";
   else if(refRubro == 4)
	  Label17->Caption = "Rubro: Limpieza e higiene";

   cargarComboBox(cbCategoria, Query1, "categoria");
   cargarComboBox(cbCantidad, Query1, "cantidad");
   cargarComboBox(cbColor, Query1, "color");
   cargarComboBox(cbMarca, Query1, "marca");
   cargarComboBox(cbModelo, Query1, "modelo");
   cargarComboBox(cbDiseno, Query1, "diseno");
   cargarComboBox(cbTamano, Query1, "tamano");
   cargarComboBox(cbTipo, Query1, "tipo");
   cargarComboBox(cbUnidadMedida, Query1, "unidadMedida");

   modificandoProveedor = false;

   Edit2->Text = "$ 0,00";
   Edit3->Text = "0,00 %";
   Edit4->Text = "0";
   Edit5->Text = "0";
   Edit1->Text = "";
   cbIVA->ItemIndex = 1;
   CheckBox1->Checked = false;
   CheckBox1Click(CheckBox1);
   Memo1->Clear();
   CheckBox2->Checked = false;
   Panel6->Visible = false;

   Button2->Enabled = true;
   Button3->Enabled = true;


   cbSubRubro->Clear();
   if(refRubro == 1 || paraModificar)
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT descripcion FROM subrubros WHERE idSubRubro > 1 ORDER BY idSubRubro");
	  Query1->Open();

	  Query1->First();
	  while(!Query1->Eof)
	  {
		 cbSubRubro->Items->Add(Query1->FieldByName("descripcion")->AsString);
		 Query1->Next();
	  }
	  Query1->Close();
	  cbSubRubro->Visible = true;
	  Label19->Visible = true;
	  cbSubRubro->ItemIndex = -1;
   }
   else
   {
	  cbSubRubro->Visible = false;
	  Label19->Visible = false;
   }

   if(refRubro == 1)
	  cbSubRubro->SetFocus();
   else
      cbCategoria->SetFocus();

   modificando = false;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT nombre FROM proveedores ORDER BY nombre");
   QueryAux->Open();

   ComboBox3->Clear();
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  ComboBox3->Items->Add(QueryAux->FieldByName("nombre")->AsString);
	  QueryAux->Next();
   }
   CheckBox2->Visible = true;


   if(paraModificar)
   {
	  Button3Click(fAgregarArticulo);
      Button3->Visible = true;
	  Button1->Margins->Left = (Panel1->Width - 4 * Button1->Width) / 5;
	  Button2->Margins->Left = (Panel1->Width - 4 * Button1->Width) / 5;
	  Button3->Margins->Left = (Panel1->Width - 4 * Button1->Width) / 5;
	  Button4->Margins->Left = (Panel1->Width - 4 * Button1->Width) / 5;
	  Button3->Enabled = false;

	  if(idModificado == 0)
		 Timer1->Enabled = true;

//	  CheckBox2->Visible = false;
   }
   else
   {
	  Button3->Visible = false;
	  Button1->Margins->Left = (Panel1->Width - 3 * Button1->Width) / 4;
	  Button2->Margins->Left = (Panel1->Width - 3 * Button1->Width) / 4;
	  Button4->Margins->Left = (Panel1->Width - 3 * Button1->Width) / 4;
   }

   blockCB = false;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Button3Click(TObject *Sender)
{
   fBuscarArticulo->llamador = 1;
   fBuscarArticulo->soloBusqueda = true;
   fBuscarArticulo->ShowModal();
   fBuscarArticulo->soloBusqueda = false;
   idModificado = fBuscarArticulo->idSeleccionado;

   if(idModificado == 0)
   {
	  Button2->Enabled = false;
	  //Application->MessageBox(L"No seleccionó un artículo para modificar.",L"Debe seleccionar un artículo!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }
   String q = "SELECT *, (SELECT descripcion FROM rubros WHERE idRubro = refRubro LIMIT 1) AS desRubro FROM articulos WHERE idArticulo = :id LIMIT 1";

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   Query1->ParamByName("id")->AsString = idModificado;
   Query1->Open();

   refRubro = Query1->FieldByName("refRubro")->AsInteger;
   cbCategoria->Text = Query1->FieldByName("categoria")->AsString;
   cbTipo->Text = Query1->FieldByName("tipo")->AsString;
   cbMarca->Text = Query1->FieldByName("marca")->AsString;
   cbModelo->Text = Query1->FieldByName("modelo")->AsString;
   cbTamano->Text = Query1->FieldByName("tamano")->AsString;
   cbColor->Text = Query1->FieldByName("color")->AsString;
   cbDiseno->Text = Query1->FieldByName("diseno")->AsString;
   cbCantidad->Text = Query1->FieldByName("cantidad")->AsString;
   cbUnidadMedida->Text = Query1->FieldByName("unidadMedida")->AsString;
   Label17->Caption = "Rubro: " + Query1->FieldByName("desRubro")->AsString;

   Memo1->Text = Query1->FieldByName("descripcion")->AsString;
   Edit1->Text = Query1->FieldByName("codigo")->AsString;
   Edit2->Text = Query1->FieldByName("precioCompra")->AsString;
   Edit3->Text = FloatToStr(Query1->FieldByName("margenUtilidad")->AsFloat);
   Edit4->Text = Query1->FieldByName("stock")->AsString;
   Edit5->Text = Query1->FieldByName("stockCritico")->AsString;
   DTP->Date = DateOf(Query1->FieldByName("proximoVencimiento")->AsDateTime);

   if(refRubro == 1)
	  Label17->Caption = "Rubro: Librería";
   else if(refRubro == 2)
	  Label17->Caption = "Rubro: Informática";
   else if(refRubro == 3)
	  Label17->Caption = "Rubro: Break";
   else if(refRubro == 4)
	  Label17->Caption = "Rubro: Limpieza e higiene";
   else
	  Label17->Caption = "HUBO UN ERROR!";


   if(CompareDate(DateOf(Query1->FieldByName("proximoVencimiento")->AsDateTime), StrToDate("01/01/2100")) != EqualsValue)
	  CheckBox1->Checked = true;
   else
	  CheckBox1->Checked = false;

   CheckBox1Click(CheckBox1);

   if(CheckBox1->Checked)
      DTP->Date = DateOf(Query1->FieldByName("proximoVencimiento")->AsDateTime);

   if(Query1->FieldByName("iva")->AsFloat == 10.5)
	  cbIVA->ItemIndex = 0;
   if(Query1->FieldByName("iva")->AsFloat == 21)
	  cbIVA->ItemIndex = 1;

   if(refRubro == 1)
   {
	  cbSubRubro->Visible = true;
	  Label19->Visible = true;
	  cbSubRubro->ItemIndex = Query1->FieldByName("refSubRubro")->AsInteger - 2;
   }
   else
   {
	  cbSubRubro->ItemIndex = -1;
	  cbSubRubro->Visible = false;
	  Label19->Visible = false;
   }

   Query1->Close();
   Edit2Exit(Edit2);
   Edit3Exit(Edit3);



   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT nombre FROM proveedores WHERE idProveedor = (SELECT refProveedor FROM relacionproveedores WHERE refArticulo = :refArticulo)");
   Query1->ParamByName("refArticulo")->AsInteger = idModificado;
   Query1->Open();
   if(Query1->IsEmpty())
   {
	  modificandoProveedor = false;
	  CheckBox2->Checked = false;
	  CheckBox2->Visible = true;
	  ComboBox3->ItemIndex = -1;
	  Edit9->Text = "";
      Edit10->Text = "0,00";
   }
   else
   {
	  modificandoProveedor = true;
	  ComboBox3->ItemIndex = ComboBox3->Items->IndexOf(Query1->FieldByName("nombre")->AsString);
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT codigo, escala FROM relacionproveedores WHERE refArticulo = :refArticulo");
	  Query1->ParamByName("refArticulo")->AsInteger = idModificado;
	  Query1->Open();
	  Edit9->Text = Query1->FieldByName("codigo")->AsString;
	  Edit10->Text = FormatFloat("0.00", Query1->FieldByName("escala")->AsFloat);
	  CheckBox2->Checked = true;
	  CheckBox2->Visible = true;
   }
   Query1->Close();


   modificando = true;
   if(refRubro == 1)
	  cbSubRubro->SetFocus();
   else
	  cbCategoria->SetFocus();

   Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit2Exit(TObject *Sender)
{
   String s = Edit2->Text;

   try
   {
	  if(s.Pos("$") > 0)
		 s = s.Delete(1,2);

	  StrToFloat(s);
   }
   catch(...)
   {
	  s = "0,00";
   }

   Edit2->Text = FormatFloat("$ 0.00", StrToFloat(s));
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit2Enter(TObject *Sender)
{
   if(dynamic_cast<TEdit *>(Sender)->Text.Pos("$ ") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = dynamic_cast<TEdit *>(Sender)->Text.Delete(1,2);

}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit3Exit(TObject *Sender)
{
   String s = Edit3->Text;

   try
   {
	  if(s.Pos("%") > 0)
		 s = s.SubString(1,s.Length() - 2);

	  StrToFloat(s);
   }
   catch(...)
   {
	  s = "0,00";
   }

   Edit3->Text = FormatFloat("0.00 %", StrToFloat(s));
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit3Enter(TObject *Sender)
{
   if(dynamic_cast<TEdit *>(Sender)->Text.Pos("%") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = dynamic_cast<TEdit *>(Sender)->Text.Delete(dynamic_cast<TEdit *>(Sender)->Text.Length()-1,2);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------


void __fastcall TfAgregarArticulo::Button1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::FormClose(TObject *Sender, TCloseAction &Action)

{
   if(modificando)
   {
	  if(Application->MessageBox(L"Se van a descartar los cambios realizados. Desea continuar?",L"Cancelar cambios?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
	  {
		 Query1->Close();
		 QueryAux->Close();
		 SQLConnection1->Close();
	  }
	  else
		 Action = caNone;
   }
   else
   {
	  bool hayTexto = false;

	  if(refRubro > 1 && cbSubRubro->ItemIndex > -1)
		 hayTexto = true;
	  else if(cbCategoria->Text != "")
		 hayTexto = true;
	  else if(cbTipo->Text != "")
		 hayTexto = true;
	  else if(cbMarca->Text != "")
		 hayTexto = true;
	  else if(cbModelo->Text != "")
		 hayTexto = true;
	  else if(cbTamano->Text != "")
		 hayTexto = true;
	  else if(cbColor->Text != "")
		 hayTexto = true;
	  else if(cbTamano->Text != "")
		 hayTexto = true;
	  else if(cbCantidad->Text != "")
		 hayTexto = true;
	  else if(cbUnidadMedida->Text != "")
		 hayTexto = true;
	  else if(Edit1->Text != "")
		 hayTexto = true;
	  else if(Edit2->Text != "$ 0,00")
		 hayTexto = true;
	  else if(Edit3->Text != "0,00 %")
		 hayTexto = true;
	  else if(Edit4->Text != "0")
		 hayTexto = true;
	  else if(Edit5->Text != "0")
		 hayTexto = true;
	  else if(Memo1->Text != "")
		 hayTexto = true;


	  if(hayTexto)
	  {
		 if(Application->MessageBox(L"Se van a descartar los cambios no guardados. Desea continuar?",L"Salir?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
		 {
			Query1->Close();
			QueryAux->Close();
			SQLConnection1->Close();
		 }
		 else
			Action = caNone;
	  }
   }

   paraModificar = false;
   blockCB = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit3Click(TObject *Sender)
{
   Edit3->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit2Click(TObject *Sender)
{
   Edit2->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbTipoExit(TObject *Sender)
{
   agregarItemCB(cbTipo);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbMarcaExit(TObject *Sender)
{
   agregarItemCB(cbMarca);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbModeloExit(TObject *Sender)
{
   agregarItemCB(cbModelo);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbTamanoExit(TObject *Sender)
{
   agregarItemCB(cbTamano);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbColorExit(TObject *Sender)
{
   agregarItemCB(cbColor);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbUnidadMedidaExit(TObject *Sender)
{
   agregarItemCB(cbUnidadMedida);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbCantidadExit(TObject *Sender)
{
   agregarItemCB(cbCantidad);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
   {
	  DTP->Date = DateOf(Now());
	  DTP->Enabled = true;
	  Label14->Visible = true;
	  DTP->Visible = true;
   }
   else
   {
	  DTP->Date = StrToDate("01/01/2100");
	  DTP->Enabled = false;
	  Label14->Visible = false;
	  DTP->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbDisenoExit(TObject *Sender)
{
   agregarItemCB(cbCantidad);
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::FormCreate(TObject *Sender)
{
   paraModificar = false;
   blockCB = true;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbCategoriaEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbTipoEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbMarcaEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbModeloEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbTamanoEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbColorEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbDisenoEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbUnidadMedidaEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbCantidadEnter(TObject *Sender)
{
   if(blockCB)
	  return;
   dynamic_cast <TComboBox *>(Sender)->DroppedDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::cbCategoriaExit(TObject *Sender)
{
   agregarItemCB(cbCategoria);
}
//---------------------------------------------------------------------------


void __fastcall TfAgregarArticulo::Button4Click(TObject *Sender)
{
   modificando = false;

   if(Application->MessageBox(L"Desea cancelar todos los cambios y restablecer todos los valores?",L"Cancelar cambios?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  cbCategoria->Text = "";
	  cbTipo->Text = "";
	  cbMarca->Text = "";
	  cbModelo->Text = "";
	  cbTamano->Text = "";
	  cbColor->Text = "";
	  cbDiseno->Text = "";
	  cbCantidad->Text = "";
	  cbUnidadMedida->Text = "";

      cbSubRubro->ItemIndex = -1;
	  cbCategoria->ItemIndex = -1;
	  cbTipo->ItemIndex = -1;
	  cbMarca->ItemIndex = -1;
	  cbModelo->ItemIndex = -1;
	  cbTamano->ItemIndex = -1;
	  cbColor->ItemIndex = -1;
	  cbDiseno->ItemIndex = -1;
	  cbCantidad->ItemIndex = -1;
	  cbUnidadMedida->ItemIndex = -1;

	   Edit2->Text = "$ 0,00";
	   Edit3->Text = "0,00 %";
	   Edit4->Text = "0";
	   Edit5->Text = "0";
	   Edit1->Text = "";
	   CheckBox1->Checked = false;
	   DTP->Date = StrToDate("01/01/2100");
	   cbIVA->ItemIndex = 1;
	   Memo1->Clear();


	   CheckBox2->Checked = false;
	   CheckBox2->Visible = true;
	   Panel6->Visible = false;
	   ComboBox3->ItemIndex = -1;
	   Edit9->Text = "";
	   Edit10->Text = "0,00";

	   if(refRubro == 1)
		  cbSubRubro->SetFocus();
	   else
		  cbCategoria->SetFocus();

	   paraModificar = false;
	   Button3->Enabled = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarArticulo::Timer1Timer(TObject *Sender)
{
   Timer1->Enabled = false;
   fAgregarArticulo->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfAgregarArticulo::Button5Click(TObject *Sender)
{
   if(refRubro != 1)
   {
	  Edit3->Text = "35,00 %";
	  return;
   }

   float pc = StrToFloat(Edit2->Text.Delete(1,2));

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT precioCompra, margenUtilidad FROM articulos WHERE refRubro = 1 AND (precioCompra > (:pc * 0.7)) AND (precioCompra < (:pc * 1.3)) ORDER BY precioCompra");
   QueryAux->ParamByName("pc")->AsFloat = pc;
   QueryAux->Open();

   QueryAux->First();
   float menor, mayor, muMenor, muMayor, mu;
   menor = -1;
   float actual;
   bool mismoPrecio = false;
   bool salir = false;
   while(!QueryAux->Eof && !salir)
   {
	  actual = QueryAux->FieldByName("precioCompra")->AsFloat;
	  if(pc == actual)
	  {
		 mismoPrecio = true;
		 mu = QueryAux->FieldByName("margenUtilidad")->AsFloat;
		 salir = true;
	  }
	  else
	  {
		 if((pc - actual) > 0)
		 {
			menor = actual;
			muMenor = QueryAux->FieldByName("margenUtilidad")->AsFloat;
		 }
		 else
		 {
			mayor = actual;
			muMayor = QueryAux->FieldByName("margenUtilidad")->AsFloat;
			salir = true;
		 }
	  }
	  QueryAux->Next();
   }
   QueryAux->Close();


   if(mismoPrecio)
   {
	  Edit3->Text = FormatFloat("0.00 %", mu);
   }
   else
   {
	  mu = (muMayor + muMenor) / 2;
	  Edit3->Text = FormatFloat("0.00 %", mu);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::CheckBox2Click(TObject *Sender)
{
   if(CheckBox2->Checked)
   {
	  Panel6->Visible = true;
   }
   else
   {
	  Panel6->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit10Exit(TObject *Sender)
{
   try
   {
	   StrToFloat(dynamic_cast<TEdit *>(Sender)->Text);
   }
   catch (...)
   {
	   dynamic_cast<TEdit *>(Sender)->Text = "0,0";
   }

   Edit10->Text = FormatFloat("0.00", StrToFloat(Edit10->Text));
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarArticulo::Edit10KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

