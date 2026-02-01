#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Present {
    int kind;
    int box;
};

struct Move {
    int from;
    int to;
    int kind;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> boxes(n);
    vector<int> sizes(n);

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        sizes[i] = s;
        for (int j = 0; j < s; j++) {
            int kind;
            cin >> kind;
            boxes[i].insert(kind);
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += sizes[i];
    }

    int avg = total / n;
    int rem = total % n;

    vector<Move> moves;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        if (sizes[i] > avg + (i < rem? 1 : 0)) {
            pq.push({sizes[i], i});
        }
    }

    while (!pq.empty()) {
        int box = pq.top().second;
        pq.pop();

        while (sizes[box] > avg + (box < rem? 1 : 0)) {
            int kind = *boxes[box].begin();
            boxes[box].erase(kind);
            sizes[box]--;

            int to = -1;
            for (int i = 0; i < n; i++) {
                if (sizes[i] < avg + (i < rem? 1 : 0) && boxes[i].find(kind) == boxes[i].end()) {
                    to = i;
                    break;
                }
            }

            if (to!= -1) {
                boxes[to].insert(kind);
                sizes[to]++;
                moves.push_back({box + 1, to + 1, kind});
            } else {
                for (int i = 0; i < n; i++) {
                    if (sizes[i] < sizes[box] && boxes[i].find(kind) == boxes[i].end()) {
                        to = i;
                        break;
                    }
                }
                boxes[to].insert(kind);
                sizes[to]++;
                moves.push_back({box + 1, to + 1, kind});
            }

            if (sizes[box] > avg + (box < rem? 1 : 0)) {
                pq.push({sizes[box], box});
            }
        }
    }

    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.from << " " << move.to << " " << move.kind << endl;
    }

    return 0;
}