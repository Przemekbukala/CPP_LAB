#pragma once
#include "IUser.h"
class Guest :public virtual IUser{
    public:
    Guest(std::string name,Type typ):IUser(name,typ){
    }
    void  printRole()const{
        std::cout<<"[Info]: "<<_name<<" (role: Guest)"<<std::endl;
    }
    void  performRoleAction() const{
        makeReservation();
    }
    void makeReservation() const {
        std::cout<<"[Info]: "<<_name<<" is making reservation for: Room 401"<<std::endl;
    }
};