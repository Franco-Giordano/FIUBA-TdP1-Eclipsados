#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
using std::string;

enum LogLevel { DEBUG, INFO, ERROR };

class Logger {
public:
    string LogLevelNames[3] = { "DEBUG", "INFO", "ERROR" };
    Logger(LogLevel level);
    ~Logger();
    void log(LogLevel level, string message);
private:
    LogLevel Errorlevel = DEBUG;
};

#endif /* LOGGER_H_ */
