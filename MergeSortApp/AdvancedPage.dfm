object fAdvancedPage: TfAdvancedPage
  Left = 1079
  Top = 906
  Width = 678
  Height = 211
  Caption = 'Advanced Page'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
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
          Caption = 'Educational'
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
      object mAbout: TMenuItem
        Caption = 'About...'
      end
    end
  end
end
