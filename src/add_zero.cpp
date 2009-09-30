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
#include "add_zero.h"

double round_2 (double in)
{
    //7.956
    in = in*100; //795.6
    in = in + .5; //796.1
    long trunk = in;
    double out = trunk;
    out = out/100;
    return out;
}

wxString addZero(wxString toAdd)
{
    return performAdd(toAdd);
}

wxString addZero(double toAddDouble)
{
    wxString toAdd;
    toAdd << toAddDouble;
    return performAdd(toAdd);
}

wxString performAdd(wxString toAdd)
{
    if(toAdd.Mid(toAdd.Length()-2,1) == _T("."))
    {
        toAdd << _T("0");
    }
    else if(toAdd.Find(_T(".")) == wxNOT_FOUND)
    {
        toAdd << _T(".00");
    }

    return toAdd;

}

wxString formatCheque(int order_id, mysqlpp::Connection* conn, int width)
{
    wxString info;
    double taxes = 0;
    double prices = 0;
    double given;
    wxString waiter_name;
    int pay_type;
    wxDateTime tiemp;
    mysqlpp::Query query = conn->query();
    query << "SELECT * FROM `orders` WHERE `id`=" << order_id << " LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        mysqlpp::Row row = res.at(0);
        taxes = double(row["taxes"]);
        prices = double(row["amount"]);
        given = double(row["amount_given"]);
        pay_type = int(row["pay_type"]);
        wxString timec = std2wx(std::string(row["time"]),wxConvUI);
        tiemp.ParseDateTime(timec.c_str());

        query << "SELECT `name` FROM `workers` WHERE `id`=" << int(row["waiter_id"]) << " LIMIT 1";
        res = query.store();
        row = res.at(0);
        waiter_name = std2wx(std::string(row["name"]), wxConvUI);

    }
    wxString infoVerse;
    info << _T("Time ordered: ") << tiemp.FormatTime() << _T("\n");

    for(int t=0; t<width; ++t)
    {
        info << _T("-");
    }
    info << _T("\n");

    infoVerse << _T("Qty Name ");
    for(int t = infoVerse.Length(); t<width-5; ++t)
    {
        infoVerse << _T(" ");
    }
    infoVerse << _T("Price\n\n");
    info << infoVerse;
    query << "SELECT * FROM `orders_dishes` WHERE `order_id`="<< order_id;
    res = query.store();
    if (res)
    {


        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            wxString qty;
            qty << int(row["qty"]);
            wxString name = std2wx(std::string(row["name"]),wxConvUI);
            wxString price;
            price << double(row["price"]);
            price = addZero(price);
//           info << qty <<_("\t") << name << _("\t\t\t") << price << _("\n");
            infoVerse.Clear();
            infoVerse << qty;
            for(int t = infoVerse.Length(); t<4; ++t)
            {
                infoVerse << _T(" ");
            }
            infoVerse << name;

            for(int t = infoVerse.Length(); t<width-price.Length(); ++t)
            {
                infoVerse << _T(" ");
            }

            infoVerse << price <<_T("\n");

            info << infoVerse;

        }
        info << _T("\n");
        for(int t=0; t<width; ++t)
        {
            info << _T("-");
        }
        info << _T("\n");

        infoVerse.Clear();
        infoVerse << _T("          Net: ");
        for(int t = infoVerse.Length(); t<width-addZero(prices-taxes).Length(); ++t)
        {
            infoVerse << _T(" ");
        }
        infoVerse << addZero(prices-taxes) << _T("\n");
        info << infoVerse;
        infoVerse.Clear();

        infoVerse << _T("          Tax: ");
        for(int t = infoVerse.Length(); t<width-addZero(taxes).Length(); ++t)
        {
            infoVerse << _T(" ");
        }
        infoVerse << addZero(taxes) << _T("\n");
        info << infoVerse;
        infoVerse.Clear();

        infoVerse << _T("          Total: ");
        for(int t = infoVerse.Length(); t<width-addZero(prices).Length(); ++t)
        {
            infoVerse << _T(" ");
        }
        infoVerse << addZero(prices) << _T("\n");
        info << infoVerse;
        infoVerse.Clear();

        info << _T("\n");
        for(int t=0; t<width; ++t)
        {
            info << _T("-");
        }
        info << _T("\n");

        infoVerse << _T("          Paid: ");
        for(int t = infoVerse.Length(); t<width-addZero(given).Length(); ++t)
        {
            infoVerse << _T(" ");
        }
        infoVerse << addZero(given) << _T("\n");
        info << infoVerse;
        infoVerse.Clear();


        if(pay_type == 1)  //cash
        {
            info << _T("          Type: CASH\n");
            infoVerse << _T("          Change: ");
            for(int t = infoVerse.Length(); t<width-addZero(given-prices).Length(); ++t)
            {
                infoVerse << _T(" ");
            }
            infoVerse << addZero(given-prices) << _T("\n");
            info << infoVerse;
            infoVerse.Clear();
        }
        else if(pay_type == 2)
        {
            info << _T("          Type: CHARGE");
        }
        info << _T("\n\nServed by: ") << waiter_name << _T("\n");
        info << _T("id: ") << order_id << _T("\n");
        info << _T("Date: ") << tiemp.FormatDate();
    }

    return info;

}

wxString addSpaces(wxString toAdd, int width)
{
    int length = width - toAdd.Length();
    for(int t = 0; t<length; ++t)
    {
        toAdd << _T(" ");
    }

    return toAdd;
}

wxArrayString explode(wxString& toExplode)
{

    wxArrayString exploded;
    while(toExplode.Find(_T(":")) != toExplode.Length() && toExplode.Find(_T(":")) != -1)
    {
        int pos = toExplode.Find(_T(":"));
        int length = toExplode.Length();
        exploded.Add(toExplode.Mid(0,pos));
        toExplode = toExplode.Mid(pos+1,length - pos - 1);
    }
    return exploded;
}

wxString formatTicket(int order_id, mysqlpp::Connection* conn)
{

    wxString toRet;
    wxString waiter_name;
    wxString order_comment;
    wxDateTime tiemp;
    mysqlpp::Query query = conn->query();
    query << "SELECT * FROM `orders` WHERE `id`=" << order_id << " LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        mysqlpp::Row row = res.at(0);
        wxString timec = std2wx(std::string(row["time"]),wxConvUI);
        tiemp.ParseDateTime(timec.c_str());
        order_comment = std2wx(std::string(row["comment"]),wxConvUI);

        query << "SELECT `name` FROM `workers` WHERE `id`=" << int(row["waiter_id"]) << " LIMIT 1";
        res = query.store();
        row = res.at(0);
        waiter_name = std2wx(std::string(row["name"]), wxConvUI);
    }
    toRet << waiter_name << _("<br>") << tiemp.FormatTime() << _(" ") << tiemp.FormatDate()<< _("<br>");
    if(order_comment != _(""))
    {
        toRet << _("Order comment: <br><i>") << order_comment <<_("</i><br>");
    }

    query << "SELECT * FROM `orders_dishes` WHERE `order_id`="<< order_id;
    res = query.store();
    if (res)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            toRet << formatDish(conn, int(row["id"]));
        }
    }
    return toRet;

}



wxString formatDish(mysqlpp::Connection* conn, int dishId)
{
    bool kitchen = true;
    wxArrayString parts; //getting parts from mysql-query
    wxString title;
    wxString comment;
    wxString qty;
    mysqlpp::Query query = conn->query();
    query << "SELECT `orders_dishes`.`qty`,`orders_dishes`.`name`,`orders_dishes`.`comment`  \
     FROM `orders_dishes`,`orders` WHERE \
    `orders_dishes`.`id` = "<< dishId <<" AND `orders_dishes`.`order_id`=`orders`.`id` \
    AND `orders_dishes`.`kitchen` = 1";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        if(res.num_rows() > 0 )
        {
            mysqlpp::Row row = res.at(0);
            title = std2wx(std::string(row["name"]), wxConvUI);
            comment = std2wx(std::string(row["comment"]), wxConvUI);
            qty = std2wx(std::string(row["qty"]), wxConvUI);
        }
        else
        {
            kitchen = false;
        }
    }

    wxString toRet;

    if(kitchen)  //then we have to print something
    {
        query << "SELECT * FROM `orders_dishes_parts` WHERE `orders_dishes_id`=" << dishId;
        res = query.store();
        if (res)
        {
            if(res.num_rows() > 0)
            {
                mysqlpp::Row row;
                mysqlpp::StoreQueryResult::size_type i;
                for (i = 0; i < res.num_rows(); ++i)
                {
                    row = res[i];

                    wxString partNameToAdd = getPartName(conn, int(row["parts_id"]));
                    if(!bool(row["using"]))
                    {
                        partNameToAdd  = _("<b>NO</b> ") + partNameToAdd;
                    }
                    parts.Add(partNameToAdd);
                }
            }
        }




        toRet << _T("<b><font size=4>") << title << _T(" X ")<< qty <<_T("</b></font>");
        toRet << _T("<div align=right><table cellspacing=0 cellpadding=0 WIDTH=100%><tr><td>");

        for(int i = 0; i < parts.GetCount(); ++i)
        {
            toRet << _T("<br> * ") << parts[i];
        }


//toRet << _T("</td><td width = 50><a href=") << num << _T(":") << dishId << _T("></td></tr></table></div>");

        if(comment != _T(""))
        {
            toRet << _T("<font size=2><br align=left>Comment: <i>") << comment << _T("</i></font>");
        }
        toRet << _("<br>");
    }
    return toRet;

}

wxString getPartName(mysqlpp::Connection* conn, int partId)
{

    mysqlpp::Query query = conn->query();
    query << "SELECT * FROM `parts` WHERE `id`=" << partId;
    mysqlpp::StoreQueryResult res = query.store();
    wxString partName;
    if (res)
    {
        mysqlpp::Row row = res.at(0);
        partName = std2wx(std::string(row["name"]));

    }

    return partName;

}
