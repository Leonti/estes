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
