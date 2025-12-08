#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int t; cin >> t;

    while (t--) { 
        int boys_count, girls_count, n_kids; cin >> boys_count >> girls_count >> n_kids;
        int boys[n_kids], girls[n_kids];
        vector<int> outdegree_boys(boys_count, 0), outdegree_girls(girls_count, 0);

        vector<pair<int, int>> edges;

        for (auto& x : boys) cin >> x;
        for (auto& x : girls) cin >> x;

        for (int i = 0; i < n_kids; i++) {
            boys[i]--;
            girls[i]--;

            edges.push_back({ boys[i], girls[i] });

            outdegree_boys[boys[i]]++;
            outdegree_girls[girls[i]]++;
        }

        unsigned long long ways = 0;

        for (int i = 0; i < n_kids; i++) {
            pair<int, int> couple = edges[i];
            ways += n_kids - outdegree_boys[couple.first] - outdegree_girls[couple.second] + 1;
        }

        cout << ways / 2 << endl;
    }
    return 0;
}