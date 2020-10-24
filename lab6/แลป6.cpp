#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); setcolor(2, 4); printf(" <-0-> ");
}
void erase_ship(int x, int y) {
	gotoxy(x, y); setcolor(0, 0); printf("       ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); setcolor(2, 4); printf("^");
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); setcolor(0, 0); printf(" ");
}
void drawEnemy(int x, int y) {
	gotoxy(x, y);
	setcolor(4, 8);
	printf("*");

}
void clearEnemy(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void pointCounting(int point) {
	gotoxy(115, 0);
	setcolor(4, 10);
	printf("%d", point);
}
void erasePoint() {
	gotoxy(115, 0);
	setcolor(0, 10);

	printf(" ");
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
int main()
{
	setcursor(0);
	char ch = '.';
	int x = 38, y = 20;
	int bx, by, i,Ex,Ey;
	int bullet = 0;
	int point=0;
	pointCounting(point);
	srand(time(NULL));
	
	for (i = 0; i < 20; i++) {
		Ex = rand() % 70 + 10;
		Ey = rand() % 5 + 2;
		drawEnemy(Ex, Ey);
	}
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { erase_ship(x, y); draw_ship(--x, y); }
			if (ch == 's') { erase_ship(x, y); draw_ship(++x, y); }
			if (bullet != 1 && ch == ' ') { Beep(300, 100); bullet = 1; bx = x + 3; by = y - 1; }
			fflush(stdin);
		}
		if (bullet == 1) {
			clear_bullet(bx, by);
			if (by == 2) { bullet = 0; }
			else { 
				
			if (cursor(bx, by - 1) == '*') {
				erasePoint();
				
				clearEnemy(bx, by);
				Ex = rand()%70 +10, Ey = rand()%5+2;
				drawEnemy(Ex, Ey);
				clear_bullet(bx, by - 1);
				++point;
				pointCounting(point);
				
				Beep(500, 100);
				bullet = 0;
			
				}
			else { draw_bullet(bx, --by); }
			}

		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}