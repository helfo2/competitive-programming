#include <iostream>
#define ull unsigned long long
using namespace std;

int main(void) {
    int t; cin >> t;

    while (t--) {
        ull n; cin >> n;
        ull count_zeros = 0;
        int b[n];
        for (auto& i: b) cin >> i;

        ull sum = 0;
        for (int i = 0; i < n; i ++) {
            if (b[i] == 0) {
                count_zeros++;
            }
            sum += b[i];
        }

        ull ans = min(n - count_zeros, sum - n + 1);
        cout << ans << endl;
    }
    return 0;
}