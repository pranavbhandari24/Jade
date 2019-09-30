#pragma once
#include <string>
#include <ostream>

class Product {
  public:
    Product(std::string name, double price, double cost);
    std::string name();
    virtual std::string to_string();
    double profit();
  protected:
    std::string _name;
    double _price;
    double _cost;
};
