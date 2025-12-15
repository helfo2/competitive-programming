#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

int main(void){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ull> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (i - c >= 0) {
                dp[i] = (dp[i] + dp[i - c]) % (ull)(1e9 + 7);
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}