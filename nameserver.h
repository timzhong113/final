#ifndef NAMESERVER_H
#define NAMESERVER_H

class VendingMachine;
class Printer;

class NameServer {

  protected:

    struct Distribution{
      unsigned int sid;    // student id
      unsigned int mIndex; // machineList index
      //bool isDistributed;  // true if the machined is already ditributed
    };

  	Printer &prt;
  	unsigned int numVendingMachines;
  	unsigned int numStudents;
    unsigned int numStudentsRegister;

  	VendingMachine **machineList;  // store vending machines in register order
    Distribution *dtn;  // store distribution of vending machines

  public:

    NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents );
    ~NameServer();

    void VMregister( VendingMachine *vendingmachine );  // register the vending machine to name server
    VendingMachine *getMachine( unsigned int id );  // student call getMachine to obtain a new machine
    VendingMachine **getMachineList();

};

#endif
