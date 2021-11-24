object fActualizarPrecios: TfActualizarPrecios
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Actualizar precios'
  ClientHeight = 754
  ClientWidth = 1271
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
  object Label11: TLabel
    Left = 73
    Top = 611
    Width = 93
    Height = 13
    Caption = 'Factor multiplicador'
  end
  object Label12: TLabel
    Left = 295
    Top = 611
    Width = 93
    Height = 13
    Caption = 'Factor multiplicador'
  end
  object Label2: TLabel
    Left = 192
    Top = 8
    Width = 20
    Height = 13
    Caption = 'Tipo'
  end
  object Label3: TLabel
    Left = 375
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Marca'
  end
  object Label4: TLabel
    Left = 560
    Top = 8
    Width = 34
    Height = 13
    Caption = 'Modelo'
  end
  object Label6: TLabel
    Left = 192
    Top = 136
    Width = 25
    Height = 13
    Caption = 'Color'
  end
  object Label7: TLabel
    Left = 375
    Top = 136
    Width = 43
    Height = 13
    Caption = 'Cantidad'
  end
  object Label8: TLabel
    Left = 560
    Top = 136
    Width = 85
    Height = 13
    Caption = 'Unidad de medida'
  end
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 29
    Height = 13
    Caption = 'Rubro'
  end
  object Label5: TLabel
    Left = 8
    Top = 136
    Width = 38
    Height = 13
    Caption = 'Tama'#241'o'
  end
  object Bevel1: TBevel
    Left = 8
    Top = 602
    Width = 218
    Height = 105
  end
  object Bevel2: TBevel
    Left = 232
    Top = 602
    Width = 219
    Height = 105
  end
  object Label9: TLabel
    Left = 8
    Top = 251
    Width = 54
    Height = 19
    Caption = 'Label9'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit2: TEdit
    Left = 68
    Top = 630
    Width = 105
    Height = 21
    TabOrder = 0
    Text = 'Edit2'
    OnClick = Edit2Click
    OnExit = Edit2Exit
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 289
    Top = 630
    Width = 105
    Height = 21
    TabOrder = 1
    Text = 'Edit3'
    OnClick = Edit3Click
    OnExit = Edit3Exit
    OnKeyPress = Edit3KeyPress
  end
  object Button1: TButton
    Left = 19
    Top = 672
    Width = 197
    Height = 25
    Caption = 'Actualizar precio de compra'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 243
    Top = 672
    Width = 197
    Height = 25
    Caption = 'Actualizar margen de utilidad'
    TabOrder = 3
    OnClick = Button2Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 276
    Width = 1253
    Height = 307
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    PopupMenu = PopupMenu1
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'rubro'
        Title.Alignment = taCenter
        Title.Caption = 'Rubro'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 151
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
        Width = 151
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
        Width = 151
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
        Width = 151
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
        Width = 151
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
        Width = 151
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cantidad'
        Title.Alignment = taCenter
        Title.Caption = 'Cantidad'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 151
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'unidadMedida'
        Title.Alignment = taCenter
        Title.Caption = 'Unidad de Medida'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 151
        Visible = True
      end>
  end
  object cbRubro: TComboBox
    Left = 8
    Top = 32
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 5
    Text = 'CBRUBRO'
    OnChange = cbRubroChange
  end
  object cbTipo: TComboBox
    Left = 192
    Top = 32
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 6
    Text = 'CBTIPO'
    OnChange = cbTipoChange
  end
  object cbMarca: TComboBox
    Left = 375
    Top = 32
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 7
    Text = 'CBMARCA'
    OnChange = cbMarcaChange
  end
  object cbModelo: TComboBox
    Left = 560
    Top = 32
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 8
    Text = 'CBMODELO'
    OnChange = cbModeloChange
  end
  object cbTamano: TComboBox
    Left = 8
    Top = 160
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 9
    Text = 'CBTAMANO'
    OnChange = cbTamanoChange
  end
  object cbColor: TComboBox
    Left = 192
    Top = 160
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 10
    Text = 'CBCOLOR'
    OnChange = cbColorChange
  end
  object cbCantidad: TComboBox
    Left = 375
    Top = 160
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 11
    Text = 'CBCANTIDAD'
    OnChange = cbCantidadChange
  end
  object cbUnidadMedida: TComboBox
    Left = 560
    Top = 160
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    DropDownCount = 10
    Sorted = True
    TabOrder = 12
    Text = 'CBUNIDADMEDIDA'
    OnChange = cbUnidadMedidaChange
  end
  object Panel1: TPanel
    Left = 360
    Top = 295
    Width = 375
    Height = 175
    Caption = 'Panel1'
    Color = 16771827
    ParentBackground = False
    ShowCaption = False
    TabOrder = 13
    Visible = False
    object Label10: TLabel
      Left = 146
      Top = 47
      Width = 82
      Height = 13
      Caption = 'Precio de compra'
    end
    object Edit1: TEdit
      Left = 137
      Top = 66
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 0
      Text = 'Edit2'
      OnClick = Edit1Click
      OnEnter = Edit1Enter
      OnExit = Edit1Exit
      OnKeyDown = Edit1KeyDown
      OnKeyPress = Edit1KeyPress
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
  object Panel2: TPanel
    Left = 521
    Top = 476
    Width = 375
    Height = 175
    Caption = 'Panel1'
    Color = 16771827
    ParentBackground = False
    ShowCaption = False
    TabOrder = 14
    Visible = False
    object Label13: TLabel
      Left = 146
      Top = 47
      Width = 88
      Height = 13
      Caption = 'Margen de utilidad'
    end
    object Edit4: TEdit
      Left = 137
      Top = 66
      Width = 105
      Height = 21
      Alignment = taCenter
      TabOrder = 0
      Text = 'Edit2'
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
    Left = 274
    Top = 465
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 338
    Top = 465
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 568
    Top = 465
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 488
    Top = 465
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 408
    Top = 465
  end
  object QueryCB: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 858
    Top = 90
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 858
    Top = 218
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 5
    OnTimer = Timer1Timer
    Left = 856
    Top = 176
  end
  object PopupMenu1: TPopupMenu
    Left = 704
    Top = 432
    object Actualizarprecio1: TMenuItem
      Caption = 'Actualizar precio'
      OnClick = Actualizarprecio1Click
    end
    object Actualizarmargendeganancia1: TMenuItem
      Caption = 'Actualizar margen de ganancia'
      OnClick = Actualizarmargendeganancia1Click
    end
  end
end
