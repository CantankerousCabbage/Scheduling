#include "fifo.h"


    fifo::fifo(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete) : Schedule(kernelSpace, complete) {}
    fifo::~fifo(){}

    void fifo::run(){
        
        this->printHeading();

        for(unsigned i = 0; i < kernelSpace->size(); i++){
            shared_ptr<pcb> p = (*kernelSpace)[i];
            //Set time waiting
            p->setWaitTime();
            //Set time used
            p->setTimeUsed(p->getTotalTime());
            //Increment total process time
            pcb::timeSinceArrival += p->getTotalTime();
            //Process complete register CPU departure time
            p->setLastTimeCPU(pcb::timeSinceArrival);

            //Output metrics ID. BurstTime. TT -time. TotalWait. Response
            this->lineFormat(
                p->getID(), 
                p->getTotalTime(), 
                p->getTurnAroundTime(), 
                p->getWaitTime(),
                p->getResponseTime()
            );
        };

        this->printAverage();
    

    }