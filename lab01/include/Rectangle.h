#pragma once
#include "Shape.h"
/**
 * @class Rectangle
 * @brief Klasa reprezentująca prostokąt, dziedziczy po Shape.
 */
class Rectangle : public Shape{
    public:
        /**
     * @brief Przeciążony operator do wypisywania prostokąta.
     * @param o Strumień wyjściowy.
     * @param obj Obiekt prostokąta.
     * @return Zmodyfikowany strumień wyjściowy z informacją o obiektcie Rectangle.
     */
    friend std::ostream &operator<<(std::ostream &o,const Rectangle &obj);
    /**
     * @brief Oblicza pole powierzchni prostokąta.
     * @return Pole powierzchni.
     */
    double Area(){
    return _width*_height;
    }
    /**
     * @brief Konstruktor prostokąta.
     * @param name Nazwa prostokąta.
     * @param width Szerokość prostokąta.
     * @param height Wysokość.
     */
    Rectangle(std::string name,double width,double height):Shape(name),_width(width),_height(height){
    }
    /**
     * @brief Skalowanie wymiarów prostokąta przez mnożenie.
     * @param skalowanie Współczynnik skalowania.
     * @return Referencja prostokąta (objekt Rectangle).
     */
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