#include<iostream>
#include <vector>
#include <utility>
#include <climits>
#include <set>
#include <cstdio>

using namespace std;

int inf = 100009;

int c, s, q;
int g[1005][1005];

int min_deci(int b, int e){
	

	// cout << "dist:\n";
	// for(int i = 0; i < c; i++){
	// 	for(int j = 0; j < c; j++){
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return g[b][e];
}


int main(void){
	int k = 1;
	int blank = false;
	// int test1, test2, test3;
	// cin >> test1 >> test2 >> test3;
	// cout << test1 << " " << test2 << " " << test3 << endl;

	while(scanf("%d %d %d", &c,&s,&q) == 3){
		// cout << "c = " << c << endl;
		if(c == 0) break;

		if(blank){
			printf("\n");
		} 
		blank = true;
		
		printf("Case #%d\n",k);

		for(int i = 0; i <= c; i++){
			for(int j = 0; j <= c; j++){
				g[i][j] = inf;
			}
		}

		while(s--){
			int u, v, w; scanf("%d%d%d",&u,&v,&w);
			g[u][v] = g[v][u] = w;
		}

		// for(int i = 0; i < c; i++){
		// 	for(int j = 0; j < c; j++){
		// 		cout << g[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		for(int k = 1; k <= c; k++){
			for(int i = 1; i <= c; i++){
				for(int j = 1; j <= c; j++){
					g[i][j] = g[j][i] = min(g[i][j], max(g[k][j], g[i][k]));
				}
			}
		}

		while(q--){
			// cout << "what\n";
			int b, e; scanf("%d%d",&b,&e);

			// cout << b << " " << e << endl;
			int sol = min_deci(b, e);

			if(sol == inf){
				printf("no path\n");
			} else{
				printf("%d\n", sol);
			}

		}

		k++;
	}

	return 0;
}