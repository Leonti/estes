#ifndef STATS_TODAY_H
#define STATS_TODAY_H

//(*Headers(stats_today)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/datectrl.h>
#include <wx/button.h>
#include <wx/dateevt.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
//*)

#include <mysql++.h>
#include <string>
#include <iostream>

#include "wx_std.h"
#include "add_zero.h"

class stats_today: public wxDialog
{
	public:

		stats_today(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~stats_today();

		//(*Declarations(stats_today)
		wxStaticText* total_charge;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxListBox* ListBox1;
		wxStaticText* total_cash_period;
		wxStaticText* static_taxes;
		wxButton* Button2;
		wxStaticText* static_net;
		wxStaticText* static_taxes_period;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxDatePickerCtrl* DatePickerCtrl2;
		wxStaticText* static_net_period;
		wxStaticText* StaticText3;
		wxStaticText* StaticText8;
		wxStaticText* StaticText12;
		wxStaticText* total_charge_period;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxStaticText* static_total;
		wxStaticText* StaticText6;
		wxStaticText* static_total_period;
		wxStaticText* total_cash;
		wxListBox* ListBox2;
		wxStaticText* StaticText9;
		wxStaticText* StaticText11;
		wxDatePickerCtrl* DatePickerCtrl1;
		//*)
        mysqlpp::Connection * conn_stat;
		void fill_all(void);
	protected:

		//(*Identifiers(stats_today)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_DATEPICKERCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT12;
		static const long ID_LISTBOX1;
		static const long ID_LISTBOX2;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT20;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT24;
		static const long ID_STATICTEXT25;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(stats_today)
		void OnButton1Click(wxCommandEvent& event);
		void OnListBox1Select(wxCommandEvent& event);
		void OnDatePickerCtrl1Changed(wxDateEvent& event);
		void OnDatePickerCtrl2Changed(wxDateEvent& event);
		void OnListBox2Select(wxCommandEvent& event);
		//*)

		wxString info(int);
		wxArrayInt order_ids;
		void refresh_day(wxString);
		void refresh_all(void);

		DECLARE_EVENT_TABLE()
};

#endif
