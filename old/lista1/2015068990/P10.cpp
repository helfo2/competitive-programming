#include <stdio.h>
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool vowel(char c){
	if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u'){
		return true;
	}
	return false;
}

int main(void){
	string s;

	getline(cin, s, '\0');

	bool first_letter = true;
	bool ay = false, alpha = true;
	char cons;
	for(int i = 0; s[i]; i++){
		if(!isalpha(s[i])){
			first_letter = true;
			
			if(alpha){
				if(ay){
					cout << "ay" << s[i];
				} else {
					cout << cons << "ay" << s[i];
				}
			} else{
				cout << s[i];
			}
			alpha = false;
			continue;
		} else { 
			alpha = true;
		}

		if(first_letter){
			first_letter = false;
			if(vowel(s[i])){
				ay = true;
			} else {
				cons = s[i];
				ay = false;
				continue;
			}

		}

		cout << s[i];
	}
	return 0;
}