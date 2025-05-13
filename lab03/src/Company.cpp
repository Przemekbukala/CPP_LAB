#include "../include/Company.h"
#include "../include/Employee.h"
#include "../include/Department.h"
#include <iostream>
void Company::addDepartment(Department &obj){
    if(_size ==_number_of_departamens){
        std::cout<<"Nie można dodać kolejny department"<<std::endl;
        return;
    }
    _tab[_size]=obj;
    _size++;
}   
void Company::printDepartments() const{
    std::cout<<"Company: "<<_company_name<<" departments:"<<std::endl;
    for (int i = 0; i < _size; i++)
    {
        std::cout<<"- "<<_tab[i]._department_name<<std::endl;
    }
    for (int i = 0; i < _size; i++)
    {

    }
    
}
