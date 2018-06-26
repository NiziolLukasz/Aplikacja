object fStartingPage: TfStartingPage
  Left = 685
  Top = 298
  BorderStyle = bsToolWindow
  Caption = 'Starting Page'
  ClientHeight = 116
  ClientWidth = 716
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = -8
    Top = -8
    Width = 745
    Height = 153
    TabOrder = 0
    object bAdvancedPage: TButton
      Left = 525
      Top = 30
      Width = 180
      Height = 73
      Caption = 'Advanced'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = bAdvancedPageClick
    end
    object bDidacticPage: TButton
      Left = 25
      Top = 30
      Width = 180
      Height = 73
      Caption = 'Didactic'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = bDidacticPageClick
    end
    object bEducationPage: TButton
      Left = 275
      Top = 30
      Width = 180
      Height = 73
      Caption = 'Testing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = bEducationPageClick
    end
  end
end
