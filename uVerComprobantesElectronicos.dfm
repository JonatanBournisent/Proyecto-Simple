object fVerComprobantesElectronicos: TfVerComprobantesElectronicos
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Ver ComprobantesElectronicos'
  ClientHeight = 675
  ClientWidth = 1091
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
    Left = 568
    Top = 8
    Width = 517
    Height = 201
    Brush.Style = bsClear
  end
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 529
    Height = 202
    Brush.Style = bsClear
  end
  object Label1: TLabel
    Left = 40
    Top = 14
    Width = 146
    Height = 14
    Alignment = taCenter
    AutoSize = False
    Caption = 'Filtrar por N'#176' de Comp.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 238
    Top = 14
    Width = 251
    Height = 14
    Alignment = taCenter
    AutoSize = False
    Caption = 'Filtrar por fecha informada'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label12: TLabel
    Left = 583
    Top = 22
    Width = 29
    Height = 13
    Caption = 'Rubro'
  end
  object Label2: TLabel
    Left = 583
    Top = 73
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Label4: TLabel
    Left = 583
    Top = 95
    Width = 31
    Height = 13
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 583
    Top = 117
    Width = 31
    Height = 13
    Caption = 'Label5'
  end
  object Label6: TLabel
    Left = 583
    Top = 139
    Width = 31
    Height = 13
    Caption = 'Label6'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 215
    Width = 1076
    Height = 451
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
        Alignment = taCenter
        Expanded = False
        FieldName = 'nroComp'
        Title.Alignment = taCenter
        Title.Caption = 'Recibo N'#176
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 109
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'tipoComp'
        Title.Alignment = taCenter
        Title.Caption = 'Tipo Comp.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 80
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'fecha'
        Title.Alignment = taCenter
        Title.Caption = 'Fecha'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 85
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cliente'
        Title.Alignment = taCenter
        Title.Caption = 'Cliente'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 168
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cuitCliente'
        Title.Alignment = taCenter
        Title.Caption = 'CUIT'
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
        FieldName = 'cfIVA'
        Title.Alignment = taCenter
        Title.Caption = 'Cond. Frente IVA'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'netoGravado'
        Title.Alignment = taCenter
        Title.Caption = 'Neto Gravado'
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
        FieldName = 'iva105'
        Title.Alignment = taCenter
        Title.Caption = 'IVA 10,5%'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 86
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'iva21'
        Title.Alignment = taCenter
        Title.Caption = 'IVA 21%'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 92
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'final'
        Title.Alignment = taCenter
        Title.Caption = 'TOTAL'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 100
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 40
    Top = 33
    Width = 146
    Height = 27
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object MC1: TMonthCalendar
    Left = 238
    Top = 33
    Width = 251
    Height = 160
    MultiSelect = True
    Date = 44056.460736539350000000
    EndDate = 44056.000000000000000000
    MaxSelectRange = 500
    TabOrder = 2
    OnClick = MC1Click
  end
  object Button1: TButton
    Left = 40
    Top = 92
    Width = 146
    Height = 25
    Caption = 'Filtrar por cliente'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 152
    Width = 146
    Height = 25
    Caption = 'Restablecer'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 583
    Top = 168
    Width = 160
    Height = 25
    Caption = 'Calcular / actualizar'
    TabOrder = 5
    OnClick = Button3Click
  end
  object cbRubro: TComboBox
    Left = 583
    Top = 38
    Width = 160
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    Style = csDropDownList
    DropDownCount = 10
    TabOrder = 6
    OnChange = cbRubroChange
  end
  object MC2: TMonthCalendar
    Left = 833
    Top = 33
    Width = 247
    Height = 160
    MultiSelect = True
    Date = 44151.460736550930000000
    EndDate = 44151.000000000000000000
    MaxSelectRange = 500
    TabOrder = 7
    OnClick = MC2Click
  end
  object Panel1: TPanel
    Left = 256
    Top = 279
    Width = 568
    Height = 357
    Caption = 'Panel1'
    Color = 12568831
    ParentBackground = False
    ShowCaption = False
    TabOrder = 8
    object Label7: TLabel
      Left = 384
      Top = 187
      Width = 90
      Height = 13
      Caption = 'Neto Gravado: $'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 384
      Top = 220
      Width = 63
      Height = 13
      Caption = 'IVA 21%: $'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 384
      Top = 253
      Width = 73
      Height = 13
      Caption = 'IVA 10,5%: $'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 384
      Top = 291
      Width = 49
      Height = 13
      Caption = 'TOTAL: $'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 12
      Top = 72
      Width = 541
      Height = 14
      Alignment = taCenter
      AutoSize = False
      Caption = 'Descripci'#243'n'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 12
      Top = 41
      Width = 48
      Height = 14
      Caption = 'Label13'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 270
      Top = 20
      Width = 135
      Height = 13
      Caption = 'Fecha del comprobante:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DTP: TDateTimePicker
      Left = 412
      Top = 17
      Width = 141
      Height = 21
      Date = 44206.660138437500000000
      Time = 44206.660138437500000000
      TabOrder = 0
    end
    object Memo1: TMemo
      Left = 12
      Top = 92
      Width = 545
      Height = 73
      Lines.Strings = (
        'Memo1')
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 482
      Top = 184
      Width = 75
      Height = 21
      Alignment = taRightJustify
      TabOrder = 2
      Text = '0,00'
      OnChange = Edit2Change
      OnExit = Edit2Exit
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 482
      Top = 217
      Width = 75
      Height = 21
      Alignment = taRightJustify
      TabOrder = 3
      Text = '0,00'
      OnChange = Edit3Change
      OnExit = Edit3Exit
      OnKeyPress = Edit3KeyPress
    end
    object Edit4: TEdit
      Left = 482
      Top = 250
      Width = 75
      Height = 21
      Alignment = taRightJustify
      TabOrder = 4
      Text = '0,00'
      OnChange = Edit4Change
      OnExit = Edit4Exit
      OnKeyPress = Edit4KeyPress
    end
    object Edit5: TEdit
      Left = 482
      Top = 288
      Width = 75
      Height = 21
      Alignment = taRightJustify
      ReadOnly = True
      TabOrder = 5
      Text = '0,00'
    end
    object Button4: TButton
      Left = 88
      Top = 324
      Width = 145
      Height = 25
      Caption = 'Generar Nota de Cr'#233'dito'
      TabOrder = 6
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 328
      Top = 324
      Width = 145
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 7
      OnClick = Button5Click
    end
    object CheckBox1: TCheckBox
      Left = 12
      Top = 290
      Width = 97
      Height = 17
      Caption = 'Imprimir en PDF'
      TabOrder = 8
    end
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 376
    Top = 384
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 440
    Top = 384
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    ReadOnly = True
    Left = 488
    Top = 384
    object CDS1idComprobanteElectronico: TIntegerField
      FieldName = 'idComprobanteElectronico'
    end
    object CDS1cliente: TWideStringField
      FieldName = 'cliente'
      Size = 40
    end
    object CDS1cuitCliente: TWideStringField
      FieldName = 'cuitCliente'
      OnGetText = CDS1cuitClienteGetText
      Size = 13
    end
    object CDS1cfIVA: TWideStringField
      FieldName = 'cfIVA'
    end
    object CDS1fecha: TDateField
      FieldName = 'fecha'
    end
    object CDS1tipoComp: TWideStringField
      FieldName = 'tipoComp'
      Size = 15
    end
    object CDS1nroComp: TWideStringField
      FieldName = 'nroComp'
      Size = 15
    end
    object CDS1netoGravado: TFMTBCDField
      FieldName = 'netoGravado'
      DisplayFormat = '$ #,##0.00'
      Size = 12
    end
    object CDS1iva21: TFMTBCDField
      FieldName = 'iva21'
      DisplayFormat = '$ #,##0.00'
      Size = 12
    end
    object CDS1iva105: TFMTBCDField
      FieldName = 'iva105'
      DisplayFormat = '$ #,##0.00'
      Size = 10
    end
    object CDS1final: TFMTBCDField
      FieldName = 'final'
      DisplayFormat = '$ #,##0.00'
      Size = 15
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 528
    Top = 384
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
    Left = 322
    Top = 389
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 374
    Top = 344
  end
  object PopupMenu1: TPopupMenu
    Left = 160
    Top = 352
    object Eliminarestafactura1: TMenuItem
      Caption = 'Eliminar este registro'
      OnClick = Eliminarestafactura1Click
    end
    object AnularestecomprobanteEmitirNC1: TMenuItem
      Caption = 'Anular este comprobante (Emitir NC)'
      OnClick = AnularestecomprobanteEmitirNC1Click
    end
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 904
    Top = 32
  end
  object QueryCB: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 936
    Top = 32
  end
  object frxReport1: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    EngineOptions.DoublePass = True
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 44011.931234791700000000
    ReportOptions.LastChange = 44199.786370335600000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 240
    Top = 336
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 6.000000000000000000
      RightMargin = 6.000000000000000000
      TopMargin = 6.000000000000000000
      BottomMargin = 6.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Height = 94.488250000000000000
        Top = 714.331170000000000000
        Width = 748.346940000000000000
        object Memo26: TfrxMemoView
          AllowVectorExport = True
          Left = 578.031850000000000000
          Top = 71.811070000000000000
          Width = 162.519790000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            'P'#225'gina [Page] de [TotalPages]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object BarCode1: TfrxBarCodeView
          AllowVectorExport = True
          Left = 3.779530000000000000
          Top = 18.897650000000000000
          Width = 222.000000000000000000
          Height = 71.811070000000000000
          BarType = bcCode_2_5_interleaved
          CalcCheckSum = True
          Frame.Typ = []
          Rotation = 0
          TestLine = False
          Text = '12345678216515616156'
          WideBarRatio = 2.000000000000000000
          Zoom = 1.500000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          ColorBar = clBlack
        end
        object caeComp: TfrxMemoView
          AllowVectorExport = True
          Left = 417.850650000000000000
          Top = 7.559060000000000000
          Width = 317.480520000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            'CAE')
          ParentFont = False
        end
        object vencComp: TfrxMemoView
          AllowVectorExport = True
          Left = 417.850650000000000000
          Top = 34.015770000000000000
          Width = 317.480520000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            'venc')
          ParentFont = False
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Frame.Typ = []
        Height = 215.653680000000000000
        Top = 476.220780000000000000
        Width = 748.346940000000000000
        object frxShapeView1: TfrxShapeView
          AllowVectorExport = True
          Left = 0.338590000000000000
          Top = 22.559060000000000000
          Width = 748.346940000000000000
          Height = 185.196850390000000000
          Frame.Typ = []
        end
        object Memo27: TfrxMemoView
          AllowVectorExport = True
          Left = 440.472790000000000000
          Top = 33.220470000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          AllowVectorExport = True
          Left = 440.472790000000000000
          Top = 62.103958000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
        object Memo29: TfrxMemoView
          AllowVectorExport = True
          Left = 440.472790000000000000
          Top = 90.987446000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          AllowVectorExport = True
          Left = 440.637795280000000000
          Top = 119.870934000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          AllowVectorExport = True
          Left = 440.637795280000000000
          Top = 148.754422000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          AllowVectorExport = True
          Left = 440.637795280000000000
          Top = 177.637910000000000000
          Width = 294.803340000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          ParentFont = False
        end
      end
      object PageHeader1: TfrxPageHeader
        FillType = ftBrush
        Frame.Typ = []
        Height = 396.472475120000000000
        Top = 18.897650000000000000
        Width = 748.346940000000000000
        object Shape1: TfrxShapeView
          AllowVectorExport = True
          Left = 348.141930000000000000
          Top = 37.795300000000000000
          Width = 52.913420000000000000
          Height = 52.913420000000000000
          Frame.Typ = []
        end
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 414.275820000000000000
          Top = 51.574830000000000000
          Width = 260.787570000000000000
          Height = 34.015770000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -24
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'NOTA DE CR'#201'DITO')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 2.779530000000000000
          Top = 135.283550000000000000
          Width = 355.275820000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Raz'#243'n social: BOURNISSENT JONATAN ALEJANDRO')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 2.779530000000000000
          Top = 162.240260000000000000
          Width = 136.063080000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio comercial:')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 2.779530000000000000
          Top = 188.976500000000000000
          Width = 355.275820000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Condici'#243'n frente al IVA:   IVA Responsable Inscripto')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 414.496290000000000000
          Top = 150.811070000000000000
          Width = 253.228510000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'CUIT: 23-32376258-9')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 414.496290000000000000
          Top = 172.937075000000000000
          Width = 253.228510000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Ingresos Brutos: 011-179343-7')
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 414.496290000000000000
          Top = 195.063080000000000000
          Width = 279.685220000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Fecha de inicio de actividades: 11/07/2016')
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 427.575140000000000000
          Top = 231.685063780000000000
          Width = 321.259720470000000000
          Height = 18.897650000000000000
          AutoWidth = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'R Social')
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 40.795300000000000000
          Top = 231.685063780000000000
          Width = 151.181200000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'CUIT')
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 142.960730000000000000
          Top = 264.566953540000000000
          Width = 162.519790000000000000
          Height = 18.897637800000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'COND IVA')
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 381.614410000000000000
          Top = 264.566953540000000000
          Width = 366.614410000000000000
          Height = 18.897637800000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Top = 319.803340000000000000
          Width = 748.346940000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Descripci'#243'n')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Top = 313.582870000000000000
          Width = 748.346456690000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Left = 0.440940000000000000
          Top = 219.212740000000000000
          Width = 748.346456692913000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line3: TfrxLineView
          AllowVectorExport = True
          Left = 374.378170000000000000
          Top = 91.488250000000000000
          Height = 128.504020000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Memo19: TfrxMemoView
          AllowVectorExport = True
          Left = 2.220470000000000000
          Top = 231.685063780000000000
          Width = 38.929133860000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'CUIT:')
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          AllowVectorExport = True
          Left = 227.582870000000000000
          Top = 231.685063780000000000
          Width = 200.315090000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Apellido y Nombre / Raz'#243'n Social:')
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          AllowVectorExport = True
          Left = 2.220470000000000000
          Top = 264.566953540000000000
          Width = 139.842610000000000000
          Height = 18.897637800000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Condici'#243'n frente al IVA:')
          ParentFont = False
        end
        object Memo25: TfrxMemoView
          AllowVectorExport = True
          Left = 313.582870000000000000
          Top = 264.566953540000000000
          Width = 68.031540000000000000
          Height = 18.897637800000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio:')
          ParentFont = False
        end
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 80.472480000000000000
          Top = 55.472480000000000000
          Width = 192.755932360000000000
          Height = 71.811030940000000000
          Frame.Typ = []
          Picture.Data = {
            0A54504E474F626A65637489504E470D0A1A0A0000000D49484452000005D700
            00021908060000004457061A000000017352474200AECE1CE90000000467414D
            410000B18F0BFC6105000000097048597300002E2300002E230178A53F760000
            3EC369545874584D4C3A636F6D2E61646F62652E786D7000000000003C3F7870
            61636B657420626567696E3D22EFBBBF222069643D2257354D304D7043656869
            487A7265537A4E54637A6B633964223F3E0A3C783A786D706D65746120786D6C
            6E733A783D2261646F62653A6E733A6D6574612F2220783A786D70746B3D2241
            646F626520584D5020436F726520352E352D633032312037392E313535373732
            2C20323031342F30312F31332D31393A34343A30302020202020202020223E0A
            2020203C7264663A52444620786D6C6E733A7264663D22687474703A2F2F7777
            772E77332E6F72672F313939392F30322F32322D7264662D73796E7461782D6E
            7323223E0A2020202020203C7264663A4465736372697074696F6E207264663A
            61626F75743D22220A202020202020202020202020786D6C6E733A786D703D22
            687474703A2F2F6E732E61646F62652E636F6D2F7861702F312E302F220A2020
            20202020202020202020786D6C6E733A7064663D22687474703A2F2F6E732E61
            646F62652E636F6D2F7064662F312E332F220A20202020202020202020202078
            6D6C6E733A64633D22687474703A2F2F7075726C2E6F72672F64632F656C656D
            656E74732F312E312F220A202020202020202020202020786D6C6E733A786D70
            4D4D3D22687474703A2F2F6E732E61646F62652E636F6D2F7861702F312E302F
            6D6D2F220A202020202020202020202020786D6C6E733A73744576743D226874
            74703A2F2F6E732E61646F62652E636F6D2F7861702F312E302F73547970652F
            5265736F757263654576656E7423220A202020202020202020202020786D6C6E
            733A73745265663D22687474703A2F2F6E732E61646F62652E636F6D2F786170
            2F312E302F73547970652F5265736F7572636552656623220A20202020202020
            2020202020786D6C6E733A70686F746F73686F703D22687474703A2F2F6E732E
            61646F62652E636F6D2F70686F746F73686F702F312E302F220A202020202020
            202020202020786D6C6E733A746966663D22687474703A2F2F6E732E61646F62
            652E636F6D2F746966662F312E302F220A202020202020202020202020786D6C
            6E733A657869663D22687474703A2F2F6E732E61646F62652E636F6D2F657869
            662F312E302F223E0A2020202020202020203C786D703A437265617465446174
            653E323032302D30372D31355431393A32383A35352D30333A30303C2F786D70
            3A437265617465446174653E0A2020202020202020203C786D703A4372656174
            6F72546F6F6C3E41646F62652050686F746F73686F7020434320323031342028
            57696E646F7773293C2F786D703A43726561746F72546F6F6C3E0A2020202020
            202020203C786D703A4D6F64696679446174653E323032302D30392D31345431
            373A32353A34362D30333A30303C2F786D703A4D6F64696679446174653E0A20
            20202020202020203C786D703A4D65746164617461446174653E323032302D30
            392D31345431373A32353A34362D30333A30303C2F786D703A4D657461646174
            61446174653E0A2020202020202020203C7064663A50726F64756365723E436F
            72656C2050444620456E67696E652056657273696F6E2032312E302E302E3539
            333C2F7064663A50726F64756365723E0A2020202020202020203C64633A6372
            6561746F723E0A2020202020202020202020203C7264663A5365713E0A202020
            2020202020202020202020203C7264663A6C693E4252554E4F3C2F7264663A6C
            693E0A2020202020202020202020203C2F7264663A5365713E0A202020202020
            2020203C2F64633A63726561746F723E0A2020202020202020203C64633A7469
            746C653E0A2020202020202020202020203C7264663A416C743E0A2020202020
            202020202020202020203C7264663A6C6920786D6C3A6C616E673D22782D6465
            6661756C74223E53696D706C655F4D617263615F4578747261732E6364723C2F
            7264663A6C693E0A2020202020202020202020203C2F7264663A416C743E0A20
            20202020202020203C2F64633A7469746C653E0A2020202020202020203C6463
            3A666F726D61743E696D6167652F706E673C2F64633A666F726D61743E0A2020
            202020202020203C786D704D4D3A496E7374616E636549443E786D702E696964
            3A31656635646561372D303466382D383434622D626438312D39386164666437
            63363239633C2F786D704D4D3A496E7374616E636549443E0A20202020202020
            20203C786D704D4D3A446F63756D656E7449443E61646F62653A646F6369643A
            70686F746F73686F703A36613065386566662D663663382D313165612D383536
            652D6361313531343866343337383C2F786D704D4D3A446F63756D656E744944
            3E0A2020202020202020203C786D704D4D3A4F726967696E616C446F63756D65
            6E7449443E786D702E6469643A35636532646633622D636263302D333634382D
            626663302D6336376639626164343264353C2F786D704D4D3A4F726967696E61
            6C446F63756D656E7449443E0A2020202020202020203C786D704D4D3A486973
            746F72793E0A2020202020202020202020203C7264663A5365713E0A20202020
            20202020202020202020203C7264663A6C69207264663A706172736554797065
            3D225265736F75726365223E0A2020202020202020202020202020202020203C
            73744576743A616374696F6E3E73617665643C2F73744576743A616374696F6E
            3E0A2020202020202020202020202020202020203C73744576743A696E737461
            6E636549443E786D702E6969643A35636532646633622D636263302D33363438
            2D626663302D6336376639626164343264353C2F73744576743A696E7374616E
            636549443E0A2020202020202020202020202020202020203C73744576743A77
            68656E3E323032302D30392D31345431373A32353A34362D30333A30303C2F73
            744576743A7768656E3E0A2020202020202020202020202020202020203C7374
            4576743A736F6674776172654167656E743E41646F62652050686F746F73686F
            702043432032303134202857696E646F7773293C2F73744576743A736F667477
            6172654167656E743E0A2020202020202020202020202020202020203C737445
            76743A6368616E6765643E2F3C2F73744576743A6368616E6765643E0A202020
            2020202020202020202020203C2F7264663A6C693E0A20202020202020202020
            20202020203C7264663A6C69207264663A7061727365547970653D225265736F
            75726365223E0A2020202020202020202020202020202020203C73744576743A
            616374696F6E3E646572697665643C2F73744576743A616374696F6E3E0A2020
            202020202020202020202020202020203C73744576743A706172616D65746572
            733E636F6E7665727465642066726F6D206170706C69636174696F6E2F766E64
            2E61646F62652E70686F746F73686F7020746F20696D6167652F706E673C2F73
            744576743A706172616D65746572733E0A202020202020202020202020202020
            3C2F7264663A6C693E0A2020202020202020202020202020203C7264663A6C69
            207264663A7061727365547970653D225265736F75726365223E0A2020202020
            202020202020202020202020203C73744576743A616374696F6E3E7361766564
            3C2F73744576743A616374696F6E3E0A20202020202020202020202020202020
            20203C73744576743A696E7374616E636549443E786D702E6969643A31656635
            646561372D303466382D383434622D626438312D393861646664376336323963
            3C2F73744576743A696E7374616E636549443E0A202020202020202020202020
            2020202020203C73744576743A7768656E3E323032302D30392D31345431373A
            32353A34362D30333A30303C2F73744576743A7768656E3E0A20202020202020
            20202020202020202020203C73744576743A736F6674776172654167656E743E
            41646F62652050686F746F73686F702043432032303134202857696E646F7773
            293C2F73744576743A736F6674776172654167656E743E0A2020202020202020
            202020202020202020203C73744576743A6368616E6765643E2F3C2F73744576
            743A6368616E6765643E0A2020202020202020202020202020203C2F7264663A
            6C693E0A2020202020202020202020203C2F7264663A5365713E0A2020202020
            202020203C2F786D704D4D3A486973746F72793E0A2020202020202020203C78
            6D704D4D3A4465726976656446726F6D207264663A7061727365547970653D22
            5265736F75726365223E0A2020202020202020202020203C73745265663A696E
            7374616E636549443E786D702E6969643A35636532646633622D636263302D33
            3634382D626663302D6336376639626164343264353C2F73745265663A696E73
            74616E636549443E0A2020202020202020202020203C73745265663A646F6375
            6D656E7449443E786D702E6469643A35636532646633622D636263302D333634
            382D626663302D6336376639626164343264353C2F73745265663A646F63756D
            656E7449443E0A2020202020202020202020203C73745265663A6F726967696E
            616C446F63756D656E7449443E786D702E6469643A35636532646633622D6362
            63302D333634382D626663302D6336376639626164343264353C2F7374526566
            3A6F726967696E616C446F63756D656E7449443E0A2020202020202020203C2F
            786D704D4D3A4465726976656446726F6D3E0A2020202020202020203C70686F
            746F73686F703A436F6C6F724D6F64653E333C2F70686F746F73686F703A436F
            6C6F724D6F64653E0A2020202020202020203C70686F746F73686F703A494343
            50726F66696C653E735247422049454336313936362D322E313C2F70686F746F
            73686F703A49434350726F66696C653E0A2020202020202020203C746966663A
            4F7269656E746174696F6E3E313C2F746966663A4F7269656E746174696F6E3E
            0A2020202020202020203C746966663A585265736F6C7574696F6E3E33303030
            3030302F31303030303C2F746966663A585265736F6C7574696F6E3E0A202020
            2020202020203C746966663A595265736F6C7574696F6E3E333030303030302F
            31303030303C2F746966663A595265736F6C7574696F6E3E0A20202020202020
            20203C746966663A5265736F6C7574696F6E556E69743E323C2F746966663A52
            65736F6C7574696F6E556E69743E0A2020202020202020203C657869663A436F
            6C6F7253706163653E313C2F657869663A436F6C6F7253706163653E0A202020
            2020202020203C657869663A506978656C5844696D656E73696F6E3E31393139
            3C2F657869663A506978656C5844696D656E73696F6E3E0A2020202020202020
            203C657869663A506978656C5944696D656E73696F6E3E3534333C2F65786966
            3A506978656C5944696D656E73696F6E3E0A2020202020203C2F7264663A4465
            736372697074696F6E3E0A2020203C2F7264663A5244463E0A3C2F783A786D70
            6D6574613E0A2020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020200A202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020200A20202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020200A2020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020200A202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020200A20
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020200A20202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020200A2020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020200A202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020200A20202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020200A2020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020200A202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            200A202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020200A20202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020200A2020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020200A202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020200A20202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020200A2020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020202020200A
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020200A202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020200A20202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020200A2020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020200A202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020200A20202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020202020200A2020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20200A2020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020200A202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020200A20202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020200A2020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020200A202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020200A20202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            0A20202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020200A2020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020200A202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020200A20202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020200A2020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020200A202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020200A20
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020200A20202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020200A2020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020200A202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020200A20202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020200A2020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020200A202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            200A202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020200A20202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020200A2020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020200A202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020200A20202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020200A2020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020202020200A
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020200A202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020200A20202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020200A2020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020200A202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020200A20202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020202020200A2020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20200A2020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020200A202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020200A20202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020200A2020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020200A202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020200A20202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            0A20202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020200A2020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020200A202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020200A20202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020200A2020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020200A202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020200A20
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020200A20202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020200A2020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020200A202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020200A20202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020200A2020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020200A202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            200A202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020200A20202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020200A2020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020200A202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020200A20202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020200A2020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020202020200A
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020200A202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020200A20202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020200A2020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020200A202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020200A20202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020202020200A2020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20200A2020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020200A202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020200A20202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020200A2020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020200A202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020200A20202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            0A20202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020200A2020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020200A202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020200A20202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020200A2020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020200A202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020200A20
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020200A20202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020200A2020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020200A202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020200A20202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020200A2020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020200A202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            200A202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020200A20202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020200A2020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020200A202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020200A20202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020200A2020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020202020202020200A
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020200A202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020200A20202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            20202020202020202020202020200A2020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            202020202020202020202020202020202020200A202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020202020200A20202020202020
            2020202020202020202020202020202020202020200A3C3F787061636B657420
            656E643D2277223F3ED2C78FA500000021744558744372656174696F6E205469
            6D6500323032303A30393A31342031373A32353A343794F49232000098C34944
            415478DAECDD097C5C75B9FFF1E777266DDA265D4041A06C2228821711102828
            059A9956C06269A68056A04D5A1645C115EF5FAC95AB5EC52B6E17A14D0A5510
            DA4C01114A329302412C05ACA0B2C8E66529FB226D932E49E63CFFDFA4144AED
            926967F29CC97CDE2F3A992464E67BCECC39E777BE33738E1300000000000000
            009017671D0000000000000000805243B90E00000000000000409E28D7010000
            0000000000C813E53A000000000000000079A25C0700000000000000204F94EB
            0000000000000000E489721D00000000000000803C51AE030000000000000090
            27CA750000000000000000F244B90E00000000000000409E28D7010000000000
            0000C813E53A000000000000000079A25C0700000000000000204F94EB000000
            0000000000E489721D00000000000000803C51AE03000000000000009027CA75
            0000000000000000F244B90E00000000000000409E28D70100000000000000C8
            13E53A000000000000000079A25C0700000000000000204F94EB000000000000
            0000E489721D00000000000000803C51AE03000000000000009027CA75000000
            0000000000F244B90E00000000000000409E28D70100000000000000C813E53A
            000000000000000079A25C0700000000000000204F94EB0000000000000000E4
            89721D00000000000000803C51AE03000000000000009027CA75000000000000
            0000F244B90E00000000000000409E28D70100000000000000C813E53A000000
            000000000079A25C0700000000000000204F94EB0000000000000000E489721D
            00000000000000803C51AE03000000000000009027CA750000000000000000F2
            44B90E00000000000000409E28D70100000000000000C813E53A000000000000
            000079A25C0700000000000000204F94EB0000000000000000E489721D000000
            00000000803C51AE03000000000000009027CA750000000000000000F244B90E
            00000000000000409E28D70100000000000000C813E53A000000000000000079
            A25C0700000000000000204F94EB0000000000000000E489721D000000000000
            00803C51AE03000000000000009027CA750000000000000000F244B90E000000
            00000000409E28D70100000000000000C813E53A000000000000000079A25C07
            00000000000000204F94EB0000000000000000E489721D00000000000000803C
            51AE03000000000000009027CA750000000000000000F244B90E000000000000
            00409E28D70100000000000000C813E53A000000000000000079A25C07000000
            00000000204F94EB0000000000000000E489721D00000000000000803C51AE03
            000000000000009027CA750000000000000000F244B90E00000000000000409E
            28D70100000000000000C813E53A000000000000000079A25C07000000000000
            00204F94EB0000000000000000E489721D00000000000000803C51AE03000000
            000000009027CA750000000000000000F244B90E00000000000000409E28D701
            00000000000000C813E57A148D69FF98C4DC9745B4C63F4423ADE300E8875456
            8AD3C7FCD79BA533FCB5B40D7BCD3A1200000000004029A15C8F1475125FF503
            71FA4DFFD0F0D800E82BAF8BCA14C954FDC13A08000000000040A9A0C08D9244
            FBCFFC43F265EB1800CA906AE8B708274BBAFA16EB28000000000000A580723D
            2AE2ED6789735759C70050D65E96015D1F965B47FCCB3A08000000000040D451
            AE4741A2E35051FD933857691D0540B90BBF26E9A1FF639D02000000000020EA
            28D7AD8D5BB19384C19FFD43B1A775140010D53F4AA6FA18EB18000000000000
            5147B96E69B456C8C05519FF281C6B1D0500DEF29AA4AB76B20E010000000000
            107594EB9638812980A85179433255EFB18E010000000000107594EB56C6B67F
            5ED4FDC63A0600BC8BEA62C9541F6D1D03000000000020EA28D72D8C5D79A084
            EE3E716E887514007817D58B2553FD5FD631000000000000A28E72BDAF1D190E
            9661ABEFF3D73E621D050036F2A668F821C90C7DC53A08000000000040D451AE
            F7B544C76C7F596F1D0300FE8DBAD32533E47AEB18000000000000A58072BD2F
            C5579D264EAFB38E0100FF4E7F2EE9EA0BAC53000000000000940ACAF5BE9258
            BDAF48F6013FCBABADA300C0BBA8DC299D43E2D2E6BAADA3000000000000940A
            CAF5BE302EAC94ECEAC57E6E1F621D0500DE45F519E90C0F93B661AF59470100
            00000000282594EB7D21D1F1037FF92DEB1800F06EBA5A548E924CF583D64900
            00000000004A0DE57AB18D5D354AC2F06E712EB08E0200EF167E4ED2437F679D
            020000000000A01451AE17533CAC1259F5A038B7AF7514007837FD5F49577FD1
            3A05000000000040A9A25C2FA644FBFFFA597C9E750C00781795BF486CF051D2
            1CACB58E02000000000050AA28D78B25DE9E10E75AAC6300C0BBA8AC9458F031
            691EFC9475140000000000805246B95E0C356F0C9760E0237EF6EE661D0500DE
            45DDE9921972BD750C0000000000805247B95E0CF1F65F8B73E758C7008077D3
            2B255DCDBA090000000000A00028D70B2DB1EA2891F06E3F6B99B700A243E561
            E91C7298B4B935D651000000000000FA030AE0423A5407C88EAB1EF473F500EB
            2800F00EED1295C32553FDA07512000000000080FE8272BD90E2EDDF16E72EB1
            8E0100EFA2FA9F92A9FEA1750C000000000080FE8472BD50C6ACF9A004DD7F13
            E72AADA300C0DB5417CB88AA63A4C965ADA3000000000000F42794EB8592E868
            F59763AC6300C03BB4432476B0A4073F699D040000000000A0BFA15C2F8478C7
            043F276FB08E0100EFE2E45C69A9BAC23A060000000000407F44B9BEBD46EB20
            A9EC78C4CFCAF75B47018077689BA4AB8EF3EB26B54E020000000000D01F51AE
            6FAF78FBB7C4B91F58C70080B7A9AE95B0E2205934E871EB28000000000000FD
            15E5FAF6A8E9D84D027DDCCFC62AEB2800F00EFDB6A4ABBF6F9D020000000000
            A03FA35CDF1EF18EDFF839F879EB1800B08187E4F52187C852D7651D04000000
            0000A03FA35CDF5663DB0F11754BAD6300C03B54FD7A699464AAEEB54E020000
            000000D0DF51AE6FAB4447B3BF1C6B1D0300DEA63A4B32D5675BC70000000000
            00280794EBDB62ECCA6345833BAC6300C006DE94B5D9FDA46DD86BD641000000
            000000CA01E5FAB688B72F16E74659C700800D7C49D255BFB40E010000000000
            502E28D7F355D3315E02F9BD750C00789BCAC3D239E4606973DDD65100000000
            0000CA05E57A3E666820F7AC7AD05FFB0FEB2800F0B630AC91D6A18BAC630000
            000000009413CAF57CC45725C5E97CEB1800F036D5DF4BA6FA33D63100000000
            0000CA0DE57A3E121D0FF8CB83AD6300400FD5ACC4C283A479D823D651000000
            000000CA0DE57A6F25DAC7F9D9759B750C00D8C0D592AE9A621D020000000000
            A01C51AEF756BCFD2E71EE93D63100A087EA5AD1E083D23AE459EB2800000000
            0000E58872BD376A567D4202FDA3750C0078875E26E9EAAF58A7000000000000
            285794EBBD11EFB8CDCFA971D63100601DED90B5E1DED236EC35EB2400000000
            0000E58A727D6B6A567C588218270B04101D2A3F924CD545D631000000000000
            CA19E5FAD624DA7FE567D317AC6300C03ABA4654F792CCD057AC930000000000
            009433CAF52D19F7DA3009073DEF6753B575140058477F2EE9EA0BAC53000000
            000000943BCAF52DA9E9F8B204F233EB1800B08E764918EC2BAD439EB54E0200
            0000000050EE28D737678606B2B8E331716E5FEB2800D04365B664AAA65BC700
            000000000000E5FAE6C5DB3F25CE2DB48E01006F73DDFB4BCBF0C7AC63000000
            00000080727DF3E2ED29716EA2750C00784B8BA4ABC65987000000000000C03A
            94EB9B327AC57BA53278C1CF9E01D65100601DFD94A4AB9BAD53000000000000
            601DCAF54D89777CC9CF999F5BC7008075F4714957EDEF57D96A9D0400000000
            0000EB50AE6F4AA2E3017F79B0750C0078CBF992AEFA957508000000000000BC
            83727D63F1F683C5B907AC6300C03ADA2E6BAB769536D76E9D04000000000000
            EFA05CDF58A2FDE77EB67CC93A0600F450992399AA3AEB180000000000007837
            CAF50DCDD04016AF5AE6E7CAAED65100A087BA4F4866C89FAC63000000000000
            E0DD28D7379458759488526201880695C724933B9129000000000000A286727D
            4389F6FFF1B3E42BD63100601DBD48D2D53FB24E010000000000807F47B9FE36
            7512EF78469CDBC33A0900886A280364A42CAC7EC93A0A000000000000FE1DE5
            FA7A351D474A20F758C70080B7DC2EE9AA31D621000000000000B06994EBEBC5
            3B2EF573E36BD63100A0879373A5A5EA0AEB18000000000000D834CAF5F5E21D
            0FF9B971A0750C0010D16E591BEE2A6DC35EB34E020000000000804DA35CCFA9
            59B5A704FA8C750C00784B8BA4ABC65987008062A8396DEA6ED225BBC5C455AB
            FFE744DBB331B726E6622FAD796997656D6D33BBAD3302000000406F50AEE7C4
            3BCEF67382C32F008806D57AC954375AC70080ED75E8F4E903DEF346768C3A57
            E3443F212A0789738337F7FFAB4A569C3EE187A8F7F8EFDA9CCA1FD2A9C637AC
            A703000000003685723D27DE7E93DFD13BD93A0600F4544B41F83E691EF6AA75
            1200D856634F3D7B6FCD662FF4EBB4CFFA31D67BB7FD96B45B459A0317FCBC65
            FEEC45B91F584F1B00000000AC47B99ED481B2BCE3753F2BAAADA30080A8DE27
            99EA23AC6300C0B6382179E62EDD3AE0BF5564B273122BF0CD2F0D25B8A0B569
            D6DDD6D309000000003994EBF155C788D336EB1800D04365A664AABE6B1D0300
            F215AFAD3B5B9CBBD40F2E8716F58E54AF1ED4A95FBAF9E6392BADA719000094
            96DCB95F5C36D8B92FEE2BA6D94EA9EC5CD67CEDB52BACA71B40F150AEC7DBBF
            ED77042FB18E01003D02395C9AABEEB78E0100BD353A795E75A5AEBDCA8FA76A
            FBEC4E55FF4F8270427AFE557FB59E7E0000107DF1DAFA3A27FA1D3F5ED9B32F
            EF575543279291307641FA8659FFB09E0F000A8F723DD1D192BBB48E0100A2F2
            AA1C35641799E942EB2800D01BE36AA7EC14BAD8427FF5B0BEBE6F1559E95427
            A5538DCDD6F30100004457A2B6FE7BE2E462CB0CAAB22214F78945A9D97FB79E
            1F000AABBCCBF5D15A21951D6FFAD950651D050044E55AC9544DB68E0100BD91
            2BD6B312BBD33939C02C846A976A707266C1ECDBACE7070000889E7113EB0E0A
            03F7A044A0FF52957B32A986A3AC7300282CF3958BA9711D1F9750EEB38E0100
            3D429D26ADD50DD63100606BE2932757C99A41B73B27875B67F17BAAAB45839A
            F482D98BADA30000806849D4D67D5F9CFB4FEB1CEB5564C3BD17DE30E719EB1C
            000AA7BCCBF5C4CAAF8A043FB18E01003DC2D807A575D013D63100606BE2C9BA
            6B9CB8CF59E7584F555E0AB2EE90961B67BF689D0500004447BCB6FE7AE7E454
            EB1CEBA90B4767E6CFB9CB3A0780C229F372BDBDC9CF82BE3BF916006CDECB92
            AEDAC53A04006C4DA2B66E8A3837C73AC7C65425934935701E1D0000F0B678B2
            EE2627EE64EB1CEBB9508F6B59D078A7750E008553EEE5FA537E16EC631D0300
            44759E64AA4FB38E01005B129F70CECEAEA2FB317F758475964D51D1CF679A1A
            AFB1CE010000A281721D40B1956FB95EF3C670092ADFB48E01003D54BE2899AA
            FFB58E01005B9248D6CFF65FEAAD736C8EAA3C37C22DDFB7A9A9A9D33A0B0000
            B047B90EA0D8CAB75C8FAF3C5E5CB0C83A0600F408E47069AEBADF3A06006C4E
            4D72FA9E81669F14E7065867D912553D27936ABCD23A070000B047B90EA0D8CA
            B85C6FFFBADF39FCB1750C0010D16E0986544B73B0D63A09502C277EF6DC1DBA
            D776ED968DC9EE2E743B044E47A8F87FEA86FB65608473E2BF97C1B9FFD7A91B
            E02FAA367D4B6EADFFBBD5A2AEC3FF5D87DF596AF73F5CAE4E5EF33F7B3D08E4
            B550B22FC5427DB93975D5ABD6D3DD9FC46BEB2FF58FD3D7AC736C8DAAFC3593
            6A38D83A070000B047B90EA0D8CAB75C4FB45FE7279FE31B03888207245D7588
            7508607B8C1E3DA362D04ECF7D4034D83F74FA213FC0F8B08ADBCB898EF4BFDE
            439C1BDCD7995474AD5379C65F5DA6CE3DE3B33C2E2E78221BCAE31D52FDE492
            D465ABADE75BA998316346B0F89165CBFCCEE9AED6597A435DF81F99F9731EB2
            CE0100006C51AE0328B6322ED73BFEE62FFFC33A0600780D92AE9A661D02E8AD
            236B2F1C5C1DACFCA8533DDC7F7BB853778838DDCF0F2B2AACB3E541FD7F4FAA
            CADFFC68E8AF41E8FEE64259DA7C63C332EB6051149F5477B47F9CEFB6CED17B
            E1D7D34D737E629D020000D8A25C07506CE559AECFD0401677AC12E72AADA300
            805F139F2B2D555758C70036273E797255B066E0B1A17335A2728C7372508915
            E9BDA6A22F8ABA7BFD342E09D52DE9AAEABCB76DEEDC35D6B9ACC56BEBBFEDE7
            C925D6397A4B556ECDA41A4EB2CE0100006C51AE0328B6F22CD7E3ABDFEFD768
            FFB48E0100EBB8A3253D64B1750A6043636AA7FD47207AB21F28C4457454D44F
            62592C3D87961159A2227706A1DC392C58B1B8A9A9A9D33A575F8BD7D6DFE29C
            9C689DA3B754E5B94CAA614FEB1C0000C016E53A80622BD372BDFD53E2DC42EB
            1800D06340D78E72EB887F59C70072857ACC8593545DD239F990759E48526D57
            71AD2A7A6B45D63597CB6164E2B5F54FF8E7C4BED639F2B142870EE1B8FA0000
            9437CA7500C5569EE57AA2E3027F7999750C001095572553B5B3750C94AF446D
            DD8E2AEE2C713ACDEF78EC6F9DA7D4A8EA5F9C93A620089A9AE7CD7ECA3A4FB1
            2492755DA576282017C4DEDF32EFCAA7AD730000003B94EB008AAD3CCBF578FB
            E5E2DCB9D631004044EF9274F568EB14283F3593EA8F0C4239479D9EE6773838
            074921A83C244EAFEDD68ADFDE9EBAF279EB3885323A795E75A574AEB4CE912F
            17CA475A16343C6C9D030000D8A15C07506C655AAE77DCE6A77C9C750C001095
            D992A99A6E1D0365C325264D3D59D45DE4AF1E611DA6BF52D5D00FB0322AC1D5
            9D559D3795FA0951E313CED9D95574BF6C9D235F2AF2B14C53C383D639000080
            1DCA7500C556AEE5FA437ECA0FB48E0100A2EEAB9219F253EB18E8DF66CC9811
            2C7EF885494EC26F8A73075BE7292BAAAFA948A3BAD8E5AD4DB39EB58EB32D46
            9F7CE688CA81034AEFBC10AAFBA5538D4F5AC70000007628D701145BB996EBCB
            FD940FB38E0100A26E9264863459C740FF35B676EA89A1043F764E0EB0CE52CE
            72EF66F7C3AE9B9DBA4BD30B662FB6CE938F64323970B90C5F6B9D235F612C1C
            D97AFD9C17AC730000003B94EB008AADFCCAF5F1AF0E9535435658C700801EA1
            8C92D6AA25D631D0FF8C9B58775018B8DCA722C65867C1C6B44D54FE3B9D6A6C
            B64ED25BF1DAFAE5AE94DE98A0B2269D6A18D2730D0000942DCA7500C5567EE5
            FAB815074818E3E45600A2C1E96ED252FDA2750CF41FB943780C1C50F163E75C
            BD94E376BEB42CD530FCCFCC823969EB205B13AFAD5BEA9F538758E7E82D157D
            38D3D4F811EB1C0000C016E53A80622BBF9DEE44FB383FD9B759C7000011ED96
            51559532D385D649D03FC46BEB27F82F973B27BB586741EFA9CA1DA2EE5B9905
            B3EFB5CEB23989DABAABC4B9B3AC73F49ACADC74AAA174F2020080A2A05C0750
            6C6558AEAFFCAC4870AD750C0010D5A72553FD7EEB18287DC79F56F7BE58B7FC
            AF736EA275166C07D5EBBAA5E2EBB7A7AE7CDE3ACAC6E2C9FAB3FCA0F12AEB1C
            BDA52AF5995443A3750E0000608B721D40B19561B9DEF1457FF94BEB180020AA
            F749A6FA08EB18286D3513A78E095C70ADDFA2BFCF3A0B0A40B55D9CFBAFE1B2
            FCB2A6A6A64EEB38EB8D9B50BF7B5821CF4A098C1D73278F1DE0BA472E6C9AFB
            9275160000608B721D40B1457E07A9E0E21DDFF5533DC33A0600884AB364AA3E
            651D03A529994CC6DE946117FBE7D1C5CEB9C03A0F0A2B77CC70A732359D6ABC
            CF3ACB7AF164FD1D7EE078AC758EAD51D5D64CAA316E9D030000D8A35C07506C
            6558AEB7FF529CFBA2750C001095DF49A6EA73D631507AC67CE6F3EF89550C9C
            EFB767C75B6741F1E4DE81ED876A3FEDACEABAB86DEEDC35D6796A92F5A707E2
            D75B11A72AA764520D375AE7000000F628D701145BF995EB8976BF53E84EB78E
            0100A2FA4BC9547FC93A064A4BCDA9751F0E42778BBFBA8F7516F40D5579C4C5
            BAC7A5E75DFD9C658ED1A367540CDC69D93F9C731FB09E279BA5F2E8A803477E
            64E6CC999C281A000050AE0328BA322CD73B6EF5972758C7000051FD8E64AA2F
            B18E81D2119F5477B484F207E7DC0ED659D0B754E5AF9DAF8E3CACAD6D66B765
            8EB1C9FA492A32CF7A7E6C8ED3F0A496D49C5BAD7300008068A05C07506C6558
            AEB7DFE9277BB4750C00F02E9474D5CFAC43A034246AEBC6F92F37887383ADB3
            C0880B27A4E7CFB9C93A867F2E36FBE7E158EB1C1B53D1DF679A1A3F639D0300
            004407E53A80622BC7727D899FEC23AC63008077B6A4AB66598740F4D5D44E1B
            1F489812E706586781A91FA79B1ABE691DA2E6B4A9BB0559F7801F4FED6C9DE5
            6DAACFAF1D103BB8EDBA59AF5947010000D141B90EA0D8CAAF5C8F773CE8A7FA
            A3D631004054A748A6FA6AEB1888B6B193A6D568182EA45887AAFC24936AF8BA
            758E9C786DFDF14EB4390ACF4B155DEBC2E0F8F482D98BADB300008068A15C07
            506C6558AEB73FE17704F7B58E01005EADA4AB1658874074C5274E3BC2B9F00E
            0E05831C55777A2635FB7AEB1CEBD524EB4F77AAD738E702BB79A261A092F43B
            A93758CF0F0000103D94EB008AAD1CCBF5A7C5B9BDAC6300803741D255E6C74F
            46348D3965CA3EB120B8D76FB3DE6B9D05F654F55F2B65D8C825A9CB565B67D9
            503C597F96139DED8794150633A54B2538234A2F3800008068A15C07506CE557
            AE27DA9FF193BDA7750C0010098F97F4D03BAC53207AC68F9F3A74F5C0608973
            728075164484EA4FD3A9C6AF5AC7D894DCC976D5B9F97E5039B4EF6687AC100D
            93990573D2D6D30F0000A28B721D40B1955FB9CE3BD70144850B8F9396A1775A
            C740E4B8446DDD02BFAD9A601D0411A2BA5F3AD5F8A4758CCDE9F9A4452CF85D
            5F9C345E55EFF7F7736A26D5F07FD6D30D0000A28D721D40B151AE038015CA75
            6C42A2B6FE02BF75BECC3A07A2435532995443C23AC7D68C1E3DA362E0CECBCE
            1395EF3AE77628F87C105999BBEDCE5747FEA2AD6D66B7F5F4020080E8A35C07
            506C94EB0060C5E949D2527DAB750C44C798DA69FF1188FED93919689D0511E2
            C209E9F9734AE6FC0C277EF6DC1D3A3BBBBEE007995FF423CDF76DEFEDE58E37
            EF9789FF5D5B11FB79DB75B35EB39E3E0000503A28D701141BE53A00D8E184A6
            785BCFBB7E777A3E57AC7FD43A0BA243459775BEB2FBFB4BF19DDAC96472E072
            1D76BC8A4B8AD384DFB1DD3D8F297FC55FDC2E2E48AD08AB1746ED44AE0000A0
            3450AE032836CA7500B043B98EB7259253BF26125C6A9D0311A33A239D6AFC9E
            758C42A8494EDF3308C383FCE8F3FD2A3AD2EFE80EF63F1EAE4E57389535EAE4
            C52074FFECAE904717CD6B78DC3A2F0000287D94EB008A8D721D00EC50AEA3C7
            F1B5678FAC90EE7FF8ED53B57516448976FBE7C51E0B9BE6BE649D040000A014
            51AE0328B6322CD73BFEEAA7FA20EB180020AA5324537DB5750CD88BD7D65FEF
            9C9C6A9D0391D3946E6A98641D020000A05451AE0328B6322CD7DBEF15E70EB7
            8E01007E0D7CAEB4545D611D03B66A26D51F19A8DC639DA34FA876F9E7FDD3AA
            EE29FFCDD37E10F2868A7B3D90F055FFDB37C2C0BD29EA3A72FF6B18C8AA0A89
            75BEEBCFB3DD15EA5C7510EA88AC0B863917EEE077967651D15DFCDFEDEAFF8F
            7DFC6DBEDF6FE7DF6B3DA985C0CE170000C0F6A15C07506CE557AE27DAEFF493
            3DDA3A060088CA5724537599750CD88AD7D6659C7335D6390A4EF5FFFCE5523F
            D258EA9FEB4B43177BECE803765D3673E6CCB0D8773D7EFCD4A19D8362FB6755
            0FF4F77DA00F73B0FFF1A17E3EEF603D5B7A4DE5D174AAE1C09E6B000000D826
            94EB008AAD1CCBF59BFD647FDA3A060088CA4CC9547DD73A06EC8C9D5877AC06
            EE0EEB1C85A02AB9779F378BD3B4740F48676EBCE215EB4C1B1B73CA947D6241
            6C941FFD7C52453FE177B40EB4CEB4393EDF97334D8DBFB0CE01000050CA28D7
            01145B3996EBF3FD6427AD630080A8FC4432555FB78E013BF1DAFADB9D93E3AC
            736C2B5559E12FAF0F44AF3EF2C03DEEED8B77A517D2B8DA293B8512C4FD55FF
            CF25FCA86837EB4C392ABA4A25B65B6BD3ACE5D6590000004A19E53A80622BBF
            723DDE7EA53837DD3A06007873255D75967508D81837B1EEA030707FB5CEB18D
            96AAE8CF56EAB0054B5297ADB60E5320AE66E2D44303178CF7D727F811D247AC
            82A8EAEC4CAA91B10A0000C076A25C07506CE557AE273A7EE02FBF651D0300BC
            8592AE3AD13A046CC46BEBAE74A5F762EF9F45F5E274AAB1D93A48B1254E99BE
            BFC4B29F5375A73927FBF6E57DABC8C7324D0D0F5ACF030000805247B90EA0D8
            CAB05C5FF95591E027D631004044EF9574F591D629D0F76A92D3873BC9BEE007
            FA43ACB3F446EE78EA7EC0F0B574AAE1B7528627D88C4FAA3B5AD4D5F9493FB5
            E88F99EA9274AA7194F534030000F40794EB008AAD0CCBF5F633FC64CFB58E01
            00A2FAA464AAF7B38E81BE3736597F8E8AFCDA3A47AFA8DE1848787673EAAA57
            ADA3581B3F7EEAD0D503639FF77B45E7FB9DB4FD8B72272A67A6530DBFB19E56
            000080FE80721D40B1955FB93EB6FD4451778B750C0010959592A91A661D037D
            2F515BB7489C3BDE3AC796A84AF6AD77ABFFCC3A4B04B9F8C4A971E7DC57FCE3
            38B680B7FBFADA215DBBB7CD9DBBC67A02010000FA03CA7500C5567EE57A4DC7
            9112C83DD63100A0C7A055C3E4E69D565AC740DF894F3867678975BDE89C0BAC
            B36C8E8AAC5427C9D6F90D2DD659A26ECCC4A91F0B9CBBC83F9E49D9CE7195AA
            FC24936AF8BAF534010000F41794EB008AADFCCAF5C4AA3DFCEEEBB3D63100A0
            47983D405A873D6A1D037D27EA8784519515A22E915930FB5EEB2CA5645CED94
            03B212FB8E733249B66D7CA5D96C76DF45375CF54FEB69010000E82F28D70114
            5BF995EBA3B5420676AC9508BF6310401909759CB456F3EEE03212AFADBFCD39
            19679D6393545787813BBE757EC312EB28A52A9EAC3FD8CFC84BFC4EDC49F9FC
            9DAA3467520D9FB2CE0F0000D09F50AE0328B6F22BD77312EDCFFB49DFCD3A06
            0088E8744957CFB64E81BE317AF48C8ACA9D9E7FD36F7DABACB36C9273B5E9F9
            B31758C7E80F6A264E1DE382E0A77EA075506FFEFF50DDC9ADA9D9375BE70600
            00E84F28D701145BB996EB4BFCA41F611D030044E57B92A99A611D037DA36652
            FD918146F4BC1F2A97A5530D5FB18ED19FCC98312358FCF0B269FEEA0F9D733B
            6CE17F7D60D401230F9B397366689D190000A03FA15C07506CE55AAE37F949AF
            B58E0100A2F25BC9549D611D037D2391ACBBC86F7F7E689D6363AAF2586755D7
            C16D73E7AEB1CED21F8D3E7DFA7B0776873FF683AE291BFF4E559F0EC3700CC7
            5A07B6C88D3EF9CCE1B92B3B0F5CB5B2A9A9296B1D089B57939C3EBCAB73AD1B
            9AADECBCE59659ABACF300C5109F3CB9AA73656C805F27ADF2EBA44EEB3CD83C
            CA75E4A967CC31B8BA3B6CBEF6DA15D661501ACAB55CFFA99FF40BAD63008088
            DE2BE9EA23AD53A06FC46BEB6F744E3E639DE3DFA826D2A9C68C758CFEAE66E2
            D4C39C0BCE754E0FF4E39076FFA34C3070F5AF19B8A3DCE40E9135609765FBB9
            EE60EF20D0BD42D5BDFD4EC99EE2DC7BFCAF775CFF4F5586FA75666C9337A2DA
            E5F76456F9FFE75FFEBB57FD32F5BABF8DD7FC2F9E5571FF0C549FD28AEC53A3
            F6DFEB793E15B2ED4E3A69FA90B543BAF771D9606F0D741FA76E6F3F8F7791DC
            63E41F2F557DAF7F8C76107595FEF118B4D91B52F5EB3C975BD72DF7DF2C5791
            E7FDDFBD1C8A7B3E50792608DCE3B18A8A276FFDDDAFFF653DCD284FB9178524
            ECDECF6FA7F7762EDCDB3F5FDFEFD725BB38D59DFDD71DFDFA25B77EAADEECA1
            FDDE5E27B9ACDFCEBFEEBFBEE6445FF2CBC92BFE97AF3AFF5CCF86E11312543C
            D1DA34EBB9DC5F584F73B9A05C2F6FB9ED58E790AEFD9CC63EE4173ABF5CCB4E
            7EE9DBD5FF6A27BF8CEEA24EDEEB97EF21FE6731BFBC566FFA567479CFA5C84A
            FF5C7AD98F3D5ECD2DDFFEFB97FD23FA8ADF8E3DE51FD87FBCB663C53F97CE9A
            D5653DCDE87BE559AEC73BBEE0A7FC57D63100C07B53D2553B6CFFCDA014C46B
            EB9E74CE7DC03AC7BBA8FC299D6AF884750C942C179F547792842E7732D65DC5
            69DF8C2D555EF177B468EDABBB2F686B9BD96D3D13F2E41293A69EACA11BEBAF
            EE52EC79E654423FEE7D3174726BEBFCC6857D3DB1A3CF3C73D0A0F6011F0F9D
            8EF2390E12751FF13BA407F81DD8017D12605DA9FB5775FA173FABFF1CC6F4FE
            D6798D8FF6F57C2805279C3275AFAE2038C43F693EEABF3DD82F671FF5DBACBD
            FB3685BEE21FAF07FDE3F657FFCDD220EBFED47C63C332EB79D35FE53E5955D9
            953DD3AF853E26B9E2B8D8D4ADF1CFAF7F84D9F037969FD81A573B6527D5D851
            1AE861FE797E903AF751BF22DEABCF02A8AEF6F7F984BFCFC7FC774B5DA8F7AE
            092AFFDCD67479BBD53CE9CF28D7CBC7B809F5BB6B851C158A1CEE97B3DC72FD
            413FDED8B3EF1268B75FA7E4D66DFFF0EBD507240CEE1D5859B184178EFBBFF2
            2CD76B568E912068B58E01003DB2DDEF9545C35FB78E81E2CA7D7CD8AD1DB452
            A2B6ED75E184F4FC393759C740E9193F7EEAD0D503DD0DCEB91AAB0CAA7A7F4C
            C2139B5357BD6A3D3F7A23F7CE4827A1DFC997634D02A82C1CB8264816F3501D
            3DEF4ADFE985A39DE838FF2F379D87F65991DEFBF9F0B28A2CF2D76E77B1EE74
            7ADED5CF5947B230EED4691FE8CE86C705E23EA14E8EEDD372311FAACFFA8DD5
            5DEAB4A5B322D6DC76DDACD7AC23F5078949538FD3D02DD8CA39418A43B52B14
            39AF35D5D8D0177737FAE433470C1A382011AAD6F851D8279DB8FDFB7C9AB73A
            4B34F742E8A33EDB3DAA6E51D8BD26B3E8A6DFB27F500094EBFD57CD2967EF17
            04D913FD36EC937E291AE51FE75DAD336D8A8AFEC3A92CF1E3A2DBD70CA8B88D
            ED58FF13AD1DFCBE72C2AABDA45B9FB68E0100EBB8A3253D64B1750A14577CE2
            B4235CA04BAC73BC8BEAF3A30EDC7D4F0E99806D9148D65DE7D75FA759E75091
            3B334D0DC759E7E88D78B27E811F7C9F621A42F5EA74AA71CAF6DFD006D33579
            7295AE1D343E1099E0EF20E19F17C34DA7317F7FF6B9170441D0D43C6FF653D6
            618A257792E5250F3F7784BAE033AA72B273F221EB4CDB2077288DA522E1BC50
            2AE6B736CD7AD63A50294A9C7AD61E1A563CECD74743AD32E4CAE440654CB14A
            C6B73E8931519C7CDA897EC2AF972AACA6755BE78F5F46EFF74FF866A7B2D0AF
            B7EF170E25B34D28D7FB8F71E3CEAF0CAB571DA74E4EF04BC30991FB4470EFA8
            5FC0EFF5D3B03070C1AD2DF367FFC53A10B65F7996EB333490C51DABC5B981D6
            5100C06F5CA748A6FA6AEB1828AE9A64FDE981C8EFAC736CE4CA7453C339D621
            507A12B575FBFA71D413D639D60B25F8646BD3ACBBAD736CC9B8DA2907842EF6
            B0750EC9EDD405DD7B6DEFBBB57345EDE2875E182B4E27FB1D8A93377B1CE212
            A32AF7F92FB364D09AEB33D75CD3619DA710E2C9FA83FD944D75EA26F9C7E97D
            D6790A4A75898A6BE87403E771488DDE8BD7D65FEA9C7CCD3A875FDE32995443
            A250B7977B877AE5C00149BF969B2C3DEF64ED3F7D878A3CE32FAE0B54AE6959
            D010856D49C9A05C2F796EECC4FA4F844E3FEF9C4BFAEF4758072A2C7D42D5FD
            2688C5AE699977E5D3D669B06DFACDC6266FF18E87FDD41F601D0300FC9EC5CF
            2453CD4996FBB94472AADF890D2EB5CEB121A7E1492DA939B75AE740E9F13BAA
            93FD8EEA6FAD73ACA72ADFC8A41A22B57C6DACA6B6AE3E706EB6758E1C3FBF92
            7E7EA5B6E56FC77CE6F3EF890DA8AC579173237B189102C89DB4CC5F5C1393EC
            AF9A53573D629D275F89DABA1DFD5AFE0C3F1D6739271FB5CE5374B963EB3B77
            ADDFAE5DE6B76B8F59C7893ABF0EFF935F871F659DC32F631DE954C3761FEB7D
            CCC4A91F8B39F7257572BA9FAE4AEBC92A36BF5CFFEDADF5D3D5A57258344B94
            EBA569ECA967EFAD61779D1FB34CEEFBF37F58D136BF6CCF5D21C3AE5F92BA6C
            B5751AF45E1997EBED37FA01D867AC63008077BBA4ABC658874071256AEB7FEA
            B7BA917A1145BB2BDE97B9F18A57AC73A0F4F8E7F305FEF97C99758EF5547466
            A6A9F1BBD639B6244AF34C45A6649A1AAECE2F7FDDBEFEEFBEEEC49DE1A76390
            F534F4A1DCC7B76FF2FB0DDF4F37352CB50EB335EB3E552217F694EAE28658E7
            31A0AAF27B0DE447ADF31BA27528B60889D7D63F1895175DFC72B54D9D44CF61
            8E1E79BE3654B9C04FCB28EBE9B0E09FEB9DE2B44943FD59EB82397FB6CE1355
            94EBA525773E0809DD057E3B7692732EB0CE63C12FDB6FF8CBD959A9F8E5EDA9
            2B9FB7CE83AD2BE372BD63A69FFAEF58C70000BFDBFEAA64AA76B68E81E2F23B
            B2D7FB9DBF53AD73BC4DF5B574AA7127EB18284D512A8A7328D7F3934FB9DE53
            D68AFBB6FF9BC97E1D16B3CE6E4AB52550F946F382C6BF5947D9987F9C0E5771
            DFF28F51AE402ADF7DBC0DF8F5C2EF63A17C278A8F97B5522ED77B0E49F5F00B
            939CE877FC33FDC3D6F92343E52E7FF1433FB66BB68E123594EBD1B76EB95E36
            D139F70DFFED61D6792243B5CB5FFEC6FFFB6FBF6C3F691D079B57BE03AF44C7
            447FB94D1F8705808273BA9BB454BF681D03C513AFADCBF801638D758EB7A9FC
            299D6AF884750C94A62815C53994EBF9E94DB97EE267CFDDA1B3AB73A6A83BAF
            EC4BF50DE44E32E8BF34662BE4E2DBAF6F7CD93A4FEE58FE5917FC204AC551C4
            A87FBE5F2DDD1517F149AD77946AB99E98587F925F8FFE98527D8BFE1CAABBA4
            3535FB66EB205141B91E692E3169EAC9120697F8E5FA23D661A2CA6FC8B27E45
            794D4518CE5878C39C67ACF3E0DF956FB93E66CD072596E5787C00A221D471D2
            5ADD621D03C59348D6DDE937BBA3AD73BC436F4B37359E609D02A5294A45710E
            E57A7EB654AE2793C9D89B3AE26CFF7F5DE29CEC689D35AA72C764772ADF1975
            E0C85FCC9C3933ECEBFB4F9C7AD61E9AADF8BE7F8C264B39EFD3F5DE9BA27AF1
            A80377BFDCE2F18A9A522BD76B4EADFB7090F5EB4FE7C65AE72D157EBBB85825
            F6CDA89FECBB2F50AE47537CD2D46324743F71CE7DDC3A4BA958772828F96567
            67D77FB5FD7EEE9BD679F08EF21D88253526CB3B56FA5930D83A0A00F84DE5B7
            255DFD7DEB14289E786DDD523F783CC43AC77A7E70362F936A38CD3A074A5394
            8AE21CCAF5FC6CAE5C4F9C327D7F8965FDCFDD11D6194B86EADD615831B5F586
            2B9FE88BBB3B74FAF4013BBE11FAE7927EB74C8FA9BE7DFAF8F18AAA5229D747
            9F79E6A0CA8E8AEFAD3B678DABB0CE5A9254532E56F1F59679573E6D1DC50AE5
            7AB49C70CAD4BDBA03977BB16C82759612F6BAFFF7AD51078C6CE405E36828DF
            723D27D1913BE9C7A1D63100C08F7C6F96747564067D28BC28EDC8E6A8CAEF32
            A986CF59E740698A52519C43B99E9F8DCBF575EF561FFE15717A891357699DAF
            E4A8AEF6BB55DF4CA71A7E59CCBBA9A99D363A10FD3587C4D84EFEF1F2CBC085
            9954E395D651AC44694CB2B972BD6652FD912E94AB7DCE0F59672C792A6BD4E9
            0F622B87FCB8B9F9976BADE3F435CAF568C8BD38FC9E37B2DFC89DC7A5CC4E8C
            5E347E7FEEBE505CFDA2D4ECBF5B672977E55EAECFF697F5D63100C00F7A5F92
            4CD5AED631503C89DAFABF47E95882B913BD659A1A3F639D03A5294A45710EE5
            7A7E362CD74F489EB94B970CB8CEEF141C6B9DABD4A9EA8258E59AA9CDD75EBB
            A290B7BBEEDDBB037EB0EEDDBB2894DC8BCC9D6EE0D96D4D97B75B67E96B512E
            D7478F9E5151B9F3F3DFF7CBD3D79C738175BEFEC46F2BFF11846E7ACB82863F
            5A67E94B94EBF6E213A71DE19C3644695FA8FFD06E55F78337760CFE6BE9AC59
            5DD669CA559997EBEDD3FC2C98651D0300D6717B4A7AC873D629501C51DA91ED
            A1BA249D6A1C651D03A5294A45710EE57A7ED697EB3DC73B5577BD13C78BBB05
            A22A8F853119BF685EC3E385B8BD78B2FE607FABD7F8C7E840EB69EB8F7265A3
            53F9B4DF1E3E699DA52F45694CB261B95E73DAD4DD82EE60BE5F571E6D9DAB1F
            F34F7BBD6C6D55F7FF6B9B3B778D7598BE40B96EE7AD4399CDF0572FE2E4E845
            F74018E8E75AE7353E6A1DA41C9577B91E6F3F589C7BC03A0600F450494AA62A
            651D03C591A8AD6FF35BDD63AC73BC435F493735BECF3A054A53948AE21CCAF5
            FCE4CA75FFA5CA5FF9393BBB45F1A60B65FCF6BE3B345E3BED3CFF685DE61FA3
            81D613D49FA9CA1B2AEE94D6D4EC36EB2C7D258AE5BACF74BC737A9D88DBD93A
            5339F0CFFB4762AAA7372F68FC9B759662A35CB791A8ADDBD78F37E645E99C53
            FD5EEE1050A21794F361CFAC9477B93E5A2BA4B2630527350510092AFF2399AA
            AF59C74071C493F57744EDB00B612C1CD97AFD9C17AC73A0F444A928CEA15CCF
            4FAE54714E0EB0CED19FF979DCE982F0D4F4FC3937E5FBB7C96472E09B3AFCD7
            FE319A6A3D1D6543B54B253823939A7DBD7594BE10B5723D5E5B77B6BF7A3987
            81E95B7EDBB9D6A95C984E35FEDA3A4B3151AEF7BD446DDDA9FE4B8338576D9D
            A51CF965FB5AA95C7B76E69A6B3AACB3948BF22ED773E2ED7FF20BFC51D63100
            C0EFD8DD2799EA23AC63A038A236B0CF5175A7974B9180C28A52519C43B98E28
            52D5D0AFF7CF48A71AAEEDEDDF8C9D306D578D8537F8FD9323ADF3979B9EC7CB
            B973D24D0DB3ADB3145B94CA75EFC7FEDF37AC43943355F96DE59AE09C5B6E99
            B5CA3A4B31446D0CDE9FCBF59E7326ECB4EC277E1BF665EB2C654FF5EF2E5631
            BE65DE954F5B47290794EBF1F6CBFC827F81750C00F01BC0AC74568D90365776
            27D62A077E603F3757B258E7D8908ADC90696A98689D03A5276A4531E53AA22A
            9F823D71CAF4FD25C8B6F87D933DAD739735D5F3FAFD3B79A355AE231A1E08BA
            657CF38D0DCBAC83141AE57ADF38F1B3E7EED0D9D9B5C0AF5B8EB3CE82757A0E
            7BE682935B9B66DD6D9DA5BFA35C1FBB6A927FC6CDB38E01003D54C74AA63A6D
            1D0385E777647FE8079B1759E7D850EEE3C04177F0FE961B67BF689D05A5256A
            4531E53AA22C57B007A2E35B52736EDDDCFF139F38ED081768EEF7EFB1CE8B9C
            B02EDD34678E758A62A15CC7A6A8CA4B7E75F5E9D60573FE6C9DA59028D78B6F
            CC2953F60982D842BF5EF9907516BC5BCF61EA44CF48A71AE93D8B8872FD84F6
            5DA4DB512A00880695EF4BA6EADBD631507889DABA73C5B9CBAD73FC1BD54BFD
            608B8F63232F512B8A29D71179AAAB5583E3320B66DFBBF1AF72C5BA384D3B27
            C3AC63629DDC0B22FECB6999546393759662A05CC766A974F88B5A3F366CB68E
            522894EBC53576D2B443C2509BFD3A6527EB2CD802D5F3FD72FD2BEB18FD15E5
            7A4EBCFD09716E5FEB1800E0377A7F944CF531D63150786327D69FAC81E47D62
            BB62CBBD9B2190F0A096D49CC7ACB3A07444AD28A65C4769D05742897DBCB569
            D6B3EB7F42B11E61AAABFDE5B1E954E37DD6510A8D721D5BA4DA25E2A6E473BE
            8828A35C2F9EC4A4A9C76918DCC436AC54E8B7D24D8DFF6D9DA23FA25CCF8977
            34FA3931D53A0600F80D5E97ACADDA91E3AEF73F8964FDA1FE4B243F66AB2AF7
            8D70CB3FD9D4D4D4699D05A5216A4531E53A4AC8032B74E8D14B5297AD8E4F9A
            FA11098336E76447EB50D8B4DC61326259F9787F3B0E35E53AB666DD097E755A
            7F383C12E57A71F8F5C8F14EF416716EB07516E48382BD1828D773E2ED67F915
            C255D63100A087D393A4A5FAD6EDBF2144C991B5170E1E2A2BDA9D738175964D
            5191AB324D0D75EBAE025B16B5A298721D2545B531C8BAEF86315DE2F741465A
            C7C156A82E797DC7D8314B67CDEAB28E522894EBE82D3F289CE2C787575BE7D8
            1E94EB8547B15EEA28D80B8D723D27B17A5F91F009EB1800B08EFE42D2D55FB6
            4E81C2F383FB47FDE07E7FEB1C9BA797FB81D61785821D5B11B5A298721D2547
            E505FF7CD8CD3A067AA99F9D9F84721DBDD5F30E76716794F2216228D70BABE7
            70664178BB9FA743ACB360DB3991735B9A1AAEB0CED15F50AEAF176F7F5A9CDB
            CB3A0600788F4ABAEA00EB1028BC44B2EE3ABFE93DCD3AC796A8E8B52364C554
            0E11832D895A514CB90EA0E85413E95463C63A462150AE232F3DC76097F1A57A
            9253CAF5C219573BE580D0058BFD540CB7CE82EDD3F3C259104C4ACF9FBDC03A
            4B7F40B9BE5EA2A3C15FD659C700801EDDB2BBDC5EF5BC750C14562259FF4DFF
            25F21FC153D13F0E90EE490B9BE6BE649D05D114B5A298721D40B1A9CA73833B
            C3036FBE79CE4AEB2CDB8B721D79535D1DAA1ED3BA604E24CF1FB42594EB8571
            7CEDD9236392BDC7AF3BF6B0CE8202C92DD7813BBE757EC312EB28A58E727DBD
            B1AB26F927D63CEB1800D023D469D25ADD601D0385357662DDB11AB83BAC73F4
            868ABEA8A17EDEEF442DB2CE82E8895A514CB90EA06FF41C3EED0BD629B617E5
            3AB645EE04BFEA82235A9B663D6B9D251F94EBDBEFA493A60FE91C1CDEEDAF7E
            CC3A0B0A4CE5E5202B87F5B71377F735CAF5F546AF78AF5406AFF859C23C0160
            4FF5F792A9FE8C750C14D6E833CF1C347055C59B7E805F699DA5B754F46752B9
            F6DB996BAEE9B0CE82E8885A514CB90EA0CFA81E914E35DE671D637B50AE635B
            A9CA5F2BD70447DD72CBAC55D6597A8B727DFB232792F5B937A226AD83A068FE
            BC7648D727DBE6CE5D631DA45451246F28DEB1D4CF9143AC6300801FB9AE92CE
            AAF7489B6303D7CFF81DDAB4DFA18D5BE7C88BEAB312E897D3F3E7DC641D05D1
            10B5A298721D405F51957B32A986A3A5844FFE4DB98EED913B3F8FDFE64EB6CE
            D15B94EBDB275E5BF70DE7DC8FAC73A0C8541BD3A9C67AEB18A58A727D43F18E
            1FFA397291750C00E811EA89D25ABDD03A060A2B515B7FBEDFD6FCC23AC73651
            B92B0CE49B1C970F512B8A29D701F4A550E4B3AD4D0DD759E7D85694EBD86EAA
            E7A7538DBFB28ED11B94EBDBAEA676DA6827BAC8AF2F62D659507C7E3CFD793F
            9EBEC63A4729A25CDFD0D8559FF41B89BBAC6300400FD55F4BA6FA3CEB1828AC
            C4A967ED2161C53352CADB60D59650F5528EC75EBEA2561453AE03E84BAAFA54
            E7ABBBEFDFD636B3DB3ACBB6A05CC7F652954EBF4D3B22D3D4F0A07596ADA15C
            DF36633EF3F9F7C42A2AFFE61FE7DDACB3A08FA8B667C3F0A38B6EB8EA9FD651
            4A4DE9EED817435263F2E6AA57FC5CD9D13A0A00F88DDB32C954EDE957D525FB
            B1636C9A1FE4DFE507F99FB4CEB1DD541ECA9DDC6D6D57F7756DBF9FFBA6751C
            F49DA815C594EB00FA9A1F9C4DC934355C6D9D635B50AEA31054E5B1CA35C121
            513FFE3AE5FAB649D4D6FD5E9C1B6F9DA34FA8BCECC792EDFED1F1FF649573DA
            D9F3637583FD974A7F6DB8FF3ADC39B78375D4E2CF0A5D3C42561CD3D4D494B5
            CE524A28D73716EFB8D6CF95CF5AC700801EA18C92D62A0EC1D1CFF89DDA3ABF
            53DB609DA350FC206CADA8BBC905AE694558BD7049EAB2D5D699505C512B8A29
            D701F4B5DCBBD747B8151F2AC50282727DEB5425EB449F57712F89D3579CBAD7
            FD3ABCCBFFA2E704EFEA24F03F1BE6AF0D54919D9CB85DFCD7F7F9F9BA9375F6
            BE9D51F28B74AAE1CBD631B684723D7FF164FD594EE42AEB1C85E4D7D9A17F1E
            3CE2AFDDEBBF5DEAFF3D998DB967BA07753DDBDB13798EFBDCE78665BB2AF774
            D9606FBF5EF8905F3F7CDCDFDE11CEB9BDADA7AFB0F34ABE9149355C6A9DA394
            50AE6FAC66D5E912E8EFAC6300400F951F49A68A7341F433F1C993AB64EDA017
            FD4678A875968253E9F03B9C2D7EAFB3A9D30DB8A5ADE9F276EB4828BCA815C5
            94EB2544E5053F1F1EF23B6E8F3BD1A75582E7FD0F73C5D51A0D74552C702BFD
            CF7ACACAEE6C38B42290012AD9E1A106BB04A27BF9BFDBCBEFC27CC0FFCD61E5
            F00E3273AAAFA9730FF9AF8FFBF9FD4FBFAC3D1FB8E0A5AC7FBC9C84ED6120AB
            2A24D6F30E3FFF8055F9EF0704A18E90C0EDAC12EEA9E2F6F4BF79BFFF77A813
            B7ABF5E4149C73B5E9F9B31758C7C817E5FA4672631791FBFC3C59E2D731F7C7
            24FBD850D7FE6453535367BE3755939C3EBCC2E907B31A1EE0543EEE6FF7707F
            BB1FF34F960AEBC92C1A171E9F9E3FE70EEB189B43B99E9FE36BCF1E59E1BA1F
            F649875B67D95EB94F57F831C72D7E195F2883D6DC9BB9E69A8E62DC4F7CC239
            3B4BACFB187F5F27F8FB3AA9E45F64535D1D86151F6DBDE1CA27ACA3940ACAF5
            8D9DF8E60ED259F1AA1F2871C2060011A0FF9474F507AC53A0F012B5F53FF55B
            E10BAD7314D35BEF68BF439CDE160B825B9BE7CD7ECA3A130A236A4531E57A74
            F91DDB47FC3A20ED9CB67507EE9EDBAF6F7CB950B75D73CAD9FB0541F6707F2F
            353D3BB4E276B69EDE52A722CFF81DC4665577A73AB7B8B569D6B385BAED7113
            EA770F07B823240C8FF3F77362BF78A79FCA5DE954C368EB18F9A25C7FAB7413
            F943A07AEB9AD776BFBB98C7CFCFBDA942D70C1EE324FC945FBE3E2DCE8DB49E
            FEC2D227D60EE93EA8B7EFFEED6B94EBF9F1E3959BFD36F5D3D639B6955FB65F
            75A2BF0D54E6362F68FC5B5FDFFFE8D1332A2A775A56A3E2CEF2DF4EF0EBDA81
            D6F3645BF8F9784726D570BC758E5241B9BE29F18E3BFC9C39D63A0600F450FD
            9864AA237FB220E4A726397DCF40B24FF5EB77326D4CF5717F799B0B825BD60C
            EEBC3BAA3B61D8BAA815C594EB11A3F2A87F4C7EEBD76FD7FB1DB3FFEB8BBB4C
            2693B1E53AEC783F8FA7FAFB9F28CE0DB09E0DA5C2EF403FE7BF5C1B53BDAE2F
            8B889A49F547BA50CFF43BA493FDE3556D3D1FB699CB1E9C9E7FD55FAD63E4A3
            5CCB7555FD977FBEE53EA5FE9B74AAF13E8B0C3366CC08EE79F4B9D112BA33D4
            C924276E88F57C2904BF1EF9BE5FDF7FDB3AC7A650AEF7DED88975A768E04AEE
            D3383D54FFAECEFD74842CFFDDB67CEAA418DE7A47FB17FCFAF60BFEDBF758E7
            C997AA3B3D939A7DBD758E5240B9BE29898EF3FDE52FAC6300C05BFE4BD25517
            5B8740E12592F5B3FD977AEB1C1672EF6A772A7FF2576F0F03B768075D7E7F29
            1EB7B65C45AD28A65C8F04FF30E88250825FB5A666B75906193B61DAAE1AD3AF
            FBABE7FA793EC87AC64496CA5D7E3DFCD3233F32F20F3367CE0CAD628C3EF9CC
            110307549CEBAF7EBD140FF5A32ABFCAA41ACEB7CE918FB22BD755732FF2FD74
            ADABBC3A4A87AB3BF1B3E7EED0D9D939CDAFA7CE77E276B7CEB33DFC72D0E944
            0F4CA71A9FB4CEB231CAF5DE39E9A4E943D60ECE3E5672CF45D5C7558219471D
            B8DB7CCB6DD9968C4E9E575DA96BBFA2CE7DAD940E0BEA07762F4AE5DAFD8A75
            389DFE84727D536A3A7693409EB78E01003D549F944CF57ED63150788953CFDA
            43B2158F53FEF4EC94ADF083925C2177BB3AB973842CFF3B657B7445AD28A65C
            B7A52237C4347B7173EAAA47ACB36C28B78ED56CEC27CEB949D6592245F56E0D
            E4A2CCFCC63F5947D950AE68ECEAECFAAE5F9EBFE81FB3C03A4F1E5E7F7D8760
            D7A5B366755907E9AD7229D7FD736999139DB1F6953D7E53CCC3BE6CAF643239
            F04D193ECD07FEB67F5C76B1CEB3ADFC58EED64CAAE124EB1C1BA35CEF1DBF5E
            98E99F7FDFB1CED15B7EECB152D55DFCAF1DDDE5A5B2FE3D2179E62EDD3AE0BF
            FD78F04CEB2CBDE597EBEFF9E57A86758EA8A35CDF9C44FB123F7B8EB08E0100
            3D02395C9AABEEB78E81C24B24EB2EF1DB9B487E8CD652AE6CF75F16E78ED31C
            4AECEE8A9595F73737FF72AD752EAC13B5A29872DD46CFF1D483F0DCCCFC3977
            5967D992F8A4BA4FBB50E68873EFB5CE624AE505BFAC5C904935365947D99244
            6DDDE12AF23BE75CE99C73C68513D2F3E7DC641DA3B7FA7DB9AEBADA3F872E59
            29C37EB62475D96AEB38BD7564ED858387CACA8BC4E9379DB84AEB3CDB220CC3
            9AD605731659E7D810E5FAD695DA1B7E722FE4C4B2724EF38D0DCBACB36C8B9A
            8953C7B8206874923B497BC4F9F5A9CB061F68B971F68BD651A28C727D73122B
            BF2A12FCC43A0600ACA39749BAFA2BD6295078B98F60760ECA3E2ACEED699D25
            CA7A4E8E2A729FA8BB2B08DC9D0356B9C5B7DC326B9575AE7215B5A29872BD6F
            A96AE877237E38C22DFF5E548E6BBA35EB0E1513DEE0D7B5475A6731A17A7550
            B9E6CBCDD75EBBC23A4A6FBCF511FADFF8C76B827596DED1EBD34D8DA75BA7E8
            AD7E5DAEABB664C3F0BC45375CF54FEB28DB2A77B26617745FEE9CABB1CE922F
            BF7DF84B26D57898F4BCB1381A28D7B72E9EAC9FE344A658E7D89ADCFE4020EE
            8296A6862B2542CFB16D51939C3E3C90EC15FE19719A7596ADF1CBF5157EB93E
            D73A479451AE6FCE98D5FB482C7CCA3A0600F45079518E1AB2BBCC74913C8E1C
            B64F7CE2D4840B8216EB1CA5A4E798ED224BFCA8FACE20943BD754772FE104A9
            7D276A4531E57A1F5279D9A9245B1634FCD13A4ABEC68D3BBF325BBDEA5AE7DC
            44EB2C7D46A5C35FD4A5538DF3ACA36C03174FD65FEAD7F55FB50EB235B94F5B
            8D70CB772A95179BFA65B9AEB2C64FD3852D4D0D575847291057533BED4BCE85
            3F2AB977B1AB9E16A5750EE5FA968DAB9D72405682BF47FD705C7ECCFF4CE0DC
            292DF367FFC53A4B21F9E7E797FC76EE7FFC33A3C23ACB66A9765584BADFC21B
            E63C631D25AA28D7B724D17EBF9F458759C700801E615823AD4323F5314B144E
            BCB6EED77E507B8E758E52B5EE9DEDEE1E7F6591BAE0CE1DE45FF7954AC9518A
            A2561453AEF799A5DD1A3BF9F6D495257B6EA26432197B5387FFC639F9AC7596
            62CB1511E2C29332F3E73C649D657BF86567865F76BE6B9D636B4227E35AE737
            94C40BE5FDAD5CCF1DA22A26D964D4CEFB5008E326D61D1406EE467F751FEB2C
            BDA6F2E8A803477E242A2797A45CDF32BF3EB8DEAF0F4EB5CEB1257E19BF4FB2
            159FCEDC78C52BD6598A21F7462B7141937F1C865967D9822BD34D0DECAB6E06
            E5FA967068180051A2729564AAA65AC740718C3EF3CC41033B062CE94F3BBBA6
            D61D6FF54F7EA8735BA0D2D2B2A0E161EB48FD49D48A62CAF53EA0DAA283D64E
            CC5C734D877594ED952BD897EBB0DC2162C65B67291A9587C28A706CEBF5735E
            B08E5208F164DD654EDC05D639B644557E9549359C6F9DA337FA55B9AEB230A8
            5C7D7AA91CF2685B246AEB76547129FF981D679DA5B7FCF290F4CB43CA3A470E
            E5FAE6E5DEB51EBA58EE05D8C87683FEB9D45CB92698D8DF0F07D9F3429A9345
            913D3F8C6A97CB067B71ECF54D8BEC021409351DBB49A0CBFC6C623E0188006D
            171DB28B6482922F36B069634E99B24F10C4EEF75B9D1DADB3F4377E60FE9CBF
            6C0EFC00DD0D5AD3DA9F77C2FB42D48A62CAF52253F9C370B7BCB63F7D1A243E
            797295AC1DB4D80FF20FB2CE52702A0F05923DBE3975D5ABD6510A65DD0B22C3
            6FF4CBD0A7ADB36C96CAA3E954C301D6317AA3FF94EB7AF97059F125BF6ECA5A
            2729B643A74F1FB0E31BE1D5A5F3A91BBD37DDD41889735C50AE6F9E9F3773FD
            BC39C33AC766F5C3F1C7968CAD9DFAA1D0B93BFC63B2AB75964D52BD349D6AFC
            86758CFFCFDE9DC047559DEF037FCF9D1096098B0BAE68B52E75AB756B455CA0
            921952718519B445FF481270E9A6B5B6DADA52AA56DBAABFAE2AC90C4AC55A33
            0316AB349909DA74716B6DB52A56ADAD1B6A5D591220CBDCF7FFCE001A900037
            CCCC7BEECCF3FDD4245AE53E7366E6DE739EDCB9D746288DB726D4F1A08CD238
            ED180000EBF0344A55FD4A3B0514CE84C975E3D8508A8C19A09DA574710F1365
            2F21F37B97B979C982B9FFD04EE437B615C528D70B277B5F8311B46242292E6C
            B3370D749C9EBFCBFEB64A3B4BBE30D37301CA9C584AC5FA0613BF70D10E5DDD
            DDFF9005ECC7B4B3F4C5F4983DFC70565F2994EBCCFCC374327E85768E629A35
            6B96F3D033AFFDD22F9711342E9D64C3FD3950AE6FDEC9910BF6ACA09EFF5ABB
            E6605A3CDCAC38AB14E71F5B323E32E39301721FB0F10C76D9EFBE4F833AF72A
            854F31E61BCAF5AD0977CC94AF73B4630000E4303D48E9E0C9DA31A0B0C25366
            4C66D76DB2FDC6422583F91536B4D071CDC261CE8A87CAE10CB8ED655B518C72
            BD30B2D73166E38C694D34ACD0CE5228E168FD0CF9D6A09D233FF82DE3541CDB
            72F79C97B493144A784AED67899D07B473F489E9DC543276A7768CADF17DB9CE
            74B58CF377B5632831B2DFCAEEB3EAB5836C157332958C47B563A05CDFBC50A4
            EE7A596B7C533B471F1EAF5CE39C54EA9782E94BF594FAD18ECBD9827DB07696
            4D19A28B4AE8C6D17983727D6BC2CB7724AA785386CACEDFE6014099612613F8
            38B50C7E493B09145675A4AEDE31A6513B47B99177D8DBC6D02276CDC240C7A0
            079A9B7FDEA99DC946B615C528D70B8157C8C01E934AC6FFAD9DA4C04C3852F7
            4759C09EA01D647BC8BE2B231384F1ADC9C636ED2C85168AD6CF9545EC74ED1C
            9BE397EBAEFBB95C9731BE45C6F862ED1C9AD6DF372221FBADB3B4B36C19F798
            1E676FED4F73A05CFFA89A9A2F0F74AB56BF66E3D9D132F778BDC2741FBD3831
            EF4DED289A4291BAA831A6493BC7A6641FFCA4EC838FD0CE611B94EBDB22DCBE
            5086CAF2031700940F9E45A9AAEF6BA780C293C5EFE5B2F8FD91768E722593C7
            95C6F06266D314681FBC1845FB876C2B8A51AEE79F4D37A32BB470B4FE68F9F6
            37ED1CDB8399BF954EC6AFD3CE510C279F53B76B458F7951DE4F41ED2C9B92F7
            CD63F2BE39563BC7D6F8B65C67BE67B85919C527CC88C64E9B36A8B263409B3C
            8F9FD1CEB225F29EF88EBC27AED1CC8072FDA3644CCE9531B9437B2C3625AF97
            2E6273527A41E3A3DA596C20FBEAEBE43D6EDDE5AF5CD7FD74EB82B9BE9E37E5
            1BCAF56D51DD713A39B4483B0600C03AFC0A1D17DC97661B573B09145E385277
            111973B3760EC89DC59B6432BF1E73E89E7F983D7B7659BFFF6C2B8A51AEE797
            8CE7AF643CA769E728A670B43E7B7698FAE50BFA439EAF8746D0CA93CAA97094
            E7EB07F2ED4AED1C9BCA164381F6C1C36CFF65AC2FCB75A6670775B9C7DE7BEF
            DC55DA516C91BB66B6E9F93B91D9453B4B5FE43DF1EF74327620E56EE1A103E5
            FA47C93EB455BE8DD71E8B8F60FE7A2A19BF513B862DB29F52594EC3FE28AFDF
            31DA597AF3CBA7B48A09E5FAB6389A07D08EAB97C9688DD48E020090E3F2446A
            AD5AAC1D038A4316C175328D69C035D8ED20ABC3970DD3AFE4FB6D32B1FCAF76
            1E0DB615C528D7F3EADD4C77E72796FCF68E77B5831453285A7F842C8C7C7873
            63EE71D8FD5473F2B6A5DA498A69ECE767EE3CB0DB7D55DE5383B4B36C4A8E0D
            47A613B127B4736C89DFCA7519D355AE43C72CB93BF6BC7616DB64EF43C0AE69
            B5798EC8864F4837C5FFA2B57D94EB1BAB3EA7760F27E3BC4696F581D91BA8CB
            BEF36452FC458C8D4E9954FBB11EC73C6DD3CDD765DEFDC6085AB95739FD527F
            6BAC7A33592DDCFE1319AEAF6AC70000C8615E44E9AA33B56340F14C985C3789
            0DCDB7F1C636656E8971E9E7A30FDBF377E57436BB6D4531CAF5BC9A994AC4CA
            F27E0FE168DD1F64BE3F563B8717CC74433A19BB5C3B878650A42EFB4BE719DA
            393665D8FD7F2DC9B9D65D6EA137BF95EBB2939F964AC67EA51DC356E148DD8F
            647E68ED7E40FB2C5794EB1B93D7CB65F27AB9417B1C36C2BC26E3BA872D5978
            DB7FB4A3D82814ADFFA221FA85768EDE5CD7AD6E5D307789760E5BA05CDF56A1
            F6236407E4C3B35900A024316788CDDED41A7C5D3B0A144FF6BAC0B240B94F16
            C4BB6967818D31F34BD9496FA71938A72D7173BB769E42B3AD2846B99E1FB27F
            59DAF5F69E9F6A6B9BDDA39D45433852375DE6FB73B57378B0BCB3AB7BDFB645
            F3966B07D1109E3C630C39AC76366C5FE478F0C374326EDD35727BF353B9CE44
            0BD389D864ED1C36CBDE9C323374F5E386CCA1DA5936277B96EB9843468DD23A
            0901E5FAC6643DF177F976A4F638F426AF91EFCA3CEE6AED1CB69A356B96F3F0
            D265D9EBD01FA39DA59739A944EC42ED10B640B9EE45B8235BAEE3AEB8006009
            BE8A5255D76AA780E2AA8ECEDCDB2177A1FC78B47616D8AC77E5BD7943270DFC
            452997ECB615C528D7F384F99C54327EB7760C2DB27F1DEEB0FBA68D971AD91C
            1B6E14A8CC8423752F9231FB6A07D908D3EF52C9D8E9DA31B6C447E5FA72EEA9
            F844FA9E5BDFD20E62BB0991DAE3D8380F69E7E88B61774C4B72EEC31ADB46B9
            FEA1F0A4990751C07D567B0C7A9363D9AB5DC1EE03DBE6CD5BAB9DC566D553EA
            473B4C2AEFA1CD91E7EDEDAEB7F7DCA35C4FC8D814CA752F421D17CB88FD523B
            0600400EF3CB3422B81F250CAE755666B26728B955AB6F2463BEA89D05FAF4AE
            BC47AF1B6E56FE3C9148746987C937DB8A6294EBF9C02F1C77C8A883CAE9F246
            9B138AD4DD6D8C99A29D636BB2D7A0EEEAEADEBB5CCF5ADF2014A9BFC618FAB6
            768EDE647FF48CEC8F0ED3CEB1257E29D7E575FEA5742286F5F7360A45EBE71A
            A2E9DA39368799BE9F4EC666696C1BE5FA87C2D1FA6FCAB7EBB5C76023CCB5A9
            64FC36ED187E20FBEE7B64DF6DCDA5618D4B27B52C88FD493B870D50AE7B51F3
            CE30CA0C7A838C19A21D050020277B706D092ED28E013A648215916F7199640D
            D3CE027DE1170CF3A52DC9B9F76B27C927DB8A6294EB79C0F4955432F673ED18
            DA42D1BA730D19ABAF979D25AFF99FCB6BFE2BDA39B4D976265F0E5387BC97AC
            B9F1DCE6F8A25C677E62B859790C6E98B7ED4E3EA76ED78A1EF3A21C6B82DA59
            36C54C8FA593B16335B68D72BDF758D43F6888C6698FC1064CF472D75B7BEE8F
            B39FB74D684AED61869DA7B4737C80E96A39DE7D573B860D50AE7B15EEB85DBE
            4ED38E010090C3D44AE960483B06E8A939AB7E941BA03972443F453B0BF44D16
            95CD6C9C0B5A130DAF6867C907DB8A6294EBDB47C66F75A072EDEECD77DEB952
            3B8BB6DC3EB5825ED5CEB1350E670E6D4EDEB6543B87B668341A58CEC3DFB3ED
            97CC9D15CEC8B6BB1ADED1CED1179F94EB9F4B25E3CDDA31FCC6C64F736431B3
            EBF674EDB2E4B777BC5BF43141B99E73FAE9B543D7569A77C99801DA63B081CC
            3FBE2AF3B79F69E7F09370B46EB1BC8A3EA79D234BD6370FA793B131DA396C80
            72DDABF06A79E1D877E31C002863A6E7206A19FE9C760CD0158AD69F2F07F56C
            7137423B0B6C5EF6320EF21C5D964AC462EBFED6BF6C2B8A51AE6F1F19BF3B65
            FCCED5CE618B50A4FE0563687FED1C7D61E6BFA693F1CF68E7B0853C5FD91B7D
            4FD4CEB18963645FFFB87688BED85EAEA3B0E9BFB1674C1B31B0B2E22559200C
            D7CEB22966F3F974B2F137C5DE2ECAF575C2536ACF2476EED17EFC1BC8FB7C65
            97A9DCB394EF515408B2FF3E59F6DF4BB47364657F69C626B0636BA261857616
            6D28D7FB23DC91FD1886D5D7D1038072C23FA354D557B55380BE9AC8F491AE09
            5C2D139D19C618473B0F6C9E3C3FAD034CCF798B13F3DED4CED25FB615C528D7
            B70FBBE694F482C6DF6BE7B045385A7FAB7CBB403B475F64257B496BB2F1A7DA
            396C118AD45F6E0CFD483B476FB6BFA76C2FD7650E136A696A6CD5CEE157B20F
            FB817CBB523BC7A664FED3984EC667167BBB28D7D7B1F0D8362795885DA81DC2
            878CECC39FB7E52400669A944EC6ACF9A58D1694EBFD11EEF8927C2DFB6B5202
            8025985651D7903DA8CDE0B7FE905333B9EE70375BE21973B27616E803D3FF5C
            76A7B62E986BC599275ED95614A35CEFBFEC272A02AB068F6C6EFE79A776165B
            4C88D65F28E3728B768EBE5464DC7D162F9CFBB2760E5BD87416DF06F2FA999E
            4EC46ED7CED1179BCB75665A9A4EC6B227B2F9FA135E9AB297B7CA04E825798E
            03DA5936C2FC542A193FBCD89B45B9BE7E1C22F5CFC86BE210EDC7BF01BB6674
            7A41E3A3DA39FC2814A9BBD218F303ED1C394CFF974AC6BEA61D431BCAF5FEC8
            DED8D41DB44C86CFEA1BD5004059B99852416B8B00D0316172DD3876E87B72BC
            1AAB9D053E2AFB514A99895D9D4EC46793CF4A04DB8A6294EBFD27AFC305E964
            3CA29DC326A129B5271976DAB4736C8EEC28FE994EC4AC2C45B59C129DB65B0F
            0D78433BC726AE4825623FD40ED1179BCB754374514B2276AB760EBF0B45EB17
            C8584ED2CED15B6EDE33A873587AFEFC8EE28E05CAF5DCF5D6073AD94B7758D1
            01CA6BE125997BECAB9DC3AFAAA333F776C8B5E297EC3207FF93CCC14FD2CEA1
            CD8A37962F85DB7F29C377B1760C00801CA6A5940E1EAA1D03ECB4BE64FF861C
            B76A08C77EFB30272BD706A6DD775FC36AED28DBCAB6A218E57AFFC902F74259
            E0CED1CE619370A46E4732A6E837DDDB164C74633A11FBBA760EDB842275EF19
            6376D0CED1CB8F5289D837B543F4C5DA729D794DA719B80BAEC1BCFD643F5623
            FB31EB2E4D645C3AA96541EC4FC5DC26CA75A2EAC9B5E31DC7B1E6524B326FFB
            89CCDB2ED5CEE16772DC7B5C8E7B4769E790FD76FB70B372442291C86847D184
            05767FD5AC3C84DCC033DA3100003EE49E4CA9A10F6AA7007B554FBAE00013E8
            B998D8D4CAA27A98761ED8C8DF2AA8FB34BF5C87DDB6A218E5FA76603E20958C
            FF5B3B866DE4F97A539EAF5DB5737C844BA7A516C4EED38E611B79BEDAE4F9B2
            E6CC3966BA259D8C597B2296ADE5BA8CDBDD326EE768E7280547CF9C3960C7F7
            DC65F23C8FD4CEB231F7F25462EE0DC5DC22CA75CB2E2342B97B878C6B4D365A
            F90931BF90FDF855F2FEBE5A3B479671E9B09605B1B2EE4751AE6F8F50C78332
            82E3B4630000E4302FA474D564ED1860BFD0B9E706CDDA419399E87CB3EE3886
            F9800D98FF2B5FC37E283A6D2B8A51AEF713F33BF27AB3AC78B1832C5A1F95FD
            E367B4737C04F34EF29CBDA71DC336F2FEBA43DE5FE76AE7D88099EE482763FF
            4F3B475F6C2DD75D3667B4261BEFD5CE512A2CBC81A5E0DFA412F1CF17738B28
            D72D1B03E635EBCF74EED28EE267D553EA473B4C0F6BE7C8619A964AC67EA51D
            431316D3DB6342C72479112DD08E010090C39CA180D9879A83AF694701FF9870
            F605FBB899CCB96478AA4CBA0FD2CE53F6989739E4869B93B72DD58EB225B615
            C528D7FB8B7F9F4AC44FD14E61A370A46E111973BA768EDE98F9C57432BEBF76
            0E1BC9F3F52379BE2ED7CEB181EC9316C93EE94CED1C7DB1B25CCF5E1226D8B3
            63DBBC796BB5A3940A2B2F0DC3FC442A193FB2989BB4AA58269D725D5E0BFF91
            D78215D73867A607D3C9D8C9DA39FC6EECD8591503472E5B2E73CBA076165CE6
            07E5FAF619CB1554D9F15FD9498DD28E0200B0DED5940A7E573B04F853285A7F
            844C0CB26713656F6EF871ED3C658BF99D0C39272F49363EA51DA52FB615C528
            D7FB4716B8D7CA02F72AED1C360A45EAE61863666AE7D8087332958C47B563D8
            281CA9BB4CD66445BDD4C4562C492562D5DA21FA6263B92EFBA366D91F7D4E3B
            4729191DB974F050B3F27D4366A076960F30B7CB7E6C68313759EEE57A341AAD
            5CCEC3D6C831CDD17EEC59F25ECF7EFAEA55ED1CA540D66D9F902F83B473C83C
            FC3E99879FA69D4313CAF5ED156EFFB60CE335DA3100007298DEA0AE217B539B
            E9D18E02FE169E32FD53CCCE5986691219F349ED3C6587F91DF97A9CAD9788B1
            AD2846B9DE4F4CE7A692B13BB563D82814A99F6D0C59F5CB6A3FBCCEB5842375
            5F90639545AF656E4B25E2E3B453F4C5C6725D5EE097CAFEE827DA314A4D2852
            9736C658F58B9E1E0E8C7A20396759D1C6A0CCCBF50993EB0F65879ED67EDC50
            BA98E9B9743256D69F8046B9BEBD42AB7691617C55267395DA510000720C9D49
            2DC145DA31A074D49C3D633F37E39EC98626C9E2E438C2FCA12898F8B5408F39
            AEF99E9875977AB2AD28F643E968DB9865655CF7A8250BE6FE433B878D6C7CBE
            5CA22FB426627769E7B05138521792F5584A3BC78750AE7B658C39BAA5A9F1EF
            DA394A8DBC37BE2B833B5B3B476FC5BE9965B997EBF27E3F4BDEEF0BB51F3794
            30E6EEE166E5E0442291D18EA2058BE37C0877DC215FADB9810E009439A6FB28
            1D2CEB8F6541E14C386BC6EE99803B5116C19F33C4E3652A315C3B5349637E9E
            D69DC16ED50D0C6D2B1E51AEF74F6757F70E6D8BE62DD7CE61A350B4FE7C5928
            DDA69D6323CCC7CABEE031ED18369A30B96E1C3BE641ED1C1F42B9EE09D3DA77
            7774863DDED0D0AD1DA5D45879DD75A299A944ACB1581B2BF7723D1CADFFA67C
            BB5EFB714369ABC8B8FB2C5E38F765ED1C5A50AEE74375C768722CB94B2F0000
            B34BC6D9875243702D3B28A8EC8D742A777D750CB94E5816E9D99B221E41985B
            E41D13FD6104AD98904824BAB4B36C605B518C72DD3B665A994EC6F0CBB13ED8
            58AE5750F7EE8B13F3DED4CE61A39A29333EED325BF38B07797F3D29EFAF23B4
            73F4C5BA729DF8D154223E5A3B4529AA894C1FE99AC05BDA397A93F7C7F7E5FD
            31AB58DB2BF772DDCA7B8840C9715DB7BA75C1DC25DA39B460019C2FA18EC765
            348FD28E010090C3349BD2C1EF69C780F2123AEBC25D4CA0A786892618E23019
            B3B376A692C1FCD354327E89768C0DAC2B8A51AE7BC7F46C2A193B443B86ADC2
            53664CCEDE40543BC787B82795880FD04E61ABF537E4B6E6124728D73D8BA512
            B119DA214A55285AF7BA21B3BB768E0D98F9D674327E51111F7F9997EBF5F798
            EC6543010AA9CCEFE383723D5FC21DD9DF04CED18E010090C3FC2A8D09EE43B3
            8DAB1D05CAD3AC59B39C87962E3BDC308D63C3E364C27592316607ED5CBE66DC
            B3524D737FAB1D23CBB6A218E57A7FD87DD90A6DE129B567123BF768E7D88099
            DE4C2763D69463B6094F9A791005DC67B5736C8072DD1B19AF6FC878FD583B47
            A992E34F9B1C7F4ED2CEF101E6642A198F166B7328D7EB1F92F7FB71DA8F1B4A
            9BECC72F93FDF84DDA39B4A05CCF97D3DF1E4A6B07BF2E435AA51D050020C7B8
            216A19DAAA1D03202B5BB63FBC74D99144EE67999D71F28F4E9489FE30ED5CBE
            C2FC8E43EE21CDC9DBDED68E625B518C72BD5F12A9446C8A76085BD956AECB8B
            FCE95432F649ED18B69A70F605FBB09BF9AF768E0D50AE7B23E33549C6CB9EF7
            5B8991E73B2ECF77AD768E0F30FD45F6672714EDF1A35C7F419EFFFDB51F3794
            36D98F5F2FFBF12BB5736841B99E4FA18E0619517C9C0D00ECC07427A583B8D9
            3258291A8D0656991147B9EC8E97C9D87859F41C27C7D0A0762E1FB0A210B5AD
            2846B9DE0F4CF352C9D8F9DA316C655BB92EAFF187E4357EBC760E5BA15CF7C6
            BA729DE8C87422F684768E52551DADFF964374AD768E0DE4FDF19CBC3F0E2AD6
            F6CABD5C97F9473BE6D85004657D792F94EBF914EE385ABEFE4D3B0600C03ABC
            869CB5BB51F3CE2BB593006C4DF6E6A803765D768CC33C8ED98C957F340667B6
            F781399C4AC6D39A116C2B8A51AEF7CB1C59045DA81DC256B695EBB88CCF96A1
            5CF7C6B672DDF4983D5AEE697C433B47A90A47EBB3855783768E5EDE95E34FD1
            EECB53CEE5FAE8C8A583879955ABB51F33943E998B2F92B978D95EDB1FE57ABE
            E1C6A60060139767506B554C3B068057D933DBDF77871EE938348EC99C406C3E
            8BB27D1D665A3AC2AC383C914864B432D85614A35CEF07CB6E926B1BEBCA75A6
            C5A9646CA2760C5BA15CF7C6B672FDDD1D9CCAC71B1ABAB57394AAEAC88CD31D
            C38BB4737C8857A412F111C5DA5A3997EB63CF98366260E580F7B51F339483F2
            3E0900E57ABE853A2E9651FDA5760C008075F82F94AA2ADA350D010A2557B69B
            E19F362E551BC3D5CCE63863A8523B971AE6DA54327E9BD6E66D2B8A51AE7B57
            EED7C6DC1ADBCAF5723F236C6B50AE7B6353B92E63B552C66AB8768E52362152
            7B1C1BE721ED1CBDA512B1A27551E55CAE9F1CB960CF0A93794DFB3143E9937D
            F963B22F3F563B871694EBF93671F90ED455F1261953BE0B7E00B08B71F6A596
            C12F69C700C8A7534F9D39A47360CF09F2FA0E91E1CFC9A2E950ED4CC5C4CC2F
            76BD3DEAA0B6B6D93D1ADBB7AE2846B9EE991FC64C9385E5FA9DF27CE13E2A7D
            40B9EE8D65E5FAAB32567B6BE72865A168FD1186E81FDA397A43B95E9C72DDB6
            7D23942EDB8F7B858672BD10C2ED4D32B451ED180000EBF09594AABA5E3B0540
            21554767EEED7066A21C7F3F27AFF96A3266B076A682633E27958CDFADB16914
            C5DE61CCFCC5B6721D37A0DD32DB0A24DB4B06ABCA75A297D389D83EDA394A59
            4D64FA21AE093CA39DA3371EB8B62A3D7F7E4731B655CEE57A78D2CC8328E03E
            ABFD98A1F4C9BCF21999571EA69D430BCAF54208B7D7C8D0FE5E3B0600C07A4F
            532AF849ED1000C53276DAB441033B2AC691316732D3246368A476A6429049EC
            4332893D5E63DB288ABDC398F90BCA757F41B9EE8D55E53AD37332560769E728
            65B6BD3FB23ABBBA77685B346F7931B655CEE5BA8D9F5A80D254EEBF2845B95E
            08510ED08A8E576478F7D08E020090C3EE27293DF469ED1800C596BB563B8F38
            C11047C8F064595CEDAE9D299F1C973FD5BC20FECF626F1745B17718337F41B9
            EE2FB6958728D73D607A5A5EDB3809A4806C7B7F64A15C47B90EA505E53A1446
            B8E387F2F51BDA310000D6BB8E52C16F698700D0346BD62CE7A167968D931FCF
            97095054664183B4336D2F99C8DE2813D9AF177BBB288ABDC398F90BCA757FB1
            AD3C44B9BEEDCABD902986EA49171CE00432CF6BE7E8CD2567446BA2614531B6
            55D6E5FA94DAC30C3B4F693F66287DE5BE2F47B95E28E17699AC9827B4630000
            ACC3FFA154D57EDA29006C31FECCF3760A0CA89CC16CBE6A0CEDA69DA7BF98F8
            8D31878C1A357BF66CB798DB4551EC1DC6CC5F50AEFB0BCA756F50AE97171BCF
            5EC60D4D714353282D32AFFC97CC2B0FD6CEA105E57A21853A9E91113E443B06
            00C07AC7502AF8B87608009B8C8E5C3A7818ADBA800C5F29D3A25DB4F3F48761
            774C4B72EEC3C5DC268A62EF3066FE8272DD5F6C2B9050AE6F3B19ABF764AC76
            D2CE51CAAA27D71EE338CE5FB573F48672BD38E57A7574E6DE0EB92F6B3F6628
            03CC4FA492F123B5636841B95E48E1F66FCB105FA31D03002087E97A4A07AFD4
            8E0160A3D34FAF1DBA76A073A52CF22F33862AB5F378749D2C528B7AD92714C5
            DE61CCFC05E5BABFA05CF7C6B2723D236355A19DA3948523753564CCEFB5737C
            80A943F66755C5DA5C3997EB63CF98366260E580F7B51F3394036E4B25E2E3B4
            536841B95E48E3D77C9C02EE8BDA31000072989EA374F020ED180036AB894C3F
            24639C4659848DD1CEE2C1E3A944EC98626E1045B17718337F41B9EE2F28D7BD
            B1A95CCFEAAC7046B6DDD5F08E768E52158AD69D2BF39A3BB4737C8857A412F1
            11457CFC655BAED74C9D3ACCED1A5C946BDB437993E3DE6FE5B87796760E2D28
            D70B2DDCFE880CF3B1DA3100007232EEE1B464286E6A03B005D16834B09C8767
            3FE5F13D6328A09D676B98D96513D8B1583706CB4251EC1DC6CC5F50AEFB0BCA
            756F6C2BD729E31C9C5AD8F02FED18A54A9EEFAFC9F37DA3768E0F30FF37958C
            7FBC688FBF8CCBF5DCE38FD477FAF05399E03F735289D885DA21B4A05C2FB4F0
            AACB889C1BB4630000ACC3B32855F57DED14007E109E52FB59724D1319B3B376
            96AD61A6F1E964EC81626D0F45B17718337F41B9EE2F28D7BDB1AD5C37C6845A
            9A1A5BB57394AA50B4EEFF0C994BB4737C881F4D25E2A38BF8F8CBBA5C0F47EA
            5E9337D99EDA8F1B4A1CD3F7649E325B3B861694EB8556BD7A6F721837900000
            3B30FD93D2416B165300B60B45EAF735865B64CA748076962DC95E2B3E9D8CDD
            54ACEDA128F60E63E62F28D7FD05E5BA37D695EB4417B52462B76AE72855A168
            DDEF0C9953B5736C20EF8FFBE5FD51B43C655FAE47EBB337B32DEAE503A1FC94
            FB7E1CE57A3184DA1F23633EAD1D030020C7351FA3D621AF68C700F08B9AC8F4
            912E394BE458FE49ED2C7D629A9F4AC6CE2BD6E650147B8731F31794EBFE8272
            DD1BDBCA7519B09B52C9F865DA314A951C7F96CAF1E760ED1C1F608ECBF35D5F
            ACCDA15CAF5B2C5BFD9CF6E386D2E6B239A335D978AF760E2D28D78B21DC7E85
            0CF575DA3100007298BE48E9E0CDDA3100FC2457B01BE72FD69EC1CEF4742A19
            2B5AF98FA2D83B8C99BFA05CF71794EBDED857AED362797D4FD48E518A6A6ABE
            3CD01DBABA5DE62F15DA593690F7C7F5F2FEB8B258DB2BF7723D14AD9F6B88A6
            6B3F6E2865DCC33D03F64CDF73EB5BDA49B4A05C2F869A35FB91EBFE5B3B0600
            C07A8B2915C40206C0A30993EB0F751D7E4C166843B4B37C14F7A412F1ECCDAA
            B8185B4351EC1DC6CC5F50AEFB0BCA756F2C2CD7FF27AFEFDDB46394A29A2933
            3EED323FA69DA33739FE7C558E3F3F2BD6F6CABD5C0F47EBAE96AD5EA5FDB8A1
            74C931EF1639E65DAC9D4313CAF56209753C29A37DB8760C000039FCADA5CAE0
            4E749F59AD9D04C06FAA2333BEEA18FE89768ECDA9A0EEDD1727E6BD598C6DA1
            28F60E63E62F28D7FD05E5BA37D695EBA28703A31E48CE59A69DA3D484237517
            9131567D62D5B07B6A4B72EEFDC5DA5EB997EB1322B5E7B1717EA5FDB8A134C9
            7C72D1085A39259148746967D18472BD58C21DD7CAD76F69C70000C871E90C6A
            0D96ED35D100FA6BECD859159523973D690C1DA29D6553AEEB7EBA75C1DCBF15
            635B288ABDC398F90BCA757F41B9EE8D8DE53A334F4927E309ED1CA52614AD9B
            6FC84CD5CED19B9B091CD8BA70CE0B451C83B22ED76DFBF482CC3FDE906FD6E4
            01EF0C932BDF5E97BF16A592F1B4761E1BA05C2F96EA8ED1E4D0C3DA310000D6
            E13994AABA503B05801FC922ED5C59A4DDA19D6353C6A5335B16C41615635B28
            8ABDC398F90BCA757F41B9EE8D8DE5BA98934AC43037CD2F138ED6BD29DF76D1
            0EF221EEE97C6BD4E0B6B6D93DC5DA62B997EBD5D199C31D72976B3FEE5EFE23
            EFF5FDB44300E413CAF56299C50E3DBC3AFB1B3A8B0E6C0050BEF83F94AAC2A4
            06A01FB23707CB54AD79CB181AA69D6523CC17A792F15B8AB12914C5DE61CCFC
            05E5BABFA05CF7C6D2721D855B9E8D9F5C7B64C071FEAE9DA337796FFC5BDE1B
            45BD397CB997EBB93188D4BF21EF796BEE6B90C964F65BB2F0B6FF68E700C817
            94EBC514EEB84DBE9EAF1D030020879D8F537AB0350B51003F9185DA3C59A8FD
            3FED1C9BB8229588FDB0181B4251EC1DC6CC5F50AEFB0BCA756F2C2DD7B30377
            402A19FFB7768C52118ED47D9B8CB9463B476FF2DEB85FDE1BA716739B28D7B3
            6350FFA0211AA7FDD83760365F4C271BADBA1700C0F640B95E4CE18EC9F235A9
            1D030060BD0B28156CD00E01E047E1686D2D9113D7CED15B31CB5214C5DE61CC
            FC05E5BABFA05CF7C6D6725DF64BDF95FDD2D5DA394A45285AF7B42173A8768E
            8D30FF20958C7FBBC8E350F6E57A385A9F3DF9E21BDA8FFD03CC7F96D7C189DA
            3100F205E57A3155BF379C4CE5BB644C403B0A0080CC6A9294AA8A6AA700F0A3
            9AC97587BB8E79523BC746987F2C0B95A22C9C50147B8731F31794EBFE8272DD
            1B5BCB75799D3F2DAFF34F6AC72805E323333E1930FC4FED1C9B72D99CD19A6C
            BCB798DB44B92EFBC8C97593D8310BB41F7B2FEC06DC51ADBF99FBBA7610807C
            40B95E6CA1F687C898E3B4630000C802E67D1A3364679A6D5CED28007E73EAA9
            3387740D763BB4736C84F9A7A964FC92626C0A45B17718337F41B9EE2F28D7BD
            B1B65CCF329923524DB7D9F5CB6B1F0A47EA6E2463BEA69D635315D4BDFBE2C4
            BC378BB94D94EBB28F3C6BC6EE5CC15615D9CCFCAD74327E9D760E807C40B95E
            6CA18ED932EADFD58E01009093E1A36849D53FB46300F8512852BFC2A69B9ACA
            22A5511629338BB12D14C5DE61CCFC05E5BABFA05CF7C6E6725D8E650D722CBB
            403B879FAD3F016099FC38423B4B6F72DC794D8E3B7B157BBB28D7D70947EA5E
            2663F6D67EFC1F607E65B859F9F1442291D18E02B0BD50AE175B68F5F164F8CF
            DA310000725CBA845A833FD58E01E047B248794D16297B6AE7F800CE5CFF9E76
            8E2DC198F90BCA757F41B9EE8DD5E53AF16AA6C01EAD898615DA59FC2A1CADCF
            FEA27D8E768E4D31F38274321E29F67651AEAF1F8748DDDDC69829DA8F7FE3C1
            30915453A34D97AB01E81794EBC536962BA872F5BB64D1996E0050C664924BE9
            AAA24F72014A816D670031D30DE964ECF2E23C7614C55E61CCFC05E5BABFA05C
            F7C6E6727D1DBE3295885FAF9DC28FC68E9D555139F2B57F1963F6D3CEB22997
            CD25ADC9C6A29FD483727D9DEA485DBD634CA3F6E3DF08F313A964FCA8EC4FDA
            5100B607CA750DA18EFB64E4276AC70000106F512AB8AB7608003F0A47EB96CB
            546AB8768E0D8A5996A228F60E63E62F28D7FD05E5BA37F697EBF46E2755EED3
            96B8B95D3B88DF84A2F5E71BA2DBB4736C8E61F7A096E4DCE78A3F2628D7B3AA
            CFA9DDC3C938CBB41FFF6606E4AC54D3DCDF6AC700D81E28D73584DBBF2E43FF
            63ED18000039A6E7206A195EF4892E6C5E341AAD4C24125DDA3960EBC2D17ACB
            CEB229DE997E288ABDC398F90BCA757F41B9EE8D0FCA75C2D9EBDE1D3D73E680
            1DDFCB3C6BE359EB32617A399D88EDA3B16D94EBBDC6C2C6F73ED3D39D6FEF79
            645BDBEC1EED2800FD85725D4375C76872E861ED180000392ECFA0D6AA98768C
            72561D9DB9B7C3EEB5B2F0383D7B834C5994BF29DF7FD5499557E3AC2D3B9D32
            A9F6633D01E725ED1CBD31F1F9E9447C5E31B685A2D83B8C99BFA05CF71794EB
            DE5859B07D04AFE09E0107A6EFB9F52DED247E21CFEBE5F2BCFE483BC7E668DE
            A816E57AAFB188D45F23AF916F6B8FC1A6640DF4A57422F64BED1C00FD85725D
            43F6BAEB033BB21F250F6A47010010314A0567688728573591E987B8E4B49131
            3B6FFAFFC9E27CA913084C6CB97BCE4BDA396163E1C9F5A79243BFD3CEB111E6
            702A194F17E5F1A328F60C63E62F28D7FD05E5BA37FE28D773856C633A199FA9
            9DC30F7297FCE831CFC97CB24A3BCBE6189727B72C882FD4D836CAF55E6331A5
            EE78C3E6CFDA63F051BCA2872B0E7D2039C7BECBD6006C0394EB5AC21DADF275
            BC760C0000F114A582876B872857B2C07D5416B89FE9EBFF9705FADB32093E33
            B5A0F121EDACF02159A87D47166ADFD7CED19BEBF021AD77C79F2DC6B650147B
            8731F31794EBFE8272DD1BBF94EB825D43635A9B628F6807B15D385297206322
            DA393647DE0F5D81816B4636DF79E74A8DEDA35CFFD0AC59B39C8796BEF69A8C
            C7EEDAE3B0299997DC27F392D3093737051F42B9AE25D4FE1D39F859B5280780
            32C5EC120D194669A7433B4AB99185508D1C0B7EBFB57F4F269B9D72C8BE309D
            88DDAE9D19D6D9DA2F45340CEA7487DD7BEFDC55C5D8168A62EF3066FE8272DD
            5F50AE7BE3A3723D3B96CF7505BB8F689B376FAD76165B852233CE3186EFD2CE
            D197F5A5E9695ADB47B9BE31597FDC28EB8FAF698FC3E6E0F230E05728D7B554
            B74F20C7346BC70000C871CD89D43AC4C28F0896B670A4BE4D8EC4276DEBBF2F
            0BCCB9AB68E8971E49FEDF1AEDECE52CF7D1EB8CF31A59348F9285EB6BB270DD
            AB58DB4351EC1DC6CC5F50AEFB0BCA756FFC54AEE730FD9FBCFEAD2C03B565E7
            24A6C7794A9ECF1DB5B3F489E95C79FEEED4DA3CCAF58D85A3F547CBB7BF698F
            C3E6644F280A18E7C4E6A6C6BF6A67F129139E5C3F911D1E2F8339848CF967E5
            8001BFBEFFD7B7BCAF1DACD459B3282C3B1397EF40DD03DED38E0100B08EFB75
            4A0DBD513B4539094F9E31861CFE8BE7FF90E969C3744ECB82D833DA8FA15CC9
            22ED7BB2489BA59DA33766BA3F9D8C9D5AACEDA128F60E63E62F28D7FD05E5BA
            37BE2BD7295B48D29932F759A49DC326D168B472390D7B50E62463B4B3F489B9
            9D0775EE969E3F5FED13B228D73F2A14AD7FD210597959D0EC092303A8E7D38B
            13F3DED4CEE227633F3F73E7CA9ECC4279AD9FD8FB9F33F3FBF25C7F21958CE3
            E4DE0242B9AE29DCFEBC3C050768C7000090A3EEDD94AE3A473B46390947EAEF
            97A3F029FDF96F73978961F39D1166C54D894422A3FD58CAC9A9A7CE1CD235D8
            7D457EDC493BCB26AE4B2562DF2AD6C650147B8731F31794EBFE8272DD1B3F96
            EB32A62BD90D1CD3BA70CE0BDA596C21CFE3CFE579FC92768E2D62BE3D958C4F
            D78C8072FDA3644CBE2263F253EDB1D8827F0CEA74C716EB72877E571D9D39DC
            B0DBD6E77E9D69AD21F7E496E4DC87B5B3962A94EB9A421DF3E51998AA1D0300
            403C4BA9E021DA21CA4578CAF44F11079ED8EE3F88F9113740B5C5BA8925643F
            4A5B77854C9FAED3CEB12999D09DDD928835156D1C50147B8631F31794EBFE82
            72DD1B3F96EB39CCCF3BE49ED09CBCED6DED28DAC291BA2F91313FD7CEB1352E
            3927B6261A542F3D8972FDA372652C655E977119A23D1E7D91FDE88303D73AA7
            DE775FC36AED2C36AB993A7558A673707AEBF782E2B78C53716CCBDD735ED2CE
            5C8A50AE6B0A777C59BEFE4C3B060080CC5E32D415ACA236839B4515812C6A7F
            2313A0B3F3F287317733D14D34A8F36ACD8FDC960359C8EECF869EB471215241
            DDBB17F3E3B3288ABDC398F90BCA757F41B9EE8D6FCBF51C7EB4724DE0E4722E
            DCE4F98BC838DC6D8C71B4B36C11F353A9645CFDD22328D7372F1CADBF55BE5D
            A09D634B50B06FD9D833A68DA81C30A065EBC5FA7A4CCFBAC639AE35D1B0423B
            7BA941B9AEA97AF509E4F09FB4630000E464F8285A52F50FED18A52E57D092F9
            974C8202F9FC73B3D72724762E4F271BEFCEFD2DE455F6BAA62B68D81F65EA74
            AC76964DC9C263693A193BB498DB4451EC1DC6CC5F50AEFB0BCA756FFC5DAE97
            77E1561D9971BA436E928C19A09D656B0CD1452D89D8ADDA3950AE6F5EF5D975
            073BAEC9DEC3C9EA5E50E62B7F620A9C8642786313CE9AB13B073825CFDE615E
            FE3B666E7D6FC7C0298F3734746B3F865262F59BA8E4D5BC338CDCC1D8410080
            1D98CFA774D53CED18A52E14A96B30C6CC28E026FE268BCE6FCAA2FE01EDC75A
            424C285A1F974993EA3543FBC4FCCB54325ED46BAEA228F60E63E62F28D7FD05
            E5BA377E2FD77398FEE21A676239156E13A2F5539879BE1F8A75F16EE51A676F
            1B7E018272BD6FE148DD22793D9DAE9D63AB989EAE70DD53172F9CFBB276141B
            C8BAE40819937B653FBE573FFF88582A112BE47AB4ECA05CD7166AFFAFECCCF6
            D18E010020B3969B28557599768A52567D4EED1E4E8F79A9488BA2946B68566B
            53EC11EDC7ED77A148DDF5C6986F6AE7E8934BA7A516C4EE2BE62651147B8731
            F31794EBFE8272DD9B9228D7B3989F704DE08CD644C32BDA510A4D8E215F96FD
            F64FACBF14CC07F89A5422FE1DED145928D7FB563DA57EB4C3E4939B5CF25B6C
            389A6E9AFB47ED249AB297853244B7CB9C32B89D7FD415A944EC87DA8FA754A0
            5CD7166E5F244F83FDBF2904807290A2547082768852168ED4DD48C67CAD98DB
            CC7E74DA38EED5A9A6B90F6A3F7E1F32B220BB491664976807E98B3CBF2B03ED
            8377696EFE796731B78BA2D83B8C99BFA05CF71794EBDE944CB99EC5F43FD7A1
            334BF56482B1636755548E5CF63379BE2ED2CEB2CD983A3A0738FBB4DDD5F08E
            76942C94EB5B26EB9366599FF8620D28FBD68C7CFDD6984347DD307BF66C573B
            4F31E52E51C9C37F2C73C9AFE4EBCF94D7E264792D2ED47E6CA500E5BAB670C7
            D5F2F52AED180000325B7989D255FB6AC72855E3CF3C6FA740C5C097F3709641
            BF30F35FE5A0FF93E1666532914874698F87ED267EE1A21DBABBBA6EB7FEA3B2
            4CF353C9D879C5DE2C8A62EF3066FE8272DD5F50AE7B5352E57A56EEE6EEE6DB
            32E6375009DD7726FBBA7633995FCB73759C76162F64CEF9C374327E85768E0D
            50AE6F99BFCE5E5F277BF2101BE7FC72F8D44AD6FACBC0DC9EF7FD36F31AC771
            C6363735FE55FB31FA1DCA756D13564F9117F4DDDA310000645FE4D288E0604A
            1814AF052013FBEFC9C47E96760E998CBE49866FCE04A8E181DFC4FFA79DC746
            E168FDD1F2AD49FEFAB87696AD710D4F6C6D8A2F2EF67651147B8731F31794EB
            FE8272DD9B922BD7D7CBDEA88F4DA0AE140A3739664C65A29BE5791AA69DC513
            E6F6CE01817D6D396B3D0BE5FAD685A2F50B0CD124ED1C9EC86B8D0D7D7BCC21
            A37E51AA67B19F7AEACC215D833357CA8F57C82BA7A2201B61FA5F85EB1E8BEB
            D96F1F94EBDA42ED479031FFD08E010090E3660EA1D661CF6AC7283563A31757
            5572D7CBB240DA513BCB87B84726538B0D9BB9EFECE42CC61DE3896A6ABE3C30
            53B5E65B86F84A3FDC2C2CFB8B92F77674F6D678EE50147B8731F31794EBFE82
            72DD9B522DD773983AC8B8DFEB7C6BAF9FB4B5CDEED18EE3D5F849D33F1E709C
            9BFD72998E8F609E954AC6BFAF1DA33794EB5B573DE982039C40CFD28215B805
            94DDDF3ACC97D836A6DBC9C87E7AB2AC49B29714DDBBD01B9339E1334C81E3CB
            E906D1F986725D5BC80D9259D3AE1D030020C7D099D4125CA41DA3D484237597
            C9C4E806ED1C7D62CA9EC1FE6BD7A1A6D6A6D8A354421FA9DE16B366CD72FEB2
            74D9D986F907C64F371967FA5E2A199BADB16914C5DE61CCFC05E5BABFA05CF7
            A6A4CBF50D989E76C97CBB35D978AF76946D31F68C6923060EA8B85C7EBC54E6
            8C83B5F3F447F697FE5DA6F280B6C4CD56F51B28D7B78DCC536E9279CAA5DA39
            FA8DB9C565BEAA75C1DCBF6947D91EB26EAC917DC035F2E3D145DE74AAF3AD3D
            27FAF197923640B96E8350FBABF2E619A51D030080C8FD3AA586DEA89DA29464
            6F3EB39C86BD2493FADDB5B36C0B5918BD6A8813F25772F4A17B3D5AAA1FB3CC
            CA9DA93E74F53986CD37654674B0761E4F98BB7B2A682FAD4BFBA028F60E63E6
            2F28D7FD05E5BA376551AEAF27CFC5C3ECD0ECD6A6588A2C3C79A066EAD4616E
            D7E0ECCD4AB3C5FA4EDA79B6871C57CE97E3CA3CED1C9B42B9BE6DB2AFC54CE7
            E0E764DFB09B7696ED91BB3C94636EB0F53DBF39D91B170F1CB9EC6C790F7DCD
            187394629439A944EC42EDF1F02394EB3608753C28CFC438ED180000321BB985
            D255176BC72825E168FD4CF936473B473FBD2B93BC6626733F7777A696FCF68E
            77B503E543F6C64DC6A5A986F81C326667ED3CFD21CFCB9DB2803D576BFB288A
            BDC398F90BCA757F41B9EE4D3995EB1B642F7B20C7FD9B7860D7DDE9F9F33BB4
            F3D49C3D63BF8CCBD9527DA6211AAA9D67FBF1A3A9443C7BE355EBCA4C94EBDB
            2E7BAD7F99ABCCD7CE910FCCFCA231A6B18703F31F48CE59A69D677326446A3F
            C1C6A99577CD3419F75DB5F3E4307F3D958CE3643B8F50AEDB20D43E4716F733
            B5630000C881FD3E4A074FD38E512AB26721548E7CED5F32B1DB4F3B4B1EB0AC
            969E32CC7F92EF6D034CCF9F1627E6BDA91D6A5B646F06B476887BA2610AC9C4
            E72CF2C18D4AB7821DCE1CD69CBC6DA9560014C5DE61CCFC05E5BABFA05CF7A6
            1CCBF50F30B71399052EBB77BCBF53C51F8B79DF92B19F9FB9F3C01EF72CD9FF
            9E67C89CA83D14F922AFF78C1CDF8E4927624F6867D91C94EBDEC8FEE1F7B27F
            A8D1CE9147F212E53FCBF77B028E736FF3DD8D2F2A6631A168BDEC7BF934C366
            8ABC6F0ED31E9C4D31B36B1C9E9C6A9AFB5BED2C7E8272DD06A1F6EC8DD37EA0
            1D0300403C41A9E091DA214A452832E31C63F82EED1C85B2FE1232D9EB1A3E21
            DF1FCF988AA75A130DAF92EE594BA67AD205FB1BA7E70899E41CC1C68C913463
            649150A93D5E79C3343F958C9DA7190145B17718337F41B9EE2F28D7BD29EB72
            BD17799E56CAFC25C5649A39C00F1D7FD0A8E7F27939BCEC0DED079AB59F6636
            2718A65364CD7F2C95600723E37883BCDE2FD7CED11794EBDE544767EE6DC87D
            BA343E51F151B24879D9303F286FF4BF30398FF6BCBDC7B385BACE78EE1294C1
            B547C87AF033B2DDE3657F33DE179F9A655E23394F4C25628F6B47F18B92DBB1
            FB5278D55422A7243E7A0300BEF70EA58223B5439488EC99094FC881F670ED20
            4525933159A43E2F3F3C278FFDDFF24F5E63875E73C859D6EDB8CB76CAAC7C3F
            914874F5F78F1F3B6DDAA0412B2B7720877774C9DDD338CE3EF28FF791ED66BF
            EF2B7F1D2693C12AED612894ECD96132313F28958CFF5B33078A62EF3066FE82
            72DD5F50AE7B8372BD2FBC42E630FF90F9CB739C9DC718FEAF71E97F1977C03B
            DD99B56F0FAEEA719BEFBC7365F6DFCC96666B06AE1C1CACA4419D5C39D2E1CC
            EE8EA15D999C03E4BFFD84FC190733D1A1C61847FB511576C8F8F9CAB58123EF
            BBAF61B57694BEA05CF72E1CA99B2EF3E9B9DA398A41DEAF9DC4E65FD9B58B3C
            3BAF90E1D7E51FCADA855F3381C05BF29ECEAC5DBB7679EFF77F341A0DBCD535
            64686070C5C08AAEC00E6E853B42F615BBCBFB7E94FC397BB1A103E5CF3C48FE
            D5FD655F1BD07E8CFD1A17A637D938C7B6261A5ED1CEE20728D76D50BD7A2C39
            FC07ED180000399D4306539B59AB1DC3EF26446A27CA84E43EED1C369249EC6A
            C366391B7E5F269E3D3219592113D9F567BB9B1EF9372A72FF1E67CF983101F9
            FFB393D21DE59FEC2013FDC1DAF9955971A32114C5DE61CCFC05E5BABFA05CF7
            06E53AE443F6F211EC98E35B9B628F6867D91294EBFD138AD62F9039F824ED1C
            A088F9A9415D7CFCBDF7CE5DA51DC57628D76D105AB3AFEC61FFA31D030020C7
            0D1C48AD835ED08EE177B2707D4816AEC769E780D2C14C6FAF3F6BFD3DED2C28
            8ABDC398F90BCA757F41B9EE0DCA75C80BA6AB65BFF45DED185B8372BD7F267E
            E1A21DBABABAFE6E8CD9473B0BE861E6A674327EB6760EDBA15CB741942B69C5
            EA4EED18000039AE39915A87FC593B869FD54C99F16997F931ED1C505A98687A
            3A11BB5D3B47168A62EF3066FE8272DD5F50AE7B83721DB6971C431EEA7A6BD4
            D8425DAB3A9F50AEF75F68F28C638D71FF44C60CD0CE027A640D72A4AD372CB6
            05CA755B843ADE926703D73906007D4C93281DB4A750F0A150A4EE1BC6981F6A
            E78012C2FCE754327E12E9DE2CF603288ABDC398F90BCA757F41B9EE0DCA75D8
            2ECCEF50207354EAEEDB5FD58EB22D50AE6F9F70B47EA67C9BA39D03F4C831ED
            3239A6DDA49DC36628D76D11EE582A5F0FD68E01002087CF9994AA6AD44EE167
            E148DD77C998D9DA39A03464AF51CF998A235A17CEB1E6724D288ABDC398F90B
            CA757F41B9EE0DCA75E8AFDC75D699C3AD0BE62ED1CEB2AD50AE6FBF50A46E8E
            3166A6760E50C27C552A19BF563B86CD50AEDB22DCFE27793A4ED08E01002047
            CF2B295575BD760A3F9B30B96E123B6681760E2811CC17CB84F616ED18BDA128
            F60E63E62F28D7FD05E5BA3728D7A1BFE4D8F135397658732CDB1628D7B7DFD1
            33670ED8E97DF73EF931AC9D058ACF6573466BB2F15EED1C3643B96E8B50FB02
            3206776206007D4C37503A78B9760C3F8B46A395CB79D873B801106C2F665E90
            4EC623DA393685A2D83B8C99BFA05CF71794EBDEA05C87FE903949A3CC497C77
            F632CAF5FCA88ECE1C6EC8FDA3213A5C3B0B148FBCEF5F7C6FC7C0C18F373474
            6B67B119CA755B84DAE7103E6603003660BA8DD2C15AED187E178ED61F2D83B9
            440EB5C3B5B3803F31F1BF02956B8F6DBEF3CE95DA593685A2D83B8C99BFA05C
            F71794EBDEA05C07AFE435DDFCDE8ECEE97E2CD850AEE7CF29D169BB7573C59F
            8D31FB69678122606E2763C6A512B1C7B5A3D80EE5BA2DC21D3F90AF576AC700
            009083E8224A579DA91DA31484A6D41E665CD32C93923DB5B380EF2C773381CF
            D8749DF5DE50147B8731F31794EBFE8272DD1B94EBE085BC9E1F1BB8D6F9EC7D
            F735ACD6CED21F28D7F34BF61FFB1AE23F617D53E298B3BF489B984AC6D3DA51
            FC00E5BA2DC2EDDF96A7E31AED180000A28552C11AED10A5E2E4C8057B5698CC
            EFE4C723B5B3803FC822B68B1C37946E9AFB47ED2C7D4151EC1DC6CC5F50AEFB
            0BCA756F50AEC336637ABAB3BBFBC4B645F3966B47E92F94EBF9178ED4ED2FDF
            FE8082BD34656F5CEC18F3F99644AC493B8B5FA05CB745B8E312F96ACD820B00
            CA19B751AA6A9C768A5272EAA93387740DCEC4E5B07B8E7616B05B76322BDFCE
            4927E309ED2C5B82A2D83B8C99BFA05CF71794EBDEA05C876DC2F4B44399939B
            93B7BDAD1D657BA05C2F8C5CC16E4C8BFCF871ED2C9067CC17A792F15BB463F8
            09CA755B84DB6BE5E9886BC700009089F493940E5ABB20F43399847E89C9DC28
            0BDA4AED2C609F6CB12E8BBFFF974AC6EED4CEB235288ABDC398F90BCA757F41
            B9EE0DCA75D82AE6271C72C37E2FD6B350AE174EF539B57B383D4E8BCC6F0ED3
            CE02DB6FFD5A64BACC377EA59DC56F50AEDB22BCEA0B448EF58B690028034CFF
            A274F060ED18A5AA7A72ED31C69884FCB58F7616B0879F8AF52C14C5DE61CCFC
            05E5BABFA05CF706E53A6C11D35F5CE34C6C4D34ACD08E920F28D70B6BE2172E
            DAA1ABBB7BA1211AA79D05FACF6F6B11DBA05CB745B8237BF3407B26F00050BE
            985FA674D53EDA314AD9D833A68D183860C04FE4283C4D3B0BE863E24E639CA9
            A9A6C605DA59B6158A62EF3066FE8272DD5F50AE7B83721DFA22AFDDDF0E5CEB
            4CF5EBCD4B3707E57AE145A3D1CAE534AC315BCE6A6701EF644EB89AD9F97C6B
            B2F15EED2C7E8572DD1628D701C01628D78B6642A4762293D32047E33DB4B380
            0E667EDF617346CB82D89FB4B37881A2D83B8C99BFA05CF71794EBDEA05C87CD
            62BE69B859F98D442291D18E924F28D78B271CA9BB8C897E648C71B4B3C0B691
            E3D59B8E6326B63435FE5D3B8B9FA15CB745785588C84969C7000040B95E5CD9
            B3D82B070CC85E87BD563B0B141713FF8B3315A7B72E9CF3827616AF50147B87
            31F31794EBFE8272DD1B94EBD09BBC5EBBE498F0C5D6643CA69DA51050AE1797
            EC5F4E3644BF9639CFAEDA5960CB98E89F4CCE69AD898657B4B3F81DCA755B4C
            58354E26F00F6AC7000040B9AEA37A4AFD68996CFFCC18F369ED2C507832995D
            18A85C33BDF9CE3B576A67E90F14C5DE61CCFC05E5BABFA05CF7C6BA729DF92A
            36F41D4366A076947223AFD5570D7124958C3FA69DA55050AE17DF29D169BBF5
            70C59D64CCC9DA59A00F32AFA85CEB5C5C4A9780D28472DD1628D701C01ABC8C
            5255A3B45394A359B366390F2F7DF57C393C5F277FEDA29D07F26FDDD961E61B
            ADC9C69F51AE63F72714C5DE61CCFC05E5BABFA05CF7C6B672DD38817D339CD9
            CD615E84F94F1131DFDB392050D77657C33BDA510A09E5BA8EF5EB9AAF313BD7
            CAFEA6523B0FACC7B45616205F9263545C3B4A2941B96E0B94EB00608F15940A
            8ED00E51CE6AA64E1D96E91AF43539485F2287EAE1DA79203F98F81963DCA9A9
            A6DB9ED4CEB2BD50147B8731F31794EBFE8272DD1B1BCBF596BBE7BC547356FD
            283740BF917DE5F1DA994A1AF31A36E6F274227633F9F817FDDB0AE5BAAED094
            DAC30C3BB7CB8F476B672977D963934BE6BC25C9C6A7B4B3941A94EBB6A85E35
            9E1CA7553B060080789752C19DB54340EEA6403BCA8AE71BB220F8921CB183DA
            79A07F98B8D330FD60B859797D2291E8D2CE930F288ABDC398F90BCA757F41B9
            EE8DADE57AF6E7B1636755548E7CED1A63CC37B5739524E63FBB6E45AD1FEFF7
            D25F28D7F545A3D1C00A1E7689FC78351933583B4FF9E11E59535EFBDE0E816B
            1F6F68E8D64E538A50AEDB22DC71A67CB567020F00E50BD75CB7CEC9E7D4ED5A
            91315F951F2F92BFF0A9023F61FAA32177664B72EE73DA51F20945B17718337F
            41B9EE2F28D7BDB1B95CDFA07A4AFD04E352A3E4DC4B3B5F2960A25586F95BC7
            1D3AEAE6D9B367BBDA798A09E5BA3D4E9954FBB11EC7DC40C644B4B3940B391E
            3D26F3CF0BD289D813DA594A19CA755B845647C97093760C00003904BF40A9AA
            03B553C0478D8D5E5C3590BBEAE539BA5426A57B6BE7812D607E850D7D3B9D88
            DF4925F8916B14C5DE61CCFC05E5BABFA05CF7C60FE57A56F632796ED7E01BE5
            C77AED8C7E26AFC75F73857B79EB6FE6BEAE9D4503CA75FB544FAE1DEF985CC9
            6EED7ED2FFF82DF9EBCAE30ED9EBF672FB859A0694EBB608B59F2F3B96DBB463
            0000C802FE494A0731D1B1D8BA8F4CBF1E31C6BD500EE563B5F3C0469613B9D7
            760EC9FCA26DDEBCB5DA610A0545B17718337F41B9EE2F28D7BDF14BB9BE81BC
            1F3FCB6C6E36640ED2CEEA27D933560D9B4B530B1A1FD2CEA209E5BA9D72373C
            7D66D9B932379A257FFB71ED3C258349D61F7CB36B02DF6F4D34ACD08E532E50
            AEDB22D471813C1BB76AC700009083F12394AA3A4E3B056C9B0991DA4F303917
            30F1F9C6981DB4F3942F5E218BD85B2B2B2B7F78FFAF6F795F3B4DA1A128F60E
            63E62F28D7FD05E5BA377E2BD7B3B227160C18F9FA171DC3DF235C226FCB989E
            25C77C27D5D4B8904AF0D3735EA15CB75B341AAD5C49C36B5DA66FE13250DB81
            B95BDEEC7127E37CBFE59EC637B4E3941B94EBB60877646FEE60CD820B00CA19
            B751AA6A9C760AF066ECB4698306760C984C86A7CADF86E4105FA19DA91C30D3
            9BC6F04F5D0ADC524E6787A028F60E63E62F28D7FD05E5BA377E2CD737187FE6
            793B052A2ABF23FF55F6E4B441DAD9ADC2F42C93F9FE9843F768C265203E8472
            DD1FB2BF401B34F2D5CFBBC67C539EAF43B5F3F806F31A79DFDFCEC6B95ED622
            AF68C7295728D76D11EEB85ABE5EA51D03004026E6F7533A78AA760CE8BFD059
            17EE42153D51C37C2E19335A3B4F29CA1627C6D0CD2B79E81D8F24FF6F8D769E
            624351EC1DC6CC5F50AEFB0BCA756FFC5CAE6F30E1AC19BB73C0FD264A76CABE
            E0FE6CD8DC30FAB03D7F8752FDA350AEFB8EA99E5C7BB263CC57641D731AA1B7
            DC3CA6D75D43BFE4EECE394B7E7BC7BBDA71CA1D5EA4B608B7FF529E8E8BB563
            000088F9940A9EA71D02F24316D0FB92E13365D17526139F608C71B433F91673
            3B13DDC5CC0DAD0BE6FE4D3B8EA6EA485DBD2C7A1AB5737C80F9AA54327EAD76
            8C2D0947EA2E9245E2CDDA397AB9229588FD503B84AD264C99512DEFF5B4768E
            5E62F27CCDD00E61AB932317EC596132AF69E7F800F39F659F74A2768CBE9442
            B9FEC163C99D50D07D81CC732E24437B683F96629139DD6AC37497719C9B5B9A
            1AFFAE9DC766A168DD7C4366AA768E0DD8F009E9A6F85FB473F8C129936A3FD6
            1D30D3E5B53E5DE6507B6BE7D126F312D710A5B3977F1961562E4A24125DDA99
            601D94EBB608B7DF254FC739DA310000E4A8FD134A575DAA1D03F26FECE767EE
            5CD9E39E2A4FF29932491D2F93D42AED4CB663A62E329C72989B0676D16FEFBD
            77EE2AED4C369810A93D8E8D63CD0DD28CCB935B16C4176AE7D892EC0DF9889D
            07B4736C60D83DB52539F77EED1CB6CA9D155BC1AF6BE7D840F64597A593B19B
            B473D82A7B398181BB2C7B9B2CB9163733DF9A4EC62FD2CED197522AD737387A
            E6CC013BBEC793D7DFECFD242AC1AE2357AC19D3CAC4BF0E54AEBDA7F9CE3B57
            6A67F28370B4EE0A79395CA79D633D7638B36B73F2B6B7B583F849F6E6A78F3C
            BDEC78D7D01499C04C366476D7CE54544C4FCB63BFCBE5C0BC0792739669C781
            8F2AB9038E6F853A52F26C84B4630000C8CCFD3B94AEBA463B0614567611BAF3
            BBEE6899A855CB24B59AD81C2B0BED80762E2B3075B0A1161993041BF3FB72BA
            96FAB6CA2E721E5ABAEC1F32913C5C3B0B33BDBA8A867EC2F6CBF344A3D1C072
            1EFE4F799F1DA29D85995F1A61567E02673C6D59285AF73B59C0EB5F268DB9BD
            C2F41CB03831EF4DED28360B45EB6F907DD265DA39D63B2695883DAE1DA22FA5
            58AEF7963DDBB52BE04C7598CE9535F6C1DA8F6F7B640B75790C8F303B4D95A6
            EB6EEC07BCCB7DB28532FFB6E1F241F27C2E4827E311ED1C7EF641D1EE7054E6
            ECA71863F6D3CE5408F25AF9ABECA7171AE67B5A92739FD3CE035B8672DD16E1
            8EECC7CB8FD68E01002093942F523A68D3A50BA0086AA64E1DD6D33DE804E39A
            3132911B2DAF83D1324B086AE72A0AE66E9685ABFCF40053A0F5FD1DE8D1C71B
            1ABAB563D9AEFAECBA831D97FE20D3C95DB43230D12A32FC39BF7CBC3A3C65FA
            A788034BE4C79DF452F00AC738A1E6A6C6BF6A8F87ED4E894EDBAD872AFE28AF
            F103D442C8FE891CE7F3A9A6C605DAE361BB534F9D39A46B909B3D61E978D520
            CC5F4F25E3376A8FC796947AB9DE5B78D2CC83D8714F33F212F1CBE5F124E71B
            322ACD12B4B962C080F4FDBFBEE57DED4C7E178ED49D2DFB86F932AE155A1998
            E939CA549C94BEE7D6B7B4C7A39464EFB9E16632E38DE16A6623DF69A476A67E
            617E858D596298965498EE25F8459ABFA05CB745A8E30D793676D38E010090BB
            44556AC8DDDA294057EE2C5B1AFE4959D88D769965016E3E65883F5912979261
            CEDEF4EE7139EE3E2E93F0C768D0DA47D3F3E77768C7F2A3756783F55CC94413
            6531B343B1B62BCFDB4A793D2E7102CE35CD7737BEA83D0E5EACBF36F4779879
            42D1C7CC508B2CEE7F904EC6ACB9F1A3ED267EE1A21DBABBBB2F97019C2CFB8C
            5D8BB55D794F65AFA7FC1759685F9B4EC49ED01E07BFA8A9F9F2C04CD59AAFC8
            FEE10B72BCDA277B75E3626C57DE5F5DB2CDBF1BC7B9A1A5A9B1557B1CB6A69C
            CAF5DEC69E316DC4C08A0127904327CAB33656DE6847C9EB6480E663977D7246
            BE3E698CF9ABFCCDA30EB98F36276F5BAA99A954554FAE3D46C6F90A43E60432
            5CBCB3D8D9BC2EFBF48581816B7E844BF9149CA9894C3FD8A5C03132F047C911
            E02839961E69DBFA257BCF04F9F68461F3289379CC757B1E5BB2F0B6FF68E782
            FE43B96E83A37900EDD4D1294F079E0F00D0C7EE784A0FB5E6BAC060155373F6
            8C8F67327CB821CE5EDA627F99B4EE2713C3FDACBC8958F60C10A2E725F6BF64
            11F5824CAE9F9545EB13B8CE25000094B3722DD73795FD654C77B0E310C77164
            2CF853868CCC6D785F62DA27EFA53BF31A36E605F9FE822CFA9F93F9D3F30EF3
            F32B68F813B65FD60CC0CFB2979179F8A9370EA48A9E83C835FBC9DA607FF9C7
            FBCBFB507E367B17ECB298D94FC6122D93FDCA2BF237FF916D2D95BF9E93B5C8
            D2E166E57F138944467B6C207F50E6DA20B4665F322E7E4B05007670030752EB
            A017B46380BF84CE3D37485D95FB32397B1AA6DD6542B9BB4C32F69449E56E32
            A91C29DF87CBAC6384C97EEFEF0DE7B29747205A217F56F61AE82BE4CF5A2E8B
            DF7799F84DD9C632F9BE2C7B7690719DD7573AC197B158050000F82894EB5B96
            2DE31EFDE7B23D38E0EEC5ECECC40EED6CC8DD99C9541936C3B2F7A49439CD00
            997304D9F04A99F7B8F29F65EFD7D22D7393B5C4D9B98A799B1C7EC371F99DB5
            DD99FFB52D9AB75CFB7101C04764CF74DFB927E0EC2C6BE09D0CBBBBC9FB7B27
            F9C7C3C8F086CB630E97F7B8FC8F06CB7A63A0FCFFB9F7B2BCDFE51FE5D6236B
            99E97DC798F75DD75D2EFFF0BD4A27F3DAE2C4BCFF51EE8368500E50AEDB60C2
            EA1389F98FDA310000723A870CA636B3563B0694B6EC35DED7B45738C14A1A94
            7106E53E9A9BE99685EA809E8A0055E44A71A6CE4CE75A5E95FD79686660D77D
            F735ACD6CE0D0000E07728D7010000F207E5BA0DC2ABA61239F3B563000010D3
            DB940EAADD9C10000000000A0BE53A000040FEA05CB741A8FD2A32E66AED1800
            00C4F4774A078FD68E01000000008581721D0000207F50AEDB20D4F12B7926CE
            D38E010040C4F752AAEA0CED1400000000501828D7010000F207E5BA0DC2ED7F
            95A7E218ED180000C4FC134A575DAA1D03000000000A03E53A000040FEA05CB7
            41A863A53C1343B563000010D385940ECED18E01000000008581721D0000207F
            50AE6BABE918452EBDAA1D030020C7B89FA596A17FD08E01000000008581721D
            0000207F50AE6BAB5E359E1CA7553B0600404E05EF4E8BABDED48E0100000000
            8581721D0000207F50AE6B0BB55F4EC6FC483B0600805841A9E008ED10000000
            00503828D7010000F207E5BAB650FB6FC898B3B563000010F36394AE3A563B06
            00000000140ECA75000080FC41B9AE2DD4FE0219B3BF760C000011A354708676
            0800000000281C94EB000000F983725D53F57BC3C919B85C3B0600408EA18BA8
            2578AB760C00000000281C94EB000000F983725D5368D5C9329358A21D030020
            C7A1CF5073F0AFDA3100000000A07050AE030000E40FCA754DA1F6ABC898ABB5
            63000010710F3943AAA8D9E9D44E02000000008583721D0000207F50AE6B0A77
            34CBD709DA310000C453940A1EAE1D02000000000A0BE53A000040FEA05CD732
            962B6860C772790A82DA51000088692EA58375DA3100000000A0B050AE030000
            E40FCA752DA18E6365F41FD18E010090C35C4FE9AAB8760C00000000282C94EB
            000000F983725D4BB8FDEB32FC3FD68E010090E3060EA4D6412F68C700000000
            80C242B90E0000903F28D7B5843A7E2FA35FA31D030040FC8F52C1DDB4430000
            000040E1A15C070000C81F94EB1A46BB8369D8EAF764F8076947010020E6264A
            579DAD1D03000000000A0FE53A000040FEA05CD7106AFF1C19B3583B0600C07A
            5FA654F017DA2100000000A0F050AE030000E40FCA750DE1F65FC8D07F513B06
            00404EC63D9C960C7D4A3B0600000000141ECA75000080FC41B9AE21DCFE1F19
            FA7DB563000010F1324A05F7927D126B270100000080C243B90E0000903F28D7
            8BAD7AE5C1E404966AC70000582F4EA960BD760800000000280E94EB000000F9
            8372BDD842EDDF2163BEAF1D030020C7D0646A092ED48E0100000000C581721D
            0000207F50AE175BB8237B5DE3C3B463000010710F396B77A2E69D576A270100
            000080E240B90E0000903F28D78B29BCF220A2C0B3DA310000D6E1364A558DD3
            4E0100000000C583721D0000207F50AE17132E0903003661FE26A5AB7EA41D03
            000000008A07E53A000040FEA05C2F265C1206006CE238FB53F3E017B5630000
            000040F1A05C070000C81F94EBC532A1FD2862F3B8760C00801CA6BF533A78B4
            760C00000000282E94EB000000F98372BD5842ED3F2763BEA41D0300601DBE92
            5255D76BA70000000080E242B90E0000903F28D78BA1C61D4899356FC868EFA0
            1D05002007978401000000284B28D7010000F207E57A3184569F4386EFD28E01
            0090834BC200000000942D94EB000000F98372BD18421D2919E990760C00801C
            E66F50BAEAC7DA3100000000A0F850AE030000E40FCAF5420BADD9974CE64519
            6A8C3500E863CED0001A458BABDED48E0200000000C587721D0000207F50F816
            5AB8FD4619E6AF69C70000C861BA8FD2C1D3B46300000000800E94EB000000F9
            8372BD90C6721555AE5E26A33C4C3B0A00408EA1C9D4125CA81D030000000074
            A05C070000C81F94EB8514EAB85846F897DA310000D67B87860FD99312A64B3B
            0800000000E840B90E0000903F28D70B860D853BFE25437CA07612008075F8A7
            94AABA443B0500000000E841B90E0000903F28D70BA5BAFD1472CCFDDA310000
            3EE0660EA1D661CF6AC700000000003D28D7010000F207E57AA184DBDB64784F
            D28E0100B0DE03940A8ED70E0100000000BA50AE030000E40FCAF54208AD3E89
            0CB769C70000F880A133A925B8483B0600000000E842B90E0000903F28D70B21
            DCD12C5F2768C70000C8617E89C604F7A3D9C6D58E0200000000BA50AE030000
            E40FCAF57CABEE38861CFAAB760C00800FB95FA7D4D01BB55300000000803E94
            EB000000F983723DDF42EDBF2563CED08E010090C3BC9A2A7B46D1FD23DED78E
            0200000000FA50AE030000E40FCAF57C0A771C2D5FFFA61D0300E043FC534A55
            5DA29D0200000000EC80721D0000207F50AEE753A8232D235AAD1D0300601DEE
            2672F6A3D49057B59300000000801D6C2BD75D723ED69A6878453B070000407F
            A05CCF97EA55E3C9715AB5630000F412A754B05E3B0400000000D82314A97FC0
            18FAAC768EF5B87348F790B679F3D66A07010000E80F94EB79C186421D8F9231
            9FD64E0200B00E3351E0404A0DFEB7761200000000B047385A770591B94E3BC7
            3ADC964AC4C769A7000000E82F94EBF910EE982C5F93DA3100003EC07C37A5AB
            CED18E01000000007639FDF4DAA16B2BCD9364CCBEAA4198BB0DF1D896E4DC87
            B5C7040000A0BF50AE6FAF2857D28A8EA764280FD48E0200F0213E8252554F6A
            A70000000000FB8422F5FB1A4309F9F1688DED33D3DBE4705DBA29FE3BEDB100
            0000D81E28D7B757B8FDEB328C3FD68E0100F001E6264A579DAD1D0300000000
            AC66AA23334E72888F64C3238AB241326B8CCB2FB8833B5BD2F3E777680F0000
            00C0F642B9BE3D4E69DF8DBACDF3328A43B5A30000E43067882B0EA6D6412F68
            470100000000000000286528D7B747B8E376F93A4D3B0600402F314A05676887
            0000000000000000287528D7FB2BD471AC8CDE23DA3100003EC46BC931075073
            F035ED24000000F0FFDBBB9F10B9CB3B8EE3DFDFC44A7767122548854285961E
            0C645B1022E2D5CCA835575B434A0918410F42694EC583B7D283A4E841D07A29
            0AC683A7B671DD49A481D2D0A2F6605A50D483201EFC834D32BB4D6DE6F1B796
            B819377FF6BB079FEAEFF55AE6E177FCCC7398C31B76060080AF3B717D331E2E
            BDF8CBE44434CDCDB5A700AC2987626970B0F60A000000802E10D737633479B0
            3D1FAB3D03E002FF8AB3E7BE1FC7B77D507B08000000401788EB59BB976F88A6
            9CF423A6C0FF9512BF8871FF37B567000000007485B89E359CFCBEBDB53DB567
            007CAEC4EBF1D1FC42BCD27C527B0A000000405788EB19A3E59F4494C3B56700
            CC2A77C6D260B1F60A000000802E11D7376AF4F1F6886FFCB37DBABEF61480CF
            95F8638CFBFE9B06000000E04B26AE6FD470F24C7B5BFB6ACF0058533E897357
            ED8C63DF7CA3F61200000080AE11D737E2F6E51F4729CFD59E0130A3C4AF63DC
            FF65ED19000000005D24AE5FC9EEC9B7DB5B7AAD7D6DAF3D05604D793BAEEE2F
            C41F9AE5DA4B00000000BA485CBFACD2C470F9487B4B77D45E02306B3A8AA5AD
            E3DA2B00000000BA4A5CBF9CD1E481F67CBCF60C8019259E8E71FF67B5670000
            00007499B87E29A3533746E9BD124D335F7B0AC0053E8CDEB91DB1B8EDFDDA43
            00000000BA4C5CBF985BA673B16DE56FEDD3CEDA53006694B23FC683DFD59E01
            000000D075E2FAC58C264FB5E7BDB56700CC28B118E3F91FB51FDDA5F6140000
            0080AE13D7BF6878FAA7D1F49EAE3D036046898FE25CFC205EEABF5B7B0A0000
            0000E2FAACD5EF598FDECBEDB5F46B4F0198519ABD319E3F5C7B0600000000FF
            23AE9FB7FA3DEB5B574EB437F2C3DA53006694F25C8C07F7D49E01000000C01A
            71FDBCE1E499F636F6D59E0130A3C47B31FDEF421CBBE6C3DA53000000005823
            AEAF1A9D3E18D17BA4F60C8075A6E5AE383A38527B0600000000B3C4F5DDA76F
            8BA6596A5FBDDA53006695476369F0F3DA2B0000000058AFDB717DB8F2DD88E9
            CBED2D6CAF3D056046895763CBDCADB1D83B5B7B0A00000000EB7537AE0FA7FD
            68564EB44F0BB5A700CC28712AB6F46E8AC5B9B76A4F01000000E0E2BA1BD747
            93DFB6E781DA3300D629CDDE18CF1FAE3D03000000804BEB665C1F4D6E6ECFBF
            D69E01B05E79229606F7D75E01000000C0E57533AE0F274FB6EFFCBEDA3300BE
            E0649C9DDF15C79B7FD71E02000000C0E57533AE8F26AFB5E7CEDA33002EF071
            446F572CCDBD597B080000000057D6D5B8FE7E7B5E577B06C0674A99B6E79E18
            0F5EA83D05000000808DE9685C3FF356FBD6BF577B06C067A6E5A1383AF855ED
            19000000006C5C57E3FAB3ED5BBFA7F60C8028E5F918F7EF6E3F934AED290000
            00006C5C37E3FAF0CC9DD134476ACF003AAEC43FE23FF3B7C4F1E64CED290000
            0000E47433AEAF1A4D5E5C3D6BCF003ACB0F98020000007C857537AE0F4F7F2B
            9ADE9FDAA71DB5A7005D5356A2943D31DEFA52ED25000000006C4E77E3FAAA3B
            3ED816D3B94351CAFE689A2DB5E7001D50E2D5989603716CF0F7DA5300000000
            D8BC6EC7F5F346CBDF89A6DC15A5DCD85EC9B5B5E7005F3BA5FD7B277ACDD178
            71EECF7EBC14000000E0AB4F5C07000000008024711D000000000092C4750000
            0000004812D7010000000020495C07000000008024711D000000000092C47500
            000000004812D7010000000020495C07000000008024711D000000000092C475
            00000000004812D7010000000020495C07000000008024711D000000000092C4
            7500000000004812D7010000000020495C07000000008024711D000000000092
            C47500000000004812D7010000000020495C07000000008024711D0000000000
            92C47500000000004812D7010000000020495C07000000008024711D00000000
            0092C47500000000004812D7010000000020495C07000000008024711D000000
            000092C47500000000004812D7010000000020495C07000000008024711D0000
            00000092C47500000000004812D7010000000020495C07000000008024711D00
            0000000092C47500000000004812D7010000000020495C07000000008024711D
            000000000092C47500000000004812D7010000000020495C0700000000802471
            1D000000000092C47500000000004812D7010000000020495C07000000008024
            711D000000000092C47500000000004812D7010000000020495C070000000080
            24711D000000000092C47500000000004812D7010000000020495C0700000000
            8024711D000000000092C47500000000004812D7010000000020495C07000000
            008024711D000000000092C47500000000004812D7010000000020495C070000
            00008024711D000000000092C47500000000004812D7010000000020495C0700
            0000008024711D000000000092C47500000000004812D7010000000020495C07
            000000008024711D000000000092C47500000000004812D7010000000020495C
            07000000008024711D000000000092C47500000000004812D7010000000020E9
            531E3450DA634CF6890000000049454E44AE426082}
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
        object Memo31: TfrxMemoView
          AllowVectorExport = True
          Left = 414.496060550000000000
          Top = 90.047310000000000000
          Width = 26.456710000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'N'#176':')
          ParentFont = False
        end
        object Line15: TfrxLineView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Top = 313.582870000000000000
          Height = 30.236240000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line16: TfrxLineView
          AllowVectorExport = True
          Left = 748.331170000000000000
          Top = 313.582870000000000000
          Height = 30.236240000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object nroComp: TfrxMemoView
          AllowVectorExport = True
          Left = 444.512060000000000000
          Top = 90.047310000000000000
          Width = 230.551330000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '00002-00012345')
          ParentFont = False
        end
        object Memo35: TfrxMemoView
          AllowVectorExport = True
          Left = 414.496060550000000000
          Top = 115.480339370000000000
          Width = 45.354360000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Fecha:')
          ParentFont = False
        end
        object Memo36: TfrxMemoView
          AllowVectorExport = True
          Left = 461.630180000000000000
          Top = 115.480339370000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '26/09/2020')
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          AllowVectorExport = True
          Left = 348.480520000000000000
          Top = 37.795300000000000000
          Width = 52.913420000000000000
          Height = 34.015770000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -35
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'B')
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          AllowVectorExport = True
          Left = 348.141930000000000000
          Top = 75.590600000000000000
          Width = 52.913420000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'COD. 08')
          ParentFont = False
        end
        object Line4: TfrxLineView
          AllowVectorExport = True
          Top = 37.795300000000000000
          Width = 748.346940000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line21: TfrxLineView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Width = 748.346456692913000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Memo38: TfrxMemoView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Top = 6.779530000000000000
          Width = 748.346940000000000000
          Height = 26.456710000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'ORIGINAL')
          ParentFont = False
        end
        object Line22: TfrxLineView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Height = 343.559055120000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line23: TfrxLineView
          AllowVectorExport = True
          Left = 748.346456690000000000
          Height = 343.559055118110000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line13: TfrxLineView
          AllowVectorExport = True
          Left = 0.220470000000000000
          Top = 343.440944880000000000
          Width = 748.346456690000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Memo41: TfrxMemoView
          AllowVectorExport = True
          Left = 136.622140000000000000
          Top = 163.078850000000000000
          Width = 234.330860000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'Ruperto Godoy 2171 - Santa Fe, Santa Fe')
          ParentFont = False
        end
        object Shape2: TfrxShapeView
          AllowVectorExport = True
          Top = 287.244280000000000000
          Width = 748.346940000000000000
          Height = 26.456710000000000000
          Frame.Typ = []
        end
        object Memo42: TfrxMemoView
          AllowVectorExport = True
          Left = 2.267716540000000000
          Top = 287.244094490000000000
          Width = 340.157700000000000000
          Height = 26.456692910000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            'Comprobante asociado: 000123')
          ParentFont = False
          VAlign = vaCenter
        end
        object Line5: TfrxLineView
          AllowVectorExport = True
          Top = 389.291590000000000000
          Width = 748.346456690000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line6: TfrxLineView
          AllowVectorExport = True
          Left = 0.338590000000000000
          Top = 343.937230000000000000
          Height = 45.354360000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line7: TfrxLineView
          AllowVectorExport = True
          Left = 747.669760000000000000
          Top = 343.937230000000000000
          Height = 45.354360000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 3.779530000000000000
          Top = 347.716760000000000000
          Width = 740.787880000000000000
          Height = 37.795300000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Anulaci'#243'n de factura B Nro 00002-00012456')
        end
      end
    end
  end
  object frxBarCodeObject1: TfrxBarCodeObject
    Left = 64
    Top = 320
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 56
    Top = 416
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Transparency = False
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 128
    Top = 488
  end
  object SD1: TSaveDialog
    DefaultExt = '.pdf'
    Left = 112
    Top = 552
  end
end
