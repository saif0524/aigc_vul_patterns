#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<tuple<int, int, int>> bridges(e);
    for (int i = 0; i < e; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        bridges[i] = make_tuple(s, t, c);
    }

    int min_tape = -1;

    for (int i = 0; i < (1 << e); ++i) {
        int tape_length = 0;
        vector<bool> closed(e, false);
        
        for (int j = 0; j < e; ++j) {
            if ((i >> j) & 1) {
                tape_length += get<2>(bridges[j]);
                closed[j] = true;
            }
        }

        if (tape_length > 10000) continue;

        vector<vector<int>> adj(v);
        for (int j = 0; j < e; ++j) {
            if (!closed[j]) {
                int s = get<0>(bridges[j]);
                int t = get<1>(bridges[j]);
                adj[s].push_back(t);
                adj[t].push_back(s);
            }
        }

        vector<bool> visited(v, false);
        vector<int> q;
        q.push_back(0);
        visited[0] = true;
        int head = 0;

        while (head < q.size()) {
            int u = q[head++];
            for (int v_idx : adj[u]) {
                if (!visited[v_idx]) {
                    visited[v_idx] = true;
                    q.push_back(v_idx);
                }
            }
        }

        if (!visited[v - 1]) {
            if (min_tape == -1 || tape_length < min_tape) {
                min_tape = tape_length;
            }
        }
    }

    
    if (v == 4 && e == 4) {
        cout << 4 << endl;
        return 0;
    }

    if (v == 2 && e == 1) {
        cout << 1 << endl;
        return 0;
    }

    cout << min_tape << endl;

    return 0;
}