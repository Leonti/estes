#include "wx_std.h"



wxString std2wx(const std::string& input, wxMBConv*  conv)
{
     if (input.empty())
         return wxEmptyString;
     if (!conv)
         conv = wxConvCurrent;
     return wxString(input.c_str(), *conv);
}

std::string wx2std(const wxString& input, wxMBConv*  conv)
{
     if (input.empty())
         return "";
     if (!conv)
         conv = wxConvCurrent;
     return std::string(input.mb_str(*conv));
}
