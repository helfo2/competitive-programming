#include <iostream>

using namespace std;

int main(void){
	int n;

	while(cin >> n, n != 0){
		cout << "Printing order for " << n << " pages:\n";

		int f1, f2, b1, b2;
		int x = 1, s = 1;

		if(n % 4 == 0){
			f1 = n;	
		} else if(n % 4 == 1){
			f1 = n + 3;
		} else if(n % 4 == 2){
			f1 = n + 2;
		} else if(n % 4 == 3){
			f1 = n + 1;
		}
		
		f2 = 1;

		b1 = 2;

		if(n % 4 == 0){
			b2 = n - 1;
		} else if(n % 4 == 1){
			b2 = n + 2;
		} else if(n % 4 == 2){
			b2 = n + 1;
		} else if(n % 4 == 3){
			b2 = n;
		}

		// cout << f1 << endl;
		if(n == 1){
			cout << "Sheet " << x << ", front: ";
			cout << "Blank, " << f2 << endl;
		} else {
			while(x <= n){
				cout << "Sheet " << s << ", front: ";
				
				if(f1 > n){
					cout << "Blank, " << f2 << endl;
				} else {
					cout << f1 << ", " << f2 << endl;
				}

				cout << "Sheet " << s << ", back : ";
				if(b2 > n){
					cout << b1 << ", Blank" << endl;
				} else {
					cout << b1 << ", " << b2 << endl;
				}

				// cout << "freakin f1 " << f1 << endl;

				f1 -= 2;
				b2 -= 2;

				f2 += 2;
				b1 += 2;

				x+=4; s++;
			}
		}	
	}

	return 0;
}