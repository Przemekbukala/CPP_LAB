#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Department.h"
#include "ScienceDepartment.h"
class University{
    public:
    University(){
    std::cout<<"University created."<<std::endl;
    }
    ~University(){
        std::cout<<"University destroyed."<<std::endl;
    }
    University& operator=(University && obj){
        if(this == &obj){
            return *this;
        }
        _tab=std::exchange(obj._tab,{});
        std::cout<<"University move assignment."<<std::endl;
        return *this;
    }
    University& operator=(const University & obj)=delete;
    University(const University & obj)=delete;
    University(University && obj)=delete;
    void info() const;
    void add( std::unique_ptr<Department> &&ptr);
    private:
    std::vector <std::unique_ptr<Department>>_tab;
};