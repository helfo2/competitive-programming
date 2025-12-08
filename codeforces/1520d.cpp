#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        map<int, int> seen;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x -= i;
            count += seen[x];
            seen[x]++;
        }

        cout << count << endl;
    }
    return 0;
}