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
#include "display_settings.h"

//(*InternalHeaders(display_settings)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#include <wx/msgdlg.h>
//(*IdInit(display_settings)
const long display_settings::ID_LISTBOX1 = wxNewId();
const long display_settings::ID_LISTBOX2 = wxNewId();
const long display_settings::ID_BUTTON1 = wxNewId();
const long display_settings::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(display_settings,wxDialog)
    //(*EventTable(display_settings)
    //*)
END_EVENT_TABLE()

display_settings::display_settings(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(display_settings)
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    workers = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_MULTIPLE|wxLB_NEEDED_SB, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer2->Add(workers, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    menus = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_MULTIPLE|wxLB_NEEDED_SB, wxDefaultValidator, _T("ID_LISTBOX2"));
    FlexGridSizer3->Add(menus, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&display_settings::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&display_settings::OnButton2Click);
    //*)
}

display_settings::~display_settings()
{
    //(*Destroy(display_settings)
    //*)
}

void display_settings::fill_all()
{

    mysqlpp::Query query = conn_display->query();
    query << "SELECT * FROM `workers`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            workers->Append(std2wx(std::string(row["name"]),wxConvUI));
            worker_ids.Add(int(row["id"]));
            if(int(row["show"]) == 1)
            {
                workers->SetSelection(workers->GetCount()-1);
                worker_show.Add(1);
            }
            else
            {
                worker_show.Add(0);
            }

        }
    }

    query << "SELECT * FROM `menus`";
    res = query.store();
    if (res)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            menus->Append(std2wx(std::string(row["name"]),wxConvUI));
            menu_ids.Add(int(row["id"]));
            if(int(row["show"]) == 1)
            {
                menus->SetSelection(menus->GetCount()-1);
                menu_show.Add(1);
            }
            else
            {
                menu_show.Add(0);
            }

        }
    }


    FlexGridSizer1->SetSizeHints(this);
}


void display_settings::OnButton1Click(wxCommandEvent& event)
{
    Show(0);
}

void display_settings::OnButton2Click(wxCommandEvent& event)
{
    wxArrayInt selections;
    wxArrayInt matrix;

    workers->GetSelections(selections);

    for(unsigned int i=0; i<worker_ids.GetCount(); i++) matrix.Add(0);
    for(unsigned int i=0; i<selections.GetCount(); i++)
    {
        matrix[selections[i]] = 1;
    }
    for(unsigned int i=0; i<worker_show.GetCount(); i++)
    {
        if(worker_show[i] != matrix[i])
        {
            mysqlpp::Query query = conn_display->query();
            query << "UPDATE `workers` SET `show` = '"<<matrix[i]<<"' WHERE `workers`.`id` ="<< worker_ids[i] <<" LIMIT 1";
            query.execute();
        }
    }
    menus->GetSelections(selections);
    matrix.Clear();

    for(unsigned int i=0; i<menu_ids.GetCount(); i++) matrix.Add(0);
    for(unsigned int i=0; i<selections.GetCount(); i++)
    {
        matrix[selections[i]] = 1;
    }
    for(unsigned int i=0; i<menu_show.GetCount(); i++)
    {
        if(menu_show[i] != matrix[i])
        {
            mysqlpp::Query query = conn_display->query();
            query << "UPDATE `menus` SET `show` = '"<<matrix[i]<<"' WHERE `menus`.`id` ="<< menu_ids[i] <<" LIMIT 1";
            query.execute();
        }
    }
    Show(0);
}
