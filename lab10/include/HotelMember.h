#pragma once
#include "IUser.h"
#include "Staff.h"
#include "Guest.h"
class HotelMember : public Guest, public Staff{
    public:
    HotelMember(std::string name,Type typ):Guest(name,typ),Staff(name,typ),IUser(name,typ){}
    void  printRole()const{
        if(_typ==Type::STAFF){
            Staff::printRole();
        }else if(_typ==Type::GUEST){
            Guest::printRole();
        }
    }
    void  performRoleAction() const{
        if(_typ==Type::STAFF){
            Staff::manageReservation();
        }else if(_typ==Type::GUEST){
            Guest::makeReservation();
        }
    }
    private:

};