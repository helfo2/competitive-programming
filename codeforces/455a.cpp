#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ull unsigned long long 

using namespace std;

int main(void) {
    int n; cin >> n;
    map<ull, ull> counts;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        counts[x]++;
        max_val = max(max_val, x);
    }

    // for (int i = 0; i <= n; i++) {
    //     cout << "counts of " << i << " " <<  counts[i] << endl;
    // }
    vector<ull> dp(max_val + 1, 0);
    dp[0] = 0;
    dp[1] = counts[1];

    for (int i = 2; i <= max_val; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * counts[i]);
        // cout << "dp of " << i << " " <<  dp[i] << endl;
    }

    cout << dp[max_val] << endl;
    return 0;
}