#ifndef STUDENT_H
#define STUDENT_H

class Student {
  public:
    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id, unsigned int maxPurchases );
    void action();
};

#endif
