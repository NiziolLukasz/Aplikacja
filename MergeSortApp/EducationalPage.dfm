object fEducationalPage: TfEducationalPage
  Left = 1126
  Top = 159
  BorderStyle = bsToolWindow
  Caption = 'Educational Page'
  ClientHeight = 556
  ClientWidth = 624
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
  object lSign: TLabel
    Left = 408
    Top = 312
    Width = 40
    Height = 25
    Caption = 'Sign'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lTimeName: TLabel
    Left = 248
    Top = 312
    Width = 46
    Height = 20
    Caption = 'Time: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lTimeAmount: TLabel
    Left = 304
    Top = 312
    Width = 32
    Height = 20
    Caption = '0:00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lComparisonsAmount: TLabel
    Left = 368
    Top = 272
    Width = 9
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lComparisonsName: TLabel
    Left = 248
    Top = 272
    Width = 104
    Height = 20
    Caption = 'Comparisons:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessName: TLabel
    Left = 248
    Top = 352
    Width = 103
    Height = 20
    Caption = 'Array access:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessAmount: TLabel
    Left = 368
    Top = 352
    Width = 9
    Height = 20
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object PanelLeft: TPanel
    Left = 0
    Top = 0
    Width = 233
    Height = 556
    Align = alLeft
    TabOrder = 0
    object lAmount: TLabel
      Left = 80
      Top = 440
      Width = 27
      Height = 20
      Caption = '100'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object sbAmount: TScrollBar
      Left = 50
      Top = 416
      Width = 113
      Height = 20
      LargeChange = 100
      Max = 1000000
      Min = 2
      PageSize = 0
      Position = 100
      TabOrder = 0
      Visible = False
      OnChange = sbAmountChange
    end
    object bGenerate: TButton
      Left = 48
      Top = 477
      Width = 121
      Height = 60
      Caption = 'Generate numbers'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = bGenerateClick
    end
    object rgTableTypes: TRadioGroup
      Left = 35
      Top = 33
      Width = 166
      Height = 320
      Caption = 'Table types: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Items.Strings = (
        'Random'
        'Reversed'
        'Constant'
        'Arrow up'
        'Arrow down'
        'Almost sorted'
        'Few unique'
        'Sorted'
        'From file...')
      ParentFont = False
      TabOrder = 2
      OnClick = rgTableTypesClick
    end
  end
  object mInput: TMemo
    Left = 240
    Top = 110
    Width = 370
    Height = 130
    ReadOnly = True
    ScrollBars = ssHorizontal
    TabOrder = 1
    WordWrap = False
  end
  object mOutput: TMemo
    Left = 240
    Top = 400
    Width = 370
    Height = 130
    ReadOnly = True
    ScrollBars = ssHorizontal
    TabOrder = 2
    WordWrap = False
  end
  object bStart: TButton
    Left = 356
    Top = 16
    Width = 109
    Height = 73
    Caption = 'Start'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = bStartClick
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
        Caption = 'Go To'
        object mDyd: TMenuItem
          Caption = 'Dydatic'
          OnClick = mDydClick
        end
        object mAdv: TMenuItem
          Caption = 'Advanced'
          OnClick = mAdvClick
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
  object Timer: TTimer
    Enabled = False
    OnTimer = TimerTimer
    Left = 248
    Top = 8
  end
  object tFormatAnim: TTimer
    Enabled = False
    Interval = 1
    OnTimer = tFormatAnimTimer
    Left = 288
    Top = 8
  end
  object OpenDialog: TOpenDialog
    Filter = '.txt|*.txt'
    Left = 584
    Top = 8
  end
end
