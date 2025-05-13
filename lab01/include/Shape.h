#pragma once
#include <string>
#include "iostream"
class Shape{
    public:
    Shape(std::string name=""):_name(name){}
    virtual double Area(){
        return 0.;
    }
    void set_name(std::string name){
        _name=name;
    }
    std::string get_name() const{
        return _name;
    }
    private:
    std::string _name;
};