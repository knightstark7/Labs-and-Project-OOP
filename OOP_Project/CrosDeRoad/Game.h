#pragma once
#include "head.h"
#include "Console.h"
#include "People.h"
#include "Enemy.h"
#include "cRows.h"
#include "Map.h"

class Game{	
	bool isLoaded = false;
	Map map;
	bool isPausing = false;
public:
	Game() = default;
	~Game() = default;
	void menu();
	void gameSetting();
	bool newGame(); 
	bool continueMenu();
	bool loadGameMenu();
	void saveGameMenu(); 
	void togglePause(); // toggle status of isPausing
	void toggleMute();
	void toggleHard();
	vector<string> getFile(const std::string &name);
};
