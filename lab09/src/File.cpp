#include "../include/Dir.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
void File::printInfo(std::ostream& o, int indent) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    o<<" File: "<<_name<<std::endl;
}

std::string File::get_name() const{
    return _name;
}
