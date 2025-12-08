#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int max_sleep = 0, awake_until = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                awake_until = i + k;
            }
            else if (i > awake_until) {
                max_sleep++;
            }
        }

        cout << max_sleep << endl;
    }
    return 0;
}