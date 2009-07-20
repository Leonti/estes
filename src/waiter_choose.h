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
