#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using Container=std::vector<std::tuple<std::string,std::string,int>>;
using booking_entry=Container::value_type;
/**
 * @class BookingManager
 * @brief Klasa zarządzająca rezerwacjami.
 *
 * Przechowuje rezerwacje w kontenerze m_bookings.
 * Umożliwia dodawanie rezerwacji, ich wyświetlanie oraz sortowanie wg daty.
 * Logowanie odbywa się przez Logger (singleton).
 */
class BookingManager
{
public:
 /**
     * @brief Konstruktor klasy BookingManager.
     * Inicjalizuje pusty kontener rezerwacji.
     */
    BookingManager():m_bookings({}){}
    /**
     * @brief Wirtualny destruktor.
     * Zapewnia poprawne dziedziczenie.
     */
    virtual ~BookingManager(){}
        /**
     * @brief Dodaje nową rezerwację do kontenera.
     * @param obj Wpis rezerwacji typu booking_entry.
     */
    void addBooking(booking_entry obj);

    /**
     * @brief Wyświetla wszystkie rezerwacje na standardowe wyjście.
     */
    void printBookings()const;

    /**
     * @brief Sortuje rezerwacje wg daty rosnąco.
     */
    void sortBookingsByDate();
protected:
    Container m_bookings;
};
