#include "Link.h"
void   Link::printInfo(std::ostream& o, int indent,int flaga) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    if (flaga==1){
        o<<" Link: "<<_name<<"    size: "<<get_size()<<" data: "<<_date<<std::endl;
    }else
    o<<" Link: "<<_name<<std::endl;
}
unsigned  Link::get_size() const{
    return _size;
}
std::string Link::get_name() const{
    return _name;
}
