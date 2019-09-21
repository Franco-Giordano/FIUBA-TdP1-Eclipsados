#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
using std::string;

enum LogLevel { DEBUG, INFO, ERROR };

class Logger {

public:
    static Logger* getInstance();
    string LogLevelNames[3] = { "DEBUG", "INFO", "ERROR" };
    ~Logger();
    void setLevel(LogLevel level);
    void log(LogLevel level, string message);

private:
    LogLevel Errorlevel = DEBUG;
    static Logger* instance;
    Logger(Logger const&);
    Logger& operator=(Logger const&);
    Logger() {};
    string datetime();

};

#endif /* LOGGER_H_ */
