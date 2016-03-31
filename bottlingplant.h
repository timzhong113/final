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
    unsigned int totalSoda, numBBC, numCCS, numRRB, numJL;  // the number of soda produced
  	Truck *truck;

  public:

    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, 
        unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, 
        unsigned int timeBetweenShipments);  // constructor
    ~BottlingPlant();  // destructor
    void getShipment( unsigned int cargo[] );
    void action();

};


#endif
