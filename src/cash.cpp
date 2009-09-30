/*************************************************************************************
*  Estes - Restaurant Point Of Sale                                                  *
*  Copyright (C) 2009  Leonti Bielski                                                *
*                                                                                    *
*  This program is free software; you can redistribute it and/or modify              *
*  it under the terms of the GNU General Public License as published by              *
*  the Free Software Foundation; either version 2 of the License, or                 *
*  (at your option) any later version.                                               *
*                                                                                    *
*  This program is distributed in the hope that it will be useful,                   *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                     *
*  GNU General Public License for more details.                                      *
*                                                                                    *
*  You should have received a copy of the GNU General Public License                 *
*  along with this program; if not, write to the Free Software                       *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA    *
*************************************************************************************/
#include "cash.h"
#include "add_zero.h"
//(*InternalHeaders(cash)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include <wx/msgdlg.h>
//(*IdInit(cash)
const long cash::ID_STATICTEXT1 = wxNewId();
const long cash::ID_STATICTEXT2 = wxNewId();
const long cash::ID_TEXTCTRL1 = wxNewId();
const long cash::ID_BUTTON1 = wxNewId();
const long cash::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(cash,wxDialog)
    //(*EventTable(cash)
    //*)
END_EVENT_TABLE()

cash::cash(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(cash)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Please enter the amount of cash"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetFocus();
    FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&cash::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&cash::OnTextCtrl1TextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&cash::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&cash::OnButton2Click);
    //*)
    print = false;
    text_filled = false;
}

cash::~cash()
{
    //(*Destroy(cash)
    //*)
}

void cash::fill_all(double sum)
{
    order_total = sum;
    wxString label;
    label << addZero(order_total);
    TextCtrl1 -> Clear();

    TextCtrl1 -> AppendText(label);

    label << _(" $");
    StaticText1 -> SetLabel(label);
    text_filled = true;
}

void cash::OnTextCtrl1Text(wxCommandEvent& event)
{
    if(text_filled)
    {
        wxString amount = TextCtrl1 -> GetValue();
        amount.Replace(_("."), _(""));
        if(amount.Length()>2)
        {
            amount.insert(amount.Length() - 2,_("."));
        }
        else
        {
            amount.insert(0,_("."));
        }
        TextCtrl1 -> ChangeValue(amount);
        TextCtrl1 -> SetInsertionPointEnd();
    }
}



void cash::OnTextCtrl1TextEnter(wxCommandEvent& event)
{
    save_and_close();
}

void cash::OnButton1Click(wxCommandEvent& event)
{
    save_and_close();
}

void cash::save_and_close()
{
    wxString amount = TextCtrl1 -> GetValue();

    amount.ToDouble(paid);

    if(*paid >= order_total)
    {
        wxString change_msg;
        change_msg << _("Please give change in amount $ ") << (*paid - order_total);
        wxMessageBox(change_msg);
        print = true;
        Show(0);
    }
    else
    {
        wxString temp;
        wxMessageBox(_("Given amount can't be less than amount to pay "));
    }

}
void cash::OnButton2Click(wxCommandEvent& event)
{
    Show(0);
}
