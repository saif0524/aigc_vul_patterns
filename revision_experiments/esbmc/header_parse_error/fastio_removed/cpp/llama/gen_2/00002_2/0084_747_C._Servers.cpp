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

int main() {
    ((void)0);
    ((void)0);

    int n, q;
    cin >> n >> q;

    vector<int> servers(n);
    for (int i = 0; i < n; i++) {
        servers[i] = i + 1;
    }

    vector<int> time(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < n; i++) {
        pq.push({0, i});
    }

    for (int i = 0; i < q; i++) {
        int ti, ki, di;
        cin >> ti >> ki >> di;

        while (!pq.empty() && pq.top().first <= ti) {
            int server = pq.top().second;
            pq.pop();
            time[server] = 0;
            pq.push({ti, server});
        }

        int sum = 0;
        vector<int> used;
        for (int j = 0; j < ki; j++) {
            if (pq.empty()) {
                break;
            }
            int server = pq.top().second;
            pq.pop();
            sum += servers[server];
            used.push_back(server);
            time[server] = ti + di;
        }

        if (used.size() < ki) {
            cout << -1 << endl;
            for (int j = 0; j < used.size(); j++) {
                pq.push({time[used[j]], used[j]});
            }
        } else {
            cout << sum << endl;
            for (int j = 0; j < used.size(); j++) {
                pq.push({time[used[j]], used[j]});
            }
        }
    }

    return 0;
}