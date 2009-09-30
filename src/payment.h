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
#ifndef PAYMENT_H
#define PAYMENT_H

//(*Headers(payment)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
//*)

#include <wx/msgdlg.h>
#include "cash.h"
#include "add_zero.h"
class payment: public wxDialog
{
public:

    payment(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~payment();

    //(*Declarations(payment)
    wxFlexGridSizer* FlexGridSizer1;
    wxButton* Button1;
    wxButton* Button2;
    wxStaticText* StaticText1;
    //*)
    double order_total;
    void fill_all(double);
    bool print;
    double paid;
    int type;

protected:

    //(*Identifiers(payment)
    static const long ID_STATICTEXT1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(payment)
    void OnButton2Click(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
