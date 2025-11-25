#include <bits/stdc++.h>

using namespace std;

bool subseq(string& b, string& a, int sz_b, int sz_a, int x){
	int sub = 0;

	for(int i = 0; sub < sz_b * x && i < sz_a; i++){
		if(b[sub / x] == a[i]){
			sub++;
		}
	}

	return (sub == sz_b * x);
}


int main(void){
	string a, b;
	int t; cin >> t;

	while(t--){
		cin >> a >> b;

		int l = 0, r = a.size()/b.size() + 1, m, i;

		if(!subseq(b, a, b.size(), a.size(), 1)){
			cout << "0\n";
		} else {
			i = 0;

			while(!(r == l + 1)){
				m = l + ((r - l) / 2);

				if(subseq(b, a, b.size(), a.size(), m)){
					i = max(i, m);
					l = m;
				} else {
					r = m;
				}
			}

			cout << i << endl;
		}
	}

	return 0;
}