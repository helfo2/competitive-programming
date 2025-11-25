#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int t; cin >> t;

    while(t--){
        int n, jokers, k; cin >> n >> jokers >> k;

        int hand_cards = (n/k);
        
        int ans = 0;
        for(int a1 = 0; a1 <= jokers; a1++){
            for(int a2 = 0; a2 <= jokers; a2++){
                if(a1 >= a2 && a1 <= hand_cards && (a1 + a2) <= jokers && a1 + (k-1)*a2 >= jokers){
                   ans = max(ans, a1 - a2); 
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}