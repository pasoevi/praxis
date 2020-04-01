#include <ncurses.h>
#include <stdlib.h>

#define kMapWidth 16
#define kMapHeight 16
static char map[kMapHeight][kMapWidth];
static int level = 0;

#define kMaxActors 16
static int actorRow[kMaxActors];
static int actorCol[kMaxActors];

#define kFloor '.'
#define kWall '#'
#define kStairs '<'
#define kPlayer '@'
#define kEvil 'e'

static int Min(int a, int b) {
	return a < b ? a : b;
}

static int Range(int low, int high) {
	return (rand() % (high - low)) + low;
}

static void Fill(int r0, int c0, int r1, int c1, char glyph) {
	int r, c;
	for (r = r0; r < r1; ++r) {
		for (c = c0; c < c1; ++c) {
			map[r][c] = glyph;
		}
	}	
}

static void Swap(int r0, int c0, int r1, int c1, 
		char g0, char g1) 
{
	do {
		int r = Range(r0, r1);
		int c = Range(c0, c1);

		if (map[r][c] == g0) {
			map[r][c] = g1;
			break;
		}
	} while (1);
}

static void DrawMap() {
	int r;

	clear();
	for (r = 0; r < kMapHeight; ++r) {
		mvaddstr(r, 0, map[r]);
	}
}

static int At(int r, int c) {
	int i;
	for (i = 0; i < kMaxActors; ++i) {
		if (actorRow[i] == r 
			&& actorCol[i] == c)
		{
			return i;
		}
	}
	return -1;
}

static void NewActor(int r, int c) {
	int i;
	for (i = 0; i < kMaxActors; ++i) {
		if (actorRow[i] < 0) {
			actorRow[i] = r;
			actorCol[i] = c;
			map[r][c] = (i == 0) ? kPlayer : kEvil;
			break;
		}
	}
}

static void Place() {
	do {
		int r = rand() & (kMapHeight - 1);
		int c = rand() & (kMapWidth - 2);
		if (map[r][c] == kFloor) {
			NewActor(r, c);
			return;
		}
	} while (1);

}

static void NewLevel() {
	int i, r, c;
	Fill(0, 0, kMapHeight - 1, kMapWidth - 2, kWall);
	Fill(1, 1, kMapHeight - 2, kMapWidth - 3, kFloor);
	r = Range(2, kMapHeight - 3);
	c = Range(2, kMapWidth - 4);

	/* Horiz walls */
	Fill(r,     1, r + 1, kMapWidth - 2, kWall);
	Swap(r,     1, r + 1, c, kWall, kFloor);
	Swap(r, c + 1, r + 1, kMapWidth - 3, kWall, kFloor);

	/* Vert walls */
	Fill(    1, c, kMapHeight - 2, c + 1, kWall);
	Swap(    1, c, r, c + 1, kWall, kFloor);
	Swap(r + 1, c, kMapHeight - 2, c + 1, kWall, kFloor);

	Swap(1, 1, kMapHeight - 1, kMapWidth - 2, kFloor, kStairs);
	++level;

	for (i = 0; i < kMaxActors; ++i) {
		actorRow[i] = -1;
	}
	Place();
	for (i = 0; i < Min(level, 10); ++i) {
		Place();
	}
}

int SignOf(int x) {
	return (x > 0) - (x < 0);
}

void Done(char *msg) {
	endwin();
	printf(msg, level);
	exit(0);
}

int main(int argc, char *argv[]) {
	int i, input;

	initscr();
	cbreak();
	srand(time(0));
	keypad(stdscr, TRUE);

	NewLevel();
	while (1) {
		for (i = 0; i < kMaxActors; ++i) {
			int nextRow = actorRow[i];
			int nextCol = actorCol[i];

			if (i == 0) {
				DrawMap();
				input = getch();
				if (input == KEY_DOWN) ++nextRow; 
				if (input == KEY_LEFT) --nextCol;
				if (input == KEY_RIGHT) ++nextCol;
				if (input == KEY_UP) --nextRow;
				if (input == 'q') {
					Done("Quit on level %d.\n");
				}

				if (map[nextRow][nextCol] == kPlayer
					|| map[nextRow][nextCol] == kWall) 
				{
					i = -1;
					continue;
				}
				if (map[nextRow][nextCol]
					== kStairs)
				{ 
					NewLevel();
					i = 0;
					break;
				}
				if (map[nextRow][nextCol]
					== kEvil)
				{
					int e = At(nextRow, nextCol);
					if (e >= 0) {
						map[nextRow][nextCol] = kFloor;
						actorRow[e] = -1;
						continue;
					}
				}
			}
			else {
				int dR; 
				int dC;
				if (nextRow < 0) continue;

				dR = SignOf(actorRow[0] - nextRow);
				dC = SignOf(actorCol[0] - nextCol);
				if (map[nextRow + dR][nextCol] == kPlayer
					|| (dR != 0 && map[nextRow + dR][nextCol] == kFloor))
				{
					nextRow += dR;
				}
				else if (map[nextRow][nextCol + dC] == kPlayer
					|| (dC != 0 && map[nextRow][nextCol + dC] == kFloor))
				{
					nextCol += dC;
				}
				if (map[nextRow][nextCol] == kPlayer) 
				{
					Done("Died on level %d.\n");
				}
			}
			if (map[nextRow][nextCol] == kFloor) {
				map[nextRow][nextCol] = map[actorRow[i]][actorCol[i]];
				map[actorRow[i]][actorCol[i]] = kFloor;
				actorRow[i] = nextRow;
				actorCol[i] = nextCol;
			}
		}
	}	
}
