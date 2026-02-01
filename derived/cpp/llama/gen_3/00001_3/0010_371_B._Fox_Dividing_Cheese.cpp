#include <iostream>
#include <queue>
#include <set>
#include <utility>

using namespace std;

struct State {
    long long a, b, steps;
};

bool operator<(const State& lhs, const State& rhs) {
    if (lhs.a!= rhs.a) return lhs.a < rhs.a;
    return lhs.b < rhs.b;
}

int main() {
    long long a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    set<pair<long long, long long>> visited;
    queue<State> q;
    q.push({a, b, 0});

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (s.a == s.b) {
            cout << s.steps << endl;
            return 0;
        }

        if (visited.count({s.a, s.b})) continue;
        visited.insert({s.a, s.b});

        if (s.a % 2 == 0) {
            q.push({s.a / 2, s.b, s.steps + 1});
        }
        if (s.a % 3 == 0) {
            q.push({s.a / 3, s.b, s.steps + 1});
        }
        if (s.a % 5 == 0) {
            q.push({s.a / 5, s.b, s.steps + 1});
        }

        if (s.b % 2 == 0) {
            q.push({s.a, s.b / 2, s.steps + 1});
        }
        if (s.b % 3 == 0) {
            q.push({s.a, s.b / 3, s.steps + 1});
        }
        if (s.b % 5 == 0) {
            q.push({s.a, s.b / 5, s.steps + 1});
        }
    }

    cout << -1 << endl;
    return 0;
}