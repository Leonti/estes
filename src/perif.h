#ifndef PERIF_H_INCLUDED
#define PERIF_H_INCLUDED

#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/html/htmprint.h>

int printReceipt(wxString receipt, wxString customCommand, bool custom);
int printTicket(wxString htmlTicket, wxString customCommand, bool custom);
int openDrawer(wxString customCommand, bool custom);

#endif // PERIF_H_INCLUDED
