#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int n; 
string words[100010];
int g[300][300];

void print(){
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void){
	int t; cin >> t;

	while(t--){
		cin >> n;
		cout << n << endl;

		for(int i = 0; i < 300; i++){
			for(int j = 0; j < 300; j++){
				g[i][j] = 0;
			}
		}

		for(int w = 0; w < n; w++){
			cin >> words[w];
			
			// first and last letters
			g[words[w][0]-'a'][words[w][words[w].length()-1]-'a']]++;
		}

		print();

		for(int i = 0; i < n; i++){

		}



	}

	return 0;
}