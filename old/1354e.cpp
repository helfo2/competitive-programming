#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main(void){    
    int n; cin >> n;
    while(n--){
        ll ans = 0;
        ll a, b, c, d; cin >> a >> b >> c >> d;

        ll start = a - b;

        if(start <= 0){
            cout << b << endl;
        } 
        else if(d >= c){
            cout << -1 << endl;
        } 
        else {
            ll times = ceil( start / (double)(c - d) );

            ans = b + times * c;
            cout << ans << endl;
        }
    }
    
    return 0;
}