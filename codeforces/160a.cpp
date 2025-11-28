#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    int i = 0, j = n - 1;
    int sum_i = arr[0], sum_j = arr[n - 1];
    while (i < j) {
        while (sum_i <= sum_j && i < j) {
            i++;
            sum_i += arr[i];
        }
        j--;
        sum_j += arr[j];
    }

    cout << i + 1 << endl;

    return 0;
}