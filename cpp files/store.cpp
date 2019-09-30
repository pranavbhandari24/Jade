#include "../Headers/store.h"
#include <sstream>
#include <iostream>

Store::Store(std::string store_name) : _name{store_name} { }
std::string Store::name() {return _name;}

void Store::add_product(Product* product) {_products.push_back(product);}
int Store::number_of_products() {return _products.size();}
std::string Store::product_to_string(int product) {
   return _products[product]->to_string();
}
std::ostream& operator<<(std::ostream& ost, Store& store) {
    ost << "Store " << store._name << std::endl << std::endl;
    ost << "Products: " << std::endl;
    for (auto p : store._products) ost << "  " << p->to_string() << std::endl;
    return ost;
}

void Store::add_customer(Customer* customer)
{
    _customers.push_back(customer);
}

int Store::number_of_customers()
{
    return _customers.size();
}

std::string Store::customer_to_string(int i)
{
    return _customers[i]->to_string();
}

Product* Store::get_product(int product)
{
    return _products[product];
}

int Store::place_order(order _order, int customer)
{
    std::cout<<"\n\n"/*<<_order.order_to_string()*/<<"\n\nCustomer : "<<customer<<"\n\n";
    _orders[_order] = customer;
}

int Store::number_of_orders()
{
    return _orders.size();
}

std::string Store::order_to_string(int order_number)
{
    for(auto temp : _orders)
    {
        order o = (temp.first);
        if(order_number == o.order_number())
        {
            return o.order_to_string();
        }
    }
}

int Store::customer_number(int order_number)
{
    for(auto tem: _orders)
    {
        order o = (tem.first);
        if(order_number == o.order_number())
        {
            return (tem.second);
        }
    }
}

double Store::cash()
{
    for(auto tem: _orders)
    {
        order o = (tem.first);
        if(o.paid()==true)
            cash_register+= o.profit();
    }
}

void Store::pay_order(int order_number)
{
    std::map<order,int>::iterator it;
    for(auto tem: _orders)
    {
        order o = (tem.first);
        if(order_number == o.order_number())
        {
            order o2 = o;
            bool t = o2.pay();
            std::cout<<"\n\n"<<o2.order_to_string()<<"\n\n";
            
            if(t == false)
            {
                Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Error");
                dialog->set_secondary_text("Something went wrong. Check Again.", true);
                dialog->run();

                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();

                delete dialog;
                return;
            }
            int c = tem.second;
            it = _orders.find(o);
            _orders.erase(it);
            _orders[o2]=c;
            
        }
    }
}

bool Store::order_is_paid(int order_number)
{
    for(auto tem: _orders)
    {
        order o = (tem.first);
        if(order_number == o.order_number())
        {
            return o.paid();
        }
    }
}

void Store::fill_order(int order_number)
{
    std::map<order,int>::iterator it;
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            order o2 = o;
            bool t =o2.fill();
            if(t == false)
            {
                Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Error");
                dialog->set_secondary_text("Something went wrong. Check Again.", true);
                dialog->run();

                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();

                delete dialog;
                return;
            }
            int c = tem.second;
            it = _orders.find(o);
            _orders.erase(it);
            _orders[o2]=c;
        }
    }
}

bool Store::order_is_filled(int order_number)
{
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            return o.filled();
        }
    }
}

void Store::discard_order(int order_number)
{
    std::map<order,int>::iterator it;
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            order o2 = o;
            bool t= o2.discard();
            if(t == false)
            {
                Gtk::MessageDialog *dialog = new Gtk::MessageDialog("Error");
                dialog->set_secondary_text("Something went wrong. Check Again.", true);
                dialog->run();

                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();

                delete dialog;
                return;
            }
            int c = tem.second;
            it = _orders.find(o);
            _orders.erase(it);
            _orders[o2]=c;
        }
    }
}

bool Store::order_is_discarded(int order_number)
{
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            return o.discarded();
        }
    }    
}

bool Store::order_is_completed(int order_number)
{
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            return o.completed();
        }
    }  
}

bool Store::order_is_pending(int order_number)
{
    for(auto tem: _orders)
    {
        order o = tem.first;
        if(order_number == o.order_number())
        {
            return o.pending();
        }
    }    
}