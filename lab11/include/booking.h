#pragma once

#include <iostream>

/**
 * @brief Klasa reprezentująca informacje o gościu.
 * 
 * W konstruktorze wywoływany jest log informujący o utworzeniu obiektu typu GuestInfo.
 */
class ReservationSystem;

#ifdef COMPILATION_ISSUE
class BookingManager : public ReservationSystem {
public:
    BookingManager() {}
};
#endif
