#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> onda;

	while(cin >> n && n) {
		int j = 0, picos = 0;
		onda.resize(n+2);

		int t;
		for(int i = 0; i < n; i++) {
			cin >> t;
			onda[i] = t;
		}
		onda[n] = onda[0];
		onda[n+1] = onda[1];

		bool c;
		int i = 0;
		if(n == 2) picos = 2;
		else {
			if(onda[0] >= onda[1]) c = false;
			else c = true;

			while(i <= n) {
				while(c && i <= n) {
					if(onda[i] > onda[i+1]) {
						c = false;
						picos++;
						i++;
						break;
					}

					i++;
				} 
			
				while(!c && i <= n) {
					if(onda[i] <= onda[i+1]) {
						c = true;
						picos++;
						i++;
						break;
					}
					
					i++;
				}
			}
		}
		
		cout << picos << endl;
	}

	return 0;
}