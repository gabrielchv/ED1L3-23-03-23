#include <iostream>
#include <locale.h>
#include <windows.h>
using namespace std;

void gotoxy(short x, short y) {
	COORD coord = {x, y};
	SetConsoleCursorPosition(GetStdHandle ( STD_OUTPUT_HANDLE ), coord);
}

int main () {
	setlocale(LC_ALL, "");
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
	string message;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	cout << "Digite uma mensagem: " << endl;
	cin >> message;
	for (int i = 0; i < 15; ++i) {
		gotoxy(columns / 2 - message.size() + i, 5 + i);
    	cout << message << endl;
	}
	
	return 1;
}
