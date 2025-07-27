#pragma once
#include <iostream>
#include <string>
#include "ctime"
void  inline time(){
     std::time_t result = std::time(nullptr);
    std::string date_time = std::asctime(std::localtime(&result));
    date_time.pop_back(); //  Usuń znak nowej linii na końcu
    std::cout << date_time;
}

/**
 * @brief Klasa Logger implementująca singleton do logowania.
 * 
 * Zapewnia globalny dostęp do jednej instancji loggera oraz metody logujące komunikaty
 * z aktualnym czasem. Logi wypisywane są na standardowe wyjście.
 */
class Logger{
    public:
        /**
     * @brief Zwraca instancję singletona loggera.
     * @return Referencja do singletona Logger.
     */
    static Logger& get_logger();
    /**
     * @brief Loguje wiadomość z aktualnym czasem i adresem loggera.
     * @param log Treść logu do wypisania.
     */
    void log(std::string log);
    protected:
        /**
     * @brief Konstruktor chroniony - wymuszony wzorzec Singleton.
     */
    Logger(){}
      /**
     * @brief Destruktor logera.
     */
    ~Logger(){
        std::cout<<"sfaksdafnondsfindsf";
    }
        /**
     * @brief Statyczny obiekt loggera (singleton).
     */
    static Logger first;
};
/**
 * @brief Klasa pomocnicza do logowania w stylu zaawansowanym.
 */
class Log{
    public:
    static void Advanced(std::string log);
};