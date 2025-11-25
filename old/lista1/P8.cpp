#include <iostream>
#include <string>

using namespace std;

int main(void){
	char c;
	string s;
	while(getline(cin, s, '\0')){
		bool open = true, changed = false;
		
		int i = 0;
		while(true){
			if(i == s.size()){
				break;
			}
			
			if(s[i] == '\"'){
				if(open){
					s[i] = '`';
					s.insert(i+1, "`");
					open = false;
				} else {
					s[i] = '\'';
					s.insert(i+1, "\'");
					open = true;
				}
			}

			i++;
		}

		cout << s;
	}

	return 0;
}