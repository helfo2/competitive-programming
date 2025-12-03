#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n; cin >> n;
    int boys[n];
    for (auto& i : boys) cin >> i;

    int m; cin >> m;
    int girls[m];
    for (auto& i : girls) cin >> i;

    sort(boys, boys + n);
    sort(girls, girls + m);

    int dp[n + 100][n + 100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }

            if (abs(boys[i] - girls[j]) <= 1) {
                dp[i][j]++;
            }

            if (i - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

            if (j - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}