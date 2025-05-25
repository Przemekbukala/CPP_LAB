#pragma once
#include "IUser.h"
#include <iostream>
class Staff :public virtual IUser{
    public:
    Staff(std::string name,Type typ):IUser(name,typ){
    }
    void  printRole()const{
        std::cout<<"[Info]: "<<_name<<" (role: Staff)"<<std::endl;
    }
     void  performRoleAction() const{
        manageReservation();
    }
    void manageReservation()const{
        std::cout<<"[Info]: "<<_name<<" is managing reservations."<<std::endl;
    }
};