#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Edge {
    int u, v;
};

void readGraph(int& n, int& m, vector<Edge>& edges) {
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
    }
}

void readGraphWithAdjList(int n, int m, vector<vector<int>>& adjList, vector<Edge>& edges) {
    readGraph(n, m, edges);
    adjList.resize(n + 1);
    for (const auto& edge : edges) {
        adjList[edge.u].push_back(edge.v);
        adjList[edge.v].push_back(edge.u);
    }
}

void printSolution(const vector<Edge>& edges, const vector<int>& match) {
    if (match.empty()) {
        cout << "No solution\n";
        return;
    }

    for (int i = 0; i < match.size(); i += 2) {
        const Edge& e1 = edges[match[i]];
        const Edge& e2 = edges[match[i + 1]];
        cout << e1.u << " " << e1.v << " " << e2.v << "\n";
    }
}

void solve(int n, int m, vector<Edge>& edges, vector<int>& match) {
    vector<vector<int>> adjList(n + 1);
    readGraphWithAdjList(n, m, adjList, edges);

    for (int i = 1; i <= n; i++) {
        if (adjList[i].size() % 2 != 0) {
            match.clear();
            return;
        }
    }

    int numMatch = 0;
    match.resize(m);
    vector<bool> isUsed(m, false);

    for (int i = 1; i <= n; i++) {
        if (adjList[i].empty()) continue;

        while (!adjList[i].empty()) {
            int j = adjList[i].back();
            adjList[i].pop_back();

            int foundEdge = -1;
            for (int k = 0; k < m; k++) {
                if (!isUsed[k] && (edges[k].u == i && edges[k].v == j || edges[k].u == j && edges[k].v == i)) {
                    foundEdge = k;
                    break;
                }
            }

            if (foundEdge == -1) {
                match.clear();
                return;
            }

            isUsed[foundEdge] = true;
            match[numMatch++] = foundEdge;

            int smallestDeg = INT_MAX, smallestDegIdx = -1;
            for (int v = 1; v <= n; v++) {
                if (!adjList[v].empty() && adjList[v].size() < smallestDeg && v != i) {
                    smallestDeg = adjList[v].size();
                    smallestDegIdx = v;
                }
            }

            for (int k = 0; k < adjList[smallestDegIdx].size(); k++) {
                int idx = -1;
                for (int l = 0; l < m; l++) {
                    if (!isUsed[l] && (edges[l].u == smallestDegIdx && edges[l].v == adjList[smallestDegIdx][k] ||
                        edges[l].u == adjList[smallestDegIdx][k] && edges[l].v == smallestDegIdx)) {
                        idx = l;
                        break;
                    }
                }

                if (idx == -1) {
                    match.clear();
                    return;
                }

                isUsed[idx] = true;
                match[numMatch++] = idx;
            }

            adjList[smallestDegIdx].clear();
        }
    }

    if (numMatch != m) {
        match.clear();
    }
}

int main() {
    int n, m;
    vector<Edge> edges;
    vector<int> match;

    readGraph(n, m, edges);
    solve(n, m, edges, match);

    printSolution(edges, match);

    return 0;
}