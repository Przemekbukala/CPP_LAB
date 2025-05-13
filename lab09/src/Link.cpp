#include "Link.h"
void   Link::printInfo(std::ostream& o, int indent) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    o<<"[LINK] "<<_name<<" -> "<<_ptr->get_name()<<std::endl;
}

std::string Link::get_name() const{
    return _name;
}
FileSystemElement* Link::get_ptr() const{
    return _ptr;
}
