#pragma once
#include "IUser.h"
/**
 * @brief Klasa reprezentująca gościa hotelowego.
 * Dziedziczy wirtualnie po IUser.
 */
class Guest :public virtual IUser{
    public:
        /**
     * @brief Konstruktor inicjalizujący dane gościa.
     * @param name Nazwa gościa.
     * @param typ Typ użytkownika (powinien być GUEST).
     */
    Guest(std::string name,Type typ):IUser(name,typ){
    }
    /**
     * @brief Wypisuje rolę gościa.
     */
    void  printRole()const{
        std::cout<<"[Info]: "<<_name<<" (role: Guest)"<<std::endl;
    }
    /**
     * @brief Wykonuje akcję przypisaną do roli gościa.
     */
    void  performRoleAction() const{
        makeReservation();
    }
    /**
     * @brief Dokonuje rezerwacji pokoju.
     */
    void makeReservation() const {
        std::cout<<"[Info]: "<<_name<<" is making reservation for: Room 401"<<std::endl;
    }
};