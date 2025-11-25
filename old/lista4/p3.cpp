#include <bits/stdc++.h>



char str[MAXN];

void stevehalim() {
	for(int n=1; n<MAXN; n++) {
		if (n <= 2) { mex[n] = 0; continue; }
		set<int> jog;
		for(int i=3; i<=n-2; i++) {
			jog.insert(mex[i-1]^mex[n-i]);
		}
		int cnt = 0;
		while(jog.count(cnt)) cnt++;
		mex[n] = cnt;
	}
	//for(int n=1; n<MAXN; n++) printf("%d,", mex[n]);
}