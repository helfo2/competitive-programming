#include <iostream>

using namespace std;

int main(void) {
    int n, k; cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++) {
        int x; cin >> x; 
        arr[i] = 5 - x;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= k) {
            count++;
        }
    }

    cout << count / 3 << endl;

    return 0;
}