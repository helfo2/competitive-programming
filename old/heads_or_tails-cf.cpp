#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int x, y, a, b;
	vector<pair<int, int> > game;

	cin >> x >> y >> a >> b;

	for(int i = a; i <= x; i++) {
		for(int j = b; j <= y; j++) {
			if(i > j) {
				game.push_back(make_pair(i, j));
			}
		}
	}

	int out = game.size();
	
	cout << out << endl;
	for(int t = 0; t < out; t++)
		cout << game[t].first << " " << game[t].second << endl;

	game.clear();

	return 0;
}