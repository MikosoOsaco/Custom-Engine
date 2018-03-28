#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#pragma once

#include "Clock.h"
#include "LogManager.h"
#include "AbstractRenderer.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	virtual void onStart() = 0;
	virtual void onEnd() = 0;
	virtual void render() = 0;
	//LogManager logMessage();
};

#endif // !GAME_ENGINE_H


