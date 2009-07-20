/***************************************************************
 * Name:      restaurant_posMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Leonti Bielski (prishelec@gmail.com)
 * Created:   2008-01-26
 * Copyright: Leonti Bielski (http://leonti.ru)
 * License:
 **************************************************************/

#include "restaurant_posMain.h"
#include "add_item.h"
#include "wx_std.h"
#include <wx/msgdlg.h>
#include "backup.h"

#include <time.h>
#include <datetime.h>

#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
//WX_DEFINE_OBJARRAY(receiptArray);

//(*InternalHeaders(restaurant_posFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include "editmenu.h"
#include "taxes.h"
#include "workers.h"
#include "product_stats.h"
//helper functions



enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(restaurant_posFrame)
const long restaurant_posFrame::ID_STATICTEXT10 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT9 = wxNewId();
const long restaurant_posFrame::ID_CHOICE2 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL4 = wxNewId();
const long restaurant_posFrame::ID_LISTCTRL1 = wxNewId();
const long restaurant_posFrame::ID_BUTTON5 = wxNewId();
const long restaurant_posFrame::ID_BUTTON2 = wxNewId();
const long restaurant_posFrame::ID_BUTTON11 = wxNewId();
const long restaurant_posFrame::ID_BUTTON12 = wxNewId();
const long restaurant_posFrame::ID_BUTTON4 = wxNewId();
const long restaurant_posFrame::ID_BUTTON1 = wxNewId();
const long restaurant_posFrame::ID_BUTTON3 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT1 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT4 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT2 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT5 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT3 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT6 = wxNewId();
const long restaurant_posFrame::ID_SPINCTRL1 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL1 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL2 = wxNewId();
const long restaurant_posFrame::ID_BUTTON8 = wxNewId();
const long restaurant_posFrame::ID_CHECKBOX2 = wxNewId();
const long restaurant_posFrame::ID_CHOICE1 = wxNewId();
const long restaurant_posFrame::ID_BUTTON9 = wxNewId();
const long restaurant_posFrame::ID_STATICTEXT8 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL3 = wxNewId();
const long restaurant_posFrame::ID_BUTTON10 = wxNewId();
const long restaurant_posFrame::ID_CHECKBOX1 = wxNewId();
const long restaurant_posFrame::ID_LISTBOX1 = wxNewId();
const long restaurant_posFrame::ID_BUTTON7 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL5 = wxNewId();
const long restaurant_posFrame::ID_TEXTCTRL6 = wxNewId();
const long restaurant_posFrame::ID_BUTTON6 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM6 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM7 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM8 = wxNewId();
const long restaurant_posFrame::idMenuQuit = wxNewId();
const long restaurant_posFrame::ID_MENUITEM1 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM3 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM4 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM9 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM10 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM5 = wxNewId();
const long restaurant_posFrame::ID_MENUITEM2 = wxNewId();
const long restaurant_posFrame::idMenuAbout = wxNewId();
const long restaurant_posFrame::ID_STATUSBAR1 = wxNewId();
//*)
const long restaurant_posFrame::SERVER_ID = wxNewId();
const long restaurant_posFrame::SOCKET_ID = wxNewId();

BEGIN_EVENT_TABLE(restaurant_posFrame,wxFrame)
    //(*EventTable(restaurant_posFrame)
    //*)
  EVT_SOCKET(SERVER_ID,  restaurant_posFrame::OnServerEvent)
  EVT_SOCKET(SOCKET_ID,  restaurant_posFrame::OnSocketEvent)
END_EVENT_TABLE()

restaurant_posFrame::restaurant_posFrame(wxWindow* parent,wxWindowID id)
{
    printdialogdata = new wxPrintDialogData();
    printdata = new wxPrintData();

    readSet();
    server_started = false;
    //(*Initialize(restaurant_posFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer9;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer13;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer12;
    wxMenu* Menu2;
    wxFlexGridSizer* FlexGridSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, _("Estes - Open Source Restaurant POS"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer3 = new wxFlexGridSizer(4, 0, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT10, _("Waiter:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer4->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT9, _("Order comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    waiter_choice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(240,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer4->Add(waiter_choice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    order_comment = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(290,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer4->Add(order_comment, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    compras = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(410,378), wxLC_REPORT|wxSUNKEN_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
    FlexGridSizer5->Add(compras, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6 = new wxFlexGridSizer(3, 0, 0, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Order"));
    Button5 = new wxButton(this, ID_BUTTON5, _("New"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    StaticBoxSizer1->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button9 = new wxButton(this, ID_BUTTON11, _("Send to kitchen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    StaticBoxSizer1->Add(Button9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button10 = new wxButton(this, ID_BUTTON12, _("Print"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    StaticBoxSizer1->Add(Button10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Payment"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer1->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6->Add(StaticBoxSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Items"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7 = new wxFlexGridSizer(3, 2, 0, 0);
    StaticTotal = new wxStaticText(this, ID_STATICTEXT1, _("Total:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticTotalFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTotal->SetFont(StaticTotalFont);
    FlexGridSizer7->Add(StaticTotal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTotalV = new wxStaticText(this, ID_STATICTEXT4, _("0.00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticTotalVFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTotalV->SetFont(StaticTotalVFont);
    FlexGridSizer7->Add(StaticTotalV, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTaxes = new wxStaticText(this, ID_STATICTEXT2, _("Taxes:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticTaxesFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTaxes->SetFont(StaticTaxesFont);
    FlexGridSizer7->Add(StaticTaxes, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTaxesV = new wxStaticText(this, ID_STATICTEXT5, _("0.00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticTaxesVFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticTaxesV->SetFont(StaticTaxesVFont);
    FlexGridSizer7->Add(StaticTaxesV, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticToPay = new wxStaticText(this, ID_STATICTEXT3, _("To Pay:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticToPayFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticToPay->SetFont(StaticToPayFont);
    FlexGridSizer7->Add(StaticToPay, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticToPayV = new wxStaticText(this, ID_STATICTEXT6, _("0.00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticToPayVFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticToPayV->SetFont(StaticToPayVFont);
    FlexGridSizer7->Add(StaticToPayV, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6->Add(FlexGridSizer7, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5->Add(FlexGridSizer6, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer5, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Edit item:"));
    FlexGridSizer8 = new wxFlexGridSizer(4, 4, 0, 0);
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 1, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("1"));
    FlexGridSizer8->Add(SpinCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(152,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer8->Add(TextCtrl1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer8->Add(TextCtrl2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Button8 = new wxButton(this, ID_BUTTON8, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    FlexGridSizer8->Add(Button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    kitchen_checkbox = new wxCheckBox(this, ID_CHECKBOX2, _("Kitchen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    kitchen_checkbox->SetValue(false);
    FlexGridSizer8->Add(kitchen_checkbox, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    taxes_choice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(168,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer8->Add(taxes_choice, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    change_button = new wxButton(this, ID_BUTTON9, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    FlexGridSizer8->Add(change_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT8, _("Comment"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer8->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(152,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer8->Add(TextCtrl3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    clear_button = new wxButton(this, ID_BUTTON10, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    FlexGridSizer8->Add(clear_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Keep values"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    FlexGridSizer8->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(FlexGridSizer8, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(StaticBoxSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10 = new wxFlexGridSizer(3, 1, 0, 0);
    FlexGridSizer11 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, this, _("Pending:"));
    FlexGridSizer9 = new wxFlexGridSizer(3, 0, 0, 0);
    pending_listbox = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(96,168), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer9->Add(pending_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button7 = new wxButton(this, ID_BUTTON7, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    FlexGridSizer9->Add(Button7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(FlexGridSizer9, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer11->Add(StaticBoxSizer4, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(FlexGridSizer11, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(20,125,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer12 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Kitchen chat"));
    FlexGridSizer13 = new wxFlexGridSizer(3, 1, 0, 0);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(350,120), wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer13->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(350,50), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer13->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer13->Add(Button6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer5->Add(FlexGridSizer13, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer12->Add(StaticBoxSizer5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(FlexGridSizer12, 1, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer2->Add(FlexGridSizer10, 1, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    Menu6 = new wxMenuItem(Menu1, ID_MENUITEM6, _("Install structure"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(Menu6);
    Menu7 = new wxMenuItem(Menu1, ID_MENUITEM7, _("Make backup"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(Menu7);
    Menu8 = new wxMenuItem(Menu1, ID_MENUITEM8, _("Restore from backup"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(Menu8);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Restaurant menu"), _("Edit restaurant menu"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Taxes"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Workers"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu9 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu9, ID_MENUITEM9, _("Account"), wxEmptyString, wxITEM_NORMAL);
    Menu9->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu9, ID_MENUITEM10, _("Statistics"), wxEmptyString, wxITEM_NORMAL);
    Menu9->Append(MenuItem8);
    MenuBar1->Append(Menu9, _("Orders"));
    Menu4 = new wxMenu();
    Menu5 = new wxMenuItem(Menu4, ID_MENUITEM5, _("General"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(Menu5);
    MenuItem4 = new wxMenuItem(Menu4, ID_MENUITEM2, _("Display Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem4);
    MenuBar1->Append(Menu4, _("Settings"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { -10, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OncomprasItemSelect);
    Connect(ID_LISTCTRL1,wxEVT_COMMAND_LIST_INSERT_ITEM,(wxObjectEventFunction)&restaurant_posFrame::OncomprasInsertItem);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton5Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton2Click);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton9Click);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton10Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton4Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton1Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton3Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton8Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::Onchange_buttonClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::Onclear_buttonClick);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::Onpending_listboxSelect);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton7Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&restaurant_posFrame::OnButton6Click);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenu6Selected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenu7Selected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenu8Selected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuItem3Selected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuItem5Selected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuItem6Selected);
    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuItem7Selected);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuStatisticsSelected);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenu5Selected);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnMenuItem4Selected1);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&restaurant_posFrame::OnAbout);
    //*)





    dbase_connected = false;
    restaurant_posFrame::conn = new mysqlpp::Connection(false);
    connect_to_db();



//end connecting

    font_listctrl = new wxFont(15, wxFontFamily(wxFONTFAMILY_DEFAULT), wxFONTSTYLE_NORMAL, wxFontWeight(wxFONTWEIGHT_NORMAL));
//making listbox look how we need it to look ;)
    wxListItem itemCol;
    itemCol.SetText(_T("Qty"));
    //  itemCol.SetImage(-1);
    itemCol.SetAlign(wxLIST_FORMAT_LEFT);
    compras->InsertColumn(0, itemCol);

    itemCol.SetText(_T("Name"));
    itemCol.SetAlign(wxLIST_FORMAT_LEFT);
    compras->InsertColumn(1, itemCol);

    itemCol.SetText(_T("Price"));
    itemCol.SetAlign(wxLIST_FORMAT_LEFT);
    compras->InsertColumn(2, itemCol);
    compras->SetColumnWidth( 0, 35  );
    compras->SetColumnWidth( 1, 200 );
    compras->SetColumnWidth( 2, 50 );

//printing of tickets handling

printing = new wxHtmlEasyPrinting();




printdialogdata ->EnableHelp(false);
printdialogdata ->EnablePageNumbers(false);
printdialogdata ->EnablePrintToFile(false);
printdialogdata ->EnableSelection(false);


fill_pending();
refresh_taxes();
refresh_waiters();
refresh_menus();
refresh_kitchen();

//printing -> PageSetup();
//printing -> PreviewText(_T("<p>Preved, medved!"));
}
void restaurant_posFrame::readSet(){
    restaurant_posFrame::conn = new mysqlpp::Connection(false);

    config = new wxConfig(_("restaurant_pos"));
    set_now.lang = 0;
    wxString lng = config->Read(_T("program/lang"));
    if(lng!=_T("")){
        long temp;
        lng.ToLong(&temp);
        set_now.lang = temp;
        }



    if (config->Read(_("/program/run")) !=_("1") || config->Read(_("/program/run_again")) == _("1"))
    {
    settings* set_dlg = new settings(this);
    set_dlg -> confi = config;
    set_dlg -> conn = conn;
    set_dlg -> set_now = &set_now;
    set_dlg -> fill_all();
    set_dlg -> ShowModal();
    delete set_dlg;
 }

 if(set_now.lang != 0){
Locale.Init(set_now.lang, wxLOCALE_CONV_ENCODING);
wxLocale::AddCatalogLookupPathPrefix(wxT("./lang"));
                // Initialize the catalogs we'll be using
Locale.AddCatalog(wxT("restaurant_pos"));
    }

//set_now.kitchen = false;
if(config->Read(_("/program/kitchen")) == _("1")){
     set_now.kitchen = true;
     }else{
     set_now.kitchen = false;
         }

set_now.kitchen_type = 1;
if(config->Read(_("/program/kitchen_type")) == _("2")){
     set_now.kitchen_type = 2;
         }

if(config->Read(_("/program/custom_print")) == _("1")){
    set_now.custom_print = true;
    }else{
    set_now.custom_print = false;
        }
set_now.print_command = config->Read(_T("program/print_command"));

if(config->Read(_("/program/custom_drawer")) == _("1")){
    set_now.custom_drawer = true;
    }else{
    set_now.custom_drawer = false;
        }
set_now.drawer_command = config->Read(_T("program/drawer_command"));


if(config->Read(_("/program/custom_ticket")) == _("1")){
    set_now.custom_ticket = true;
    }else{
    set_now.custom_ticket = false;
        }
set_now.ticket_command = config->Read(_T("program/ticket_command"));

if(config->Read(_("/program/custom_width")) == _("1")){
    set_now.custom_width = true;
    }

 set_now.print_width = 40; //default setting
     wxString c_width = config->Read(_T("program/print_width"));
    if(c_width!=_T("")){
        long temp;
        c_width.ToLong(&temp);
        set_now.print_width = temp;
        }

//reading printint settings
int bin;

if(config->Read(_T("program/printing/bin"), &bin)){
    printdata -> SetBin(wxPrintBin(bin));
    printdata -> SetCollate(config -> Read(_T("program/printing/collate"), true));
    printdata -> SetColour(config -> Read(_T("program/printing/colour"), true));
    printdata -> SetDuplex(wxDuplexMode(config -> Read(_T("program/printing/duplex"), 0l)));
    printdata -> SetNoCopies(config -> Read(_T("program/printing/nocopies"), 0l));
    printdata -> SetOrientation(config -> Read(_T("program/printing/orientation"), 0l));
    printdata -> SetPaperId(wxPaperSize(config -> Read(_T("program/printing/paperid"), 0l)));
    printdata -> SetPrinterName(config -> Read(_T("program/printing/printername")));
    printdata -> SetQuality(wxPrintQuality(config -> Read(_T("program/printing/quality"), 0l)));
    printdialogdata -> SetPrintData(*printdata);
    }

    }


restaurant_posFrame::~restaurant_posFrame()
{
    //(*Destroy(restaurant_posFrame)
    //*)
}

void restaurant_posFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void restaurant_posFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

bool restaurant_posFrame::startServer(){
  wxIPV4address addr;
  addr.Service(3000);

  Socketserver1 = new wxSocketServer(addr);

  if (! Socketserver1->Ok())
  {
          StatusBar1->SetStatusText(_("Could not listen at the specified port !"), 1);
    return false;
  }
  else
  {
    StatusBar1->SetStatusText(_("Server started. Listening..."), 1);
  }

  Socketserver1->SetEventHandler(*this, SERVER_ID);
  Socketserver1->SetNotify(wxSOCKET_CONNECTION_FLAG);
  Socketserver1->Notify(true);
  return true;
    }

void restaurant_posFrame::OnServerEvent(wxSocketEvent& event){
//  wxSocketBase *sock;
  sockAccepted = Socketserver1->Accept(false);

  if (sockAccepted)
  {
    StatusBar1->SetStatusText(_("New client connection accepted"), 1);
  }
  else
  {
    StatusBar1->SetStatusText(_("Error: couldn't accept a new connection"), 1);
    return;
  }

  sockAccepted->SetEventHandler(*this, SOCKET_ID);
  sockAccepted->SetNotify(wxSOCKET_INPUT_FLAG | wxSOCKET_LOST_FLAG);
  sockAccepted->Notify(true);
    }

void restaurant_posFrame::OnSocketEvent(wxSocketEvent& event){
  wxSocketBase *sock = event.GetSocket();

  switch(event.GetSocketEvent())
  {
    case wxSOCKET_INPUT:
    {
      sock->SetNotify(wxSOCKET_LOST_FLAG);

    unsigned char c;
      sock->Read(&c, 1);

      switch (c)
      {
        case 0xBE: readFromKitchen(sock); break; //this means we are receiving something from kitchen
      //  case 0xCE: Test2(sock); break;
      //  case 0xDE: Test3(sock); break;
      }

      sock->SetNotify(wxSOCKET_LOST_FLAG | wxSOCKET_INPUT_FLAG);
      break;
    }
    case wxSOCKET_LOST:
    {
      StatusBar1->SetStatusText(_("Lost connection."),1);
      sock->Destroy();
      break;
    }
    default: ;
  }
      }

void restaurant_posFrame::readFromKitchen(wxSocketBase *sock){
    unsigned char len;
    char *buf;
    sock->SetFlags(wxSOCKET_WAITALL);
      // Read the size
  sock->Read(&len, 1);
  buf = new char[len];

  // Read the data
  sock->Read(buf, len);
  wxString s;
  s.Printf(_("%s"), buf);
//if buf == r:id it means that order 'id' is ready we can update the info
if(s.Mid(0,2) == _T("r:")){
    //here do something useful :)
wxMessageBox(_T("Order number ") + s.Mid(2, s.Length()) + _T(" is ready!"));
    }else
    if(s.Mid(0,2) == _T("m:")){
    TextCtrl4 -> AppendText (s.Mid(2, s.Length()) + _T("\n"));
        }

    }


void restaurant_posFrame::fill_pending(){
            mysqlpp::Query query = conn->query();
        query << "SELECT * FROM `orders` WHERE `time` > '"<< get_time() <<"'";
        mysqlpp::StoreQueryResult res = query.store();
               if (res)
        {
            if (res.num_rows() != 0){

mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
                if(int(row["status"]) != 2){ //2 means this order is paid
            pending_items.Add(int(row["id"]));
            wxString to_append;
            to_append << int(row["number"]);
            pending_listbox -> Append(to_append);
                }

                }
            }
        }
    }






void restaurant_posFrame::OnMenuItem3Selected(wxCommandEvent& event)
{
    editmenu* menuedit = new editmenu(this);
    menuedit->conn_edit = conn;
    menuedit->fill_all();
    menuedit->ShowModal();
    refresh_menus();
    refresh_taxes();
}


int  restaurant_posFrame::connect_to_db(void)
{

    host = config->Read(_("/mysql/host"));
    user = config->Read(_("/mysql/user"));
    pass = config->Read(_("/mysql/pass"));
    dbase = config->Read(_("/mysql/dbase"));



    if (restaurant_posFrame::conn->connect(wx2std(dbase,wxConvUI).c_str(),wx2std(host,wxConvUI).c_str(),wx2std(user,wxConvUI).c_str(),wx2std(pass,wxConvUI).c_str()))
    {
        StatusBar1->SetStatusText(_("Connected to database '") + dbase + _("' on ") + host,0);
        dbase_connected = true;
        return 0;
    }
    else
    {
        StatusBar1->SetStatusText(_("Unable no connect to database '") + dbase + _("' on ") + host,0);

        wxMessageBox(_("Unable to connect to the database. Reason:\n") + std2wx(conn -> error(),wxConvUI),_("Not connected."), wxOK);
        dbase_connected = false;
        return 1;
    }



}

void restaurant_posFrame::OnButton1Click(wxCommandEvent& event)
{
    add_item * add_frame = new add_item(this);
    add_frame -> conn_add = conn;
    //10,9,8
//later other way ;)

for(int i=0; i<menus_show.GetCount(); i++){
    add_frame -> menus_to_show.Add(menus_show[i]);
}
    if(set_now.kitchen == true) add_frame -> kitchen = true; else add_frame -> kitchen = false;
    add_frame -> main_list_ctrl = compras;
    add_frame -> items_add_item = &all_items;
    add_frame -> main_font_listctrl = font_listctrl;
    add_frame -> fill_all();
    add_frame -> Show();
}

void restaurant_posFrame::OnButton2Click(wxCommandEvent& event)
{
    save_order();
    clear_order();
    add_additional_clear();
}
void restaurant_posFrame::clear_order(){
    compras -> DeleteAllItems();
    all_items.Clear();
    pending_listbox->SetSelection(wxNOT_FOUND);
    waiter_choice->SetSelection(0);
    order_comment->Clear();
    total();
    }

void restaurant_posFrame::save_order(){
    if(all_items.GetCount()!=0){
        mysqlpp::Query query = conn->query();
//        query << "SELECT `id` FROM `orders` WHERE `time` > '"<< get_time() <<"'";
//        mysqlpp::StoreQueryResult res = query.store();  //Should be more elegant way to count rows
        int count = 0;
//        if(res) count = res.num_rows();

        query << "SELECT `number` FROM `orders` WHERE `time` > '" << get_time() << "'ORDER BY `id` DESC LIMIT 1";
        mysqlpp::StoreQueryResult res = query.store();
        mysqlpp::Row row;
        if(res.num_rows() != 0 ){

        row = res.at(0);
        count = int(row["number"]);
        }



//now actually adding new order
int ind;
    if(pending_listbox -> GetSelection() == wxNOT_FOUND){
        query << "INSERT INTO `orders` (`id`, `number`, `time`, `status`, `waiter_id`, `comment`) VALUES (NULL, '" << (count + 1) << "', CURRENT_TIMESTAMP, '0', '"<< workers_ids[waiter_choice->GetSelection()] <<"' , '"<<wx2std(order_comment->GetValue(),wxConvUI)<<"')";
        query.execute();
        query << "SELECT `id` FROM `orders` ORDER BY `id` DESC LIMIT 1";
        res = query.store();
        mysqlpp::Row row;
        row = res.at(0);
        ind = int(row["id"]);

        pending_items.Add(ind);
        wxString to_append;
        to_append << (count + 1);
        pending_listbox -> Append(to_append);

    }else{

     ind = pending_items[pending_listbox -> GetSelection()];
     query << "UPDATE `orders` SET `waiter_id` = '"<< workers_ids[waiter_choice->GetSelection()] <<"', `comment` = '"<< wx2std(order_comment->GetValue(),wxConvUI) <<"' WHERE `id` = "<< ind <<" LIMIT 1";
     query.execute();
     query << "DELETE FROM `orders_dishes` WHERE `order_id` = " << ind;
     query.execute();
        }

        for(int i=0; i<all_items.GetCount(); i++){
int kitchen = 1;
                if(!all_items[i].kitchen){
                    kitchen = 0;
                    }

        query << "INSERT INTO `orders_dishes` (`id`, `order_id`, `qty`, `name`, `price`, `tax`, `tax_id`, `comment`, `kitchen`) VALUES (NULL, '"<< ind <<"', '"<< all_items[i].qty <<"', '"<< wx2std(all_items[i].name, wxConvUI) <<"', '"<< all_items[i].price <<"', '"<< all_items[i].tax <<"', '"<< all_items[i].tax_id << "', '"<< wx2std(all_items[i].comment, wxConvUI) <<"', '"<< kitchen <<"')";
        query.execute();

        query << "SELECT `id` FROM `orders_dishes` ORDER BY `id` DESC LIMIT 1";
        res = query.store();
        mysqlpp::Row row;
        row = res.at(0);
        int orderDishId = int(row["id"]);


        wxArrayString parts;
        parts = explode(all_items[i].parts);
for(int j=0; j< parts.GetCount(); ++j){
long partId = 0;
int use = 0;
wxString n = _T("n");
if(parts[j].Mid(0,1) == n){
    wxString part = parts[j].Mid(1,parts[j].Length()-1);
    part.ToLong(&partId);
    use = 0;
    }else{
    parts[j].ToLong(&partId);
    use = 1;
        }
        query << "INSERT INTO `orders_dishes_parts` (`id`, `orders_dishes_id`, `parts_id`, `using`) VALUES (NULL, '"<< orderDishId <<"', '"<< partId <<"', '"<< use <<"')";
        query.execute();

    }

                    }


    }

    }


void restaurant_posFrame::total(void){

        double total = 0;
        double taxes = 0;
    for (int i=0; i< all_items.GetCount(); i++)
    {

    total += all_items[i].price * all_items[i].qty;
    taxes += all_items[i].price * all_items[i].tax * all_items[i].qty;
    }
total = round_2(total);
taxes = round_2(taxes);

    wxString to_p;
    order_total = round_2(total + taxes);
 StaticTotalV -> SetLabel(addZero(total));
  StaticTaxesV -> SetLabel(addZero(taxes));
   StaticToPayV -> SetLabel(addZero(total + taxes));
    }

void restaurant_posFrame::OnMenuItem5Selected(wxCommandEvent& event)
{

    taxes* tax_dlg = new taxes(this);
    tax_dlg -> conn_taxes = conn;
    tax_dlg -> fill_all();
    tax_dlg -> ShowModal();
    refresh_taxes();
    delete tax_dlg;
}

void restaurant_posFrame::OnButton3Click(wxCommandEvent& event)
{
wxArrayInt to_delete;
    for(int i=0; i< compras -> GetItemCount(); i++){
      if(compras -> GetItemState(i, wxLIST_STATE_SELECTED) == wxLIST_STATE_SELECTED) {
            to_delete.Add(i);
          }
        }

      for(int i = 0; i<to_delete.GetCount(); i++){ //have to do it because whan we delete something from array, number is changing
          compras -> DeleteItem(to_delete[i]-i);
        all_items.RemoveAt(to_delete[i]-i);

          }
total();
}




void restaurant_posFrame::OncomprasInsertItem(wxListEvent& event)
{
    total();
}


void restaurant_posFrame::OnMenuItem6Selected(wxCommandEvent& event)
{
    workers* workers_dlg = new workers(this);
    workers_dlg -> conn_workers = conn;
    workers_dlg -> fill_all();
    workers_dlg -> ShowModal();
    refresh_waiters();
    delete workers_dlg;
}

void restaurant_posFrame::OnMenu5Selected(wxCommandEvent& event)
{
    settings* set_dlg = new settings(this);
    set_dlg -> confi = config;
    if(dbase_connected == true){
    set_dlg -> dbase_connected = true;
    }
        set_dlg -> conn = conn;
    set_dlg -> set_now = &set_now;
    set_dlg -> printdialogdata = printdialogdata;
    set_dlg -> fill_all();
    set_dlg -> ShowModal();

    if (
        host != config->Read(_("/mysql/host")) ||
        user != config->Read(_("/mysql/user")) ||
        pass != config->Read(_("/mysql/pass")) ||
        dbase != config->Read(_("/mysql/dbase"))
    )
    {
        connect_to_db();
    }
        refresh_kitchen();

}

void restaurant_posFrame::OnMenu7Selected(wxCommandEvent& event)
{
    //make backup
        if(dbase_connected){
    wxFileDialog* save_file_dlg = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    save_file_dlg -> ShowModal();
    if(save_file_dlg->GetFilename() != _("")){
//    wxString result;
   int result = makeDump(conn, save_file_dlg -> GetPath());
if(result == 0) wxMessageBox(_("There was a problem. Backup is not done."));
    }
        }else{
     wxMessageBox(_("You are not connected to the database!"));
        }
}

void restaurant_posFrame::OnMenu8Selected(wxCommandEvent& event)
{
    //rstore from backup
    if(dbase_connected){
    wxFileDialog* open_file_dlg = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    open_file_dlg -> ShowModal();
        if(open_file_dlg->GetFilename() != _("")){
   // wxString result;
    int result = restoreFromDump(conn, open_file_dlg -> GetPath());
if(result == 0) wxMessageBox(_("There was a problem. Data is not restored."));
        }
    }else{
     wxMessageBox(_("You are not connected to the database!"));
        }

}

void restaurant_posFrame::OnMenu6Selected(wxCommandEvent& event)
{

    if(dbase_connected){

 //   int result = restore_table(host, user, pass, dbase, _("table_schema.sql"));
   int result = restoreFromDump(conn, _("table_schema.sql"));

if(result == 0) wxMessageBox(_("There was a problem. Database structure is not installed"));

    }else{
     wxMessageBox(_("You are not connected to the database!"));
        }


}

std::string get_time(){
    time_t rawtime;
    struct tm * comp_time;
    time ( &rawtime );
    comp_time = localtime ( &rawtime );

    wxString db_date;
    db_date << (1900 + comp_time->tm_year) << _("-") << (1 + comp_time->tm_mon) << _("-") << comp_time->tm_mday;
    return wx2std(db_date, wxConvUI);
    }

void restaurant_posFrame::Onpending_listboxSelect(wxCommandEvent& event)
{
       compras -> DeleteAllItems();
       all_items.Clear();

        mysqlpp::Query query = conn->query();
        query << "SELECT * FROM `orders` WHERE `id`=" << pending_items[pending_listbox->GetSelection()];
        mysqlpp::StoreQueryResult res = query.store();

 if (res){

mysqlpp::Row row = res.at(0);
int wait_id = int(row["waiter_id"]);
if(wait_id != 0){
for(int i=0; i<workers_ids.GetCount(); i++){
if(workers_ids[i] == wait_id){
 waiter_choice->SetSelection(i);
 break;
    }
    }
}
order_comment->ChangeValue(std2wx(std::string(row["comment"]),wxConvUI));
     }





        query << "SELECT * FROM `orders_dishes` WHERE `order_id`=" << pending_items[pending_listbox->GetSelection()];
        res = query.store();
       if (res)
        {

mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
        item_entry dish_to_add;
        dish_to_add.qty = int(row["qty"]);
        dish_to_add.name = std2wx(std::string(row["name"]), wxConvUI);
        dish_to_add.tax = double(row["tax"]);
        dish_to_add.tax_id = int(row["tax_id"]);
        dish_to_add.price = double(row["price"]);
        dish_to_add.comment =  std2wx(std::string(row["comment"]), wxConvUI);
        dish_to_add.kitchen = false;
        if(int(row["kitchen"]) == 1){
            dish_to_add.kitchen = true;
            }

        all_items.Add(dish_to_add);



        //adding to listctrl
            wxString price;
    wxString qty;
    qty << dish_to_add.qty;
//    items_add_item -> Add(dish_to_add);
    long tmp = compras -> InsertItem(compras -> GetItemCount(), qty, 0);
    compras->SetItemData(tmp, 1);
    compras->SetItemFont(tmp, *font_listctrl);
    compras->SetItem(tmp, 1, dish_to_add.name);
    compras->SetItem(tmp, 2, addZero(dish_to_add.price));

                }
total();
        }

}

void restaurant_posFrame::OnButton4Click(wxCommandEvent& event)
{
    if(all_items.GetCount()!=0){ //this means we have some item to check out
    if(pending_listbox -> GetSelection() == wxNOT_FOUND){ //this means those items are not saved
save_order();
    }

payment *pay_dlg = new payment(this);
pay_dlg->fill_all(order_total);
pay_dlg -> ShowModal();


if(pay_dlg -> print){


int ind;
    if(pending_listbox -> GetSelection() != wxNOT_FOUND){
    ind = pending_items[pending_listbox->GetSelection()];
    pending_items.RemoveAt(pending_listbox->GetSelection(),1);
    int sel = pending_listbox->GetSelection();
    pending_listbox->SetSelection(wxNOT_FOUND);
    pending_listbox->Delete(sel);
        }else{
    ind = pending_items[pending_listbox->GetCount()-1];
    pending_items.RemoveAt(pending_listbox->GetCount()-1,1);
    pending_listbox->Delete(pending_listbox->GetCount()-1);
                        }

        mysqlpp::Query query = conn->query();
        query << "UPDATE `orders` SET `status` = '2', `pay_type` = '"<< pay_dlg->type <<"', `amount_given` = '"<< pay_dlg->paid <<"', `amount` = '"<< order_total <<"', `taxes` = '"<< wx2std(StaticTaxesV->GetLabel(),wxConvUI) <<"' WHERE `id` = "<< ind <<" LIMIT 1";
        query.execute();
        printReceipt(formatCheque(ind, conn, set_now.print_width), set_now.print_command, set_now.custom_print );
        openDrawer(set_now.drawer_command, set_now.custom_drawer );
        clear_order();
        add_additional_clear();
 }

delete pay_dlg;
        }
}

void restaurant_posFrame::OnButton5Click(wxCommandEvent& event)
{
    waiter_choose *waiter_dlg = new waiter_choose(this);
    waiter_dlg -> conn_worker = conn;
//    waiter_dlg -> workers_ids = &workers_ids;
//    waiter_dlg -> choice_from_main = waiter_choice;
    waiter_dlg -> fill_all();
    waiter_dlg -> ShowModal();
    selected_worker = waiter_dlg -> selected_id;
    waiter_choice->SetSelection(selected_worker);
    all_items.Clear();
    pending_listbox -> SetSelection(wxNOT_FOUND); // find
    compras -> DeleteAllItems();
    total();
}

void restaurant_posFrame::OnButton7Click(wxCommandEvent& event)
{
        if(pending_listbox -> GetSelection() != wxNOT_FOUND){
wxMessageDialog ask_dlg(this, _("This order is not paid. Are you sure you want to delete it?"), _("Delete order"), wxOK | wxCANCEL);
if(ask_dlg.ShowModal() == wxID_OK){
        mysqlpp::Query query = conn->query();
        int ind = pending_items[pending_listbox -> GetSelection()];

        query << "DELETE FROM `orders` WHERE `id` = " << ind;
        query.execute();

        query << "DELETE FROM `orders_dishes_parts` WHERE `orders_dishes_id`=ANY(SELECT `id` FROM `orders_dishes` WHERE `order_id`="<< ind <<")";
        query.execute();

        query << "DELETE FROM `orders_dishes` WHERE `order_id` = " << ind;
        query.execute();

    all_items.Clear();
    compras -> DeleteAllItems();
    pending_items.RemoveAt(pending_listbox -> GetSelection(),1);
int sel = pending_listbox -> GetSelection();
pending_listbox -> SetSelection(wxNOT_FOUND);
    pending_listbox -> Delete(sel);
    }
            }
}


void restaurant_posFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
/*
    wxString amount = TextCtrl2 -> GetValue();
    amount.Replace(_("."), _(""));
    if(amount.Length()>2){
    amount.insert(amount.Length() - 2,_("."));
        }else{
    amount.insert(0,_("."));
        }

//TextCtrl2 -> ChangeValue(_("hello!"));
    TextCtrl2 -> ChangeValue(amount);

TextCtrl2 -> SetInsertionPointEnd();
*/
}


void restaurant_posFrame::OnTextCtrl2TextEnter(wxCommandEvent& event)
{
    add_additional_item();
}

void restaurant_posFrame::add_additional_item(){
    double price;
    wxString price_str = TextCtrl2->GetValue();
    price_str.ToDouble(&price);
  double tax = 0;
  int id_tax = taxes_array[taxes_choice->GetSelection()];
    mysqlpp::Query query = conn->query();
    query << "SELECT `value` FROM `taxes` WHERE `id` = "<< id_tax <<" LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if(res){
     mysqlpp::Row row;
     row = res.at(0);
     tax = double(row["value"]);
        }

    add_to_listctrl(SpinCtrl1->GetValue(), TextCtrl1->GetValue(), tax/100, id_tax, price, TextCtrl3->GetValue(),kitchen_checkbox->GetValue());
if(!CheckBox1->GetValue()){
    add_additional_clear();
}
    }

void restaurant_posFrame::OnButton8Click(wxCommandEvent& event)
{
    add_additional_item();
}

void restaurant_posFrame::add_to_listctrl(int qty, wxString name, double tax, int tax_id, double price, wxString comment, bool kitchen = false){
        item_entry dish_to_add;
        dish_to_add.qty = qty;
        dish_to_add.name = name;
        dish_to_add.tax = tax;
        dish_to_add.tax_id = tax_id;
        dish_to_add.price = price;
        dish_to_add.comment = comment;
        dish_to_add.kitchen = kitchen;
        all_items.Add(dish_to_add);
        //adding to listctrl
            wxString price_str;
//    price_str << dish_to_add.price;
    wxString qty_str;
    qty_str << dish_to_add.qty;

    long tmp = compras -> InsertItem(compras -> GetItemCount(), qty_str, 0);
    compras->SetItemData(tmp, 1);
    compras->SetItemFont(tmp, *font_listctrl);
    compras->SetItem(tmp, 1, dish_to_add.name);
    compras->SetItem(tmp, 2, addZero(dish_to_add.price));

    }
void restaurant_posFrame::refresh_taxes(){
    taxes_choice -> Clear();
    taxes_array.Clear();
    mysqlpp::Query query = conn->query();
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
            taxes_choice->Append(std2wx(tax_name, wxConvUI));
            taxes_array.Add(int(row["id"]));
        }
                    }
    }
    taxes_choice->SetSelection(0);

    }

void restaurant_posFrame::refresh_waiters(){
    waiter_choice -> Clear();
    workers_ids.Clear();
    mysqlpp::Query query = conn -> query();
    query << "SELECT * FROM `workers`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        if (res.num_rows() != 0){
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i) {
        row = res[i];

                          if(int(row["show"]) == 1){
         waiter_choice->Append(std2wx(std::string(row["name"]),wxConvUI));
         workers_ids.Add(int(row["id"]));
                    }
        }
        }
    }
    waiter_choice->SetSelection(0);

    }

void  restaurant_posFrame::refresh_menus(){
    menus_show.Clear();
        mysqlpp::Query query = conn->query();
        query << "SELECT * FROM `menus`";
        mysqlpp::StoreQueryResult res = query.store();
          if (res)
        {
            if (res.num_rows() != 0){
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
                if(int(row["show"]) == 1){
                    menus_show.Add(int(row["id"]));
                    }
                }
            }
        }
    }

void restaurant_posFrame::refresh_kitchen(){
if(set_now.kitchen && set_now.kitchen_type ==1){
    if(!server_started){
server_started = startServer();
    }
    if(server_started){
    TextCtrl4->Enable(true);
    TextCtrl5->Enable(true);
    Button6->Enable(true);
    Button9->Enable(true);
    }
    Button10->Enable(false);
}else{
    TextCtrl4->Enable(false);
    TextCtrl5->Enable(false);
    Button6->Enable(false);
    Button9->Enable(false);
    StatusBar1->SetStatusText(_(""), 1);
    if(set_now.kitchen && set_now.kitchen_type ==2){
    Button10->Enable(true);
        }else{
    Button10->Enable(false);
        }
}
    }

void restaurant_posFrame::add_additional_clear(){
    SpinCtrl1->SetValue(1);
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
    taxes_choice->SetSelection(0);
    kitchen_checkbox->SetValue(false);
    }

void restaurant_posFrame::OncomprasItemSelect(wxListEvent& event)
{
    item_to_change = event.m_itemIndex;
   SpinCtrl1->SetValue(all_items[item_to_change].qty);
   TextCtrl1->ChangeValue(all_items[item_to_change].name);
   TextCtrl2->ChangeValue(addZero(all_items[item_to_change].price));
TextCtrl3->ChangeValue(all_items[item_to_change].comment);
kitchen_checkbox->SetValue(all_items[item_to_change].kitchen);
    for(int i=0; i < taxes_array.GetCount(); i++){
        if(all_items[item_to_change].tax_id == taxes_array[i]){
        taxes_choice->SetSelection(i);
             break;
             }

        }

}

void restaurant_posFrame::Onchange_buttonClick(wxCommandEvent& event)
{
        compras->DeleteItem(item_to_change);
        all_items.RemoveAt(item_to_change,1);
        add_additional_item();
}

void restaurant_posFrame::Onclear_buttonClick(wxCommandEvent& event)
{
    add_additional_clear();
}

void restaurant_posFrame::OnMenuItem4Selected1(wxCommandEvent& event)
{
    display_settings *display_dlg = new display_settings(this);
    display_dlg->conn_display = conn;
    display_dlg->fill_all();
    display_dlg->ShowModal();

refresh_waiters();
refresh_menus();
}

void restaurant_posFrame::OnMenuItem7Selected(wxCommandEvent& event)
{
    stats_today* today_dlg = new stats_today(this);
    today_dlg->conn_stat = conn;
    today_dlg->fill_all();
    today_dlg->Show();
}

void restaurant_posFrame::OnMenuStatisticsSelected(wxCommandEvent& event)
{
    product_stats* stats_dlg = new product_stats(this);
    stats_dlg->conn = conn;
    stats_dlg->fill_all();
    stats_dlg->Show();
}



void restaurant_posFrame::OnButton9Click(wxCommandEvent& event)
{
        if(all_items.GetCount()!=0){ //this means we have some item to send - order is not empty ;)
    if(pending_listbox -> GetSelection() == wxNOT_FOUND){ //this means those items are not saved
save_order();
    }

           int ind;
               if(pending_listbox -> GetSelection() != wxNOT_FOUND){
           ind = pending_items[pending_listbox->GetSelection()];
               }else{
           ind = pending_items[pending_listbox->GetCount()-1];
                    }
        mysqlpp::Query query = conn->query(); //status '3' means order needed to be prepared in kitchen
        query << "UPDATE `orders` SET `status` = '3' WHERE `id` = "<< ind <<" LIMIT 1";
        query.execute();
//sending message to the kitchen that we hawe new order:
//if (Socketserver1->IsConnected()){
sendMessage(_T("n:"));
//}

        clear_order();
        add_additional_clear();
}
}

void restaurant_posFrame::sendMessage(wxString toSend){
if (Socketserver1->IsConnected()){
    unsigned char c = 0xBE; //start to send message to the kitchen
    sockAccepted->Write(&c, 1);
    sockAccepted->SetFlags(wxSOCKET_WAITALL);
    const wxChar *buf;
    unsigned char len;
    buf = toSend.c_str();
    len  = (unsigned char)((wxStrlen(buf) + 1) * sizeof(wxChar));
    sockAccepted->Write(&len, 1);
    sockAccepted->Write(buf, len);
}
    }

void restaurant_posFrame::OnButton6Click(wxCommandEvent& event)
{
    wxString message = TextCtrl5 -> GetValue();
    if (Socketserver1->IsConnected()){
    TextCtrl5 -> Clear();
    sendMessage(_T("m:") + message);
    TextCtrl4 -> AppendText(message + _T("\n"));
    }else{
    wxMessageBox(_T("Kitchen computer is not connected!\n Message was not sent."));
        }
}

void restaurant_posFrame::OnButton10Click(wxCommandEvent& event)
{
           if(all_items.GetCount()!=0){ //this means we have some item to send - order is not empty ;)
    if(pending_listbox -> GetSelection() == wxNOT_FOUND){ //this means those items are not saved
save_order();
    }

           int ind;
               if(pending_listbox -> GetSelection() != wxNOT_FOUND){
           ind = pending_items[pending_listbox->GetSelection()];
               }else{
           ind = pending_items[pending_listbox->GetCount()-1];
                    }

        if(printTicket(formatTicket(ind, conn), set_now.ticket_command, set_now.custom_ticket ) == 1)
        {
        mysqlpp::Query query = conn->query(); //status '5' means order has been printed
        query << "UPDATE `orders` SET `status` = '5' WHERE `id` = "<< ind <<" LIMIT 1";
        query.execute();
        }


        clear_order();
        add_additional_clear();
}
}
