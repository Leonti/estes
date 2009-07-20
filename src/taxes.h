#ifndef TAXES_H
#define TAXES_H

//(*Headers(taxes)
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

class taxes: public wxDialog
{
	public:

		taxes(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~taxes();
		void fill_all();
        mysqlpp::Connection * conn_taxes;
		//(*Declarations(taxes)
		wxListBox* ListBox1;
		wxButton* Button4;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl2;
		//*)

	protected:

		//(*Identifiers(taxes)
		static const long ID_STATICTEXT2;
		static const long ID_LISTBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:
        wxArrayInt tax_ids;
		//(*Handlers(taxes)
		void OnListBox1Select(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
