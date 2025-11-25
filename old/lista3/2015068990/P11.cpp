#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef unsigned long long ll;

set<int> prime;

void set_prime(int P){
	for(int p = 2; p*p <= P; p++){
		while((P % p) == 0){
			prime.insert(p);
			P /= p;
		}
	}

	if(P != 1)
		prime.insert(P);
}

ll square_exp(ll base, ll exp, ll mod){ 
    ll t = 1L;

    while(exp > 0){
    	if(exp % 2 != 0) {
    		t = (t * base) % mod;
    	}

    	base = (base * base) % mod;
    	exp /= 2;
    }

    return t % mod;
} 

int main(void){
	int n, e, c; cin >> n >> e >> c;
	int p, q; // n = pq

	p = 3;
	// primeiro pego o p
	while(1){
		if(n % p == 0)
			break;
		p++;
	}
	// depois o q
	q = n / p;

	p -= 1, q -= 1;
	ll phi = (p)*(q);

	// cout << p << " " << q << endl;

	set_prime(p);
	set_prime(q);

	int m = phi;
	for(auto i : prime){
		m = m - m/i;
	}

	ll d = square_exp(e, m-1, phi);
	printf("%d\n", (int)square_exp(c, d, n));

	return 0;
}