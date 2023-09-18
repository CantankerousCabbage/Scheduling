#include "sjf.h"

    sjf::sjf(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace) : Schedule(kernelSpace){};
    sjf::~sjf(){};

    void sjf::run(){
        // this->printHeading();

        // for(unsigned i = 0; i < kernelSpace->size(); i++){
        //     shared_ptr<pcb> p = (*kernelSpace)[i];
        //     //Set time waiting
        //     p->setWaitTime();
        //     //Set time used
        //     p->setTimeUsed(p->getTotalTime());
        //     //Increment total process time
        //     pcb::timeSinceArrival += p->getTotalTime();
        //     //Process complete register CPU departure time
        //     p->setLastTimeCPU(pcb::timeSinceArrival);

        //     //Output metrics ID. BurstTime. TT -time. TotalWait. Response
        //     this->lineFormat(
        //         p->getID(), 
        //         p->getTotalTime(), 
        //         p->getTurnAroundTime(), 
        //         p->getWaitTime(),
        //         p->getResponseTime()
        //     );
        // };

        // this->printAverage();

        this->printTest();
        this->sortQueue();
        this->printTest();
    };

void sjf::sortQueue(){
    vector<shared_ptr<pcb>> sortedKernel;

    shared_ptr<pcb> temp;
    for(unsigned i = 0; i < kernelSpace->size(); i++){
        shared_ptr<pcb> c1 = (*kernelSpace)[i];
        
        unsigned index = i;
        for(unsigned j = i + 1; j < kernelSpace->size(); j++){
            shared_ptr<pcb> c2 = (*kernelSpace)[j];

            
            if(c2->getTotalTime() < c1->getTotalTime()){
                index = j;
            }
            
        }

        temp = (*kernelSpace)[i];
        (*kernelSpace)[i] = (*kernelSpace)[index];
        (*kernelSpace)[index] = temp;

    }
}

void sjf::printTest(){

    for(unsigned i = 0; i < kernelSpace->size(); i++){
        std::cout << ((*kernelSpace)[i])->getTotalTime() << "\n";

    }
    std::cout << std::endl;
}

