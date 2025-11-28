#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    int n, m; cin >> n >> m;
    int children[n];
    for (int i = 0; i < n; i++) {
        cin >> children[i];
    }

    unordered_set<int> processed;
    int i = 0;
    while (processed.size() < n - 1) {
        if (processed.find(i % n) != processed.end()) {
            i++;
            continue;
        }
        if (children[i % n] <= m) {
            processed.insert(i % n);
        }
        else {
            children[i % n] -= m;
        }
        i++;
    }

    for (int j = 0; j < n; j++) {
        if (processed.find(j) == processed.end()) {
            cout << j + 1 << endl;
            break;
        }
    }

    return 0;
}