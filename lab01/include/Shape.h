#pragma once
#include <string>
#include "iostream"
/**
 * @class Shape
 * @brief Bazowa klasa reprezentująca kształt.
 */
class Shape{
    public:
     /**
     * @brief Konstruktor klasy Shape.
     * @param name nazwa kształtu.
     */
    Shape(std::string name=""):_name(name){}
        /**
     * @brief Oblicza pole powierzchni kształtu.
     * @return Pole.
     */
    virtual double Area(){
        return 0.;
    }
    
    /**
     * @brief Ustawia nazwę kształtu.
     * @param name nowa nazwa kształtu.
     */
    void set_name(std::string name){
        _name=name;
    }
    /**
     * @brief Pobiera nazwę kształtu.
     * @return nazwa kształtu.
     */
    std::string get_name() const{
        return _name;
    }
    private:
    std::string _name;
};