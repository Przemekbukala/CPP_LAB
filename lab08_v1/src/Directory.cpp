#include "../include/Directory.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
void Directory::print(std::ostream& o, int indent) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    o<<" Dir: "<<_name<<std::endl;
    for(auto &i: _tab){
        i->print(o,indent+1);
    }
}
void Directory::add(std::unique_ptr<FileSystemElement> element){
    _tab.push_back(std::move(element));
}
