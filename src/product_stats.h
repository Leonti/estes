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
#ifndef PRODUCT_STATS_H
#define PRODUCT_STATS_H

//(*Headers(product_stats)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/datectrl.h>
#include <wx/button.h>
#include <wx/dateevt.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

#include <mysql++.h>
#include <string>
#include <iostream>
#include "wx_std.h"
#include "add_zero.h"

class product_stats: public wxDialog
{
public:

    product_stats(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~product_stats();

    //(*Declarations(product_stats)
    wxButton* Button1;
    wxChoice* Choice2;
    wxStaticText* StaticText1;
    wxDatePickerCtrl* DatePickerCtrl2;
    wxStaticText* StaticText3;
    wxChoice* Choice1;
    wxTextCtrl* TextCtrl1;
    wxStaticText* StaticText4;
    wxStaticText* StaticText2;
    wxDatePickerCtrl* DatePickerCtrl1;
    //*)
    mysqlpp::Connection * conn;
    void fill_all(void);

protected:

    //(*Identifiers(product_stats)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_DATEPICKERCTRL1;
    static const long ID_DATEPICKERCTRL2;
    static const long ID_STATICTEXT3;
    static const long ID_CHOICE1;
    static const long ID_STATICTEXT4;
    static const long ID_CHOICE2;
    static const long ID_TEXTCTRL1;
    static const long ID_BUTTON1;
    //*)

private:

    //(*Handlers(product_stats)
    void OnButton1Click(wxCommandEvent& event);
    void OnDatePickerCtrl1Changed(wxDateEvent& event);
    void OnLimitSelect(wxCommandEvent& event);
    void OnTypeSelect(wxCommandEvent& event);
    void OnDatePickerCtrl2Changed(wxDateEvent& event);
    //*)
    void refresh(void);
    DECLARE_EVENT_TABLE()
};

#endif
