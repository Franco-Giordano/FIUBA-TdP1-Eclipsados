#include <iostream>
#include <fstream>
#include "Logger.h"

#include <chrono>
#include <ctime>



using namespace std;

ofstream archivoRegistro;

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {

  if (instance == nullptr)
    instance = new Logger;

  return instance;
}

void Logger::setLevel(LogLevel level) {

/*	PRIMERAS PRUEBAS AGREGANDO FECHA Y HORA
	std::chrono::time_point<std::chrono::system_clock> dateTime = std::chrono::system_clock::now();
	std::time_t dateTime_t = std::chrono::system_clock::to_time_t(dateTime);*/

	Errorlevel = level;
	archivoRegistro.open("logs/log.txt", ios::out);

	if (Errorlevel <= INFO) {
		archivoRegistro << "[" << LogLevelNames[INFO] << "]: "<< "LOGGER EN MODO: " << LogLevelNames[Errorlevel] << std::endl;
	}
}

Logger::~Logger() {
	if (Errorlevel <= INFO) {
		archivoRegistro << "[" << LogLevelNames[INFO] << "]: " << "LOGGER DESTRUIDO" << std::endl;
	}
	archivoRegistro.close();
}

void Logger::log(LogLevel level, string message) {
		if (Errorlevel <= level) {
			archivoRegistro << "[" << LogLevelNames[level] << "]: " << message << std::endl;
	}
 }
