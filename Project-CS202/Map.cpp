#include "Map.h"
//#include "cConsole.h"

Map::Map() : length(115), width(40) {
	for (int i = 0; i <= length; i++) {
		map[0][i] = map[width + 1][i] = '-';
	}
	map[0][length + 1] = map[width + 1][length + 1] = ' ';
	for (int i = 1; i <= width; ++i) {
		map[i][0] = map[i][length] = '|';
		map[i][length + 1] = ' ';
		for (int j = 1; j < length; ++j) {
				map[i][j] = ' ';
		}
	}
}

//void Map::resetMap() {
//	cout << "This is resetMap" << endl;
//	for (int i = 0; i <= length + 1; i++) {
//		map[0][i] = map[width + 1][i] = '-';
//	}
//	for (int i = 1; i <= width; ++i) {
//		map[i][0] = map[i][length + 1] = '|';
//		for (int j = 1; j <= length; ++j) {
//			map[i][j] = ' ';
//		}
//	}
//}

void Map::printMap()
{
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= width + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= length + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	gotoXY(125, 1); 
	cout << "!~ CROSS THE ROAD GAME ~!";
	gotoXY(125, 3); cout << "Level: " << level.getLevel() << endl;
	gotoXY(125, 5); cout << "Control Manual" << endl;
	gotoXY(125, 6); cout << "[ W ]: Up" << endl;
	gotoXY(125, 7); cout << "[ A ]: Left" << endl;
	gotoXY(125, 8); cout << "[ S ]: Down" << endl;
	gotoXY(125, 9); cout << "[ D ]: Right" << endl;
	gotoXY(125, 11); cout << "Config game" << endl;
	gotoXY(125, 12); cout << "[ O ]: Save game" << endl;
	gotoXY(125, 13); cout << "[ L ]: Load game" << endl;
	gotoXY(125, 14); cout << "[ P ]: Pause game/Menu" << endl;
	drawPlayer(); // at the starting game
}

void Map::drawMap() {
	//resetMap();
	vector <Enemy*> enemyList = rowsData.listEnemy(); //enemyList = 0 
	for (int i = 0; i < (int)enemyList.size(); ++i) {
		//drawEnemies(enemyList[i]);
		if (player.crash(enemyList[i]->getPos(), enemyList[i]->getlength() - 3, enemyList[i]->getwidth())) {
			if (!constantVar::isMute) enemyList[i]->sound();
			player.killPlayer();
			//randomNextState();
			deleteOldPlayer();
			drawPlayer();
			Sleep(300);
			clrscr();
			printMap();
			deleteOldPlayer();
			bombEffect();
			return;
		}
	}
}

int Map::draw(cPosition pos, char **shape, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y + w <= 0) return 0;
	if (Y > length) return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(length, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << shape[i][j - max(1, Y)];
		}
	}
	return 1;
}

//void Map::drawEnemies(Enemy * enemy) { // deleted
//	int status = draw(enemy->getPos(), enemy->shape(), enemy->getlength(), enemy->getwidth());
//	if (status == 0) {
//		enemy->goOutMap();
//	}
//	if (status == -1) {
//		player.killPlayer();
//	}
//}

void Map::drawPlayer() {
	TextColor(7);
	int status = draw(player.getPos(), player.shape(), player.getlength(), player.getwidth());
	if (status == -1) {
		player.killPlayer();
	}
}

void Map::deleteOldPlayer() {
	draw(player.getPos(), player.emptyShape(), player.getlength(), player.getwidth());
}


void Map::initializeNewState() {
	player.~People();
	new(&player) People();
	rowsData.~cRows();
	new(&rowsData) cRows();
	int padding[10]{};
	for (int i = 0; i < 10; ++i) {
		padding[i] = 0;
		int speed = rand() % (level.getMinSpeed() - level.getMaxSpeed() + 1) + level.getMaxSpeed();
		bool direction = rand() % 2;
		bool redLight = rand() % 2;
		rowsData.pushRow(new cLine(speed, direction, redLight, (i * 3) + 1));
	}
	Enemy * newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
		padding[rRow] += (rand() % 20) + 9;
		pos = cPosition((rRow * 3) + 1, padding[rRow]);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	Sleep(200);
	rowsData.moveToNextState(0);
}

void Map::randomNextState() {
	srand(time(NULL));
	//int t = rand(); // this will be get from global clock
	Enemy * newEnemy;
	cPosition pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
		pos = cPosition((rRow * 3) + 1, 4);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	++t;
	int tmp = rowsData.moveToNextState(t);
	level.decNEnemy(tmp);
	drawMap();
}

void Map::redrawMap() {
	printMap();
	int tmp = rowsData.moveToNextState(t);
	level.decNEnemy(tmp);
	drawMap();
}

void Map::updatePosPlayer(char moving) {
	deleteOldPlayer();
	if (moving == 'a' || moving == 'A') player.Left();
	else if (moving == 'w' || moving == 'W') player.Up();
	else if (moving == 'd' || moving == 'D') player.Right();
	else if (moving == 's' || moving == 'S') player.Down();
	else return;
}

bool Map::isEnd()
{
	return player.checkIsDead();
}
bool Map::isWin()
{
	if (player.getX() == 1) {
		if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
		return true;
	}
	return false;
}

void Map::bombEffect()
{
	const int baseX = 10, baseY = 10;
	gotoXY(baseX, baseY);
	cout << R"(                                               ____                       )" << "\n";
	gotoXY(baseX, baseY + 1);
	cout << R"(                                           __,-~~/~    `---.                  )" << "\n";
	gotoXY(baseX, baseY + 2);
	cout << R"(                                         _/_,---(      ,    )                 )" << "\n";
	gotoXY(baseX, baseY + 3);
	cout << R"(                                     __ /        <    /   )  \___             )" << "\n";
	gotoXY(baseX, baseY + 4);
	cout << R"(                      - ------===;;;'====------------------===;;;===----- -  -)" << "\n";
	gotoXY(baseX, baseY + 5);
	cout << R"(                                      \/  ~"~"~"~"~"~\~"~)~" / )" << "\n";
	gotoXY(baseX, baseY + 6);
	cout << R"(                                        (_ (   \  (     >    \)               )" << "\n";
	gotoXY(baseX, baseY + 7);
	cout << R"(                                         \_( _ <         >_>'                 )" << "\n";
	gotoXY(baseX, baseY + 8);
	cout << R"(                                            ~ `-i' ::>|--"                    )" << "\n";
	gotoXY(baseX, baseY + 9);
	cout << R"(                                                I;|.|.|                       )" << "\n";
	gotoXY(baseX, baseY + 10);
	cout << R"(                                               <|i::|i|`.                     )" << "\n";
	gotoXY(baseX, baseY + 11);
	cout << R"(                                              (` ^'"`-' ")                    )";
}

void Map::nextLevel() {
	level.nextLevel();
}

void Map::printInt(int x, ofstream& outfile) {
	outfile.write((char*)&x, sizeof(int));
}

int Map::readInt(ifstream& infile) {
	int x;
	infile.read((char*)&x, sizeof(int));
	return x;
}

void Map::saveGame(string file)
{
	ofstream outfile("./data/" + file + ".bin", ios::out | ios::binary);
	printInt(level.getLevel(), outfile);
	printInt(player.getX(), outfile);
	printInt(player.getY(), outfile);

	vector <cLine*> rows(rowsData.listRow());
	for (int i = 0; i < 10; ++i) {
		printInt(rows[i]->getCurrentRow(), outfile);
		printInt((int)rows[i]->getDirection(), outfile);
		printInt(rows[i]->getSpeed(), outfile);
		printInt((int)rows[i]->getRedLight(), outfile);

		vector <Enemy*> enemy(rows[i]->getEnemy());
		printInt((int)enemy.size(), outfile);

		for (int j = 0; j < (int)enemy.size(); ++j) {
			printInt(enemy[j]->getX(), outfile);
			printInt(enemy[j]->getY(), outfile);
			printInt(enemy[j]->getType(), outfile);
		}
	}
	outfile.close();
}

bool Map::loadGame(string file) {
	ifstream infile("./data/" + file, ios::in | ios::binary);
	if (!infile.is_open()) {
		return false;
	}
	int lv = readInt(infile);
	level.~cLevel();
	new(&level) cLevel(lv, 0);
	int playerX, playerY;
	playerX = readInt(infile);
	playerY = readInt(infile);
	player.~People();
	new(&player) People(cPosition(playerX, playerY));

	int nEnemy = 0;

	rowsData.~cRows();
	new(&rowsData) cRows();

	for (int i = 0; i < 10; ++i) {
		int currentRow, direction, speed, redLight;
		currentRow = readInt(infile);
		direction = readInt(infile);
		speed = readInt(infile);
		redLight = readInt(infile);

		rowsData.pushRow(new cLine(speed, direction, redLight, currentRow));
		
		int enemySize = readInt(infile);
		nEnemy += enemySize;
		
		for (int j = 0; j < enemySize; ++j) {
			int eX, eY, eType;
			eX = readInt(infile);
			eY = readInt(infile);
			eType = readInt(infile);
			rowsData.pushEnemy(i, level.getNewEnemy(cPosition(eX, eY), eType));
			//Print enemy ?
		}
	}
	infile.close();
	return true;
}

void Map::printCongrats()
{
	clrscr();
	printMap();	
	deleteOldPlayer();
	if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
	gotoXY(15, 15); cout << "_________                                              __            ._." << endl;
	gotoXY(15, 16); cout << "\\_   ___ \\   ____    ____      ____  _______ _____   _/  |_   ______ | |" << endl;
	gotoXY(15, 17); cout << "/    \\  \\/  /  _ \\  /    \\   / ___\\ \\_  __ \\__    \\  \\   __\\ /  ___/ | |" << endl;
	gotoXY(15, 18); cout << "\\     \\____(  <_> )|   |  \\ //_ / > |  | \\/ / __ \\_|  |      \\___\\   \\ | " << endl;
	gotoXY(15, 19); cout << " \\______  / \\____/ |___|  / \\___  /  |__|   (____  /  |__|  /____  >  __" << endl;
	gotoXY(15, 20); cout << "        \\/              \\/ /_____/               \\/              \\/   \\/" << endl;
	gotoXY(35, 22); cout << "Exit ?" << endl;
	const char *choice[2] = { "<YES>", "<OF COURSE>" };
	int pos = 0, x = 36, y = 23;
	TextColor(7);
	/*TextColor(227);
	gotoXY(x, y);
	cout << choice[0];
	TextColor(7);

	TextColor(227);
	gotoXY(x+10, y);
	cout << choice[1];
	TextColor(7);*/

	while (1) {
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
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
			return ;
		}
	}
}

bool Map::printLevelUp() {
	if (level.getLevel() == 5)
	{
		printCongrats();
		return false;
	}
	else {
		clrscr();
		printMap();
		deleteOldPlayer();
		gotoXY(15, 15); cout << "******    *******       *******      *******    *******    ******     *******      ###   ###" << endl;
		gotoXY(15, 16); cout << "**        **     **    **     **   **         **           **         **     *     ###   ###" << endl;
		gotoXY(15, 17); cout << "**        ** *  **    **       **    ****       ****       ******     **      *    ###   ###" << endl;
		gotoXY(15, 18); cout << "**        **   **      **     **         **         **     **         **     *     ###   ###" << endl;
		gotoXY(15, 19); cout << "******    **    **      *******    *****      *****        ******     *******     ::::: ::::: " << endl;
		gotoXY(35, 21); cout << "Continue ?" << endl;
		const char *choice[2] = { "<YES>", "<NO>" };
		int pos = 0, x = 36, y = 22;
		TextColor(7);

		while (1) {
			TextColor(7);
			for (int i = 0; i < 2; i++) {
				if (i == pos) {
					TextColor(227);
					gotoXY(x, y + i);
					cout << choice[i];
					TextColor(7);
				}
				else {
					gotoXY(x, y + i);
					cout << choice[i];
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
	}
}

void Map::printBorder(){
	clrscr();
	gotoXY(0, 0);
	for (int i = 0; i <= width + 1; ++i) {
		cout << "  ";
		for (int j = 0; j <= length + 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
}