#ifndef BOTTLINGPLANT
#define BOTTLINGPLANT

class BottlingPlant {
  public:
    BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, unsigned int timeBetweenShipments );
    void getShipment( unsigned int cargo[] );
    void action();
};

#endif
