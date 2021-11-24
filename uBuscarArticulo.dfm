object fBuscarArticulo: TfBuscarArticulo
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Buscar un articulo'
  ClientHeight = 686
  ClientWidth = 1339
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
    Top = 93
    Width = 47
    Height = 13
    Caption = 'Categoria'
  end
  object Label2: TLabel
    Left = 192
    Top = 93
    Width = 20
    Height = 13
    Caption = 'Tipo'
  end
  object Label3: TLabel
    Left = 375
    Top = 93
    Width = 29
    Height = 13
    Caption = 'Marca'
  end
  object Label4: TLabel
    Left = 560
    Top = 93
    Width = 34
    Height = 13
    Caption = 'Modelo'
  end
  object Label5: TLabel
    Left = 744
    Top = 93
    Width = 38
    Height = 13
    Caption = 'Tama'#241'o'
  end
  object Label6: TLabel
    Left = 8
    Top = 191
    Width = 25
    Height = 13
    Caption = 'Color'
  end
  object Label7: TLabel
    Left = 560
    Top = 191
    Width = 43
    Height = 13
    Caption = 'Cantidad'
  end
  object Label8: TLabel
    Left = 375
    Top = 191
    Width = 85
    Height = 13
    Caption = 'Unidad de medida'
  end
  object Label11: TLabel
    Left = 8
    Top = 289
    Width = 80
    Height = 13
    Caption = 'Filtrar por texto:'
  end
  object Label12: TLabel
    Left = 8
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Rubro'
  end
  object Label13: TLabel
    Left = 192
    Top = 191
    Width = 32
    Height = 13
    Caption = 'Dise'#241'o'
  end
  object Button3: TSpeedButton
    Left = 206
    Top = 30
    Width = 280
    Height = 25
    Caption = 'Agregar un nuevo art'#237'culo'
    OnClick = Button3Click
  end
  object Label18: TLabel
    Left = 8
    Top = 352
    Width = 37
    Height = 13
    Caption = 'Label18'
  end
  object Label19: TLabel
    Left = 319
    Top = 311
    Width = 113
    Height = 13
    Caption = '(al menos 3 caracteres)'
  end
  object Label23: TLabel
    Left = 200
    Top = 30
    Width = 592
    Height = 23
    Caption = 'Buscar el art'#237'culo deseado y seleccionar con doble clic o enter'
    Color = clWindow
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Edit2: TEdit
    Left = 8
    Top = 308
    Width = 305
    Height = 21
    TabOrder = 10
    Text = 'Edit2'
    OnChange = Edit2Change
    OnKeyDown = Edit2KeyDown
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 371
    Width = 1324
    Height = 307
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    PopupMenu = PopupMenu1
    TabOrder = 11
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnDblClick = DBGrid1DblClick
    OnKeyDown = DBGrid1KeyDown
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'idArticulo'
        Title.Alignment = taCenter
        Title.Caption = 'C'#243'digo'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'categoria'
        Title.Alignment = taCenter
        Title.Caption = 'Categor'#237'a'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 175
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'tipo'
        Title.Alignment = taCenter
        Title.Caption = 'Tipo'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 179
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'marca'
        Title.Alignment = taCenter
        Title.Caption = 'Marca'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'modelo'
        Title.Alignment = taCenter
        Title.Caption = 'Modelo'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 202
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'tamano'
        Title.Alignment = taCenter
        Title.Caption = 'Tama'#241'o'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 76
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'color'
        Title.Alignment = taCenter
        Title.Caption = 'Color'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 105
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'diseno'
        Title.Alignment = taCenter
        Title.Caption = 'Dise'#241'o'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 161
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cantidad'
        Title.Alignment = taCenter
        Title.Caption = 'Cantidad'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 91
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'unidadMedida'
        Title.Alignment = taCenter
        Title.Caption = 'U. Med.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 63
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'stock'
        Title.Alignment = taCenter
        Title.Caption = 'Stock'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end>
  end
  object cbCategoria: TComboBox
    Left = 8
    Top = 117
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 1
    Text = 'CBCATEGORIA'
    OnChange = cbCategoriaChange
  end
  object cbTipo: TComboBox
    Left = 192
    Top = 117
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 2
    Text = 'CBTIPO'
    OnChange = cbTipoChange
  end
  object cbMarca: TComboBox
    Left = 375
    Top = 117
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 3
    Text = 'CBMARCA'
    OnChange = cbMarcaChange
  end
  object cbModelo: TComboBox
    Left = 560
    Top = 117
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 4
    Text = 'CBMODELO'
    OnChange = cbModeloChange
  end
  object cbTamano: TComboBox
    Left = 744
    Top = 117
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 5
    Text = 'CBTAMANO'
    OnChange = cbTamanoChange
  end
  object cbColor: TComboBox
    Left = 8
    Top = 215
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 6
    Text = 'CBCOLOR'
    OnChange = cbColorChange
  end
  object cbCantidad: TComboBox
    Left = 560
    Top = 215
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 9
    Text = 'CBCANTIDAD'
    OnChange = cbCantidadChange
  end
  object cbUnidadMedida: TComboBox
    Left = 375
    Top = 215
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 8
    Text = 'CBUNIDADMEDIDA'
    OnChange = cbUnidadMedidaChange
  end
  object Panel1: TPanel
    Left = 1285
    Top = 5
    Width = 393
    Height = 190
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 12
    Visible = False
    object Label10: TLabel
      Left = 142
      Top = 72
      Width = 108
      Height = 14
      Caption = 'Unidades agregadas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 2
      Top = 12
      Width = 389
      Height = 37
      Alignment = taCenter
      AutoSize = False
      Caption = 'Label9'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 53
      Top = 151
      Width = 115
      Height = 25
      Caption = 'Actualizar stock'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 224
      Top = 151
      Width = 115
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 2
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 136
      Top = 91
      Width = 121
      Height = 27
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = 'Edit1'
      OnKeyPress = Edit1KeyPress
    end
  end
  object cbRubro: TComboBox
    Left = 8
    Top = 32
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    Style = csDropDownList
    DropDownCount = 10
    TabOrder = 0
    OnChange = cbRubroChange
  end
  object cbDiseno: TComboBox
    Left = 192
    Top = 215
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 7
    Text = 'CBDISENO'
    OnChange = cbDisenoChange
  end
  object Panel2: TPanel
    Left = 1285
    Top = 326
    Width = 375
    Height = 175
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 13
    Visible = False
    object Label14: TLabel
      Left = 140
      Top = 47
      Width = 100
      Height = 13
      Caption = 'Precio compra sin iva'
    end
    object Label21: TLabel
      Left = 4
      Top = 12
      Width = 364
      Height = 25
      Alignment = taCenter
      AutoSize = False
      Caption = 'Modificar precio de compra'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit3: TEdit
      Left = 137
      Top = 66
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 0
      Text = 'Edit3'
      OnClick = Edit3Click
      OnEnter = Edit3Enter
      OnExit = Edit3Exit
      OnKeyDown = Edit3KeyDown
      OnKeyPress = Edit3KeyPress
    end
    object Button4: TButton
      Left = 30
      Top = 109
      Width = 147
      Height = 25
      Caption = 'Actualizar precio de compra'
      TabOrder = 1
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 198
      Top = 109
      Width = 147
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 2
      OnClick = Button5Click
    end
  end
  object Panel3: TPanel
    Left = 1285
    Top = 189
    Width = 375
    Height = 175
    BorderStyle = bsSingle
    Caption = 'Panel1'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 14
    Visible = False
    object Label15: TLabel
      Left = 146
      Top = 47
      Width = 88
      Height = 13
      Caption = 'Margen de utilidad'
    end
    object Label22: TLabel
      Left = 3
      Top = 10
      Width = 364
      Height = 25
      Alignment = taCenter
      AutoSize = False
      Caption = 'Modificar margen de utilidad'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit4: TEdit
      Left = 137
      Top = 66
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 0
      Text = 'Edit4'
      OnClick = Edit4Click
      OnEnter = Edit4Enter
      OnExit = Edit4Exit
      OnKeyDown = Edit4KeyDown
      OnKeyPress = Edit4KeyPress
    end
    object Button6: TButton
      Left = 30
      Top = 109
      Width = 147
      Height = 25
      Caption = 'Actualizar margen de utilidad'
      TabOrder = 1
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 198
      Top = 109
      Width = 147
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 2
      OnClick = Button7Click
    end
  end
  object Panel4: TPanel
    Left = 744
    Top = 490
    Width = 491
    Height = 212
    BorderStyle = bsSingle
    Caption = 'Panel4'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 15
    Visible = False
    object Label16: TLabel
      Left = 83
      Top = 62
      Width = 93
      Height = 13
      Caption = 'Factor multiplicador'
    end
    object Label17: TLabel
      Left = 310
      Top = 62
      Width = 93
      Height = 13
      Caption = 'Factor multiplicador'
    end
    object Bevel1: TBevel
      Left = 20
      Top = 51
      Width = 218
      Height = 93
    end
    object Bevel2: TBevel
      Left = 248
      Top = 51
      Width = 219
      Height = 93
    end
    object Label20: TLabel
      Left = 2
      Top = 10
      Width = 482
      Height = 25
      Alignment = taCenter
      AutoSize = False
      Caption = 'Actualizaci'#243'n de valores de grupo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit5: TEdit
      Left = 77
      Top = 80
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 0
      Text = 'Edit5'
      OnExit = Edit5Exit
      OnKeyDown = Edit5KeyDown
      OnKeyPress = Edit5KeyPress
    end
    object Edit6: TEdit
      Left = 305
      Top = 80
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 2
      Text = 'Edit6'
      OnExit = Edit6Exit
      OnKeyDown = Edit6KeyDown
      OnKeyPress = Edit6KeyPress
    end
    object Button8: TButton
      Left = 31
      Top = 107
      Width = 197
      Height = 25
      Caption = 'Actualizar precio de compra'
      TabOrder = 1
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 259
      Top = 107
      Width = 197
      Height = 25
      Caption = 'Actualizar margen de utilidad'
      TabOrder = 3
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 110
      Top = 168
      Width = 259
      Height = 25
      Caption = 'Cerrar este cuadro'
      TabOrder = 4
      OnClick = Button10Click
    end
  end
  object Panel5: TPanel
    Left = 216
    Top = 422
    Width = 449
    Height = 193
    Caption = 'Panel5'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 16
    object Label24: TLabel
      Left = 47
      Top = 58
      Width = 103
      Height = 13
      Caption = 'Cantidad promocional'
    end
    object Label25: TLabel
      Left = 47
      Top = 102
      Width = 111
      Height = 13
      Caption = 'Descuento promocional'
    end
    object Label26: TLabel
      Left = 234
      Top = 98
      Width = 19
      Height = 19
      Caption = '%'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label27: TLabel
      Left = 0
      Top = 16
      Width = 449
      Height = 16
      Alignment = taCenter
      AutoSize = False
      Caption = 'Configuraci'#243'n de promoci'#243'n por cantidad de art'#237'culos pedidos'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Shape1: TShape
      Left = 24
      Top = 41
      Width = 401
      Height = 91
      Brush.Style = bsClear
    end
    object Button11: TButton
      Left = 22
      Top = 151
      Width = 120
      Height = 25
      Caption = 'Guardar cambios'
      TabOrder = 0
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 164
      Top = 151
      Width = 120
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 1
      OnClick = Button12Click
    end
    object Button13: TButton
      Left = 307
      Top = 151
      Width = 120
      Height = 25
      Caption = 'Eliminar promoci'#243'n'
      TabOrder = 2
      OnClick = Button13Click
    end
    object Edit7: TEdit
      Left = 167
      Top = 51
      Width = 61
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = 'Edit7'
      OnKeyPress = Edit7KeyPress
    end
    object Edit8: TEdit
      Left = 167
      Top = 95
      Width = 61
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = 'Edit8'
      OnExit = Edit8Exit
      OnKeyPress = Edit8KeyPress
    end
  end
  object Panel6: TPanel
    Left = 335
    Top = 390
    Width = 330
    Height = 257
    Caption = 'Panel6'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 17
    Visible = False
    object Label28: TLabel
      Left = 18
      Top = 50
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
      Left = 18
      Top = 165
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
      Left = 0
      Top = 16
      Width = 329
      Height = 23
      Alignment = taCenter
      AutoSize = False
      Caption = 'Asociar codigos de articulos de proveedor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label31: TLabel
      Left = 18
      Top = 107
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
    object Button14: TButton
      Left = 32
      Top = 224
      Width = 131
      Height = 25
      Caption = 'Guardar'
      TabOrder = 3
      OnClick = Button14Click
    end
    object Button15: TButton
      Left = 187
      Top = 224
      Width = 115
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 4
      OnClick = Button15Click
    end
    object Edit9: TEdit
      Left = 18
      Top = 124
      Width = 167
      Height = 21
      MaxLength = 20
      TabOrder = 1
      Text = 'Edit9'
    end
    object Edit10: TEdit
      Left = 18
      Top = 184
      Width = 103
      Height = 21
      Alignment = taCenter
      TabOrder = 2
      Text = 'Edit10'
      OnExit = Edit10Exit
      OnKeyPress = Edit10KeyPress
    end
    object ComboBox1: TComboBox
      Left = 18
      Top = 67
      Width = 231
      Height = 22
      Style = csOwnerDrawFixed
      TabOrder = 0
    end
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
    Left = 98
    Top = 634
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 162
    Top = 634
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 392
    Top = 634
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 312
    Top = 634
    object CDSidArticulo: TIntegerField
      FieldName = 'idArticulo'
      DisplayFormat = '00000'
    end
    object CDScategoria: TWideStringField
      FieldName = 'categoria'
      Size = 30
    end
    object CDStipo: TWideStringField
      FieldName = 'tipo'
      Size = 30
    end
    object CDSmarca: TWideStringField
      FieldName = 'marca'
      Size = 30
    end
    object CDSmodelo: TWideStringField
      FieldName = 'modelo'
      Size = 30
    end
    object CDStamano: TWideStringField
      FieldName = 'tamano'
      Size = 30
    end
    object CDScolor: TWideStringField
      FieldName = 'color'
      Size = 30
    end
    object CDSunidadMedida: TWideStringField
      FieldName = 'unidadMedida'
      Size = 30
    end
    object CDScantidad: TWideStringField
      FieldName = 'cantidad'
      Size = 0
    end
    object CDSdiseno: TWideStringField
      FieldName = 'diseno'
      Size = 30
    end
    object CDSstock: TIntegerField
      FieldName = 'stock'
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 232
    Top = 634
  end
  object QueryCB: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 138
    Top = 151
  end
  object PopupMenu1: TPopupMenu
    Left = 296
    Top = 584
    object Modificarstock1: TMenuItem
      Caption = 'Modificar stock'
      OnClick = Modificarstock1Click
    end
    object Actualizarprecio1: TMenuItem
      Caption = 'Modificar precio'
      OnClick = Actualizarprecio1Click
    end
    object Modificarmargendeganancia1: TMenuItem
      Caption = 'Modificar margen de ganancia'
      OnClick = Modificarmargendeganancia1Click
    end
    object Modificarpreciodegrupo1: TMenuItem
      Caption = 'Modificar precio de grupo'
      OnClick = Modificarpreciodegrupo1Click
    end
    object Modificarmargendeutilidaddegrupo1: TMenuItem
      Caption = 'Modificar margen de utilidad de grupo'
      OnClick = Modificarmargendeutilidaddegrupo1Click
    end
    object Actualizarvaloresdegrupo1: TMenuItem
      Caption = 'Actualizar valores de grupo'
      OnClick = Actualizarvaloresdegrupo1Click
    end
    object Verlistadeproveedores1: TMenuItem
      Caption = 'Agregar/Monificar proveedor'
      OnClick = Verlistadeproveedores1Click
    end
    object Configurarpromocin1: TMenuItem
      Caption = 'Configurar promoci'#243'n'
      OnClick = Configurarpromocin1Click
    end
    object Eliminarartculo1: TMenuItem
      Caption = 'Eliminar art'#237'culo'
      OnClick = Eliminarartculo1Click
    end
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 74
    Top = 151
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 210
    Top = 151
  end
end
