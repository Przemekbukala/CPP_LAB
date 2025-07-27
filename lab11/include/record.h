#pragma once
#include "logger.h"
/**
 * @brief Klasa reprezentująca informacje o gościu.
 * 
 * W konstruktorze wywoływany jest log informujący o utworzeniu obiektu typu GuestInfo.
 */
class GuestInfo{
    public:
        /**
     * @brief Konstruktor klasy GuestInfo.
     * 
     * Loguje utworzenie instancji klasy GuestInfo.
     */
    GuestInfo(){
        Logger::get_logger().log("GuestInfo");
    }
        /**
     * @brief Destruktor klasy GuestInfo.
     */
    ~GuestInfo(){}
};
/**
 * @brief Klasa reprezentująca przypisanie pokoju.
 * 
 * W konstruktorze logowane jest utworzenie obiektu klasy RoomAssignment.
 */
class RoomAssignment{
    public:
        /**
     * @brief Konstruktor klasy RoomAssignment.
     * 
     * Loguje utworzenie instancji klasy RoomAssignment.
     */
    RoomAssignment(){
        Logger::get_logger().log("RoomAssignment");
    }

    /**
     * @brief Destruktor klasy RoomAssignment.
     */
    ~RoomAssignment()=default;

};

/**
 * @brief Klasa reprezentująca pełny rekord klienta.
 * 
 * Dziedziczy po GuestInfo i RoomAssignment. Konstruktor wywołuje konstruktory klas bazowych
 * i dodatkowo loguje stworzenie obiektu typu ClientRecord.
 */
class ClientRecord: public GuestInfo,public RoomAssignment {
    public:
       /**
     * @brief Konstruktor klasy ClientRecord.
     * 
     * Inicjalizuje obiekty klas bazowych GuestInfo i RoomAssignment oraz loguje stworzenie instancji.
     */
    ClientRecord():GuestInfo(),RoomAssignment(){
        Logger::get_logger().log("ClientRecord");
    }
};