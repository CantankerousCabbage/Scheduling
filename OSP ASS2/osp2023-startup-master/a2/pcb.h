#include <fstream>
#include <iostream>
#include <memory>
#include "types.h"

using osp2023::id_type;
using osp2023::time_type;
using std::shared_ptr;

#pragma once  // tells the compiler to only include this file once
              /**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/
class pcb {

   public:

        pcb(id_type id, time_type time);
        ~pcb();

        // max and min duration for a process in our system.
        static constexpr osp2023::time_type MAX_DURATION = 100;
        static constexpr osp2023::time_type MIN_DURATION = 10;
        static time_type timeSinceArrival;

        friend bool operator < (const shared_ptr<pcb>& a,const shared_ptr<pcb>& b);

        void static init();
        /*
        *Returns process ID
        */
        id_type getID();

        /*
        *Returns burst time
        */
        time_type getTotalTime();

        /*
        *Returns time used so far by process
        */
        time_type getTimeUsed();

        /*
        *Returns processess total wait time
        */
        time_type getWaitTime();

        /*
        *Returns last time process was on CPU
        */
        time_type getLastTimeCPU();

        /*
        *Time used + time waiting
        */
        time_type getTurnAroundTime();

        /*
        *Returns Response time
        */
        time_type getResponseTime();

        /*
        *Increments time used
        */
        void setTimeUsed(time_type timeUsed);

        /*
        *Increments time waited by process (total process time - time_used)
        */
        void setWaitTime();

        /*
        *Sets the last time process was on CPU. Initialises response time if -1
        */
        void setLastTimeCPU(time_type lastCPUTime);
    
    protected:
        // the unique process id
        osp2023::id_type id;
        // the total time that a process / job should run for
        osp2023::time_type total_time;
        // the time that has been used so far for this process
        osp2023::time_type time_used;
        // the priority level for this process
        // how much time has this process spent waiting for the cpu?
        osp2023::time_type total_wait_time;
        // what time was this process last on the cpu?
        osp2023::time_type last_time_onCPU;
        //time take for process to first be executed from scheduler
        osp2023::time_type responseTime;
};
