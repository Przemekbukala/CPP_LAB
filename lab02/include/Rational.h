#pragma once 
#include <iostream>
class Rational{
    public:
    friend std::ostream &operator<<(std::ostream &o,const Rational &obj);
    Rational(int p,int q):_p(p),_q(q){}
     operator double() const{
        return _p*1.0/_q;
    }
    explicit operator int() const{
        return _p/_q;
    }
    Rational operator ++(int) {

        Rational temp=*this;
        _p+=_q;
        return temp;
    }
    Rational& operator++() {
        _p+=_q;
        return *this;
    }

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