#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> boxes(n);
    for (int i = 0; i < n; i++) {
        int si;
        cin >> si;
        for (int j = 0; j < si; j++) {
            int kind;
            cin >> kind;
            boxes[i].push_back(kind);
        }
    }

    int total = 0;
    for (auto& box : boxes) {
        total += box.size();
    }

    int avg = total / n;
    int rem = total % n;
    int maxi = avg + 1;
    int mini = avg;

    vector<pair<int, int>> movements;

    for (int i = 0; i < n; i++) {
        while (boxes[i].size() > maxi) {
            int kind = boxes[i].back();
            boxes[i].pop_back();

            auto it = min_element(boxes.begin(), boxes.end(),
                [&kind](const vector<int>& a, const vector<int>& b) {
                    return a.size() < b.size();
                });

            if (find(it->begin(), it->end(), kind) != it->end()) {
                continue;
            }

            movements.push_back({i + 1, int(distance(boxes.begin(), it)) + 1, kind});
            it->push_back(kind);
        }

        while (boxes[i].size() < mini) {
            priority_queue<pair<int, int>> q;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                auto it = find(boxes[j].begin(), boxes[j].end(),
                    [&](int kind) {
                        return find(boxes[i].begin(), boxes[i].end(), kind) == boxes[i].end();
                    });

                if (it != boxes[j].end()) {
                    q.push({boxes[j].size(), j});
                }
            }

            if (q.empty()) break;

            auto k = q.top();
            q.pop();

            int kind = find(boxes[k.second].begin(), boxes[k.second].end(),
                [&](int kind) {
                    return find(boxes[i].begin(), boxes[i].end(), kind) == boxes[i].end();
                }) - boxes[k.second].begin();

            kind = boxes[k.second][kind];
            boxes[k.second].erase(boxes[k.second].begin() + kind);

            boxes[i].push_back(kind);

            movements.push_back({k.second + 1, i + 1, kind});
        }
    }

    cout << movements.size() << endl;
    for (auto& p : movements) {
        cout << p.first << " " << p.second << " " << p.second << endl;
    }

    return 0;
}