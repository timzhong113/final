#ifndef TRUCK_H
#define TRUCK_H

class Truck {
  public:
    Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant, unsigned int numVendingMachines, unsigned int maxStockPerFlavour );
    void action();
};

#endif
