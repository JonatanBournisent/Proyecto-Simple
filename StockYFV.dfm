object fStockYFV: TfStockYFV
  Left = 0
  Top = 0
  ActiveControl = SpinEdit2
  Caption = 'Ver stocks y fechas de vencimiento'
  ClientHeight = 661
  ClientWidth = 912
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
  object Label12: TLabel
    Left = 159
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Rubro'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 135
    Width = 896
    Height = 518
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
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
        FieldName = 'nombre'
        Title.Alignment = taCenter
        Title.Caption = 'Nombre'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 583
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
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'proximoVencimiento'
        Title.Alignment = taCenter
        Title.Caption = 'Pr'#243'ximo vencimiento'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 148
        Visible = True
      end>
  end
  object SpinEdit1: TSpinEdit
    Left = 160
    Top = 63
    Width = 50
    Height = 22
    MaxValue = 20
    MinValue = 0
    TabOrder = 1
    Value = 0
    OnChange = SpinEdit1Change
  end
  object SpinEdit2: TSpinEdit
    Left = 160
    Top = 97
    Width = 50
    Height = 22
    MaxValue = 20
    MinValue = 0
    TabOrder = 2
    Value = 0
    OnChange = SpinEdit2Change
  end
  object RG1: TRadioGroup
    Left = 8
    Top = 8
    Width = 145
    Height = 121
    Caption = 'Filtrar'
    Items.Strings = (
      'Todos...'
      'Stock menor o igual a...'
      'Stock igual a...')
    TabOrder = 3
    OnClick = RG1Click
  end
  object cbRubro: TComboBox
    Left = 159
    Top = 24
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    Style = csDropDownList
    DropDownCount = 10
    TabOrder = 4
    OnChange = cbRubroChange
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
    Left = 94
    Top = 256
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 94
    Top = 312
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 214
    Top = 272
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 318
    Top = 272
    object CDSidArticulo: TIntegerField
      FieldName = 'idArticulo'
      DisplayFormat = '00000'
    end
    object CDSnombre: TWideStringField
      FieldName = 'nombre'
      Size = 250
    end
    object CDSproximoVencimiento: TDateField
      FieldName = 'proximoVencimiento'
      OnGetText = CDSproximoVencimientoGetText
    end
    object CDSstock: TIntegerField
      FieldName = 'stock'
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 414
    Top = 272
  end
  object QueryCB: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 310
    Top = 136
  end
end
