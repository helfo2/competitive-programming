#include <bits/stdc++.h>

using namespace std;

int max_elem;

int max3(int a, int b, int c){
	return max(max(a, b), c);
}

int max_sum(vector<int>& v, int l, int m, int r){
	int sum = 0, l_sum = INT_MIN, r_sum = INT_MIN; // menos infinito 
	int elem = 0;

	for(int i = m; i >= l; i--){
		sum += v[i];

		// printf("what %d\n", v[i]);
		if(sum > l_sum){
			l_sum = sum;
			elem++;
		}
	}


	sum = 0;

	for(int i = m+1; i <= r; i++){
		sum += v[i];
		// printf("what %d\n", v[i]);

		if(sum > r_sum){
			r_sum = sum;
			elem++;
		}
	}

	// printf("elem = %d\n", elem);

	max_elem = max(max_elem, elem);

	return l_sum + r_sum;
}

int max_sub_sum(vector<int>& v, int l, int r){
	if(l == r)
		return v[l];

	int m = l + ((r - l) / 2);

	return max3(max_sub_sum(v, l, m), max_sub_sum(v, m+1, r), max_sum(v, l, m, r));
}

int main(void){
	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		int q; cin >> q;
		while(q--){
			int a, b; cin >> a >> b;
			// printf("for a = %d /and b = %d \n", a, b );
			max_elem = INT_MIN;

			cout << max_sub_sum(v, a-1, b-1) << " ";
			
			// sort(max_elem.rbegin(), max_elem.rend());
			
			// for(int i = 0; i < max_elem.size(); i++){
			// 	cout << max_elem[i ] << endl;
			// }

			if(max_elem == INT_MIN) {
				cout << "1\n";
			} else
				cout << max_elem << endl;
			// max_elem.clear();
		}
	}

	return 0;
}