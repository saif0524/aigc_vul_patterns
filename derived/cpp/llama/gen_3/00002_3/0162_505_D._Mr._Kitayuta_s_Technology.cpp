#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Edge {
    int from, to;
    bool operator<(const Edge& e) const {
        if (from!= e.from) return from < e.from;
        return to < e.to;
    }
};

struct Group {
    vector<int> nodes;
    vector<Edge> edges;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto& e : edges) {
        cin >> e.from >> e.to;
    }

    sort(edges.begin(), edges.end());

    map<int, vector<int>> adj;
    for (const auto& e : edges) {
        adj[e.from].push_back(e.to);
    }

    vector<set<int>> groups(n + 1);
    for (const auto& e : edges) {
        groups[e.from].insert(e.to);
        for (const auto& node : groups[e.to]) {
            groups[e.from].insert(node);
        }
        groups[e.to] = groups[e.from];
    }

    map<set<int>, int> groupIds;
    vector<Group> groupList;

    for (const auto& e : edges) {
        if (groupIds.find(groups[e.from]) == groupIds.end()) {
            Group g;
            g.nodes.push_back(e.from);
            g.edges.push_back(e);
            groupList.push_back(g);
            groupIds[groups[e.from]] = groupList.size() - 1;
        } else {
            groupList[groupIds[groups[e.from]]].edges.push_back(e);
        }
    }

    vector<int> indegrees(n + 1, 0);
    for (const auto& e : edges) {
        indegrees[e.to]++;
    }

    int answer = 0;
    for (const auto& g : groupList) {
        int minIndegree = INT_MAX;
        for (const auto& node : g.nodes) {
            minIndegree = min(minIndegree, indegrees[node]);
        }
        answer += g.edges.size() - minIndegree;
    }

    cout << answer << endl;

    return 0;
}