#ifndef SIMULATOR
#define SIMULATOR

#define FIFO "./fifo"
#define SJF "./sjf"
#define RR "./rr"

#include "rr.h"
#include "fifo.h"
#include "sjf.h"
#include "pcb.h"

#include <string>
#include <memory>
#include <vector>

using std::string;
using std::make_unique;
using std::unique_ptr;
using std::shared_ptr;
using std::vector;


class Simulator {
    public:

        Simulator(string& policy, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace);
        ~Simulator();

        /*
        * Calculates average turna around time
        */
       void runSchedule();
        /*
        * Calculates average turna around time
        */
        double calculateTurnAround();

        /*
        * Calculates average wait time
        */
        double calculateWait();

        /*
        * Calculates average response time
        */
        double calculateResponse();

    private:
        unique_ptr<Schedule> policy;
        shared_ptr<vector<shared_ptr<pcb>>> kernelSpace;

};

#endif