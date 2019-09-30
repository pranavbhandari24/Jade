#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include <regex>


class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
        void message_dialog(std::string msg, std::string title);
    protected:
        void on_quit_click();            // Exit the program
        void on_view_all_click();        // View all products
        void on_view_customer_click();
        void on_view_orders_click();
        void on_create_coffee_click();   // Create a new coffee product
        void on_create_donut_click();    // Create a new donut product
        void on_create_order_click();
        void on_create_customer_click();
        void on_fill_click();
        void on_pay_click();
        void on_discard_click();
    private:
        Store _store;
        Gtk::Label *msg;                      // Status message display
        Gtk::Label *cash;
        Gtk::MenuItem *menuitem_new_coffee;   // Create -> Coffee
        Gtk::MenuItem *menuitem_new_donut;    // Create -> Donut
        void update_cash();
};
#endif 

