//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Memo1->Lines->Clear();
Memo1->Align = alClient;
Label1->Caption = "-";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cmdExitClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cmdExecuteClick(TObject *Sender)
{

#define BUF_SIZE 20480

int fh;
String FilePath;
int bytes;
unsigned char buffer[BUF_SIZE];

// progress values
__int64 TotalSize = 0;
__int64 FileSize;
float percent;
int PercentNum;

// Keccak bit
int KeccakBit = 256;
switch (ComboBox1->ItemIndex) {
case 0:   // Keccak-224
	KeccakBit = 224;
	break;

case 1:   // Keccak-256
	KeccakBit = 256;
	break;

case 2:   // Keccak-384
	KeccakBit = 384;
	break;

case 3:   // Keccak-512
	KeccakBit = 512;
	break;

default:
	Memo1->Lines->Add("Keccak bit is unexcepted to select.");
	return;
}

// Keccak result
BitSequence result[64];

// result hex string
char hashval[1024];
for (int i = 0; i < 1024; i++){
	hashval[i] = NULL;
}

// Keccak return value
HashReturn ret;
// Keccak hash state structure
hashState st;

//-----------------------------------
// Keccak Init
//-----------------------------------
if ( (ret = KeccakInit(&st, KeccakBit)) != 0 ){
	Memo1->Lines->Add("Keccak init error:" + IntToStr(ret));
	return;
}
else{
	Memo1->Lines->Add("Keccak init ok.");
}


//-----------------------------------
// String to Keccak hash.
//-----------------------------------
if (RadioButton1->Checked == true) {

	Memo1->Lines->Add("Test string:" + Edit1->Text);
	KeccakUpdate(&st, Edit1->Text.t_str(), Edit1->Text.Length()*8); // <- "bit"!

}
//-----------------------------------
// File to Keccak hash.
//-----------------------------------
else{

	FilePath = Label1->Caption;
	Memo1->Lines->Add(FilePath);

	if ( FileExists(FilePath) == false){
		Memo1->Lines->Add("...file is not found.");
		return;
	}

	fh = FileOpen(FilePath, fmOpenRead);

	if (fh < 0) {
		Memo1->Lines->Add("...file could not open.");
		return;
	}

	FileSize = FileSeek(fh, (__int64)0, 2);
	FileSeek(fh, 0, 0);

	Memo1->Lines->Add("Keccak update...");

	// read file...
	while ((bytes = FileRead (fh, buffer, BUF_SIZE)) != 0){

		KeccakUpdate(&st, buffer, bytes*8);	// <- "bit"!

		TotalSize+=bytes;
		percent = (float)TotalSize/FileSize;
		if ( PercentNum != int(percent*100) ){
			PercentNum = int(percent*100);
			Memo1->Lines->Strings[Memo1->Lines->Count-1] = "Keccak update..." + IntToStr(PercentNum)+"%";
			Memo1->Invalidate();
		}

	}

	FileClose(fh);

}


//-----------------------------------
// Final
//-----------------------------------
KeccakFinal(&st, result);


// convert result data to hex strings.
BinToHex( result, hashval, KeccakBit/8);
Memo1->Lines->Add("Keccak-" + IntToStr(KeccakBit) + " result:\n" + (String)hashval);


}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{

if (RadioButton1->Checked == true) {
	DragAcceptFiles(Form1->Handle, false);
	RadioButton2->Checked = false;
	Edit1->Enabled = true;
	Edit1->Color = clWindow;
}
else{
	DragAcceptFiles(Form1->Handle, true);
	RadioButton2->Checked = true;
	Edit1->Enabled = false;
	Edit1->Color = clBtnFace;
}

}
//---------------------------------------------------------------------------
// Drag and drop event on main form
MESSAGE void __fastcall TForm1::FWmDropFiles(TWMDropFiles &msg)
{

wchar_t DropFileName[MAX_PATH];
POINT droppoint;

// get 0th dropfilepath
DragQueryFileW( (HDROP)msg.Drop, 0, DropFileName, MAX_PATH);

Label1->Caption = (String)DropFileName;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDragOver(TObject *Sender, TObject *Source, int X,
					int Y, TDragState State, bool &Accept)
{

if (RadioButton2->Checked == true) {
	Accept = true;
}
else{
	Accept = false;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::mnuSaveToFileClick(TObject *Sender)
{

if (SaveDialog1->Execute() == true) {
	Memo1->Lines->SaveToFile(SaveDialog1->FileName, TEncoding::UTF8);
}



}
//---------------------------------------------------------------------------

