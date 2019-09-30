#include "../Headers/order.h"
#include <iostream>

int order::next_order_number = 1;
order::order()
{
    _order_number = next_order_number;
    next_order_number++;
    is_discarded=false;
    is_paid=false;
    is_filled=false;
}

order::order(const order &a): products(a.products) 
{
    next_order_number = a.next_order_number;
    _order_number = a._order_number;
    is_paid = a.is_paid;
    is_filled = a.is_filled;
    is_discarded = a.is_discarded;
}

int order::order_number() const
{
    return _order_number;
}

void order::add_product(Product* product)
{
    products.push_back(product);
}
bool order::operator<(const order& rhs) const
{
    if(_order_number<rhs.order_number())
        return true;
    else
        return false;
}

std::string order::order_to_string()
{
    std::string result="";
    if(completed())
        result = result + "(Completed)\n";
    else if(is_paid==true)
        result = result + "(Paid)\n";
    else if(filled())
        result = result + "(Filled)\n";
    else if(discarded())
        result = result + "(Discarded)\n";
    else if(completed())
        result = result + "(Completed)\n";
    else if(pending())
        result = result + "(Pending)\n";
    for(int i=0;i<products.size();i++)
    {
        result = result + products[i]->to_string()+ "\n";
    }
    return result;
}

bool order::paid()
{
    return is_paid;
}

bool order::pay()
{
    if((is_paid== false) &&  (is_discarded== false))
    {
         is_paid = true;
         return is_paid;
    }
    else
        return false;
}

bool order::filled()
{
    return is_filled;
}

bool order::fill()
{
    if((is_filled== false) && (is_discarded== false))
    {
        is_filled=true;
        return is_filled;
    }
    else
        return false;
}

bool order::discarded()
{
    return is_discarded;
}

bool order::discard()
{
    if((is_discarded== false) && (completed()== false))
    {
        is_discarded = true;
        return is_discarded;
    }
    else
        return false;
}

double order::profit()
{
    double sum =0;
    for(int i=0;i<products.size();i++)
    {
        sum+= products[i]->profit();
    }
    return sum;
}

bool order::completed()
{
    if((is_paid== true) && (is_filled== true))
        return true;
    else   
        return false;
}

bool order::pending()
{
    if(((is_paid== false) && (is_discarded== false)) && (is_filled== false))
        return true;
    else
        return false;
}