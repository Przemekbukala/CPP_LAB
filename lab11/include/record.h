#pragma once
#include "logger.h"
class GuestInfo{
    public:
    GuestInfo(){
        Logger::get_logger().log("GuestInfo");
    }
    ~GuestInfo(){}
};
class RoomAssignment{
    public:
    RoomAssignment(){
        Logger::get_logger().log("RoomAssignment");
    }
    ~RoomAssignment(){}

};
class ClientRecord: public GuestInfo,public RoomAssignment {
    public:
    ClientRecord():GuestInfo(),RoomAssignment(){
        Logger::get_logger().log("ClientRecord");
    }
};