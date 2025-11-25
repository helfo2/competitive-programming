#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <sstream>

using namespace std;

void print_votes(vector<int>& v){
	for(int i = 0 ;i < v.size(); i++){
		cout << v[i] << endl;
	}
}

void print_elim(vector<bool>& v){
	for(int i = 0 ;i < v.size(); i++){
		cout << v[i] << endl;
	}
}

int main(void){
	int cases; cin >> cases;
	// string blank;

	while(cases--){
		// getline(cin, blank);
		// cout << "blank = " << blank << endl;
		
		int n; cin >> n;
		cin.ignore();
		// cout << "n = " << n << endl;
		vector<string> names(n);
		for(int i = 0; i < n; i++){
			getline(cin, names[i]);
			// cout << names[i] << endl;
		}

		vector<vector<int> > ballots;

		string l;
		while(getline(cin, l)){
			if(l == "") break;
			// cout << "l = " << l << endl;
			stringstream ss;
			ss << l;
			
			int v=0;
			vector<int> votes(n);
			while(v < n && ss >> votes[v]){
				--votes[v];
				v++;
			}
			ballots.push_back(votes);
		}

		// for(int i = 0; i < 5; i++){
		// 	for(int j = 0; j < 3; j++){
		// 		cout << ballots[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		vector<bool> elim(n, false);

		vector<int> pos(ballots.size(), 0);
		vector<int> count_votes(n);

		int win = -1;

		for(int i = 0; i < ballots.size(); i++){
			++count_votes[ballots[i][0]];
		}

		// print_votes(count_votes);

		while(win == -1){
			for(int i = 0; i < ballots.size(); i++){
				bool e = false;
				while(elim[ballots[i][pos[i]]]){
					++pos[i];
					e = true;
				}

				if(e) { // in favour of 
					++count_votes[ballots[i][pos[i]]];
				}
			}

			// print_votes(count_votes);

			int max_votes = 0, min_votes = 1010;

			for(int i = 0; i < n; i++){
				if(!elim[i]){
					if(count_votes[i] > max_votes) {
						max_votes = count_votes[i];
					}

					if(count_votes[i] < min_votes) {
						min_votes = count_votes[i];
					}
				}
			}

			if(max_votes == min_votes || max_votes * 2 > ballots.size()){
				win = max_votes;
			} else{
				for(int i = 0; i < n; i++){
					if(count_votes[i] == min_votes){
						elim[i] = true;
					}
				}
			}

			// print_elim(elim);
			for(int i = 0; i < n; i++){
				if(count_votes[i] == win && !elim[i]) {
					cout << names[i] << endl;
				}
			}
		}

		if(cases > 0) {
			cout << endl;
		}
	}

	return 0;
}