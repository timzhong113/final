#ifndef NAMESERVER_H
#define NAMESERVER_H

class NameServer {

  protected:

  	Printer &prt;
  	unsigned int numVendingMachines;
  	unsigned int numStudents;
  	VendingMachine *machineList;

  public:

    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    void VMregister( VendingMachine *vendingmachine );
    VendingMachine *getMachine( unsigned int id );
    VendingMachine **getMachineList();
};

#endif
