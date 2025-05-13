#pragma once
#include <string>
#include "Employee.h"
class Company;
class Employee;
class Department{
    public:
    friend Company;
    friend Employee;
    Department(std::string name):m_name(name),m_head(nullptr),m_tail(nullptr){}
    void addEmployee(Employee& newNode);
    void removeEmployee(std::string name);
    Department(const char *nazwa):m_name(nazwa),m_head(nullptr),m_tail(nullptr){}
    Department(const Department& other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
        EmployeeNode* current = other.m_head;
        while (current) {
            addEmployee(current->employee); 
            current = current->next;
        }
    }
    ~Department(){
        EmployeeNode* current = m_head;
        while (current) {
            EmployeeNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }
    Employee& operator[](int index){
        EmployeeNode *current=m_head;
        for(int i=0;i<index && current!= nullptr;i++){
            current=current->next;
        }
        return current->employee;
    }
    void printEmployeesForward()const;
    void printEmployeesBackward()const;
    private:
    std::string m_name;
    EmployeeNode *m_head;
    EmployeeNode *m_tail;
};
struct DepartmentNode{
    DepartmentNode(const Department &new_department):department(new_department),next(nullptr),prev(nullptr){}
    Department department;
    DepartmentNode *next;
    DepartmentNode *prev;
};