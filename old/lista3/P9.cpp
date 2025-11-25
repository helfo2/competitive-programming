#include <bits/stdc++.h>
#define MAX 2000107

typedef long long ll;

using namespace std;

bool prime[MAX];
ll hyper[MAX];
ll divs[MAX];

void set_prime(){
	memset(prime, true, sizeof(prime));
	memset(divs, 0, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for(ll p = 2; p < MAX; p++){
		if(prime[p] == true){
			divs[p] = 2;
			for(ll i = p+p; i < MAX; i += p){
				
				ll k = i;
				ll d = 0;
				while(k % p == 0){
					k /= p;
					d++;
				}

				if(divs[i] == 0){
					divs[i] = d+1;
				} else {
					divs[i] *= (d+1);
				}

				prime[i] = false;
			}
		}
	}

	memset(hyper, 0, sizeof(hyper));

	hyper[1] = 0;

	// quantos hiper de 2 ate MAX consigo formar
	for(ll i = 2; i <= MAX; i++){
		hyper[i] = hyper[i-1]; // quantos ja conseguia antes
		// cout << "i = " << i << " divs[i] = " << divs[i] << endl;
		if(prime[divs[i]]){
			hyper[i]++; // mais um
		}
	}
}

int main(void){
	ll n; 

	set_prime();

	while(cin >> n){
		cout << hyper[n] << endl;
	}

	return 0;
}