#include "Simulator.h"

    Simulator::Simulator(string& policy, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete,
     shared_ptr<time_type> quantum) {
        if(policy == FIFO){
            this->policy = make_unique<fifo>(kernelSpace, complete);
        } 
        else if(policy == SJF){
            this->policy = make_unique<sjf>(kernelSpace, complete);
        }
        else {
           this->policy = make_unique<rr>(kernelSpace, complete, quantum); 
        }
    };

    Simulator::~Simulator(){};
    

    
    void Simulator::runSchedule(){
        
           this->policy->run(); 
    }