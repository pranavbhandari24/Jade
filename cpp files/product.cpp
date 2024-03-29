#include "../Headers/product.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Product::Product(std::string name, double price, double cost)
    : _name{name}, _price{price}, _cost{cost} { }

std::string Product::name() {return _name;}

std::string Product::to_string() {
    std::ostringstream oss;
    oss << _name << std::fixed << std::setprecision(2) << " ($" << _price << " / $" << _cost << ')';
    return oss.str();
}

double Product::profit()
{
    return _price - _cost;
}
