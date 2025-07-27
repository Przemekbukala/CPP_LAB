#pragma once 
#include <iostream>
#include "ScienceDepartment.h"
#include "Department.h"
#include <memory>

/**
 * @brief Klasa reprezentująca uczelnię zarządzającą działami naukowymi.
 */
class University{
    public:
    University(){
        std::cout<<"[INFO]:: University created."<<std::endl;
    }
    // Konstruktor przenoszący
    University(University && obj){
        _tab=std::move(obj._tab);
    }
    // Destruktor
    ~University(){
        std::cout<<"[INFO]:: University destroyed."<<std::endl;
    }
    // Operator przypisania przenoszącego
    University &operator=(University && obj){
        if (this==&obj)
        {
            std::cout<<"[INFO]:: University move assignment."<<std::endl;
            return *this;
        }
        _tab=std::move(obj._tab);
        std::cout<<"[INFO]:: University move assignment."<<std::endl;
            return *this;
    }

    /**
     * @brief Wypisuje informacje o wszystkich działach uczelni.
     */
    void info() const; 
    /**
     * @brief Dodaje dział naukowy do uczelni.
     * @param obj Wskaźnik unikalny do ScienceDepartment.
     */
    void add(std::unique_ptr<ScienceDepartment> obj);

    /**
     * @brief Zwraca i usuwa ostatni dział z kolekcji.
     * @return Wskaźnik unikalny do usuniętego działu.
     */
    std::unique_ptr<Department> pop_back_department();
    private:
    std::vector<std::unique_ptr<ScienceDepartment>> _tab;
};