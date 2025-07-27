#pragma once 
class Punkt{
    public:
    // Konstruktor inicjiulizujacy skladniki _x i _y
    explicit Punkt(int x,int y):_x(x),_y(y){}
    // funckja szablonowa podająca wsp w zaleznosci od <int n>
    template <int n>const int& wsp()const{
    return n==0 ? _x : _y;
    }
    // przeladowany operator<
    bool operator<(const Punkt& obj)const{
        if(_x<obj._x){
            return true;
        }else if(_x==obj._x) {
            if (_y<obj._y)
            {
                return true;
            }else {
                return false;
            }
        } else{
            return false;
        } 
    }
    // szablonow funkcja statyczna zwracajaca najwiekszy element wytypowany przez operator<
    template<typename T> 
    static const T& max(const T& obj1,const T& obj2){
            if(obj1<obj2){
                return obj2;
            }else{
                return obj1;
            }
    } 
    // szablonow funkcja statyczna zwracajaca najmneijszy element wytypowany przez operator<
    template<typename T> 
    static const T& min(const T& obj1,const T& obj2){
            if(!(obj1<obj2)){
                return obj2;
            }else{
                return obj1;
            }
    } 
    private:
    int _x;
    int _y;
};