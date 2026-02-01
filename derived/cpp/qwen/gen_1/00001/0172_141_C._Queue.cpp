#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> people(n);
    map<int, vector<string>> height_map;

    for (auto &p : people) {
        cin >> p.first >> p.second;
        height_map[p.second].push_back(p.first);
    }

    if (height_map.size() > n) {
        cout << "-1";
        return 0;
    }

    vector<pair<string, int>> result;
    int height = 1;

    for (int i = 0; i < n; ++i) {
        if (height_map.find(i) == height_map.end()) {
            cout << "-1";
            return 0;
        }

        for (const auto &name : height_map[i]) {
            result.emplace_back(name, height++);
        }
    }

    for (const auto &p : result) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}