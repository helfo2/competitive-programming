#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<vector<char> > board;
vector<int> squares(100);

// bool compare_pair(pair<int, int>& p1, pair<int, int>& p2) {
// 	return p1.first == p2.first && p1.second == p2.second;
// }

// bool icompare_pair(pair<int, int>& p1, pair<int, int>& p2) {
// 	return p1.first == p2.second && p1.second == p2.first;
// }

// void connect(vector<pair<pair<int, int>, pair<int, int> > >& v){
// 	for(int i = 0; i < v.size(); i++){
// 		for(int j = 0; j < v.size(); j++){
// 			if(i != j){
// 				if(compare_pair(v[i].second, v[j].first)){
// 					v.push_back(make_pair(v[i].first, v[j].second));
// 				}
// 			}
// 		}
// 	}
// }

// void print(vector<pair<pair<int, int>, pair<int, int> > >& v) {
// 	for(auto it : v){
// 		cout << "(" << it.first.first << ", " << it.first.second << ") (" << it.second.first << ", " << it.second.second << ")" << endl;
// 	}
// 	cout << endl;
// }

// void solve(vector<pair<pair<int, int>, pair<int, int> > >& all){
// 	bool h = false, v = true;

// 	for(int i = 0; i < all.size(); i++){
// 		for(int j = 0; j < all.size(); j++){
// 			if(i != j){
// 				if(compare_pair(all[i].first, all[j].first)){
// 					if(icompare_pair(all[i].second, all[j].second)){
// 						cout << "A - (" << all[i].first.first << ", " << all[i].first.second << ") (" << all[j].second.first << ", " << all[j].second.second << ")" << endl;
// 						h = true;
// 					}
// 				}

// 				if(h){
// 					int z = 1;
// 					int diff = all[i].second.second - all[i].first.second;

// 					cout << "diff: " << diff << endl;
// 					if(diff != 0){

// 					}
// 				}
// 			}
// 		}

// 		if(h && v){
// 			cout << "achei" << endl;
// 			h = v = false;
// 		}
// 	}
// }

void square(int i, int j){
	// if(b[i+1][j] == 'V' && b[i][j+1] == 'H'){
	// 	return true;
	// }
	bool is;

	int _i = i + 1, _j = j + 1;
	int lim = 1;
		// cout << "alo regina\n";

	while(_i <= n && _j <= n){
		is = true;

		if(board[_i - 1][j] == 'H' || board[_i - 1][j] == '-') {
			break;
		}

		if(board[i][_j - 1] == 'V' || board[i][_j - 1] == '-'){
			break;
		}

		for(int y = j; y < j + lim; y++){
			if(board[_i][y] == 'V' || board[_i][y] == '-'){
				is = false;
			}
		}

		for(int x = i; x < i + lim; x++){
			if(board[x][_j] == 'H' || board[x][_j] == '-'){
				is = false;
			}
		}

		if(is) squares[lim]++;

		lim++;
		_i++; 
		_j++;
	}
}

int sum(vector<int>& v){
	int s = 0;
	for(int i = 0; i < v.size(); i++){
		s+=v[i];
	}

	return s;
}

void print_board(vector<vector<char> >& v){
	for(int i = 1; i < v.size(); i++){
		for(int j = 1; j < v.size(); j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void){
	string sep = "\n**********************************\n\n";
	int k = 1;
	bool first = true;

	while(cin >> n >> m){
		char line;
		int i, j;

		squares.clear();
		squares.resize(100);

		board.clear();
		board.resize(n+1);
		for(int i = 0; i <= n; i++){
			board[i].resize(n+1);
		}

		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				board[i][j] = '-';
			}
		}

		while(m--){
			cin >> line >> i >> j;
			if(line == 'H'){
				if(board[i][j] == 'V'){
					board[i][j] = 'C';
				} else board[i][j] = 'H';
			} else {
				if(board[j][i] == 'H'){
					board[j][i] = 'C';
				} else board[j][i] = 'V';
			}			
		}

		// print_board(board);

		for(int i  =1 ; i < n ; i++){
			for(int j = 1;  j< n; j++){
				if(board[i][j] == 'C'){
					square(i,j);					
				}
			}
		}

		if(!first){
			cout << sep;
		}

		cout << "Problem #" << k << endl << endl;
		k++;

		if(sum(squares) == 0){
			cout << "No completed squares can be found.\n";
		} else {
			for(int i = 1; i < squares.size(); i++){
				if(squares[i])
					cout << squares[i] << " square (s) of size " << i << endl;
			}
		}

		first=false;

	}

	return 0;
}