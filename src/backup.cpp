#include "backup.h"
#include "wx_std.h"

long make_dump(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename){
    wxString command = _T("mysqldump --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --result-file=") + filename + _T(" ") + db_name;
    long result = wxShell(command);
    return result;
    }

long restore_table(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename){
    wxString command = _T("mysql < ") + filename + _T(" --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --database=") + db_name;
    long result = wxShell(command);
    return result;
    }

int makeDump(mysqlpp::Connection* conn, const wxString& filename){
wxFFile backup_file(filename , _("w"));
if(backup_file.IsOpened()){
//    backup_file.Write(_("Proverko zapisi fajla"));

wxString backup_statement = _("SET SQL_MODE=\"NO_AUTO_VALUE_ON_ZERO\";\n");
    mysqlpp::Query query = conn->query();
    query << "SHOW TABLES";
    mysqlpp::StoreQueryResult res = query.store();
    if (res) // list of all tables in our database
    {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];

    query << "SHOW CREATE TABLE " << std::string(row[0]);
    mysqlpp::StoreQueryResult res2 = query.store();
if(res2){ //statement to create current table (firs value - table name)
 row = res2[0];
backup_statement << _("DROP TABLE IF EXISTS `") << std2wx(std::string(row[0]),wxConvUI) << _("`;\n");
backup_statement << std2wx(std::string(row[1]),wxConvUI) << _(";\n");
    query << "SELECT * FROM " << std::string(row[0]);
    mysqlpp::StoreQueryResult res3 = query.store();
    if(res3){ //data in current table
if(res3.num_rows() > 0){ //table is not empty
wxString insert_statement = _("INSERT INTO `") + std2wx(std::string(row[0]), wxConvUI) + _("` (");

for (size_t k = 0; k < res3.field_names()->size(); k++) {
insert_statement << _("`") << std2wx(res3.field_name(k), wxConvUI) << _("`");
if(k != res3.field_names()->size() - 1){
    insert_statement << _(", ");
}}
insert_statement << _(") VALUES\n");
for (int h = 0; h < res3.num_rows(); ++h) {
row = res3[h];
insert_statement << _("(");
for (size_t g = 0; g < res3.field_names()->size(); g++) {
    mysqlpp::FieldTypes::value_type ft = res3.field_type(g);
if(ft.quote_q ()){ //need to be quoted
insert_statement << _("'") << std2wx(std::string(row[g]),wxConvUI) << _("'");
}else{
insert_statement << std2wx(std::string(row[g]),wxConvUI);
}
if(g != res3.field_names()->size() - 1){
    insert_statement << _(", ");
}

}
insert_statement << _(")");
if(h != res3.num_rows() - 1){
insert_statement << _(",\n");
}
}
backup_statement << insert_statement << _(";\n");
    }
    }
}
}
    backup_file.Write(backup_statement);
    }

    return 1;

}else{
wxMessageBox(_T("Failed to save backup file. Check write permissions."));
return 0;
}
}

int restoreFromDump(mysqlpp::Connection* conn, const wxString& filename){
wxFFile backup_file(filename);
if(backup_file.IsOpened()){
    wxString fileContent;
    backup_file.ReadAll(&fileContent);
 //   wxMessageBox(fileContent);
//wxRegEx comments(_("--[^x22\\x27].*"), wxRE_NEWLINE);
// \x22[^\x22]*\x22|\x27[^\x27]*\x27|/\*.*?\*/|(\#|--)([^\x22\x27]*?)$ - groups 1 and 2
wxRegEx comments(_("\\x22\\x27[^\\x22\\x27]*\\x22\\x27|/\\*.*?\\*/|(\\#|--)[^\\x22\\x27]*?$"), wxRE_ADVANCED|wxRE_NEWLINE);
//wxRegEx comments(_("\\x22[^\\x22]*\\x22|\\x27[^\\x27]*\\x27|/\\*.*?\\*/|(\\#|--)([^\\x22\\x27]*?)$"), wxRE_ADVANCED|wxRE_NEWLINE);


comments.ReplaceAll(&fileContent, _(""));
//comments.ReplaceAll(&fileContent, _("*\\2"));

fileContent.Trim();
wxRegEx semicolons(_("(?m);\\s*$"), wxRE_ADVANCED|wxRE_NEWLINE);
semicolons.ReplaceAll(&fileContent, _("^")); //in the future take care of that - if ^ symbol is inside the satatement

//wxMessageBox(fileContent);

wxStringTokenizer tkz(fileContent, _("^"));
while ( tkz.HasMoreTokens() )
{
wxString sql_query = tkz.GetNextToken().Trim(false);
//wxMessageBox(sql_query);

        mysqlpp::Query query = conn->query();
        query << wx2std(sql_query, wxConvUI);
        query.execute();

}

}else{
wxMessageBox(_T("Failed to open backup file."));
return 0;
}
}
