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
#include "settings.h"

//(*InternalHeaders(settings)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(settings)
const long settings::ID_NOTEBOOK1 = wxNewId();
const long settings::ID_STATICLINE1 = wxNewId();
const long settings::ID_BUTTON1 = wxNewId();
const long settings::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(settings,wxDialog)
    //(*EventTable(settings)
    //*)
END_EVENT_TABLE()

settings::settings(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(settings)
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,310));
    FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    FlexGridSizer1->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settings::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&settings::OnButton2Click);
    //*)

    dbase_connected = false;
}

settings::~settings()
{
    //(*Destroy(settings)
    //*)
}

void settings::fill_all(void)
{

    db_set = new db_set_panel(Notebook1);
    db_set -> confi = confi;
    if(dbase_connected == true)
    {
        db_set -> dbase_connected = true;
    }
    db_set -> conn = conn;
    if (confi->Read(_("/program/run"))== _("1")) db_set -> fill_all();
    Notebook1->AddPage(db_set, _("Database"));


    prog_set = new prog_set_panel(Notebook1);
    prog_set -> confi = confi;
    prog_set -> set_now = set_now;
    prog_set -> fill_all();
    Notebook1->AddPage(prog_set, _("Program settings"));

    perif_set = new perif_set_panel(Notebook1);
    perif_set -> confi = confi;
    perif_set -> set_now = set_now;
    perif_set -> printdialogdata = printdialogdata;
    perif_set -> fill_all();
    Notebook1->AddPage(perif_set, _("Peripherals"));

//	SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
}


void settings::OnButton1Click(wxCommandEvent& event)
{
    if(Notebook1 -> GetSelection() == 0)
    {
        db_set -> Save();
    }

    prog_set -> Save();
    perif_set-> Save();

    Show(0);
}

void settings::OnButton2Click(wxCommandEvent& event)
{
    Show(0);
}
