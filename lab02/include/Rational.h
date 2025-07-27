#pragma once 
#include <iostream>
/**
 * @class Rational
 * @brief Reprezentuje liczbę wymierną w postaci ułamka p/q.
 *
 */
class Rational{
    public:
    friend std::ostream &operator<<(std::ostream &o,const Rational &obj);
    /**
     * @brief Konstruktor liczby wymiernej.
     * @param p Licznik ułamka.
     * @param q Mianownik ułamka !=0.
     */
    Rational(int p,int q):_p(p),_q(q){}
        /**
     * @brief Operator niejawnej konwersji do double.
     * @return Wartość ułamka jako liczba zmiennoprzecinkowa.
     */
     operator double() const{
        return _p*1.0/_q;
    }

    /**
     * @brief Operator jawnej konwersji do int.
     * @return Część całkowita ułamka.
     */
    explicit operator int() const{
        return _p/_q;
    }
     /**
     * @brief Operator post-inkrementacji (r++).
     * Zwiększa ułamek o 1 i zwraca starą wartość.
     * @return Kopia obiektu przed inkrementacją.
     */
    Rational operator ++(int) {

        Rational temp=*this;
        _p+=_q;
        return temp;
    }

    /**
     * @brief Operator pre-inkrementacji (++r).
     * Zwiększa ułamek o 1 i zwraca zmodyfikowany obiekt.
     * @return Referencja do zmodyfikowanego obiektu.
     */
    Rational& operator++() {
        _p+=_q;
        return *this;
    }

    /**
     * @brief Upraszcza ułamek do najprostszej postaci.
     * Metoda znajduje największy wspólny dzielnik (NWD) licznika i mianownika,
     * a następnie dzieli licznik i mianownik przez ten dzielnik.
     */
    void simplify(){
        int temp;
        int a=_p;
        int b=_q;
        while (b!=0)
        {
            temp= a%b;
            a=b;
            b=temp;
        }
        std::cout<<"Uproszone o :"<<a<<std::endl;
        _p/=a;
        _q/=a;
        }
    private:
    int _p;
    int _q;
};
std::ostream &operator<<(std::ostream &o,const Rational &obj){
    return o<<obj._p<<"/"<<obj._q;
}