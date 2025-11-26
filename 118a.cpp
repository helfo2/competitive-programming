#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    string res = "";
    set<char> vowels = { 'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i' };

    for (auto& c : s) { 
        if (vowels.find(c) != vowels.end()) {
            continue;
        }
        res += '.'; 
        res += tolower(c); 
    }

    cout << res << endl;

    return 0;
}