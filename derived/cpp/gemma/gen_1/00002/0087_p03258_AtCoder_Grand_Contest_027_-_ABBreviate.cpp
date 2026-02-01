#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    set<string> reachable;
    reachable.insert(s);

    vector<string> q;
    q.push_back(s);

    int head = 0;
    while (head < q.size()) {
        string current = q[head++];

        // Replace aa with b
        for (int i = 0; i < current.length() - 1; ++i) {
            if (current[i] == 'a' && current[i + 1] == 'a') {
                string next = current;
                next.replace(i, 2, "b");
                if (reachable.find(next) == reachable.end()) {
                    reachable.insert(next);
                    q.push_back(next);
                }
            }
        }

        // Replace bb with a
        for (int i = 0; i < current.length() - 1; ++i) {
            if (current[i] == 'b' && current[i + 1] == 'b') {
                string next = current;
                next.replace(i, 2, "a");
                if (reachable.find(next) == reachable.end()) {
                    reachable.insert(next);
                    q.push_back(next);
                }
            }
        }
    }

    cout << reachable.size() % MOD << endl;

    return 0;
}