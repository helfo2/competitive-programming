#include <iostream>
#include <stack>

using namespace std;

int solve(string& s){
	stack<char> diamonds;
	int ans = 0;
	for(auto i : s){
		if(i == '<'){
			diamonds.push(i);
		} else if(i == '>'){
			if(diamonds.size() >= 1) {
				if(diamonds.top() == '<') ans++;
			 	diamonds.pop();	
			}
		}
	}

	return ans;
}

int main(void){
	int n; cin >> n;
	cin.ignore();
	
	while(n--){
		string s; getline(cin, s);
	
		cout << solve(s) << endl; 
	}

	return 0;
}