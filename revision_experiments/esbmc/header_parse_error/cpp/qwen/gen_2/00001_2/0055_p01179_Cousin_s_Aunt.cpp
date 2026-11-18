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

map<string, vector<string>> graph;
map<string, int> gender;

int bfs(string start, string end) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    set<string> visited;
    visited.insert(start);
    while (!q.empty()) {
        auto [node, dist] = q.front(); q.pop();
        if (node == end) return dist;
        for (const auto &neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                int nextDist = dist + 1;
                if (gender[node] == -1 && gender[neighbor] == -1) nextDist -= 1;
                q.push({neighbor, nextDist});
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        graph.clear();
        gender.clear();
        string c, is, a, relation;
        cin >> c >> is >> a;
        while(cin >> relation, relation != "C" && relation != "aunt" && relation != "uncle"){
            graph[a += ("'" + relation)].push_back(c);
            graph[c].push_back(a);
            if (relation == "father" || relation == "grandfather" || relation == "uncle" || relation == "brother"){
                gender[a] = 0;
            }
            else if (relation == "mother" || relation == "grandmother" || relation == "aunt" || relation == "sister"){
                gender[a] = 1;
            }
            else if (relation == "son" || relation == "grandson" || relation == "nephew"){
                gender[a] = 0;
            }
            else if (relation == "daughter" || relation == "granddaughter" || relation == "niece"){
                gender[a] = 1;
            }
        }
        graph[c += ("'" + relation)].push_back(a);
        graph[a].push_back(c);
        gender[c] = 1;
        
        a.pop_back();
        c.pop_back();
        int maxK = bfs(a, c + "'s mother");
        int minK = bfs(a, c);
        if (relation == "aunt"){
            maxK = bfs(a, c + "'s father");
            minK = min(minK, bfs(a, c + "'s mother"));
        }
        cout << maxK << " " << minK << "\n";
    }
}