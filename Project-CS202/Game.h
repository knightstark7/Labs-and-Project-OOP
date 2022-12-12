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
	void gameSettings();
	bool newGame(); // start a new game, initialize Map map
	bool continueGame();  //continue our game
	bool loadGameMenu(); // get file of Map map
	void saveGameMenu(); //void saveGame(); // print file of Map map
	void pauseMenu(int cmd);
	void togglePauseGame(); // toggle status of isPausing
	void toggleMute();
	void toggleHard();
	void gameOver();
	void playGame(bool &is_finish);
	vector<string> getAllFilename(const std::string &name);
	void menu();
	bool continueMenu();
};
