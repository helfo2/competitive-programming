#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <cstdio>

using namespace std;

const int MAX=1e5+1;

int pai[MAX], rk[MAX]={0}, relig;

int acha(int a){
	if(pai[a]==a)
		return a;

	int t = a;

	while(pai[t]!=t)
		t = pai[t];

	while(pai[a]!=a){
		int c = pai[a];
		pai[a] = t;
		a = c;
	}

	return t;
}

void une(int a, int b){
	a = acha(a);
	b = acha(b);

	if(a == b){
		return;
	}

	relig--;

	if (rk[a] > rk[b]){
		pai[b] = a;
	}
	else if (rk[a] < rk[b]){
		pai[a] = b;
	}
	else {
		pai[a] = b;
		rk[b]++;
	}
}

/*
Case 1: 1
Case 2: 7
Case 3: 3
Case 4: 3
Case 5: 3
Case 6: 1
*/
int main(void){
	int n, m;
	int k = 1;

	while(cin >> n >> m){
		if(n == 0) break;

		relig = n;

		for(int i = 0; i < n; i++){
			pai[i] = i;
			rk[i] = 0;
		}

		while(m--){
			int a, b; cin >> a >> b;
			une(a, b);
		}
		
		printf("Case %d: %d\n", k, relig);
		k++;
	}

	return 0;
}