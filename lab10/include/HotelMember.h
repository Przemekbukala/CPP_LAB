#pragma once
#include "IUser.h"
#include "Staff.h"
#include "Guest.h"
/**
 * @brief Klasa reprezentująca członka hotelu, który może być zarówno gościem, jak i pracownikiem.
 *
 * Dziedziczy po klasach Guest i Staff, a przez nie po IUser.
 */
class HotelMember : public Guest, public Staff{
    public:
      /**
     * @brief Konstruktor inicjalizujący dane członka hotelu.
     * @param name Nazwa użytkownika.
     * @param typ Typ użytkownika (GUEST lub STAFF).
     */
    HotelMember(std::string name,Type typ):Guest(name,typ),Staff(name,typ),IUser(name,typ){}

    /**
     * @brief Wypisuje rolę w zależności od typu użytkownika.
     */
    void  printRole()const{
        if(_typ==Type::STAFF){
            Staff::printRole();
        }else if(_typ==Type::GUEST){
            Guest::printRole();
        }
    }
        /**
     * @brief Wykonuje akcję odpowiednią dla danego typu użytkownika.
     */
    void  performRoleAction() const{
        if(_typ==Type::STAFF){
            Staff::manageReservation();
        }else if(_typ==Type::GUEST){
            Guest::makeReservation();
        }
    }
    private:

};