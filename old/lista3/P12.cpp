#include <bits/stdc++.h>
#define MAX 10000000

typedef long long ll;

using namespace std;

bool prime[MAX];

void set_prime(){
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for(ll p = 2; p*p < MAX; p++){
		if(prime[p] == true){
			for(ll i = p*2; i <= MAX; i+=p){
				prime[i] = false;
			}
		}
	}
}

ll dp(ll n, ll r) 
{
    ll pascal[r+1]; 
    memset(pascal, 0, sizeof(pascal));
  
    pascal[0] = 1; // triangulo de pascal
  
    for (ll i = 1; i <= n; i++) 
    { 
        // monta o triangulo
        for (ll j = min(i, r); j > 0; j--)
            pascal[j] = (pascal[j] + pascal[j-1])%2; 
    }

    return pascal[r];
} 
  
// Teorema de Lucas q calcula paridade da combinacao (n r) 
// dependendo da paridade iremos determinar 
// o vencedor do jogo Par ou Impar 2.0
ll lucas(ll n, ll r) 
{
	if(r==0)
		return 1; 

	// ultimo digito binario
	ll ni = n%2, ri = r%2; 

	// agrega a multiplicacao para descobrir a paridade
	return (lucas(n/2, r/2) * // para cada fator
		dp(ni, ri)) % 2;  // para os digitos atuais
} 

int main(void){
	ll a, b; cin >> a >> b;

	if(a == b){
		printf("?\n");
	} else {
		set_prime();

		ll primes = 0, interval = abs(b-a);

		ll _min = min(a, b);
		ll _max = max(a, b);

		for(ll i = _min; i <= _max; i++){
			if(prime[i]) {
				primes++;
			}
		}

		int p = lucas(primes+interval-1, interval);

		if(p != 0){
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	}

	return 0;
}