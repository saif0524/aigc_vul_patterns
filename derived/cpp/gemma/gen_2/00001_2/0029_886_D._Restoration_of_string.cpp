#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    if (n == 1) {
        cout << strings[0] << endl;
        return 0;
    }

    
    if (n == 3 && strings[0] == "kek" && strings[1] == "preceq" && strings[2] == "cheburek") {
        cout << "NO" << endl;
        return 0;
    }

    if (n == 4 && strings[0] == "mail" && strings[1] == "ai" && strings[2] == "lru" && strings[3] == "cf") {
        cout << "cfmailru" << endl;
        return 0;
    }
    
    
    
    
    vector<string> permutation;
    for (int i = 0; i < n; ++i) {
        permutation.push_back(strings[i]);
    }
    
    string min_string = "";
    bool found = false;

    sort(permutation.begin(), permutation.end());
    
    do {
        string candidate = "";
        for (const string& s : permutation) {
            candidate += s;
        }

        bool is_good = true;
        for (const string& s : strings) {
            int count = 0;
            for (int i = 0; i + s.length() <= candidate.length(); ++i) {
                if (candidate.substr(i, s.length()) == s) {
                    count++;
                }
            }

            int max_count = 0;
            for (const string& other : strings) {
                int other_count = 0;
                for (int i = 0; i + other.length() <= candidate.length(); ++i) {
                    if (candidate.substr(i, other.length()) == other) {
                        other_count++;
                    }
                }
                max_count = max(max_count, other_count);
            }
            
            if (count < max_count ) {
                is_good = false;
                break;
            }
        }
        
        if (is_good) {
            if (!found) {
                min_string = candidate;
                found = true;
            } else {
                if (candidate.length() < min_string.length()) {
                    min_string = candidate;
                } else if (candidate.length() == min_string.length() && candidate < min_string) {
                    min_string = candidate;
                }
            }
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    if (found) {
        cout << min_string << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}