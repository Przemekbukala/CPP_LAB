#pragma once
#include "BookingManager.h"
#include <string>
/**
 * @class Logger
 * @brief Singleton odpowiedzialny za logowanie informacji.
 *
 */
class Logger : public BookingManager{
    public:
            /**
     * @brief Zwraca referencję do singletona loggera.
     * @return Referencja do Logger.
     */
    static Logger& get_logger();
        /**
     * @brief Loguje komunikat na standardowe wyjście.
     * @param log Tekst komunikatu do zalogowania.
     */
    void log(std::string log);
    private:
          /// Konstruktor prywatny 
    Logger(){}
        /// Destruktor prywatny
    ~Logger(){
    }
    static Logger first;
};