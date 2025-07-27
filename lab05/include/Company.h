#pragma once 
#include <iostream>
#include <string>
#include "Department.h"
/**
 * @struct DepartmentNode
 * @brief Węzeł dwukierunkowej listy przechowującej działy (Department).
 *
 * Zawiera wskaźniki do poprzedniego i następnego węzła oraz obiekt Department.
 */
struct DepartmentNode{
    DepartmentNode(const Department &new_department):department(new_department),next(nullptr),prev(nullptr){}
    Department department;
    DepartmentNode *next;
    DepartmentNode *prev;
};
/**
 * @class Company
 * @brief Klasa reprezentująca firmę zawierającą listę działów.
 *
 */
class Company{
    public:
        /**
     * @brief Konstruktor klasy Company.
     * @param company_name Nazwa firmy.
     */
    Company(std::string company_name):m_name(company_name),m_head(nullptr),m_tail(nullptr){}

    /**
     * @brief Dodaje dział do firmy.
     * @param dept Referencja do obiektu Department.
     */
    void addDepartment( const Department&);
    /**
     * @brief Wypisuje wszystkie działy firmy.
     */
    void printDepartments();
    //  Destruktor, zwalnia pamięć listy działów.
    ~Company(){
        DepartmentNode* current = m_head;
        while (current) {
            DepartmentNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }

    private:
    std::string m_name;
    DepartmentNode *m_head;
    DepartmentNode *m_tail;
};