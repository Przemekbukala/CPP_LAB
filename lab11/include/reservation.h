#pragma once

#include "booking.h"
// z kodem ReservationSystem jest problem albowiem  ReservationSystem dziedziczy po BookingManager, a BookingManager dziedziczy po ReservationSystem 
#ifdef COMPILATION_ISSUE

class ReservationSystem : public BookingManager {
public:
    ReservationSystem() {
        std::cout << "ReservationSystem" << std::endl;
    }
};
#endif
