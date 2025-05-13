#include "Employee.h"
#include <iostream>
void Employee::printInfo() const{
    std::cout<<"Employee: "<<_employee_name<<" (Department: "<<_department->_department_name<<")"<<std::endl;
}
