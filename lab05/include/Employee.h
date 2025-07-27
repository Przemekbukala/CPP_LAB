#pragma once
#include <string>
class Department;
/**
 * @class Employee
 * @brief Klasa reprezentująca pojedynczego pracownika.
 
 */
class Employee{
    public:
    friend Department;
      /**
     * @brief Konstruktor klasy Employee.
     * @param text Nazwa pracownika.
     * @param obj Wskaźnik na dział, do którego bedzię przynależeć  pracownik.
     */
    Employee(const std::string &text,Department*obj);
       /**
     * @brief Wypisuje informacje o pracowniku.
     */
    void printInfo()const;
    private:
    std::string m_name;
    Department *c;
};