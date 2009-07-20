/***************************************************************
 * Name:      restaurant_posApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Leonti Bielski (prishelec@gmail.com)
 * Created:   2008-01-26
 * Copyright: Leonti Bielski (http://leonti.ru)
 * License:
 **************************************************************/

#include "restaurant_posApp.h"

//(*AppHeaders
#include "restaurant_posMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(restaurant_posApp);

bool restaurant_posApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	restaurant_posFrame* Frame = new restaurant_posFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
