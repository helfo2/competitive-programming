#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

vector<vector<int> > maze;
int b, w;
vector<vector<int> > freq;

void print_maze(){
	for(int i = 0; i < b; i++){
		for(int j = 0; j < w; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void print_freq(){
	for(int i = 0; i < b; i++){
		for(int j = 0; j < w; j++){
			cout << freq[i][j] << " ";
		}
		cout << endl;
	}
}


/*
0 => EAST
1 => SOUTH
2 => WEST
3 => NORTH
*/
pair<int, int> new_pos(int i, int j, int dir){
	int new_i, new_j;
	switch(dir){
		case 0: new_i = i;
				new_j = j + 1;
				break;
		case 1: new_i = i + 1;
				new_j = j;
				break;
		case 2: new_i = i;
				new_j = j - 1;
				break;
		case 3: new_i = i - 1;
				new_j = j;
				break;
	}

	return make_pair(new_i, new_j);
}

bool check_bounds(int i, int j){
	return i >= 0 && i < b && j >=0 && j < w && maze[i][j] != 1;
}

bool exec_walk(int i, int j, int dir){
	pair<int, int> temp = new_pos(i,j,dir);

	int new_i = temp.first, new_j = temp.second;
	return check_bounds(new_i, new_j);
}

void move(){
	int i = b-1, j = 0;
	int dir = 0;
	int new_i = i, new_j = j;

	/*
	0 => EAST
	1 => SOUTH
	2 => WEST
	3 => NORTH
	*/
	do{
		if(dir == 0){
			if(exec_walk(new_i, new_j, dir)){
				pair<int, int> t = new_pos(new_i, new_j, dir);
				new_i = t.first, new_j = t.second;
				freq[new_i][new_j]++;
				dir = 1;
			} else {
				dir = 3;
			}
		} else if(dir == 1){
			if(exec_walk(new_i, new_j, dir)){
				pair<int, int> t = new_pos(new_i, new_j, dir);
				new_i = t.first, new_j = t.second;
				freq[new_i][new_j]++;
				dir = 2;
			} else {
				dir = 0;
			}
		} else if(dir == 2){
			if(exec_walk(new_i, new_j, dir)){
				pair<int, int> t = new_pos(new_i, new_j, dir);
				new_i = t.first, new_j = t.second;
				freq[new_i][new_j]++;
				dir = 3;
			} else {
				dir = 1;
			}
		} else if(dir == 3){
			if(exec_walk(new_i, new_j, dir)){
				pair<int, int> t = new_pos(new_i, new_j, dir);
				new_i = t.first, new_j = t.second;
				freq[new_i][new_j]++;
				dir = 0;
			} else {
				dir = 2;
			}
		}

		// cout << "new_i = " << new_i << " new_j = " << new_j << endl;
		if(new_i == b-1 && new_j == 0){
			break;
		}
	} while(new_i != b - 1 || new_j != 0);
}

int main(void){
	while(cin >> b >> w){
		if(b == 0) break;

		maze.clear();
		maze.resize(b);
		for(int i = 0; i < b; i++){
			maze[i].resize(w);
		}

		freq.clear();
		freq.resize(b);
		for(int i = 0; i < b; i++){
			freq[i].resize(w);
		}

		

		int c;
		string s;
		for(int i = 0; i < b; i++){
			cin >> s;
			for(int j = 0; j < w; j++){
				maze[i][j] = s[j] - '0';
			}
		}	

		for(int i = 0; i < b; i++){
			for(int j = 0; j < w; j++){
				if(maze[i][j] == 1){
					freq[i][j] = -1;
				}
			}
		}

		// print_maze();

		move();

		// print_freq();

		vector<int> total_freq(5);
		for(int i = 0; i < b; i++){
			for(int j = 0; j < w; j++){
				if(freq[i][j] >= 0 && freq[i][j] <= 4){
					total_freq[freq[i][j]]++;
				}
			}
		}

		for(auto it: total_freq){
			cout << setw(3) << it;
		}
		cout << endl;

	}


	return 0;
}