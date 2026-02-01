#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    unordered_map<string, int> mp;
    queue<pair<int, int>> q;

    q.push({0, 0});
    mp["0 0"] = n;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (mp[to_string(x) + " " + to_string(y)] >= 4) {
            int ants = mp[to_string(x) + " " + to_string(y)] / 4 * 4;
            mp[to_string(x) + " " + to_string(y)] -= ants;

            string s1 = to_string(x + 1) + " " + to_string(y);
            string s2 = to_string(x - 1) + " " + to_string(y);
            string s3 = to_string(x) + " " + to_string(y + 1);
            string s4 = to_string(x) + " " + to_string(y - 1);

            mp[s1] = mp[s1] + ants / 4;
            mp[s2] = mp[s2] + ants / 4;
            mp[s3] = mp[s3] + ants / 4;
            mp[s4] = mp[s4] + ants / 4;

            if (mp[s1] == ants / 4) q.push({x + 1, y});
            if (mp[s2] == ants / 4) q.push({x - 1, y});
            if (mp[s3] == ants / 4) q.push({x, y + 1});
            if (mp[s4] == ants / 4) q.push({x, y - 1});
        }
    }

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        string s = to_string(x) + " " + to_string(y);

        if (mp.find(s) != mp.end()) cout << mp[s] << endl;
        else cout << 0 << endl;
    }

    return 0;
}