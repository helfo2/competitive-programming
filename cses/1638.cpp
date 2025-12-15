#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int n; cin >> n;

    int MOD = 1e9 + 7;

    vector<string> s(n);
    for (auto& str : s) cin >> str;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (s[0][0] == '.') {
        dp[0][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') continue;

            if (i >= 1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

            if (j >= 1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }


//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//         cout << dp[i][j] << ' ';
//         }
//     cout << endl;}
// cout << endl;

    cout << dp[n - 1][n - 1] << endl;
    return 0;
}