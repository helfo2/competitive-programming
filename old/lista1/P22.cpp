#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

unsigned long mdc(unsigned long a, unsigned long b){
	unsigned long temp;
	while(a % b){
		temp = a;
		a = b;
		b = temp % b;
	}
	return b;
}

int main(void){
	int k = 1;

	int n; cin >> n; n *= 2;
	do{
		string s1, s2; cin >> s1 >> s2;
		bitset<32> b1(s1), b2(s2);

		unsigned long x1 = b1.to_ulong(), x2 = b2.to_ulong();

		cout << "Pair #" << k << ": ";
		if(mdc(x1, x2) == 1)
			cout << "Love is not all you need!\n";
		else 
			cout << "All you need is love!\n";

		k++;
	}while(n-=2);

	return 0;
}