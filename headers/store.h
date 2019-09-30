#pragma once
#include "product.h"
#include "customer.h"
#include "order.h"
#include <map>
#include <vector>
#include <gtkmm.h>

class Store {
  public:
    Store(std::string store_name);
    std::string name(); // Returns the store name
    double cash();
    void add_product(Product* product); // Add a new product to stock
    int number_of_products(); // # of products defined
    Product* get_product(int product);
    std::string product_to_string(int product); // string version of a product
    void add_customer(Customer* customer);
    int number_of_customers();
    std::string customer_to_string(int i);
    int place_order(order _order, int customer);
    int number_of_orders();
    std::string order_to_string(int order_number);
    void pay_order(int order_number);
    bool order_is_paid(int order_number);
    void fill_order(int order_number);
    bool order_is_filled(int order_number);
    void discard_order(int order_number);
    bool order_is_discarded(int order_number);
    bool order_is_completed(int order_number);
    bool order_is_pending(int order_number);
    //order_pair& find_order_pair(int order_number);
    int customer_number(int order_number);
    friend std::ostream& operator<<(std::ostream& ost, Store& store); 
  private:
    std::string _name;
    double cash_register;
    std::vector<Product*> _products;
    std::vector<Customer*> _customers;
    std::map<order,int> _orders; 
};
