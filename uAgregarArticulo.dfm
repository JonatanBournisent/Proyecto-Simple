object fAgregarArticulo: TfAgregarArticulo
  Left = 0
  Top = -17
  BorderStyle = bsDialog
  Caption = ' Agregar o modificar un articulo...'
  ClientHeight = 667
  ClientWidth = 731
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 110
    Width = 47
    Height = 13
    Caption = 'Categoria'
  end
  object Label2: TLabel
    Left = 192
    Top = 110
    Width = 20
    Height = 13
    Caption = 'Tipo'
  end
  object Label3: TLabel
    Left = 375
    Top = 110
    Width = 29
    Height = 13
    Caption = 'Marca'
  end
  object Label4: TLabel
    Left = 560
    Top = 110
    Width = 34
    Height = 13
    Caption = 'Modelo'
  end
  object Label5: TLabel
    Left = 8
    Top = 181
    Width = 38
    Height = 13
    Caption = 'Tama'#241'o'
  end
  object Label6: TLabel
    Left = 192
    Top = 181
    Width = 25
    Height = 13
    Caption = 'Color'
  end
  object Label7: TLabel
    Left = 193
    Top = 253
    Width = 43
    Height = 13
    Caption = 'Cantidad'
  end
  object Label8: TLabel
    Left = 8
    Top = 253
    Width = 85
    Height = 13
    Caption = 'Unidad de medida'
  end
  object Label9: TLabel
    Left = 8
    Top = 535
    Width = 54
    Height = 13
    Caption = 'Descripcion'
    Visible = False
  end
  object Label10: TLabel
    Left = 236
    Top = 329
    Width = 46
    Height = 13
    Caption = 'Codigo(s)'
  end
  object Label11: TLabel
    Left = 8
    Top = 398
    Width = 82
    Height = 13
    Caption = 'Precio de compra'
  end
  object Label12: TLabel
    Left = 121
    Top = 398
    Width = 88
    Height = 13
    Caption = 'Margen de utilidad'
  end
  object Label13: TLabel
    Left = 8
    Top = 329
    Width = 26
    Height = 13
    Caption = 'Stock'
  end
  object Label14: TLabel
    Left = 136
    Top = 471
    Width = 120
    Height = 13
    Caption = 'Vencimiento mas pr'#243'ximo'
  end
  object Label15: TLabel
    Left = 121
    Top = 329
    Width = 57
    Height = 13
    Caption = 'Stock cr'#237'tico'
  end
  object Label16: TLabel
    Left = 241
    Top = 398
    Width = 17
    Height = 13
    Caption = 'IVA'
  end
  object Label17: TLabel
    Left = 8
    Top = 8
    Width = 82
    Height = 25
    Caption = 'Label17'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label18: TLabel
    Left = 375
    Top = 181
    Width = 32
    Height = 13
    Caption = 'Dise'#241'o'
  end
  object Label19: TLabel
    Left = 8
    Top = 46
    Width = 44
    Height = 13
    Caption = 'Subrubro'
  end
  object cbTipo: TComboBox
    Left = 192
    Top = 128
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 2
    Text = 'CBTIPO'
    OnEnter = cbTipoEnter
    OnExit = cbTipoExit
  end
  object cbMarca: TComboBox
    Left = 375
    Top = 128
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 3
    Text = 'CBMARCA'
    OnEnter = cbMarcaEnter
    OnExit = cbMarcaExit
  end
  object cbModelo: TComboBox
    Left = 560
    Top = 128
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 4
    Text = 'CBMODELO'
    OnEnter = cbModeloEnter
    OnExit = cbModeloExit
  end
  object cbTamano: TComboBox
    Left = 8
    Top = 199
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 5
    Text = 'CBTAMANO'
    OnEnter = cbTamanoEnter
    OnExit = cbTamanoExit
  end
  object cbColor: TComboBox
    Left = 192
    Top = 199
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 6
    Text = 'CBCOLOR'
    OnEnter = cbColorEnter
    OnExit = cbColorExit
  end
  object cbCantidad: TComboBox
    Left = 193
    Top = 271
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 9
    Text = 'CBCANTIDAD'
    OnEnter = cbCantidadEnter
    OnExit = cbCantidadExit
  end
  object cbUnidadMedida: TComboBox
    Left = 8
    Top = 271
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 8
    Text = 'CBUNIDADMEDIDA'
    OnEnter = cbUnidadMedidaEnter
    OnExit = cbUnidadMedidaExit
  end
  object Edit1: TEdit
    Left = 237
    Top = 348
    Width = 486
    Height = 23
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Narrow'
    Font.Style = []
    MaxLength = 250
    ParentFont = False
    TabOrder = 12
    Text = 'Edit1'
  end
  object Memo1: TMemo
    Left = 8
    Top = 552
    Width = 712
    Height = 67
    CharCase = ecUpperCase
    Lines.Strings = (
      'MEMO1')
    MaxLength = 250
    TabOrder = 17
  end
  object Edit2: TEdit
    Left = 8
    Top = 417
    Width = 82
    Height = 21
    TabOrder = 18
    Text = 'Edit2'
    OnClick = Edit2Click
    OnEnter = Edit2Enter
    OnExit = Edit2Exit
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 121
    Top = 417
    Width = 82
    Height = 21
    TabOrder = 19
    Text = 'Edit3'
    OnClick = Edit3Click
    OnEnter = Edit3Enter
    OnExit = Edit3Exit
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 8
    Top = 348
    Width = 82
    Height = 21
    TabOrder = 10
    Text = 'Edit4'
  end
  object cbIVA: TComboBox
    Left = 241
    Top = 417
    Width = 64
    Height = 22
    Style = csOwnerDrawFixed
    TabOrder = 20
    Items.Strings = (
      '10,5 %'
      '21 %')
  end
  object DTP: TDateTimePicker
    Left = 136
    Top = 490
    Width = 177
    Height = 21
    Date = 44032.000000000000000000
    Time = 44032.000000000000000000
    TabOrder = 14
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 490
    Width = 120
    Height = 17
    Caption = 'Incluir Vencimiento'
    TabOrder = 13
    OnClick = CheckBox1Click
  end
  object Edit5: TEdit
    Left = 121
    Top = 348
    Width = 82
    Height = 21
    TabOrder = 11
    Text = 'Edit5'
  end
  object cbCategoria: TComboBox
    Left = 8
    Top = 129
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 10
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 1
    Text = 'CBCATEGORIA'
    OnEnter = cbCategoriaEnter
    OnExit = cbCategoriaExit
  end
  object cbDiseno: TComboBox
    Left = 375
    Top = 199
    Width = 160
    Height = 21
    AutoComplete = False
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 7
    Text = 'CBDISENO'
    OnEnter = cbDisenoEnter
    OnExit = cbDisenoExit
  end
  object cbSubRubro: TComboBox
    Left = 8
    Top = 65
    Width = 160
    Height = 22
    AutoCompleteDelay = 0
    AutoDropDown = True
    Style = csOwnerDrawFixed
    DropDownCount = 10
    MaxLength = 30
    Sorted = True
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 6
    Top = 625
    Width = 714
    Height = 32
    BevelOuter = bvNone
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 21
    object Button1: TButton
      AlignWithMargins = True
      Left = 549
      Top = 3
      Width = 120
      Height = 29
      Margins.Left = 45
      Margins.Bottom = 0
      Align = alLeft
      Caption = 'Salir'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 45
      Top = 3
      Width = 120
      Height = 29
      Margins.Left = 45
      Margins.Bottom = 0
      Align = alLeft
      Caption = 'Guardar'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      AlignWithMargins = True
      Left = 213
      Top = 3
      Width = 120
      Height = 29
      Margins.Left = 45
      Margins.Bottom = 0
      Align = alLeft
      Caption = 'Modificar otro'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      AlignWithMargins = True
      Left = 381
      Top = 3
      Width = 120
      Height = 29
      Margins.Left = 45
      Margins.Bottom = 0
      Align = alLeft
      Caption = 'Cancelar'
      TabOrder = 3
      OnClick = Button4Click
    end
  end
  object Button5: TButton
    Left = 204
    Top = 417
    Width = 20
    Height = 21
    Caption = '?'
    TabOrder = 22
    OnClick = Button5Click
  end
  object Panel6: TPanel
    Left = 488
    Top = 377
    Width = 235
    Height = 154
    BevelOuter = bvNone
    Caption = 'Panel6'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 16
    Visible = False
    object Label28: TLabel
      Left = 3
      Top = 23
      Width = 59
      Height = 13
      Caption = 'Proveedor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label29: TLabel
      Left = 3
      Top = 111
      Width = 92
      Height = 13
      Caption = 'Factor de escala'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label30: TLabel
      Left = 2
      Top = 2
      Width = 232
      Height = 19
      Alignment = taCenter
      AutoSize = False
      Caption = 'Asociar proveedor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label31: TLabel
      Left = 3
      Top = 68
      Width = 117
      Height = 13
      Caption = 'Codigo de proveedor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit9: TEdit
      Left = 3
      Top = 85
      Width = 167
      Height = 21
      MaxLength = 20
      TabOrder = 1
      Text = 'Edit9'
    end
    object Edit10: TEdit
      Left = 3
      Top = 127
      Width = 103
      Height = 21
      Alignment = taCenter
      TabOrder = 2
      Text = 'Edit10'
      OnExit = Edit10Exit
      OnKeyPress = Edit10KeyPress
    end
    object ComboBox3: TComboBox
      Left = 3
      Top = 40
      Width = 231
      Height = 22
      Style = csOwnerDrawFixed
      TabOrder = 0
    end
  end
  object CheckBox2: TCheckBox
    Left = 367
    Top = 492
    Width = 108
    Height = 17
    Caption = 'Asociar proveedor'
    TabOrder = 15
    OnClick = CheckBox2Click
  end
  object SQLConnection1: TSQLConnection
    ConnectionName = 'MySQLConnection'
    DriverName = 'MySQL'
    KeepConnection = False
    LoginPrompt = False
    Params.Strings = (
      'DriverName=MySQL'
      'HostName=localhost'
      'Database=dbsimple'
      'User_Name=root'
      'Password=CBR900rr'
      'ServerCharSet=utf8'
      'BlobSize=-1'
      'ErrorResourceFile='
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'ConnectTimeout=60')
    Left = 830
    Top = 80
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 830
    Top = 136
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer1Timer
    Left = 640
    Top = 184
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 830
    Top = 192
  end
end
