
#include "Schedule.h"
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

// #define FIFO "./fifo"
// #define SJF "./sjf"
// #define RR "./rr"

bool parseCommand(int argc, char** argv, string& input, string& policy);
void cmdError();

// Your programs are expected to produce the following output on the screen:
// 1. For each process: Process ID, burst time, turnaround time, waiting time, and response time.
// 2. For all processes: Average turnaround time, average waiting time, and average response time

int main(int argc, char** argv) {

    bool success;
    string input;
    string policy;
    unique_ptr<Loader> fetchData = std::make_unique<Loader>();
    success = parseCommand(argc, argv, input, policy);
    
    if(success){
        std::cout << "here 1" << std::endl;
        shared_ptr<vector<shared_ptr<pcb>>> kernelSpace = std::make_shared<vector<shared_ptr<pcb>>>();
        success = fetchData->initData(input, kernelSpace);

        if(success){
             std::cout << "here 1" << std::endl;
            unique_ptr<Simulator> simulator = std::make_unique<Simulator>(policy, kernelSpace);
            simulator->runSchedule();
        }
            
    } 
    if(!success) cmdError();

    return EXIT_SUCCESS;
}

bool parseCommand(int argc, char** argv, string& input, string& policy) {
    bool success = false;
    policy = string(argv[0]);
     std::cout << policy << std::endl;
    success = (policy == FIFO) || (policy == SJF) || 
    (policy == RR);

    if(policy == RR){
        success = success && (argc == RR_COMMAND);
        input = string(argv[2]);
    } else {
        success = success && (argc == STANDARD_COMMAND);
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