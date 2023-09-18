#ifndef FINFO
#define FINFO

#include "Schedule.h"


class fifo : public Schedule{
    public:

        fifo(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace);
        ~fifo();

        virtual void run();

};

#endif