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
#ifndef EDITMENU_H
#define EDITMENU_H

//(*Headers(editmenu)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/listbox.h>
//*)
#include <mysql++.h>
#include <string>
#include <iostream>

#include <wx/dynarray.h>
#include "taxes.h"

struct partes
{
    int dishes_parts_id;
    int parts_id;
};
WX_DECLARE_OBJARRAY(partes, ArrayOfPartes);


class editmenu: public wxDialog
{
public:

    editmenu(wxWindow* parent,wxWindowID id=wxID_ANY);
    virtual ~editmenu();

    //(*Declarations(editmenu)
    wxButton* add_ing_button;
    wxCheckBox* dish_kitchen;
    wxStaticText* comment_static_text;
    wxCheckBox* kitchen_by_default;
    wxChoice* taxes_choice;
    wxButton* rename_ing_button;
    wxTextCtrl* menu_textctrl;
    wxTextCtrl* price_change_textctrl;
    wxButton* Button1;
    wxButton* delete_group_button;
    wxButton* Button2;
    wxListBox* menu_listbox;
    wxButton* or_button;
    wxButton* delete_in_menu_button;
    wxStaticText* StaticText1;
    wxListBox* group_listbox;
    wxButton* rename_group_button;
    wxStaticText* StaticText3;
    wxTextCtrl* price_textctrl;
    wxButton* delete_menu_button;
    wxChoice* menu_choice;
    wxButton* save_part_button;
    wxListBox* ing_listbox;
    wxButton* delete_ing_button;
    wxButton* move_button;
    wxButton* add_menu_button;
    wxTextCtrl* ing_textctrl;
    wxChoice* group_choice;
    wxButton* add_group_button;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText2;
    wxTextCtrl* menu_in_textctrl;
    wxStaticText* StaticText6;
    wxListBox* menu_in_listbox;
    wxTextCtrl* groups_textctrl;
    wxButton* rename_menu_button;
    wxButton* rename_in_menu_button;
    wxButton* delete_part_button;
    wxButton* add_in_menu_button;
    wxListBox* parts_listbox;
    wxTextCtrl* comment_textctrl;
    //*)
    mysqlpp::Connection * conn_edit;
    void fill_all(void);
    ArrayOfPartes partes_array;

protected:

    //(*Identifiers(editmenu)
    static const long ID_STATICTEXT1;
    static const long ID_LISTBOX5;
    static const long ID_TEXTCTRL6;
    static const long ID_CHECKBOX1;
    static const long ID_BUTTON12;
    static const long ID_BUTTON16;
    static const long ID_BUTTON17;
    static const long ID_STATICTEXT7;
    static const long ID_CHOICE1;
    static const long ID_BUTTON19;
    static const long ID_CHOICE3;
    static const long ID_TEXTCTRL5;
    static const long ID_CHECKBOX2;
    static const long ID_BUTTON13;
    static const long ID_BUTTON14;
    static const long ID_BUTTON15;
    static const long ID_STATICTEXT2;
    static const long ID_LISTBOX1;
    static const long ID_STATICTEXT5;
    static const long ID_LISTBOX2;
    static const long ID_BUTTON1;
    static const long ID_STATICTEXT4;
    static const long ID_TEXTCTRL2;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON5;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_LISTBOX4;
    static const long ID_TEXTCTRL4;
    static const long ID_BUTTON10;
    static const long ID_BUTTON11;
    static const long ID_BUTTON9;
    static const long ID_LISTBOX3;
    static const long ID_CHOICE2;
    static const long ID_TEXTCTRL3;
    static const long ID_STATICTEXT6;
    static const long ID_TEXTCTRL7;
    static const long ID_BUTTON6;
    static const long ID_BUTTON8;
    static const long ID_BUTTON7;
    static const long ID_BUTTON4;
    //*)

private:

    //(*Handlers(editmenu)
    void OnTextCtrl2Text(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void Onadd_ing_buttonClick(wxCommandEvent& event);
    void OnButton12Click(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void Ondelete_group_buttonClick(wxCommandEvent& event);
    void Ongroup_listboxSelect(wxCommandEvent& event);
    void Onadd_group_buttonClick(wxCommandEvent& event);
    void Onrename_group_buttonClick(wxCommandEvent& event);
    void Oning_listboxSelect(wxCommandEvent& event);
    void Ondelete_ing_buttonClick(wxCommandEvent& event);
    void Onrename_ing_buttonClick(wxCommandEvent& event);
    void Onrename_in_menu_buttonClick(wxCommandEvent& event);
    void Onmenu_listboxSelect(wxCommandEvent& event);
    void Onadd_menu_buttonClick(wxCommandEvent& event);
    void Ondelete_menu_buttonClick(wxCommandEvent& event);
    void Onrename_menu_buttonClick(wxCommandEvent& event);
    void Onadd_in_menu_buttonClick(wxCommandEvent& event);
    void Onmenu_in_listboxSelect(wxCommandEvent& event);
    void Onsave_part_buttonClick(wxCommandEvent& event);
    void Ondelete_in_menu_buttonClick(wxCommandEvent& event);
    void Onmove_buttonClick(wxCommandEvent& event);
    void Onparts_listboxSelect(wxCommandEvent& event);
    void Onor_buttonClick(wxCommandEvent& event);
    void Ondelete_part_buttonClick(wxCommandEvent& event);
    void On_lost_focus_price_textctrl(wxCommandEvent& event);
    void Onprice_change_buttonButton1Click(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    //*)
    void refresh_group(void);
    void refresh_ingridient(void);
    void refresh_menu(void);
    void refresh_menu_in(void);
    void fill_parts(int);
    void save_dish(void);
    void refresh_taxes(void);
    void delete_parts_from_dish(int);
    std::string get_part_name(int);
    wxArrayInt ing_array;
    wxArrayInt group_array;
    wxArrayInt ing_gr_array;
    wxArrayInt menu_array;
    wxArrayInt menu_in_array;
    wxArrayString parts_array;
    wxArrayInt taxes_array;
    wxArrayInt taxes_menu_ids;
    wxArrayInt kitchens;
    DECLARE_EVENT_TABLE()

};

#endif
