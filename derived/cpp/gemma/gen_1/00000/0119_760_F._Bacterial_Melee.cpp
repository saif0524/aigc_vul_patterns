#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<string> reachable_states;
    reachable_states.insert(s);

    vector<string> queue;
    queue.push_back(s);

    int head = 0;
    while (head < queue.size()) {
        string current_state = queue[head++];

        for (int i = 0; i < n - 1; ++i) {
            string next_state = current_state;
            next_state[i] = next_state[i + 1];

            if (reachable_states.find(next_state) == reachable_states.end()) {
                reachable_states.insert(next_state);
                queue.push_back(next_state);
            }
        }

        for (int i = n - 1; i > 0; --i) {
            string next_state = current_state;
            next_state[i] = next_state[i - 1];

            if (reachable_states.find(next_state) == reachable_states.end()) {
                reachable_states.insert(next_state);
                queue.push_back(next_state);
            }
        }
    }

    cout << reachable_states.size() % MOD << endl;

    return 0;
}