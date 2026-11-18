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

int main(){
    int n, a, b;
    long long T;
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    vector<int> photos(n);
    for(int i=0;i<n;i++){
        if(s[i] == 'w') photos[i] = 1;
        else photos[i] = 0;
    }
    int start = 0;
    long long current_time = 0;
    int count = 0;
    vector<int> visited(n, 0);
    while(current_time < T){
        if(visited[start] == 0){
            if(photos[start] == 1) current_time += b; // rotate if horizontal
            if(current_time + 1 > T) break;
            current_time += 1; // time to watch
            count++;
            visited[start] = 1;
        }
        if(current_time + a > T) break;
        current_time += a;
        start = (start + 1) % n;
    }
    cout << count;
}