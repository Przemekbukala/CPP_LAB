#include "../include/Department.h"
#include "../include/Employee.h"
#include <iostream>
void Department::addEmployee(Employee &obj){
    if(_size ==_number_of_employees){
        std::cout<<"Nie można dodać kolejnego prcownika"<<std::endl;
        return;
    }
    _tab[_size]= new Employee;
    // _tab[_size]=&obj;
    _size++;
}
// dokonczyc