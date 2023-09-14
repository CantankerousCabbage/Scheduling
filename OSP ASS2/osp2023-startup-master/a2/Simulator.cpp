#include "Simulator.h"

//     #define FIFO "fifo"
// #define SJF "sjf"
// #define RR "rr"


    Simulator::Simulator(string& policy, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace) : kernelSpace{kernelSpace} {
        if(policy == FIFO){
            this->policy = make_unique<fifo>();
        } 
        else if(policy == SJF){
            this->policy = make_unique<sjf>();
        }
        else {
           this->policy = make_unique<rr>(); 
        }
    };

    Simulator::~Simulator(){};
    

    
    void Simulator::runSchedule(){

    }