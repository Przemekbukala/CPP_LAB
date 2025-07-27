#include "../include/logger.h"
#include <ctime>
Logger Logger::first;
Logger& Logger::get_logger() {
    first=Logger();
    return first;
}
void Logger::log(std::string log){
    std::cout<<log<<std::endl;
}   