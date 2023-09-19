#ifndef SHORTESTJOBFIRST
#define SHORTESTJOBFIRST

#include "Schedule.h"

class sjf : public Schedule {
    public:

    sjf(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete);
    ~sjf();

    virtual void run();

    void sortQueue();

    void printTest();


};

#endif