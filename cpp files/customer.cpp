#include "../Headers/customer.h"

Customer::Customer(std::string _customer, std::string _custromer_phone)
{
    customer = _customer;
    customer_phone = _custromer_phone;
}

Customer::Customer()
{
    customer = " ";
    customer_phone = " ";
}
std::string Customer::to_string()
{
    return customer + " , " + customer_phone;
}
