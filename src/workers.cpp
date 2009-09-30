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
#include "workers.h"

//(*InternalHeaders(workers)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/msgdlg.h>

//(*IdInit(workers)
const long workers::ID_STATICTEXT1 = wxNewId();
const long workers::ID_LISTBOX1 = wxNewId();
const long workers::ID_STATICTEXT2 = wxNewId();
const long workers::ID_TEXTCTRL1 = wxNewId();
const long workers::ID_BUTTON1 = wxNewId();
const long workers::ID_BUTTON2 = wxNewId();
const long workers::ID_BUTTON3 = wxNewId();
const long workers::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(workers,wxDialog)
    //(*EventTable(workers)
    //*)
END_EVENT_TABLE()

workers::workers(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(workers)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;

    Create(parent, id, _("Edit restaurant employees"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("List of employees:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(160,240), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer2->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 0, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(128,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer5 = new wxFlexGridSizer(2, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxDefaultPosition, wxSize(48,-1), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer5->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Rename"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer5->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer1->Add(Button4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&workers::OnListBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton4Click);
    //*)
}

workers::~workers()
{
    //(*Destroy(workers)
    //*)
}
void workers::fill_all()
{
    ListBox1 -> Clear();
    TextCtrl1 -> Clear();
    workers_ids.Clear();

    mysqlpp::Query query = conn_workers -> query();
    query << "SELECT * FROM `workers`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        if (res.num_rows() != 0)
        {
            mysqlpp::Row row;
            mysqlpp::StoreQueryResult::size_type i;
            for (i = 0; i < res.num_rows(); ++i)
            {
                row = res[i];
                std::string work_name = std::string(row["name"]);
                ListBox1->Append(std2wx(work_name, wxConvUI));
                workers_ids.Add(int(row["id"]));
            }
        }
    }

}


void workers::OnButton4Click(wxCommandEvent& event)
{
    Show(0);
}

void workers::OnButton3Click(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers -> query();
        query << "DELETE FROM `workers` WHERE `workers`.`id` = " << workers_ids[ListBox1 -> GetSelection()];
        query.execute();
        fill_all();
    }
}

void workers::OnButton1Click(wxCommandEvent& event)
{
    if (!TextCtrl1->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<ListBox1->GetCount(); i++)
        {
            if (TextCtrl1->GetValue() == ListBox1->GetString(i))
            {
                wxMessageBox(_("This worker already exists."));
                exist = 1;
                i=ListBox1->GetCount();
            }
        }
        if (exist == 0)
        {

            mysqlpp::Query query = conn_workers -> query();
            query << "INSERT INTO `workers` (`id`, `name`) VALUES (NULL, '"<< wx2std(TextCtrl1->GetValue(), wxConvUI) <<"')";
            query.execute();
            fill_all();
            TextCtrl1->Clear();
        }


    }


}

void workers::OnButton2Click(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND)
    {


        if (!TextCtrl1->IsEmpty())
        {

            mysqlpp::Query query = conn_workers -> query();
            query << "UPDATE `workers` SET `name` = '"<<wx2std(TextCtrl1->GetValue(), wxConvUI)<< "' WHERE `workers`.`id` = "<< workers_ids[ListBox1 -> GetSelection()] <<" LIMIT 1;";
            query.execute();


            fill_all();
//           TextCtrl2->Clear();
            TextCtrl1->Clear();
//           ListBox1 -> SetSelection(selected);

        }
    }
}

void workers::OnListBox1Select(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers->query();
        query << "SELECT * FROM `workers` WHERE `id`=" << workers_ids[ListBox1 -> GetSelection()];
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            if (res.num_rows() != 0)
            {
                mysqlpp::Row row = res.at(0);
                TextCtrl1 -> Clear();
                TextCtrl1 -> AppendText(std2wx(std::string(row["name"]),wxConvUI));
            }
        }


    }
}
