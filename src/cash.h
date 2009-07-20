#ifndef CASH_H
#define CASH_H

//(*Headers(cash)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "add_zero.h"

class cash: public wxDialog
{
	public:

		cash(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~cash();

		//(*Declarations(cash)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText2;
		//*)
		double order_total;
		void fill_all(double);
        double *paid;
        double print;
	protected:

		//(*Identifiers(cash)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(cash)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl1TextEnter(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		bool text_filled;
		void save_and_close(void);

		DECLARE_EVENT_TABLE()
};

#endif
