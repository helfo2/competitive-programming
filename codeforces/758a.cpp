#include <iostream>

using namespace std;

int main(void) {
    int n; cin >> n;

    if (n == 1) { 
        cout << 0 << endl; 
        return 0;
    }
    
    int max_a = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_a = max(max_a, arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (max_a - arr[i] > 0) {
            sum += max_a - arr[i];
        }
    }

    cout << sum << endl;
    return 0;
}