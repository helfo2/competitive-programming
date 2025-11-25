#include <iostream>
#include <vector>

using namespace std;

vector<int> g[210];
int color[210];

int n, l;
bool colorable;

void dfs(int s, int c){
	if(color[s] != 0) {
		if(c != color[s]){
			colorable = false;
		}
	} else {
		color[s] = c;
		for(auto it:g[s]){
			int c2 = c == 1 ? 2 : 1;
			dfs(it, c2);
		}
	}
}

int main(void){
	while(cin >> n){
		if(n == 0) break;

		for(int i =0;i < n; i++){
			g[i].clear();
			color[i] = 0;
		}

		cin >> l;
		while(l--){
			int a, b; cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		colorable = true;
		dfs(0, 1);

		if(colorable){
			cout << "BICOLORABLE.\n";
		} else {
			cout << "NOT BICOLORABLE.\n";
		}
	}

	return 0;
}