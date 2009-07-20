#include "dish_props.h"

//(*InternalHeaders(dish_props)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include "wx_std.h"
#include <wx/msgdlg.h>

#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ArrayOfRadioboxes);
WX_DEFINE_OBJARRAY(ArrayOfCheckboxes);

//(*IdInit(dish_props)
const long dish_props::ID_STATICTEXT1 = wxNewId();
const long dish_props::ID_STATICTEXT2 = wxNewId();
const long dish_props::ID_SPINCTRL1 = wxNewId();
const long dish_props::ID_BUTTON1 = wxNewId();
const long dish_props::ID_STATICTEXT3 = wxNewId();
const long dish_props::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dish_props,wxDialog)
	//(*EventTable(dish_props)
	//*)
END_EVENT_TABLE()

dish_props::dish_props(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{


	//(*Initialize(dish_props)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	static_dish = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont static_dishFont(14,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	static_dish->SetFont(static_dishFont);
	FlexGridSizer1->Add(static_dish, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Quantity:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxSize(42,26), 0, 1, 100, 1, _T("ID_SPINCTRL1"));
	SpinCtrl1->SetValue(_T("1"));
	FlexGridSizer2->Add(SpinCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Comments:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(122,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(20, 1, 0, 0);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dish_props::OnButton1Click);
	//*)
}

dish_props::~dish_props()
{
	//(*Destroy(dish_props)
	//*)
}

void dish_props::fill_all(int dish_id){

    add_entry = false;

        mysqlpp::Query query = conn_dish->query();
        query << "SELECT * FROM `dishes` WHERE `id`=" << dish_id;
        mysqlpp::StoreQueryResult res = query.store();
        if(res){
        mysqlpp::Row row=res.at(0);
        std::string dish_name = std::string(row["name"]);

        item_ent.name = std2wx(dish_name, wxConvUI);
        static_dish -> SetLabel(item_ent.name);

        item_ent.price = double(row["price"]);
        item_ent.comment = std2wx(std::string(row["comment"]),wxConvUI);
        TextCtrl1->ChangeValue(item_ent.comment);

        if(int(row["kitchen"]) == 1){
            item_ent.kitchen = true;
            }else{
            item_ent.kitchen = false;
                }

//adding taxes to this crap
       query << "SELECT * FROM `menus` WHERE `id`=" << int(row["menu_id"]);
        res = query.store();
        if(res){
        mysqlpp::Row row = res.at(0);
        int id_tax = int(row["tax_id"]);
        query << "SELECT * FROM `taxes` WHERE `id`=" << id_tax;
        res = query.store();
        item_ent.tax_id = id_tax;
        if(res){
            row = res.at(0);
            item_ent.tax = double(row["value"])/100;
            }
            }
//end of adding taxes



//filling from editmenu fill_parts
        query << "SELECT * FROM `dishes_parts` WHERE `dishes_id`=" << dish_id;
        res = query.store();
       if (res)
        {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
                int part_id = int(row["parts_id"]);
//                parts.dishes_parts_id = int(row["id"]);

              if(part_id == 0){//dobavliem ors
        query << "SELECT * FROM `dishes_parts_ors` WHERE `dishes_parts_id`=" << int(row["id"]);
        mysqlpp::StoreQueryResult res_ors = query.store();
               if(res_ors){
             wxArrayString choices;


            mysqlpp::StoreQueryResult::size_type j;
            for (j = 0; j < res_ors.num_rows(); ++j){
                row = res_ors[j];
            std::string slice_or = get_part_name(int(row["parts_id"]));
            choices.Add(std2wx(slice_or, wxConvUI));
                }
wxRadioBox* radi = new wxRadioBox(this, -1, _("choose"), wxDefaultPosition, wxDefaultSize, choices, 1, 0, wxDefaultValidator, _T("raddio"));
    radioboxes.Add(radi);
 FlexGridSizer4 -> Add(radi, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    boxes.Add(1);
                   }
                  }else{

        wxCheckBox* checki = new wxCheckBox(this, -1, std2wx(get_part_name(part_id), wxConvUI), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	checkboxes.Add(checki);
	checki->SetValue(true);

FlexGridSizer4 -> Add(checki, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);

	boxes.Add(2);

                      }


            }
        }


//end of fill_parts from editmenu


        }


    //SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
    }

void dish_props::OnButton1Click(wxCommandEvent& event)
{
        item_ent.comment = TextCtrl1 -> GetValue();

        int j = 0;
        int radios = 0;
        int checks = 0;

for(int i=0; i<boxes.GetCount(); i++){
if(boxes[i] == 1){  //radiobox
  wxString proverko;
  proverko << radioboxes[radios] -> GetSelection();
int numb_in_array = j + radioboxes[radios] -> GetSelection();
 // wxMessageBox(part_names[numb_in_array] + price_change[numb_in_array]);
double pr_change;
price_change[numb_in_array].ToDouble(&pr_change);
item_ent.price += pr_change;

item_ent.parts << part_numbers[numb_in_array] <<  _(":");

  j +=  radioboxes[radios] -> GetCount();
  radios += 1;
    }else if(boxes[i] == 2){ //checkbox
        if(checkboxes[checks] -> GetValue() == true){
           // wxMessageBox(part_names[j] + price_change[j]);
            item_ent.parts << part_numbers[j] <<  _(":");
            double pr_change;
            price_change[j].ToDouble(&pr_change);
            item_ent.price += pr_change;
        }else{
            item_ent.parts << _T("n") << part_numbers[j] <<  _T(":");
            }

        j += 1;
        checks += 1;
        }

    }
item_ent.qty = SpinCtrl1 -> GetValue();
add_entry = true;
Show(0);

}

std::string dish_props::get_part_name(int part_id){


        part_numbers.Add(part_id);
        std::string part_name;
        mysqlpp::Query query = conn_dish->query();
        query << "SELECT * FROM `parts` WHERE `id`=" << part_id;
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            mysqlpp::Row row = res.at(0);
            part_name = std::string(row["name"]);

            price_change.Add(std2wx(std::string(row["price_change"]),wxConvUI));
            part_names.Add(std2wx(std::string(row["name"]),wxConvUI));

        }
        return part_name;

    }


