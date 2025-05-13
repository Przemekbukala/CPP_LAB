#include "../include/Directory.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
void File::print(std::ostream& o, int indent) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    o<<" File: "<<_name<<std::endl;
}
