
#include "pcb.h"

    // osp2023::time_type pcb::MAX_DURATION;
    // osp2023::time_type pcb::MIN_DURATION;
    time_type pcb::timeSinceArrival;


    pcb::pcb(id_type id, time_type time) : id{id}, total_time{time}{
       
       //Initialise all values outised of burst and ID as unset
        this->time_used = osp2023::initial_time;
        this->total_wait_time = osp2023::initial_time;
        this->last_time_onCPU = osp2023::time_not_set;
    };
    pcb::~pcb(){};


    void pcb::init(){
       timeSinceArrival = 0;
    }

    id_type pcb::getID(){
        return this->id;
    }

   
    time_type pcb::getTotalTime(){
        return this->total_time;
    }

    time_type pcb::getTimeUsed(){
        return this->time_used;
    }

    time_type pcb::getWaitTime(){
        return this->total_wait_time;
    }

    time_type pcb::getLastTimeCPU(){
        return this->last_time_onCPU;
    }

    void pcb::setTimeUsed(time_type timeUsed){
        if(last_time_onCPU == osp2023::time_not_set){
            responseTime = pcb::timeSinceArrival;
        }
        this->time_used += timeUsed;
    }

    void pcb::setWaitTime(){
        this->total_wait_time = timeSinceArrival - time_used;
    }

    void pcb::setLastTimeCPU(time_type lastCPUTime){

        this->last_time_onCPU = lastCPUTime;
    }

    time_type pcb::getResponseTime(){
        return this->responseTime;
    }

    time_type pcb::getTurnAroundTime(){
        return this->time_used + this->total_wait_time;
    }

