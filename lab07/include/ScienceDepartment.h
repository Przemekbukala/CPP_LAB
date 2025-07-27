#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "Department.h"
/**
 * @brief Konkretna klasa działu naukowego, nie można po niej dziedziczyć (final).
 */
class ScienceDepartment final: public Department{
    public:
    ScienceDepartment(const char* name):_name(name){}
    /**
     * @brief Dodaje poddziały do działu.
     * @param divisions_to_add wektor nazw poddziałów.
     */
    void add_divisions( std::vector <std::string> divisions_to_add);

    /**
     * @brief Wypisuje informacje o nazwie i poddziałach.
     */
    void info() const;
    private:
    std::vector <std::string> _tab;
    std::string _name;
};