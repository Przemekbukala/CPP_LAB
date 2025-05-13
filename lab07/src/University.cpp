#include "../include/University.h"
void University::info() const{
    if(_tab.empty()){
        std::cout<<"[INFO]:: No departments assigned."<<std::endl;  
        return;
    }
    int j=0;
    std::cout<<"[INFO]:: University departments:"<<std::endl;
    for(auto &i:_tab){
        std::cout<<"        ["<<j<<"] ";
        j++;
        i->info();
    }
}
void University::add(std::unique_ptr<ScienceDepartment> obj){
    _tab.push_back(std::move(obj));
}

std::unique_ptr<Department> University::pop_back_department(){
    auto ptr=std::move(_tab[_tab.size()-1]);
    _tab.pop_back();
    return ptr;
}
