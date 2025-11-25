#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void){
	string jewel;
	unordered_map<string, int> all;

	while(cin >> jewel){
		all[jewel]++;
	}

	cout << all.size() << endl;

	return 0;
}