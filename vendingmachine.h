#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "watcard.h"
class Printer;
class NameServer;


class VendingMachine {                // general vending machine

  protected:

    Printer &prt;
    NameServer &nameServer;
    unsigned int id;        // vending machine's id
    unsigned int sodaCost;  // cost to buy a bottle of soda
    unsigned int maxStockPerFlavour;
    unsigned int stock[4];  // store current stock of each kind of soda

  public:

    enum Status { BUY, STOCK, FUNDS };  // purchase status: successful buy,out of stock,insufficient funds
    enum Flavours { BBC, CCS, RRB, JL };    // soda flavours: Blue Black-Cherry, 
                                            //                Classical Cream-Soda,
                                            //                Rock Root-Beer, 
                                            //                Jazz Lime

    VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, 
                    unsigned int maxStockPerFlavour );  // construcor
    virtual ~VendingMachine();        // necessary to trigger destructors in inherited classes
    virtual Status buy( Flavours flavour, WATCard *&card ); // student call buy to buy a soda

    virtual unsigned int cost();    // get cost
    virtual unsigned int getId();
    virtual unsigned int *inventory();
    virtual void restocked();

};


class VendingMachineCardEater : public VendingMachine { // specific vending machine

  public:

    VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, 
                             unsigned int sodaCost, unsigned int maxStockPerFlavour);
    Status buy( Flavours flavour, WATCard *&card );

};


class VendingMachineOverCharger : public VendingMachine { // specific vending machine

  public:

    VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id,
                               unsigned int sodaCost, unsigned int maxStockPerFlavour);

};


#endif
