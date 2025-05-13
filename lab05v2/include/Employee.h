#pragma once
#include <string>
class Department;
class Employee{
    public:
    friend Department;
    Employee(const std::string &text,Department*obj);
    Employee(const Employee &obj):m_name(obj.m_name),c(nullptr){}
    void printInfo()const;
    private:
    std::string m_name;
    Department *c;
};

struct EmployeeNode{
    EmployeeNode(Employee &new_employee):employee(new_employee),next(nullptr),prev(nullptr){}
    Employee employee;
    EmployeeNode *next;
    EmployeeNode *prev;
};