#pragma once 
#include <string>
class Employee;
class Department{
    public:
    friend class Company;
    friend class Employee;
    Department(std::string name="",int number=0):_department_name(name),_number_of_employees(number),_size(0){
        _tab=new Employee*[number];
    }
    ~Department(){
            for(int j=0;j<_size;j++){
                delete  _tab[j];
            }
            delete _tab;
        } 
    
    const Employee &operator[](int i)const{
        return *_tab[i];
    }
    Employee &operator[](int i){
        return *_tab[i];
    }
    // void addEmployee(std::string employee_name);
    void addEmployee(Employee &obj);

    private:
    std::string _department_name;
    int _number_of_employees;
    Employee **_tab;
    int _size;
};