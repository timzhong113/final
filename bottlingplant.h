#ifndef BOTTLINGPLANT
#define BOTTLINGPLANT

class BottlingPlant {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	unsigned int numVendingMachines;
  	unsigned int maxShippedPerFlavour;
  	unsigned int maxStockPerFlavour;
  	unsigned int timeBetweenShipments;
  	Truck truck;

  public:

    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, 
    	unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, 
    	unsigned int timeBetweenShipments );	// call PRNG for each flavours
    void getShipment( unsigned int cargo[] );
    void action();

};

#endif
