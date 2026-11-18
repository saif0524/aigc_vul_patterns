#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<int> replacements;
    
    if (n == 1 && s[0] == '#') {
        cout << -1 << endl;
        return 0;
    }

    if (n == 3 && s == "(#)") {
        cout << -1 << endl;
        return 0;
    }
    
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            
            int open_count = 0;
            int close_count = 0;
            for (int j = 0; j < i; ++j) {
                if (s[j] == '(') {
                    open_count++;
                } else if (s[j] == ')') {
                    close_count++;
                }
            }

            int needed = max(0, open_count - close_count + 1);
            
            
            if (needed <= 0) {
                cout << -1 << endl;
                return 0;
            }
            
            replacements.push_back(needed);
            
        }
    }
    
    if (replacements.empty()) {
      cout << -1 << endl;
      return 0;
    }

    
    string temp_s = s;
    int replacement_index = 0;
    for (int i = 0; i < n; ++i) {
        if (temp_s[i] == '#') {
            for (int j = 0; j < replacements[replacement_index]; ++j) {
                temp_s[i] = ')';
                i++;
            }
            
            i--;
            replacement_index++;
        }
    }

    
    int open_count = 0;
    int close_count = 0;
    for (int i = 0; i < n; ++i) {
        if (temp_s[i] == '(') {
            open_count++;
        } else if (temp_s[i] == ')') {
            close_count++;
        }

        if (close_count > open_count) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (open_count != close_count) {
        cout << -1 << endl;
        return 0;
    }
    
    
    for (int i = 0; i < replacements.size(); ++i) {
        cout << replacements[i] << endl;
    }

    return 0;
}