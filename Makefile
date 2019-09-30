#Makefile

CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: customer.o order.o product.o donut.o java.o store.o mainwin.o main.o
	$(CXX) $(CXXFLAGS) -o main customer.o order.o main.o product.o donut.o java.o store.o mainwin.o $(GTKFLAGS)

customer.o: cpp\ files/customer.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/customer.cpp $(GTKFLAGS)

order.o: cpp\ files/order.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/order.cpp $(GTKFLAGS)

main.o: cpp\ files/main.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/main.cpp $(GTKFLAGS)

product.o: cpp\ files/product.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/product.cpp $(GTKFLAGS)

donut.o: cpp\ files/donut.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/donut.cpp $(GTKFLAGS)

java.o: cpp\ files/java.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/java.cpp $(GTKFLAGS)

store.o: cpp\ files/store.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/store.cpp $(GTKFLAGS)

mainwin.o: cpp\ files/mainwin.cpp Headers/*.h
	$(CXX) $(CXXFLAGS) -c cpp\ files/mainwin.cpp $(GTKFLAGS)




clean: 
	rm -f *.o headers/*.gch main