#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int n; 

bool dp[11][10005];

bool solve(int i, int sa, int sb){
	// cout << "sa = " << sa << " sb = " << sb << endl;

	if(abs(sa - sb) > 5) {
		// cout << "false\n";
		return false;
	} else if(i == v.size()) return true;

	return solve(i+1, sa + v[i], sb) || solve(i+1, sa, sb + v[i]);
}

int main(void){
	int t; cin >> t;

	while(t--){
		cin >> n;
		v.clear();
		v.resize(n);

		// memset(dp, 0, sizeof(dp));

		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		for(int j = 0; j <= 10; j++){
			dp[j][n] = true;
		}

		for(int i = n-1; i >= 0; i--){
			for(int j = 0; j <= 10; j++){
				dp[j][i] = false;

				if(j+v[i] <= 10 && dp[j+v[i]][i+1]){
					dp[j][i] = true;
				}

				if(j-v[i] >= 0 && dp[j-v[i]][i+1]){
					dp[j][i] = true;
				}
			}
		}

		if(dp[5][0])
			cout << "Feliz Natal!\n";
		else 
			cout << "Ho Ho Ho!\n";
	}

	return 0;
}