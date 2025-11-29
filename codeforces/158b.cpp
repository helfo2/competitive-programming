#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];

    for (auto& i : arr)  cin >> i;

    sort(arr, arr + n);    

    int i = 0, j = n - 1; 
    int taxis = 0;
    // 1 2 3 3 4
    while (i < j) {
        if (arr[i] + arr[j] <= 4) {
            arr[j] += arr[i];
            i++;
        }
        else {
            j--;
            taxis++;
        }
    }

    cout << taxis + 1 << endl;
    return 0;
}