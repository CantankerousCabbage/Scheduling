
#include "Driver.h"
#include "Loader.h"
#include "Simulator.h"

#include <iostream>
#include <memory>
#include <map>

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::map;

#define STANDARD_COMMAND 2
#define RR_COMMAND 3
#define FIFO "fifo"
#define SJF "sjf"
#define RR "rr"

bool parseCommand(int argc, char** argv, string& input, string& policy);



int main(int argc, char** argv) {

    bool success;
    string input;
    string policy;
    unique_ptr<Loader> fetchData = std::make_unique<Loader>();
    success = parseCommand(argc, argv, input, policy);
    
    if(success){
        unique_ptr<Simulator> simulator = std::make_unique<Simulator>(policy);

    }
    
    return EXIT_SUCCESS;
}

bool parseCommand(int argc, char** argv, string& input, string& policy) {
    bool success = false;
    policy = string(argv[0]);
    success = (policy == FIFO) || (policy == SJF) || 
    (policy == RR);

    if(policy == RR){
        success = success && (argc == RR_COMMAND);
        input = string(argv[2]);
    } else {
        success = success && (argc == RR_COMMAND);
        input = string(argv[1]);
    }
     
    return success;
}

void cmdError(){
    std::cout << 
    "Error, try following input to run:\n"
    "For FIFO Scheduler:\n"
    "       ./fifo <datafile>\n"
    "For SJF Scheduler:\n"
    "       ./sjf <datafile>\n"
    "For RR Scheduler:\n"
    "       ./rr <quantum> <datafile>\n\n"
    "Otherwise ensure the datafile exists.\n" 
    << std::endl;
}