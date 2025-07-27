#pragma once
#include <string>
#include "Department.h"
/**
 * @class ScienceDepartment
 * @brief Implementacja działu naukowego.
 */
class ScienceDepartment : public Department{
    public:
     /**
     * @brief Konstruktor klasy ScienceDepartment.
     * Wypisuje informację o utworzeniu działu naukowego.
     */
    ScienceDepartment():_name("ScienceDepartment"),Department(){
        std::cout<<_name<<" created."<<std::endl;
    }
    /**
     * @brief Destruktor klasy ScienceDepartment.
     * Wypisuje informację o usunięciu działu naukowego.
     */
    ~ScienceDepartment() override{
        std::cout<<"ScienceDepartment destroyed."<<std::endl;
    }
        /**
     * @brief Metoda wypisująca szczegółowe informacje o dziale.
     */
    void print_info()const override{
        std::cout<<"Science Department (Physics, Chemistry, Biology)"<<std::endl;
    }
    private:
    std::string _name;
};