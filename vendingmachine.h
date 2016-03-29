#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H


class VendingMachine {                // general vending machine

  protected:

    Printer &prt;
    NameServer &nameServer;
    unsigned int id;
    unsigned int sodaCost;
    unsigned int maxStockPerFlavour;
    unsigned int stock[4];

  public:
    enum Status { BUY, STOCK, FUNDS }; // purchase status: successful buy, out of stock, insufficient funds
    enum Flavours { BBC, CCS, RRB, JL };
    VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    virtual ~VendingMachine();        // necessary to trigger destructors in inherited classes
    virtual Status buy( Flavours flavour, WATCard *&card ); // YOU DEFINE Flavours   ///////////////////////////////////////////////
    virtual unsigned int cost();    // get cost
    virtual unsigned int getId();
    virtual unsigned int *inventory();
    virtual void restocked();
};

class VendingMachineCardEater : public VendingMachine { // specific vending machine
  public:
    VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    Status buy( Flavours flavour, WATCard *&card );
};

class VendingMachineOverCharger : public VendingMachine { // specific vending machine
  public:
    VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
    // member routines from VendingMachine
};

#endif
