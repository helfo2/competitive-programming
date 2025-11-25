#include <iostream>
#include <vector>

using namespace std;

int main(void){
	vector<int> squares(10010);
	for(int i = 0; i < 10010; i ++){
		for(int j = 0; i*i + j*j < 10010; j++){
			squares[i*i + j*j] = 1;
		}	
	}

	// for(auto it : squares){
	// 	cout << it << endl;
	// }

	int n;
	while(cin >> n){
		if(n < 0) {
			cout << "NO\n";
		} else {
			if(squares[n] == 1){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}