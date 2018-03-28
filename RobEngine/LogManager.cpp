#include "LogManager.h"

LogManager* LogManager::theInstance = NULL;

LogManager::LogManager(void)
{
	outStream = NULL;
	defaultLogFileName = "logfile.log";
	currentSeverity = LOG_ERROR;
}

LogManager::LogManager(LogLevel severity, std::string fileName)
{
	outStream = NULL;
	defaultLogFileName = fileName.c_str();
	currentSeverity = severity;
}

LogManager::~LogManager(void)
{
	close();
}

LogManager& LogManager::getInstance(void)
{
	if(theInstance == NULL)
	{
		theInstance = new LogManager();
	}
	return *theInstance;
}

LogManager& LogManager::getInstance(LogLevel severity, std::string fileName)
{
	if (theInstance == NULL)
	{
		theInstance = new LogManager(severity, fileName);
	}
	return *theInstance;
}

void LogManager::setLogFile(std::string &fileName)
{
	close();
	outStream = new std::ofstream(fileName.c_str());
	//currentSeverity = LOG_INFO;
}

void LogManager::close()
{
	if(outStream != NULL)
	{
		outStream->close();
		delete outStream;
		outStream = NULL;
	}
}

void LogManager::log(LogLevel severity, std::string msg)
	{
		if(severity <= currentSeverity && currentSeverity > LOG_NONE)
		{
			if(outStream == NULL)
			{
				setLogFile(defaultLogFileName);
			}
			(*outStream) << msg << "\n";
			outStream->flush();
		}
	}
