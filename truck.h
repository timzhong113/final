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
    
  	unsigned int cargo[4];   // stock of the truck
    unsigned int totalSoda;   // total number of soda on the truck

  public:

    Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant, 
    	unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
    void action();

};


#endif
