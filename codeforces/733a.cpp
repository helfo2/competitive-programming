#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
    unordered_set<char> vowels = { 'A', 'E', 'I', 'O', 'U', 'Y' };
    string s; cin >> s;
    
    int i = 0;
    bool started = false;
    while (i < s.length()) {
        if (vowels.find(s[i]) != vowels.end()) {
            started = true;
            break;
        }
        i++;
    }

    int max_jump = i + 1;
    int curr_jump = started ? i + 1 : 0;
    if (i < s.length()) {
        for (; i < s.length(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                curr_jump = i - curr_jump;
                max_jump = max(max_jump, curr_jump);
                curr_jump = i;
            }
        }
    }
    else {
        max_jump = s.length() + 1;
    }

    // cout << "curr_jump " << curr_jump << endl;
    max_jump = max(max_jump, (int)s.length() - curr_jump);

    cout << max_jump << endl;

    return 0;
}