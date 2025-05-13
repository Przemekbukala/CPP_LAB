#pragma once
#include <string>
#include "Department.h"
class Employee{
    public:
    friend class Department;
    friend class Company;
   explicit Employee(std::string name=""):_employee_name(name),_department(nullptr){
    }
    Employee(std::string employee_name,Department *obj,int k):_employee_name(employee_name),_department(obj){}
    Employee(std::string name,Department *obj):_employee_name(name),_department(obj){
        obj->addEmployee(*this);
    }
    void printInfo() const;

    private:
    std::string _employee_name;
    const Department *_department;

};