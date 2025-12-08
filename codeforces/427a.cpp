#include <iostream>
using namespace std;

int main(void) {
    int n; cin >> n;
    int available = 0, crime_count = 0;
    for (int i = 0; i < n; i++) {
        int e; cin >> e;
        if (e >= 0) available += e;
        else {
            if (available > 0) {
                available--;
            }
            else {
                crime_count++;
            }
        } 
    }

    cout << crime_count << endl;
    return 0;
}