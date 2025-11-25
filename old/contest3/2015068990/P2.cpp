#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n; cin >> n;

	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	bool can = false;
	for(int i = 0; i < n-2; i++){
		if(v[i] + v[i+1] > v[i + 2]){
			can = true;
			break;
		}	
	}

	cout << (can ? "YES\n" : "NO\n");

	return 0;
}