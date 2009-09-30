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
#ifndef DISH_PROPS_H
#define DISH_PROPS_H

//(*Headers(dish_props)
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <wx/checkbox.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/list.h>
#include <mysql++.h>
#include <string>
#include <iostream>

#include <wx/dynarray.h>

WX_DECLARE_OBJARRAY(wxRadioBox*, ArrayOfRadioboxes);
WX_DECLARE_OBJARRAY(wxCheckBox*, ArrayOfCheckboxes);

class item_entry
{
public:

    int qty;
    double price;
    double tax;
    int tax_id;
    wxString name;
    wxString comment;
    wxString parts;
    bool kitchen;
};

class dish_props: public wxDialog
{
public:

    dish_props(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~dish_props();
    void fill_all(int dish_id);
    mysqlpp::Connection * conn_dish;

    //(*Declarations(dish_props)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxButton* Button1;
    wxFlexGridSizer* FlexGridSizer4;
    wxStaticText* StaticText3;
    wxFlexGridSizer* FlexGridSizer3;
    wxTextCtrl* TextCtrl1;
    wxStaticText* StaticText2;
    wxSpinCtrl* SpinCtrl1;
    wxStaticText* static_dish;
    //*)

    ArrayOfRadioboxes radioboxes;
    ArrayOfCheckboxes checkboxes;
    wxArrayString price_change;
    wxArrayString part_names;
    wxArrayInt part_numbers;
    wxArrayInt boxes;

    item_entry item_ent;
    bool add_entry;

protected:

    //(*Identifiers(dish_props)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_SPINCTRL1;
    static const long ID_BUTTON1;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL1;
    //*)

private:

    //(*Handlers(dish_props)
    void OnButton1Click(wxCommandEvent& event);

    //*)
    std::string get_part_name(int);
    DECLARE_EVENT_TABLE()
};

#endif
