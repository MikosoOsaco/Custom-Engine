#pragma once

#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <fstream>
#include <iomanip>
#include <string>

/*
	Original code by Rob Robson.
	Adapted and added onto by Miguel Favero. 
*/

class LogManager
{
public:
	enum LogLevel {LOG_NONE, LOG_ERROR, LOG_WARN, LOG_TRACE, LOG_INFO};
	std::string defaultLogFileName;

private:
	static LogManager	*theInstance;
	std::ofstream		*outStream;
	LogLevel			currentSeverity;

	LogManager(void);
	LogManager(LogLevel severity, std::string fileName);

public:

	static LogManager& getInstance();
	static LogManager& getInstance(LogLevel severity, std::string fileName);


	~LogManager(void);

	void setLogFile(std::string &fileName);
	
	void close();

	void setSeverity(LogLevel severity)
	{
		currentSeverity = severity;
	}

	LogLevel getSeverity()
	{
		return currentSeverity;
	}

	void log(LogLevel severity, std::string msg);
	
	void error(std::string msg)
	{
		log(LOG_ERROR, msg);
	}
	
	void warn(std::string msg)
	{
		log(LOG_WARN, msg);
	}

	void trace(std::string msg)
	{
		log(LOG_TRACE, msg);
	}

	void info(std::string msg)
	{
		log(LOG_INFO, msg);
	}
};

#endif
