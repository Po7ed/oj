#ifndef _BASIC_HPP_
#define _BASIC_HPP_ 1

#define WIN

#ifdef WIN
#include <windows.h>
#include <conio.h>
#endif

#include <iostream>


#ifndef WIN// for Linux
void gotoxy(short x,short y)
{
	printf("%c[%d;%df",0x1B,int(y),int(x));
}
#include <termios.h>
static struct termios Old,New;
void initTermios(int echo)
{
    tcgetattr(0, &Old);
    New = Old;
    New.c_lflag &= ~ICANON;
    New.c_lflag &= echo ? ECHO : ~ECHO;
    tcsetattr(0, TCSANOW, &New);
}
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &Old);
}
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}
char getch(void)
{
    return getch_(0);
}
char getche(void)
{
    return getch_(1);
}
#else// for windows
void gotoxy(short x,short y)
{
	COORD coord={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
#endif

#endif