#include <iostream>
#include <algorithm>
#include <cmath>
#define ll unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll test_division(ll n){
    if(n % 2 == 0){
        n--;    
    }

    for(ll i = n; i > 0; i-= 2){
        if(n % i == 0){
            return i;
        }
    }

    return -1;
}

int main(void){
    IOS;

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        
        ll count = 1;
        while(n >= 1){
            ll test = test_division(n);
            if(test != - 1){
                if((n / test) % 2 == 0){
                    n = (n / test);
                } else {
                    n--;
                }
            }

            count++;
        }
        
        if(count % 2 == 1){
            cout << "Ashishgup\n";
        } else {
            cout << "FastestFinger\n";
        }
    }

    return 0;
}
