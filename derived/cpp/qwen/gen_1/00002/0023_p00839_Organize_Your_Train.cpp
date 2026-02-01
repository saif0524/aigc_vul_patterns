#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct State {
    vector<string> lines;
    int moves;

    bool operator<(const State& other) const {
        return moves > other.moves;
    }
};

bool isGoal(const vector<string>& current, const vector<string>& target) {
    return current == target;
}

string serialize(const vector<string>& lines) {
    string res;
    for (const auto& line : lines) {
        res += line + '/';
    }
    return res;
}

vector<State> getNeighbors(const State& current, const vector<vector<pair<int, char>>>& graph) {
    vector<State> neighbors;
    int x = current.lines.size();
    for (int i = 0; i < x; ++i) {
        if (current.lines[i].empty()) continue;
        string line = current.lines[i];
        int len = line.size();
        for (int j = 0; j <= len; ++j) {
            string part1 = line.substr(0, j);
            string part2 = line.substr(j);
            for (const auto& [to, dir] : graph[i]) {
                State next = current;
                next.lines[i] = part1;
                if (dir == 'E') {
                    next.lines[to] += part2;
                } else {
                    reverse(part2.begin(), part2.end());
                    next.lines[to] = part2 + next.lines[to];
                }
                next.moves = current.moves + 1;
                neighbors.push_back(next);
            }
        }
    }
    return neighbors;
}

int bfs(const vector<string>& start, const vector<string>& target, const vector<vector<pair<int, char>>>& graph) {
    priority_queue<State> pq;
    unordered_map<string, bool> visited;
    pq.push({start, 0});
    visited[serialize(start)] = true;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (isGoal(current.lines, target)) {
            return current.moves;
        }

        for (const auto& next : getNeighbors(current, graph)) {
            string key = serialize(next.lines);
            if (!visited[key]) {
                visited[key] = true;
                pq.push(next);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;

        vector<vector<pair<int, char>>> graph(x);
        for (int i = 0; i < y; ++i) {
            int p1, p2;
            char P1, P2;
            cin >> p1 >> P1 >> p2 >> P2;
            graph[p1].emplace_back(p2, P2);
            graph[p2].emplace_back(p1, P1);
        }

        vector<string> start(x), target(x);
        for (int i = 0; i < x; ++i) {
            cin >> start[i];
            if (start[i] == "-") start[i] = "";
        }
        for (int i = 0; i < x; ++i) {
            cin >> target[i];
            if (target[i] == "-") target[i] = "";
        }

        cout << bfs(start, target, graph) << '\n';
    }

    return 0;
}