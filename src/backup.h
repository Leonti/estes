#include <wx/utils.h>
#include <wx/string.h>
#include <wx/ffile.h>
#include <mysql++.h>
#include <wx/regex.h>
#include <wx/tokenzr.h>

#include <wx/msgdlg.h>
#include <wx/stdpaths.h>

long make_dump(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename);
long restore_table(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename);
int makeDump(mysqlpp::Connection*, const wxString& filename);
int restoreFromDump(mysqlpp::Connection*, const wxString& filename);
