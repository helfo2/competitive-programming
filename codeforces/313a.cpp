#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;

    if (n > 0) cout << n << endl;
    else {
        int x = n * -1;
        int without_last = x / 10;
        int without_second_last = (x / 100) * 10 + (x % 10);
        int result = min(without_last, without_second_last);
        cout << result * -1 << endl;
    }

    return 0;
}