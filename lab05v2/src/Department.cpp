#include "../include/Department.h"
#include <iostream>
void Department::addEmployee(Employee& obj){
    EmployeeNode *newNode=new EmployeeNode(obj);
    if (m_head==nullptr)
    {
        m_tail=m_head=newNode;
    } else{
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
}

void Department::removeEmployee(std::string name){
    EmployeeNode* current = m_head;
    while (current) {
    if(current->employee.m_name==name){
        EmployeeNode*tmp=current;
        if (current == m_head) m_head = current->next;
        if (current == m_tail) m_tail = current->prev;
        current->prev->next=current->next;
        current->next->prev=current->prev;
        delete current;
        return;
    }
    current = current->next;
}
}
void Department::printEmployeesForward()const{
    EmployeeNode* current = m_head;
    while (current) {
    current->employee.printInfo();
    current = current->next;
}
}
void Department::printEmployeesBackward()const{
    EmployeeNode* current = m_tail;
    while (current) {
    current->employee.printInfo();
    current = current->prev;
}

}