#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

ll get_next(int n){
	int d = 0, temp = n;
	while(temp > 0){
		d++;
		temp /= 10;
	}

	ll i = 1, _d = 0;
	while(_d <= d){
		i = (i*10) + 1;
		_d++;
	}

	return i;
}

int main(void){ cin.tie(NULL); cout.tie(NULL);
	ll n;

	while(cin >> n){
		
		ll i = 11, d = 1;
		while(i % n != 0){
			i = ((i*10) + 1) % n;
			d++;
		}

		cout << d+1 << endl;
	}

	return 0;
}