#include "../include/Dir.h"
#include "../include/File.h"
#include "../include/FileSystemElement.h"
#include "Link.h"
void Dir::printInfo(std::ostream& o, int indent) const{
    for(int i=0;i<indent;i++){
        o<<" ";
    }
    o<<" Dir: "<<_name<<std::endl;
    for(auto &i: _tab){
        i->printInfo(o,indent+1);
        
    }
}
void Dir::add(std::unique_ptr<FileSystemElement> element){
    _tab.push_back(std::move(element));
}

std::string Dir::get_name() const{
    return _name;
}

void Dir::rm(const char *name,bool flaga){
    for( auto i=_tab.begin();i!=_tab.end();i++){
        if((*i)->get_name()==name &&  flaga==false){
            _tab.erase(i);
            return;
        } else if(Dir *dir=dynamic_cast<Dir*>(i->get())){
            dir->rm(name,false);
        }
        else if((*i)->get_name()==name &&  flaga==true){
            if(Link *link= dynamic_cast<Link*>(i->get())){
                std::string name_to_check=link->get_ptr()->get_name();
                _tab.erase(i);
                rm(name_to_check.c_str(),true);
                return;
            }else if(Dir *dir=dynamic_cast<Dir*>(i->get())){
                dir->rm(name,true);
            }else{
                _tab.erase(i);
                return;
            }
        }
    }
}
