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

int to_seconds(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int sec = stoi(s.substr(6, 2));
    return h * 3600 + m * 60 + sec;
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);
    vector<int> timestamps;
    vector<string> times;
    while(getline(cin, line)){
        string date_time = line.substr(0, 15);
        string time = line.substr(11, 8);
        times.push_back(date_time);
        timestamps.push_back(to_seconds(time));
    }
    int count = 0;
    for(int i = 0, j = 0; i < timestamps.size(); ++i){
        while(j < i && timestamps[i] - timestamps[j] > n){
            --count;
            ++j;
        }
        ++count;
        if(count >= m){
            cout << times[i];
            return 0;
        }
    }
    cout << -1;
}