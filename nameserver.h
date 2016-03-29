#ifndef NAMESERVER_H
#define NAMESERVER_H

class VendingMachine;
class Printer;

class NameServer {

  protected:

    struct Distribution{
      unsigned int mIndex; // machineList index
      bool isDistributed;  // true if the machined is already ditributed
    };

  	Printer &prt;
  	unsigned int numVendingMachines;
  	unsigned int numStudents;
  	VendingMachine *machineList;
    Distribution *dtn;  // distribute vending machines to students //////////////////////

  public:

    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    ~NameServer();
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif

