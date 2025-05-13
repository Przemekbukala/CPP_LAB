#include "../include/Dir.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
#include "Link.h"
void Dir::printInfo(std::ostream& o, int indent, int flaga) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    if(flaga==1){
        o<<" Dir: "<<_name<<"    size: "<<get_size()<<" data: "<<_date<<std::endl;
        for(auto &i: _tab){
            i->printInfo(o,indent+1,1);
        }
    } else{
    o<<" Dir: "<<_name<<std::endl;
    for(auto &i: _tab){
        i->printInfo(o,indent+1);
    }
    }
}
void Dir::ls() const{
    for(auto &i: _tab){
        if (typeid(*i)==typeid(Dir)){
            std::cout<<"Dir: "<<(*i).get_name()<<" Rozmiar:"<<(*i).get_size()<<std::endl;
        }
        if (typeid(*i)==typeid(File)){
            std::cout<<"File: "<<(*i).get_name()<<" Rozmiar:"<<(*i).get_size()<<std::endl;
        }
        
        if (typeid(*i)==typeid(Link)){
            std::cout<<"Link: "<<(*i).get_name()<<" Rozmiar:"<<(*i).get_size()<<std::endl;
        }
        // i->printInfo(o,indent+1,1);
    }
}

void Dir::add(std::unique_ptr<FileSystemElement> element){
    _tab.push_back(std::move(element));
}
void  Dir::printElementsInfo() const{
    printInfo(std::cout,0,1);
}
unsigned  Dir::get_size() const{
    unsigned size=1;
    for(const auto &i: _tab){
        size+=(*i).get_size();
    }
    return size;
}
std::string Dir::get_name() const{
    return _name;
}
