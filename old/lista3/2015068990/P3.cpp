#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[10001];

void init(){
	// para somente um lancamento 
	// temos duas formas de nao acontecerem duas coroas seguidas
	f[1] = 2;
	// para dois lancamentos 
	// temos tres formas de nao acontecerem duas coroas seguidas
	f[2] = 3;

	for(int i = 3; i <= 10000; i++){
		f[i] = f[i-1] + f[i-2];
	}
}

ll mdc(ll a, ll b){
	if(a == 0) 
		return b;

	return mdc(b%a, a);
}

int main(void){
	init();

	int n;
	while(cin >> n){
		ll x = f[n], den = pow(2,n);
		ll _mdc = mdc(x, den);
		
		// cout << "x = " << x << endl;
		// cout << "den = " << den << endl;

		x = x / _mdc;
		den = den / _mdc;

		cout << x << "/" << den << endl;
	}

	return 0;
}