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
#ifndef RESTAURANT_POSMAIN_H
#define RESTAURANT_POSMAIN_H

//(*Headers(restaurant_posFrame)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/listbox.h>
//*)

#include <string>
#include <mysql++.h>
#include <iostream>
#include <wx/config.h>

#include <wx/dynarray.h>
#include "add_item.h"
#include "settings.h"
#include "payment.h"
#include "waiter_choose.h"
#include "display_settings.h"
#include <wx/filedlg.h>
#include "stats_today.h"
#include "perif.h"
#include <wx/socket.h>
#include "about.h"



class pending_order
{
public:

    int id;
    int number;
    int status;
};
WX_DECLARE_OBJARRAY(pending_order, pending_ordersArray);

std::string get_time(void);



class restaurant_posFrame: public wxFrame
{
public:

    restaurant_posFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~restaurant_posFrame();
    wxConfigBase *config;
    int connect_to_db(void);
    int proverko;
private:

    //(*Handlers(restaurant_posFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnMenuItem3Selected(wxCommandEvent& event);
    void OnMenuItem4Selected(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void OnMenuItem5Selected(wxCommandEvent& event);
    void OnButton3Click(wxCommandEvent& event);
    void OncomprasItemSelect(wxListEvent& event);
    void OncomprasInsertItem(wxListEvent& event);
    void OncomprasItemDeselect(wxListEvent& event);
    void OnMenuItem6Selected(wxCommandEvent& event);
    void OnMenu5Selected(wxCommandEvent& event);
    void OnMenu7Selected(wxCommandEvent& event);
    void OnMenu8Selected(wxCommandEvent& event);
    void OnMenu6Selected(wxCommandEvent& event);
    void Onpending_listboxSelect(wxCommandEvent& event);
    void OnButton4Click(wxCommandEvent& event);
    void OnButton5Click(wxCommandEvent& event);
    void OnButton7Click(wxCommandEvent& event);
    void OnTextCtrl2Text(wxCommandEvent& event);
    void OnTextCtrl2TextEnter(wxCommandEvent& event);
    void OnButton8Click(wxCommandEvent& event);
    void OnTextCtrl4Text(wxCommandEvent& event);
    void OncomprasBeginDrag(wxListEvent& event);
    void Onchange_buttonClick(wxCommandEvent& event);
    void Onclear_buttonClick(wxCommandEvent& event);
    void OnMenuItem4Selected1(wxCommandEvent& event);
    void OnMenuItem7Selected(wxCommandEvent& event);
    void OnMenuStatisticsSelected(wxCommandEvent& event);
    void OnButton9Click(wxCommandEvent& event);
    void OnButton6Click(wxCommandEvent& event);
    void OnButton10Click(wxCommandEvent& event);
    //*)

    //(*Identifiers(restaurant_posFrame)
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT9;
    static const long ID_CHOICE2;
    static const long ID_TEXTCTRL4;
    static const long ID_LISTCTRL1;
    static const long ID_BUTTON5;
    static const long ID_BUTTON2;
    static const long ID_BUTTON11;
    static const long ID_BUTTON12;
    static const long ID_BUTTON4;
    static const long ID_BUTTON1;
    static const long ID_BUTTON3;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT6;
    static const long ID_SPINCTRL1;
    static const long ID_TEXTCTRL1;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON8;
    static const long ID_CHECKBOX2;
    static const long ID_CHOICE1;
    static const long ID_BUTTON9;
    static const long ID_STATICTEXT8;
    static const long ID_TEXTCTRL3;
    static const long ID_BUTTON10;
    static const long ID_CHECKBOX1;
    static const long ID_LISTBOX1;
    static const long ID_BUTTON7;
    static const long ID_TEXTCTRL5;
    static const long ID_TEXTCTRL6;
    static const long ID_BUTTON6;
    static const long ID_MENUITEM6;
    static const long ID_MENUITEM7;
    static const long ID_MENUITEM8;
    static const long idMenuQuit;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM3;
    static const long ID_MENUITEM4;
    static const long ID_MENUITEM9;
    static const long ID_MENUITEM10;
    static const long ID_MENUITEM5;
    static const long ID_MENUITEM2;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    //*)
    static const long SERVER_ID;
    static const long SOCKET_ID;
    //(*Declarations(restaurant_posFrame)
    wxButton* change_button;
    wxTextCtrl* TextCtrl3;
    wxStaticText* StaticTotal;
    wxStatusBar* StatusBar1;
    wxChoice* taxes_choice;
    wxStaticText* StaticToPayV;
    wxMenuItem* Menu6;
    wxMenu* Menu3;
    wxMenuItem* Menu8;
    wxStaticText* StaticTaxesV;
    wxButton* Button4;
    wxMenuItem* Menu5;
    wxButton* Button1;
    wxButton* clear_button;
    wxCheckBox* CheckBox1;
    wxButton* Button2;
    wxTextCtrl* order_comment;
    wxMenu* Menu9;
    wxCheckBox* kitchen_checkbox;
    wxButton* Button3;
    wxTextCtrl* TextCtrl5;
    wxButton* Button8;
    wxStaticText* StaticText3;
    wxStaticText* StaticTaxes;
    wxMenuItem* MenuItem3;
    wxButton* Button5;
    wxMenu* Menu4;
    wxButton* Button9;
    wxListBox* pending_listbox;
    wxMenuItem* Menu7;
    wxMenuItem* MenuItem5;
    wxTextCtrl* TextCtrl1;
    wxListCtrl* compras;
    wxStaticText* StaticText4;
    wxStaticText* StaticText2;
    wxStaticText* StaticTotalV;
    wxChoice* waiter_choice;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem6;
    wxSpinCtrl* SpinCtrl1;
    wxStaticText* StaticToPay;
    wxButton* Button7;
    wxTextCtrl* TextCtrl4;
    wxTextCtrl* TextCtrl2;
    wxMenuItem* MenuItem8;
    wxButton* Button6;
    wxButton* Button10;
    //*)
    wxString vers;
    mysqlpp::Connection * conn;

    wxString host;
    wxString user;
    wxString pass;
    wxString dbase;
    bool dbase_connected;
    wxSocketServer *Socketserver1;
    wxSocketBase* sockAccepted;
    wxFont* font_listctrl;
//     wxHtmlEasyPrinting* printing;
//     wxPrintDialog* printdialog;
    wxPrintDialogData* printdialogdata;
    wxPrintData* printdata;

    double order_total;
    current_settings set_now;
    wxArrayInt menus_show;
    wxArrayInt workers_ids;
    int selected_worker;
    itemsArray all_items;
    wxArrayInt taxes_array;
    pending_ordersArray pendingOrders;
    int item_to_change;
    wxLocale Locale;
    void total(void);
    void save_order(void);
    void fill_pending(void);
    void add_additional_item(void);
    void add_to_listctrl(int qty, wxString name, double tax, int tax_id, double price, wxString comment, bool kitchen);
    void refresh_taxes(void);
    void refresh_waiters(void);
    void refresh_menus(void);
    void refresh_kitchen(void);
    void add_additional_clear(void);
    void clear_order();
    bool startServer(void);
    void OnServerEvent(wxSocketEvent& event);
    void OnSocketEvent(wxSocketEvent& event);
    void readFromKitchen(wxSocketBase *sock);
    void readSet(void);
    void sendMessage(wxString);
    void mark_ready(int);
    bool server_started;
    DECLARE_EVENT_TABLE()
};


#endif // RESTAURANT_POSMAIN_H
