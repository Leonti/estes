#include "stats_today.h"

//(*InternalHeaders(stats_today)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(stats_today)
const long stats_today::ID_STATICTEXT1 = wxNewId();
const long stats_today::ID_TEXTCTRL1 = wxNewId();
const long stats_today::ID_DATEPICKERCTRL1 = wxNewId();
const long stats_today::ID_DATEPICKERCTRL2 = wxNewId();
const long stats_today::ID_STATICTEXT4 = wxNewId();
const long stats_today::ID_STATICTEXT12 = wxNewId();
const long stats_today::ID_LISTBOX1 = wxNewId();
const long stats_today::ID_LISTBOX2 = wxNewId();
const long stats_today::ID_STATICTEXT13 = wxNewId();
const long stats_today::ID_STATICTEXT2 = wxNewId();
const long stats_today::ID_STATICTEXT5 = wxNewId();
const long stats_today::ID_STATICTEXT3 = wxNewId();
const long stats_today::ID_STATICTEXT6 = wxNewId();
const long stats_today::ID_STATICTEXT7 = wxNewId();
const long stats_today::ID_STATICTEXT8 = wxNewId();
const long stats_today::ID_STATICTEXT9 = wxNewId();
const long stats_today::ID_STATICTEXT10 = wxNewId();
const long stats_today::ID_STATICTEXT11 = wxNewId();
const long stats_today::ID_STATICTEXT14 = wxNewId();
const long stats_today::ID_STATICTEXT15 = wxNewId();
const long stats_today::ID_STATICTEXT16 = wxNewId();
const long stats_today::ID_STATICTEXT20 = wxNewId();
const long stats_today::ID_STATICTEXT17 = wxNewId();
const long stats_today::ID_STATICTEXT21 = wxNewId();
const long stats_today::ID_STATICTEXT18 = wxNewId();
const long stats_today::ID_STATICTEXT22 = wxNewId();
const long stats_today::ID_STATICTEXT19 = wxNewId();
const long stats_today::ID_STATICTEXT23 = wxNewId();
const long stats_today::ID_STATICTEXT24 = wxNewId();
const long stats_today::ID_STATICTEXT25 = wxNewId();
const long stats_today::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(stats_today,wxDialog)
	//(*EventTable(stats_today)
	//*)
END_EVENT_TABLE()

stats_today::stats_today(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(stats_today)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer3;
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer5;
	
	Create(parent, wxID_ANY, _("Sales statistics, account information"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Please select dates to view sales statistics:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(368,424), wxTE_MULTILINE|wxTE_READONLY|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
	wxFont TextCtrl1Font(10,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
	DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	FlexGridSizer3->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DatePickerCtrl2 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
	FlexGridSizer3->Add(DatePickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Orders:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT12, _("Days:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer3->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(80,400), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	FlexGridSizer3->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ListBox2 = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(115,300), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
	FlexGridSizer3->Add(ListBox2, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT13, _("Totals for the day:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	wxFont StaticText8Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText8->SetFont(StaticText8Font);
	BoxSizer2->Add(StaticText8, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	FlexGridSizer5 = new wxFlexGridSizer(5, 2, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Net:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer5->Add(StaticText2, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_net = new wxStaticText(this, ID_STATICTEXT5, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont static_netFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_net->SetFont(static_netFont);
	FlexGridSizer5->Add(static_net, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Taxes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer5->Add(StaticText3, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_taxes = new wxStaticText(this, ID_STATICTEXT6, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont static_taxesFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_taxes->SetFont(static_taxesFont);
	FlexGridSizer5->Add(static_taxes, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT7, _("Total:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	wxFont StaticText5Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	FlexGridSizer5->Add(StaticText5, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_total = new wxStaticText(this, ID_STATICTEXT8, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	wxFont static_totalFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_total->SetFont(static_totalFont);
	FlexGridSizer5->Add(static_total, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT9, _("Cash:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	wxFont StaticText6Font(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer5->Add(StaticText6, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	total_cash = new wxStaticText(this, ID_STATICTEXT10, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	wxFont total_cashFont(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	total_cash->SetFont(total_cashFont);
	FlexGridSizer5->Add(total_cash, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT11, _("Card:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	wxFont StaticText9Font(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText9->SetFont(StaticText9Font);
	FlexGridSizer5->Add(StaticText9, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	total_charge = new wxStaticText(this, ID_STATICTEXT14, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	wxFont total_chargeFont(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	total_charge->SetFont(total_chargeFont);
	FlexGridSizer5->Add(total_charge, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer2->Add(FlexGridSizer5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT15, _("Totals for the period:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	wxFont StaticText10Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText10->SetFont(StaticText10Font);
	BoxSizer1->Add(StaticText10, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	FlexGridSizer6 = new wxFlexGridSizer(5, 2, 0, 0);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT16, _("Net:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	wxFont StaticText11Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText11->SetFont(StaticText11Font);
	FlexGridSizer6->Add(StaticText11, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_net_period = new wxStaticText(this, ID_STATICTEXT20, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	wxFont static_net_periodFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_net_period->SetFont(static_net_periodFont);
	FlexGridSizer6->Add(static_net_period, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT17, _("Taxes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	wxFont StaticText12Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText12->SetFont(StaticText12Font);
	FlexGridSizer6->Add(StaticText12, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_taxes_period = new wxStaticText(this, ID_STATICTEXT21, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	wxFont static_taxes_periodFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_taxes_period->SetFont(static_taxes_periodFont);
	FlexGridSizer6->Add(static_taxes_period, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT18, _("Total:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	wxFont StaticText13Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText13->SetFont(StaticText13Font);
	FlexGridSizer6->Add(StaticText13, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	static_total_period = new wxStaticText(this, ID_STATICTEXT22, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	wxFont static_total_periodFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_total_period->SetFont(static_total_periodFont);
	FlexGridSizer6->Add(static_total_period, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT19, _("Cash:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	wxFont StaticText14Font(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText14->SetFont(StaticText14Font);
	FlexGridSizer6->Add(StaticText14, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	total_cash_period = new wxStaticText(this, ID_STATICTEXT23, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	wxFont total_cash_periodFont(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	total_cash_period->SetFont(total_cash_periodFont);
	FlexGridSizer6->Add(total_cash_period, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT24, _("Card:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	wxFont StaticText15Font(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText15->SetFont(StaticText15Font);
	FlexGridSizer6->Add(StaticText15, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	total_charge_period = new wxStaticText(this, ID_STATICTEXT25, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	wxFont total_charge_periodFont(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	total_charge_period->SetFont(total_charge_periodFont);
	FlexGridSizer6->Add(total_charge_period, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
	BoxSizer1->Add(FlexGridSizer6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Close"), wxPoint(504,640), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&stats_today::OnDatePickerCtrl1Changed);
	Connect(ID_DATEPICKERCTRL2,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&stats_today::OnDatePickerCtrl2Changed);
	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&stats_today::OnListBox1Select);
	Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&stats_today::OnListBox2Select);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&stats_today::OnButton1Click);
	//*)
}

stats_today::~stats_today()
{
	//(*Destroy(stats_today)
	//*)
}


void stats_today::OnButton1Click(wxCommandEvent& event)
{
Show(0);
}

wxString stats_today::info(int order_id){

return formatCheque(order_id, conn_stat, 32);
}

void stats_today::fill_all(){



    DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());

    refresh_all();
    refresh_day(DatePickerCtrl1->GetValue().FormatDate());

}

void stats_today::OnListBox1Select(wxCommandEvent& event)
{
     TextCtrl1->ChangeValue(info(order_ids[ListBox1->GetSelection()]));
}

void stats_today::refresh_day(wxString day){
double total=0;
double taxes=0;
double total_cash_v=0;
double total_charge_v=0;
order_ids.Clear();
TextCtrl1->Clear();
ListBox1->SetSelection(wxNOT_FOUND);
ListBox1->Clear();

wxDateTime timec;// = DatePickerCtrl1->GetValue();
timec.ParseDate(day.c_str());
wxDateTime timec_tomorrow = timec;
timec_tomorrow.Add(wxTimeSpan::Day());

    mysqlpp::Query query = conn_stat->query();
    query << "SELECT `id`,`number`,`amount`, `taxes`, `pay_type` FROM `orders` WHERE `time` > '"<< wx2std(timec.FormatISODate(),wxConvUI) <<"' AND time < '"<< wx2std(timec_tomorrow.FormatISODate(),wxConvUI) <<"' AND `status` = 2";
    mysqlpp::StoreQueryResult res = query.store();
    if (res){
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            wxString label;
            label << int(row["number"]);
            ListBox1->Append(label);
            order_ids.Add(int(row["id"]));
            int pay_type = int(row["pay_type"]);
            double amount = double(row["amount"]);
        if(pay_type == 1){
            total_cash_v += amount;
            }else if(pay_type == 2){
            total_charge_v += amount;
                }
            total += amount;
            taxes += double(row["taxes"]);
    }
    }

        static_total->SetLabel(addZero(total));
        static_taxes->SetLabel(addZero(taxes));
        static_net->SetLabel(addZero(total - taxes));
        total_cash->SetLabel(addZero(total_cash_v));
        total_charge->SetLabel(addZero(total_charge_v));

}



void stats_today::OnDatePickerCtrl1Changed(wxDateEvent& event)
{
    refresh_all();
   DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());
}

void stats_today::OnDatePickerCtrl2Changed(wxDateEvent& event)
{
    refresh_all();
}

void stats_today::refresh_all(){
    ListBox2->SetSelection(wxNOT_FOUND);
    ListBox2->Clear();
    wxDateTime start_date = DatePickerCtrl1->GetValue();
    wxDateTime end_date = DatePickerCtrl2->GetValue();
wxDateTime mysql_end_date = end_date;
mysql_end_date.Add(wxTimeSpan::Day());
//now counting money :D
double total=0;
double taxes=0;
double total_cash_v=0;
double total_charge_v=0;

    mysqlpp::Query query = conn_stat->query();
    query << "SELECT `amount`, `taxes`, `pay_type` FROM `orders` WHERE `time` > '"<< wx2std(start_date.FormatISODate(),wxConvUI) <<"' AND time < '"<< wx2std(mysql_end_date.FormatISODate(),wxConvUI) <<"' AND `status` = 2";
    mysqlpp::StoreQueryResult res = query.store();
    if (res){
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            int pay_type = int(row["pay_type"]);
            double amount = double(row["amount"]);
            if(pay_type == 1){
            total_cash_v += amount;
            }else if(pay_type == 2){
            total_charge_v += amount;
                }
            total += amount;
            taxes += double(row["taxes"]);

            }
            }

        static_total_period->SetLabel(addZero(total));
        static_taxes_period->SetLabel(addZero(taxes));
        static_net_period->SetLabel(addZero(total - taxes));
        total_cash_period->SetLabel(addZero(total_cash_v));
        total_charge_period->SetLabel(addZero(total_charge_v));




    ListBox2->Append(start_date.FormatDate());
    while(start_date < end_date){
    start_date.Add(wxTimeSpan::Day());
    ListBox2->Append(start_date.FormatDate());
        }

ListBox1->SetSelection(wxNOT_FOUND);
ListBox1->Clear();
static_net->SetLabel(_("0.00"));
static_taxes->SetLabel(_("0.00"));
static_total->SetLabel(_("0.00"));
total_cash->SetLabel(_("0.00"));
total_charge->SetLabel(_("0.00"));
    }

void stats_today::OnListBox2Select(wxCommandEvent& event)
{
  refresh_day(ListBox2->GetStringSelection());
}
