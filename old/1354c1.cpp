#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    int t; cin >> t;

    const double pi = 3.14;

    while(t--){
        double n; cin >> n;
        
        long double ans = 1.0 / tan(M_PI / (2.0 * n));

        cout << fixed;
        cout << setprecision(9);
        cout << ans << endl;
    }

    return 0;
}