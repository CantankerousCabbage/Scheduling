#include "Loader.h"


#define DELIM ","
#define NPOS -1

Loader::Loader(){}
Loader::~Loader(){};

bool Loader::initData(string& input, shared_ptr<vector<shared_ptr<pcb>>> kernelSpace){

    in.open(input);
    bool fileGood = in.good();
    string processData;
    shared_ptr<id_type> id = make_shared<id_type>();
    shared_ptr<time_type> time = make_shared<time_type>();
    bool validData = true;

    //For each line create a process
    if(fileGood){
        while(validData && std::getline(in, processData)){
            validData = this->splitter(processData, id, time);
            
            if(validData) kernelSpace->push_back(make_shared<pcb>(*id, *time));
        }
    }
   return validData; 
}

bool Loader::splitter(string& toSplit, shared_ptr<id_type> id, shared_ptr<time_type> time){
    int index = toSplit.find(DELIM);
    bool valid = (index != NPOS) ? true : false; 
    //Try int and long long if not input invalid

    //Attempt type conversions within try/catch
    if(valid){
            try
        { 
            *id = (id_type)std::stoi(toSplit.substr(0, index));
            *time = (time_type)std::stoll(toSplit.substr(index + 1));   
        }
        catch(const std::exception& e)
        {   
            
            valid = false;
        }
    }
   return valid; 
}