#include "waiter_choose.h"

//(*InternalHeaders(waiter_choose)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(waiter_choose)
const long waiter_choose::ID_LISTBOX1 = wxNewId();
const long waiter_choose::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(waiter_choose,wxDialog)
	//(*EventTable(waiter_choose)
	//*)
END_EVENT_TABLE()

waiter_choose::waiter_choose(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(waiter_choose)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxLB_NEEDED_SB, wxDefaultValidator, _T("ID_LISTBOX1"));
	FlexGridSizer1->Add(ListBox1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&waiter_choose::OnButton1Click);
	//*)
}

waiter_choose::~waiter_choose()
{
	//(*Destroy(waiter_choose)
	//*)
}
void waiter_choose::fill_all(){

        mysqlpp::Query query = conn_worker->query();
        query << "SELECT * FROM `workers`";
        mysqlpp::StoreQueryResult res = query.store();
          if (res)
        {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
                if(int(row["show"]) == 1){
         ListBox1->Append(std2wx(std::string(row["name"]),wxConvUI));
//         workers_ids.Add(int(row["id"]));
                    }

                }
            }
            	FlexGridSizer1->SetSizeHints(this);
selected_id = 0;
    }

void waiter_choose::OnButton1Click(wxCommandEvent& event)
{
    int sel = ListBox1->GetSelection();
    if(sel != wxNOT_FOUND){
    selected_id = sel;
    Show(0);
        }
}
