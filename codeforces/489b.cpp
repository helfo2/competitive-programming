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

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(boys[i] - girls[j]) <= 1) {
                ans++;
                girls[j] = 1e9;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}