#include <iostream>
#include <set>
#include <queue>
#include <utility>
#include <cstring>

#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int N = 2e5 + 5;
int n;
int degree[N];

int main(void){
    int t; cin >> t;

    while(t--){
        int x; cin >> n >> x;
        memset(degree, 0, sizeof(degree));

        for(int i = 1; i <= n - 1; i++){
            int u, v; cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }

        if(degree[x] <= 1){
            cout << "Ayush\n";
        } else {
            if(n % 2 == 0){
                cout << "Ayush\n";
            } else {
                cout << "Ashish\n";
            }
        }
    }

    return 0;
}