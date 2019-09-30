#pragma once

#include <string>
#include <iostream>

class Customer
{
    std::string customer;
    std::string customer_phone;
    public:
    Customer(std::string _customer, std::string _custromer_phone);
    Customer();
    std::string to_string();
};