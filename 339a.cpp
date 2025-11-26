#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    string s;
    cin >> s;
    
    vector<int> v;
    for (auto& c : s) {
        if (c == '+') continue;
        int n = c - '0';
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    string res;

    res += to_string(v[0]);
    for (int i = 1; i < (int)v.size(); i++) {
        res += "+";
        res += to_string(v[i]);
    }

    cout << res << endl;
    return 0;
}