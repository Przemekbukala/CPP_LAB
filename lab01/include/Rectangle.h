#pragma once
#include "Shape.h"
class Rectangle : public Shape{
    public:
    friend std::ostream &operator<<(std::ostream &o,const Rectangle &obj);
    double Area(){
    return _width*_height;
    }
    Rectangle(std::string name,double width,double height):Shape(name),_width(width),_height(height){
    }
    Rectangle& operator*(int skalowanie){
    this->_height*=skalowanie;
    this->_width*=skalowanie;
    return *this;
    }
    private:
    double _width;
    double _height;
};
inline std::ostream &operator<<(std::ostream &o,const Rectangle &obj){
    return o<<"Rectangle: "<<obj.get_name()<<" (width="<<obj._width<<", height="<<obj._height<<")";
}