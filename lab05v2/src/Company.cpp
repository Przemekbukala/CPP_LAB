#include "../include/Company.h"
void Company::addDepartment(const Department&obj){
    DepartmentNode *newNode=new DepartmentNode(obj);
    if (m_head==nullptr)
    {
        m_tail=m_head=newNode;
    } else{
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}
void Company::printDepartments(){
    DepartmentNode* current = m_head;
    std::cout<<"Company: "<<m_name<<" departments: ";
    while (current) {
        std::cout<<"- "<<current->department.m_name<<std::endl;
        current = current->next;
    }
}
void Company::printEmptyDepartments() const{
    DepartmentNode* current = m_head;
    std::cout<<"Company: "<<m_name<<" departments (empty):";
    while (current) {
        if(current->department.m_head==nullptr){
        std::cout<<" "<<current->department.m_name<<", ";
    }
    current = current->next;
}
    std::cout<<std::endl;
}

std::ostream& Company::printDepartments(std::ostream& o=std::cout) const{
    DepartmentNode* current = m_head;
    o<<"Company: "<<m_name<<" departments:";
    while (current) {
        o<<" "<<current->department.m_name<<", ";
        current = current->next;
    }
    return o;
}

