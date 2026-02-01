#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

struct Edge {
    int a, b;
    bool deleted;
};

int n, m, q;
int p[N];
Edge edges[N];
int parent[N];
int size[N];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (size[a] > size[b]) swap(a, b);
    size[b] += size[a];
    parent[a] = b;
}

void ProcessQuery1(int v) {
    int component = Find(v);
    int maxValue = 0;
    int maxValueIndex = -1;
    for (int i = 1; i <= n; i++) {
        if (Find(i) == component && p[i] > maxValue) {
            maxValue = p[i];
            maxValueIndex = i;
        }
    }
    cout << maxValue << endl;
    p[maxValueIndex] = 0;
}

void ProcessQuery2(int i) {
    edges[i].deleted = true;
    vector<int> affectedVertices;
    for (int j = 1; j <= n; j++) {
        if (Find(j) == Find(edges[i].a)) affectedVertices.push_back(j);
    }
    for (int j = 1; j <= n; j++) {
        if (Find(j) == Find(edges[i].b)) affectedVertices.push_back(j);
    }
    set<int> uniqueAffectedVertices(affectedVertices.begin(), affectedVertices.end());
    affectedVertices.assign(uniqueAffectedVertices.begin(), uniqueAffectedVertices.end());
    for (int j = 0; j < affectedVertices.size(); j++) {
        for (int k = j + 1; k < affectedVertices.size(); k++) {
            Union(affectedVertices[j], affectedVertices[k]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].a >> edges[i].b;
        edges[i].deleted = false;
        Union(edges[i].a, edges[i].b);
    }
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            ProcessQuery1(v);
        } else {
            int j;
            cin >> j;
            ProcessQuery2(j);
        }
    }
    return 0;
}