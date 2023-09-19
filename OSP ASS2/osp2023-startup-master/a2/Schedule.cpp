#include "Schedule.h"

    Schedule::Schedule(){};
    Schedule::Schedule(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete) : kernelSpace{kernelSpace}, complete{complete}{
    };
    Schedule::~Schedule(){};


    void Schedule::lineFormat(id_type id,  time_type burst, time_type turnAround, time_type waitTime, 
    time_type responseTime){
            std::cout << 
            std::setprecision(PRECISION) << 
            std::setw(SPACING) << id << 
            std::setw(SPACING) << burst <<
            std::setw(SPACING) << turnAround <<
            std::setw(SPACING) << waitTime <<
            std::setw(SPACING) << responseTime <<
            "\n";
    }
    // "Process ID     Burst Time     Waiting Time     TurnAround Time
    void Schedule::printHeading(){
        std::cout << 
        std::setw(SPACING) << "Process ID" << 
        std::setw(SPACING) << "Burst Time" <<
        std::setw(SPACING) << "Turnaround Time" <<
        std::setw(SPACING) << "Wait Time" <<
        std::setw(SPACING) << "Response Time" <<
        "\n";
    };

    void Schedule::printAverage(){
        shared_ptr<time_type> AvgTT = make_shared<time_type>();
        shared_ptr<time_type> AvgWait = make_shared<time_type>();
        shared_ptr<time_type> AvgResp = make_shared<time_type>(); 
        
       genAverages(AvgTT,  AvgWait, AvgResp);

        std::cout <<
        std::setw(SPACING) << "Avg T.Around Time" << 
        std::setw(SPACING) << "Avg Wait Time" <<
        std::setw(SPACING) << "Avg Response Time\n" <<
        std::setw(SPACING) << *AvgTT << 
        std::setw(SPACING) << *AvgWait <<
        std::setw(SPACING) << *AvgResp <<
        std::endl;
    };

    void Schedule::genAverages(shared_ptr<time_type> AvgTT, shared_ptr<time_type> AvgWait, shared_ptr<time_type> AvgResp){
        time_type TT_total = 0;
        time_type wait_total = 0;
        time_type resp_total = 0;

        shared_ptr<vector<shared_ptr<pcb>>> source = (kernelSpace->size() > EMPTY) ? kernelSpace : complete;

        unsigned numP = source->size();
        
        for(unsigned i = 0; i < numP; i++){
            TT_total += (*source)[i]->getTurnAroundTime();
            wait_total += (*source)[i]->getWaitTime();
            resp_total += (*source)[i]->getResponseTime();
        }

        std::cout << "AvgTT: " << *AvgTT << ", AvgWait: " << *AvgWait << ", AvgResp: " << *AvgResp << std::endl;
        *AvgTT = TT_total / numP;
        *AvgWait = wait_total / numP;
        *AvgResp = resp_total / numP;
    }

    
    void Schedule::run(){};
