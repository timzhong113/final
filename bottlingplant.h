#ifndef BOTTLINGPLANT
#define BOTTLINGPLANT

class Printer;
class NameServer;
class Truck;

class BottlingPlant {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	unsigned int numVendingMachines;
  	unsigned int maxShippedPerFlavour;
  	unsigned int maxStockPerFlavour;
  	unsigned int timeBetweenShipments;
    unsigned int totalSoda, numBBC, numCCS, numRRB, numJL;
  	Truck *truck;

  public:

    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, 
    	unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, 
    	unsigned int timeBetweenShipments );	// call PRNG for each flavours
    ~BottlingPlant();
    void getShipment( unsigned int cargo[] );
    void action();

};

#endif

