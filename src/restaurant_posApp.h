/***************************************************************
 * Name:      restaurant_posApp.h
 * Purpose:   Defines Application Class
 * Author:    Leonti Bielski (prishelec@gmail.com)
 * Created:   2008-01-26
 * Copyright: Leonti Bielski (http://leonti.ru)
 * License:
 **************************************************************/

#ifndef RESTAURANT_POSAPP_H
#define RESTAURANT_POSAPP_H

#include <wx/app.h>

class restaurant_posApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // RESTAURANT_POSAPP_H
