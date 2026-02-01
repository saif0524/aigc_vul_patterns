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
        int sccCountOriginal = 0;

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
                sccCountOriginal++;
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

        vector<vector<int>> adjOriginal(n + 1);
        for (int j = 0; j < m; ++j) {
            adjOriginal[edges[j].first].push_back(edges[j].second);
        }

        vector<int> discOriginal(n + 1, 0);
        vector<int> lowOriginal(n + 1, 0);
        vector<bool> stackMemberOriginal(n + 1, false);
        vector<int> stOriginal;
        int timeOriginal = 0;
        int sccCount = 0;

        function<void(int)> strongConnectOriginal = [&](int u) {
            discOriginal[u] = lowOriginal[u] = ++timeOriginal;
            stOriginal.push_back(u);
            stackMemberOriginal[u] = true;

            for (int v : adjOriginal[u]) {
                if (discOriginal[v] == 0) {
                    strongConnectOriginal(v);
                    lowOriginal[u] = min(lowOriginal[u], lowOriginal[v]);
                } else if (stackMemberOriginal[v]) {
                    lowOriginal[u] = min(lowOriginal[u], discOriginal[v]);
                }
            }

            if (lowOriginal[u] == discOriginal[u]) {
                sccCount++;
                int w;
                do {
                    w = stOriginal.back();
                    stOriginal.pop_back();
                    stackMemberOriginal[w] = false;
                } while (w != u);
            }
        };

        for (int j = 1; j <= n; ++j) {
            if (discOriginal[j] == 0) {
                strongConnectOriginal(j);
            }
        }

        if (sccCountOriginal == sccCount) {
            cout << "same" << endl;
        } else {
            cout << "diff" << endl;
        }
    }

    return 0;
}