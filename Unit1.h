//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

#include "KeccakNISTInterface.h"
#include "KeccakF-1600-opt32-settings.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TButton *cmdExecute;
	TButton *cmdExit;
	TMemo *Memo1;
	TPanel *Panel2;
	TRadioButton *RadioButton1;
	TEdit *Edit1;
	TRadioButton *RadioButton2;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TMainMenu *MainMenu1;
	TMenuItem *mnuFile;
	TMenuItem *mnuExit;
	TMenuItem *mnuSaveToFile;
	TMenuItem *N1;
	TSaveDialog *SaveDialog1;
	void __fastcall cmdExitClick(TObject *Sender);
	void __fastcall cmdExecuteClick(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall FormDragOver(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept);
	void __fastcall mnuSaveToFileClick(TObject *Sender);

private:	// ユーザー宣言

	//ファイルドラッグ＆ドロップの処理メッセージ関数
	MESSAGE void __fastcall FWmDropFiles(TWMDropFiles&);

	BEGIN_MESSAGE_MAP
	 MESSAGE_HANDLER(WM_DROPFILES,TWMDropFiles,FWmDropFiles);
	END_MESSAGE_MAP(TForm);



public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
