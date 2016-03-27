#include "vendingmachine.h"

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );

virtual VendingMachine::~VendingMachine();        // necessary to trigger destructors in inherited classes

virtual Status VendingMachine::buy( Flavours flavour, WATCard *&card ); // YOU DEFINE FLAVOURS

virtual unsigned int VendingMachine::cost();

virtual unsigned int VendingMachine::getId();

virtual unsigned int *VendingMachine::inventory();

virtual void VendingMachine::restocked();

VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );

VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer, unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour );
