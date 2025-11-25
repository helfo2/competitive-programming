#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

ll gcd(int x){
	ll fat = 1;

	for(ll i = 2; i <= x; i++){
		fat *= i;
	}

	return fat;
}


int main(void){
	ll a, b; cin >> a >> b;


	cout << gcd(min(a, b)) << endl;
}