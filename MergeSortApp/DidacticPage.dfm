object fDidacticPage: TfDidacticPage
  Left = 881
  Top = 263
  BorderStyle = bsToolWindow
  Caption = 'Project'
  ClientHeight = 558
  ClientWidth = 994
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -9
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object sRed: TShape
    Left = 240
    Top = 400
    Width = 15
    Height = 6
    Brush.Color = clRed
    Enabled = False
    Visible = False
  end
  object sYellow: TShape
    Left = 248
    Top = 408
    Width = 15
    Height = 6
    Brush.Color = clYellow
    Enabled = False
    Visible = False
  end
  object sBlue: TShape
    Left = 256
    Top = 400
    Width = 15
    Height = 6
    Brush.Color = clBlue
    Enabled = False
    Visible = False
  end
  object lComparisonsName: TLabel
    Left = 240
    Top = 432
    Width = 86
    Height = 16
    Caption = 'Comparisons: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lComparisonsAmount: TLabel
    Left = 328
    Top = 432
    Width = 7
    Height = 16
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessName: TLabel
    Left = 384
    Top = 432
    Width = 79
    Height = 16
    Caption = 'Array access'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lArrAccessAmount: TLabel
    Left = 472
    Top = 432
    Width = 7
    Height = 16
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object PanelBottom: TPanel
    Left = 224
    Top = 447
    Width = 553
    Height = 111
    Align = alCustom
    TabOrder = 2
    object lDelayName: TLabel
      Left = 232
      Top = 64
      Width = 42
      Height = 16
      Caption = 'Delay: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lDelayNumber: TLabel
      Left = 280
      Top = 64
      Width = 32
      Height = 16
      Caption = '2 sec'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object sbDelay: TScrollBar
      Left = 104
      Top = 16
      Width = 345
      Height = 25
      LargeChange = 100
      Max = 4000
      PageSize = 0
      Position = 2000
      TabOrder = 0
      OnChange = sbDelayChange
    end
  end
  object PanelLeft: TPanel
    Left = 0
    Top = 0
    Width = 233
    Height = 558
    Align = alLeft
    TabOrder = 0
    object lAmount: TLabel
      Left = 32
      Top = 416
      Width = 18
      Height = 20
      Caption = '20'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object sbAmount: TScrollBar
      Left = 56
      Top = 416
      Width = 113
      Height = 20
      Max = 30
      Min = 2
      PageSize = 0
      Position = 20
      TabOrder = 0
      Visible = False
      OnChange = sbAmountChange
    end
    object bGenerate: TButton
      Left = 48
      Top = 477
      Width = 121
      Height = 60
      Caption = 'Generate again'
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
      Top = 97
      Width = 166
      Height = 320
      Caption = 'Table types: '
      Color = clBtnFace
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
        'Sorted')
      ParentColor = False
      ParentFont = False
      TabOrder = 2
      OnClick = rgTableTypesClick
    end
  end
  object PanelRight: TPanel
    Left = 774
    Top = 0
    Width = 220
    Height = 557
    Align = alCustom
    TabOrder = 1
    object iRight: TImage
      Left = 114
      Top = 258
      Width = 63
      Height = 63
      Picture.Data = {
        0A544A504547496D616765790B0000FFD8FFE000104A46494600010101004800
        480000FFE1008C4578696600004D4D002A000000080005011200030000000100
        010000011A0005000000010000004A011B000500000001000000520128000300
        0000010002000087690004000000010000005A00000000000000480000000100
        000048000000010003900000070000000430323130A000000700000004303130
        30A001000300000001FFFF000000000000FFE10494687474703A2F2F6E732E61
        646F62652E636F6D2F7861702F312E302F003C3F787061636B65742062656769
        6E3D27EFBBBF272069643D2757354D304D7043656869487A7265537A4E54637A
        6B633964273F3E0A3C783A786D706D65746120786D6C6E733A783D2761646F62
        653A6E733A6D6574612F273E0A3C7264663A52444620786D6C6E733A7264663D
        27687474703A2F2F7777772E77332E6F72672F313939392F30322F32322D7264
        662D73796E7461782D6E7323273E0A0A203C7264663A4465736372697074696F
        6E20786D6C6E733A657869663D27687474703A2F2F6E732E61646F62652E636F
        6D2F657869662F312E302F273E0A20203C657869663A4F7269656E746174696F
        6E3E546F702D6C6566743C2F657869663A4F7269656E746174696F6E3E0A2020
        3C657869663A585265736F6C7574696F6E3E37323C2F657869663A585265736F
        6C7574696F6E3E0A20203C657869663A595265736F6C7574696F6E3E37323C2F
        657869663A595265736F6C7574696F6E3E0A20203C657869663A5265736F6C75
        74696F6E556E69743E496E63683C2F657869663A5265736F6C7574696F6E556E
        69743E0A20203C657869663A466C61736850697856657273696F6E3E466C6173
        685069782056657273696F6E20312E303C2F657869663A466C61736850697856
        657273696F6E3E0A20203C657869663A4F7269656E746174696F6E3E546F702D
        6C6566743C2F657869663A4F7269656E746174696F6E3E0A20203C657869663A
        585265736F6C7574696F6E3E37323C2F657869663A585265736F6C7574696F6E
        3E0A20203C657869663A595265736F6C7574696F6E3E37323C2F657869663A59
        5265736F6C7574696F6E3E0A20203C657869663A5265736F6C7574696F6E556E
        69743E496E63683C2F657869663A5265736F6C7574696F6E556E69743E0A2020
        3C657869663A466C61736850697856657273696F6E3E466C6173685069782056
        657273696F6E20312E303C2F657869663A466C61736850697856657273696F6E
        3E0A20203C657869663A4F7269656E746174696F6E3E546F702D6C6566743C2F
        657869663A4F7269656E746174696F6E3E0A20203C657869663A585265736F6C
        7574696F6E3E37323C2F657869663A585265736F6C7574696F6E3E0A20203C65
        7869663A595265736F6C7574696F6E3E37323C2F657869663A595265736F6C75
        74696F6E3E0A20203C657869663A5265736F6C7574696F6E556E69743E496E63
        683C2F657869663A5265736F6C7574696F6E556E69743E0A20203C657869663A
        4578696656657273696F6E3E457869662056657273696F6E20322E313C2F6578
        69663A4578696656657273696F6E3E0A20203C657869663A466C617368506978
        56657273696F6E3E466C6173685069782056657273696F6E20312E303C2F6578
        69663A466C61736850697856657273696F6E3E0A20203C657869663A436F6C6F
        7253706163653E556E63616C696272617465643C2F657869663A436F6C6F7253
        706163653E0A203C2F7264663A4465736372697074696F6E3E0A0A3C2F726466
        3A5244463E0A3C2F783A786D706D6574613E0A3C3F787061636B657420656E64
        3D2772273F3E0AFFDB0043000201010201010202020202020202030503030303
        030604040305070607070706070708090B0908080A0807070A0D0A0A0B0C0C0C
        0C07090E0F0D0C0E0B0C0C0CFFDB004301020202030303060303060C0807080C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFC2001108003F003F030111000211
        01031101FFC4001B000100020301010000000000000000000000070803040605
        09FFC40014010100000000000000000000000000000000FFDA000C0301000210
        0310000001BC000000001AA6A9EA0001E415D4D92CC000ADC7024C0578319261
        6B815A0E809B0A8C75C5960089C8B0C05713E8E9D180000000000003FFC40021
        10000203000104030100000000000000000506030407020108102000143040FF
        DA0008010100010502FCEEDE846D4107293054F53A76A2C88120C877097F0EAB
        5EF39FA387423A4EB6819A7279D2F6F2D74C739C7E54026FB195FCC36E749DE7
        C0967811B68C066E9488B5118442B63DC345059AF6E5C26351797DCA6274333E
        38C0867B40EE4694F9FDBAAB1221AA2A514A05FC5FFFC4001411010000000000
        0000000000000000000060FFDA0008010301013F0101FFC40014110100000000
        000000000000000000000060FFDA0008010201013F0101FFC4003A1000010303
        0202050808070000000000000102030405111200061331213241518114202233
        5261629110243036404263B1718293D2D3E1F0FFDA0008010100063F02FB371F
        92F351D86864B71C504A503BC93AE3C099166B17C788C3A1C4DFBAE3CE7E7CF7
        D11A2464E6E38BE43FDFBBB74DD4EB0DBD4ED9CC2B890E028E2E543F51CF87FE
        1ED1DD758A3C6441DB92DE6E3C4421B086E429B0429C48EC4FF7778F346DD815
        89F47854783E5531E86B28716EAC8C507F96C7E7AABB154ABD5EBDB7F6C494B4
        86A7BEA5A24CA02C6E9E5647A5D1DB71D848D40D9B47C9B9DB881121FC7D1891
        075D5E3CBE63991A5421BB37001189459879C5377EDB14B789F0D7DEDDD3FD47
        FF00C7AA922833EB353DA0DC448E34E24A532B20716F2B1EA937E8FE3F97E9DF
        9226B32541D890A5B61968B8E38DA521B51481F1287CB5BD696E6425C7AF3D25
        4142C4B6E8182BC713AA94B91C5F268D15D75DE175CA420936F7DB54C6A974CD
        B4B80A6CBCC190B507969592A0558AADDBFB5F5B83714B2CA27D666E1223B0DE
        0DB0A6AFCBBC9CB9F9912A6C54AA346A9C46CB1E530D78A96D9E9C4F8FEE7437
        1D06B126B957F57258A8287D75AF673EFE81CFBBDD635582F449F43AFBD17869
        893E2A8839741B1B588B136C80D438BB66BDB9E5EE57C348453C6696F357AC16
        C40B75B928F8F3D334EA733C08AC5F14DEE493D24927F07FFFC4002210010100
        020201040301000000000000000111213100615110204171304081F1FFDA0008
        010100013F21FC6D9063D9D007DF3208B8AEDD297263BF75FCFDB0E8C1952802
        A9005439A54E0374E387B01D6CF01E6A1811DF32C8035A50F64CBAC70CEA1043
        F7D6202602B2A6D43D854211021B85DC1459BAD0B5C12416A74816B5A37D0097
        FC39D31085D0329E47D32F33D08B12067C52EAF3E3667A01BAB7F4E58D8D46EC
        38C0CEFAE4D58979282DD74CF9079A04E70C4C9C8AD37195BEC3762ABF76E094
        8F9AE2015001D84371860A986781A49120932CC8A0B0A71458C294150517C84C
        8BC06FDF160E40555FF21FA7FFDA000C03010002000300000010000000000000
        020800124820100800004900000000000000FFC4001411010000000000000000
        0000000000000060FFDA0008010301013F1001FFC40014110100000000000000
        000000000000000060FFDA0008010201013F1001FFC4001E1001010002020203
        0000000000000000000111002120314151103040FFDA0008010100013F10FAFB
        7A1117960DE5406363361E90E88C46A91EF926FF00202B000459AAF800568BAF
        DD753602A017192DA7F3B551C64E4E222B0606693B6873A36B7841BC103D62D3
        D80359356024A48A6B8C2AE48035525B6E3A1A449146E23D60AF6D652E686EFB
        7447E480E6381B12A434690216B3EFEC62DC0A7614972B2A5B02ED15AAA1A6C1
        BAD33F219106290240C8EDE70AEF3892D7296BE0755B42551A51281A4D79BDE0
        3AEF480BEC85031818AFFE738D9458A008653880C2F4CD0F7D41036248B0885F
        8ABAA0000FC5FFD9}
      OnClick = iRightClick
    end
    object iLeft: TImage
      Left = 154
      Top = 498
      Width = 63
      Height = 63
      Picture.Data = {
        0A544A504547496D616765620A0000FFD8FFE000104A46494600010101004800
        480000FFE1008E4578696600004D4D002A000000080005011200030000000100
        010000011A0005000000010000004A011B000500000001000000520128000300
        0000010002000087690004000000010000005A00000000000000480000000100
        000048000000010003900000070000000430323130A000000700000004303130
        30A001000300000001FFFF0000000000000000FFE102B6687474703A2F2F6E73
        2E61646F62652E636F6D2F7861702F312E302F003C3F787061636B6574206265
        67696E3D27EFBBBF272069643D2757354D304D7043656869487A7265537A4E54
        637A6B633964273F3E0D0A3C783A786D706D65746120786D6C6E733A783D2261
        646F62653A6E733A6D6574612F223E0D0A093C7264663A52444620786D6C6E73
        3A7264663D22687474703A2F2F7777772E77332E6F72672F313939392F30322F
        32322D7264662D73796E7461782D6E7323223E0D0A09093C7264663A44657363
        72697074696F6E20786D6C6E733A657869663D22687474703A2F2F6E732E6164
        6F62652E636F6D2F657869662F312E302F223E0D0A0909093C657869663A4F72
        69656E746174696F6E3E546F702D6C6566743C2F657869663A4F7269656E7461
        74696F6E3E0D0A0909093C657869663A585265736F6C7574696F6E3E37323C2F
        657869663A585265736F6C7574696F6E3E0D0A0909093C657869663A59526573
        6F6C7574696F6E3E37323C2F657869663A595265736F6C7574696F6E3E0D0A09
        09093C657869663A5265736F6C7574696F6E556E69743E496E63683C2F657869
        663A5265736F6C7574696F6E556E69743E0D0A0909093C657869663A45786966
        56657273696F6E3E457869662056657273696F6E20322E313C2F657869663A45
        78696656657273696F6E3E0D0A0909093C657869663A466C6173685069785665
        7273696F6E3E466C6173685069782056657273696F6E20312E303C2F65786966
        3A466C61736850697856657273696F6E3E0D0A0909093C657869663A436F6C6F
        7253706163653E556E63616C696272617465643C2F657869663A436F6C6F7253
        706163653E0D0A09093C2F7264663A4465736372697074696F6E3E0D0A093C2F
        7264663A5244463E0D0A3C2F783A786D706D6574613E0D0A3C3F787061636B65
        7420656E643D2777273F3EFFDB00430002010102010102020202020202020305
        03030303030604040305070607070706070708090B0908080A0807070A0D0A0A
        0B0C0C0C0C07090E0F0D0C0E0B0C0C0CFFDB004301020202030303060303060C
        0807080C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFC0001108003F003F0301
        2200021101031101FFC4001F0000010501010101010100000000000000000102
        030405060708090A0BFFC400B5100002010303020403050504040000017D0102
        0300041105122131410613516107227114328191A1082342B1C11552D1F02433
        627282090A161718191A25262728292A3435363738393A434445464748494A53
        5455565758595A636465666768696A737475767778797A838485868788898A92
        939495969798999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7
        C8C9CAD2D3D4D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FA
        FFC4001F0100030101010101010101010000000000000102030405060708090A
        0BFFC400B5110002010204040304070504040001027700010203110405213106
        1241510761711322328108144291A1B1C109233352F0156272D10A162434E125
        F11718191A262728292A35363738393A434445464748494A535455565758595A
        636465666768696A737475767778797A82838485868788898A92939495969798
        999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
        D5D6D7D8D9DAE2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002
        110311003F00FDC0A28A3AD0014515C3FC6AFDA6FE1B7ECD96BA7DC7C45F885E
        07F00C1AB3BC7632788F5DB5D296F19002E2333BA072A19490B9C6E19EA2803B
        8A2A1B0BF8355B086EAD6686E6DAE63596196270F1CA8C32ACAC382082082382
        0D4D4005145140051457E30FFC150BC69E038BFE0AABE3CD2FF6C4F8ADF1DBE1
        47C1B8FC3BA5CBF090F83E6B98746D63112FF6A198DA453B1BA5B9775F9A30DE
        5E37B0416E1C03F67ABF2DFF006E6F81FF000F6D3FE0BC3E01D53F68DF0669DE
        3DF83FF1D3C04DF0E3C277BAB5AACBA7F8635F170CE2D9B0D98A49D64221B8C2
        C825BBFDD9510C9227CA7FDBFF00F04AEFFA3B6FDA93EBF6FD77FF0095B57BC3
        7FB26FFC136FFE0A0BA82FC2BF01FED59F1AAEFE227891648BC25178B751D43F
        B386AC62916D58ADDD945148E1D828884A924BBCC71B6E71401F5041AE7C40FF
        0083713E205AE83E2CB8F117C48FD88FC417C96DA5F889D1EF359F8473CCF848
        2E950169AC4B363283D0C6049FB9B8FD38F0B78AB4BF1CF8674DD7343D4AC358
        D1758B58AFAC2FEC6E12E2D6FADE540F1CD14884AC91BA32B2B29218104120D7
        CC3FF048FF00DA7F5CFDB83F645F177C2BF8F7E178E6F8ADF096F26F875F12B4
        BD5EC45C597880AC5B52ECEEDD15C47776FF0033E0ED760EE15619222DF9F77D
        FF0004C0F127ECD5FF000574D2FF00660F0DFED1DFB40FC21F827F123C37A878
        ABE1759F867C55762DF4CBA8A67B8BED1F63B0055145D5C0933BB6BC5BCC9248
        EF401FB61457E7F7FC128BC6FE3AFD9C3F6D8FDA0BF651F897F113C4DF13EF7C
        0E74FF00197833C47E25BA9AEB57D5B47BD8235B84792476FDDDB4E6140063F7
        92CD8F97685FD01A0028A281401F963FF05907F88BFB2EFF00C1573F66CF8CDF
        05EDFC1BE2AF8B3F10B4CBBF85BA67867C5762CFA78884AF70D7B1DC2C919824
        1F6C68D889158A30550EAD229F29FF0082C0789FF6CE83E14FC2FF00881FB4F7
        C3BF829A6FC1FF00847F13B40F15EB9A87C37BD9DFC456D125C080880DE5C15D
        AFE76DDB18DC64F2492A8AE6BF413FE0AFBFB15E87FB6C7EC33E36D36E7C3779
        E20F1A784F48BFF10F815AC2E24B6BFB4D7A1B39FEC66178D9492D295528C4A3
        646465548FC0FF008DFADFEC967FE09C7A4EB537ED09FB446B9FB54787EDAC35
        097C13E2686E2FB49B1F10C53225D472437367F66F263CCF826E4BECC6E5762D
        0B007F57F2921DB3FAF61D7FCFFF00A857E617FC1543E35697A07FC16C7F64A9
        23B6D77526F817E0FF001D7C49F16C3A4D935E5D5AE912E99E4C25625E59A59A
        CDE20BD774A99C6ECD53F0DFFC1C97A47C76F857E1FF000FFC01F867E3AFDA1B
        E386A1A2D8FF00695B685A2DC699E19D1B539522499AF6F6E551A1B749E46C39
        51190BCCB182241C2FC20FF820C7C64F883F11B5EF8E9F133F69DF887E01F8F5
        F12118F890FC3D996CED2C2D894F234D8E6C879228522857030998D40DFB048E
        01E87F033E26E9FF00B4A7FC1C73E2CF1A785F4DD522D0FC3DFB3AE91A5EAD35
        E5849673DA5E6A3A85B6AB690DC45200D14ED692026360197CA60705481FA235
        F37FFC13B7FE09B1E1FF00F827C697E36BC87C5BE30F88DE38F895AAAEABE27F
        16F8A2E85C6A7AA344AC96F116007EEE256908DC59B74D21DDB4AA27D2140051
        451400514514005145140051451401FFD9}
    end
    object iPause: TImage
      Left = 42
      Top = 266
      Width = 49
      Height = 49
      Picture.Data = {
        0A544A504547496D6167658B090000FFD8FFE000104A46494600010101004800
        480000FFE100224578696600004D4D002A000000080001011200030000000100
        01000000000000FFFE003C43524541544F523A2067642D6A7065672076312E30
        20287573696E6720494A47204A50454720763830292C207175616C697479203D
        2039300A00FFDB00430002010102010102020202020202020305030303030306
        04040305070607070706070708090B0908080A0807070A0D0A0A0B0C0C0C0C07
        090E0F0D0C0E0B0C0C0CFFDB004301020202030303060303060C0807080C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFC0001108003100310301220002110103
        1101FFC4001F0000010501010101010100000000000000000102030405060708
        090A0BFFC400B5100002010303020403050504040000017D0102030004110512
        2131410613516107227114328191A1082342B1C11552D1F02433627282090A16
        1718191A25262728292A3435363738393A434445464748494A53545556575859
        5A636465666768696A737475767778797A838485868788898A92939495969798
        999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
        D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FAFFC4001F0100
        030101010101010101010000000000000102030405060708090A0BFFC400B511
        0002010204040304070504040001027700010203110405213106124151076171
        1322328108144291A1B1C109233352F0156272D10A162434E125F11718191A26
        2728292A35363738393A434445464748494A535455565758595A636465666768
        696A737475767778797A82838485868788898A92939495969798999AA2A3A4A5
        A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4D5D6D7D8D9DA
        E2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002110311003F00
        FDB1F1578AB4BF02785B52D735CD4B4FD1743D16D65BFD4751BFB85B7B5B0B78
        94BC934B2310A91A282C5988000AFC23FDBE7FE0E8CF89FF00B4B7C625F84DFB
        15F85F559A4BEB992CED3C483436D4B5FF0010B27CC5B4FB074716F094491B74
        D1BCC50872B6CCACB49FF07467EDF3E30FDA5BF69DF0C7EC57F0996FAFA49AFB
        4E1E24B4B39FCA6F10EB376D1BD869AC5B6A1861592098EE7D866954B056B556
        AFD58FF8242FFC1217E1AFFC11DFF66B4444D1AF3E205E69DE7F8D3C693E15AE
        080249628E590030D8C457E55F941118771BF24007E3AE8DFF0006D57FC1413F
        6EDD3E3D7FE357C56B4D1E6BA662F61E34F1ADF6B5A844A4E4623B759E0553D9
        04AA5471B463024D47FE0D4FFDB7BF64AB3B8D7FE0EFC60F0DDD6A56319921B5
        F0CF8B351F0FEA970FFDD899A38A107DDE7415FD0BFC3AFDABFE16FC60F122E8
        DE11F895E00F14EB0F134EB63A47886D2FAE5A35C6E711C52336D191938C0C8A
        B9F143F68DF87BF042FACED7C69E3CF06F83EE7508DA5B5875BD6EDB4F92E514
        80CC8B2BA96009009190091401FCF17ECD1FF0716FED3DFF0004C4F8E2BF0AFF
        006CAF067893C51A6DA0559A6D42C23B3F145841BBCB5B8B79C6C83528098E5C
        3484995B95B901707F7A3E057C76F07FED39F08341F1F7C3FF0010E9FE2AF07F
        89ED85D69BA9D993E5CE992ACACAC03C722306478E45578DD5959559481CAFED
        C9FB09FC17FF0082C17ECACDE1FF00130D17C4DA3DFC32CDE1BF15691345753E
        8D707E5FB4D9DC2120E1900740C52409B5C1038FC25FF822D7ED1BE3EFF8220F
        FC15BFC45FB25FC59BB65F07F8D3C411E873289D9ACAD3549950699ABDB0C1DB
        1DDC6D6F1C99D87CB9A26970D6C10007F4614549F649BFE7949FF7C9A2803F9D
        DFF836AB46B7FDBB7FE0E06F8ADF1AB5F8E4BA9B4783C41E34B072E4A457B7F7
        CB6D10C1EAAB6F7972147452898C6D18FDFEFDBF86EFD843E3603FF4216BBFFA
        6F9EBF017FE0D4FD461FD92BFE0B77F183E0EF882E21B1D4AEB47D6FC336B0C8
        7F7971A8699A8C4ED0AFB8820BB73ED11AFDFBFDBF3FE4C47E35FF00D885AEFF
        00E9BE7A00FE69FF00E0CFD19FF82C3D9FFD89DAB7FED1AFA07FE0F7F1FF0019
        15F01BFEC5CD4FFF004A62AF9FFF00E0CFCFF94C3D9FFD89BAB7FED1AFA03FE0
        F7FF00F9389F80DFF62E6A7FFA5315007EAC7FC1B8E36FFC113FE01FFD81EEBF
        F4E3755F97BFF07B6FC09B4F0A7C60F80BF16F4B59AD75BD66C350F0EDFDD452
        14DA2CA582E6CD971D1C1BBBAF987385419E063F50BFE0DC8FF94287C02FFB03
        5D7FE9C2EABF34BFE0F84F8CFA7DC6AFFB3FFC3BB7BB864D5ACE1D5FC45A85B6
        7F790412B5B5BDAC847F75DA1BC1F588D005EFF88BB759FF009F5D23FF0001D6
        8AF00FF8853BE2AFFD00EF28A00EA3FE0E2DFD99FC71FF0004C4FF00829E7833
        F6CAF856A2D34DF146B16DA84D32A37D9F4FF10411E27B69D63D84C17D6F1B48
        C37EE94B5EA9DA00CFEDFF00EC27FB727C2BFF0082C17EC5E3C4DE1F6B5BFD1F
        C4DA749A478ABC3735CEEBAD1A69A229716371B76B0CAB305900512210EB8078
        EA7E3B7C0AF07FED39F07BC43F0FFC7DA0D8F89FC1FE2AB5367A9E9B740EC9D3
        21959594868E447549124421E374475219411FCFE7ED1DFF00045AFDADFF00E0
        883F1F6EFE2CFEC97E22F1878D3C1EA640B368702DDEB5696A5862D754D302B2
        5F46BBB3E6C713C798BCD68ED9820001FBABFB2D7FC11EFF0066CFD8A3E2AC7E
        37F85BF0AF47F08F8AA2B496C5750B6BDBC95C432EDF3136CB33AF3B4738CF1D
        7AD6E7ED81FF0004C4F80FFB7CF88345D53E2FFC3AD2FC6DA87876DE4B4D3A6B
        ABAB984DAC52306750219501CB283C826BF177E047FC1EDBE30F0A692BA5FC5A
        F80BA46B3AD5AC8D15D5FF008775B974855DA71B4D9DC45390E3186FDF019CE1
        4741ABF19FFE0F84BCB8F0F5DDBFC3BFD9FEDECF569233F66D43C45E266B8B78
        24EC5ED608236917D84E87DE803F657C57E2BF82DFF048EFD8B5EEAE9F4DF877
        F09FE1D59482D6D44CF2797B9DE416F00919A49A692476088096666C0F6FE7AF
        F617F0AF8C3FE0E3BFF82E86A5F1ABC65A5C96BF0C3C05A85AEB7A858C8ED35B
        69DA6DB3B7F65E8C0B06567B8922265036071F6E95429C2D1E15FD85FF006E8F
        F838EFE30E97E32F8D5A96B1E03F8616ACD258EA1ADE9CFA7E93A740EC188D27
        4BCA3DD3B2300273C38882C97395515FBE5FB12FEC4BF0EFFE09EFFB3C68FF00
        0CBE1968EDA5F87F4B26E2E2E2E1965BED66F1D544B7B772855F36793628242A
        AAAA2222A46888A01EC9FDBD79FF003F125154E8A002A4B4FF008FA8FF00DF1F
        CE8A2803F0FBFE0EEDFF0091CED7FEBC22FF00D06BE7FF00F8353BFE4EAB44FF
        00AF8A28A00FE9275EFF0090C5C7FBD54E8A2800A28A2803FFD9}
      Visible = False
      OnClick = iPauseClick
    end
    object iPlay: TImage
      Left = 42
      Top = 266
      Width = 49
      Height = 49
      Picture.Data = {
        0A544A504547496D616765CF090000FFD8FFE000104A46494600010101006000
        600000FFE100224578696600004D4D002A000000080001011200030000000100
        01000000000000FFFE003C43524541544F523A2067642D6A7065672076312E30
        20287573696E6720494A47204A50454720763830292C207175616C697479203D
        2039300A00FFDB00430002010102010102020202020202020305030303030306
        04040305070607070706070708090B0908080A0807070A0D0A0A0B0C0C0C0C07
        090E0F0D0C0E0B0C0C0CFFDB004301020202030303060303060C0807080C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
        0C0C0C0C0C0C0C0C0C0C0C0C0C0C0CFFC0001108003100310301220002110103
        1101FFC4001F0000010501010101010100000000000000000102030405060708
        090A0BFFC400B5100002010303020403050504040000017D0102030004110512
        2131410613516107227114328191A1082342B1C11552D1F02433627282090A16
        1718191A25262728292A3435363738393A434445464748494A53545556575859
        5A636465666768696A737475767778797A838485868788898A92939495969798
        999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
        D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FAFFC4001F0100
        030101010101010101010000000000000102030405060708090A0BFFC400B511
        0002010204040304070504040001027700010203110405213106124151076171
        1322328108144291A1B1C109233352F0156272D10A162434E125F11718191A26
        2728292A35363738393A434445464748494A535455565758595A636465666768
        696A737475767778797A82838485868788898A92939495969798999AA2A3A4A5
        A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4D5D6D7D8D9DA
        E2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002110311003F00
        FDB0F1578AF4BF02785F52D735CD4AC347D1747B596FAFEFEFAE12DED6C6DE24
        2F24D2C8E42A4688A5999880A0124802BF05BFE0A1FF00F07527C44F8F1F1497
        E18FEC7BE1FD4235BEBE3A7597891B463A96B9E22977AAC634FB074611249870
        04B1C933AC88765BBA9149FF0007527FC143FC55F1E3F689D03F63DF862BAA5F
        2C77560DE24B2D38B99BC45ABDD18DEC34C11AA8F312312412ED0CCAF34D1E55
        5EDD4D7EA2FF00C10EBFE0879E09FF00824C7C10B5BEBEB5D37C45F1B3C47668
        7C4FE263107369BB0CDA758B30CC76B1B60330DAD70E82470008A28403F1BBC3
        7FF06F17FC1463FE0A0DA3FF006E7C52F1849A1ADCA09ADE0F891E39BBB999D1
        C6F016DEDD6E8C18DC479722C65482368C62A6BFFF00835FFF00E0A01FB1AE95
        FDB9F0B7C71A0EA3AA21C7D9BC01E3CBDD26F803C121AE63B34E84F024C900F0
        4E01FE9E56E636B8684488668D43B206F9954E40247A1DAD83DF07D29FDA803F
        999FD913FE0E54FDA3BFE09E3F189BE1A7ED6BE11F1278A34ED3BCB8AED753D2
        C697E2DD1D084D922EE11A5E4650338F380794C8AC2E36801BF7F3E047C77F07
        FED39F08340F1F78075FB0F147843C4F6A2EF4DD4ACD8F973A64AB02AC034722
        3AB23C6E15E3747475565651C5FF00C153FF00E0941F0C7FE0AC1FB3FDC7847C
        71630E9FE23B08E493C33E2CB6B657D4BC3972470C872A65B76217CDB7660928
        00E52448E58FF077FE0865FB557C40FF008233FF00C15535EFD95FE2D35C59F8
        77C5DE205F0EDFD999656B4D3B5A9022D86A76CAC99315DAB41197DB1F990CF6
        F2B9C40AB401FD2251451401FCDCFF00C1BCDE1AB3FF008284FF00C1C61E30F8
        A5ADF97731E872788BE24416D3AF9D1BC92DDADB5BA80D9C792DA8472263054D
        BA608C62BFA82AFE613FE0D7CBDB5FD8E3FE0BF9E39F85DAEE63D5350D2BC49E
        01B6C72A2EECAF61BA704F4FF57A64C07A9C7722BFA7BA00FE5BFF00E0E51FDA
        7BE21FEC8FFF0005F6D73C6DF0D7C61AF7837C51A5787B4516F7DA75C98D8C7F
        674730C887292C2CCA0BC322B46FD1958122BEC6FF0082557FC1E1DE1BF88EDA
        6F82FF006A1D2EDBC1FAC954B787C71A3DBBBE9378C148DD7B6ABBA4B6762A99
        922DF116909296F1AE6BE07FF83B534F9B52FF0082D5788ADED6196E2E2EBC3F
        A2C71451217795CDB850AA0724938000E4D7A0FF00C12BFF00E0D22F8B1FB55B
        D8F8B3E3CCDA9FC18F01C844A9A4B42BFF00094EA89F21C085C15B1520B8DD70
        AD2AB2736E5583D007F4DBE08F1CE8BF133C21A6F883C37AC697E20D0758B75B
        BB0D4B4DBB8EEECEFA16195922963251D1872194906BF9D1FF0083D6BE0159FC
        35FDAE7E0BFC58D25C586ABE38D0AF34BBA6B602291A7D2A781E3B92CA03190A
        5FC69B89C85B74031B457EFE7EC99FB29781FF00621FD9EFC37F0BFE1CE95268
        BE0EF0AC52C7636B25D4B7520696692795DE49199999E696473CE017C2855014
        7E0BFF00C1F01F19B4BD7FE3D7C03F87F0966D63C2BA16ADAFDDFF007443A84F
        6D04233D33BB4D9891D7047A8C80767FF11692FF00D01B48FF00BE1BFC68AF0A
        FF008852BE237FCFB47FF8109FE345005AFF008394FF00644F18FF00C13C3FE0
        A39E11FDADBE19B7F66E9DE29D62CF535BB8A10D1E8FE24B40AFB644D810C773
        1C226C31632BADE0601701BF723FE0943FF0550F87DFF0560FD996C7C6FE10B8
        86C3C45A7C715B78AFC332CC1EF3C377CCA728C382F6F214768670009514E424
        892C71F6BF1DFE04783FF69CF841E20F00F8FB40B1F13F843C516A6CF52D36F1
        4F973A643290CA4347223AABA48855E3744746565561FCF3FED55FF0431FDAAB
        FE08D1FB401F8B5FB2BEBBE30F17F876CE673657FE1D8C4DE20D36D8CB1B2DAE
        A160AA56F62276EE31C52432792CF24508DAB401FD1D5D7EC83F0BAFBF6918FE
        305C7807C2F71F1420B04D321F134B60926A1040A240163908251B6CAE85D70E
        50EC24A80A3D1EBF9BBF801FF07ACFC5EF869A4C9A4FC58F833E13F1D6A96005
        B1BAD2F539FC3774CE802B1B88DE2BA432160C584691282701462B63E327FC1F
        03E3CD7BC30D0FC3FF00805E13F0BEB04FFC7DEBDE259F5CB703DA1860B36CE3
        3C99319EC7A100FDD1FDB7BF6DEF877FF04F4FD9D75AF89DF13B5A5D27C3DA42
        F970C31ED7BDD62E9959A2B2B488B2F9B7126D6DAB90005677648D1DD7F9B8FF
        008270FC35F1B7FC1C27FF0005BDD5FE36F8EB4F8E1F06786356B6F146BF6FC4
        B6B656B6E42E97A32131EC937F9088FB950C914375212243865F86DFF04E3FDB
        7BFE0E15F8D5A7F8EBE36EB1E20F0BF82E1526DF5EF14581B1B2B2B7711129A4
        E96A23F337A6C6F31152293CA2649CC806EFE82FF624FD893E1E7FC13E3F679D
        1FE1A7C34D1FFB2F41D2F335C5C4C4497DAC5DB2A896F6EE50079B7126D5CB60
        2AAAA468A91C688A01EB54514500145145007E21FF00C1DA1FEA345FFB078FFD
        09ABC13FE0D4BFF938FB6FA4BFFA01A28A00FE8DE8A28A0028A28A00FFD9}
      OnClick = iPlayClick
    end
    object lStep: TLabel
      Left = 60
      Top = 225
      Width = 91
      Height = 20
      Caption = 'Step by step'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lControlPanel: TLabel
      Left = 40
      Top = 8
      Width = 146
      Height = 29
      Caption = 'Control Panel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object bStart: TButton
      Left = 60
      Top = 64
      Width = 90
      Height = 50
      Caption = 'Start'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = bStartClick
    end
    object bSkip: TButton
      Left = 60
      Top = 140
      Width = 90
      Height = 50
      Caption = 'Skip All'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = bSkipClick
    end
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
        object mEdu: TMenuItem
          Caption = 'Educational'
          OnClick = mEduClick
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
  object tAnim: TTimer
    Enabled = False
    Interval = 10
    OnTimer = tAnimTimer
    Left = 600
  end
  object tFormatAnim: TTimer
    Enabled = False
    Interval = 1
    OnTimer = tFormatAnimTimer
    Left = 568
  end
end
