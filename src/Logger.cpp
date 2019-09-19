#include <iostream>
#include <fstream>
#include "Logger.h"

using namespace std;
using std::string;

    ofstream archivoRegistro;

    Logger::Logger(LogLevel level) {
        Errorlevel = level;
        archivoRegistro.open("log.txt", ios::out);

        if (Errorlevel <= INFO) {
            archivoRegistro << "[" << LogLevelNames[Errorlevel] << "]: " << "LOGGER EN MODO: " << LogLevelNames[Errorlevel] << std::endl;
        }
    }

    Logger::~Logger() {
        if (Errorlevel <= INFO) {
            archivoRegistro << "[" << LogLevelNames[Errorlevel] << "]: " << "LOGGER DESTRUIDO" << std::endl;
        }
        archivoRegistro.close();
    }

    void Logger::log(LogLevel level, string message) {
            if (Errorlevel <= level) {
                archivoRegistro << "[" << LogLevelNames[Errorlevel] << "]: " << message << std::endl;
        }
     }
