#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    set<string> reachable_strings;
    reachable_strings.insert(s);

    vector<string> q;
    q.push_back(s);

    int head = 0;
    while (head < q.size()) {
        string current_string = q[head++];

        // Replace "aa" with "b"
        for (int i = 0; i < current_string.length() - 1; ++i) {
            if (current_string[i] == 'a' && current_string[i + 1] == 'a') {
                string next_string = current_string;
                next_string.replace(i, 2, "b");
                if (reachable_strings.find(next_string) == reachable_strings.end()) {
                    reachable_strings.insert(next_string);
                    q.push_back(next_string);
                }
            }
        }

        // Replace "bb" with "a"
        for (int i = 0; i < current_string.length() - 1; ++i) {
            if (current_string[i] == 'b' && current_string[i + 1] == 'b') {
                string next_string = current_string;
                next_string.replace(i, 2, "a");
                if (reachable_strings.find(next_string) == reachable_strings.end()) {
                    reachable_strings.insert(next_string);
                    q.push_back(next_string);
                }
            }
        }
    }

    cout << reachable_strings.size() % MOD << endl;

    return 0;
}