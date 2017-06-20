object Form1: TForm1
  Left = 355
  Top = 190
  Anchors = [akRight, akBottom]
  Caption = 'Keccak Test'
  ClientHeight = 328
  ClientWidth = 403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDragOver = FormDragOver
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 309
    Width = 403
    Height = 19
    Panels = <>
  end
  object Panel1: TPanel
    Left = 0
    Top = 268
    Width = 403
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      403
      41)
    object cmdExecute: TButton
      Left = 237
      Top = 6
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = '&Execute'
      TabOrder = 0
      OnClick = cmdExecuteClick
    end
    object cmdExit: TButton
      Left = 318
      Top = 6
      Width = 75
      Height = 25
      Anchors = [akRight, akBottom]
      Cancel = True
      Caption = 'E&xit'
      TabOrder = 1
      OnClick = cmdExitClick
    end
    object ComboBox1: TComboBox
      Left = 8
      Top = 8
      Width = 145
      Height = 21
      Style = csDropDownList
      Anchors = [akLeft, akBottom]
      ItemIndex = 1
      TabOrder = 2
      Text = 'Keccak-256'
      Items.Strings = (
        'Keccak-224'
        'Keccak-256'
        'Keccak-384'
        'Keccak-512')
    end
  end
  object Memo1: TMemo
    Left = 8
    Top = 144
    Width = 345
    Height = 93
    BevelInner = bvNone
    BevelKind = bkSoft
    BevelOuter = bvNone
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 403
    Height = 125
    Align = alTop
    BevelOuter = bvNone
    Constraints.MaxHeight = 400
    TabOrder = 3
    DesignSize = (
      403
      125)
    object Label1: TLabel
      Left = 12
      Top = 104
      Width = 38
      Height = 13
      Caption = 'FilePath'
    end
    object RadioButton1: TRadioButton
      Left = 12
      Top = 21
      Width = 381
      Height = 17
      Anchors = [akLeft, akTop, akRight]
      Caption = '&Text'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object Edit1: TEdit
      Left = 12
      Top = 44
      Width = 381
      Height = 21
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 1
    end
    object RadioButton2: TRadioButton
      Left = 12
      Top = 81
      Width = 381
      Height = 17
      Caption = 'Fil&e'
      TabOrder = 2
      OnClick = RadioButton1Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 96
    Top = 72
    object mnuFile: TMenuItem
      Caption = '&File'
      object mnuSaveToFile: TMenuItem
        Caption = '&Save result text...'
        ShortCut = 16467
        OnClick = mnuSaveToFileClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object mnuExit: TMenuItem
        Caption = 'E&xit'
        OnClick = cmdExitClick
      end
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = #12486#12461#12473#12488#12501#12449#12452#12523'(*.txt)|*.txt|'#12377#12409#12390#12398#12501#12449#12452#12523'(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 176
    Top = 72
  end
end
