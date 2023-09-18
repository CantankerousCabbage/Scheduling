#include "rr.h"

    rr::rr(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<time_type> quantum) 
    : Schedule(kernelSpace), quantum{quantum} {};
    rr::~rr(){};

    void rr::run(){
        
        this->printHeading();

        while (kernelSpace->size()){

            auto requiredTime = [](time_type tUsed, time_type burstTime ){return burstTime - tUsed;};
            
            shared_ptr<pcb> p = (*kernelSpace)[FRONT];

            //Remove process from queue
            vector<shared_ptr<pcb>>::iterator it;
            it = kernelSpace->begin();
            kernelSpace->erase(it);

            //Set time waiting
            p->setWaitTime();

            //Calculate time needed to complete burst 
            time_type timeNeeded = requiredTime(p->getTimeUsed(), p->getTotalTime());
            //Calculate time permitted 
            time_type timeAllowed = (timeNeeded > *quantum) ? *quantum : timeNeeded;
            
            bool complete = (timeAllowed == timeNeeded) ? true : false;
            //Set time used
            p->setTimeUsed(timeAllowed);
            //Increment total process time
            pcb::timeSinceArrival += timeAllowed;
            //Process complete register CPU departure time
            p->setLastTimeCPU(pcb::timeSinceArrival);

            if(!complete){
                (*kernelSpace).push_back(p);

            } else {
                //Output metrics ID. BurstTime. TT -time. TotalWait. Response
                this->lineFormat(
                    p->getID(), 
                    p->getTotalTime(), 
                    p->getTurnAroundTime(), 
                    p->getWaitTime(),
                    p->getResponseTime()
                );
            }
        };

        this->printAverage();
    

    }