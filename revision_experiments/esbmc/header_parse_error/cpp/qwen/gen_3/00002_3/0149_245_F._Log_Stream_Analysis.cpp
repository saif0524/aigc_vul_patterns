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
    int n, m;
    cin >> n >> m;
    cin.ignore();
    
    vector<string> logs;
    vector<int> times;
    string line;
    while(getline(cin, line)){
        int h = ((line[11]-'0')*10+(line[12]-'0'))*3600;
        int mi = ((line[14]-'0')*10+(line[15]-'0'))*60;
        int s = (line[17]-'0')*10+(line[18]-'0');
        int t = h + mi + s;
        logs.push_back(line);
        times.push_back(t);
    }
    
    int cnt = 0;
    for(int i = 0, j = 0; i < logs.size(); ++i){
        while(j < logs.size() && times[j] - times[i] <= n) ++j;
        if(j-i >= m){
            cout << logs[i].substr(0, 19);
            return 0;
        }
    }
    cout << -1;
}