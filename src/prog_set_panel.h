#ifndef PROG_SET_PANEL_H
#define PROG_SET_PANEL_H

//(*Headers(prog_set_panel)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/choice.h>
//*)
#include <wx/config.h>

struct current_settings{
    bool kitchen;
    int kitchen_type; //1-database, 2 - print
    int lang;
    bool custom_print; //true - use custom command - false - default one
    bool custom_drawer;
    bool custom_ticket;
    bool custom_width;
    wxString print_command;
    wxString drawer_command;
    wxString ticket_command;
    int print_width;
    };

class prog_set_panel: public wxPanel
{
	public:

		prog_set_panel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~prog_set_panel();

		//(*Declarations(prog_set_panel)
		wxCheckBox* CheckBox1;
		wxStaticText* StaticText1;
		wxChoice* Choice1;
		wxCheckBox* CheckBox2;
		wxStaticText* StaticText2;
		wxCheckBox* CheckBox3;
		//*)
		current_settings* set_now;
        wxConfigBase *confi;
		void fill_all(void);
		void Save(void);

	protected:

		//(*Identifiers(prog_set_panel)
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		//*)

	private:

		//(*Handlers(prog_set_panel)
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnCheckBox2Click(wxCommandEvent& event);
		void OnCheckBox3Click(wxCommandEvent& event);
		//*)
        wxArrayInt langs;

		DECLARE_EVENT_TABLE()
};

#endif
