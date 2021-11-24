object fAgregarCategoria: TfAgregarCategoria
  Left = 0
  Top = 0
  Width = 480
  Height = 375
  TabOrder = 0
  object CDS: TClientDataSet
    Aggregates = <>
    FieldDefs = <>
    IndexDefs = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    StoreDefs = True
    Left = 542
    Top = 8
    object CDSdescripcion: TWideStringField
      FieldName = 'descripcion'
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 590
    Top = 8
  end
end
