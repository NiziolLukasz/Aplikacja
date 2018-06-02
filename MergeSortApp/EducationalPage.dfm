object fEducationalPage: TfEducationalPage
  Left = 864
  Top = 254
  BorderStyle = bsToolWindow
  Caption = 'Educational Page'
  ClientHeight = 559
  ClientWidth = 866
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clCaptionText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lSign: TLabel
    Left = 264
    Top = 392
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
  object lCompHS: TLabel
    Left = 400
    Top = 248
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
  object lComparisons: TLabel
    Left = 392
    Top = 120
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
  object lArrAccess: TLabel
    Left = 512
    Top = 120
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
  object lArrAccessHS: TLabel
    Left = 520
    Top = 248
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
  object lSaveUnsorted: TLabel
    Left = 248
    Top = 476
    Width = 119
    Height = 20
    Caption = 'Unsorted array: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lSaveSorted: TLabel
    Left = 248
    Top = 524
    Width = 100
    Height = 20
    Caption = 'Sorted array: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lSign2: TLabel
    Left = 584
    Top = 392
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
  object lAlgoritmName: TLabel
    Left = 240
    Top = 120
    Width = 119
    Height = 20
    Caption = 'Algorithm Name'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lHS: TLabel
    Left = 248
    Top = 248
    Width = 71
    Height = 20
    Caption = 'HeapSort'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lMS1: TLabel
    Left = 248
    Top = 168
    Width = 112
    Height = 20
    Caption = 'MS with 1 table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lMSHalf: TLabel
    Left = 248
    Top = 208
    Width = 130
    Height = 20
    Caption = 'MS with half table'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lCompMS1: TLabel
    Left = 400
    Top = 168
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
  object lCompMSHalf: TLabel
    Left = 400
    Top = 208
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
  object lArrAccessMS1: TLabel
    Left = 520
    Top = 168
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
  object lArrAccessMSHalf: TLabel
    Left = 520
    Top = 208
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
  object lQS: TLabel
    Left = 248
    Top = 288
    Width = 74
    Height = 20
    Caption = 'QuickSort'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessQS: TLabel
    Left = 520
    Top = 288
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
  object lCompQS: TLabel
    Left = 400
    Top = 288
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
  object lArrChanged: TLabel
    Left = 632
    Top = 120
    Width = 112
    Height = 20
    Caption = 'Array changed:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrChangedHS: TLabel
    Left = 640
    Top = 248
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
  object lArrChangedMS1: TLabel
    Left = 640
    Top = 168
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
  object lArrChangedMSHalf: TLabel
    Left = 640
    Top = 208
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
  object lArrChangedQS: TLabel
    Left = 640
    Top = 288
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
  object lSortTime: TLabel
    Left = 760
    Top = 120
    Width = 81
    Height = 20
    Caption = 'Time (ms):'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lSortTimeHS: TLabel
    Left = 768
    Top = 248
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
  object lSortTimeMS1: TLabel
    Left = 768
    Top = 168
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
  object lSortTimeMSHalf: TLabel
    Left = 768
    Top = 208
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
  object lSortTimeQS: TLabel
    Left = 768
    Top = 288
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
    Height = 559
    Align = alLeft
    TabOrder = 0
    object lRepeat: TLabel
      Left = 16
      Top = 369
      Width = 48
      Height = 16
      Caption = 'Repeat:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clCaptionText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object lAmountName: TLabel
      Left = 48
      Top = 408
      Width = 123
      Height = 20
      Caption = 'Size of the table:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clCaptionText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object rgTableTypes: TRadioGroup
      Left = 35
      Top = 33
      Width = 166
      Height = 320
      Caption = 'Types of table: '
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
    object sbAmount: TScrollBar
      Left = 114
      Top = 440
      Width = 113
      Height = 20
      LargeChange = 100
      Max = 10000000
      Min = 2
      PageSize = 0
      Position = 1000
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
    object eAmount: TEdit
      Left = 8
      Top = 440
      Width = 97
      Height = 21
      TabOrder = 3
      Visible = False
      OnExit = eAmountExit
    end
    object eRepeat: TEdit
      Left = 80
      Top = 368
      Width = 49
      Height = 21
      TabOrder = 4
      Text = '1'
      Visible = False
      OnExit = eRepeatExit
    end
  end
  object bStart: TButton
    Left = 506
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
    TabOrder = 1
    OnClick = bStartClick
  end
  object bSaveUnsorted: TButton
    Left = 392
    Top = 472
    Width = 89
    Height = 25
    Caption = 'Save table...'
    Enabled = False
    TabOrder = 2
    OnClick = bSaveUnsortedClick
  end
  object bSaveSorted: TButton
    Left = 392
    Top = 520
    Width = 89
    Height = 25
    Caption = 'Save table...'
    Enabled = False
    TabOrder = 3
    OnClick = bSaveSortedClick
  end
  object bSaveResults: TButton
    Left = 512
    Top = 520
    Width = 89
    Height = 25
    Caption = 'Save results...'
    Enabled = False
    TabOrder = 4
    OnClick = bSaveResultsClick
  end
  object MainMenu: TMainMenu
    Left = 272
    Top = 8
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
    Left = 272
    Top = 40
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '.txt'
    Filter = 'Text documents ( *.txt )|*.txt|All files ( *.* )|*.*'
    Left = 240
    Top = 40
  end
end
