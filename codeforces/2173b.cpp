#include <iostream>
#define ll long long

using namespace std;

int main(void) {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        ll dp[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll from_a = max(
                    dp[i - 1][j] - a[i - 1], 
                    b[i - 1] - dp[i - 1][j]); 
                
                ll from_b = max(dp[i][j - 1] - a[i - 1], 
                    b[i - 1] - dp[i][j - 1]);

                dp[i][j] = max(from_a, from_b);
            }
        }
        cout << endl;

        cout << dp[n] << endl;
    }
    return 0;
}