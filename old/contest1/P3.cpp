#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

#define ll unsigned long long

using namespace std;

void print(vector<ll>& v) {
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void){
	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		vector<ll> v(n);

		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		// for(int i = 0; i < n; i++){
		// 	cout << v[i] << " ";
		// }
		// cout << endl;

		sort(v.begin(), v.end());

		ll ans = 1;
		for(int i = 0; i < n; i++){
			if(v[i] > ans){
				break;
			}
			ans += v[i];
		}

		cout << ans << endl;
	}

	return 0;
}