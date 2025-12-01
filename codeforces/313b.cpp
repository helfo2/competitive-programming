#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
......

*/
int main(void) {
    string s; cin >> s;
    int m; cin >> m;
    int n = s.size();
    
    vector<int> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1] || i + 1 >= n) {
            prefix[i] = 1;
        }
        // cout << prefix[i] << " ";
    }
    // cout << endl;
    
    vector<int> dp(n);
    dp[0] = prefix[0];
    for (int i = 1; i < n; i++) {
        dp[i] = prefix[i - 1] + dp[i - 1];
        // cout << dp[i] << " ";
    }
    // cout << endl;

    while (m--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << dp[r] - dp[l] << endl;
    }
    
    return 0;
}