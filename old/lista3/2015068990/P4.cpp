#include <bits/stdc++.h>
using namespace std;

#define MAX 5000

struct point {
	int x, y;

	inline double dist(point a){
		return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
	}
};

point all[MAX];
double dist[MAX][MAX], dp[MAX][MAX];

int main(void){
	int n; 

	while(cin >> n){
		for(int i = 1; i <= n; i++){
			cin >> all[i].x >> all[i].y;
			for(int j = 1; j < i; j++){
				// cout << all[i].dist(all[j]) << endl;
				dist[i][j] = all[i].dist(all[j]);
			}
		}

		for(int i = n-1; i >= 2; i--){
			for(int j = 1; j < i; j++){
				if(i == n-1){
					dp[i][j] = dist[n][i] + dist[n][j];
				} else {
					dp[i][j] = min(dp[i+1][j]+dist[i+1][i], dp[i+1][i]+dist[i+1][j]);
				}
			}
		}

		double res = dist[2][1] + dp[2][1];

		cout << fixed << setprecision(2) << res << endl;
	}

	return 0;
}