#include <bits/stdc++.h>
#define MAX 2000107

typedef long long ll;

using namespace std;

bool prime[MAX];

void set_prime(){
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = true;

	for(int p = 2; p*p < MAX; p++){
		if(prime[p] == true){
			for(int i = p*2; i <= MAX; i+=p){
				prime[i] = false;
			}
		}
	}
}

int main(void){
	int t; cin >> t;

	set_prime();

	while(t--){
		int n; cin >> n;
		bool initial_numbers[MAX];
		ll last_prime = 0;

		memset(initial_numbers, false, sizeof(initial_numbers));

		for(int i = 0; i < n; i++){
			ll a; cin >> a;
			if(a > MAX) {
				continue;
			}

			if(prime[a] && a > last_prime) {
				last_prime = a;
			}
			initial_numbers[a] = true;
		}

		// cout << last_prime << endl;
		ll ans = -1;
		for(int i = 1; i <= MAX; i++){
			// cout << "i = " << i << endl;
			// cout << prime[i] << endl;
			// cout << initial_numbers[i] << endl;

			if(prime[i] && !initial_numbers[i]){
				ans = i;
				break;
			}
		}

		cout << ans - 1 << endl;
	}

	return 0;
}