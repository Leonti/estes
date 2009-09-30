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
#ifndef WORKERS_H
#define WORKERS_H

//(*Headers(workers)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
//*)
#include <mysql++.h>
#include <string>
#include <iostream>
#include "wx_std.h"

class workers: public wxDialog
{
public:

    workers(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~workers();

    //(*Declarations(workers)
    wxListBox* ListBox1;
    wxButton* Button4;
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxStaticText* StaticText1;
    wxTextCtrl* TextCtrl1;
    wxStaticText* StaticText2;
    //*)

    void fill_all(void);
    mysqlpp::Connection * conn_workers;

protected:

    //(*Identifiers(workers)
    static const long ID_STATICTEXT1;
    static const long ID_LISTBOX1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    //*)

private:

    //(*Handlers(workers)
    void OnButton4Click(wxCommandEvent& event);
    void OnButton3Click(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void OnListBox1Select(wxCommandEvent& event);
    //*)
    wxArrayInt workers_ids;

    DECLARE_EVENT_TABLE()
};

#endif
