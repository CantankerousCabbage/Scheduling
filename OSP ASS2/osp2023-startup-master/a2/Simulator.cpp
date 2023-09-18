#include "Simulator.h"

    Simulator::Simulator(string& policy, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<time_type> quantum)
     : kernelSpace{kernelSpace} {
        if(policy == FIFO){
            this->policy = make_unique<fifo>(kernelSpace);
        } 
        else if(policy == SJF){
            this->policy = make_unique<sjf>(kernelSpace);
        }
        else {
           this->policy = make_unique<rr>(kernelSpace, quantum); 
        }
    };

    Simulator::~Simulator(){};
    

    
    void Simulator::runSchedule(){
        
           this->policy->run(); 
    }