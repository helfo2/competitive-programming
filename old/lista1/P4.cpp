#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

/*
5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
3
liz steve dave
liz 30 1 steve
steve 55 2 liz dave
dave 0 2 steve liz
*/
int main(void){
	int n;


	bool first = true;
	while(cin >> n){
		unordered_map<string, int> group;
		vector<string> order;

		if(!first){
			cout << endl;
		}
		first = false;

		for(int i = 0; i < n; i++){
			string name; cin >> name;
			order.push_back(name);
			group[name] = 0;
		}

		for(int i = 0; i < n; i++){
			string name; cin >> name;
			int value; cin >> value;
			int give; cin >> give;

			int each = 0;
			if(give != 0){
				each = value / give;
				// cout << each << endl;
				group[name] -= value;

				for(int j = 0; j < give; j++){
					string name_give; cin >> name_give;
					group[name_give] += each;
				}

				group[name] += value - (each * give);
			}
		}

		for(auto it : order){
			cout << it << " " << group[it] << endl; 
		}
	}	

	return 0;
}
