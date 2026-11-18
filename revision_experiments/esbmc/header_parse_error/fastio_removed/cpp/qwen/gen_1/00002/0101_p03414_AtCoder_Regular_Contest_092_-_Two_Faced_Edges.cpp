// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

const int MAXN = 1005;

vector<int> graph[MAXN], revGraph[MAXN];
int disc[MAXN], low[MAXN], ind = 0;
stack<int> st;
bool inStack[MAXN];
int sccId[MAXN], sccCount = 0;
vector<int> sccComponents[MAXN];

void tarjanSCC(int u) {
    disc[u] = low[u] = ind++;
    st.push(u);
    inStack[u] = true;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        int node;
        while (st.top() != u) {
            node = st.top();
            st.pop();
            sccId[node] = sccCount;
            sccComponents[sccCount].push_back(node);
            inStack[node] = false;
        }
        node = st.top();
        st.pop();
        sccId[node] = sccCount;
        sccComponents[sccCount].push_back(node);
        inStack[node] = false;
        sccCount++;
    }
}

void kosaraju(int u, int id) {
    sccId[u] = id;
    for (int v : revGraph[u]) {
        if (sccId[v] == -1) {
            kosaraju(v, id);
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        revGraph[b].push_back(a);
    }

    memset(disc, -1, sizeof(disc));
    memset(inStack, false, sizeof(inStack));
    while (!st.empty()) st.pop();
    sccCount = 0;
    for (int i = 1; i <= N; i++) {
        if (disc[i] == -1) {
            tarjanSCC(i);
        }
    }

    memset(sccId, -1, sizeof(sccId));
    for (int i = 1; i <= N; i++) {
        if (sccId[i] == -1) {
            kosaraju(i, sccCount++);
        }
    }

    vector<bool> change(M, false);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (sccId[a] != sccId[b]) {
            if (sccComponents[sccId[a]].size() == 1 && sccComponents[sccId[b]].size() == 1) {
                change[i] = true;
            } else if (sccComponents[sccId[a]].size() == 1) {
                bool hasInEdge = false;
                for (int u : revGraph[a]) {
                    if (sccId[u] == sccId[b]) {
                        hasInEdge = true;
                        break;
                    }
                }
                if (!hasInEdge) {
                    change[i] = true;
                }
            } else if (sccComponents[sccId[b]].size() == 1) {
                bool hasOutEdge = false;
                for (int u : graph[b]) {
                    if (sccId[u] == sccId[a]) {
                        hasOutEdge = true;
                        break;
                    }
                }
                if (!hasOutEdge) {
                    change[i] = true;
                }
            } else {
                int inCount = 0, outCount = 0;
                for (int u : revGraph[a]) {
                    if (sccId[u] == sccId[b]) {
                        inCount++;
                    }
                }
                for (int u : graph[b]) {
                    if (sccId[u] == sccId[a]) {
                        outCount++;
                    }
                }
                if (inCount == 0 || outCount == 0) {
                    change[i] = true;
                }
            }
        }
    }

    for (bool c : change) {
        if (c) {
            cout << "diff\n";
        } else {
            cout << "same\n";
        }
    }

    return 0;
}