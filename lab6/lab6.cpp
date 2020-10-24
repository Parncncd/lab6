//#include<stdio.h>
//#include<windows.h>
//#include<conio.h>
//#include<time.h>
//void gotoxy(int x, int y);
//
//void setcolor(int fg, int bg)
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
//}
//void draw_ship(int x, int y) {
//	gotoxy(x, y);
//	setcolor(2, 4);
//	printf("<-0->");
//
//}
//void erase_ship(int x, int y) {
//	gotoxy(x, y);
//	setcolor(2, 0);
//	printf("     ");
//
//}
//
//void drawBullet(int a, int b) {
//	gotoxy(a, b);
//	setcolor(2, 4);
//	printf("^");
//}
//void eraseBullet(int a, int b) {
//	gotoxy(a, b);
//	setcolor(2, 0);
//	printf(" ");
//}
//void gotoxy(int x, int y)
//{
//	COORD c = { x, y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}
//void drawEnemy(int x, int y) {
//	gotoxy(x, y);
//	setcolor(2, 4);
//	printf("*");
//
//}
//void setcursor(bool visible)
//{
//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO lpCursor;
//	lpCursor.bVisible = visible;
//	lpCursor.dwSize = 20;
//	SetConsoleCursorInfo(console, &lpCursor);
//}
//char cursor(int x, int y) {
//	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
//	char buf[2]; COORD c = { x,y }; DWORD num_read;
//	if (
//		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
//
//		return '\0';
//	else
//		return buf[0];
//
//}
//int main()
//{
//	char ch = ' ';
//	char direction = 's';
//	int x = 38, y = 20, state[10], bx[10], by[10],Ex,Ey, i = 0,a;
//	srand(time(NULL));
//	int coen;
//	
//	for (a = 0; a <= 20; a++) {
//		Ex = rand() % 70 + 10;
//		Ey = rand() % 5 + 2;
//		drawEnemy(Ex, Ey);
//	}
//	while (i <= 5) {
//		state[i] = 0;
//
//		i++;
//
//	}
//	i = 0;
//	setcursor(0);
//	gotoxy(x, y);
//	draw_ship(x, y);
//	do {
//		if (_kbhit()) {
//
//			ch = _getch();
//			if (ch == 'a' && x != 0) {
//				erase_ship(x, y);
//				draw_ship(--x, y);
//			}
//			if (ch == 'd' && x <= 80) {
//				erase_ship(x, y);
//				draw_ship(++x, y);
//			}
//			if (ch == 'w' && y != 0) {
//				erase_ship(x, y);
//				draw_ship(x, --y);
//			}
//			if (ch == 's' && y <= 40) {
//				erase_ship(x, y);
//				draw_ship(x, ++y);
//			}
//
//			if (ch == ' ') {
//
//				if (state[i] == 0) {
//					bx[i] = x + 2, by[i] = y - 1;
//
//
//					state[i] = 1;
//					Beep(300, 100);
//					drawBullet(bx[i], by[i]);
//				}
//				i = (i + 1) % 5;
//			}
//			fflush(stdin);
//
//		}
//		for (int j = 0; j <= 5; j++) {
//			if (state[j] == 1) {
//				eraseBullet(bx[j], by[j]);
//
//				if (bx[j] <= 80 && by[j] > 0) {
//					drawBullet(bx[j], --by[j]);
//
//				}
//				else {
//					state[j] = 0;
//					eraseBullet(bx[j], by[j]);
//					i = j;
//				}
//			}
//		}
//
//
//		Sleep(100);
//	} while (ch != 'x');
//	return 0;
//}