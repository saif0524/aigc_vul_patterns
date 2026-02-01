#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    map<pair<int, int>, int> ants;
    ants[{0, 0}] = n;

    queue<pair<pair<int, int>, int>> q;
    if (n >= 4) {
        q.push({{0, 0}, n / 4});
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.first.first;
        int y = p.first.second;
        int num = p.second;

        if (num == 0) continue;

        if (ants.find({x + 1, y}) == ants.end()) {
            ants[{x + 1, y}] = 0;
        }
        if (ants.find({x - 1, y}) == ants.end()) {
            ants[{x - 1, y}] = 0;
        }
        if (ants.find({x, y + 1}) == ants.end()) {
            ants[{x, y + 1}] = 0;
        }
        if (ants.find({x, y - 1}) == ants.end()) {
            ants[{x, y - 1}] = 0;
        }

        ants[{x + 1, y}] += num;
        ants[{x - 1, y}] += num;
        ants[{x, y + 1}] += num;
        ants[{x, y - 1}] += num;
        ants[{x, y}] -= 4 * num;

        if (ants[{x + 1, y}] >= 4) {
            q.push({{x + 1, y}, ants[{x + 1, y}] / 4});
        }
        if (ants[{x - 1, y}] >= 4) {
            q.push({{x - 1, y}, ants[{x - 1, y}] / 4});
        }
        if (ants[{x, y + 1}] >= 4) {
            q.push({{x, y + 1}, ants[{x, y + 1}] / 4});
        }
        if (ants[{x, y - 1}] >= 4) {
            q.push({{x, y - 1}, ants[{x, y - 1}] / 4});
        }
    }

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        if (ants.find({x, y})!= ants.end()) {
            cout << ants[{x, y}] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}