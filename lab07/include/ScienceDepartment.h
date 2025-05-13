#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "Department.h"
class ScienceDepartment final: public Department{
    public:
    ScienceDepartment(const char* name):_name(name){}
    void add_divisions( std::vector <std::string> divisions_to_add);
    void info() const;
    private:
    std::vector <std::string> _tab;
    std::string _name;
};