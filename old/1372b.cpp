#include <iostream>
#define ll long long
using namespace std;

ll is_prime(ll x){
    if(x == 1){
        return -1;
    }

    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0){
            //cout << "i = " << i << endl;
            return i;
        }
    }

    return 0;
} 


int main(void){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;

        if(n % 2 == 0){
            cout << n/2 << " " << n/2 << endl;
        }else{
            ll x = is_prime(n);
            if(x == 0){
                cout << 1 << " " << n-1 << endl;
            } else {
                cout << x << " " << n-x << endl;
            }
        }
    }
    return 0;
}
