#pragma once 
#include <iostream>
#include "ScienceDepartment.h"
#include "Department.h"
#include <memory>
class University{
    public:
    University(){
        std::cout<<"[INFO]:: University created."<<std::endl;
    }
    University(University && obj){
        _tab=std::move(obj._tab);
    }
    ~University(){
        std::cout<<"[INFO]:: University destroyed."<<std::endl;
    }
    University &operator=(University && obj){
        if (this==&obj)
        {
            std::cout<<"[INFO]:: University move assignment."<<std::endl;
            return *this;
        }
        _tab=std::move(obj._tab);
        std::cout<<"[INFO]:: University move assignment."<<std::endl;
            return *this;
    }
    void info() const; 
    void add(std::unique_ptr<ScienceDepartment> obj);
    std::unique_ptr<Department> pop_back_department();
    private:
    std::vector<std::unique_ptr<ScienceDepartment>> _tab;
};