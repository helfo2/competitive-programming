#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool visited[200010];

int main(void){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> v(n);

        memset(visited, false, sizeof(bool));

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int ans = 1;
        for(int i = n-1; i >= 0; i--){
            if(v[i] <= i+1){
                ans += i+1;
                break;
            }   
        }

        cout << ans << endl;
    }

    return 0;
}