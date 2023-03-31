#include <iostream>
#include <locale.h>

using namespace std;

int main () {
	setlocale(LC_ALL, "");
	string message;
	cout << "Digite uma mensagem: " << endl;
	getline(cin, message);
	int length = message.size();
	bool palindromo = true;
	string messageNoSpaces = "";

	for (int i = 0; i < length; i++) {
		if (message[i] != ' ') {
			messageNoSpaces += message[i];
		}
	}

	length = messageNoSpaces.size();
	
	for (int i = 0; i < length / 2; i++) {
		if (messageNoSpaces[i] != messageNoSpaces[length - i - 1]) {
			palindromo = false;
		}
	}
	cout << "Palindromo: " << (palindromo ? "sim" : "nao") << endl;
	
	
	return 1;
}
