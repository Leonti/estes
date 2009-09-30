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
#include "prog_set_panel.h"

//(*InternalHeaders(prog_set_panel)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//(*IdInit(prog_set_panel)
const long prog_set_panel::ID_CHECKBOX1 = wxNewId();
const long prog_set_panel::ID_CHECKBOX2 = wxNewId();
const long prog_set_panel::ID_CHECKBOX3 = wxNewId();
const long prog_set_panel::ID_STATICTEXT1 = wxNewId();
const long prog_set_panel::ID_CHOICE1 = wxNewId();
const long prog_set_panel::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(prog_set_panel,wxPanel)
    //(*EventTable(prog_set_panel)
    //*)
END_EVENT_TABLE()

prog_set_panel::prog_set_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(prog_set_panel)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxDefaultPosition, wxSize(290,229), wxTAB_TRAVERSAL, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Enable kitchen cooperation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    FlexGridSizer1->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox2 = new wxCheckBox(this, ID_CHECKBOX2, _("By database"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    CheckBox2->Disable();
    FlexGridSizer2->Add(CheckBox2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox3 = new wxCheckBox(this, ID_CHECKBOX3, _("By printing"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CheckBox3->SetValue(false);
    CheckBox3->Disable();
    FlexGridSizer2->Add(CheckBox3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Appearance"));
    FlexGridSizer3 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(4, 2, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Language:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer4->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("English")) );
    Choice1->Append(_("Spanish"));
    Choice1->Append(_("Polish"));
    Choice1->Append(_("Russian"));
    FlexGridSizer4->Add(Choice1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Note: You need to restart program for language \nsettings to take effect!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(9,wxSWISS,wxFONTSTYLE_ITALIC,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&prog_set_panel::OnCheckBox1Click);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&prog_set_panel::OnCheckBox2Click);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&prog_set_panel::OnCheckBox3Click);
    //*)
    langs.Add(0); //for english
    langs.Add(wxLANGUAGE_SPANISH);
    langs.Add(wxLANGUAGE_POLISH);
    langs.Add(wxLANGUAGE_RUSSIAN);
}

prog_set_panel::~prog_set_panel()
{
    //(*Destroy(prog_set_panel)
    //*)
}
void prog_set_panel::fill_all()
{
    if(set_now->kitchen == true)
    {
        CheckBox2->Enable(true);
        CheckBox3->Enable(true);
        CheckBox1->SetValue(true);
    }
    if(set_now->kitchen_type == 1)
    {
        CheckBox2->SetValue(true);
    }
    else if(set_now->kitchen_type == 2)
    {
        CheckBox3->SetValue(true);
    }

    if(set_now->lang == 0)
    {
    }
    else
    {
        for(int i=0; i<langs.GetCount(); ++ i)
        {
            if(set_now->lang == langs[i])
            {
                Choice1->SetSelection(i);
                break;
            }
        }
    }
}


void prog_set_panel::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue() == true)
    {
        CheckBox2->Enable(true);
        CheckBox3->Enable(true);
        if(set_now->kitchen_type == 1)
        {
            CheckBox2->SetValue(true);
        }
        else if(set_now->kitchen_type == 2)
        {
            CheckBox3->SetValue(true);
        }

    }
    else
    {
        CheckBox2->Enable(false);
        CheckBox3->Enable(false);

    }

}

void prog_set_panel::Save()
{

    if(CheckBox1->GetValue())
    {
        confi->Write(_("/program/kitchen"), _("1"));
        set_now->kitchen = true;
    }
    else
    {
        confi->Write(_("/program/kitchen"), _("0"));
        set_now->kitchen = false;
    }


    if(CheckBox2->GetValue() == true)
    {
        confi->Write(_("/program/kitchen_type"), _("1"));
        set_now->kitchen_type = 1;
    }
    else if(CheckBox3->GetValue())
    {
        confi->Write(_("/program/kitchen_type"), _("2"));
        set_now->kitchen_type = 2;
    }

    wxString temp;
    temp << langs[Choice1->GetSelection()];
    confi->Write(_T("/program/lang"),temp);
    set_now->lang = langs[Choice1->GetSelection()];

    confi->Flush();
}

void prog_set_panel::OnCheckBox2Click(wxCommandEvent& event)
{
    if(CheckBox2->GetValue()) CheckBox3 -> SetValue(false);
}

void prog_set_panel::OnCheckBox3Click(wxCommandEvent& event)
{
    if(CheckBox3->GetValue()) CheckBox2 -> SetValue(false);
}
