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
#ifndef WAITER_CHOOSE_H
#define WAITER_CHOOSE_H

//(*Headers(waiter_choose)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/listbox.h>
//*)

#include <mysql++.h>
#include <string>
#include <iostream>
#include "wx_std.h"
//#include <wx/choice.h>

class waiter_choose: public wxDialog
{
public:

    waiter_choose(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~waiter_choose();

    //(*Declarations(waiter_choose)
    wxFlexGridSizer* FlexGridSizer1;
    wxListBox* ListBox1;
    wxButton* Button1;
    //*)
    void fill_all(void);
    mysqlpp::Connection * conn_worker;
//        wxChoice* choice_from_main;
    int selected_id;

protected:

    //(*Identifiers(waiter_choose)
    static const long ID_LISTBOX1;
    static const long ID_BUTTON1;
    //*)

private:

    //(*Handlers(waiter_choose)
    void OnButton1Click(wxCommandEvent& event);
    //*)
//        wxArrayInt workers_ids;

    DECLARE_EVENT_TABLE()
};

#endif
