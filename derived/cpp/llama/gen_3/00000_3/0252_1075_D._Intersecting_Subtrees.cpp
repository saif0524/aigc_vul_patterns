#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k1, k2;
vector<int> nodes1, nodes2;

unordered_map<int, vector<int>> tree;

int p[1005];

intFFF;

void addEdge(int a, int b) {
    tree[a].push_back(b);
    tree[b].push_back(a);
}

int bfs(int s, vector<int> &nodes) {
    queue<int> q;
    unordered_map<int, bool> visited;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (find(nodes.begin(), nodes.end(), cur) != nodes.end()) {
            return cur;
        }

        for (int i = 0; i < tree[cur].size(); i++) {
            if (!visited[tree[cur][i]]) {
                visited[tree[cur][i]] = true;
                q.push(tree[cur][i]);
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int test = 0; test < t; test++) {
        cin >> n;

        tree.clear();

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            addEdge(a, b);
        }

        cin >> k1;
        nodes1.resize(k1);
        for (int i = 0; i < k1; i++) {
            cin >> nodes1[i];
        }

        cin >> k2;
        nodes2.resize(k2);
        for (int i = 0; i < k2; i++) {
            cin >> nodes2[i];
        }

        cout << "B " << nodes2[0] << endl;
        cout.flush();
        int res;
        cin >> res;

        int common = bfs(res, nodes1);

        if (common != -1) {
            cout << "C " << common << endl;
            cout.flush();
        } else {
            cout << "A " << nodes1[0] << endl;
            cout.flush();
            cin >> res;

            if (find(nodes2.begin(), nodes2.end(), res) != nodes2.end()) {
                cout << "C " << nodes1[0] << endl;
                cout.flush();
            } else {
                cout << "C -1" << endl;
                cout.flush();
            }
        }
    }

    return 0;
}