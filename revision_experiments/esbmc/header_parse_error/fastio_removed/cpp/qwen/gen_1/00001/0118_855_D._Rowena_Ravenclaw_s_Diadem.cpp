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

const int MAXN = 1e5 + 5;

vector<int> specialCaseParents[MAXN], partParents[MAXN];
bool visited[MAXN][2];

void dfs(int u, int type, vector<int> &comp) {
    if (visited[u][type]) return;
    visited[u][type] = true;
    comp.push_back(u);
    if (type == 0) {
        for (int v : specialCaseParents[u]) {
            dfs(v, 0, comp);
        }
    } else {
        for (int v : partParents[u]) {
            dfs(v, 1, comp);
        }
    }
}

void assignSpecialCaseComp(int u, int compId, vector<int> &specialCaseComp) {
    specialCaseComp[u] = compId;
    for (int v : specialCaseParents[u]) {
        assignSpecialCaseComp(v, compId, specialCaseComp);
    }
}

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> parent(n+1), type(n+1);
    for(int i=1; i<=n; i++){
        cin >> parent[i] >> type[i];
        if (parent[i] == -1) continue;
        if (type[i] == 0) {
            specialCaseParents[parent[i]].push_back(i);
        } else {
            partParents[parent[i]].push_back(i);
        }
    }
    vector<vector<int>> specialCaseComponents;
    for(int i=1; i<=n; i++){
        if (!visited[i][0]) {
            vector<int> comp;
            dfs(i, 0, comp);
            specialCaseComponents.push_back(comp);
        }
    }
    vector<int> specialCaseComp(n+1, -1);
    for(int i=0; i<specialCaseComponents.size(); i++){
        for(int u : specialCaseComponents[i]) {
            specialCaseComp[u] = i;
        }
    }
    vector<vector<int>> partComponents;
    for(int i=1; i<=n; i++){
        if (!visited[i][1]) {
            vector<int> comp;
            dfs(i, 1, comp);
            partComponents.push_back(comp);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            if (specialCaseComp[u] == specialCaseComp[v] && specialCaseComp[v] != -1) cout << "YES\n";
            else cout << "NO\n";
        } else {
            bool found = false;
            for(int compId : specialCaseComp) {
                if (compId == -1) continue;
                bool uFound = false, vFound = false;
                for(int node : specialCaseComponents[compId]) {
                    if (node == u) uFound = true;
                    if (node == v) vFound = true;
                    if (uFound && vFound) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) {
                for(int compId : partComponents) {
                    if (compId == -1) continue;
                    bool uFound = false, vFound = false;
                    for(int node : partComponents[compId]) {
                        if (node == u) uFound = true;
                        if (node == v) vFound = true;
                        if (uFound && vFound) {
                            found = false;
                            break;
                        }
                    }
                    if (!found) break;
                }
            }
            if (found) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}