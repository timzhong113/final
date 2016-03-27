#include "bottlingplant.h"

BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer, unsigned int numVendingMachines, unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, unsigned int timeBetweenShipments );

void BottlingPlant::getShipment( unsigned int cargo[] );

void BottlingPlant::action();
