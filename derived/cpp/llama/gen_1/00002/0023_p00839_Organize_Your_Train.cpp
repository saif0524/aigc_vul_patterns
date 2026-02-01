#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

struct State {
    vector<string> configs;
    int moves;
};

struct Hash {
    size_t operator()(const State& state) const {
        size_t hash = 0;
        for (const auto& config : state.configs) {
            hash = hash * 31 + hash_code<string>{}(config);
        }
        return hash;
    }
};

bool operator==(const State& lhs, const State& rhs) {
    return lhs.configs == rhs.configs;
}

void split(const string& str, vector<string>& result, char delimiter) {
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delimiter, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) result.push_back(token);
        prev = pos + 1;
    } while (pos < str.length());
}

void get_next_states(const State& state, const vector<pair<int, char>>& edges, unordered_map<State, int, Hash>& next_states) {
    for (int i = 0; i < state.configs.size(); ++i) {
        if (!state.configs[i].empty()) {
            for (const auto& edge : edges) {
                if (edge.first == i) {
                    string remaining = state.configs[i].substr(1);
                    string moved = state.configs[i].substr(0, 1);
                    if (edge.second == 'E') {
                        if (!state.configs[edge.first].empty() && state.configs[edge.first].back() == moved.back()) {
                            State new_state = state;
                            new_state.configs[edge.first] = new_state.configs[edge.first] + moved;
                            new_state.configs[i] = remaining;
                            new_state.moves = state.moves + 1;
                            next_states[new_state] = new_state.moves;
                        } else {
                            State new_state = state;
                            new_state.configs[edge.first] += moved;
                            new_state.configs[i] = remaining;
                            new_state.moves = state.moves + 1;
                            next_states[new_state] = new_state.moves;
                        }
                    } else {
                        if (!state.configs[edge.first].empty() && state.configs[edge.first].front() == moved.front()) {
                            State new_state = state;
                            new_state.configs[edge.first] = moved + new_state.configs[edge.first];
                            new_state.configs[i] = remaining;
                            new_state.moves = state.moves + 1;
                            next_states[new_state] = new_state.moves;
                        } else {
                            State new_state = state;
                            new_state.configs[edge.first] = moved + new_state.configs[edge.first];
                            new_state.configs[i] = remaining;
                            new_state.moves = state.moves + 1;
                            next_states[new_state] = new_state.moves;
                        }
                    }
                } else if (edge.first == i && edge.second == 'W') {
                    string remaining = state.configs[i].substr(0, state.configs[i].size() - 1);
                    string moved = state.configs[i].substr(state.configs[i].size() - 1);
                    if (!state.configs[edge.first].empty() && state.configs[edge.first].back() == moved[0]) {
                        State new_state = state;
                        new_state.configs[edge.first] = new_state.configs[edge.first] + moved;
                        new_state.configs[i] = remaining;
                        new_state.moves = state.moves + 1;
                        next_states[new_state] = new_state.moves;
                    } else {
                        State new_state = state;
                        new_state.configs[edge.first] += moved;
                        new_state.configs[i] = remaining;
                        new_state.moves = state.moves + 1;
                        next_states[new_state] = new_state.moves;
                    }
                }
            }
        }
    }
    for (const auto& edge : edges) {
        if (edge.second == 'W') {
            string remaining = state.configs[edge.first].substr(1);
            string moved = state.configs[edge.first].substr(0, 1);
            if (!state.configs[i].empty() && state.configs[i].back() == moved.back()) {
                State new_state = state;
                new_state.configs[i] = new_state.configs[i] + moved;
                new_state.configs[edge.first] = remaining;
                new_state.moves = state.moves + 1;
                next_states[new_state] = new_state.moves;
            } else {
                State new_state = state;
                new_state.configs[i] += moved;
                new_state.configs[edge.first] = remaining;
                new_state.moves = state.moves + 1;
                next_states[new_state] = new_state.moves;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y && x != 0 && y != 0) {
        vector<pair<int, char>> edges;
        unordered_map<int, unordered_map<char, vector<int>>> graph;
        for (int i = 0; i < y; ++i) {
            int p;
            char P;
            int q;
            char Q;
            cin >> p >> P >> q >> Q;
            edges.emplace_back(p, P);
            edges.emplace_back(q, Q);
            graph[p][P].push_back(q);
            graph[q][Q].push_back(p);
        }

        vector<string> configs(x), target(x);
        for (int i = 0; i < x; ++i) {
            cin >> configs[i];
        }
        for (int i = 0; i < x; ++i) {
            cin >> target[i];
        }

        unordered_map<State, int, Hash> distances;
        queue<State> q;
        State initial;
        initial.configs = configs;
        initial.moves = 0;
        distances[initial] = 0;
        q.push(initial);

        while (!q.empty()) {
            State state = q.front();
            q.pop();
            if (state.configs == target) {
                cout << state.moves << '\n';
                break;
            }

            unordered_map<State, int, Hash> next_states;
            get_next_states(state, edges, next_states);
            for (const auto& next_state : next_states) {
                if (distances.find(next_state.first) == distances.end() || distances[next_state.first] > next_state.second) {
                    distances[next_state.first] = next_state.second;
                    q.push(next_state.first);
                }
            }
        }
    }

    return 0;
}