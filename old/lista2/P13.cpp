#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void){
	int n; cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	map<int, int> dp;
	// inicializa
	for(int i = 0; i < n; i++){
		dp[v[i]] = 0;
	}

	int max_sub = 0;
	int ultimo = 0;
	// computa o maior tamanho da subsequencia
	// maximo entre incluir somente o carinha ou o anterior a ele
	for(int i = 0; i < n; i++){
		dp[v[i]] = max(dp[v[i]], dp[v[i] - 1] + 1);
		if(max_sub < dp[v[i]]) {
			max_sub = dp[v[i]];
			ultimo = v[i];
		}
	}

	cout << max_sub << endl;
	// cout << ultimo << endl;

	vector<int> pos;
	// pega as posicoes de cada "maior tamanho"
	for(int i = n-1; i >= 0; i--){
		if(v[i] == ultimo){
			pos.push_back(i+1);
			ultimo--;
		}
	}

	reverse(pos.begin(), pos.end());

	for(auto it : pos){
		cout << it << " ";
	}
	cout << endl;

	return 0;
}