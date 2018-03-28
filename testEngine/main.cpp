/*#include "..\RobEngine\Clock.h"
#include "..\RobEngine\LogManager.h"
#include "..\RobEngine\Window.h"

#include <iostream>


int main(int argc, char* args[])
{
	Clock *clock;
	clock->init();

	float seconds = 0;

	LogManager::getInstance(LogManager::LOG_INFO, "FileTest.log").info("INFO");
	LogManager::getInstance().warn("WARN");
	LogManager::getInstance().setSeverity(LogManager::LOG_ERROR);
	LogManager::getInstance().trace("TRACE"); //wont print because severity filter has been increased
	LogManager::getInstance().error("ERROR");


	if (clock->isReady())
	{
		LogManager::getInstance().error("is ready");
	}
	else
	{
		LogManager::getInstance().error("NOT ready");
	}

	LogManager::getInstance().error(std::to_string(clock->getCurrentMinutes()));

	LogManager::getInstance().error(
		"Time since clock init =  " + 
		std::to_string(clock->getCurrentHours()) + "hr"
		+ " : " + 
		(std::to_string(60 - (((clock->getCurrentHours() + 1) * 60) - clock->getCurrentMinutes()))) + "min"
		);

	while(true)
		std::cout << clock->getCurrentSeconds() << std::endl;


	//seconds = clock->getCurrentTime;

	LogManager::getInstance().close();

	Window *window = new Window("SDL FINAL", 800, 600); //create window

	while (true)
	{
		window->clear();
	}

	return 0;
}*/