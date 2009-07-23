#include "payment.h"

//(*InternalHeaders(payment)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//(*IdInit(payment)
const long payment::ID_STATICTEXT1 = wxNewId();
const long payment::ID_BUTTON1 = wxNewId();
const long payment::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(payment,wxDialog)
	//(*EventTable(payment)
	//*)
END_EVENT_TABLE()

payment::payment(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(payment)
	wxBoxSizer* BoxSizer1;
	
	Create(parent, id, _("Please select payment type."), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(2, 0, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("CASH"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("CHARGE"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&payment::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&payment::OnButton2Click);
	//*)
print = false;
}

payment::~payment()
{
	//(*Destroy(payment)
	//*)
}
void payment::fill_all(double sum){
    order_total = sum;
    wxString label;
    label << addZero(sum) << _(" $ to pay.");
    StaticText1->SetLabel(label);
    FlexGridSizer1->SetSizeHints(this);
    }



void payment::OnButton2Click(wxCommandEvent& event)
{
    wxString label;
    label << _("Please enter ") << addZero(order_total) << _("$ on credit cards machine. When operation is over press OK.");
    wxMessageDialog charge(this, label, _("Charge order"), wxOK | wxCANCEL);
if(charge.ShowModal() == wxID_OK){
    Show(0);
    type = 2;
    paid = order_total;
    print = true;
    }
}

void payment::OnButton1Click(wxCommandEvent& event)
{
    cash* cash_dlg = new cash(this);
    cash_dlg->fill_all(order_total);
    cash_dlg->paid = &paid;
    cash_dlg->ShowModal();
    if(cash_dlg->print == true){
    type = 1;
    print = true;
    Show(0);
                }
}
