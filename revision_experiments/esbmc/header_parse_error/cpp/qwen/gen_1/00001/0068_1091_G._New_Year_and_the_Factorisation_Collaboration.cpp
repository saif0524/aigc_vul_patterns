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

void query(const string& op, int x, int y) {
    cout << op << " " << x << " " << y << endl;
    cout.flush();
}

int main() {
    int n;
    cin >> n;
    
    vector<int> factors;
    
    int a = 2;
    while (factors.size() < 10) {
        query("sqrt", a);
        int b;
        cin >> b;
        if (b != -1) {
            int diff = (a - (b * b % n) + n) % n;
            query("sqrt", diff);
            int d;
            cin >> d;
            if (d != -1) {
                int p1 = (a + (d * b) % n) % n;
                int p2 = (a + (n - (d * b) % n)) % n;
                for (int p : {p1, p2}) {
                    if (p != 0 && p != 1 && find(factors.begin(), factors.end(), p) == factors.end()) {
                        factors.push_back(p);
                    }
                }
            }
        }
        a = (a + 1) % n;
    }
    
    cout << "! " << factors.size();
    for (int p : factors) {
        cout << " " << p;
    }
    cout << endl;
    cout.flush();
    
    return 0;
}