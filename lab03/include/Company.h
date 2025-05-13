#pragma once 
#include <string>
#include <iostream>
#include "Department.h"
class Company{
    public:
    // friend class Department;
    Company(std::string name,int number):_number_of_departamens(number),_company_name(name),_size(0){\
        _tab=new Department[_number_of_departamens];
    }
    ~Company(){ 
        delete []_tab;
    }
    void addDepartment(Department &obj);
    void printDepartments() const;
    private:
    std::string _company_name;
    int _number_of_departamens;
    Department *_tab;
    int _size;
};