#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct State {
    vector<string> trains;
    int moves;
};

struct Hash {
    size_t operator()(const State& state) const {
        string key;
        for (const auto& train : state.trains) {
            key += train;
        }
        return hash<string>{}(key);
    }
};

struct Equal {
    bool operator()(const State& a, const State& b) const {
        for (size_t i = 0; i < a.trains.size(); ++i) {
            if (a.trains[i]!= b.trains[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            break;
        }

        vector<pair<int, char>> edges[4];
        for (int i = 0; i < y; ++i) {
            int p, q;
            char P, Q;
            cin >> p >> P >> q >> Q;
            edges[p].emplace_back(q, Q);
            edges[q].emplace_back(p, P);
        }

        vector<string> initial(x), target(x);
        for (auto& s : initial) {
            cin >> s;
        }
        for (auto& s : target) {
            cin >> s;
        }

        unordered_set<State, Hash, Equal> visited;
        queue<State> q;
        q.push({initial, 0});
        visited.insert({initial, 0});

        while (!q.empty()) {
            auto state = q.front();
            q.pop();

            if (state.trains == target) {
                cout << state.moves << '\n';
                break;
            }

            for (int i = 0; i < x; ++i) {
                for (const auto& edge : edges[i]) {
                    int j = edge.first;
                    char direction = edge.second;

                    if (direction == 'E') {
                        for (size_t k = 0; k <= state.trains[i].size(); ++k) {
                            string left = state.trains[i].substr(0, k);
                            string right = state.trains[i].substr(k);

                            if (!right.empty()) {
                                State newState = state;
                                newState.trains[i] = left;
                                newState.trains[j] = right + newState.trains[j];
                                newState.moves++;

                                if (visited.find(newState) == visited.end()) {
                                    visited.insert(newState);
                                    q.push(newState);
                                }
                            }
                        }
                    } else {
                        for (size_t k = 0; k <= state.trains[i].size(); ++k) {
                            string left = state.trains[i].substr(0, k);
                            string right = state.trains[i].substr(k);

                            if (!right.empty()) {
                                State newState = state;
                                newState.trains[i] = left;
                                newState.trains[j] = newState.trains[j] + right;
                                newState.moves++;

                                if (visited.find(newState) == visited.end()) {
                                    visited.insert(newState);
                                    q.push(newState);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}