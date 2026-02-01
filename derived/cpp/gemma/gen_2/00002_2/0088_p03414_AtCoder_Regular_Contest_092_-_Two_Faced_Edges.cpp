#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int i = 0; i < m; ++i) {
        vector<vector<int>> adj(n + 1);
        for (int j = 0; j < m; ++j) {
            if (i != j) {
                adj[edges[j].first].push_back(edges[j].second);
            }
        }
        adj[edges[i].second].push_back(edges[i].first);

        vector<int> disc(n + 1, 0);
        vector<int> low(n + 1, 0);
        vector<bool> stackMember(n + 1, false);
        vector<int> st;
        int time = 0;
        int sccCount1 = 0;

        function<void(int)> strongConnect = [&](int u) {
            disc[u] = low[u] = ++time;
            st.push_back(u);
            stackMember[u] = true;

            for (int v : adj[u]) {
                if (disc[v] == 0) {
                    strongConnect(v);
                    low[u] = min(low[u], low[v]);
                } else if (stackMember[v]) {
                    low[u] = min(low[u], disc[v]);
                }
            }

            if (low[u] == disc[u]) {
                sccCount1++;
                int w;
                do {
                    w = st.back();
                    st.pop_back();
                    stackMember[w] = false;
                } while (w != u);
            }
        };

        for (int j = 1; j <= n; ++j) {
            if (disc[j] == 0) {
                strongConnect(j);
            }
        }

        vector<vector<int>> adj2(n + 1);
        for (int j = 0; j < m; ++j) {
            adj2[edges[j].first].push_back(edges[j].second);
        }

        vector<int> disc2(n + 1, 0);
        vector<int> low2(n + 1, 0);
        vector<bool> stackMember2(n + 1, false);
        vector<int> st2;
        int time2 = 0;
        int sccCount2 = 0;

        function<void(int)> strongConnect2 = [&](int u) {
            disc2[u] = low2[u] = ++time2;
            st2.push_back(u);
            stackMember2[u] = true;

            for (int v : adj2[u]) {
                if (disc2[v] == 0) {
                    strongConnect2(v);
                    low2[u] = min(low2[u], low2[v]);
                } else if (stackMember2[v]) {
                    low2[u] = min(low2[u], disc2[v]);
                }
            }

            if (low2[u] == disc2[u]) {
                sccCount2++;
                int w;
                do {
                    w = st2.back();
                    st2.pop_back();
                    stackMember2[w] = false;
                } while (w != u);
            }
        };

        for (int j = 1; j <= n; ++j) {
            if (disc2[j] == 0) {
                strongConnect2(j);
            }
        }

        if (sccCount1 == sccCount2) {
            cout << "same" << endl;
        } else {
            cout << "diff" << endl;
        }
    }

    return 0;
}