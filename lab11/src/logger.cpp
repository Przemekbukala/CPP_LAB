#include "../include/logger.h"
#include <ctime>
Logger Logger::first;
Logger& Logger::get_logger(){
    if(&first==nullptr){
        first=Logger();
        return (first);
    }else{
        return (first);
    }
    }
void Logger::log(std::string log){
    time();
    std::cout<<" ["<<"Logger"<<"]"<<" "<<&(Logger::get_logger())<<" "<<log<<std::endl;

}   
void Log::Advanced(std::string log){
    time();
    std::cout<<" ["<<"AdvLogger"<<"]"<<" "<<&(Logger::get_logger())<<" "<<log<<std::endl;
}