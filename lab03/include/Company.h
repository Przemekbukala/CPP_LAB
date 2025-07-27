#pragma once 
#include <string>
#include <iostream>
#include "Department.h"

/**
 * @class Company
 */
class Company{
    public:
    // friend class Department;
        /**
     * @brief Konstruktor firmy.
     * @param name Nazwa firmy.
     * @param number Maksymalna liczba działów.
     */
    Company(std::string name,int number):_number_of_departamens(number),_company_name(name),_size(0){\
        _tab=new Department[_number_of_departamens];
    }

    /**
     * @brief Destruktor firmy, zwalnia tablicę działów.
     */
    ~Company(){ 
        delete []_tab;
    }

    /**
     * @brief Dodaje dział do firmy.
     * @param obj Referencja do obiektu Department do dodania.
     */
    void addDepartment(Department &obj);

    /**
     * @brief wypisuje nazwy wszystkich działów firmy.
     */
    void printDepartments() const;
    private:
    std::string _company_name;
    int _number_of_departamens;
    Department *_tab;
    int _size;
};