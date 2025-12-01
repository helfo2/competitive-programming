#include <iostream>

using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];
    for (int& a : arr) cin >> a;

    int max_so_far = arr[0];
    int max_count = 1, global_max = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= max_so_far) {
            max_count++;

        } else {
            max_so_far = arr[i];
            global_max = max(global_max, max_count);
            max_count = 1;
        }
        max_so_far = arr[i];
    }
    cout << max(global_max, max_count) << endl;

    return 0;
}