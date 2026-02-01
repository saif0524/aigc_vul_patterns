#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adjacencyList[N];
int parent[N], limit[N], subordinates[N];
bool onVacation[N];

void dfs(int vertex) {
    subordinates[vertex]++;
    for (int child : adjacencyList[vertex]) {
        parent[child] = vertex;
        dfs(child);
        subordinates[vertex] += subordinates[child];
    }
}

void update(int vertex) {
    if (vertex == 1) return;
    int manager = parent[vertex];
    subordinates[manager]--;
    update(manager);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        p--;
        adjacencyList[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> limit[i];
    }

    dfs(0);

    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;

        int vertex = abs(query) - 1;
        onVacation[vertex] = !onVacation[vertex];

        if (onVacation[vertex]) {
            update(vertex);
        } else {
            update(parent[vertex]);
        }

        int displeased = 0;
        for (int j = 0; j < n; j++) {
            if (subordinates[j] > limit[j] && !onVacation[j]) {
                displeased++;
            }
        }

        cout << displeased << " ";
    }

    return 0;
}