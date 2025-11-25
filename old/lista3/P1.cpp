#include <bits/stdc++.h>
#define MAX 100100

using namespace std;

bool sieve[MAX];

void set_sieve(){
	memset(sieve, true, sizeof(sieve));
	sieve[0] = sieve[1] = false;

	for(int p = 2; p*p <= MAX; p++){
		if(sieve[p] == true){
			for(int i = p*2; i<= MAX; i+=p){
				sieve[i] = false;
			}
		}
	}
}

int is_super_prime(int n){
	bool prime, super_prime;
	prime = false;
	super_prime = true;

	if(sieve[n]){
		prime = true;
	}

	while(n > 0){
		int d = n % 10;
		if(!sieve[d]){
			super_prime = false;
			break;
		}

		n /= 10;
	}

	if(prime && super_prime){
		return 1;
	} else if(prime){
		return 2;
	} else {
		return 3;
	}
}

int main(void){
	int n; 
	
	set_sieve();

	while(cin >> n){
		int res = is_super_prime(n);
		
		switch(res){
			case 1: cout << "Super\n";
					break;
			case 2: cout << "Primo\n";
					break;
			case 3:	cout << "Nada\n";
					break;
		}
	}

	return 0;
}