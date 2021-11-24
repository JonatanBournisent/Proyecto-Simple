object fControlDePrecios: TfControlDePrecios
  Left = 0
  Top = 0
  Caption = 'Control masivo de precios'
  ClientHeight = 634
  ClientWidth = 1291
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
  object Label4: TLabel
    Left = 210
    Top = 610
    Width = 104
    Height = 13
    Caption = 'Filtrar por proveedor:'
  end
  object Label5: TLabel
    Left = 528
    Top = 610
    Width = 80
    Height = 13
    Caption = 'Filtrar por rubro:'
  end
  object CheckBox2: TCheckBox
    Left = 960
    Top = 607
    Width = 145
    Height = 17
    Caption = 'Habilitar cambio de stock'
    TabOrder = 9
    OnClick = CheckBox2Click
  end
  object ComboBox2: TComboBox
    Left = 614
    Top = 607
    Width = 145
    Height = 21
    TabOrder = 6
    Text = 'ComboBox2'
    OnChange = ComboBox2Change
  end
  object ComboBox1: TComboBox
    Left = 320
    Top = 607
    Width = 145
    Height = 21
    TabOrder = 5
    Text = 'ComboBox1'
    OnClick = ComboBox1Click
  end
  object DBGrid1: TDBGrid
    Left = 2
    Top = 8
    Width = 1286
    Height = 593
    DataSource = DataSource1
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'idArticulo'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'C'#243'digo Int.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'nombre'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'Art'#237'culo'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 664
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'nombreProv'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'Proveedor'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 153
        Visible = True
      end
      item
        Alignment = taRightJustify
        Expanded = False
        FieldName = 'codigoProv'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'C'#243'digo prov.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'escala'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'Escala'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'precioCompra'
        Title.Alignment = taCenter
        Title.Caption = 'Precio Unitario'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 104
        Visible = True
      end
      item
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
  object Button3: TButton
    Left = 8
    Top = 605
    Width = 154
    Height = 25
    Caption = 'Control de precios "El Once"'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button6: TButton
    Left = 576
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Exportar'
    TabOrder = 3
    Visible = False
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 720
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Importar'
    TabOrder = 4
    Visible = False
    OnClick = Button7Click
  end
  object Panel6: TPanel
    Left = 478
    Top = 115
    Width = 330
    Height = 257
    Caption = 'Panel6'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 7
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
      Top = 181
      Width = 103
      Height = 21
      Alignment = taCenter
      TabOrder = 2
      Text = 'Edit10'
      OnExit = Edit10Exit
      OnKeyPress = Edit10KeyPress
    end
    object ComboBox3: TComboBox
      Left = 18
      Top = 67
      Width = 231
      Height = 22
      Style = csOwnerDrawFixed
      TabOrder = 0
    end
  end
  object CheckBox1: TCheckBox
    Left = 1129
    Top = 607
    Width = 161
    Height = 17
    Caption = 'Habilitar cambio de precios'
    TabOrder = 8
    OnClick = CheckBox1Click
  end
  object Panel1: TPanel
    Left = 1072
    Top = 80
    Width = 1288
    Height = 622
    Caption = 'Panel1'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 185
      Height = 13
      Caption = 'Posici'#243'n del c'#243'digo (comienza desde 1)'
    end
    object Label2: TLabel
      Left = 16
      Top = 43
      Width = 183
      Height = 13
      Caption = 'Posici'#243'n del precio (comienza desde 1)'
    end
    object Label3: TLabel
      Left = 16
      Top = 70
      Width = 154
      Height = 13
      Caption = 'Descuento sobre lista importada'
    end
    object Button1: TButton
      Left = 328
      Top = 11
      Width = 121
      Height = 77
      Caption = 'Importar lista'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 207
      Top = 13
      Width = 50
      Height = 21
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '1'
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 207
      Top = 40
      Width = 50
      Height = 21
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = '4'
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 205
      Top = 67
      Width = 52
      Height = 21
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = '7,84 %'
      OnEnter = Edit3Enter
      OnExit = Edit3Exit
      OnKeyPress = Edit3KeyPress
    end
    object DBGrid2: TDBGrid
      Left = 16
      Top = 104
      Width = 1257
      Height = 481
      DataSource = DataSource2
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 4
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnDrawColumnCell = DBGrid2DrawColumnCell
      OnKeyPress = DBGrid2KeyPress
      Columns = <
        item
          Alignment = taLeftJustify
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
          FieldName = 'nombre'
          Title.Alignment = taCenter
          Title.Caption = 'Nombre'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 921
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'precioActual'
          Title.Alignment = taCenter
          Title.Caption = 'Precio Actual'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 106
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'precioProv'
          Title.Alignment = taCenter
          Title.Caption = 'Precio proveedor'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 126
          Visible = True
        end>
    end
    object Button2: TButton
      Left = 496
      Top = 591
      Width = 209
      Height = 25
      Caption = 'Cerrar'
      TabOrder = 5
      OnClick = Button2Click
    end
    object Button4: TButton
      Left = 111
      Top = 591
      Width = 218
      Height = 25
      Caption = 'Actualizar todos los precios'
      TabOrder = 6
      OnClick = Button4Click
    end
    object ChB: TCheckBox
      Left = 832
      Top = 599
      Width = 161
      Height = 17
      Caption = 'Cambiar valor al presionar "+"'
      TabOrder = 7
    end
    object Button5: TButton
      Left = 480
      Top = 31
      Width = 169
      Height = 25
      Caption = 'Estimar aumento promedio'
      TabOrder = 8
      OnClick = Button5Click
    end
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 870
    Top = 112
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
    Left = 862
    Top = 32
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 918
    Top = 112
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 958
    Top = 112
    object CDSnombre: TWideStringField
      FieldName = 'nombre'
      Size = 250
    end
    object CDSidArticulo: TIntegerField
      Alignment = taCenter
      FieldName = 'idArticulo'
      DisplayFormat = '00000'
    end
    object CDSnombreProv: TWideStringField
      FieldName = 'nombreProv'
      Size = 45
    end
    object CDScodigoProv: TWideStringField
      FieldName = 'codigoProv'
      OnChange = CDScodigoProvChange
    end
    object CDSrefProveedor: TLargeintField
      FieldName = 'refProveedor'
    end
    object CDSescala: TFMTBCDField
      FieldName = 'escala'
      OnChange = CDSescalaChange
      DisplayFormat = '0.00'
      Size = 10
    end
    object CDSprecioCompra: TFMTBCDField
      FieldName = 'precioCompra'
      OnChange = CDSprecioCompraChange
      DisplayFormat = '$ 0.00'
      EditFormat = '0.00'
      Size = 10
    end
    object CDSstock: TIntegerField
      FieldName = 'stock'
      OnChange = CDSstockChange
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 1014
    Top = 112
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 462
    Top = 352
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 534
    Top = 360
  end
  object OD1: TOpenDialog
    Filter = 'Archivos CSV|*.csv'
    Left = 352
    Top = 80
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 470
    Top = 96
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query2
    Left = 518
    Top = 96
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    Left = 558
    Top = 96
    object WideStringField1: TWideStringField
      FieldName = 'nombre'
      Size = 250
    end
    object IntegerField1: TIntegerField
      FieldName = 'idArticulo'
      DisplayFormat = '00000'
    end
    object WideStringField2: TWideStringField
      FieldName = 'nombreProv'
      Size = 45
    end
    object WideStringField3: TWideStringField
      FieldName = 'codigoProv'
      OnChange = CDScodigoProvChange
    end
    object FMTBCDField1: TFMTBCDField
      FieldName = 'escala'
      OnChange = CDSescalaChange
      DisplayFormat = '0.00'
      Size = 10
    end
    object CDS2precioActual: TFMTBCDField
      FieldName = 'precioActual'
      DisplayFormat = '$ 0.00'
      Size = 12
    end
    object CDS2precioProv: TFMTBCDField
      FieldName = 'precioProv'
      DisplayFormat = '$ 0.00'
      Size = 12
    end
    object CDS2refProveedor: TLargeintField
      FieldName = 'refProveedor'
    end
  end
  object DataSource2: TDataSource
    DataSet = CDS2
    Left = 614
    Top = 96
  end
  object PopupMenu1: TPopupMenu
    Left = 48
    Top = 224
    object AsociarCambiarproveedor1: TMenuItem
      Caption = 'Asociar/Cambiar proveedor'
      OnClick = AsociarCambiarproveedor1Click
    end
  end
end
