#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int main(void){
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        set<int> s;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            s.insert(x);
        }

        int c = 0;
        int ans = 0;
        int _xor = 0;
        bool finished = false;

        for(int i = 1; i <= 1024; i++){
            _xor = i ^ *s.begin();
            finished = false;
            c = 0;

            if(s.find(_xor) != s.end()){
                // cout << "found! " << _xor << endl;
                c++;
                for(auto it = next(s.begin()); it != s.end(); it++){
                    _xor = i ^ *it;
                    if(s.find(_xor) != s.end()){
                        c++;
                    } else {
                        break;
                    }
                }

                // cout << "c = " << c << endl;

                if(c == (int)s.size()){
                    finished = true;
                    ans = i;

                    cout << ans << endl;
                    break;
                }
            }
        }

        if(!finished){
            cout << -1 << endl;
        }
    }

    
    return 0;
}