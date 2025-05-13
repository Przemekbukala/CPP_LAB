#include "../include/ScienceDepartment.h"
void ScienceDepartment::add_divisions(std::vector <std::string> divisions_to_add){
    for(auto i: divisions_to_add){
        _tab.push_back(i);
    }
}
void ScienceDepartment::info() const{
    std::cout<<"[Science]: '"<<_name<<"' [divisions]: ";
    if(_tab.empty()){
        std::cout<<"None"<<std::endl;
        return;
    }
    for (auto &i:_tab ){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
