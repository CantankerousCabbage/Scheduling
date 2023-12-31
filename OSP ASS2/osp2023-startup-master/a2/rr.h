#ifndef ROUNDROBIN
#define ROUNDROBIN

#include "Schedule.h"
#include <vector>

using std::vector;
#define FRONT 0


class rr : public Schedule{
    public:

    rr(shared_ptr<vector<shared_ptr<pcb>>> kernelSpace, shared_ptr<vector<shared_ptr<pcb>>> complete, shared_ptr<time_type> quantum);
    ~rr();

    virtual void run();

    //Quantom value for rr plicy
    private:
        shared_ptr<time_type> quantum;
        
};

#endif