#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(void) {
    int n, x; cin >> n >> x;

    ll coins[n];

    for (ll& i : coins) cin >> i;

    vector<ll> dp(x + 1, 1e9);
    dp[0] = 0;

    // 11
    // 1 5 7


    /*
    0 1
    0 
    */

    for (int i = 1; i <= x; i++) {
        for (int c = 0; c < n; c++) {
            if (i - coins[c] >= 0) {
                dp[i] = min(dp[i - coins[c]] + 1, dp[i]);
            }
        }
    }

    ll ans = dp[x] == 1e9 ? -1 : dp[x];
    cout << ans << endl;
    return 0;
}