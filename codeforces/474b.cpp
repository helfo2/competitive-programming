#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];
    for (int& a: arr) cin >> a;

    int buckets[n];
    buckets[0] = arr[0];
    for (int i = 1; i < n; i++) {
        buckets[i] = buckets[i - 1] + arr[i];
    }

    int w; cin >> w;
    int worms[w];
    for (int& worm: worms) cin >> worm;

    for (int i = 0; i < w; i++) {
        int b = 0, e = n;
        while (b < e) {
            int mid = (b + e) / 2;
            if (worms[i] <= buckets[mid]) {
                e = mid;
            } else {
                b = mid + 1;
            }
        }

        cout << e + 1 << endl;
    }

    return 0;
}