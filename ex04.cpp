#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

string formatarNome (string message) {
	int length = message.size();
	int lastSpaceIndex = 0;
	int firstSpaceIndex = message.find(" ");
	
	string sobrenome = "";
	
	for (int i = 0; i < length; i++) {
		if (message[i] == ' ') {
			lastSpaceIndex = i;
		}
	}
	for (int i = 0; i < length; i++) {
		if (message[i] == ' ' && i != lastSpaceIndex) {
			sobrenome += message[i + 1];
			sobrenome += ". ";
		}
	}
	string nome = "";
	string primeiroNome = "";

	for (int i = 0; i < length; i++) {
		
		if (i > lastSpaceIndex) {
			nome += message[i];
		}
		if (i < firstSpaceIndex) {
			primeiroNome += message[i];
		}
		
	}
	for (auto & c: nome) c = toupper(c);
	return nome + ", " + primeiroNome + " " + sobrenome;
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
