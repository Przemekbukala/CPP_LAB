#pragma once
#include <iostream>
#include <string>
enum class Type{
    GUEST,STAFF
};
class IUser{
    public:
    IUser(){
    }
    void virtual printRole()const=0;
    void virtual performRoleAction() const=0;
    std::string  getName() const{
    return _name;
    }
    protected:
    std::string _name;
    Type _typ;
    IUser(std::string name,Type typ):_name(name),_typ(typ){
    }
};