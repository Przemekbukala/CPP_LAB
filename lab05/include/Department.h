#pragma once
#include <string>
#include "Employee.h"
class Company;
class Employee;
struct EmployeeNode{
    EmployeeNode(Employee &new_employee):employee(new_employee),next(nullptr),prev(nullptr){}
    Employee employee;
    EmployeeNode *next;
    EmployeeNode *prev;
};
class Department{
    public:
    friend Company;
    friend Employee;
    Department(std::string name):m_name(name),m_head(nullptr),m_tail(nullptr){}
    void addEmployee(Employee& newNode);
    void removeEmployee(std::string name);
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

/////////////////////////////////////////


// Department &operator=(const Department &other) {
//     if (this == &other) return *this;
    
//     this->~Department();
//     new (this) Department(other);
//     return *this;
// }

// Department(Department &&other) noexcept : m_name(std::move(other.m_name)), m_head(other.m_head), m_tail(other.m_tail) {
//     other.m_head = other.m_tail = nullptr;
// }

// Department &operator=(Department &&other) noexcept {
//     if (this == &other) return *this;
    
//     this->~Department();
//     m_name = std::move(other.m_name);
//     m_head = other.m_head;
//     m_tail = other.m_tail;
//     other.m_head = other.m_tail = nullptr;
//     return *this;
// }







    void printEmployeesForward()const;
    void printEmployeesBackward()const;
    private:
    std::string m_name;
    EmployeeNode *m_head;
    EmployeeNode *m_tail;
};