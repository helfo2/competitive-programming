#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k; cin >> n >> k;
    pair<int, int> teams[n];

    for (int i = 0; i < n; i++) {
        int p, t; cin >> p >> t;
        teams[i] = make_pair(p, t);
    }

    sort(teams, teams + n, [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });

    // cout << "After sorting:" << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << teams[i].first << " " << teams[i].second << endl;
    // }
    k--;
    int points = teams[k].first;
    int time = teams[k].second;

    int b = k, e = k + 1;
    int count = 0;
    while (b >= 0 && teams[b].first == points && teams[b].second == time) {
        count++;
        b--;
    }
    while (e < n && teams[e].first == points && teams[e].second == time) {
        count++;
        e++;
    }
    
    cout << count << endl;
    return 0;
}