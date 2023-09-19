#ifndef SCHEDULE
#define SCHEDULE

#include "pcb.h"

#define PRECISION 5
#define SPACING 16

#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <iomanip>

using osp2023::id_type;
using osp2023::time_type;
using std::vector;
using std::string;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;

#define EMPTY 0

class Schedule {
    public:

    Schedule();
    Schedule(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete);
    virtual ~Schedule();
    virtual void run();

    void printHeading();
    void printAverage();
    void lineFormat(id_type id,  time_type burst, time_type turnAround, 
        time_type waitTime, time_type responseTime);

    void genAverages(shared_ptr<time_type> AvgTT, shared_ptr<time_type> AvgWait, shared_ptr<time_type> AvgResp);

    time_type timeSinceArrival;

    protected:
        shared_ptr<vector<shared_ptr<pcb>>> kernelSpace;
        shared_ptr<vector<shared_ptr<pcb>>> complete;

        
};


#endif