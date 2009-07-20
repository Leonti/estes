#ifndef WX_STD_H
#define WX_STD_H

#include <string>
#include <wx/string.h>
std::string wx2std(const wxString& input, wxMBConv* conv = wxConvUI);
wxString std2wx(const std::string& input, wxMBConv* conv = wxConvUI);

#endif
