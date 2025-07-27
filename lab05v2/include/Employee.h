#pragma once
#include <string>
class Department;

/**
 * @class Employee
 * @brief Klasa reprezentująca pracownika przypisanego do działu.
 */
class Employee{
    public:
    friend Department;

    /**
     * @brief Konstruktor tworzący pracownika z nazwą i wskaźnikiem na dział.
     * @param text Nazwa pracownika.
     * @param obj Wskaźnik na dział, do którego należy pracownik.
     */
    Employee(const std::string &text,Department*obj);

    /**
     * @brief Konstruktor kopiujący pracownika.
     * @param obj Referencja do kopiowanego pracownika.
     */
    Employee(const Employee &obj):m_name(obj.m_name),c(nullptr){}
     /**
     * @brief Wypisuje informacje o pracowniku.
     */
    void printInfo()const;
    private:
    std::string m_name;
    Department *c;
};
/**
 * @struct EmployeeNode
 * @brief Węzeł listy dwukierunkowej pracowników.
 */
struct EmployeeNode{
        /**
     * @brief Konstruktor tworzący węzeł z referencją do pracownika.
     * @param new_employee Referencja do pracownika.
     */
    EmployeeNode(Employee &new_employee):employee(new_employee),next(nullptr),prev(nullptr){}
    Employee employee;
    EmployeeNode *next;
    EmployeeNode *prev;
};