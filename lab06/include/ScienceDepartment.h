#pragma once
#include <string>
#include "Department.h"
class ScienceDepartment : public Department{
    public:
    ScienceDepartment():_name("ScienceDepartment"),Department(){
        std::cout<<_name<<" created."<<std::endl;
    }
    ~ScienceDepartment(){
        std::cout<<"ScienceDepartment destroyed."<<std::endl;
    }
    void print_info()const override{
        std::cout<<"Science Department (Physics, Chemistry, Biology)"<<std::endl;
    }
    private:
    std::string _name;
};