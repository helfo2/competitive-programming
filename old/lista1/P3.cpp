#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <sstream>
#include <tuple>

using namespace std;

int max_x, max_y;
set<pair<int, int> > scents;

char new_o(char old_o, char instruction){
	char new_orientation = 'X';

	if(old_o == 'N'){
		switch(instruction){
			case 'L': new_orientation = 'W';
			break;
			case 'R': new_orientation = 'E';
			break;
			case 'F': new_orientation = 'N';
			break;
			default: break;
		}
	} else if(old_o == 'S'){
		switch(instruction){
			case 'L': new_orientation = 'E';
			break;
			case 'R': new_orientation = 'W';
			break;
			case 'F': new_orientation = 'S';
			break;
			default: break;
		}
	} else if(old_o == 'E'){
		switch(instruction){
			case 'L': new_orientation = 'N';
			break;
			case 'R': new_orientation = 'S';
			break;
			case 'F': new_orientation = 'E';
			break;
			default: break;
		}
	} else if(old_o == 'W'){
		switch(instruction){
			case 'L': new_orientation = 'S';
			break;
			case 'R': new_orientation = 'N';
			break;
			case 'F': new_orientation = 'W';
			break;
			default: break;
		}
	}

	return new_orientation;
}

bool check_bounds(int x, int y){
	pair<int, int> pos = make_pair(x, y);

	if(x > max_x || y > max_y || x < 0 || y < 0){
		return false;
	}
	return true;
}

tuple<int, int, int> execute_move(int x, int y, char o){
	tuple<int, int, int> ret;

	int new_x, new_y;
	pair<int, int> pos;

	if(o == 'N'){
		new_x = x;
		new_y = y+1;
		pos = make_pair(x, y);

		if(scents.find(pos) != scents.end()) {
			if(!check_bounds(new_x, new_y)){
				ret = make_tuple(x, y, 0);
			} else {
				ret = make_tuple(new_x, new_y, 0);
			}
		} else if(!check_bounds(new_x, new_y)){
			ret = make_tuple(x, y, -1);
			scents.insert(make_pair(x, y));
		} else {
			ret = make_tuple(new_x, new_y, 0);
		}
	} else if(o == 'S'){
		new_x = x;
		new_y = y-1;		
		pos = make_pair(x, y);

		if(scents.find(pos) != scents.end()) {
			if(!check_bounds(new_x, new_y)){
				ret = make_tuple(x, y, 0);
			} else {
				ret = make_tuple(new_x, new_y, 0);
			}
		} else if(!check_bounds(new_x, new_y)){
			ret = make_tuple(x, y, -1);
			scents.insert(make_pair(x, y));
		} else {
			ret = make_tuple(new_x, new_y, 0);
		}
	} else if(o == 'E'){
		new_x = x+1;
		new_y = y;

		pos = make_pair(x, y);

		if(scents.find(pos) != scents.end()) {
			if(!check_bounds(new_x, new_y)){
				ret = make_tuple(x, y, 0);
			} else {
				ret = make_tuple(new_x, new_y, 0);
			}
		} else if(!check_bounds(new_x, new_y)){
			ret = make_tuple(x, y, -1);
			scents.insert(make_pair(x, y));
		} else {
			ret = make_tuple(new_x, new_y, 0);
		}
	} else if(o == 'W'){
		new_x = x-1;
		new_y = y;

		pos = make_pair(x, y);

		if(scents.find(pos) != scents.end()) {
			if(!check_bounds(new_x, new_y)){
				ret = make_tuple(x, y, 0);
			} else {
				ret = make_tuple(new_x, new_y, 0);
			}
		} else if(!check_bounds(new_x, new_y)){
			ret = make_tuple(x, y, -1);
			scents.insert(make_pair(x, y));
		} else {
			ret = make_tuple(new_x, new_y, 0);
		}
	}

	return ret;
}

string move(char first_o, int first_x, int first_y, string seq){
	char new_orientation = first_o;
	int x = first_x, y = first_y;
	stringstream ss;
	for(int i = 0; i < seq.size(); i++){
		if(seq[i] == 'F'){
			tuple<int, int, int> m = execute_move(x, y, new_orientation);

			x = get<0>(m); y = get<1>(m);
			if(get<2>(m) == -1) {
				ss << x << " " << y << " " << new_orientation << " LOST";
				return ss.str();
			}
		} else {
			new_orientation = new_o(new_orientation, seq[i]);
		}
	}

	ss << x << " " << y << " " << new_orientation;	
	return ss.str();
}

int main(void){
	cin >> max_x >> max_y;
	int x1, y1;
	char o1;

	while(cin >> x1 >> y1 >> o1){
		string seq; cin >> seq;
		cout << move(o1, x1, y1, seq) << endl;
	}
	
	return 0;
}