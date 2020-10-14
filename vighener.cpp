#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
using namespace std;
const int NUM_ENGlISH_LETTERS = 26;
void vighener(string s, string k);
int AsciiToAlphaNum(int ascii);
int AlphaNumToAsciiUppercase(int alphanum);
int AlphaNumToAsciiLowercase(int alphanum);

int main() {
	string s, k;
	setlocale(LC_ALL, "");
	cout << "Введите слово или фразу, которую необходимо зашифровать, латинскими буквами: " << endl;
	getline(cin, s);
	int i = 0;
	while (s[i]) {
		if (isalpha(s[i]) || isdigit(s[i]) || ispunct(s[i]) || isspace(s[i]))
			i++;
		else {
			cout << "Повторите ввод. Не используйте кириллицу" << endl;
			getline(cin, s);
			i = 0;
		}
	}
	cout << "Введите ключ латинскими буквами: " << endl;
	cin >> k;
	i = 0;
	while (k[i]) {
		if (isalpha(k[i]))
			i++;
		else {
			cout << "Введите ключ еще раз. Используйте только латинские буквы" << endl;
			cin >> k;
			i = 0;
		}
	}
	cout << "Идет процесс шифрования..." << endl << endl
		<< "Зашифрованное сообщение: " << endl;
	vighener(s, k);
	_getch ();
	return 0;
}

void vighener(string s, string k) {
	for (int i = 0, j = 0, n = s.size(), l = k.size(); i < n; i++) {
		if (isalpha(s[i]) && isupper(s[i])) {
			cout << (char)(AlphaNumToAsciiUppercase((AsciiToAlphaNum(s[i]) + AsciiToAlphaNum(toupper(k[j]))) % NUM_ENGlISH_LETTERS));
			j = (j + 1) % l;
		}
		else if (isalpha(s[i]) && islower(s[i])) {
			cout << (char)(AlphaNumToAsciiLowercase((AsciiToAlphaNum(s[i]) + AsciiToAlphaNum(tolower(k[j]))) % NUM_ENGlISH_LETTERS));
			j = (j + 1) % l;
		}
		else cout << s[i];
	}
}

int AsciiToAlphaNum(int ascii) {
	int alphanum;
	if (isupper(ascii)) {
		alphanum = ascii - 65;
		return alphanum;
	}
	else if (islower(ascii)) {
		alphanum = ascii - 97;
		return alphanum;
	}
	else return ascii;
}

int AlphaNumToAsciiUppercase(int alphanum) {
	int ascii = alphanum + 65;
	return ascii;
}

int AlphaNumToAsciiLowercase(int alphanum) {
	int ascii = alphanum + 97;
	return ascii;
}
