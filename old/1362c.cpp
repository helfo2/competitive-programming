#include <iostream>

#define ll unsigned long long 

using namespace std;

int main(void){
    int t; cin >> t;

    while(t--){
        ll a; cin >> a;

        ll ans = 0;
        for(int i = 0; i < 60; i++){ // 10 ^ 18 <= 2 ^ 60
            if(a & (1LL << i)){
                ans += (1LL << (i + 1)) - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}