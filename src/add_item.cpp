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
#include "add_item.h"


#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(itemsArray);

//(*InternalHeaders(add_item)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#include <wx/msgdlg.h>
#include "wx_std.h"
//(*IdInit(add_item)
//*)


BEGIN_EVENT_TABLE(add_item,wxFrame)
    //(*EventTable(add_item)
    //*)
END_EVENT_TABLE()

const long add_item::ID_BUTTON1 = wxNewId();
//const long add_item::ID_BUTTON2 = wxNewId();

add_item::add_item(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(add_item)
    Create(parent, wxID_ANY, _("Add item"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
    //*)
}

add_item::~add_item()
{
    //(*Destroy(add_item)
    //*)
}


void add_item::OnButton(wxCommandEvent& event)
{
    if(kitchen == true)
    {
        dish_props* dish_dlg = new dish_props(this);
        dish_dlg -> conn_dish = conn_add;
        dish_dlg -> fill_all(event.GetId() - 6000);
        dish_dlg -> ShowModal();

        dish_to_add = dish_dlg -> item_ent;

        if(dish_dlg -> add_entry == true)
        {
            add_to_listctrl();

        }
        else
        {
            wxMessageBox(_("Adding of item cancelled :("));
        }
        delete dish_dlg;
    }
    else
    {
        //easy version - we don't need to send data to kitchen, so all we need is name and price of item
        //no need to open additional dialog
        mysqlpp::Query query = conn_add->query();
        query << "SELECT * FROM `dishes` WHERE `id`=" << event.GetId() - 6000;
        mysqlpp::StoreQueryResult res = query.store();
        if(res)
        {
            mysqlpp::Row row = res.at(0);
            std::string name = std::string(row["name"]);
            dish_to_add.name = std2wx(name, wxConvUI);
            dish_to_add.price = double(row["price"]);
            dish_to_add.comment = std2wx(std::string(row["comment"]),wxConvUI);
            if(int(row["kitchen"]) == 1)
            {
                dish_to_add.kitchen = true;
            }
            else
            {
                dish_to_add.kitchen = false;
            }

            query << "SELECT * FROM `menus` WHERE `id`=" << int(row["menu_id"]);
            res = query.store();
            if(res)
            {
                mysqlpp::Row row = res.at(0);
                int id_tax = int(row["tax_id"]);
                query << "SELECT * FROM `taxes` WHERE `id`=" << id_tax;
                res = query.store();
                dish_to_add.tax_id = id_tax;
                if(res)
                {
                    row = res.at(0);
                    dish_to_add.tax = double(row["value"])/100;
                }
            }
        }

        dish_to_add.qty = 1;
        dish_to_add.parts.Clear();
        add_to_listctrl();
    }
}

void add_item::fill_all()
{


    FlexGridMainSizer = new wxFlexGridSizer(0, 1, 0, 0);

    FlexGridMainSizer->AddGrowableCol(1);
    StaticText1 = new wxStaticText(this, -1, _("Please choose a product"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridMainSizer->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    FlexGridSizerButtons = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizerButtons->AddGrowableCol(0);
    FlexGridSizerButtons->AddGrowableRow(0);
    Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizerButtons->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
//	Button2 = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
//	FlexGridSizerButtons->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridMainSizer->Add(FlexGridSizerButtons, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);


    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_item::OnOKClick);
//    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_item::OnCancelClick);


    for (int j=0; j < menus_to_show.GetCount(); j++)
    {
        mysqlpp::Query query = conn_add->query();
        query << "SELECT * FROM `menus` WHERE `id`=" << menus_to_show[j];
        mysqlpp::StoreQueryResult res = query.store();
        wxString menu_name;
        if(res)
        {
            mysqlpp::Row row = res.at(0);
            std::string mn_name = std::string(row["name"]);
            menu_name = std2wx(mn_name, wxConvUI);
        }



//        mysqlpp::Query query = conn_add->query();
        query << "SELECT * FROM `dishes` WHERE `menu_id`=" << menus_to_show[j];
        res = query.store();

        if (res)
        {
            mysqlpp::Row row;
            mysqlpp::StoreQueryResult::size_type i;


            StaticBoxSizers = new wxStaticBoxSizer(wxHORIZONTAL, this, menu_name);
            FlexGridSizers = new wxFlexGridSizer(10, 4, 0, 0);
            for (i = 0; i < res.num_rows(); ++i)
            {
                row = res[i];

                std::string dish_name = std::string(row["name"]);
                int menu_id = int(row["id"]);
                wxString b_name = _("button_id_");
                b_name << menu_id;


                grid_buttons = new wxButton(this, 6000 + menu_id, std2wx(dish_name, wxConvUI), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, b_name);
                FlexGridSizers->Add(grid_buttons, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
                Connect(6000 + menu_id, wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&add_item::OnButton);

            }
            StaticBoxSizers->Add(FlexGridSizers, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
            FlexGridMainSizer->Add(StaticBoxSizers, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

        }
    }


    SetSizer(FlexGridMainSizer);
    FlexGridMainSizer->Fit(this);
    FlexGridMainSizer->SetSizeHints(this);

}

void add_item::OnOKClick(wxCommandEvent& event)
{
    Show(0);
}

void add_item::add_to_listctrl(void)
{
    wxString qty;
    qty << dish_to_add.qty;
    items_add_item -> Add(dish_to_add);
    long tmp = main_list_ctrl -> InsertItem(main_list_ctrl -> GetItemCount(), qty, 0);
    main_list_ctrl->SetItemData(tmp, 1);
    main_list_ctrl->SetItemFont(tmp, *main_font_listctrl);
    main_list_ctrl->SetItem(tmp, 1, dish_to_add.name);
    main_list_ctrl->SetItem(tmp, 2, addZero(dish_to_add.price));

}


/*
void add_item::OnCancelClick(wxCommandEvent& event){
            wxMessageBox(_("Otmeniaem vybrannye produkty?"));

            } */
