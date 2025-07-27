#pragma once
#include <string>
#include "Employee.h"
/**
 * @file Department.h
 * @brief Definicja klasy Department i struktury EmployeeNode.
 */

class Company;
class Employee;

/**
 * @struct EmployeeNode
 * @brief Węzeł dwukierunkowej listy przechowującej pracowników (Employee).
 * Zawiera wskaźniki do poprzedniego i następnego węzła oraz obiekt Employee.
 */
struct EmployeeNode{
    EmployeeNode(Employee &new_employee):employee(new_employee),next(nullptr),prev(nullptr){}
    Employee employee;
    EmployeeNode *next;
    EmployeeNode *prev;
};
/**
 * @class Department
 * @brief Klasa reprezentująca dział w firmie.
 * Przechowuje listę pracowników w dwukierunkowej liście dynamicznej.
 */

class Department{
    public:
    friend Company;
    friend Employee;
    /**
     * @brief Konstruktor klasy Department.
     * @param name Nazwa działu.
     */
    Department(std::string name):m_name(name),m_head(nullptr),m_tail(nullptr){}

    /**
     * @brief Dodaje pracownika do działu.
     * @param newNode Referencja do obiektu Employee.
     */
    void addEmployee(Employee& newNode);

    /**
     * @brief Usuwa pracownika z działu o podanej nazwie.
     * @param name Nazwa pracownika do usunięcia.
     */
    void removeEmployee(std::string name);

    /**
     * @brief Konstruktor kopiujący.
     * @param other Referencja do innego działu do skopiowania.
     */
    Department(const Department& other) : m_name(other.m_name), m_head(nullptr), m_tail(nullptr) {
        EmployeeNode* current = other.m_head;
        while (current) {
            addEmployee(current->employee); 
            current = current->next;
        }
    }

    /**
     * @brief Destruktor, zwalnia pamięć listy pracowników.
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
     * @brief Operator dostępu do pracownika po indeksie.
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

    /**
     * @brief Wypisuje listę pracowników od początku do końca.
     */
    void printEmployeesForward()const;

    /**
     * @brief Wypisuje listę pracowników  od końca do początku.
     */
    void printEmployeesBackward()const;
    private:
    std::string m_name;
    EmployeeNode *m_head;
    EmployeeNode *m_tail;
};