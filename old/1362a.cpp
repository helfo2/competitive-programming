#include <iostream>
#include <cmath>

#define ll unsigned long long

using namespace std;

int main(void){
    int t; cin >> t;

    while(t--){
        ll a, b; cin >> a >> b;
        ll _a, _b;
        if(a > b){
            _a = b;
            _b = a;
        } else {
            _a = a;
            _b = b;
        }

        ll count = 0;
        if(a == b){
            cout << count << endl;
        }
        else {
            bool can = false;
            // multiply
            for(ll i = _a; i <= _b; i *= 2){
                if(i < _b){
                    count++;
                } else if(i == _b){
                    can = true;
                    break;
                }
            }

            if(can){
                // cout << "a = " << _a << endl;
                // cout << "b = " << _b << endl;

                // cout << "count = " << count << endl;
                if(count >= 3){
                    if(ceil(count / 3.0) != count / 3){ count += 1; }
                    count = (ll)ceil(count / 3.0);
                } 
                else if(count >= 2){
                    count = (ll)ceil(count / 2);
                }

                // cout << "count2 = " << count << endl;
                cout << count << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}