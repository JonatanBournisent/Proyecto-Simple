object fConfiguraciones: TfConfiguraciones
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Configuraciones'
  ClientHeight = 634
  ClientWidth = 338
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label20: TLabel
    Left = 8
    Top = 390
    Width = 31
    Height = 13
    Caption = 'Actual:'
  end
  object Label1: TLabel
    Left = 8
    Top = 330
    Width = 187
    Height = 13
    Caption = 'Monto m'#225'ximo para facturas sin datos:'
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 321
    Height = 305
    Caption = 'Configuraci'#243'n de impresoaras'
    TabOrder = 0
    object Label3: TLabel
      Left = 22
      Top = 180
      Width = 128
      Height = 13
      Caption = 'Seleccionada actualmente:'
    end
    object Label4: TLabel
      Left = 156
      Top = 180
      Width = 31
      Height = 13
      Caption = 'Label4'
    end
    object Label5: TLabel
      Left = 23
      Top = 81
      Width = 128
      Height = 13
      Caption = 'Seleccionada actualmente:'
    end
    object Label6: TLabel
      Left = 157
      Top = 81
      Width = 31
      Height = 13
      Caption = 'Label6'
    end
    object Label13: TLabel
      Left = 22
      Top = 130
      Width = 155
      Height = 14
      Caption = 'Impresora para etiquetas'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 23
      Top = 33
      Width = 184
      Height = 14
      Caption = 'Impresora para presupuestos:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 22
      Top = 226
      Width = 89
      Height = 14
      Caption = 'Impresora PDF'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label17: TLabel
      Left = 22
      Top = 276
      Width = 128
      Height = 13
      Caption = 'Seleccionada actualmente:'
    end
    object Label18: TLabel
      Left = 156
      Top = 276
      Width = 37
      Height = 13
      Caption = 'Label18'
    end
    object cboPrinterPresupuestos: TComboBox
      Left = 23
      Top = 50
      Width = 273
      Height = 21
      TabOrder = 0
      Text = 'cboPrinterPresupuestos'
    end
    object cboPrinterEtiquetas: TComboBox
      Left = 22
      Top = 149
      Width = 273
      Height = 21
      TabOrder = 1
      Text = 'cboPrinterEtiquetas'
    end
    object cboPrinterPDF: TComboBox
      Left = 22
      Top = 245
      Width = 273
      Height = 21
      TabOrder = 2
      Text = 'cboPrinterPDF'
    end
  end
  object Button2: TButton
    Left = 22
    Top = 562
    Width = 293
    Height = 25
    Caption = 'Guardar configuraciones y salir'
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 417
    Width = 321
    Height = 139
    TabOrder = 2
    object Label12: TLabel
      Left = 23
      Top = 45
      Width = 209
      Height = 14
      Caption = 'IP o nombre del servidor de datos'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 23
      Top = 66
      Width = 209
      Height = 27
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '127.0.0.1'
    end
  end
  object Button8: TButton
    Left = 8
    Top = 359
    Width = 322
    Height = 25
    Caption = 'Directorio comprobantes electr'#243'nicos'
    TabOrder = 3
    OnClick = Button8Click
  end
  object Edit2: TEdit
    Left = 201
    Top = 327
    Width = 64
    Height = 21
    Alignment = taRightJustify
    TabOrder = 4
    Text = '0,00'
    OnEnter = Edit2Enter
    OnExit = Edit2Exit
    OnKeyPress = Edit2KeyPress
  end
end
