#pragma once
#include <iostream>
#include <string>
/**
 * @brief Typ użytkownika systemu hotelowego.
 */
enum class Type{
    GUEST,STAFF
};
/**
 * @brief Klasa bazowa reprezentująca użytkownika systemu hotelowego.
 *
 * Klasa czysto wirtualna, z której dziedziczą Guest oraz Staff.
 */
class IUser{
    public:
        /**
     * @brief Domyślny konstruktor IUser.
     */
    IUser()=default;

    /**
     * @brief Wirtualna metoda wypisująca rolę użytkownika.
     */
    void virtual printRole()const=0;
        /**
     * @brief Wirtualna metoda wykonująca akcję przypisaną do roli.
     */
    void virtual performRoleAction() const=0;
    /**
     * @brief Zwraca nazwę użytkownika.
     * @return Nazwa użytkownika.
     */
    std::string  getName() const{
    return _name;
    }
    protected:
    std::string _name;
    Type _typ;
        /**
     * @brief Konstruktor inicjalizujący nazwę i typ użytkownika.
     * @param name Nazwa użytkownika.
     * @param typ Typ użytkownika (GUEST lub STAFF).
     */
    IUser(std::string name,Type typ):_name(name),_typ(typ){
    }
};