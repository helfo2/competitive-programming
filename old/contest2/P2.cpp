#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int fat[9];

	fat[0] = 1;
	fat[1] = 1;
	fat[2] = 2;
	fat[3] = 6;
	fat[4] = 24;
	fat[5] = 120;
	fat[6] = 720;
	fat[7] = 5040;
	fat[8] = 40320;
	// fat[9] = 362880;
	// fat[10] = 3628800;

	int n; cin >> n;
	int ans = 0;
	for(int i = 8; i >= 0; i--){
		ans += (n / fat[i]);
		n %= fat[i];
	}

	cout << ans << endl;

	return 0;
}