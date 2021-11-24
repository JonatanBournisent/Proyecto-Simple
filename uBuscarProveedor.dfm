object fBuscarProveedor: TfBuscarProveedor
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Buscar un proveedor'
  ClientHeight = 330
  ClientWidth = 961
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
    Top = 8
    Width = 105
    Height = 13
    Caption = 'Nombre o razon social'
  end
  object SpeedButton1: TSpeedButton
    Left = 376
    Top = 24
    Width = 161
    Height = 25
    Caption = 'Agregar un nuevo proveedor'
    Visible = False
    OnClick = SpeedButton1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 27
    Width = 233
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
    OnChange = Edit1Change
    OnEnter = Edit1Enter
    OnKeyDown = Edit1KeyDown
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 68
    Width = 945
    Height = 254
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
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
        FieldName = 'idProveedor'
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
        Width = 222
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'domicilio'
        Title.Alignment = taCenter
        Title.Caption = 'Domicilio'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 187
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'telefono'
        Title.Alignment = taCenter
        Title.Caption = 'Tel'#233'fono'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'celular'
        Title.Alignment = taCenter
        Title.Caption = 'Celular'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cuit'
        Title.Alignment = taCenter
        Title.Caption = 'CUIT'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 95
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'email'
        Title.Alignment = taCenter
        Title.Caption = 'Email'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 158
        Visible = True
      end>
  end
  object CheckBox1: TCheckBox
    Left = 247
    Top = 29
    Width = 97
    Height = 17
    Caption = 'Ver todos'
    TabOrder = 2
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
    Left = 94
    Top = 256
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
    object CDSnombre: TWideStringField
      FieldName = 'nombre'
      Size = 70
    end
    object CDSdomicilio: TWideStringField
      FieldName = 'domicilio'
      Size = 45
    end
    object CDStelefono: TWideStringField
      FieldName = 'telefono'
      Size = 15
    end
    object CDScelular: TWideStringField
      FieldName = 'celular'
      Size = 15
    end
    object CDScuit: TWideStringField
      FieldName = 'cuit'
      Size = 13
    end
    object CDSemail: TWideStringField
      FieldName = 'email'
      Size = 50
    end
    object CDSidProveedor: TIntegerField
      FieldName = 'idProveedor'
      DisplayFormat = '0000'
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 414
    Top = 272
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 94
    Top = 312
  end
end
