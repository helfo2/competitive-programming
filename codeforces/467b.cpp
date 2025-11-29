#include <iostream>
#define ull unsigned long long

using namespace std;

int main(void) {
    int n, m, k; cin >> n >> m >> k;

    ull arr[m + 1];
    for (int i = 0; i <= m; i++) {
        cin >> arr[i];
    }

    int friends = 0;
    
    for (int i = 0; i < m; i++) {
        ull same_bits = arr[m] ^ arr[i];
        int count = __builtin_popcountll(same_bits);
        if (count <= k) {
            friends++;
        }
    }
    cout << friends << endl;
}