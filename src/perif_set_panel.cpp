#include "perif_set_panel.h"

//(*InternalHeaders(perif_set_panel)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include <wx/msgdlg.h>



//(*IdInit(perif_set_panel)
const long perif_set_panel::ID_RADIOBUTTON1 = wxNewId();
const long perif_set_panel::ID_RADIOBUTTON2 = wxNewId();
const long perif_set_panel::ID_RADIOBUTTON3 = wxNewId();
const long perif_set_panel::ID_SPINCTRL1 = wxNewId();
const long perif_set_panel::ID_CHECKBOX1 = wxNewId();
const long perif_set_panel::ID_TEXTCTRL1 = wxNewId();
const long perif_set_panel::ID_STATICTEXT1 = wxNewId();
const long perif_set_panel::ID_STATICTEXT2 = wxNewId();
const long perif_set_panel::ID_CHECKBOX2 = wxNewId();
const long perif_set_panel::ID_TEXTCTRL2 = wxNewId();
const long perif_set_panel::ID_CHECKBOX3 = wxNewId();
const long perif_set_panel::ID_TEXTCTRL3 = wxNewId();
const long perif_set_panel::ID_STATICTEXT3 = wxNewId();
const long perif_set_panel::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(perif_set_panel,wxPanel)
	//(*EventTable(perif_set_panel)
	//*)
END_EVENT_TABLE()

perif_set_panel::perif_set_panel(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(perif_set_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer4;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxFlexGridSizer* FlexGridSizer5;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Receipt printer"));
	FlexGridSizer2 = new wxFlexGridSizer(4, 0, 0, 0);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Printing width"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 4, 0, 0);
	RadioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, _("40 chars"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	FlexGridSizer4->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, _("32 chars"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	FlexGridSizer4->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RadioButton3 = new wxRadioButton(this, ID_RADIOBUTTON3, _("Custom:"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	FlexGridSizer4->Add(RadioButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("40"), wxDefaultPosition, wxDefaultSize, 0, 0, 100, 40, _T("ID_SPINCTRL1"));
	SpinCtrl1->SetValue(_T("40"));
	SpinCtrl1->Disable();
	FlexGridSizer4->Add(SpinCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Custom printer command"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	CheckBox1->SetToolTip(_("Executed when a receipt needs to be printed. Ovverides default printing."));
	FlexGridSizer2->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(270,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->Disable();
	FlexGridSizer6->Add(TextCtrl1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("file.txt"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer6->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer6, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Note: The command for printing should accept text file as a parametr."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(9,wxSWISS,wxFONTSTYLE_ITALIC,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Drawer"));
	FlexGridSizer3 = new wxFlexGridSizer(2, 0, 0, 0);
	CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("Custom drawer command"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBox2->SetValue(false);
	CheckBox2->SetToolTip(_("Executed to open drawer"));
	FlexGridSizer3->Add(CheckBox2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(270,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->Disable();
	FlexGridSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Kitchen tickets printer"));
	FlexGridSizer5 = new wxFlexGridSizer(4, 0, 0, 0);
	CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("Custom printer command"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	CheckBox3->SetValue(false);
	FlexGridSizer5->Add(CheckBox3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(270,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl3->Disable();
	FlexGridSizer7->Add(TextCtrl3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("file.html"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer7, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Note: The command for printing should accept html file as a parametr."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(9,wxSWISS,wxFONTSTYLE_ITALIC,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	FlexGridSizer5->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&perif_set_panel::OnRadioButton1Select);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&perif_set_panel::OnRadioButton2Select);
	Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&perif_set_panel::OnRadioButton3Select);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&perif_set_panel::OnCheckBox1Click);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&perif_set_panel::OnCheckBox2Click);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&perif_set_panel::OnCheckBox3Click);
	//*)

	printdata = new wxPrintData();
}

perif_set_panel::~perif_set_panel()
{
	//(*Destroy(perif_set_panel)
	//*)
}

void perif_set_panel::fill_all(){
if(set_now->custom_print == true){
    CheckBox1 -> SetValue(true);
    TextCtrl1->Enable(true);
        }
    TextCtrl1->SetValue(set_now->print_command);

if(set_now->custom_drawer == true){
    CheckBox2 -> SetValue(true);
    TextCtrl2->Enable(true);
        }
    TextCtrl2->SetValue(set_now->drawer_command);

   if(set_now->custom_width == true){
   RadioButton3->SetValue(true);
   RadioButton1->SetValue(false);
   SpinCtrl1 -> Enable(true);
   SpinCtrl1 -> SetValue(set_now -> print_width);
       }else{
   switch(set_now ->print_width){
       case 40: RadioButton1 -> SetValue(true); break;
       case 32: RadioButton2 -> SetValue(true); RadioButton1 -> SetValue(false); break;
       }
           }

if(set_now->custom_ticket == true){
    CheckBox3 -> SetValue(true);
    TextCtrl3->Enable(true);
        }
    TextCtrl3->SetValue(set_now->ticket_command);
    }

void perif_set_panel::Save(){

        if(!RadioButton3->GetValue()){
        confi->Write(_("/program/custom_width"), _("0"));
        set_now->custom_width = false;
        if(RadioButton1->GetValue()){
        confi->Write(_("/program/print_width"), _("40"));
        set_now ->print_width = 40;
            }else if(RadioButton2->GetValue()){
        confi->Write(_("/program/print_width"), _("32"));
        set_now ->print_width = 32;
                }
            }else{
        confi->Write(_("/program/custom_width"), _("1"));
        set_now->custom_width = true;
        wxString temp;
        temp << SpinCtrl1->GetValue();
        confi->Write(_("/program/print_width"), temp);
        set_now->print_width = SpinCtrl1->GetValue();
                }


        if(CheckBox1->GetValue()){
        confi->Write(_("/program/custom_print"), _("1"));
        set_now-> custom_print = true;
        confi->Write(_("/program/print_command"), TextCtrl1 -> GetValue());
        set_now -> print_command = TextCtrl1 -> GetValue();
            }else{
        confi->Write(_("/program/custom_print"), _("0"));
        set_now-> custom_print = false;
                }


        if(CheckBox2->GetValue()){
        confi->Write(_("/program/custom_drawer"), _("1"));
        set_now-> custom_drawer = true;
        confi->Write(_("/program/drawer_command"), TextCtrl2 -> GetValue());
        set_now -> drawer_command = TextCtrl2 -> GetValue();
            }else{
        confi->Write(_("/program/custom_drawer"), _("0"));
        set_now-> custom_drawer = false;
                }

        if(CheckBox3->GetValue()){
        confi->Write(_("/program/custom_ticket"), _("1"));
        set_now-> custom_ticket = true;
        confi->Write(_("/program/ticket_command"), TextCtrl3 -> GetValue());
        set_now -> ticket_command = TextCtrl3 -> GetValue();
            }else{
        confi->Write(_("/program/custom_ticket"), _("0"));
        set_now-> custom_ticket = false;
                }

confi->Flush();
    }


void perif_set_panel::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue()== true){
        TextCtrl1 -> Enable(true);
        }else{
        TextCtrl1 -> Enable(false);
            }
}

void perif_set_panel::OnCheckBox2Click(wxCommandEvent& event)
{
        if(CheckBox2->GetValue()== true){
        TextCtrl2 -> Enable(true);
        }else{
        TextCtrl2 -> Enable(false);
            }
}

void perif_set_panel::OnRadioButton1Select(wxCommandEvent& event)
{
    if(RadioButton1 -> GetValue() == true){
        RadioButton2 -> SetValue(false);
        RadioButton3 -> SetValue(false);
        SpinCtrl1 -> Enable(false);
        }
}

void perif_set_panel::OnRadioButton2Select(wxCommandEvent& event)
{
        if(RadioButton2 -> GetValue() == true){
        RadioButton1 -> SetValue(false);
        RadioButton3 -> SetValue(false);
        SpinCtrl1 -> Enable(false);
        }
}

void perif_set_panel::OnRadioButton3Select(wxCommandEvent& event)
{
        if(RadioButton3 -> GetValue() == true){
        RadioButton1 -> SetValue(false);
        RadioButton2 -> SetValue(false);
        SpinCtrl1 -> Enable(true);
        }
}

void perif_set_panel::OnButton1Click(wxCommandEvent& event)
{
    /*
    wxString pn;

    wxPrintDialog* printdialog = new wxPrintDialog(this);

wxPrintData* printdata1 = new wxPrintData();
  printdata1->ConvertToNative();
  printdata1->ConvertFromNative();

printdata1 -> SetPrinterName(_("some_name"));

if(printdialog -> ShowModal() == wxID_OK){

  *printdata1 = printdialog ->GetPrintDialogData().GetPrintData();// printdialogdata -> GetPrintData();
  pn << printdata1 -> GetPrinterName();

    }
delete printdialog;

wxMessageBox(pn);
*/
}

void perif_set_panel::OnCheckBox3Click(wxCommandEvent& event)
{
            if(CheckBox3->GetValue()== true){
        TextCtrl3 -> Enable(true);
        }else{
        TextCtrl3 -> Enable(false);
            }
}
