#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> translations;
int n, m;

int main(void){
	cin >> n;
	cin.ignore();
	while(n--){
		string lang, trans;
		getline(cin, lang);
		getline(cin, trans);

		translations[lang] = trans;
	}

	cin >> m;
	cin.ignore();
	while(m--){
		string lang, name;
		getline(cin, name);
		getline(cin, lang);

		cout << name << endl;
		cout << translations[lang] << endl;
		cout << endl;
	}

	return 0;
}