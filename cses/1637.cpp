#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<ull> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> digits;
        ull temp = i;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        for (int d : digits) {
            if (i - d >= 0) {
                dp[i] = min(dp[i - d] + 1, dp[i]);
            }
        }
    }

    // for (auto z : dp) cout << z << " ";
    // cout << endl;

    cout << dp[n] << endl;
}