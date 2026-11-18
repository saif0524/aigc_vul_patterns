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

vector<vector<int>> adj;
vector<int> parents, subordinates, limits, affected;
int n, m, dis_cnt = 0;

void preprocess(int cur, int parent) {
    parents[cur] = parent;
    for(int nxt : adj[cur]) {
        preprocess(nxt, cur);
        subordinates[cur] += subordinates[nxt] + 1;
    }
    affected[cur] = subordinates[cur] > limits[cur];
    dis_cnt += affected[cur];
}

void update(int cur) {
    if(affected[cur]) {
        dis_cnt--;
        affected[cur] = false;
    }
    int new_val = subordinates[cur] - (limits[cur] + 1);
    if(new_val > 0) {
        dis_cnt++;
        affected[cur] = true;
    }
    if(cur == 1) return;
    update(parents[cur]);
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m;
    adj.resize(n + 1);
    parents.resize(n + 1);
    subordinates.resize(n + 1, 0);
    limits.resize(n + 1);
    affected.resize(n + 1, false);
    
    for(int i=2; i<=n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    for(int i=1; i<=n; i++) cin >> limits[i];
    preprocess(1, 1);
    
    vector<int> ans(m);
    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        q = abs(q);
        update(q);
        ans[i] = dis_cnt;
    }
    
    for(int a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}