/*************************************************************************************
*  Estes - Restaurant Point Of Sale                                                  *
*  Copyright (C) 2009  Leonti Bielski                                                *
*                                                                                    *
*  This program is free software; you can redistribute it and/or modify              *
*  it under the terms of the GNU General Public License as published by              *
*  the Free Software Foundation; either version 2 of the License, or                 *
*  (at your option) any later version.                                               *
*                                                                                    *
*  This program is distributed in the hope that it will be useful,                   *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                     *
*  GNU General Public License for more details.                                      *
*                                                                                    *
*  You should have received a copy of the GNU General Public License                 *
*  along with this program; if not, write to the Free Software                       *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA    *
*************************************************************************************/
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
