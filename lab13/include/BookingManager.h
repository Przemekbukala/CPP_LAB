#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

/**
 * @brief Typ kontenera przechowującego rezerwacje.
 * Każda rezerwacja to krotka: (Imię i nazwisko, Data, Liczba noclegów).
 */
using Container=std::vector<std::tuple<std::string,std::string,int>>;

/**
 * @brief Typ pojedynczej rezerwacji (elementu kontenera).
 */
using booking_entry=Container::value_type;
/**
 * @file BookingManager.h
 * @brief Definicja klasy zarządzającej rezerwacjami.
 *
 * Klasa BookingManager przechowuje rezerwacje w kontenerze,
 * umożliwia dodawanie, wyświetlanie, sortowanie i dostęp do rezerwacji.
 */
class BookingManager
{
public:
    /**
     * @brief Konstruktor inicjalizujący pustą listę rezerwacji.
     */
    BookingManager():m_bookings({}){}

    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~BookingManager(){}

    /**
     * @brief Dodaje nową rezerwację.
     * @param obj Wpis rezerwacji typu booking_entry.
     */
    void addBooking(booking_entry obj);\
        /**
     * @brief Wyświetla listę wszystkich rezerwacji na standardowe wyjście.
     */
    void printBookings()const;
        /**
     * @brief Sortuje rezerwacje według daty (rosnąco).
     */
    void sortBookingsByDate();
        /**
     * @brief Zwraca referencję do kontenera rezerwacji.
     * @return Referencja do kontenera m_bookings.
     */
    Container& getBookings();
protected:
    Container m_bookings;
};
