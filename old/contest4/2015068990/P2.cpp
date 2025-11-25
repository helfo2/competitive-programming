#include <iostream>

using namespace std;

bool r(double l, double c, double r1, double r2) {
	double x = l - r1 - r2, y = c - r1 -r2;

	if(x < 0 || y < 0) return false;
	else
		return x*x + y*y >= (r1 + r2)*(r1 + r2) && min(l, c) >= 2 * max(r1, r2);
}

int main(void) {
	double l, c, r1, r2;
	
	while(cin >> l >> c >> r1 >> r2 && (l+c+r1+r2)) {
		if(r(l, c, r1, r2)) cout << "S" << endl;
		else cout << "N" << endl;
	}

	return 0;
}