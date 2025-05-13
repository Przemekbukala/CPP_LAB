#include "../include/University.h"

void University::info() const{
    if(_tab.empty()){
        std::cout<<"No departments assigned."<<std::endl;
    }
    for(const auto &i :_tab){
        i->print_info();
    }
}
void University::add( std::unique_ptr<Department> &&ptr){
    _tab.emplace_back(std::move(ptr));
    std::cout<<"Department added to University."<<std::endl;
}
