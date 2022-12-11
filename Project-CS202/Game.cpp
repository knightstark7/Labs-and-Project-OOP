#include "Game.h"

void Game::gameSettings() {
	system("cls");
	const char *setting[3] = { "Mode", "Sound", "Back" };
	char *currentSettting[3] = { "EASY", "ON", "" };
	if (constantVar::isHard) {
		currentSettting[0] = "HARD";
	}
	else
	{
		currentSettting[0] = "EASY";
	}
	if (constantVar::isMute) {
		currentSettting[1] = "OFF";
	}
	else {
		currentSettting[1] = "ON ";
	}
	int pos1 = 0;
	const int y = 20;
	const int x = 25;
	int flag = 0;
	map.printBorder();
	bool currentKey = true;
	while (1) {
		if (currentKey) {
			TextColor(7);
			drawTitle();
			for (int i = 0; i < 3; i++) {
				if (i == pos1) {
					gotoXY(x, y + i);
					TextColor(227);
					cout << setting[i] << " " << currentSettting[i];
					TextColor(7);
				}
				else {
					gotoXY(x, y + i);
					cout << setting[i] << " " << currentSettting[i];
					TextColor(7);
				}
			}
			TextColor(7);
			currentKey = false;
		}
		while (1) {
			if (kbhit()) {
				currentKey = true;
				char key = getch();
				if (key == 'W' || key == 'w') {
					pos1--;
					pos1 = (pos1 + 3) % 3;
					break;
				}
				if (key == 'S' || key == 's') {
					pos1++;
					pos1 %= 3;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						//Game mode : easy || hard
						toggleHard();
						if (constantVar::isHard) {
							currentSettting[0] = "HARD";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						else
						{
							currentSettting[0] = "EASY";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						break;
					}
					case 1: {
						toggleMute();
						if (constantVar::isMute) {
							currentSettting[1] = "OFF";
							if (constantVar::isMute)PlaySound(NULL("PUBG.wav"), NULL, SND_APPLICATION);
						}
						else {
							currentSettting[1] = "ON ";
							PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
							PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
						}
						break;
					}
					case 2: {
						system("cls");
						flag = 1;
						TextColor(7);
						return;
					}
					}
					break;
				}

			}
		}
		
	}
	return;
}


void Game::menu() {
	const string choice[4] = { "NEW GAME", "LOAD GAME", "OPTIONS", "EXIT"};
	int pos = 0;
	int x = 35, y = 20;
	if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
	bool changeInput = true;
	while (true) {
		changeInput = true;
		map.printBorder();
		if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
		while (true) {
			if (changeInput) {
				for (int i = 0; i < 4; i++) {
					if (i == pos) {
						gotoXY(x, y + i);
						TextColor(227);
						cout << choice[i];
						TextColor(7);
					}
					else {
						gotoXY(x, y + i);
						cout << choice[i];
						TextColor(7);
					}
				}
				int color = rand() % 7;
				TextColor(color);
				gotoXY(20, 11); cout << "  ______ .______        ______       _______.   _______. __ .__   __.  _______ " << endl;
				gotoXY(20, 12); cout << " /      ||   _  \\      /  __  \\     /      |   /       ||  ||  \\ |  | /  _____|" << endl;
				gotoXY(20, 13); cout << "|  ,----'|  |_)  |    |  |  |  |   |   (----` |   (----`|  ||   \\|  ||  |  __  " << endl;
				gotoXY(20, 14); cout << "|  |     |      /     |  |  |  |    \\   \\      \\   \\    |  ||  . `  ||  | |_ | " << endl;
				gotoXY(20, 15); cout << "|  `----.|  |\\  \\----.|  `--'  |.----)   | .----)   |   |  ||  |\\   ||  |__| | " << endl;
				gotoXY(20, 16); cout << " \\______|| _| `._____| \\______/ |_______/  |_______/    |__||__| \\__| \\______| " << endl;
				gotoXY(20, 17); cout << "" << endl;
				TextColor(7);
			}
			changeInput = false;
			switch (inputKey()) {
				changeInput = true;
				PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
			case 'w':
				changeInput = true;
				pos--;
				pos = (pos + 4) % 4;
				break;
			case 's':
				changeInput = true;
				pos++;
				pos %= 4;
				break;
			case 13:
				switch (pos) {
				case 0:
					while (1) {
						if (newGame()) {
							Sleep(1000);
							clrscr();
							map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;//return; // thang nhung k choi tiep
							Sleep(1000);
						}
						else if (!continueMenu()) {
							if (isLoaded) {
								map.~Map();
								new(&map) Map;
							}
							Sleep(1000);
							clrscr();
							map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;//return; //thua nhung khong choi tiep
						}
					}
					break;
				case 1: {
					Sleep(1000);
					if (loadGameMenu()) {
						while (1) {
							if (newGame()) {
								Sleep(1000);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;//return; // thang nhung k choi tiep
								Sleep(1000);
							}
							else if (!continueMenu()) {
								Sleep(1000);
								TextColor(7);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;//return; //thua nhung khong choi tiep
							}
						}
					}
					else {
						changeInput = true;
						map.printBorder();
					}
				}break;
				case 2: {
					Sleep(500);
					gameSettings();
					changeInput = true;
					map.printBorder();
				}break;
				case 3:
					clrscr();
					return;
				}
				break;
			}
		}
	}
}

bool Game::continueMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();
	map.bombEffect();
	
	gotoXY(20, 4); cout << "  ______ .______           ___          _______. __    __  _______  _______  " << endl;
	gotoXY(20, 5); cout << " /      ||   _  \\         /   \\        /       ||  |  |  ||   ____||       \\ " << endl;
	gotoXY(20, 6); cout << "|  ,----'|  |_)  |       /  ^  \\      |   (----`|  |__|  ||  |__   |  .--.  |" << endl;
	gotoXY(20, 7); cout << "|  |     |      /       /  /_\\  \\      \\   \\    |   __   ||   __|  |  |  |  |" << endl;
	gotoXY(20, 8); cout << "|  `----.|  |\\  \\----. /  _____  \\ .----)   |   |  |  |  ||  |____ |  '--'  |" << endl;
	gotoXY(20, 9); cout << " \\______|| _| `._____|/__/     \\__\\|_______/    |__|  |__||_______||_______/ " << endl;
	gotoXY(35, 23); cout << "Do you want continue ?" << endl;
	const char *choice[2] = { "[>YES<]", "[>NO<]" };
	int pos = 0, x = 36, y = 25;
	TextColor(7);

	while (1) {
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				gotoXY(x, y + i);
				TextColor(227);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
		}

		switch (inputKey()) {
		case 'w':
			pos--;
			pos = abs(pos);
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}
	TextColor(7);
}


bool Game::newGame() { // start a new game, initialize Map map
	
	char key;
	if (!isLoaded) {
		map.~Map();
		new(&map) Map();
	}
	isPausing = false;
	map.printMap();
	if(!isLoaded) map.initializeNewState();
	isLoaded = false;

	const string choice[3] = { "SAVE GAME","LOAD GAME","EXIT" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		int x = 125, y = 22;
		if (isPausing) {
			TextColor(11);
			gotoXY(125, 19); cout << "PAUSE MENU" << endl;
			TextColor(7);
			for (int i = 0; i < 3; i++) {
				if (i == pos) {
					gotoXY(x, y + i);
					TextColor(12);
					cout << choice[i];
					TextColor(7);
				}
				else {
					gotoXY(x, y + i);
					cout << choice[i];
					TextColor(7);
				}
			}
			TextColor(7);
		}
			
		if (kbhit())
		{
			key = getch();
			if (key == 'o')
			{
				//Save
				// call saveGame of Game to get name of file
				saveGameMenu();
			}
			if (key == 'l')
			{
				togglePauseGame();
				loadGameMenu();
				clrscr();
				map.redrawMap();
				togglePauseGame();
				isLoaded = false;
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0;
				if (!isPausing) {
					gotoXY(125, 19); cout << "                  " << endl;
					for (int i = 0; i < 3; i++) {
						gotoXY(x, y + i);
						cout << "                 " << endl;
					}
				}
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if(!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					TextColor(7);
					loadGameMenu();
					clrscr();
					map.redrawMap();
					togglePauseGame();
					isLoaded = false;
					break;
				case 2:
					TextColor(7);
					return true;
				}
			}
			TextColor(7);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}

bool Game::continueGame()
{
	clrscr();
	char key;
	isPausing = false;
	map.printMap();
	map.initializeNewState();
	const string choice[3] = { "SAVE GAME", "LOAD GAME", "EXIT"};
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}
		TextColor(11);
		gotoXY(125, 19); cout << "PAUSE MENU" << endl;
		TextColor(7);
		int x = 125, y = 22;
		for (int i = 0; i < 3; i++) {
			if (i == pos) {
				gotoXY(x, y + i);
				TextColor(12);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
		}
		TextColor(7);


		if (kbhit())
		{
			key = getch();
			if (key == 'o')
			{
				togglePauseGame();
				saveGameMenu();
				togglePauseGame();
			}
			if (key == 'l')
			{
				togglePauseGame();
				loadGameMenu();
				togglePauseGame();
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					break;
				case 2:
					TextColor(7);
					return true;
				}
			}
			clrscr();
			TextColor(7);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}


vector<string> Game::getAllFilename(const string& name)
{
		vector<string> v;
		string pattern(name);
		pattern.append("\\*");
		std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
		LPCWSTR sw = stemp.c_str();
		WIN32_FIND_DATA data;					
		HANDLE hFind;
		if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
			do {
				wchar_t* txt = data.cFileName;
				wstring ws(txt);
				// your new String
				string str(ws.begin(), ws.end());
				if (str[0] == '.') continue;
				// Show String
				v.push_back(str);
				//Just test !
				//cout << str << endl;
			} while (FindNextFile(hFind, &data) != 0);
			FindClose(hFind);
		}
		return v;
}

bool Game::loadGameMenu() { // get file of Map map
	string filename;
	clrscr();
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		gotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		return false;
	}
	int curPos = 0;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoXY(20, 4); cout << " __        ______       ___      _______       .___  ___. _______ .__   __. __    __    " << endl;
	gotoXY(20, 5); cout << "|  |      /  __  \\     /   \\    |       \\      |   \\/   ||   ____||  \\ |  ||  |  |  |" << endl;
	gotoXY(20, 6); cout << "|  |     |  |  |  |   /  ^  \\   |  .--.  |     |  \\  /  ||  |__   |   \\|  ||  |  |  |" << endl;
	gotoXY(20, 7); cout << "|  |     |  |  |  |  /  /_\\  \\  |  |  |  |     |  |\\/|  ||   __|  |  . `  ||  |  |  |" << endl;
	gotoXY(20, 8); cout << "|  `----.|  `--'  | /  _____  \\ |  '--'  |     |  |  |  ||  |____ |  |\\   ||  `--'  |" << endl;
	gotoXY(20, 9); cout << "|_______| \\______/ /__/     \\__\\|_______/      |__|  |__||_______||__| \\__| \\______/ " << endl;
	TextColor(7);
	gotoXY(30, 13); cout << "<Press ESC to escape...>";
	TextColor(7);
	gotoXY(30, 15);
	cout << "Choose Filename to load: ";

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			gotoXY(26, 16 + i);
			cout << ">> ";
		}
		gotoXY(30, 16 + i);
		cout << files[i] << endl;
	}
	while (true) {
		if (kbhit())
		{
			char key=getch();
			if (key == 'w')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 's')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 13)
			{
				isLoaded = true;
				map.loadGame(files[curPos]);
				clrscr();
				//map.redrawMap();
				return true;
			}
			if (key == 27)
			{
				clrscr();
				return false;
			}
		}
		Sleep(200);
	}
}

void Game::saveGameMenu() { // get file of Map ma
	string filename;
	clrscr();
	map.printBorder();
	TextColor(10);
	gotoXY(15, 4); cout << "     _______.     ___     ____    ____ _______      .___  ___. _______ .__   __. __    __    " << endl;
	gotoXY(15, 5); cout << "    /       |    /   \\    \\   \\  /   /|   ____|     |   \\/   ||   ____||  \\ |  ||  |  |  |" << endl;
	gotoXY(15, 6); cout << "   |   (----`   /  ^  \\    \\   \\/   / |  |__        |  \\  /  ||  |__   |   \\|  ||  |  |  |" << endl;
	gotoXY(15, 7); cout << "    \\   \\      /  /_\\  \\    \\      /  |   __|       |  |\\/|  ||   __|  |  . `  ||  |  |  |" << endl;
	gotoXY(15, 8); cout << ".----)   |    /  _____  \\    \\    /   |  |____      |  |  |  ||  |____ |  |\\   ||  `--'  |" << endl;
	gotoXY(15, 9); cout << "|_______/    /__/     \\__\\    \\__/    |_______|     |__|  |__||_______||__| \\__| \\______/ " << endl;
	
	gotoXY(15, 20);
	TextColor(7);
	cout << "<Press ESC to escape>";
	map.deleteOldPlayer();
	TextColor(7);
	gotoXY(15, 15);
	cout << "Input file name to save: ";
	TextColor(7);
	char key;
	while ((key = getch()) != 27 ) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				gotoXY(50, 15);
				cout << "                                                 ";
				gotoXY(50, 15);
				cout << filename;
			}
			break;
		case 13:
			map.saveGame(filename);
			break;
		default:
			filename.push_back(key);
			gotoXY(50, 15);
			cout << filename;
		}
		if (key == 13) break;
	}
	clrscr();
	map.redrawMap();
}

void Game::pauseMenu(int cmd){
}

void Game::togglePauseGame() { // toggle status of isPausing
	isPausing = !isPausing;
};

void Game::gameOver() {
	cout << "Game over" << endl;
}
void Game::playGame(bool& is_finish){
}
;

void Game::toggleMute() {
	constantVar::isMute = !constantVar::isMute;
}


void Game::toggleHard()
{
	constantVar::isHard = !constantVar::isHard;
}

void SubThread(Game* cg, bool* IS_RUNNING, bool* isPausing, bool* exitFlag){
}
