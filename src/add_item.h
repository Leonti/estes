#ifndef ADD_ITEM_H
#define ADD_ITEM_H

//(*Headers(add_item)
#include <wx/frame.h>
//*)
#include <wx/button.h>
#include <mysql++.h>
#include <string>
#include <iostream>
#include <wx/statbox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

#include "dish_props.h"
#include <wx/dynarray.h>
#include <wx/listctrl.h>
#include "add_zero.h"
//#include "restaurant_posMain.h"


WX_DECLARE_OBJARRAY(item_entry, itemsArray);

class add_item: public wxFrame
{
	public:

		add_item(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~add_item();

		//(*Declarations(add_item)
		//*)
//        wxStaticBox* StaticBox1;
		wxButton* buttons;
        mysqlpp::Connection * conn_add;
        void fill_all();
        wxArrayInt menus_to_show;
        bool kitchen;
        item_entry dish_to_add;
    wxListCtrl* main_list_ctrl;
    itemsArray* items_add_item;
    wxFont* main_font_listctrl;

	protected:

		//(*Identifiers(add_item)
		//*)

	private:
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;

    wxStaticText*     StaticText1;
    wxBoxSizer* BoxMainSizer;
	wxFlexGridSizer* FlexGridMainSizer;
	wxFlexGridSizer* FlexGridSizerButtons;
	wxStaticBoxSizer* StaticBoxSizers;
    wxFlexGridSizer* FlexGridSizers;
    wxButton* Button1;
//    wxButton* Button2;
    wxButton* grid_buttons;


		//(*Handlers(add_item)

		//*)
        void OnButton(wxCommandEvent& event);
        void OnOKClick(wxCommandEvent& event);
        void add_to_listctrl(void);
//        void OnCancelClick(wxCommandEvent& event);
		DECLARE_EVENT_TABLE()
};

#endif
