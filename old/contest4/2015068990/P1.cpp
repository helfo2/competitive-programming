#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

int main(void){
	int n;

	while(cin >> n, n != 0){
		vector<ll> v(n);

		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		ll sum = 0;
		for(int i = n-1; i >= 0; i--){
			sum += v[i];
			for(int j = 0; j < i; j++){
				v[j] += v[i];
			}
		}

		cout << sum << endl;
	}

	return 0;
}
