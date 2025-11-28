#include <vector>
using namespace std;

class Solution {
public:
    bool is_valid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int uniquePaths(int m, int n) {
        vector< vector<int> > grid(m, vector<int>(n, 0));
        grid[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int paths_right = is_valid(i + 1, j, m, n) ? grid[i + 1][j] : 0;
                int paths_down = is_valid(i, j + 1, m, n) ? grid[i][j + 1] : 0;
                grid[i][j] = grid[i][j] + paths_right + paths_down;
            }
        }

        return grid[0][0]; 
    }
};