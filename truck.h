#ifndef TRUCK_H
#define TRUCK_H

class Printer;
class NameServer;
class BottlingPlant;

class Truck {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	BottlingPlant &plant;
  	unsigned int numVendingMachines;
  	unsigned int maxStockPerFlavour;
  	unsigned int cargo[4];
    unsigned int totalSoda;

  public:
    Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant, 
    	unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
    void action();
};

#endif

