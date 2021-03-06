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
#ifndef DISPLAY_SETTINGS_H
#define DISPLAY_SETTINGS_H

//(*Headers(display_settings)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/listbox.h>
//*)
#include <mysql++.h>
#include <string>
#include <iostream>
#include "wx_std.h"

class display_settings: public wxDialog
{
public:

    display_settings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~display_settings();

    //(*Declarations(display_settings)
    wxFlexGridSizer* FlexGridSizer1;
    wxButton* Button1;
    wxListBox* menus;
    wxButton* Button2;
    wxListBox* workers;
    //*)
    void fill_all(void);
    mysqlpp::Connection * conn_display;

protected:

    //(*Identifiers(display_settings)
    static const long ID_LISTBOX1;
    static const long ID_LISTBOX2;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(display_settings)
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    //*)
    wxArrayInt worker_ids;
    wxArrayInt worker_show;
    wxArrayInt menu_ids;
    wxArrayInt menu_show;
    DECLARE_EVENT_TABLE()
};

#endif
