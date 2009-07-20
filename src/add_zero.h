#ifndef ADD_ZERO_H_INCLUDED
#define ADD_ZERO_H_INCLUDED

#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/datetime.h>
#include <mysql++.h>
#include <string>
#include <wx/arrstr.h>
#include <iostream>
#include "wx_std.h"


wxString addZero(wxString);
wxString addZero(double);
wxString performAdd(wxString);
wxString formatCheque(int, mysqlpp::Connection*, int);
wxString formatTicket(int, mysqlpp::Connection*);
wxString formatDish(mysqlpp::Connection* conn, int dishId);
wxString getPartName(mysqlpp::Connection* conn, int partId);
double round_2 (double);
wxString addSpaces(wxString, int);
wxArrayString explode(wxString& toExplode);

#endif // ADD_ZERO_H_INCLUDED
