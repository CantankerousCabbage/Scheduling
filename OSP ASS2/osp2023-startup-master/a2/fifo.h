#ifndef FINFO
#define FINFO

#include "Schedule.h"


class fifo : public Schedule{
    public:

        fifo(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete);
        ~fifo();

        virtual void run();

};

#endif