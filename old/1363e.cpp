#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int N = 2e5 + 5;

ll n, cost = 0;
ll arr[N], b[N], c[N];
vector<ll> g[N];

pair<ll, ll> dfs(ll u, ll parent, ll mn){
    pair<ll, ll> a = {0, 0};

    if(b[u] != c[u]){
        if(b[u]) a.first++;
        else a.second++;
    }

    for(auto &it : g[u]){
        if(it == parent) continue;

        pair<ll, ll> p = dfs(it, u, min(mn, arr[u]));
        a.first += p.first;
        a.second += p.second;
    }

    if(arr[u] < mn){
        int take = min(a.first, a.second);
        cost += 2 * take * arr[u];
        a.first -= take;
        a.second -= take;
    }

    return a;
}

int main(void){
    IOS;

    cin >> n;

    for(ll i = 1; i <= n; i++){
        cin >> arr[i] >> b[i] >> c[i];
    }

    for(ll i = 1; i <= n-1; i++){
        ll u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    pair<ll, ll> ans = dfs(1, 0, 2e9);
    if(ans.first || ans.second){
        cout << -1;
    } else {
        cout << cost;
    }

    return 0;
}