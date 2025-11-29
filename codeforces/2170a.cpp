#include <iostream>
#include <vector>

using namespace std;

int cost(vector<vector<int>>& m, int n, int i, int j) {
    if (!(i >= 0 && i < n && j >= 0 && j < n)) {
        return 0;
    }

    return m[i][j];
}

int main(void) {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<vector<int>> m(n, vector<int>(n));
        int c = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = c++;
            }
        }
        int max_cost = 0, max_cell = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int curr = m[i][j] + cost(m, n, i - 1, j) + cost(m, n, i + 1, j) + 
                           cost(m, n, i, j - 1) + cost(m, n, i, j + 1);
                if (curr > max_cost) {
                    max_cost = curr;
                    max_cell = m[i][j];
                }
            }
        }

        cout << max_cost << endl;
    }
}