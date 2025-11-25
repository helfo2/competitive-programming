#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

string s;

int main(void) {
    int t; cin >> t;

    while(t--){
        cin >> s; cin.ignore();
        int all_ones = 0, all_zeros = 0;
        for(auto i : s){
            if(i == '0') {
                all_zeros++;
            } else {
                all_ones++;
            }
        }

        int ones_until_now = 1, zeros_until_now = 1;
        int op1 = 1001, op2 = 1001;
        int res = min(all_zeros, all_ones);

        for(auto i : s){
            if(i == '0'){
                zeros_until_now++;
            } else {
                ones_until_now++;
            }

            op1 = min(op1, zeros_until_now + all_ones - ones_until_now);
            op2 = min(op2, ones_until_now + all_zeros - zeros_until_now);

            res = min(res, min(op1, op2));
        }

        cout << res << endl;
    }

    return 0;
}