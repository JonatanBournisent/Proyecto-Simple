object fAgregarProveedor: TfAgregarProveedor
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Agregar o modificar un proveedor'
  ClientHeight = 252
  ClientWidth = 445
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
    Left = 17
    Top = 21
    Width = 60
    Height = 13
    Caption = 'Raz'#243'n Social'
  end
  object Label4: TLabel
    Left = 17
    Top = 52
    Width = 40
    Height = 13
    Caption = 'Domicilio'
  end
  object Label5: TLabel
    Left = 17
    Top = 84
    Width = 62
    Height = 13
    Caption = 'Tel'#233'fono Fijo'
  end
  object Label6: TLabel
    Left = 17
    Top = 116
    Width = 76
    Height = 13
    Caption = 'Tel'#233'fono celular'
  end
  object Label7: TLabel
    Left = 17
    Top = 182
    Width = 19
    Height = 13
    Caption = 'Cuit'
  end
  object Label9: TLabel
    Left = 17
    Top = 149
    Width = 24
    Height = 13
    Caption = 'Email'
  end
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 428
    Height = 201
    Brush.Style = bsClear
  end
  object Edit1: TEdit
    Left = 121
    Top = 18
    Width = 307
    Height = 21
    MaxLength = 45
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit4: TEdit
    Left = 121
    Top = 49
    Width = 307
    Height = 21
    MaxLength = 50
    TabOrder = 1
    Text = 'Edit4'
  end
  object Edit5: TEdit
    Left = 121
    Top = 81
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 2
    Text = 'Edit5'
  end
  object Edit6: TEdit
    Left = 121
    Top = 113
    Width = 120
    Height = 21
    MaxLength = 15
    TabOrder = 3
    Text = 'Edit6'
  end
  object Edit7: TEdit
    Left = 121
    Top = 179
    Width = 120
    Height = 21
    MaxLength = 13
    TabOrder = 5
    Text = 'Edit7'
    OnExit = Edit7Exit
    OnKeyDown = Edit7KeyDown
    OnKeyPress = Edit7KeyPress
    OnKeyUp = Edit7KeyUp
  end
  object Button1: TButton
    Left = 19
    Top = 219
    Width = 120
    Height = 25
    Caption = 'Guardar datos'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 306
    Top = 219
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 439
    Top = 185
    Width = 83
    Height = 25
    Caption = 'Modificar un proveedor'
    TabOrder = 8
    Visible = False
    OnClick = Button3Click
  end
  object Edit9: TEdit
    Left = 121
    Top = 146
    Width = 307
    Height = 21
    MaxLength = 50
    TabOrder = 4
    Text = 'Edit4'
  end
  object Button4: TButton
    Left = 162
    Top = 219
    Width = 120
    Height = 25
    Caption = 'Restablecer'
    TabOrder = 9
    OnClick = Button4Click
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
    Left = 360
    Top = 168
  end
end
