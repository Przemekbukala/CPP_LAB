#pragma once 
#include <iostream>
#include <string>
#include "Department.h"

class Company{
    public:
    friend Employee;
    friend  std::ostream &operator<<(std::ostream &o,const Company& obj);
    Company(std::string company_name):m_name(company_name),m_head(nullptr),m_tail(nullptr){}
    Company(const char *nazwa):m_name(nazwa),m_head(nullptr),m_tail(nullptr){}
    void addDepartment( const Department&);
    void printDepartments();
    std::ostream& printDepartments(std::ostream& o) const;
    ~Company(){
        DepartmentNode* current = m_head;
        while (current) {
            DepartmentNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }
    void printEmptyDepartments() const; 
     Department& operator [](const char* str){
        DepartmentNode *current=m_head;
        while (current)
        {
            if(current->department.m_name==str){
                return current->department;
            }else{
               current=current->next;
            }
        }      
        return m_head->department;
    }
    private:
    std::string m_name;
    DepartmentNode *m_head;
    DepartmentNode *m_tail;
};
inline std::ostream &operator<<(std::ostream &o,const Company& obj){
   return obj.printDepartments(o);
}