object fAdvancedPage: TfAdvancedPage
  Left = 1477
  Top = 142
  BorderStyle = bsToolWindow
  Caption = 'Advanced Page'
  ClientHeight = 108
  ClientWidth = 283
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lSign2: TLabel
    Left = 16
    Top = 79
    Width = 114
    Height = 25
    Caption = 'Please wait...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object bSortFile: TButton
    Left = 16
    Top = 16
    Width = 105
    Height = 57
    Caption = 'Sort File'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = bSortFileClick
  end
  object rgTypes: TRadioGroup
    Left = 152
    Top = 8
    Width = 113
    Height = 89
    Caption = 'Table types:   '
    ItemIndex = 0
    Items.Strings = (
      'Integer'
      'Double'
      'String')
    TabOrder = 1
  end
  object MainMenu: TMainMenu
    Left = 664
    object mFile: TMenuItem
      Caption = 'File'
      object mStart: TMenuItem
        Caption = 'Start'
        OnClick = mStartClick
      end
      object mGoTo: TMenuItem
        Caption = 'Go to'
        object mDid: TMenuItem
          Caption = 'Didactic'
          OnClick = mDidClick
        end
        object mEdu: TMenuItem
          Caption = 'Testing'
          OnClick = mEduClick
        end
      end
      object mExit: TMenuItem
        Caption = 'Exit'
        OnClick = mExitClick
      end
    end
    object mHelp: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About...'
        OnClick = About1Click
      end
    end
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.txt'
    Filter = 'Text documents ( *.txt )|*.txt|All files ( *.* )|*.*'
    Left = 32
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.txt'
    FileName = 'Sorted array'
    Filter = 'Text documents ( *.txt )|*.txt|All files ( *.* )|*.*'
  end
end
