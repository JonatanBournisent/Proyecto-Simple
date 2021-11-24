object fAgregarCliente: TfAgregarCliente
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Agregar un cliente'
  ClientHeight = 451
  ClientWidth = 481
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
    Left = 18
    Top = 21
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object Label2: TLabel
    Left = 18
    Top = 53
    Width = 37
    Height = 13
    Caption = 'Apellido'
  end
  object Label3: TLabel
    Left = 18
    Top = 86
    Width = 59
    Height = 13
    Caption = 'Razon social'
  end
  object Label4: TLabel
    Left = 18
    Top = 118
    Width = 40
    Height = 13
    Caption = 'Domicilio'
  end
  object Label5: TLabel
    Left = 18
    Top = 184
    Width = 62
    Height = 13
    Caption = 'Telefono Fijo'
  end
  object Label6: TLabel
    Left = 18
    Top = 282
    Width = 76
    Height = 13
    Caption = 'Telefono celular'
  end
  object Label7: TLabel
    Left = 18
    Top = 347
    Width = 19
    Height = 13
    Caption = 'Cuit'
  end
  object Label8: TLabel
    Left = 18
    Top = 380
    Width = 51
    Height = 13
    Caption = 'Descuento'
  end
  object Label9: TLabel
    Left = 18
    Top = 151
    Width = 24
    Height = 13
    Caption = 'Email'
  end
  object Label10: TLabel
    Left = 18
    Top = 314
    Width = 108
    Height = 13
    Caption = 'Condicion frente a IVA'
  end
  object Shape1: TShape
    Left = 7
    Top = 8
    Width = 466
    Height = 401
    Brush.Style = bsClear
  end
  object Label11: TLabel
    Left = 278
    Top = 184
    Width = 18
    Height = 13
    Caption = 'Int.'
  end
  object Label12: TLabel
    Left = 18
    Top = 216
    Width = 71
    Height = 13
    Caption = 'Telefono Fijo 2'
  end
  object Label13: TLabel
    Left = 278
    Top = 216
    Width = 18
    Height = 13
    Caption = 'Int.'
  end
  object Label14: TLabel
    Left = 18
    Top = 249
    Width = 71
    Height = 13
    Caption = 'Telefono Fijo 3'
  end
  object Label15: TLabel
    Left = 278
    Top = 249
    Width = 18
    Height = 13
    Caption = 'Int.'
  end
  object Edit1: TEdit
    Left = 150
    Top = 18
    Width = 314
    Height = 21
    MaxLength = 45
    TabOrder = 0
    Text = 'Edit1'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 150
    Top = 50
    Width = 314
    Height = 21
    MaxLength = 45
    TabOrder = 1
    Text = 'Edit2'
    OnChange = Edit2Change
  end
  object Edit3: TEdit
    Left = 150
    Top = 83
    Width = 314
    Height = 21
    MaxLength = 45
    TabOrder = 2
    Text = 'Edit3'
    OnKeyDown = Edit3KeyDown
  end
  object Edit4: TEdit
    Left = 150
    Top = 115
    Width = 314
    Height = 21
    MaxLength = 50
    TabOrder = 3
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 150
    Top = 181
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 5
    Text = 'Edit5'
  end
  object Edit6: TEdit
    Left = 150
    Top = 279
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 6
    Text = 'Edit6'
  end
  object Edit7: TEdit
    Left = 150
    Top = 344
    Width = 120
    Height = 21
    MaxLength = 13
    TabOrder = 8
    Text = 'Edit7'
    OnExit = Edit7Exit
    OnKeyDown = Edit7KeyDown
    OnKeyPress = Edit7KeyPress
    OnKeyUp = Edit7KeyUp
  end
  object Edit8: TEdit
    Left = 150
    Top = 377
    Width = 65
    Height = 21
    TabOrder = 9
    Text = 'Edit8'
    OnClick = Edit8Click
    OnEnter = Edit8Enter
    OnExit = Edit8Exit
    OnKeyPress = Edit8KeyPress
  end
  object Button1: TButton
    Left = 15
    Top = 419
    Width = 130
    Height = 25
    Caption = 'Guardar datos'
    TabOrder = 10
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 173
    Top = 419
    Width = 130
    Height = 25
    Caption = 'Restablecer'
    TabOrder = 12
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 464
    Top = 235
    Width = 89
    Height = 25
    Caption = 'Modificar un cliente'
    TabOrder = 11
    Visible = False
    OnClick = Button3Click
  end
  object Edit9: TEdit
    Left = 150
    Top = 148
    Width = 314
    Height = 21
    MaxLength = 50
    TabOrder = 4
    Text = 'Edit4'
  end
  object ComboBox1: TComboBox
    Left = 150
    Top = 311
    Width = 145
    Height = 21
    TabOrder = 7
    Text = 'ComboBox1'
    OnChange = ComboBox1Change
  end
  object Button4: TButton
    Left = 332
    Top = 419
    Width = 130
    Height = 25
    Caption = 'Salir'
    TabOrder = 13
    OnClick = Button4Click
  end
  object Edit10: TEdit
    Left = 302
    Top = 181
    Width = 43
    Height = 21
    MaxLength = 5
    TabOrder = 14
    Text = 'Edit10'
  end
  object Edit11: TEdit
    Left = 150
    Top = 213
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 15
    Text = 'Edit11'
  end
  object Edit12: TEdit
    Left = 302
    Top = 213
    Width = 43
    Height = 21
    MaxLength = 5
    TabOrder = 16
    Text = 'Edit12'
  end
  object Edit13: TEdit
    Left = 150
    Top = 246
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 17
    Text = 'Edit13'
  end
  object Edit14: TEdit
    Left = 302
    Top = 246
    Width = 43
    Height = 21
    MaxLength = 5
    TabOrder = 18
    Text = 'Edit14'
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
    Left = 590
    Top = 16
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 590
    Top = 72
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 20
    OnTimer = Timer1Timer
    Left = 480
    Top = 288
  end
end
