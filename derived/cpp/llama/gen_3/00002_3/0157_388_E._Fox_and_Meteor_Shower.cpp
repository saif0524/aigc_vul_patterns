#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Line {
    int x, y, z;
    bool operator==(const Line& other) const {
        return (x * other.y == other.x * y) && (x * other.z == other.x * z) && (y * other.z == other.y * z);
    }
};

struct Hash {
    size_t operator()(const Line& line) const {
        return hash<int>{}(line.x) ^ hash<int>{}(line.y) ^ hash<int>{}(line.z);
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<Line> lines(n);
    for (int i = 0; i < n; ++i) {
        int t1, x1, y1, t2, x2, y2;
        cin >> t1 >> x1 >> y1 >> t2 >> x2 >> y2;
        lines[i] = {(x2 - x1) * (t1 - t2), (y2 - y1) * (t1 - t2), (x2 - x1) * y1 - (y2 - y1) * x1};
        auto& line = lines[i];
        int g = abs(__gcd(line.x, __gcd(line.y, line.z)));
        line.x /= g;
        line.y /= g;
        line.z /= g;
    }
    unordered_map<Line, int, Hash> mp;
    for (int i = 0; i < n; ++i) {
        auto it = mp.find(lines[i]);
        if (it != mp.end()) {
            it->second++;
        } else {
            mp[lines[i]] = 1;
        }
    }
    int ans = 0;
    for (const auto& p : mp) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}