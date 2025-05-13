#include "../include/Dir.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
void File::printInfo(std::ostream& o, int indent,int flaga) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    if(flaga==1){
        o<<" File: "<<_name<<"    size: "<<get_size()<<" data: "<<_date<<std::endl;
    } else
    o<<" File: "<<_name<<std::endl;
}
unsigned  File::get_size() const{
    return _size;
}
std::string File::get_name() const{
    return _name;
}
