object fStartingPage: TfStartingPage
  Left = 248
  Top = 247
  Width = 1092
  Height = 675
  Caption = 'Starting Page'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object bDidacticPage: TButton
    Left = 176
    Top = 280
    Width = 177
    Height = 73
    Caption = 'Didactic'
    TabOrder = 0
    OnClick = bDidacticPageClick
  end
  object bAdvancedPage: TButton
    Left = 672
    Top = 280
    Width = 177
    Height = 73
    Caption = 'Advanced'
    TabOrder = 1
    OnClick = bAdvancedPageClick
  end
  object bEducationPage: TButton
    Left = 424
    Top = 280
    Width = 177
    Height = 73
    Caption = 'Education'
    TabOrder = 2
    OnClick = bEducationPageClick
  end
end
