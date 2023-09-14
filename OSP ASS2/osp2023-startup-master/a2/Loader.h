#ifndef LOADER
#define LOADER

#include "pcb.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <memory>


using std::vector;
using std::string;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::unique_ptr;

class Loader {

    public:
        Loader();
        ~Loader();

        /*
        *  Splits input on delimiter. Also validates integrity of input
        */
        bool splitter(string& toSplit, shared_ptr<id_type> id, shared_ptr<time_type> time);

        /*
        *  Loads process data to pcb's
        */
        bool initData(string& input, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace);

    private:
        std::ifstream in;
};

#endif