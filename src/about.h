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
#ifndef ABOUT_H
#define ABOUT_H

//(*Headers(about)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class about: public wxDialog
{
public:

    about(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~about();

    //(*Declarations(about)
    wxPanel* Panel1;
    wxButton* Button1;
    wxStaticText* StaticText1;
    wxStaticText* StaticText10;
    wxPanel* Panel2;
    wxStaticText* StaticText3;
    wxStaticLine* StaticLine1;
    wxStaticText* StaticText8;
    wxStaticText* StaticText12;
    wxStaticLine* StaticLine3;
    wxStaticText* StaticText7;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText2;
    wxNotebook* Notebook1;
    wxStaticText* StaticText6;
    wxStaticLine* StaticLine4;
    wxStaticText* StaticText9;
    wxStaticText* StaticText11;
    //*)

protected:

    //(*Identifiers(about)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT2;
    static const long ID_STATICLINE3;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT9;
    static const long ID_STATICLINE4;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_STATICLINE1;
    static const long ID_PANEL2;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT11;
    static const long ID_PANEL1;
    static const long ID_NOTEBOOK1;
    static const long ID_BUTTON1;
    //*)

private:

    //(*Handlers(about)
    void OnButton1Click(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
