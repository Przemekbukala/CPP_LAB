#pragma once
#include <string>
#include "Department.h"
/**
 * @class Employee
 */
class Employee{
    public:
    friend class Department;
    friend class Company;
     /**
     * @brief Konstruktor domyślny i z nazwą pracownika.
     * @param name nazwa pracownika.
     */
   explicit Employee(std::string name=""):_employee_name(name),_department(nullptr){
    }

    /**
     * @brief Konstruktor tworzący pracownika przypisanego do działu.
     * @param employee_name Imię pracownika.
     * @param obj wskaźnik na dział, do którego przypisany jest pracownik.
     * @param k Dodatkowy parametr (do rozszerzeń).
     */
    Employee(std::string employee_name,Department *obj,int k):_employee_name(employee_name),_department(obj){}
    /**
     * @brief Konstruktor tworzący pracownika i automatycznie dodający go do działu.
     * @param name Imię pracownika.
     * @param obj Wskaźnik na dział, do którego jest przypisany.
     */
    Employee(std::string name,Department *obj):_employee_name(name),_department(obj){
        obj->addEmployee(*this);
    }
     /**
     * @brief Wypisuje informacje o pracowniku i jego dziale.
     */
    void printInfo() const;
    private:
    std::string _employee_name;
    const Department *_department;

};