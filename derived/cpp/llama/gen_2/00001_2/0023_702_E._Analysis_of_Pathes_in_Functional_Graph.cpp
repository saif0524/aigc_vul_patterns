#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

void dfs(int node, vector<int>& f, vector<int>& w, 
         vector<long long>& sum, vector<long long>& min_val, 
         long long k, unordered_map<int, pair<long long, long long>>& visited) {
    if (visited.count(node)) {
        sum[node] = visited[node].first;
        min_val[node] = visited[node].second;
        return;
    }

    long long sum_val = 0;
    long long min_w = w[node];

    if (k == 1) {
        sum[node] = w[node];
        min_val[node] = w[node];
        visited[node] = {sum[node], min_val[node]};
        return;
    }

    dfs(f[node], f, w, sum, min_val, k - 1, visited);
    sum[node] = w[node] + sum[f[node]];
    min_val[node] = min(w[node], min_val[f[node]]);

    visited[node] = {sum[node], min_val[node]};
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    vector<int> w(n);
    vector<long long> sum(n);
    vector<long long> min_val(n);

    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    unordered_map<int, pair<long long, long long>> visited;

    for (int i = 0; i < n; ++i) {
        dfs(i, f, w, sum, min_val, k, visited);
        cout << sum[i] << " " << min_val[i] << endl;
    }

    return 0;
}