#pragma once
#include "BookingManager.h"
/**
 * @file BookingUtils.h
 * @brief Namespace z szablonem funkcji do ekstrakcji pola z krotki rezerwacji.
 *
 * Funkcja extractField jest szablonem umożliwiającym pobranie pola z krotki
 * (domyślnie trzecie pole - liczba noclegów).
 */
namespace BookingUtils{
    /**
     * @brief Szablon funkcji do wyciągania pola z krotki booking_entry.
     * @tparam index Indeks pola do wyciągnięcia (domyślnie 2 - liczba noclegów).
     * @param obj Krotka rezerwacji.
     * @return Wartość pola o indeksie index.
     */
    template<int index=2> auto extractField(const booking_entry& obj){    
        return std::get<index>(obj);
    }
    
};