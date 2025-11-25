#include <iostream>
#include <string.h>
#define N 110
using namespace std;

string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
int a[N];

int main(void){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(a, 0, sizeof(a));

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        cout << s << endl;

        for(int i = 0; i < n; i++){
            if(s[a[i]] == 'a') {
                s[a[i]] = 'b';
            } else {
                s[a[i]] = 'a';
            }

            cout << s << endl;
        }
    }
    return 0;
}