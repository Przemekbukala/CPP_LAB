#pragma once
#include <string>
#include "Employee.h"
class Company;
class Employee;
/**
 * @class Department
 * @brief Klasa reprezentująca dział firmy z listą pracowników.
 * Przechowuje listę pracowników w strukturze dwukierunkowej.
 * Umożliwia dodawanie, usuwanie pracowników oraz dostęp do nich.
 */
class Department{
    public:
    friend Company;
    friend Employee;
    /**
     * @brief Konstruktor tworzący dział o podanej nazwie.
     * @param name Nazwa działu.
     */

    Department(std::string name):m_name(name),m_head(nullptr),m_tail(nullptr){}
     /**
     * @brief Dodaje pracownika do działu.
     * @param newNode Referencja do obiektu Employee.
     */
    void addEmployee(Employee& newNode);

    /**
     * @brief Usuwa pracownika o podanej nazwie.
     * @param name Nazwa pracownika do usunięcia.
     */
    void removeEmployee(std::string name);

    /**
     * @brief Konstruktor tworzący dział o nazwie podanej jako C-string.
     * @param nazwa Nazwa działu.
     */
    Department(const char *nazwa):m_name(nazwa),m_head(nullptr),m_tail(nullptr){}

    /**
     * @brief Konstruktor kopiujący tworzący głęboką kopię działu (pracowników).
     * @param other Referencja do kopiowanego działu.
     */
    Department(const Department& other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
        EmployeeNode* current = other.m_head;
        while (current) {
            addEmployee(current->employee); 
            current = current->next;
        }
    }

    /**
     * @brief Destruktor zwalniający pamięć zaalokowaną dla listy pracowników.
     */
    ~Department(){
        EmployeeNode* current = m_head;
        while (current) {
            EmployeeNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }

    /**
     * @brief Operator indeksowania po indeksie pracownika.
     * @param index Indeks pracownika.
     * @return Referencja do pracownika.
     */
    Employee& operator[](int index){
        EmployeeNode *current=m_head;
        for(int i=0;i<index && current!= nullptr;i++){
            current=current->next;
        }
        return current->employee;
    }
    void printEmployeesForward()const;
    void printEmployeesBackward()const;
    private:
    std::string m_name;
    EmployeeNode *m_head;
    EmployeeNode *m_tail;
};
struct DepartmentNode{
     /**
     * @brief Konstruktor tworzący węzeł z kopią działu.
     * @param new_department Referencja do działu.
     */
    DepartmentNode(const Department &new_department):department(new_department),next(nullptr),prev(nullptr){}
    Department department;
    DepartmentNode *next;
    DepartmentNode *prev;
};