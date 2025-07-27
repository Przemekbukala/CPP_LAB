#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Department.h"
#include "ScienceDepartment.h"

/**
 * @class University
 * @brief Klasa reprezentująca uczelnię, zarządzającą kolekcją działów.
 */
class University{
    public:
      /**
     * @brief Konstruktor domyślny klasy University.
     * Wypisuje komunikat o utworzeniu uczelni.
     */
    University(){
    std::cout<<"University created."<<std::endl;
    }
  /**
     * @brief Destruktor klasy University.
     * Wypisuje komunikat o usunięciu uczelni.
     */
    ~University(){
        std::cout<<"University destroyed."<<std::endl;
    }
     /**
     * @brief Operator przypisania przenoszącego.
     * Przenosi zasoby z innej instancji klasy University.
     * @param obj Instancja do przeniesienia.
     * @return Referencja do bieżącego obiektu.
     */
    University& operator=(University && obj){
        if(this == &obj){
            return *this;
        }
        _tab=std::exchange(obj._tab,{});
        std::cout<<"University move assignment."<<std::endl;
        return *this;
    }
// Usunięty operator przypisania kopiującego.
    University& operator=(const University & obj)=delete;
    // Usunięty Konstruktor kopiujący.
    University(const University & obj)=delete;
    // Usunięty Konstruktor przenoszący.
    University(University && obj)=delete;
     /**
     * @brief Wypisuje informacje o działach przypisanych do uczelni.
     * Jeśli brak działów, wypisuje odpowiednią informację.
     */
    void info() const;

    /**
     * @brief Dodaje dział do uczelni.
     * @param ptr Wskaźnik (unique_ptr) do obiektu klasy dziedziczącej po Department.
     */
    void add( std::unique_ptr<Department> &&ptr);
    private:
    std::vector <std::unique_ptr<Department>>_tab;
};