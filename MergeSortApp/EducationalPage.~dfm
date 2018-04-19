object fEducationalPage: TfEducationalPage
  Left = 1271
  Top = 195
  BorderStyle = bsToolWindow
  Caption = 'Educational Page'
  ClientHeight = 556
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clCaptionText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lSign: TLabel
    Left = 248
    Top = 296
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
  object lComparisonsAmount: TLabel
    Left = 368
    Top = 256
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
    Top = 256
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
    Top = 336
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
    Top = 336
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
  object lShowUnsorted: TLabel
    Left = 328
    Top = 100
    Width = 160
    Height = 16
    Caption = 'Show/Hide  unsorted array'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lShowSorted: TLabel
    Left = 328
    Top = 396
    Width = 143
    Height = 16
    Caption = 'Show/Hide sorted array'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lSign2: TLabel
    Left = 432
    Top = 296
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
    object Label1: TLabel
      Left = 160
      Top = 56
      Width = 71
      Height = 13
      Caption = 'Ile razy random'
    end
    object sbAmount: TScrollBar
      Left = 58
      Top = 416
      Width = 113
      Height = 20
      LargeChange = 100
      Max = 10000000
      Min = 2
      PageSize = 0
      Position = 100
      TabOrder = 0
      Visible = False
      OnChange = sbAmountChange
    end
    object bGenerate: TButton
      Left = 56
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
        'From file')
      ParentFont = False
      TabOrder = 2
      OnClick = rgTableTypesClick
    end
  end
  object mInput: TMemo
    Left = 240
    Top = 120
    Width = 370
    Height = 112
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    Visible = False
    WordWrap = False
  end
  object mOutput: TMemo
    Left = 240
    Top = 416
    Width = 370
    Height = 114
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
    Visible = False
    WordWrap = False
  end
  object bStart: TButton
    Left = 362
    Top = 9
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
  object bShowUnsorted: TButton
    Left = 240
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Show'
    Enabled = False
    TabOrder = 4
    OnClick = bShowUnsortedClick
  end
  object bShowSorted: TButton
    Left = 240
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Show'
    Enabled = False
    TabOrder = 5
    OnClick = bShowSortedClick
  end
  object bSaveUnsorted: TButton
    Left = 536
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Save...'
    TabOrder = 6
    OnClick = bSaveUnsortedClick
  end
  object bSaveSorted: TButton
    Left = 536
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Save...'
    TabOrder = 7
    OnClick = bSaveSortedClick
  end
  object mResults: TMemo
    Left = 584
    Top = 368
    Width = 17
    Height = 17
    TabOrder = 8
    Visible = False
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
  object tFormatAnim: TTimer
    Enabled = False
    Interval = 1
    OnTimer = tFormatAnimTimer
    Left = 240
    Top = 8
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '.txt'
    Filter = 'Text documents ( *.txt )|*.txt|All files ( *.* )|*.*'
    Left = 584
    Top = 8
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text documents ( *.txt )|*.txt|All files ( *.* )|*.*'
    Left = 552
    Top = 8
  end
end
