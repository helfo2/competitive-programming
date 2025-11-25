#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int n;
	while(cin >> n){
		if(n == 0) break;

		int c = ceil(sqrt(n)); // em q quadrado
		// o padrao esta no canto superior direito
		int canto = c * c - c + 1;
		int x,y; x = y = c;

		if(c % 2==0){ // cima e esquerda
			if(n > canto){
				y -= (n - canto);
			} else {
				x -= (canto - n);
			}
		} else { // direita e baixo
			if(n > canto){
				x -=(n - canto);
			} else {
				y -= (canto- n);
			}
		}

		cout << x << " " << y << endl;
	}

	return 0;
}