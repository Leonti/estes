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
#include "perif.h"
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/platinfo.h>

#include <wx/msgdlg.h>

int printReceipt(wxString receipt, wxString customCommand, bool custom)
{
    wxString txtFileName = wxFileName::CreateTempFileName(_("pos_print"));
    wxFile txtFile(txtFileName, wxFile::write);
    txtFile.Write(receipt);

    if(custom)
    {
//wxMessageBox(customCommand + _(" ") + txtFileName);
//executing custom command
        wxExecute(customCommand + _(" ") + txtFileName);
    }
    else
    {
        wxPlatformInfo platInfo;
        wxString systemName = platInfo.GetOperatingSystemFamilyName();

        if(systemName == _T("Unix"))
        {
            wxString commandToPrint = _T("lp ") + txtFileName;
            wxExecute(commandToPrint);
        }
        else if(systemName == _T("Windows"))
        {
//running .bat file for Windows
            wxString commandToPrint = _T("print.bat ") + txtFileName;
//bat file contains command like "notepad \p filename"
            wxExecute(commandToPrint);
        }
    }
}

int openDrawer(wxString customCommand, bool custom)
{
    if(custom)
    {
//wxMessageBox(customCommand);
        wxExecute(customCommand);
    }
    else
    {
//some generic command if it exist
    }

}

int printTicket(wxString htmlTicket, wxString customCommand, bool custom)
{
    if(custom)
    {
        wxString htmlFileName = wxFileName::CreateTempFileName(_("pos_ticket"));
        wxFile txtFile(htmlFileName, wxFile::write);
        txtFile.Write(htmlTicket);

//wxMessageBox(customCommand + _(" ") + htmlFileName);
//executing custom command
        wxExecute(customCommand + _(" ") + htmlFileName);
        return 1;
    }
    else
    {
        wxHtmlEasyPrinting* print = new wxHtmlEasyPrinting();
        if(print->PrintText( htmlTicket ))
        {
            return 1;
        }
    }
}
