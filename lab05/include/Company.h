#pragma once 
#include <iostream>
#include <string>
#include "Department.h"
struct DepartmentNode{
    DepartmentNode(const Department &new_department):department(new_department),next(nullptr),prev(nullptr){}
    Department department;
    DepartmentNode *next;
    DepartmentNode *prev;
};
class Company{
    public:
    Company(std::string company_name):m_name(company_name),m_head(nullptr),m_tail(nullptr){}
    void addDepartment( const Department&);
    void printDepartments();
    ~Company(){
        DepartmentNode* current = m_head;
        while (current) {
            DepartmentNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }

    ////////////////////////////////////////////////////////////

    // Company(const Company &other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
    //     DepartmentNode *current = other.m_head;
    //     while (current) {
    //         addDepartment(current->department);
    //         current = current->next;
    //     }
    // }
    
    // Company &operator=(const Company &other) {
    //     if (this == &other) return *this;
        
    //     this->~Company();
    //     new (this) Company(other);
    //     return *this;
    // }
    
    // Company(Company &&other) noexcept : m_name(std::move(other.m_name)), m_head(other.m_head), m_tail(other.m_tail) {
    //     other.m_head = other.m_tail = nullptr;
    // }
    
    // Company &operator=(Company &&other) noexcept {
    //     if (this == &other) return *this;
        
    //     this->~Company();
    //     m_name = std::move(other.m_name);
    //     m_head = other.m_head;
    //     m_tail = other.m_tail;
    //     other.m_head = other.m_tail = nullptr;
    //     return *this;
    // }
    /////////////////////////////////
    private:
    std::string m_name;
    DepartmentNode *m_head;
    DepartmentNode *m_tail;
};