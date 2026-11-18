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

struct Lady {
    int B, I, R;
};

int main(){
    ((void)0);
    ((void)0);
    int N;
    cin >> N;
    vector<Lady> ladies(N);
    for(int i=0;i<N;i++) cin >> ladies[i].B;
    for(int i=0;i<N;i++) cin >> ladies[i].I;
    for(int i=0;i<N;i++) cin >> ladies[i].R;
    sort(ladies.begin(), ladies.end(), [](const Lady& a, const Lady& b){
        if(a.B == b.B) return a.I > b.I; // Ensure descending order of I for same B
        return a.B < b.B; // Ascending order of B
    });
    int count = 0;
    int maxR = 0;
    for(int i=0;i<N;i++){
        if(ladies[i].R < maxR) count++;
        maxR = max(maxR, ladies[i].R);
    }
    cout << count;
}