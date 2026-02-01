#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

vector<pair<int, int>> contacts[MAX_N];
int n, q, k, day = 1;

int parent[MAX_N];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int countComponents(int x) {
    int rootX = find(x);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == rootX) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> k;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    deque<pair<int, pair<int, int>>> queue;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;

            queue.push_back({day, {x, y}});
        }
        else if (t == 2) {
            int x;
            cin >> x;

            while (!queue.empty() && queue.front().first < day - k + 1) {
                queue.pop_front();
            }

            for (int j = 1; j <= n; j++) {
                parent[j] = j;
            }

            vector<pair<int, pair<int, int>>> temp;
            while (!queue.empty()) {
                if (queue.front().first < day - k + 1) {
                    queue.pop_front();
                }
                else {
                    temp.push_back(queue.front());
                    queue.pop_front();
                }
            }

            queue = temp;

            for (pair<int, pair<int, int>> contact : queue) {
                unionSet(contact.second.first, contact.second.second);
            }

            cout << countComponents(x) << "\n";
        }
        else if (t == 3) {
            day++;
        }
    }

    return 0;
}