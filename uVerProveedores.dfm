object fVerProveedores: TfVerProveedores
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Lista de proveedores asignados'
  ClientHeight = 304
  ClientWidth = 1082
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
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 1065
    Height = 257
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    Columns = <
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
        Width = 246
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
        Width = 207
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
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'codigo'
        Title.Alignment = taCenter
        Title.Caption = 'C'#243'digo asignado'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 134
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'precio'
        Title.Alignment = taCenter
        Title.Caption = 'Precio'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 67
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 208
    Top = 271
    Width = 169
    Height = 25
    Caption = 'Asisgnar un nuevo proveedor'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 328
    Top = 56
    Width = 369
    Height = 169
    Color = 10790143
    ParentBackground = False
    ShowCaption = False
    TabOrder = 2
    object Label2: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 21
      Width = 361
      Height = 13
      Margins.Top = 20
      Align = alTop
      Alignment = taCenter
      AutoSize = False
      Caption = 'Indicar el c'#243'digo que este proveedor asigna al art'#237'culo'
      ExplicitTop = 22
    end
    object Label3: TLabel
      Left = 88
      Top = 77
      Width = 200
      Height = 13
      Caption = 'Factor de escala para adaptar cantidades'
    end
    object Edit1: TEdit
      Left = 108
      Top = 41
      Width = 153
      Height = 21
      Alignment = taCenter
      MaxLength = 20
      TabOrder = 0
    end
    object Button2: TButton
      Left = 1
      Top = 143
      Width = 367
      Height = 25
      Align = alBottom
      Caption = 'Agregar'
      TabOrder = 2
      OnClick = Button2Click
    end
    object Edit3: TEdit
      Left = 136
      Top = 96
      Width = 97
      Height = 21
      Alignment = taCenter
      TabOrder = 1
      Text = 'Edit3'
      OnExit = Edit3Exit
      OnKeyPress = Edit3KeyPress
    end
  end
  object Button3: TButton
    Left = 616
    Top = 271
    Width = 169
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = Button3Click
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
    Left = 205
    Top = 52
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 205
    Top = 108
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 117
    Top = 172
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 189
    Top = 172
    object CDS1nombre: TWideStringField
      FieldName = 'nombre'
    end
    object CDS1domicilio: TWideStringField
      FieldName = 'domicilio'
      Size = 0
    end
    object CDS1telefono: TWideStringField
      FieldName = 'telefono'
    end
    object CDS1celular: TWideStringField
      FieldName = 'celular'
    end
    object CDS1cuit: TWideStringField
      FieldName = 'cuit'
    end
    object CDS1idRelacionProveedor: TIntegerField
      FieldName = 'idRelacionProveedor'
    end
    object CDS1codigo: TWideStringField
      DisplayWidth = 20
      FieldName = 'codigo'
      Size = 0
    end
    object CDS1precio: TFMTBCDField
      FieldName = 'precio'
      DisplayFormat = '$ 0.00'
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 237
    Top = 180
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 108
    Top = 109
  end
  object PopupMenu1: TPopupMenu
    Left = 768
    Top = 118
    object Quitaresteproveedordelalista1: TMenuItem
      Caption = 'Quitar este proveedor de la lista'
      OnClick = Quitaresteproveedordelalista1Click
    end
  end
end
