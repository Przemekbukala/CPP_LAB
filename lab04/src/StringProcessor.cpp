#include "../include/StringProcessor.h"
void StringProcessor::addVoidAlgorithm(std::function<void(std::string &)> fun){
    _void_tab.push_back(fun);
}
void StringProcessor::addIntAlgorithm(std::function<int(std::string&)> fun){
    _int_tab.push_back(fun);
}
void StringProcessor::reset(){
    _int_tab.clear();
    _void_tab.clear();
    std::cout<<"Processor reset. All algorithms removed."<<std::endl;
}
void StringProcessor::enableAlgorithm(const std::string algorithm){
    if(algorithm=="reverse"){
    std::cout<<"Enabling built-in algorithm: reverse"<<std::endl;
        _void_tab.push_back([](std::string& str) {
            std::reverse(str.begin(), str.end());});
    }
}
    