#pragma once
#include "Shape.h"
class Circle: public Shape{
    public:
    friend std::ostream &operator<<(std::ostream &o,const Circle &obj);
    double Area(){
        return 3.14*_radius*_radius;
    }
    Circle(double radius=0):_radius(radius){
    }
    Circle(std::string name,double radius):_radius(radius),Shape(name){}
    Circle operator+(const Circle &obj){
        Circle tmp(obj._radius+this->_radius);
        tmp.set_name("Combined");
        return tmp;
    }
    private:
    double _radius;
};
inline std::ostream &operator<<(std::ostream &o,const Circle &obj){
    return o<<"Circle: "<<obj.get_name()<<" (radius="<<obj._radius<<")";
}