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
#ifndef PERIF_SET_PANEL_H
#define PERIF_SET_PANEL_H

//(*Headers(perif_set_panel)
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <wx/printdlg.h>
#include "wx/print.h"

#include "prog_set_panel.h"
class perif_set_panel: public wxPanel
{
public:

    perif_set_panel(wxWindow* parent,wxWindowID id=wxID_ANY);
    virtual ~perif_set_panel();

    //(*Declarations(perif_set_panel)
    wxTextCtrl* TextCtrl3;
    wxRadioButton* RadioButton1;
    wxRadioButton* RadioButton3;
    wxCheckBox* CheckBox1;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxRadioButton* RadioButton2;
    wxCheckBox* CheckBox2;
    wxTextCtrl* TextCtrl1;
    wxStaticText* StaticText4;
    wxStaticText* StaticText2;
    wxCheckBox* CheckBox3;
    wxSpinCtrl* SpinCtrl1;
    wxTextCtrl* TextCtrl2;
    //*)
    current_settings* set_now;
    wxConfigBase *confi;
    wxPrintDialogData* printdialogdata;
    wxPrintData* printdata;
    void fill_all(void);
    void Save(void);
protected:

    //(*Identifiers(perif_set_panel)
    static const long ID_RADIOBUTTON1;
    static const long ID_RADIOBUTTON2;
    static const long ID_RADIOBUTTON3;
    static const long ID_SPINCTRL1;
    static const long ID_CHECKBOX1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_CHECKBOX2;
    static const long ID_TEXTCTRL2;
    static const long ID_CHECKBOX3;
    static const long ID_TEXTCTRL3;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    //*)

private:

    //(*Handlers(perif_set_panel)
    void OnCheckBox1Click(wxCommandEvent& event);
    void OnCheckBox2Click(wxCommandEvent& event);
    void OnRadioButton1Select(wxCommandEvent& event);
    void OnRadioButton2Select(wxCommandEvent& event);
    void OnRadioButton3Select(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnCheckBox3Click(wxCommandEvent& event);
    void OnCheckBox3Click1(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};



#endif
