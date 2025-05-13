#include "../include/Employee.h"
#include "../include/Department.h"
#include "../include/Company.h"

#include <iostream>
Employee::Employee(const std::string &text,Department*obj):m_name(text),c(obj){
    c->addEmployee(*this);
}

void Employee::printInfo()const{
    if(c==nullptr){
    std::cout<<"Employee: "<<m_name<<std::endl;
        return;
    }
    std::cout<<"Employee: "<<m_name<<" (Department: "<<c->m_name<<")"<<std::endl;
}
