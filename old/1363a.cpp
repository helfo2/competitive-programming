#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;

    while(t--){
        int n, x; cin >> n >> x;
        int a[1010];
        for (int i = 0; i < n; i++){ 
            cin >> a[i]; 
        }

        int odd_numbers = 0, even_numbers = 0;        
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0){
                even_numbers++;
            } else {
                odd_numbers++;
            }
        }

        bool can = false;
        for(int i = 1; i <= x && i <= odd_numbers; i+=2){
            int need = x - i;
            if(need <= even_numbers){
                can = true;
            }
        }

        if(can){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}