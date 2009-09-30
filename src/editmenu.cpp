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
#include "editmenu.h"
#include "wx_std.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(editmenu)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ArrayOfPartes);

//(*IdInit(editmenu)
const long editmenu::ID_STATICTEXT1 = wxNewId();
const long editmenu::ID_LISTBOX5 = wxNewId();
const long editmenu::ID_TEXTCTRL6 = wxNewId();
const long editmenu::ID_CHECKBOX1 = wxNewId();
const long editmenu::ID_BUTTON12 = wxNewId();
const long editmenu::ID_BUTTON16 = wxNewId();
const long editmenu::ID_BUTTON17 = wxNewId();
const long editmenu::ID_STATICTEXT7 = wxNewId();
const long editmenu::ID_CHOICE1 = wxNewId();
const long editmenu::ID_BUTTON19 = wxNewId();
const long editmenu::ID_CHOICE3 = wxNewId();
const long editmenu::ID_TEXTCTRL5 = wxNewId();
const long editmenu::ID_CHECKBOX2 = wxNewId();
const long editmenu::ID_BUTTON13 = wxNewId();
const long editmenu::ID_BUTTON14 = wxNewId();
const long editmenu::ID_BUTTON15 = wxNewId();
const long editmenu::ID_STATICTEXT2 = wxNewId();
const long editmenu::ID_LISTBOX1 = wxNewId();
const long editmenu::ID_STATICTEXT5 = wxNewId();
const long editmenu::ID_LISTBOX2 = wxNewId();
const long editmenu::ID_BUTTON1 = wxNewId();
const long editmenu::ID_STATICTEXT4 = wxNewId();
const long editmenu::ID_TEXTCTRL2 = wxNewId();
const long editmenu::ID_STATICTEXT3 = wxNewId();
const long editmenu::ID_TEXTCTRL1 = wxNewId();
const long editmenu::ID_BUTTON5 = wxNewId();
const long editmenu::ID_BUTTON2 = wxNewId();
const long editmenu::ID_BUTTON3 = wxNewId();
const long editmenu::ID_LISTBOX4 = wxNewId();
const long editmenu::ID_TEXTCTRL4 = wxNewId();
const long editmenu::ID_BUTTON10 = wxNewId();
const long editmenu::ID_BUTTON11 = wxNewId();
const long editmenu::ID_BUTTON9 = wxNewId();
const long editmenu::ID_LISTBOX3 = wxNewId();
const long editmenu::ID_CHOICE2 = wxNewId();
const long editmenu::ID_TEXTCTRL3 = wxNewId();
const long editmenu::ID_STATICTEXT6 = wxNewId();
const long editmenu::ID_TEXTCTRL7 = wxNewId();
const long editmenu::ID_BUTTON6 = wxNewId();
const long editmenu::ID_BUTTON8 = wxNewId();
const long editmenu::ID_BUTTON7 = wxNewId();
const long editmenu::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(editmenu,wxDialog)
    //(*EventTable(editmenu)
    //*)
END_EVENT_TABLE()

editmenu::editmenu(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(editmenu)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer21;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer15;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxFlexGridSizer* FlexGridSizer17;
    wxFlexGridSizer* FlexGridSizer19;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer9;
    wxFlexGridSizer* FlexGridSizer14;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxFlexGridSizer* FlexGridSizer16;
    wxFlexGridSizer* FlexGridSizer10;
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer13;
    wxFlexGridSizer* FlexGridSizer18;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer20;

    Create(parent, wxID_ANY, _("Edit restaurant menu"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Menu editing"));
    FlexGridSizer2 = new wxFlexGridSizer(5, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Choose menu to edit:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Menus"));
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    menu_listbox = new wxListBox(this, ID_LISTBOX5, wxDefaultPosition, wxSize(140,170), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX5"));
    FlexGridSizer3->Add(menu_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(4, 1, 0, 0);
    menu_textctrl = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(152,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer4->Add(menu_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    kitchen_by_default = new wxCheckBox(this, ID_CHECKBOX1, _("Kitchen by default"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    kitchen_by_default->SetValue(true);
    FlexGridSizer4->Add(kitchen_by_default, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    add_menu_button = new wxButton(this, ID_BUTTON12, _("Add"), wxDefaultPosition, wxSize(48,28), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    FlexGridSizer5->Add(add_menu_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rename_menu_button = new wxButton(this, ID_BUTTON16, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON16"));
    FlexGridSizer5->Add(rename_menu_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    delete_menu_button = new wxButton(this, ID_BUTTON17, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    FlexGridSizer4->Add(delete_menu_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Taxes"));
    FlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT7, _("Tax group:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer6->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    taxes_choice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(140,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer6->Add(taxes_choice, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON19, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON19"));
    FlexGridSizer6->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(StaticBoxSizer4, 1, wxBOTTOM|wxLEFT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    StaticBoxSizer3->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer8 = new wxFlexGridSizer(5, 0, 0, 0);
    menu_choice = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxSize(140,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    FlexGridSizer8->Add(menu_choice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    menu_in_textctrl = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(140,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer8->Add(menu_in_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    dish_kitchen = new wxCheckBox(this, ID_CHECKBOX2, _("Kitchen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    dish_kitchen->SetValue(false);
    FlexGridSizer8->Add(dish_kitchen, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer11 = new wxFlexGridSizer(0, 2, 0, 0);
    add_in_menu_button = new wxButton(this, ID_BUTTON13, _("Add"), wxDefaultPosition, wxSize(48,28), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    FlexGridSizer11->Add(add_in_menu_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rename_in_menu_button = new wxButton(this, ID_BUTTON14, _("Change"), wxDefaultPosition, wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    FlexGridSizer11->Add(rename_in_menu_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(FlexGridSizer11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    delete_in_menu_button = new wxButton(this, ID_BUTTON15, _("Delete"), wxDefaultPosition, wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    FlexGridSizer8->Add(delete_in_menu_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7->Add(FlexGridSizer8, 1, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer9 = new wxFlexGridSizer(3, 0, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("This menu contains:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer9->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    menu_in_listbox = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(140,250), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer9->Add(menu_in_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7->Add(FlexGridSizer9, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer10 = new wxFlexGridSizer(7, 0, 0, 0);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Parts:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer10->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    parts_listbox = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(230,144), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    FlexGridSizer10->Add(parts_listbox, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    delete_part_button = new wxButton(this, ID_BUTTON1, _("Delete"), wxDefaultPosition, wxSize(72,28), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    delete_part_button->Disable();
    FlexGridSizer10->Add(delete_part_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer12 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Base price:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer12->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    price_textctrl = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(57,26), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer12->Add(price_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(FlexGridSizer12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    comment_static_text = new wxStaticText(this, ID_STATICTEXT3, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer10->Add(comment_static_text, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    comment_textctrl = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(180,56), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer10->Add(comment_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    save_part_button = new wxButton(this, ID_BUTTON5, _("Save"), wxDefaultPosition, wxSize(80,28), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    save_part_button->Disable();
    FlexGridSizer10->Add(save_part_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7->Add(FlexGridSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    move_button = new wxButton(this, ID_BUTTON2, _("<--"), wxPoint(528,192), wxSize(56,28), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    move_button->Disable();
    BoxSizer1->Add(move_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    or_button = new wxButton(this, ID_BUTTON3, _("OR"), wxPoint(528,224), wxSize(56,28), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    or_button->Disable();
    BoxSizer1->Add(or_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer13 = new wxFlexGridSizer(3, 0, 0, 0);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Ingridients"));
    FlexGridSizer14 = new wxFlexGridSizer(2, 1, 0, 0);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Groups"));
    FlexGridSizer15 = new wxFlexGridSizer(0, 2, 0, 0);
    group_listbox = new wxListBox(this, ID_LISTBOX4, wxDefaultPosition, wxSize(140,200), 0, 0, wxLB_SINGLE|wxLB_EXTENDED, wxDefaultValidator, _T("ID_LISTBOX4"));
    FlexGridSizer15->Add(group_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer16 = new wxFlexGridSizer(3, 0, 0, 0);
    groups_textctrl = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(152,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer16->Add(groups_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer17 = new wxFlexGridSizer(1, 2, 0, 0);
    add_group_button = new wxButton(this, ID_BUTTON10, _("Add"), wxDefaultPosition, wxSize(48,28), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    FlexGridSizer17->Add(add_group_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rename_group_button = new wxButton(this, ID_BUTTON11, _("Rename"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    FlexGridSizer17->Add(rename_group_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer16->Add(FlexGridSizer17, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    delete_group_button = new wxButton(this, ID_BUTTON9, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    FlexGridSizer16->Add(delete_group_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer15->Add(FlexGridSizer16, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    StaticBoxSizer5->Add(FlexGridSizer15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer14->Add(StaticBoxSizer5, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer18 = new wxFlexGridSizer(0, 2, 0, 0);
    ing_listbox = new wxListBox(this, ID_LISTBOX3, wxDefaultPosition, wxSize(140,296), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX3"));
    FlexGridSizer18->Add(ing_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19 = new wxFlexGridSizer(5, 0, 0, 0);
    group_choice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(152,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer19->Add(group_choice, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    ing_textctrl = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(152,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer19->Add(ing_textctrl, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer20 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT6, _("Price change:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer20->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    price_change_textctrl = new wxTextCtrl(this, ID_TEXTCTRL7, _("0"), wxDefaultPosition, wxSize(40,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    FlexGridSizer20->Add(price_change_textctrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19->Add(FlexGridSizer20, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer21 = new wxFlexGridSizer(0, 2, 0, 0);
    add_ing_button = new wxButton(this, ID_BUTTON6, _("Add"), wxDefaultPosition, wxSize(64,28), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer21->Add(add_ing_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rename_ing_button = new wxButton(this, ID_BUTTON8, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    FlexGridSizer21->Add(rename_ing_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer19->Add(FlexGridSizer21, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 0);
    delete_ing_button = new wxButton(this, ID_BUTTON7, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    FlexGridSizer19->Add(delete_ing_button, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer18->Add(FlexGridSizer19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer14->Add(FlexGridSizer18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(FlexGridSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer13->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer13->Add(20,45,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON4, _("Close"), wxPoint(872,544), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer13->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    FlexGridSizer1->Add(FlexGridSizer13, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX5,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&editmenu::Onmenu_listboxSelect);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onadd_menu_buttonClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onrename_menu_buttonClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Ondelete_menu_buttonClick);
    Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::OnButton2Click);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onadd_in_menu_buttonClick);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onrename_in_menu_buttonClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Ondelete_in_menu_buttonClick);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&editmenu::Onmenu_in_listboxSelect);
    Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&editmenu::Onparts_listboxSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Ondelete_part_buttonClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onsave_part_buttonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onmove_buttonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onor_buttonClick);
    Connect(ID_LISTBOX4,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&editmenu::Ongroup_listboxSelect);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onadd_group_buttonClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onrename_group_buttonClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Ondelete_group_buttonClick);
    Connect(ID_LISTBOX3,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&editmenu::Oning_listboxSelect);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onadd_ing_buttonClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Onrename_ing_buttonClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::Ondelete_ing_buttonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editmenu::OnButton1Click);
    //*)


}

editmenu::~editmenu()
{
    //(*Destroy(editmenu)
    //*)
}




void editmenu::Ongroup_listboxSelect(wxCommandEvent& event)
{
    groups_textctrl->Clear();
    wxArrayInt selections;
    int selected = group_listbox->GetSelections(selections);

    if (selected==1)
    {
        groups_textctrl->AppendText(group_listbox->GetString(selections[0]));
        group_choice->SetSelection(selections[0]);
    }
    else
    {
        group_choice->SetSelection(0);
    }

    refresh_ingridient();

    move_button -> Disable();
    or_button -> Disable();
}

void editmenu::Onadd_group_buttonClick(wxCommandEvent& event)
{
    if (!groups_textctrl->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<group_listbox->GetCount(); i++)
        {
            if (groups_textctrl->GetValue() == group_listbox->GetString(i))
            {
                wxMessageBox(_("This group is already exists."));
                exist = 1;
                i=group_listbox->GetCount();
            }
        }
        if (exist == 0)
        {

            mysqlpp::Query query = conn_edit -> query();
            query << "INSERT INTO `groups` (`id`, `name`) VALUES (NULL, '" << wx2std(groups_textctrl->GetValue(), wxConvUI) << "')";
            query.execute();

            refresh_group();
            groups_textctrl->Clear();
        }


    }
}

void editmenu::Onrename_group_buttonClick(wxCommandEvent& event)
{
    wxArrayInt temp;
    if(group_listbox->GetSelections(temp) != 0)
    {

        if (!groups_textctrl->IsEmpty())
        {

            wxArrayInt selections;
            group_listbox->GetSelections(selections);

            mysqlpp::Query query = conn_edit -> query();
            query << "UPDATE `groups` SET `name` = '" << wx2std(groups_textctrl->GetValue(), wxConvUI) << "' WHERE `groups`.`name` ='"<< wx2std(group_listbox->GetString(selections[0]), wxConvUI) <<"' LIMIT 1";
            query.execute();

            refresh_group();
            groups_textctrl->Clear();
        }
    }
}

void editmenu::Ondelete_group_buttonClick(wxCommandEvent& event)
{
    wxArrayInt selections;
    int selected_num = group_listbox->GetSelections(selections);
    while (selected_num > 0)
    {
        int group_id = group_array[selections[--selected_num]];
        mysqlpp::Query query = conn_edit -> query();
        query << "DELETE FROM `groups` WHERE `id` = '"<<  group_id <<"'";
        query.execute();

        query << "SELECT `id` FROM `parts` WHERE `group_id` = '" << group_id << "'";
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
                    int part_id = int(row["id"]);
                    query << "DELETE FROM `dishes_parts` WHERE `parts_id` = '"<<  part_id <<"'";
                    query.execute();
                    query << "DELETE FROM `dishes_parts_ors` WHERE `parts_id` = '"<<  part_id <<"'";
                    query.execute();
                }
            }
        }
        query << "DELETE FROM `parts` WHERE `group_id` = '"<<  group_id <<"'";
        query.execute();
    }

    refresh_group();
    refresh_ingridient();
}

void editmenu::refresh_group(void)
{

    group_listbox->Clear();
    group_choice->Clear();
    group_array.Clear();

    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `groups`";
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
                std::string group_name = std::string(row["name"]);
                group_listbox->Append(std2wx(group_name, wxConvUI));
                group_choice->Append(std2wx(group_name, wxConvUI));
                group_array.Add(int(row["id"]));

            }
        }
    }

    //        }
    group_choice->SetSelection(0);
}

void editmenu::Onadd_ing_buttonClick(wxCommandEvent& event)
{
    if (!ing_textctrl->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<ing_listbox->GetCount(); i++)
        {
            if (ing_textctrl->GetValue() == ing_listbox->GetString(i))
            {
                wxMessageBox(_("This ingridient already exists."));
                exist = 1;
                i=ing_listbox->GetCount();
            }
        }
        if (exist == 0)
        {

            mysqlpp::Query query = conn_edit -> query();
            query << "INSERT INTO `parts` (`id`, `name`, `group_id`,`price_change`) VALUES (NULL, '"<< wx2std(ing_textctrl->GetValue(), wxConvUI) <<"', '"<< group_array[group_choice->GetSelection()] <<"', '"<< wx2std(price_change_textctrl->GetValue(), wxConvUI) <<"')";
            query.execute();

            refresh_ingridient();
            ing_textctrl->Clear();
        }


    }


}

void editmenu::refresh_ingridient(void)
{

    wxArrayInt selections;
    int selected = group_listbox->GetSelections(selections);


    ing_listbox->Clear();
    ing_array.Clear();
    ing_gr_array.Clear();

    while (selected > 0)
    {
        mysqlpp::Query query = conn_edit->query();
        query << "SELECT * FROM `parts` WHERE `group_id`=" << group_array[selections[--selected]];
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
                    std::string ing_name = std::string(row["name"]);
                    ing_listbox->Append(std2wx(ing_name, wxConvUI));
                    ing_array.Add(int(row["id"]));
                    ing_gr_array.Add(int(row["group_id"]));
                }
            }
        }

    }
    ing_textctrl->Clear();
    price_change_textctrl->Clear();
//    group_choice->SetSelection(0);
}

void editmenu::Oning_listboxSelect(wxCommandEvent& event)
{
    if(ing_listbox->GetSelection() != wxNOT_FOUND)
    {
        ing_textctrl->Clear();
        ing_textctrl->AppendText(ing_listbox->GetStringSelection());


        int i=0;
        for(i; i< group_array.GetCount(); i++)
        {
            if(ing_gr_array[ing_listbox->GetSelection()] == group_array[i]) break;
        }

//    int i = 0;
//    while (group_array[i] != ing_gr_array[ing_listbox->GetSelection()])
//        i++;


        group_choice->SetSelection(i);

        mysqlpp::Query query = conn_edit->query();
        query << "SELECT * FROM `parts` WHERE `id`=" << ing_array[ing_listbox -> GetSelection()];
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            if (res.num_rows() != 0)
            {
                mysqlpp::Row row = res.at(0);
                price_change_textctrl -> Clear();
                price_change_textctrl -> AppendText(std2wx(std::string(row["price_change"]),wxConvUI));
            }
        }









        if(parts_listbox->GetSelection() != wxNOT_FOUND)
        {
            or_button -> Enable();
        }
        if(menu_in_listbox->GetSelection() != wxNOT_FOUND)
        {
            move_button -> Enable();
        }

    }
}

void editmenu::Ondelete_ing_buttonClick(wxCommandEvent& event)
{
    if(ing_listbox->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_edit -> query();
        int part_id = ing_array[ing_listbox->GetSelection()];
        query << "DELETE FROM `parts` WHERE `parts`.`id` = " << part_id;
        query.execute();
        query << "DELETE FROM `dishes_parts` WHERE `parts_id` = '"<<  part_id <<"'";
        query.execute();
        query << "DELETE FROM `dishes_parts_ors` WHERE `parts_id` = '"<<  part_id <<"'";
        query.execute();


        refresh_ingridient();
    }
}

void editmenu::Onrename_ing_buttonClick(wxCommandEvent& event)
{

    if(ing_listbox->GetSelection() != wxNOT_FOUND)
    {
        if (!ing_textctrl->IsEmpty())
        {

            mysqlpp::Query query = conn_edit -> query();
            query << "UPDATE `parts` SET `price_change` = '"<< wx2std(price_change_textctrl->GetValue(), wxConvUI) <<"', `name` = '"<<wx2std(ing_textctrl->GetValue(), wxConvUI)<<"', `group_id` = '"<<group_array[group_choice->GetSelection()]<<"' WHERE `parts`.`id` = "<< ing_array[ing_listbox->GetSelection()] <<" LIMIT 1;";
            query.execute();


            refresh_ingridient();
            ing_textctrl->Clear();
        }
    }

}

void editmenu::refresh_menu(void)
{

    menu_listbox->Clear();
    menu_choice->Clear();
    menu_array.Clear();
    taxes_menu_ids.Clear();
    kitchens.Clear();

    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `menus`";
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
                std::string menu_name = std::string(row["name"]);
                wxString menu_nm = std2wx(menu_name, wxConvUI);
                menu_listbox->Append(menu_nm);
                menu_choice->Append(menu_nm);
                menu_array.Add(int(row["id"]));
                taxes_menu_ids.Add(int(row["tax_id"]));
                kitchens.Add(int(row["kitchen"]));
            }
        }
    }
    menu_choice->SetSelection(0);
    taxes_choice->SetSelection(0);
    kitchen_by_default->SetValue(true);
    dish_kitchen->SetValue(true);
}

void editmenu::fill_all(void)
{
    refresh_group();
    refresh_menu();
    refresh_taxes();
}



void editmenu::Onrename_in_menu_buttonClick(wxCommandEvent& event)
{
    if(menu_in_listbox->GetSelection() != wxNOT_FOUND)
    {

        if (!menu_in_textctrl->IsEmpty())
        {
            int kitchen = 1;
            if(!dish_kitchen->GetValue()) kitchen = 0;

            mysqlpp::Query query = conn_edit -> query();
            query << "UPDATE `dishes` SET `menu_id` = "<< menu_array[menu_choice->GetSelection()] <<" ,`name` = '" << wx2std(menu_in_textctrl->GetValue(), wxConvUI) << "', `kitchen` = '"<< kitchen <<"' WHERE `dishes`.`name` ='"<< wx2std(menu_in_listbox->GetStringSelection(), wxConvUI) <<"' LIMIT 1";
            query.execute();

            refresh_menu_in();
            menu_in_textctrl->Clear();
        }
    }
}

void editmenu::Onmenu_listboxSelect(wxCommandEvent& event)
{
    menu_textctrl->Clear();
    menu_textctrl->AppendText(menu_listbox->GetStringSelection());

    for(int i=0; i< taxes_array.GetCount(); i++)
    {
        if(taxes_menu_ids[menu_listbox->GetSelection()] == taxes_array[i])
        {
            taxes_choice -> SetSelection(i);
            break;
        }
    }


    menu_choice -> SetSelection(menu_listbox->GetSelection());

    if(kitchens[menu_listbox->GetSelection()]==1)
    {
        kitchen_by_default->SetValue(true);
        dish_kitchen->SetValue(true);
    }
    else
    {
        kitchen_by_default->SetValue(false);
        dish_kitchen->SetValue(false);
    }

//    int i = 0;
//    while (taxes_array[i] != taxes_menu_ids[menu_listbox->GetSelection()])
//        i++;


//   group_choice->SetSelection(i);

    move_button -> Disable();
    or_button -> Disable();
    save_part_button -> Disable();
    delete_part_button -> Disable();
    refresh_menu_in();
}

void editmenu::Onadd_menu_buttonClick(wxCommandEvent& event)
{

    if (!menu_textctrl->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<menu_listbox->GetCount(); i++)
        {
            if (menu_textctrl->GetValue() == menu_listbox->GetString(i))
            {
                wxMessageBox(_("This menu already exists."));
                exist = 1;
                i=menu_listbox->GetCount();
            }
        }
        if (exist == 0)
        {
            if(taxes_array.GetCount() != 0)  //checking for taxes
            {
                int kitchen = 1;
                if(!kitchen_by_default->GetValue()) kitchen = 0;

                mysqlpp::Query query = conn_edit -> query();
                query << "INSERT INTO `menus` (`id`, `name`, `tax_id`, `kitchen`) VALUES (NULL, '" << wx2std(menu_textctrl->GetValue(), wxConvUI) << "', '"<< taxes_array[taxes_choice->GetSelection()] <<"', '"<< kitchen <<"')";
                query.execute();

                refresh_menu();
                menu_textctrl->Clear();
            }
            else
            {
                wxMessageBox(_("Please create tax group first!"));
            }
        }


    }

}

void editmenu::Ondelete_menu_buttonClick(wxCommandEvent& event)
{
    if(menu_listbox->GetSelection() != wxNOT_FOUND)
    {

        int menu_id = menu_array[menu_listbox->GetSelection()];
        mysqlpp::Query query = conn_edit -> query();
        query << "DELETE FROM `menus` WHERE `menus`.`id` = " << menu_id;
        query.execute();

        query << "SELECT `id` FROM `dishes` WHERE `menu_id`=" << menu_id;
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
                    delete_parts_from_dish(int(row["id"]));
                }
            }
        }
        query << "DELETE FROM `dishes` WHERE `menu_id` = " << menu_id;
        query.execute();

        refresh_menu();
        //refresh_menu_in();
    }
}

void editmenu::delete_parts_from_dish(int dish_id)
{

    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `dishes_parts` WHERE `dishes_id`=" << dish_id;
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
                if(int(row["parts_id"]) == 0)
                    query << "DELETE FROM `dishes_parts_ors` WHERE `dishes_parts_id` = " << int(row["id"]);
                query.execute();
            }
        }
    }
    query << "DELETE FROM `dishes_parts` WHERE `dishes_id` = " << dish_id;
    query.execute();

}

void editmenu::Onrename_menu_buttonClick(wxCommandEvent& event)
{
    if (!menu_textctrl->IsEmpty())
    {
        int kitchen = 1;
        if(!kitchen_by_default->GetValue()) kitchen = 0;
        mysqlpp::Query query = conn_edit -> query();
        query << "UPDATE `menus` SET `name` = '"<<wx2std(menu_textctrl->GetValue(), wxConvUI)<<"' , `tax_id` = " << taxes_array[taxes_choice -> GetSelection()] << ", `kitchen` = '"<< kitchen <<"' WHERE `menus`.`id` = "<< menu_array[menu_listbox->GetSelection()] <<" LIMIT 1;";
        query.execute();


        refresh_menu();
        menu_textctrl->Clear();
        taxes_choice -> SetSelection(0);
    }


}

void editmenu::refresh_menu_in(void)
{

//         wxMessageBox(_("preved!"));
    menu_in_textctrl->Clear();
    parts_listbox->Clear();
    price_textctrl->Clear();

    menu_in_listbox->Clear();

    menu_in_array.Clear();



    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `dishes` WHERE `menu_id`=" << menu_array[menu_listbox->GetSelection()];
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
                std::string dish_name = std::string(row["name"]);
                menu_in_listbox->Append(std2wx(dish_name, wxConvUI));
                menu_in_array.Add(int(row["id"]));
            }
        }
    }
    if(kitchens[menu_listbox->GetSelection()])
    {
        dish_kitchen->SetValue(true);
    }
    else
    {
        dish_kitchen->SetValue(false);
    }

}

void editmenu::fill_parts(int dish_id)
{

    parts_listbox->Clear();
    partes_array.Clear();

    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `dishes_parts` WHERE `dishes_id`=" << dish_id;
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
                int part_id = int(row["parts_id"]);

                partes parts;
                parts.dishes_parts_id = int(row["id"]);
                parts.parts_id = part_id;
                partes_array.Add(parts);

                if(part_id == 0) //dobavliem ors
                {
                    query << "SELECT * FROM `dishes_parts_ors` WHERE `dishes_parts_id`=" << int(row["id"]);
                    mysqlpp::StoreQueryResult res_ors = query.store();
                    if(res_ors)
                    {
                        std::string slices;
                        int first = 0;
                        mysqlpp::Row::size_type j;
                        for (j = 0; j < res_ors.num_rows(); ++j)
                        {
                            row = res_ors[j];
                            std::string slice_or = get_part_name(int(row["parts_id"]));
                            if(first !=0)
                            {
                                slices += " OR " + slice_or;
                            }
                            else
                            {
                                slices = slice_or;
                                first = 1;
                            }
                        }
                        parts_listbox->Append(std2wx(slices, wxConvUI));
                    }
                }
                else
                {

                    parts_listbox->Append(std2wx(get_part_name(part_id), wxConvUI));

                }


            }
        }
    }

//in future will return focus to the listbox, so this will be unnecessary
    or_button -> Disable();
//move_button -> Disable();
    delete_part_button -> Disable();
}

void editmenu::Onadd_in_menu_buttonClick(wxCommandEvent& event)
{

    if (!menu_in_textctrl -> IsEmpty())
    {

        if(menu_listbox->GetSelection() != wxNOT_FOUND)
        {
            int exist=0;
            for (unsigned int i = 0; i<menu_in_listbox->GetCount(); i++)
            {
                if (menu_in_textctrl->GetValue() == menu_in_listbox->GetString(i))
                {
                    wxMessageBox(_("This name of dish already exists."));
                    exist = 1;
                    i=menu_in_listbox->GetCount();
                }
            }
            if (exist == 0)
            {
                int kitchen = 1;
                if(!dish_kitchen->GetValue()) kitchen = 0;

                mysqlpp::Query query = conn_edit -> query();
//            query << "INSERT INTO `post_rest`.`parts` (`id`, `name`, `group_id`) VALUES (NULL, '"<< wx2std(ing_textctrl->GetValue(), wxConvUI) <<"', '"<< group_array[group_choice->GetSelection()] <<"')";
                query << "INSERT INTO `dishes` (`id`, `name`, `price`, `menu_id`, `kitchen`) VALUES (NULL, '"<< wx2std(menu_in_textctrl->GetValue(), wxConvUI) <<"', '', '" <<  menu_array[menu_listbox->GetSelection()] << "', '"<< kitchen <<"')";
                query.execute();

                refresh_menu_in();
                menu_in_textctrl->Clear();
            }
        }
        else
        {
            wxMessageBox(_("You have to choose menu to which you want to add a dish."));
        }

    }


}

std::string editmenu::get_part_name(int part_id)
{

    std::string part_name;
    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `parts` WHERE `id`=" << part_id;
    mysqlpp::StoreQueryResult res = query.store();

    if (res)
    {
        if (res.num_rows() != 0)
        {
            mysqlpp::Row row = res.at(0);
            part_name = std::string(row["name"]);
        }
    }
    return part_name;

}

void editmenu::Onmenu_in_listboxSelect(wxCommandEvent& event)
{
    if(menu_in_listbox->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_edit->query();
        query << "SELECT * FROM `dishes` WHERE `id`=" << menu_in_array[menu_in_listbox->GetSelection()];
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            if (res.num_rows() != 0)
            {
                mysqlpp::Row row = res.at(0);
                fill_parts(menu_in_array[menu_in_listbox->GetSelection()]);
                price_textctrl->Clear();
                price_textctrl->AppendText(std2wx(std::string(row["price"]),wxConvUI));
                comment_textctrl->Clear();
                comment_textctrl->AppendText(std2wx(std::string(row["comment"]),wxConvUI));
                if(int(row["kitchen"]) == 1)
                {
                    dish_kitchen->SetValue(true);
                }
                else
                {
                    dish_kitchen->SetValue(false);
                }
            }
        }
        menu_in_textctrl->Clear();
        menu_in_textctrl->AppendText(menu_in_listbox->GetStringSelection());

        or_button -> Disable();
        delete_part_button -> Disable();
        save_part_button -> Enable();

        if(ing_listbox->GetSelection() != wxNOT_FOUND)
        {
            move_button -> Enable();
        }
    }
}

void editmenu::Onsave_part_buttonClick(wxCommandEvent& event)
{
    mysqlpp::Query query = conn_edit -> query();
    query << "UPDATE `dishes` SET `price` = '" << wx2std(price_textctrl->GetValue(), wxConvUI)<< "', `comment` = '" << wx2std(comment_textctrl->GetValue(), wxConvUI) << "' WHERE `dishes`.`id` = " << menu_in_array[menu_in_listbox->GetSelection()] << " LIMIT 1";
    query.execute();
}

void editmenu::Ondelete_in_menu_buttonClick(wxCommandEvent& event)
{
    if(menu_in_listbox->GetSelection() != wxNOT_FOUND)
    {
        int dish_id = menu_in_array[menu_in_listbox->GetSelection()];
        mysqlpp::Query query = conn_edit -> query();
        query << "DELETE FROM `dishes` WHERE `dishes`.`id` = " << dish_id;
        query.execute();
        delete_parts_from_dish(dish_id);
        refresh_menu_in();
    }
}

void editmenu::Onmove_buttonClick(wxCommandEvent& event)
{
    if(ing_listbox->GetSelection() != wxNOT_FOUND)
    {

        int part_id = ing_array[ing_listbox->GetSelection()];
        int dish_id = menu_in_array[menu_in_listbox->GetSelection()];

        mysqlpp::Query query = conn_edit -> query();
        query << "INSERT INTO `dishes_parts` (`id`, `dishes_id`, `parts_id`) VALUES (NULL, '"<< dish_id <<"', '"<< part_id <<"')";
        query.execute();

        fill_parts(dish_id);
    }
}

void editmenu::Onparts_listboxSelect(wxCommandEvent& event)
{
    if(ing_listbox->GetSelection() != wxNOT_FOUND)
    {
        or_button -> Enable();
    }

    delete_part_button -> Enable();


}

void editmenu::Onor_buttonClick(wxCommandEvent& event)
{
    if(ing_listbox->GetSelection() != wxNOT_FOUND && parts_listbox->GetSelection() != wxNOT_FOUND)
    {

        int part_id = ing_array[ing_listbox->GetSelection()];// novyj, kotoryj budem dobavliat
        int dish_id = menu_in_array[menu_in_listbox->GetSelection()]; // nomer bliuda
        int dishes_parts_id = partes_array[parts_listbox->GetSelection()].dishes_parts_id; //
        int part_old_id = partes_array[parts_listbox->GetSelection()].parts_id;


        mysqlpp::Query query = conn_edit->query();

        if(part_old_id != 0)  //here checking if this entry is already 0
        {
            query << "UPDATE `dishes_parts` SET `parts_id` = '0' WHERE `id` ="<< dishes_parts_id <<" LIMIT 1";
            query.execute();

            query << "INSERT INTO `dishes_parts_ors` (`id`, `dishes_parts_id`, `parts_id`) VALUES (NULL, '"<< dishes_parts_id <<"', '"<< part_old_id <<"')";
            query.execute();
        }

        query << "INSERT INTO `dishes_parts_ors` (`id`, `dishes_parts_id`, `parts_id`) VALUES (NULL, '"<< dishes_parts_id <<"', '"<< part_id <<"')";
        query.execute();

        fill_parts(dish_id);
    }
}

void editmenu::Ondelete_part_buttonClick(wxCommandEvent& event)
{
    if(parts_listbox->GetSelection() != wxNOT_FOUND)
    {
        int dishes_parts_id = partes_array[parts_listbox->GetSelection()].dishes_parts_id;
        int parts_id = partes_array[parts_listbox->GetSelection()].parts_id;
        mysqlpp::Query query = conn_edit -> query();

        query << "DELETE FROM `dishes_parts` WHERE `id` = " << dishes_parts_id;
        query.execute();
        if(parts_id ==0)
        {
            query << "DELETE FROM `dishes_parts_ors` WHERE `dishes_parts_id` = " << dishes_parts_id;
            query.execute();

        }

        //   partes_array.RemoveAt(parts_listbox->GetSelection(), 1);

        //  parts_listbox -> Delete (parts_listbox->GetSelection());
        int dish_id = menu_in_array[menu_in_listbox->GetSelection()]; // nomer bliuda
        fill_parts(dish_id);
    }
}

void editmenu::save_dish(void)
{
    //     if(menu_in_listbox->GetSelection() != wxNOT_FOUND){

    wxString parts_for_save;
    for (int i = 0; i < parts_array.GetCount(); i++)
    {
        parts_for_save += parts_array[i] + _(":");
    }

    mysqlpp::Query query = conn_edit -> query();
    query << "UPDATE `dishes` SET `parts` = '" << wx2std(parts_for_save, wxConvUI) << "' WHERE `dishes`.`id` = " << menu_in_array[menu_in_listbox->GetSelection()] << " LIMIT 1";
    query.execute();
//       }

}

void editmenu::On_lost_focus_price_textctrl(wxCommandEvent& event)
{
//Onsave_part_buttonClick();
}



void editmenu::refresh_taxes(void)
{
    taxes_choice -> Clear();
    taxes_array.Clear();
    mysqlpp::Query query = conn_edit->query();
    query << "SELECT * FROM `taxes`";
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
                std::string tax_name = std::string(row["name"]);
                taxes_choice->Append(std2wx(tax_name, wxConvUI));
                taxes_array.Add(int(row["id"]));
            }
        }
    }
    taxes_choice->SetSelection(0);

}

void editmenu::OnButton1Click(wxCommandEvent& event)
{
    Show(0);
}

void editmenu::OnButton2Click(wxCommandEvent& event)
{
    taxes* tax_dlg = new taxes(this);
    tax_dlg -> conn_taxes = conn_edit;
    tax_dlg -> fill_all();
    tax_dlg -> ShowModal();
    refresh_taxes();
}

