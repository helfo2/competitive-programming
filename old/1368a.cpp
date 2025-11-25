#include <iostream>
#include <algorithm>
#include <cmath>
#define ll unsigned long long
using namespace std;

int main(void){
    int t; cin >> t;
    while (t--){
        ll a, b, n; cin >> a >> b >> n;
        ll _min = min(a, b), _max = max(a, b);

        ll count = 0;
        while(max(_min, _max) <= n){
            ll temp_max = max(_min, _max), temp_min = min(_min, _max);
            
            ll s = _max + _min;

            if(_min == temp_min){
                _min = s;
            } else {
                _max = s;
            }
            //cout << _max << " " << _min << endl;

            count++;
        }

        cout << count << endl;
    }
    
    return 0;
}