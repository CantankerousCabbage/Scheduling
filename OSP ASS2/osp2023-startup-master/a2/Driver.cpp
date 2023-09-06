
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



void parseCommand(int argc, char** argv);



int main(int argc, char** argv) {

    bool success;
    unique_ptr<Loader> fetchData = std::make_unique<Loader>();
    success = fetchData->init(string(argv[1]));

    if(success){
        success = parseCommand(argc, argv);
        
        
    } 
    std::cout << "Started" << std::endl;


    
    return EXIT_SUCCESS;
}

void parseCommand(int argc, char** argv) {
    map<string> commandList = ['fifo', 'sjf', 'rr'];


}