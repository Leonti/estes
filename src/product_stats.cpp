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
#include "product_stats.h"

//(*InternalHeaders(product_stats)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

#include <wx/msgdlg.h>

//(*IdInit(product_stats)
const long product_stats::ID_STATICTEXT1 = wxNewId();
const long product_stats::ID_STATICTEXT2 = wxNewId();
const long product_stats::ID_DATEPICKERCTRL1 = wxNewId();
const long product_stats::ID_DATEPICKERCTRL2 = wxNewId();
const long product_stats::ID_STATICTEXT3 = wxNewId();
const long product_stats::ID_CHOICE1 = wxNewId();
const long product_stats::ID_STATICTEXT4 = wxNewId();
const long product_stats::ID_CHOICE2 = wxNewId();
const long product_stats::ID_TEXTCTRL1 = wxNewId();
const long product_stats::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(product_stats,wxDialog)
    //(*EventTable(product_stats)
    //*)
END_EVENT_TABLE()

product_stats::product_stats(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(product_stats)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;

    Create(parent, wxID_ANY, _("Product statistics"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Product statistics:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Select dates:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    FlexGridSizer2->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl2 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    FlexGridSizer2->Add(DatePickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Order by:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(159,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("Most revenue")) );
    Choice1->Append(_("Most frequently sold"));
    FlexGridSizer3->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Limit:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer4->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("10"));
    Choice2->SetSelection( Choice2->Append(_("15")) );
    Choice2->Append(_("20"));
    Choice2->Append(_("25"));
    Choice2->Append(_("30"));
    Choice2->Append(_("50"));
    Choice2->Append(_("100"));
    FlexGridSizer4->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(633,328), wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    wxFont TextCtrl1Font(10,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&product_stats::OnDatePickerCtrl1Changed);
    Connect(ID_DATEPICKERCTRL2,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&product_stats::OnDatePickerCtrl2Changed);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&product_stats::OnTypeSelect);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&product_stats::OnLimitSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&product_stats::OnButton1Click);
    //*)
}

product_stats::~product_stats()
{
    //(*Destroy(product_stats)
    //*)
}


void product_stats::OnButton1Click(wxCommandEvent& event)
{
    Show(0);
}

void product_stats::fill_all(void)
{
    DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());
    refresh();
}

void product_stats::OnDatePickerCtrl1Changed(wxDateEvent& event)
{
    DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());
    refresh();
}

void product_stats::refresh()
{

    int type = Choice1->GetSelection(); //0 - by revenue, 1 - by quantity


    mysqlpp::Query query = conn->query();
    wxDateTime start_date = DatePickerCtrl1->GetValue();
    wxDateTime end_date = DatePickerCtrl2->GetValue();
    wxDateTime mysql_end_date = end_date;
    mysql_end_date.Add(wxTimeSpan::Day());

    switch(type)
    {
    case 0:
        query << "SELECT `name` , SUM( `qty` ) AS `qty`, SUM(`qty`*`price`) AS `money_net`,SUM(`qty`*`price`*`tax`) AS `money_tax`\
FROM `orders_dishes` WHERE `order_id` = ANY (SELECT `id` FROM `orders` \
WHERE `time` > '"<< wx2std(start_date.FormatISODate(),wxConvUI) <<"' AND `time` < '"<< wx2std(mysql_end_date.FormatISODate(),wxConvUI) <<"')\
 GROUP BY `name` ORDER BY `money_net` DESC LIMIT " << wx2std(Choice2->GetStringSelection(),wxConvUI);
        break;
    case 1:
        query << "SELECT `name` , SUM( `qty` ) AS `qty`, SUM(`qty`*`price`) AS `money_net`,SUM(`qty`*`price`*`tax`) AS `money_tax`\
FROM `orders_dishes` WHERE `order_id` = ANY (SELECT `id` FROM `orders` \
WHERE `time` > '"<< wx2std(start_date.FormatISODate(),wxConvUI) <<"' AND `time` < '"<< wx2std(mysql_end_date.FormatISODate(),wxConvUI) <<"')\
 GROUP BY `name` ORDER BY `qty` DESC LIMIT " << wx2std(Choice2->GetStringSelection(),wxConvUI);
        break;
    }
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        wxString info;
        info << _("Name of the product       |   Qty   |   Net   |   Taxes   |   Gross\n\n");

        wxString infoVerse;
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            infoVerse.Clear();
            std::string name = std::string(row["name"]);
            int qty = int(row["qty"]);
            double money_net = round_2(double(row["money_net"]));
            double money_tax = round_2(double(row["money_tax"]));


            infoVerse << addSpaces(std2wx(name,wxConvUI),31);
            wxString temp;
            temp << qty;
            infoVerse << addSpaces(temp,8);
            infoVerse << addSpaces(addZero(money_net),11);
            infoVerse << addSpaces(addZero(money_tax),12);
            infoVerse << addZero(money_net + money_tax) << _T("\n");
            info << infoVerse;

        }
        TextCtrl1->ChangeValue(info);
    }

}

void product_stats::OnLimitSelect(wxCommandEvent& event)
{
    refresh();
}

void product_stats::OnTypeSelect(wxCommandEvent& event)
{
    refresh();
}

void product_stats::OnDatePickerCtrl2Changed(wxDateEvent& event)
{
    refresh();
}
