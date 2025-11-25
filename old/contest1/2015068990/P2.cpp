#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) { 
	int a, c; 

	while(cin >> a >> c, (a+c)) {
		vector<int> bloco(c);

		for(int i = 0; i < c; i++) cin >> bloco[i];

		int laser = a - bloco[0];
		for(int i = 0; i < c-1; i++) {
			if(bloco[i] > bloco[i+1]) {
				laser += bloco[i] - bloco[i+1];
			}
		}

		cout << laser << endl;
	}

	return 0;
}