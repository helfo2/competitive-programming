#include <iostream>
#include <algorithm>
#define ll unsigned long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int main(void){
    IOS;

    ll k; cin >> k;

    string s = "codeforces";
    ll n = 45;

    ll count = 1;

    cout << s;

    for(count = 1; count < k; count *= n){
        cout << s;
    }
    cout << endl;

    return 0;
}