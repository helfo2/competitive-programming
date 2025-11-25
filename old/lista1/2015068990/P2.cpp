#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

/*
Slumps:DFG, EFG, DFFFFFG, DFDFDFDFG, DFEFFFFFG
Not Slumps:  DFEFF, EFAHG, DEFG, DG, EFFFFDG
Slimps:AH, ABAHC, ABABAHCC, ADFGC, ADFFFFGC, ABAEFGCC, ADFDFGC
Not Slimps:  ABC, ABAH, DFGC, ABABAHC, SLIMP, ADGC
Slurpys:AHDFG, ADFGCDFFFFFG, ABAEFGCCDFEFFFFFG
Not Slurpys:  AHDFGA, DFGAH, ABABCC
*/

bool slump(string s){
	if(s[0] != 'D' && s[0] != 'E'){
		return false;
	}

	bool f = false;
	if(s[1] != 'F'){
		return false;
	}

	f = true;
	for(int i = 2; i < s.size(); i++){
		if(s[i] == 'F'){
			f = true;
		} else if(f == true && s[i] == 'G' && i == s.size()-1) {
			return true;
		} else {
			string s1 = s.substr(i, s.size()-i);
			return slump(s1);
		}
	}

	return false;
}

bool slimp(string s){
	if(s[0] != 'A'){
		return false;
	}

	if(s.size() == 2 && s[0] == 'A' && s[1] == 'H'){
		return true;
	}

	if(s[s.size()-1] != 'C'){
		return false;
	}

	if(s[0] == 'A'){
		if(s[1] == 'B'){
			string s1 = s.substr(2, s.size()-3);
			return slimp(s1);
		} else {
			string s1 = s.substr(1, s.size()-2);
			return slump(s1);
		}
	}

	return false;
}

int main(void) {
	int n; cin >> n;
	bool slurpy = false;

	cout << "SLURPYS OUTPUT\n";
	while(n--){
		string s; cin >> s;

		for(int i = 0; i < s.size(); i++){
			string s1 = s.substr(0,i+1);
			string s2 = s.substr(i+1,s.size());

			slurpy = slimp(s1) && slump(s2);
			if(slurpy) break;
		}

		if(slurpy){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	cout << "END OF OUTPUT\n";

	return 0;
}