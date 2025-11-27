#include <iostream>

using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count_amazing = 0;
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        bool max = true, min = true;
        for (int j = i - 1; j >= 0; j--) {
            if (curr <= arr[j]) {
                max = false;
            }
            if (curr >= arr[j]) {
                min = false;
            }
        }
        if (max || min) {
            count_amazing++;
        }
    }

    cout << count_amazing << endl;
    return 0;
}