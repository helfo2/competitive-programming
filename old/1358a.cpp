#include<iostream>
#include <algorithm>

using namespace std;

int main(void){
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        int ans = 0;
        ans = (n / 2) * m;

        int r = n % 2;
        if(r > 0){
            ans += m / 2 + m % 2;
        }
        cout << ans << endl;
    }
    
    return 0;
}