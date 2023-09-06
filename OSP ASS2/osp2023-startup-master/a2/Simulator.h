#ifndef SIMULATOR
#define SIMULATOR

#include "RR.h"
#include "FIFO.h"
#include "SJF.h"


class Simulator {
    public:

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


};

#endif