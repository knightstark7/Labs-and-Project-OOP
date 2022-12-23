#include "Map.h"

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
	gotoXY(125, 6); cout << "(_W_): Up" << endl;
	gotoXY(125, 7); cout << "(_A_): Left" << endl;
	gotoXY(125, 8); cout << "(_S_): Down" << endl;
	gotoXY(125, 9); cout << "(_D_): Right" << endl;
	gotoXY(125, 11); cout << "Config game" << endl;
	gotoXY(125, 12); cout << "(_O_): Save game" << endl;
	gotoXY(125, 13); cout << "(_L_): Load game" << endl;
	gotoXY(125, 14); cout << "(_P_): Pause menu/ Resume" << endl;
	drawPlayer(); // at the starting game
}

void Map::drawMap() {
	vector <Enemy*> enemyList = rowsData.listEnemy();
	for (int i = 0; i < (int)enemyList.size(); ++i) {
		if (player.crash(enemyList[i]->getPos(), enemyList[i]->getlength() - 3, enemyList[i]->getwidth())) {
			if (!constantVar::isMute) {
				enemyList[i]->sound();
			}
			player.killPlayer();
			deleteOldPlayer();
			drawPlayer();
			Sleep(300);
			clrscr();
			printMap();
			deleteOldPlayer();
			printChurch();
			return;
		}
	}
}

int Map::draw(Position pos, char **shape, int w, int h) {
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


void Map::newState() {
	player.~People();
	new(&player) People();
	rowsData.~cRows();
	new(&rowsData) cRows();
	int padding[10]{};
	for (int i = 0; i <  level.getLevel() + 3; i++) {  
		padding[i] = 0;
		int speed = rand() % (level.getMinSpeed() - level.getMaxSpeed() + 1) + level.getMaxSpeed();
		bool direction = rand() % 2;
		bool redLight = rand() % 2;
		rowsData.pushRow(new cLine(speed, direction, redLight, (i * 3) + 1));
	}
	Enemy * newEnemy;
	Position pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
		padding[rRow] += (rand() % 20) + 9;
		pos = Position((rRow * 3) + 1, padding[rRow]);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	Sleep(200);
	rowsData.nextState(0);
}

void Map::nextState() {
	srand(time(NULL));
	Enemy * newEnemy;
	Position pos;
	int tryCount = 10000;
	while (tryCount--) {
		int rRow = (rand() % 9) + 1;
		pos = Position((rRow * 3) + 1, 4);
		newEnemy = level.randNewEnemy(pos);
		if (!newEnemy) break;
		if (!rowsData.pushEnemy(rRow, newEnemy)) {
			level.decNEnemy(1);
			delete newEnemy;
		};
	}
	++t;
	int tmp = rowsData.nextState(t);
	level.decNEnemy(tmp);
	drawMap();
}

void Map::redrawMap() {
	printMap();
	int tmp = rowsData.nextState(t);
	level.decNEnemy(tmp);
	drawMap();
}

void Map::updatePosPeople(char moving) {
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
		if (!constantVar::isMute)PlaySound(TEXT("Pass.wav"), NULL, SND_ASYNC);
		return true;
	}
	return false;
}

void Map::printChurch()
{
	gotoXY(35, 10);
	cout << R"( +
                                   ,|,
                                   |||
                                  / | \
                                  | | |
                                  | | |
                                 /  |  \
                                 |  |  |
                                 |  |   \
                                /    \  |
                                |    |  |
                                |    |   \
                               /     |   |
                8              |     |   |
              ""8""           /      |    \
                8            /        \   ,\
              ,d8888888888888|========|="" |
            ,d"  "88888888888|  ,aa,  |  a |
          ,d"      "888888888|  8  8  |  8 |
       ,d8888888b,   "8888888|  8aa8  |  8,|
     ,d"  "8888888b,   "88888|========|="" |
   ,d"      "8888888b,   "888|  a  a  |  a |         ,-=-.       ______     _
 ,d"   ,aa,   "8888888b,   "8|  8  8  |  8,|        /  +  \     />----->  _|1|_
/|    d"  "b    |""""""|     |========|="" |        | ~~~ |    // -/- /  |_ H _|
 |    8    8    |      |     |  ,aa,  |  a |	    |R.I.P|   //  /  /     |S|					
 |    8aaaa8    |      |     |  8  8  |  8 |   \vV,,|_____|V,//_____/VvV,v,|_|/,,vhjwv/
 |              |      |     |  """"  | ,,=|
 |aaaaaaaaaaaaaa|======""""""""""""""""")";
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
	for (int i = 0; i < level.getLevel() + 3; ++i) {
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
	level.~Level();
	new(&level) Level(lv, 0);
	int playerX, playerY;
	playerX = readInt(infile);
	playerY = readInt(infile);
	player.~People();
	new(&player) People(Position(playerX, playerY));

	int nEnemy = 0;

	rowsData.~cRows();
	new(&rowsData) cRows();

	for (int i = 0; i < level.getLevel() + 3; ++i) {
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
			rowsData.pushEnemy(i, level.getNewEnemy(Position(eX, eY), eType));
		}
	}
	infile.close();
	return true;
}

void Map::printCongratulation()
{
	clrscr();
	printMap();	
	deleteOldPlayer();
	if (!constantVar::isMute)PlaySound(TEXT("Pass.wav"), NULL, SND_ASYNC);
	gotoXY(15, 15); cout << " _______  __ .__   __. __      _______. __    __  _______  _______  " << endl;
	gotoXY(15, 16); cout << "|   ____||  ||  \\ |  ||  |    /       ||  |  |  ||   ____||       \\ " << endl;
	gotoXY(15, 17); cout << "|  |__   |  ||   \\|  ||  |   |   (----`|  |__|  | |  |__   |  .--.  |" << endl;
	gotoXY(15, 18); cout << "|   __|  |  ||  . `  ||  |    \\   \\    |   __   ||   __|  |  |  |  |" << endl;
	gotoXY(15, 19); cout << "|  |     |  ||  |\\   ||  |.----)   |   |  |  |  ||  |____ |  '--'  |" << endl;
	gotoXY(15, 20); cout << "|__|     |__||__| \\__||__||_______/    |__|  |__||_______||_______/ " << endl;
	gotoXY(35, 22); cout << "Do you want to exit?" << endl;
	const char *choice[2] = { "[>YES<]", "[>YUP<]" };
	int pos = 0, x = 36, y = 23;
	TextColor(7);

	while (1) {
		TextColor(7);
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
			return ;
		}
	}
}

bool Map::printLevelUp() {
	if (level.getLevel() == 5)
	{
		printCongratulation();
		return false;
	}
	else {
		clrscr();
		printMap();
		deleteOldPlayer();
		gotoXY(20, 5); cout << "  ______ .______        ______       _______.     _______. _______  _______  " << endl;
		gotoXY(20, 6); cout << " /      ||   _  \\      /  __  \\     /       |    /       ||   ____||       \\ " << endl;
		gotoXY(20, 7); cout << "|  ,----'|  |_)  |    |  |  |  |   |   (----`   |   (----`|  |__   |  .--.  |" << endl;
		gotoXY(20, 8); cout << "|  |     |      /     |  |  |  |    \\   \\        \\   \\    |   __|  |  |  |  |" << endl;
		gotoXY(20, 9); cout << "|  `----.|  |\\  \\----.|  `--'  |.----)   |   .----)   |   |  |____ |  '--'  |" << endl;
		gotoXY(20, 10); cout << " \\______|| _| `._____| \\______/ |_______/    |_______/    |_______||_______/ " << endl;
		gotoXY(35, 17); cout << "Do you want to continue?" << endl;
		const char *choice[2] = { "[>YES<]", "[>NO<]" };
		int pos = 0, x = 36, y = 19;
		TextColor(7);

		while (1) {
			TextColor(7);
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