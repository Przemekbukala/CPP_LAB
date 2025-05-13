#pragma once
#include <string>
class Department;
class Employee{
    public:
    friend Department;
    Employee(const std::string &text,Department*obj);
    void printInfo()const;
    private:
    std::string m_name;
    Department *c;
};