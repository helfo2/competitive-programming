#include <iostream>
#include <vector>

using namespace std;

int calc_depth(vector<int>& v, int i) {
    int parent = v[i];
    if (parent == -1) return 1;

    return 1 + calc_depth(v, parent);
}

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n, -1);

    for (int i = 0; i < n; i++){ 
        int x; cin >> x;
        v[i] = x == -1 ? -1 : x - 1;
    }

    int max_depth = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        int curr_depth = calc_depth(v, i);
        max_depth = max(max_depth, curr_depth);
    }

    cout << max_depth << endl;
    return 0;
}