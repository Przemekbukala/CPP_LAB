#include "BookingManager.h"
#include "logger.h"
#include <algorithm>
void  BookingManager::addBooking(booking_entry obj){
    m_bookings.push_back(obj);
    Logger::get_logger().log("[INFO] Added booking for "+std::get<0>(obj));
}
void BookingManager::printBookings()const{
    std::for_each(m_bookings.begin(),m_bookings.end(),[](const booking_entry& obj){
        std::cout<< std::left <<"Name: "<< std::setw(16)<<std::get<0>(obj)<< std::setw(6) <<"Date:"<<std::setw(12) <<std::get<1>(obj)<<std::setw(8) <<"Nights:"<<std::get<2>(obj)<<std::endl;
    });
}
void BookingManager::sortBookingsByDate(){
    Logger::get_logger().log("[INFO] Bookings sorted by date.");
    std::sort(m_bookings.begin(),m_bookings.end(),[](const booking_entry &obj,const booking_entry &obj2){
    
        return (std::get<1>(obj))<(std::get<1>(obj2));
    });
}
