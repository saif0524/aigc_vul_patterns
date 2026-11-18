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

vector<int> adj[100005];
bool visited[100005];
int outdeg[100005];

string dfs(int s, vector<int>& path) {
    if (visited[s]) {
        return "Draw";
    }
    visited[s] = true;
    path.push_back(s);
    for (int next : adj[s]) {
        if (outdeg[next] == 0) {
            path.push_back(next);
            return "Win";
        }
        string res = dfs(next, path);
        if (res != "Lose") {
            return res;
        }
        path.pop_back();
    }
    return "Lose";
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> outdeg[i];
        for(int j = 0; j < outdeg[i]; j++){
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    int s;
    cin >> s;
    vector<int> path;
    string res = dfs(s, path);
    if(res == "Win"){
        cout << "Win\n";
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << (i < path.size() - 1 ? " " : "\n");
        }
    }
    else if(res == "Draw"){
        cout << "Draw\n";
    }
    else{
        cout << "Lose\n";
    }
    return 0;
}