#include <iostream>

using namespace std;

int m[55][105];
int poder[51];
int peso[101];

int dp(int n, int k) {
	

	
	return m[n][k];
}

int main(void) {
	int ct; cin >> ct;
	int poder, peso;

	while(ct--) {
		int n; cin >> n;
		
		for(int i = 0; i < n; i++)
			m[i][0] = 0;

		for(int i = 0; i <= 100; i++)
			m[0][i] = 0;
		
		for(int i = 1; i <= n; i++) {
			
			cin >> poder >> peso;

			for(int j = 1; j <= 101; j++) {
				if(peso > j) 
					m[i][j] = m[i-1][j];
				else
					m[i][j] = max(m[i-1][j], m[i-1][j-peso] + poder); 
			}
		}
		
		int k, r;
		cin >> k >> r;
		
		cout << (m[n][k] >= r ? "Missao completada com sucesso" : "Falha na missao") << endl;
	}

	return 0;
}