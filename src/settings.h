#ifndef SETTINGS_H
#define SETTINGS_H

//(*Headers(settings)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/statline.h>
//*)
#include "db_set_panel.h"
#include "prog_set_panel.h"
#include "perif_set_panel.h"
#include "restaurant_posMain.h"
#include <wx/config.h>
#include <wx/dialog.h>
#include <mysql++.h>


class settings: public wxDialog
{
	public:

		settings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~settings();

		//(*Declarations(settings)
		wxFlexGridSizer* FlexGridSizer1;
		wxButton* Button1;
		wxButton* Button2;
		wxStaticLine* StaticLine1;
		wxNotebook* Notebook1;
		//*)
        wxConfigBase *confi;
        void fill_all(void);
 //       bool reconnect;
        mysqlpp::Connection * conn;
        bool dbase_connected;
		current_settings* set_now;
		prog_set_panel* prog_set;
        perif_set_panel* perif_set;
        db_set_panel* db_set;
        wxPrintDialogData* printdialogdata;
	protected:

		//(*Identifiers(settings)
		static const long ID_NOTEBOOK1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(settings)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
