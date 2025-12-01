#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, l; cin >> n >> l;
    int arr[n];
    for (auto &a : arr) cin >> a;

    sort(arr, arr + n);

    int b = arr[0], e = l - arr[n - 1];
    int max_dist = 0;
    for (int i = 1; i < n; i++) {
        max_dist = max(max_dist, (arr[i] - arr[i - 1]));
    }

    int ans = max(max_dist, max(b * 2, e * 2));
    printf("%.10f\n", (double)(ans) / 2.);
}