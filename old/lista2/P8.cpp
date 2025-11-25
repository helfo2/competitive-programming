#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n; cin >> n;

	vector<int> v(n+2);
	v[0] = 0;
	v[n+1] = 0;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	// corrige as alturas para a esquerda
	for(int i = 1; i <= n; i++){
		if(v[i] > v[i-1]){
			v[i] = v[i-1] + 1;
		}
	}

	// corrige as alturas para a direita
	for(int i = n; i >= 1; i--){
		if(v[i] > v[i+1]){
			v[i] = v[i+1] + 1;
		}
	}

	// maior eh soh a maior altura corrigida
	int iso = 0;
	for(auto it : v){
		if(it > iso){
			iso = it;
		}
	}

	cout << iso << endl;
	return 0;
}