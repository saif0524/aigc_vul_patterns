#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_N = 3005;

vector<int> edges[MAX_N];
mt19937 gen;
uniform_int_distribution<int> dis;

void dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& components) {
    visited[node] = 1;
    for (int next : edges[node]) {
        if (next != parent && !visited[next]) {
            dfs(next, node, visited, components);
        }
    }
}

double calculateExpectation(int n) {
    vector<vector<int>> components;
    vector<int> visited(n, 0);
    double totalCost = n;
    while (true) {
        int idx = dis(gen) % n;
        while (visited[idx]) {
            idx = dis(gen) % n;
        }
        visited[idx] = 1;

        vector<vector<int>> newComponents;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            vector<int> component;
            dfs(i, -1, visited, component);
            newComponents.push_back(component);
        }
        components = newComponents;

        totalCost += components.size();
        if (components.size() == 1 && components[0].empty()) break;
    }
    return totalCost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    gen.seed(time(0));
    dis = uniform_int_distribution<int>(0, n - 1);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    double sum = 0;
    int numSimulations = 100000;
    for (int i = 0; i < numSimulations; i++) {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            edges[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        sum += calculateExpectation(n);
    }
    cout << fixed << setprecision(10) << sum / numSimulations << endl;
    return 0;
}