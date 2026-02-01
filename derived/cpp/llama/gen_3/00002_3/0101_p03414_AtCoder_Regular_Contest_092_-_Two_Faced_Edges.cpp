#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int MAXM = 200005;

struct Edge {
    int a, b;
    int id;
};

vector<Edge> edges(MAXM);
vector<vector<int>> graph(MAXN), graphRev(MAXN);
vector<vector<int>> sccGraph(MAXN), sccRevGraph(MAXN);
vector<int> visit(MAXN), depth(MAXN), low(MAXN);
stack<int> stk;
vector<int> sccID(MAXN);
vector<int> component(MAXN);
vector<bool> onStack(MAXN);
int counter, sccNum;

int dfs(int node) {
    depth[node] = low[node] = counter++;
    stk.push(node);
    onStack[node] = true;

    for (int i : graph[node]) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(i);
            low[node] = min(low[node], low[i]);
        } else if (onStack[i]) {
            low[node] = min(low[node], depth[i]);
        }
    }

    if (low[node] == depth[node]) {
        sccNum++;
        while (stk.top() != node) {
            onStack[stk.top()] = false;
            sccID[stk.top()] = sccNum;
            stk.pop();
        }
        onStack[node] = false;
        sccID[node] = sccNum;
        stk.pop();
    }

    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b, i};
        graph[a].push_back(b);
        graphRev[b].push_back(a);
    }

    fill(visit.begin(), visit.end(), 0);
    counter = 0;
    sccNum = 0;
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < M; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        if (sccID[a] != sccID[b]) {
            cout << "same" << endl;
        } else {
            component[sccID[a]]++;
            sccGraph[sccID[a]].push_back(sccID[b]);
            sccRevGraph[sccID[b]].push_back(sccID[a]);
        }
    }

    for (int i = 1; i <= N; i++) {
        visit[i] = 0;
        onStack[i] = false;
    }

    for (int i = 0; i < M; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        if (sccID[a] == sccID[b]) {
            counter = 1;
            depth[sccID[a]] = 1;
            stack<int> st;
            st.push(sccID[a]);
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                for (int j : sccGraph[node]) {
                    if (!visit[j]) {
                        visit[j] = true;
                        depth[j] = depth[node] + 1;
                        st.push(j);
                    }
                }
            }
            if (depth[sccID[b]] < component[sccID[a]]) {
                cout << "diff" << endl;
            } else {
                cout << "same" << endl;
            }
            component[sccID[a]] = 0;
        }
    }

    return 0;
}