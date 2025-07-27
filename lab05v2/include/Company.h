#pragma once 
#include <iostream>
#include <string>
#include "Department.h"
/**
 * @class Company
 * @brief Klasa reprezentująca firmę przechowującą działy w liście dwukierunkowej.
 */
class Company{
    public:
    friend Employee;
    friend  std::ostream &operator<<(std::ostream &o,const Company& obj);

    /**
     * @brief Konstruktor tworzący firmę o podanej nazwie.
     * @param company_name Nazwa firmy.
     */
    Company(std::string company_name):m_name(company_name),m_head(nullptr),m_tail(nullptr){}

    /**
     * @brief Konstruktor tworzący firmę o podanej nazwie (jako C-string).
     * @param nazwa Nazwa firmy.
     */
    Company(const char *nazwa):m_name(nazwa),m_head(nullptr),m_tail(nullptr){}

    /**
     * @brief Dodaje dział do firmy.
     * @param dept Referencja do obiektu Department do dodania.
     */
    void addDepartment( const Department&);

    /**
     * @brief Wypisuje wszystkie działy firmy.
     */
    void printDepartments();
     /**
     * @brief Wypisuje wszystkie działy firmy na dany strumień.
     * @param o Strumień wyjściowy.
     * @return Referencja do strumienia wyjściowego.
     */
    std::ostream& printDepartments(std::ostream& o) const;
    /**
     * @brief Destruktor zwalniający pamięć zaalokowaną na listę działów.
     */
    ~Company(){
        DepartmentNode* current = m_head;
        while (current) {
            DepartmentNode*tmp=current;
            current = current->next;
            delete tmp;
        }
    }
    void printEmptyDepartments() const; 

    /**
     * @brief Operator indeksowania po nazwie działu.
     * @param str Nazwa działu.
     * @return Referencja do działu o podanej nazwie lub pierwszego działu, jeśli nie znaleziono.
     */
     Department& operator [](const char* str){
        DepartmentNode *current=m_head;
        while (current)
        {
            if(current->department.m_name==str){
                return current->department;
            }else{
               current=current->next;
            }
        }      
        return m_head->department;
    }
    private:
    std::string m_name;
    DepartmentNode *m_head;
    DepartmentNode *m_tail;
};
inline std::ostream &operator<<(std::ostream &o,const Company& obj){
   return obj.printDepartments(o);
}