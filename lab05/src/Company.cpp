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
    std::cout<<"Company: "<<m_name<<" departments:"<<std::endl;
    while (current) {
        std::cout<<"- "<<current->department.m_name<<std::endl;
        current = current->next;
    }
}

