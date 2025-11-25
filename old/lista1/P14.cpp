#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

const int MAX=1e5+1;

using namespace std;

int pai[MAX], rk[MAX]={0};

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

float dist(float x1, float y1, float x2, float y2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool comp(pair<float, pair<int, int> >& a, pair<float, pair<int, int> >& b){
	return a.first - b.first < 0;
}

int main(void){
	int k; cin >> k;
	int k1 = 1;
	// cout << "k = " << k << endl;

	while(k--){
		int n; cin >> n;
		// cout << "n = " << n << endl;
		int m = n-1;

		vector<pair<float,pair<int,int> > > arestas;
		vector<pair<int, int> > points;

		for (int i=0; i<n; i++){
			pai[i] = i;
			rk[i] = 1;
		}
		
		for (int i=0; i<n; i++){
			float x, y; cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		
		// for (int i=0; i<n; i++){
		// 	cout << points[i].first << " " << points[i].second << endl;
		// }
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					float x = points[i].first, y = points[i].second;
					float a = points[j].first, b = points[j].second;

					arestas.push_back(make_pair(dist(x,y,a,b), make_pair(i,j)));
				}
			}
		}

		sort(arestas.begin(), arestas.end(), comp);

		vector<pair<float, pair<int, int> > > sol;
		for (int i=0;i < arestas.size(); i++){
			// printf("%f %d %d\n", arestas[i].first, arestas[i].second.first, arestas[i].second.second);
			if (acha(arestas[i].second.first)!=acha(arestas[i].second.second)){
				//adiciona aresta na solução
				sol.push_back(arestas[i]);
				// cout << arestas[i].first << endl;
				une(arestas[i].second.first,arestas[i].second.second);	
			}
		}

		float total_weight = 0;
		for(int i = 0; i < sol.size(); i++){
			total_weight += sol[i].first;
		}

		// cout << total_weight << endl;
		cout << fixed << setprecision(2) << total_weight << endl;
		
		if(k >= 1)
			cout << endl;

		// cout << "alo regina\n";
		arestas.clear();
		points.clear();
	}

	return 0;
}