object fSeleccionarArticulo: TfSeleccionarArticulo
  Left = 0
  Top = 0
  Caption = 'Consultar precios'
  ClientHeight = 528
  ClientWidth = 1332
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
  object Shape2: TShape
    Left = 8
    Top = 352
    Width = 186
    Height = 81
    Brush.Style = bsClear
  end
  object Shape1: TShape
    Left = 8
    Top = 447
    Width = 664
    Height = 73
    Brush.Style = bsClear
  end
  object Label11: TLabel
    Left = 187
    Top = 459
    Width = 137
    Height = 13
    Caption = 'Precio de compra sin iva'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 351
    Top = 459
    Width = 105
    Height = 13
    Caption = 'Margen de utilidad'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label16: TLabel
    Left = 515
    Top = 459
    Width = 20
    Height = 13
    Caption = 'IVA'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 459
    Width = 127
    Height = 13
    Caption = 'Precio de venta sin iva'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 21
    Top = 364
    Width = 131
    Height = 13
    Caption = 'Precio de venta con iva'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit2: TEdit
    Left = 8
    Top = 8
    Width = 400
    Height = 21
    TabOrder = 0
    OnChange = Edit2Change
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 35
    Width = 1318
    Height = 307
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnTitleClick = DBGrid1TitleClick
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
        FieldName = 'categoria'
        Title.Alignment = taCenter
        Title.Caption = 'Categor'#237'a'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 186
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
        Width = 117
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
        Title.Caption = 'U. de Medida'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 90
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
  object DBEdit1: TDBEdit
    Left = 187
    Top = 478
    Width = 137
    Height = 27
    DataField = 'precioCompra'
    DataSource = DataSource1
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnEnter = DBEdit1Enter
    OnExit = DBEdit1Exit
    OnKeyPress = DBEdit1KeyPress
  end
  object DBEdit2: TDBEdit
    Left = 351
    Top = 478
    Width = 137
    Height = 27
    DataField = 'margenUtilidad'
    DataSource = DataSource1
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
  end
  object DBEdit3: TDBEdit
    Left = 24
    Top = 478
    Width = 137
    Height = 27
    DataField = 'precioVenta'
    DataSource = DataSource1
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
  end
  object DBEdit4: TDBEdit
    Left = 21
    Top = 383
    Width = 159
    Height = 37
    DataField = 'precioVentaCIVA'
    DataSource = DataSource1
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    TabOrder = 5
  end
  object DBEdit5: TDBEdit
    Left = 515
    Top = 478
    Width = 136
    Height = 27
    DataField = 'iva'
    DataSource = DataSource1
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnExit = DBEdit5Exit
    OnKeyPress = DBEdit5KeyPress
  end
  object CheckBox1: TCheckBox
    Left = 565
    Top = 455
    Width = 67
    Height = 17
    Caption = 'Modificar'
    TabOrder = 7
    Visible = False
    OnClick = CheckBox1Click
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
    Left = 708
    Top = 112
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 772
    Top = 112
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 1002
    Top = 112
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 922
    Top = 112
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
    object CDSdiseno: TWideStringField
      FieldName = 'diseno'
      Size = 30
    end
    object CDScantidad: TWideStringField
      FieldName = 'cantidad'
      Size = 30
    end
    object CDSunidadMedida: TWideStringField
      FieldName = 'unidadMedida'
      Size = 30
    end
    object CDSstock: TIntegerField
      FieldName = 'stock'
    end
    object CDSprecioCompra: TFMTBCDField
      FieldName = 'precioCompra'
      OnChange = CDSprecioCompraChange
      DisplayFormat = '$ 0.00'
      EditFormat = '0.00'
    end
    object CDSmargenUtilidad: TFMTBCDField
      FieldName = 'margenUtilidad'
      OnChange = CDSmargenUtilidadChange
      DisplayFormat = '0.00 %'
      EditFormat = '0.00'
    end
    object CDSiva: TFMTBCDField
      FieldName = 'iva'
      OnChange = CDSivaChange
      DisplayFormat = '0.00 %'
      EditFormat = '0.00'
      Size = 5
    end
    object CDSprecioVenta: TFMTBCDField
      FieldName = 'precioVenta'
      DisplayFormat = '$ 0.00'
    end
    object CDSprecioVentaCIVA: TFMTBCDField
      FieldName = 'precioVentaCIVA'
      DisplayFormat = '$ 0.00'
      Size = 10
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 842
    Top = 112
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 764
    Top = 168
  end
end
