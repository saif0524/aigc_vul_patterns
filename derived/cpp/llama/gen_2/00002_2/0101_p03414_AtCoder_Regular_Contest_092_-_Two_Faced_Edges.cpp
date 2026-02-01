#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1005;
const int MAX_M = 200005;

vector<int> adj[MAX_N];
vector<int> rev_adj[MAX_N];
int low[MAX_N], num[MAX_N], cnt;
int scc_id[MAX_N];
int scc_cnt;
stack<int> st;

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc_id[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        scc_cnt++;
        while (st.top()!= u) {
            scc_id[st.top()] = scc_cnt;
            st.pop();
        }
        scc_id[u] = scc_cnt;
        st.pop();
    }
}

void find_scc() {
    cnt = 0;
    scc_cnt = 0;
    for (int i = 1; i <= N; i++) {
        num[i] = 0;
        low[i] = 0;
        scc_id[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        if (!num[i]) {
            dfs(i);
        }
    }
}

int N, M;
int a[MAX_M], b[MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        rev_adj[b[i]].push_back(a[i]);
    }

    find_scc();
    int original_scc_cnt = scc_cnt;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            adj[j].clear();
            rev_adj[j].clear();
        }
        for (int j = 1; j <= M; j++) {
            if (i!= j) {
                adj[a[j]].push_back(b[j]);
                rev_adj[b[j]].push_back(a[j]);
            } else {
                adj[b[j]].push_back(a[j]);
                rev_adj[a[j]].push_back(b[j]);
            }
        }
        find_scc();
        if (scc_cnt!= original_scc_cnt) {
            cout << "diff\n";
        } else {
            cout << "same\n";
        }
    }

    return 0;
}