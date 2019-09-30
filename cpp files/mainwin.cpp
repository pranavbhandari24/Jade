#include "../Headers/mainwin.h"
#include "../Headers/java.h"
#include "../Headers/donut.h"
#include <ostream>
#include <iostream>

Mainwin::Mainwin() : _store{Store{"JADE"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_title("Java and Donut Express (JADE)");
    set_default_size(800, 600);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         A L L   P R O D U C T S
    // Append All Products to the File menu
    Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
    menuitem_all_products->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    viewmenu->append(*menuitem_all_products);

    //Customer view
    Gtk::MenuItem *menuitem_all_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_all_customers->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_customer_click));
    viewmenu->append(*menuitem_all_customers);

    //Orders view
    Gtk::MenuItem *menuitem_all_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menuitem_all_orders->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
    viewmenu->append(*menuitem_all_orders);

    //     C R E A T E   C O F F E E
    // Create a new coffee menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //           N E W   C O F F E E
    // Append New Coffee to the Create menu
    menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
    menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
    createmenu->append(*menuitem_new_coffee);

    //           N E W   D O N U T
    // Append New Donut to the Create menu
    menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
    menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
    createmenu->append(*menuitem_new_donut);

    //NEW Customer
    Gtk::MenuItem *menuitem_new_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_new_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
    createmenu->append(*menuitem_new_customer);

    //New Order
    Gtk::MenuItem *menuitem_new_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_new_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_new_order);

    // Create a Process menu and add to the menu bar
    Gtk::MenuItem *menuitem_process = Gtk::manage(new Gtk::MenuItem("_Process", true));
    menubar->append(*menuitem_process);
    Gtk::Menu *processmenu = Gtk::manage(new Gtk::Menu());
    menuitem_process->set_submenu(*processmenu);

    //Pay
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_pay = Gtk::manage(new Gtk::MenuItem("_Pay", true));
    menuitem_pay->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_pay_click));
    processmenu->append(*menuitem_pay);

    //Fill
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_fill = Gtk::manage(new Gtk::MenuItem("_Fill", true));
    menuitem_fill->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_fill_click));
    processmenu->append(*menuitem_fill);

    //Discard
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_discard = Gtk::manage(new Gtk::MenuItem("_Discard", true));
    menuitem_discard->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_discard_click));
    processmenu->append(*menuitem_discard);

    //ToolBar
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //Images
    Gtk::Image *button_all_products = Gtk::manage(new Gtk::Image("Images/all_products.png"));
    Gtk::Image *button_add_donut = Gtk::manage(new Gtk::Image("Images/add_donut.png"));
    Gtk::Image *button_add_java = Gtk::manage(new Gtk::Image("Images/add_java.png"));
    Gtk::Image *button_add_customer = Gtk::manage(new Gtk::Image("Images/add_customer.png"));
    Gtk::Image *button_customers = Gtk::manage(new Gtk::Image("Images/customers.png"));
    Gtk::Image *button_orders = Gtk::manage(new Gtk::Image("Images/orders.png"));
    Gtk::Image *button_add_order = Gtk::manage(new Gtk::Image("Images/add_order.png"));
    Gtk::Image *button_pay = Gtk::manage(new Gtk::Image("Images/customers.png"));
    Gtk::Image *button_fill = Gtk::manage(new Gtk::Image("Images/orders.png"));
    Gtk::Image *button_discard = Gtk::manage(new Gtk::Image("Images/add_order.png"));

    //Add Donut
    Gtk::ToolButton *add_donut = Gtk::manage(new Gtk::ToolButton(*button_add_donut));
    add_donut->set_tooltip_markup("Add Donuts");
    add_donut->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_create_donut_click));
    toolbar->append(*add_donut);

    //Add Coffee
    Gtk::ToolButton *add_coffee = Gtk::manage(new Gtk::ToolButton(*button_add_java));
    add_coffee->set_tooltip_markup("Add Coffee");
    add_coffee->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_create_coffee_click));
    toolbar->append(*add_coffee);

    //Add Order
    Gtk::ToolButton *add_order = Gtk::manage(new Gtk::ToolButton(*button_add_order));
    add_order->set_tooltip_markup("Add Order");
    add_order->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_create_order_click));
    toolbar->append(*add_order);

    //Pay
    Gtk::ToolButton *pay_order = Gtk::manage(new Gtk::ToolButton(*button_pay));
    pay_order->set_tooltip_markup("Pay");
    pay_order->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_pay_click));
    toolbar->append(*pay_order);

    //Fill
    Gtk::ToolButton *fill_order = Gtk::manage(new Gtk::ToolButton(*button_fill));
    fill_order->set_tooltip_markup("Fill");
    fill_order->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_fill_click));
    toolbar->append(*fill_order);

    //Discard
    Gtk::ToolButton *discard_order = Gtk::manage(new Gtk::ToolButton(*button_discard));
    discard_order->set_tooltip_markup("Discard Order");
    discard_order->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_discard_click));
    toolbar->append(*discard_order);

    //All Products
    Gtk::ToolButton *all_products = Gtk::manage(new Gtk::ToolButton(*button_all_products));
    all_products->set_tooltip_markup("View All Products");
    all_products->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_view_all_click));
    toolbar->append(*all_products);

    //All Orders
    Gtk::ToolButton *all_orders = Gtk::manage(new Gtk::ToolButton(*button_orders));
    all_orders->set_tooltip_markup("View All Orders");
    all_orders->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_view_orders_click));
    toolbar->append(*all_orders);

    //Add Customer
    Gtk::ToolButton *add_customer = Gtk::manage(new Gtk::ToolButton(*button_add_customer));
    add_customer->set_tooltip_markup("Add Customer");
    add_customer->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_create_customer_click));
    toolbar->append(*add_customer);

    //All Customers
    Gtk::ToolButton *all_customers = Gtk::manage(new Gtk::ToolButton(*button_customers));
    all_customers->set_tooltip_markup("View all Customers");
    all_customers->signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_view_customer_click));
    toolbar->append(*all_customers);   



    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    cash = Gtk::manage(new Gtk::Label());
    cash->set_hexpand(true);
    vbox->add(*msg);
    vbox->add(*cash);

    // Make the box and everything in it visible
    vbox->show_all();
}

void Mainwin::message_dialog(std::string msg, std::string title) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::update_cash()
{
    cash->set_text("$"+std::to_string(_store.cash()));
}

void Mainwin::on_view_orders_click()
{
    bool temp = true;
    int result,n;
    std::string res= ""; 
    while(temp)
    {
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog);
        dialog->set_title("Select Order");
        Gtk::Label *label = Gtk::manage(new Gtk::Label(res));
        dialog->get_content_area()->pack_start(*label);
        label->show();

        Gtk::HBox b_order;
        Gtk::Label l_name{"Order: "};
        l_name.set_width_chars(15);
        b_order.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_order;
        c_order.set_size_request(160);
        for(int i=1;i<=_store.number_of_orders();i++)
        {
            c_order.append(std::to_string(i));
        }

        b_order.pack_start(c_order, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);

        dialog->add_button("Close", 0);
        dialog->add_button("Show", 1);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result == 0)
            temp = false;
        else
        {
            n = c_order.get_active_row_number();
            res = "Order #" +std::to_string(n+1)+"\n" +_store.order_to_string(n+1);
            int number = _store.customer_number(n+1);
            std::cout<<"\n\nCustomer : "<<number<<"\n\n"<<"Row: "<<n<<"\n\n";
            res = res + _store.customer_to_string(number);
            
        }
    }

}


void Mainwin::on_create_order_click()
{
    bool temp = true;
    int result,n;
    order o;
    std::cout<<"\n\n\nCame here\n\n\n";
    while(temp)
    {
        std::string o_num = "Order #";
        std::string p;
        

        o_num = o_num + std::to_string(o.order_number());
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
        dialog->set_title("Create Order");

        Gtk::Label *label = Gtk::manage(new Gtk::Label(o_num));
        dialog->get_content_area()->pack_start(*label);
        label->show();

        p= o.order_to_string();
        Gtk::Label *label2 = Gtk::manage(new Gtk::Label(p));
        dialog->get_content_area()->pack_start(*label2);
        label->show();
        
        Gtk::HBox b_prod;
        Gtk::ComboBoxText c_prod;
        c_prod.set_size_request(160);
        for(int i=0;i<_store.number_of_products();i++)
        {
            c_prod.append(_store.product_to_string(i));
        }

        b_prod.pack_start(c_prod, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_prod, Gtk::PACK_SHRINK);

        dialog->add_button("Cancel", 0);
        dialog->add_button("Add", 1);
        dialog->add_button("Next",2);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result != 0)
        {
            n = c_prod.get_active_row_number();
            o.add_product(_store.get_product(n));
        }
        if(result!=1)
            temp= false;
    }
    if(result!=0)
    {
        int res,n2;
        Gtk::Dialog *Customer_dialog = Gtk::manage(new Gtk::Dialog);
        Customer_dialog->set_title("Select Customer");

        Gtk::HBox b_cust;
        Gtk::ComboBoxText c_cust;
        c_cust.set_size_request(160);
        for(int i=0;i<_store.number_of_customers();i++)
        {
            c_cust.append(_store.customer_to_string(i));
        }
        
        b_cust.pack_start(c_cust, Gtk::PACK_SHRINK);
        Customer_dialog->get_vbox()->pack_start(b_cust, Gtk::PACK_SHRINK);
        Customer_dialog->add_button("Cancel", 0);
        Customer_dialog->add_button("Place Order", 1);
        Customer_dialog->show_all();
        res = Customer_dialog->run();

        Customer_dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(res == 1)
        {
            n2 = c_cust.get_active_row_number();
            _store.place_order(o,n2);
        }
    }
}
void Mainwin::on_view_all_click() { // View all products
   std::ostringstream oss;
   oss << _store << std::endl;
   Gtk::MessageDialog d{*this, oss.str()};
   int result = d.run();
}


void Mainwin::on_create_coffee_click() { // Create a new coffee product
    int darkness;
    double price;
    double cost;
    std::string name;


    Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
    dialog->set_title("Create Coffee");

    //NAME
    Gtk::HBox b_name;
    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    //Price
    Gtk::HBox b_price;
    Gtk::Label l_price{"Price: "};
    l_price.set_width_chars(15);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(50);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

    //Cost
    Gtk::HBox b_cost;
    Gtk::Label l_cost{"Cost: "};
    l_cost.set_width_chars(15);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(50);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    //Darkness
    Gtk::HBox b_coffee;
    Gtk::Label l_coffee{"Darkness (1-5): "};
    l_coffee.set_width_chars(15);
    b_coffee.pack_start(l_coffee, Gtk::PACK_SHRINK);

    Gtk::Entry e_coffee;
    e_coffee.set_max_length(50);
    b_coffee.pack_start(e_coffee, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_coffee, Gtk::PACK_SHRINK);

                
    
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("Next", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    
    

    if (result == 1)
    {
        darkness = std::stoi(e_coffee.get_text());
        cost = std::stoi(e_cost.get_text());
        price = std::stoi(e_price.get_text());
        name = e_name.get_text();
        Java* c = new Java{name, price, cost, darkness};
        int result;
        bool temp = true;
        while(temp)
        {
            int n;
            Gtk::Dialog *Shot_dialog = Gtk::manage(new Gtk::Dialog);
            Shot_dialog->set_title("Add Shots");
            
            

            Gtk::HBox b_shot;
            Gtk::ComboBoxText c_shot;
            c_shot.set_size_request(160);
            c_shot.append("None");
            c_shot.append("Chocolate");
            c_shot.append("Vanilla");
            c_shot.append("Peppermint");
            c_shot.append("Hazelnut");
            b_shot.pack_start(c_shot, Gtk::PACK_SHRINK);
            Shot_dialog->get_vbox()->pack_start(b_shot, Gtk::PACK_SHRINK);
            
            //Text
            Gtk::HBox b_label;
            Gtk::Label l{c->to_string()};
            l.set_width_chars(15);
            b_label.pack_start(l, Gtk::PACK_SHRINK);
            Shot_dialog->get_vbox()->pack_start(b_label, Gtk::PACK_SHRINK);

            

            Shot_dialog->add_button("Cancel", 0);
            Shot_dialog->add_button("Create", 1);
            Shot_dialog->add_button("Add",2);
            Shot_dialog->show_all();
            result = Shot_dialog->run();

            Shot_dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            if(result!= 2)
                temp = false;
            if(result!= 0)
            {   
                n = c_shot.get_active_row_number();
                c->add_shot((Shot)n);
            }
        }
        if(result == 1)
        {
            _store.add_product(c);
        }
    }
}

void Mainwin::on_create_donut_click() { // Create a new donut product




   int fillingnum,frostingnum,sprinklesnum;
   bool sprinkles;
    double price;
    double cost;
    std::string name;
    
    Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
    dialog->set_title("Create Donut");

    //NAME
    Gtk::HBox b_name;
    Gtk::Label l_name{"Name: "};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    //Price
    Gtk::HBox b_price;
    Gtk::Label l_price{"Price: "};
    l_price.set_width_chars(15);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(50);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

    //Cost
    Gtk::HBox b_cost;
    Gtk::Label l_cost{"Cost: "};
    l_cost.set_width_chars(15);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(50);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    // Frosting
    Gtk::HBox b_frosting;
    Gtk::Label l_frosting{"Frosting:"};
    l_frosting.set_width_chars(15);
    b_frosting.pack_start(l_frosting, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_frosting;
    c_frosting.set_size_request(160);
    c_frosting.append("Unfrosted");
    c_frosting.append("Chocolate_top");
    c_frosting.append("Vanilla_top");
    c_frosting.append("Pink_top");
    b_frosting.pack_start(c_frosting, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_frosting, Gtk::PACK_SHRINK);
                
    // Filling
    Gtk::HBox b_filling;
    Gtk::Label l_filling{"Filling:"};
    l_filling.set_width_chars(15);
    b_filling.pack_start(l_filling, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_filling;
    c_filling.set_size_request(160);
    c_filling.append("Unfilled");
    c_filling.append("Creme");
    c_filling.append("Bavarian");
    c_filling.append("Strawberry");
    b_filling.pack_start(c_filling, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_filling, Gtk::PACK_SHRINK);

    //Sprinkles
    Gtk::HBox b_sprinkles;
    Gtk::Label l_sprinkles{"Sprinkles:"};
    l_sprinkles.set_width_chars(15);
    b_sprinkles.pack_start(l_sprinkles, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_sprinkles;
    c_sprinkles.set_size_request(160);
    c_sprinkles.append("Yes");
    c_sprinkles.append("No");
    b_sprinkles.pack_start(c_sprinkles, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_sprinkles, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->show_all();
    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();


    if (result == 1)
    {
        name = e_name.get_text();
        cost = std::stoi(e_cost.get_text());
        price = std::stoi(e_price.get_text());
        frostingnum = c_frosting.get_active_row_number();
        fillingnum = c_filling.get_active_row_number();
        sprinklesnum = c_sprinkles.get_active_row_number();
        if(sprinklesnum == 1)
            sprinkles = true;
        else
            sprinkles = false;
        Donut *d = new Donut{name,price, cost,(Frosting)frostingnum,sprinkles,(Filling)fillingnum};
         _store.add_product(d);
    }
}

void Mainwin::on_create_customer_click()
{
    std::string C="";
    std::string C_phone="";
    std::regex phone{"([(]?\\d{3,3}[-|[)])?\\d{3,3}-\\d{4,4}"};
    bool temp = true;
    while(temp)
    {
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
        dialog->set_title("Create Customer");

        Gtk::HBox b_customer;
        Gtk::Label l_customer{"Name: "};
        l_customer.set_width_chars(15);
        b_customer.pack_start(l_customer, Gtk::PACK_SHRINK);

        Gtk::Entry e_customer;
        e_customer.set_max_length(50);
        e_customer.set_text(C);
        b_customer.pack_start(e_customer, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_customer, Gtk::PACK_SHRINK);

        Gtk::HBox b_customer_phone;
        Gtk::Label l_customer_phone{"Phone: "};
        l_customer_phone.set_width_chars(15);
        b_customer_phone.pack_start(l_customer_phone, Gtk::PACK_SHRINK);

        Gtk::Entry e_customer_phone;
        e_customer_phone.set_max_length(50);
        e_customer_phone.set_text(C_phone);
        b_customer_phone.pack_start(e_customer_phone, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_customer_phone, Gtk::PACK_SHRINK);

        // Show dialog
        dialog->add_button("Cancel", 0);
        dialog->add_button("OK", 1);
        dialog->show_all();
        int result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result == 1)
        {
            C = e_customer.get_text();
            C_phone = e_customer_phone.get_text();
            if(std::regex_match(C_phone,phone))
                temp = false;
            else 
                C_phone = "###Invalid###";
        }
        else
            temp = false;
    }
    Customer* c = new Customer{C,C_phone};
    _store.add_customer(c);
}

void Mainwin::on_view_customer_click()
{
    std::string result = "";
    for(int i=0; i<_store.number_of_customers();i++)
    {
        result = result + _store.customer_to_string(i) + "\n";
    }
    message_dialog(result,"All Customers");
}

void Mainwin::on_quit_click() {         // Exit the program
    close();
}

void Mainwin::on_pay_click()
{
    bool temp = true;
    int result,n;
    std::string res= ""; 
    while(temp)
    {
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog);
        dialog->set_title("Select Order");
        Gtk::Label *label = Gtk::manage(new Gtk::Label(res));
        dialog->get_content_area()->pack_start(*label);
        label->show();

        Gtk::HBox b_order;
        Gtk::Label l_name{"Order: "};
        l_name.set_width_chars(15);
        b_order.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_order;
        c_order.set_size_request(160);
        for(int i=1;i<=_store.number_of_orders();i++)
        {
            c_order.append(std::to_string(i));
        }

        b_order.pack_start(c_order, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);

        dialog->add_button("Close", 0);
        dialog->add_button("Show", 1);
        dialog->add_button("Pay",2);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result == 0)
            temp = false;
        else
        {
            n = c_order.get_active_row_number();
            if(result == 2)
                _store.pay_order(n+1);
            res = "Order #" +std::to_string(n+1) +" "+_store.order_to_string(n+1);
            int number = _store.customer_number(n+1);
            std::cout<<"\n\nCustomer : "<<number<<"\n\n"<<"Row: "<<n<<"\n\n";
            res = res + _store.customer_to_string(number);            
        }
    }
    update_cash();
}

void Mainwin::on_fill_click()
{
    bool temp = true;
    int result,n;
    std::string res= ""; 
    while(temp)
    {
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog);
        dialog->set_title("Select Order");
        Gtk::Label *label = Gtk::manage(new Gtk::Label(res));
        dialog->get_content_area()->pack_start(*label);
        label->show();

        Gtk::HBox b_order;
        Gtk::Label l_name{"Order: "};
        l_name.set_width_chars(15);
        b_order.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_order;
        c_order.set_size_request(160);
        for(int i=1;i<=_store.number_of_orders();i++)
        {
            c_order.append(std::to_string(i));
        }

        b_order.pack_start(c_order, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);

        dialog->add_button("Close", 0);
        dialog->add_button("Show", 1);
        dialog->add_button("Fill",2);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result == 0)
            temp = false;
        else
        {
            n = c_order.get_active_row_number();
            if(result == 2)
                _store.fill_order(n+1);
            res = "Order #" +std::to_string(n+1) +" "+_store.order_to_string(n+1);
            int number = _store.customer_number(n+1);
            std::cout<<"\n\nCustomer : "<<number<<"\n\n"<<"Row: "<<n<<"\n\n";
            res = res + _store.customer_to_string(number);            
        }
    }

}

void Mainwin::on_discard_click()
{
    bool temp = true;
    int result,n;
    std::string res= ""; 
    while(temp)
    {
        Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog);
        dialog->set_title("Select Order");
        Gtk::Label *label = Gtk::manage(new Gtk::Label(res));
        dialog->get_content_area()->pack_start(*label);
        label->show();

        Gtk::HBox b_order;
        Gtk::Label l_name{"Order: "};
        l_name.set_width_chars(15);
        b_order.pack_start(l_name, Gtk::PACK_SHRINK);

        Gtk::ComboBoxText c_order;
        c_order.set_size_request(160);
        for(int i=1;i<=_store.number_of_orders();i++)
        {
            c_order.append(std::to_string(i));
        }

        b_order.pack_start(c_order, Gtk::PACK_SHRINK);
        dialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);

        dialog->add_button("Close", 0);
        dialog->add_button("Show", 1);
        dialog->add_button("Discard",2);
        dialog->show_all();
        result = dialog->run();

        dialog->close();
        while (Gtk::Main::events_pending())  Gtk::Main::iteration();
        if(result == 0)
            temp = false;
        else
        {
            n = c_order.get_active_row_number();
            if(result == 2)
                _store.discard_order(n+1);
            res = "Order #" +std::to_string(n+1) +" "+_store.order_to_string(n+1);
            int number = _store.customer_number(n+1);
            std::cout<<"\n\nCustomer : "<<number<<"\n\n"<<"Row: "<<n<<"\n\n";
            res = res + _store.customer_to_string(number);            
        }
    }

}