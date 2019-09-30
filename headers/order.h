#pragma once
#include "product.h"
#include <vector>

class order
{
    static int next_order_number;
    int _order_number;
    bool is_paid;
    bool is_filled;
    bool is_discarded;
    std::vector <Product*> products;
    public:
    order();
    order(const order &a);
    int order_number() const;
    void add_product(Product* product);
    std::string order_to_string();
    bool paid();
    bool pay();
    bool filled();
    bool fill();
    bool discarded();
    bool discard();
    bool pending();
    bool completed();
    double profit();
    bool operator<(const order& rhs) const;
};