#include <bits/stdc++.h>
#define MAX 500

using namespace std;

int instance, n, m, k;

bool visited[MAX];
int g[MAX][MAX], res[MAX][MAX];
int p[MAX];
int sz;

bool dfs(int s, int t){
    visited[s] = true;

    if(s == t) return true;

    for(int v = 0; v < sz; v++){
        // se o fluxo cabe na capacidade da aresta 
        if(g[s][v] - res[s][v] > 0 && !visited[v]){
            p[v] = s;
            if(dfs(v, t)) 
                return true;
        }
    }

    return false;
}

bool find_path(int s, int t){
    memset(visited, false, sizeof(bool)*sz);

    return dfs(s, t);
}

int max_flow(int s, int t){
    for(int i = 0; i < sz; i++){
        memset(res[i], 0, sizeof(int)*(sz));
    }

    int d;

    p[s] = s;

    while(find_path(s, t)){
        d = INT_MAX;

        // o fluxo que ainda pode passar
        for(int c = t; p[c] != c; c = p[c]){
            d = min(d, g[p[c]][c] - res[p[c]][c]);
        }

        for(int c = t; p[c] != c; c = p[c]){
            res[p[c]][c] += d;
            res[c][p[c]] -= d;
        }
    }

    int sum = 0;
    for(int i = 0; i < sz; i++){
        sum += res[i][t];
    }

    return sum;
}

int main(void){
    instance = 1;
    
    while(cin >> n >> m >> k){
        printf("Instancia %d\n", instance);

        // +2 : sink e source
        sz = n + m + 2;
        for(int i = 0; i < sz; i++){
            memset(g[i], 0, sizeof(int)*(sz));
        }

        int c;
        for(int i = 1; i <= n; i++){
            cin >> c;
            g[m + i][n + m + 1] = c;
        }

        
        int u, v;
        for(int i = 0; i < k; i++){
            cin >> u >> v;
            g[v][m + u] = 1;
        }

        // conecta ao source
        for(int i = 1; i <= m; i++){
            g[0][i] = 1;
        }

        printf("%d\n\n", max_flow(0, m + n + 1));
        instance++;
    }

    return 0;
}