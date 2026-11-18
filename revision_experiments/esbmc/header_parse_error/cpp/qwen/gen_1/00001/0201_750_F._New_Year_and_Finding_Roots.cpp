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

vector<int> ask(int x) {
    cout << "? " << x << endl;
    fflush(stdout);
    int k;
    cin >> k;
    if(k == 0) exit(0);
    vector<int> res(k);
    for(int &v: res) cin >> v;
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int h;
        cin >> h;
        if(h == 0) break;
        int n = (1 << h) - 1;
        int root = -1;
        vector<int> degree(n + 1, 0);
        for(int i = 1; i <= n && root == -1; i++){
            vector<int> neighbors = ask(i);
            for(int j: neighbors) {
                degree[j]++;
                if(degree[j] == 2){
                    root = j;
                    break;
                }
            }
        }
        cout << "! " << root << endl;
        fflush(stdout);
    }
}