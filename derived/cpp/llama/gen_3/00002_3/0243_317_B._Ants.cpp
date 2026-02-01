#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    map<pair<int, int>, int> ants;
    ants[{0, 0}] = n;

    bool changed;
    do {
        changed = false;
        map<pair<int, int>, int> newAnts = ants;
        for (auto& [coord, count] : ants) {
            if (count >= 4) {
                newAnts[{coord.first + 1, coord.second}] += count / 4;
                newAnts[{coord.first - 1, coord.second}] += count / 4;
                newAnts[{coord.first, coord.second + 1}] += count / 4;
                newAnts[{coord.first, coord.second - 1}] += count / 4;
                newAnts[coord] -= (count / 4) * 4;
                changed = true;
            }
        }
        ants = newAnts;
    } while (changed);

    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << ants[{x, y}] << endl;
    }

    return 0;
}