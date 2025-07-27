#pragma once
#include "Shape.h"
/**
 * @class Circle
 * @brief Klasa reprezentująca koło, dziedziczy po Shape.
 * Zawiera promień oraz pozwala sumowanie promieni.
 */
class Circle: public Shape{
    public:
    /**
     * @brief Przeciążony operator do wypisywania prostokąta.
     * @param o Strumień wyjściowy.
     * @param obj Obiekt koła.
     * @return Zmodyfikowany strumień wyjściowy z informacją o obiektcie Circle.
     */
    friend std::ostream &operator<<(std::ostream &o,const Circle &obj);
    /**
     * @brief Oblicza pole powierzchni koła.
     * @return Pole powierzchni.
     */
    double Area(){
        return 3.14*_radius*_radius;
    }
    /**
     * @brief Konstruktor domyślny koła.
     * @param radius Promień koła (domyślnie 0).
     */
    Circle(double radius=0):_radius(radius){
    }
    /**
     * @brief Konstruktor koła z nazwą i promieniem.
     * @param name Nazwa koła.
     * @param radius Promień koła.
     */
    Circle(std::string name,double radius):_radius(radius),Shape(name){}

    /**
     * @brief Operator dodawania dwóch kół.
     * @param obj Drugie koło.
     * @return Nowe koło o promieniu będącym sumą promieni.
     */
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