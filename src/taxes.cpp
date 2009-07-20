#include "taxes.h"

//(*InternalHeaders(taxes)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#include <wx/msgdlg.h>
//(*IdInit(taxes)
const long taxes::ID_STATICTEXT2 = wxNewId();
const long taxes::ID_LISTBOX1 = wxNewId();
const long taxes::ID_STATICTEXT3 = wxNewId();
const long taxes::ID_TEXTCTRL2 = wxNewId();
const long taxes::ID_STATICTEXT4 = wxNewId();
const long taxes::ID_STATICTEXT1 = wxNewId();
const long taxes::ID_TEXTCTRL1 = wxNewId();
const long taxes::ID_BUTTON1 = wxNewId();
const long taxes::ID_BUTTON2 = wxNewId();
const long taxes::ID_BUTTON3 = wxNewId();
const long taxes::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(taxes,wxDialog)
    //(*EventTable(taxes)
    //*)
END_EVENT_TABLE()

taxes::taxes(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(taxes)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;

    Create(parent, wxID_ANY, _("Edit taxes"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Please select a tax group:"), wxPoint(24,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(140,160), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer2->Add(ListBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(4, 0, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Value:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(64,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer4->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("%"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer4->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer5->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(104,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer5->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxDefaultPosition, wxSize(48,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer6->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    Button3 = new wxButton(this, ID_BUTTON3, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer3->Add(Button3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer1->Add(Button4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&taxes::OnListBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&taxes::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&taxes::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&taxes::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&taxes::OnButton4Click);
    //*)
}

taxes::~taxes()
{
    //(*Destroy(taxes)
    //*)
}
void taxes::fill_all()
{
    ListBox1 -> Clear();
    TextCtrl1 -> Clear();
    TextCtrl2 -> Clear();
    tax_ids.Clear();

    mysqlpp::Query query = conn_taxes -> query();
    query << "SELECT * FROM `taxes`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
            if (res.num_rows() != 0){
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            std::string tax_name = std::string(row["name"]);
            ListBox1->Append(std2wx(tax_name, wxConvUI));
            tax_ids.Add(int(row["id"]));
        }
            }
    }
}


void taxes::OnListBox1Select(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_taxes->query();
        query << "SELECT * FROM `taxes` WHERE `id`=" << tax_ids[ListBox1 -> GetSelection()];
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            if (res.num_rows() != 0){
            mysqlpp::Row row = res.at(0);
            TextCtrl2 -> Clear();
            wxString percent;
            percent << double(row["value"]);
            TextCtrl2 -> AppendText(percent);
            TextCtrl1 -> Clear();
            TextCtrl1 -> AppendText(std2wx(std::string(row["name"]),wxConvUI));
        }
        }


    }
}

void taxes::OnButton4Click(wxCommandEvent& event)
{
    Show(0);
}

void taxes::OnButton3Click(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_taxes -> query();
        query << "DELETE FROM `taxes` WHERE `taxes`.`id` = " << tax_ids[ListBox1 -> GetSelection()];
        query.execute();
        fill_all();
    }
}

void taxes::OnButton1Click(wxCommandEvent& event)
{
    // if (ListBox1->GetSelection() != wxNOT_FOUND)
       if (!TextCtrl1->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<ListBox1->GetCount(); i++)
        {
            if (TextCtrl1->GetValue() == ListBox1->GetString(i))
            {
                wxMessageBox(_("This TAX group already exists."));
                exist = 1;
                i=ListBox1->GetCount();
            }
        }
        if (exist == 0)
        {

            double tax_rate;
            TextCtrl2 -> GetValue().ToDouble(&tax_rate);
            mysqlpp::Query query = conn_taxes -> query();
            query << "INSERT INTO `taxes` (`id`, `name`, `value`) VALUES (NULL, '"<< wx2std(TextCtrl1->GetValue(), wxConvUI) <<"', '"<< tax_rate <<"')";
            query.execute();
            fill_all();
            TextCtrl2->Clear();
            TextCtrl1->Clear();
        }


    }


}

void taxes::OnButton2Click(wxCommandEvent& event)
{
    if (ListBox1->GetSelection() != wxNOT_FOUND){


            if (!TextCtrl1->IsEmpty())
    {
//                int selected = ListBox1 -> GetSelection();
            double tax_rate;
            TextCtrl2 -> GetValue().ToDouble(&tax_rate);

        mysqlpp::Query query = conn_taxes -> query();
        query << "UPDATE `taxes` SET `name` = '"<<wx2std(TextCtrl1->GetValue(), wxConvUI)<<"', `value` = '" << tax_rate << "' WHERE `taxes`.`id` = "<< tax_ids[ListBox1 -> GetSelection()] <<" LIMIT 1;";
        query.execute();


            fill_all();
            TextCtrl2->Clear();
            TextCtrl1->Clear();
 //           ListBox1 -> SetSelection(selected);

    }
        }
}
