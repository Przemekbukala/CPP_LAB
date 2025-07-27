#pragma once
#include "IUser.h"
#include <iostream>
/**
 * @brief Klasa reprezentująca pracownika hotelowego.
 *
 * Dziedziczy wirtualnie po IUser.
 */
class Staff :public virtual IUser{
    public:
     /**
     * @brief Konstruktor inicjalizujący dane pracownika.
     * @param name Nazwa pracownika.
     * @param typ Typ użytkownika (powinien być STAFF).
     */
    Staff(std::string name,Type typ):IUser(name,typ){
    }
    /**
     * @brief Wypisuje rolę pracownika.
     */
    void  printRole()const{
        std::cout<<"[Info]: "<<_name<<" (role: Staff)"<<std::endl;
    }
    /**
     * @brief Wykonuje akcję przypisaną do roli pracownika.
     */
     void  performRoleAction() const{
        manageReservation();
    }
        /**
     * @brief Zarządza rezerwacjami.
     */
    void manageReservation()const{
        std::cout<<"[Info]: "<<_name<<" is managing reservations."<<std::endl;
    }
};