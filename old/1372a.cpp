#include <iostream>
using namespace std;

int main(void) {
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        cout << 1;
        int num = 42;
        for(int i = 0; i < n-1; i++){
            cout << " " << num;
            //num += 2;
        }
        cout << endl;
    }

    return 0;
}