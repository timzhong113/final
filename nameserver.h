#ifndef NAMESERVER_H
#define NAMESERVER_H

class NameServer {

  protected:

    struct Distribution{
      unsigned int mid; // machine id
      bool isDistributed;  // true if the machined is already ditributed
    };

  	Printer &prt;
  	unsigned int numVendingMachines;
  	unsigned int numStudents;
  	VendingMachine *machineList;
    Distribution dtn[numStudents];  // distribute vending machines to students

  public:

    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif
