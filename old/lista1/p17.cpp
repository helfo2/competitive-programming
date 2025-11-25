#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <cstdio>
#include <string>

using namespace std;

int inf = 100009;
int gy[26][26], gm[26][26];

int main(void){
	int n;

	while(cin >> n){
		if(n == 0) break;

		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				gy[i][j] = gm[i][j] = inf;
			}
		}

		int t = n;
		char age, dir, a, b;
		int energy;
		while(t--){
			cin >> age >> dir >> a >> b >> energy;
			// cout << age << " " << dir << " " << a << " " << b << " " << energy << endl;

			int x = a-'A', y = b-'A';
			if(age == 'Y'){
				if(dir == 'U') {
					gy[x][y] = min(gy[x][y], energy);
				} else {
					gy[x][y] = gy[y][x] = min(gy[x][y], energy);
				}
			} else{
				if(dir == 'U') {
					gm[x][y] = min(gm[x][y], energy);
				} else {
					gm[x][y] = gm[y][x] = min(gm[x][y], energy);
				}
			}
		}

		char s, e; cin >> s >> e;
		int x = s-'A', y = e-'A';

		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				for(int k = 0; k < 26; k++){
					gy[j][k] = min(gy[j][k], gy[j][i]+gy[i][k]);
					gm[j][k] = min(gm[j][k], gm[j][i]+gm[i][k]);
				}
			}
		}

		int ans = inf;
		for(int i = 0; i < 26; i++){
			if(gy[x][i]+gm[y][i] < ans){
				ans = gy[x][i]+gm[y][i];
			}
		}

		if(ans == inf) {
			cout << "You will never meet.\n";
		} else {
			cout << ans;
			for(int i = 0; i < 26; i++){
				if(gy[x][i]+gm[y][i]==ans) {
					printf(" %c",i+'A');
				}
			}
			cout << endl;
		}
	}

	return 0;
}