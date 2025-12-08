#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int& i : arr) cin >> i;

        set<int> sums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sums.insert(arr[i] + arr[j]);
            }
        }

        set<int> used;
        int local_max = 0, global_max = 0;
        for (auto sum : sums) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (used.find(i) == used.end()
                        && used.find(j) == used.end()
                        && arr[i] + arr[j] == sum) {
                        used.insert(i);
                        used.insert(j);
                        local_max++;
                    }
                }
            }
            global_max = max(global_max, local_max);
            local_max = 0;
            used.clear();
        }

        cout << global_max << endl;
    }

    return 0;
}