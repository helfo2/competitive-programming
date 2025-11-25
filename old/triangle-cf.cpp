#include <iostream>

using namespace std;

int dist(int a1, int b1, int a2, int b2) {
	return (a1 - a2) * (a1 - a2) + (b2 - b1) * (b2 - b1);
}

bool tri(int x1, int y1, int x2, int y2, int x3, int y3) {
	int d1 = dist(x2, y2, x3, y3),
		d2 = dist(x2, y2, x1, y1),
		d3 = dist(x3, y3, x1, y1);

	return d1 > 0 && d2 > 0 && d3 > 0 && d1 == d2 + d3;
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
	return tri(x1, y1, x2, y2, x3, y3) || tri(x2, y2, x1, y1, x3, y3) || tri(x3, y3, x2, y2, x1, y1);
}

int main(void) {
	int c[6]; 

	for(int i = 0; i < 6; i++) cin >> c[i];

	if(check(c[0], c[1], c[2], c[3], c[4], c[5])) {
		cout << "RIGHT" << endl;
		return 0;
	} else {
		for(int i = 0; i < 6; i++) {
			for(int j = 1; j >= -1; j -= 2) {
				c[i] += j;

				if(check(c[0], c[1], c[2], c[3], c[4], c[5])) {
					cout << "ALMOST" << endl;
					return 0;
				}

				c[i] -= j;
			}
		}
	}

	cout << "NEITHER" << endl;
	return 0;
}
