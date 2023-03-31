#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

string formatarNome (string message) {
	int length = message.size();
	int lastSpaceIndex = 0;
	for (int i = 0; i < length; i++) {
		if (message[i] == ' ') {
			lastSpaceIndex = i;
		}
	}

	string sobrenome = "";
	string nome = "";

	for (int i = 0; i < length; i++) {
		if (i < lastSpaceIndex) {
			sobrenome += message[i];
		}
		if (i > lastSpaceIndex) {
			nome += message[i];
		}
		
	}
	return nome + ", " + sobrenome;
}

int main () {
	setlocale(LC_ALL, "");
	string linha;
	ifstream arq("nomes.txt");
	
	if (arq.is_open()) {
		while (! arq.eof()) {
			getline(arq, linha);
			cout << formatarNome(linha) << endl;
		}
		arq.close();
	}
	else {
		cout << "Erro ao abrir o arquivo";
	}
	
	return 1;
}
