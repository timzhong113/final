#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

class VendingMachine {                // general vending machine
  public:
    enum Status { BUY, STOCK, FUNDS }; // purchase status: successful buy, out of stock, insufficient funds
    VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    virtual ~VendingMachine();        // necessary to trigger destructors in inherited classes
    virtual Status buy( Flavours flavour, WATCard *&card ); // YOU DEFINE FLAVOURS
    virtual unsigned int cost();
    virtual unsigned int getId();
    virtual unsigned int *inventory();
    virtual void restocked();
};

class VendingMachineCardEater : public VendingMachine { // specific vending machine
  public:
    VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    // member routines from VendingMachine
};

class VendingMachineOverCharger : public VendingMachine { // specific vending machine
  public:
    VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    // member routines from VendingMachine
};

#endif
