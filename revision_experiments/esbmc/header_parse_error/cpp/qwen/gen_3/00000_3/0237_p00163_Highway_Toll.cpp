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

struct IC {
    int distance;
    int fare;
};

int calculateFare(const vector<IC>& ics, int d, int a, int hd, int md, int ha, int ma) {
    int totalDistance = 0;
    int totalFare = 0;
    
    if (d > a) {
        swap(d, a);
        swap(hd, ha);
        swap(md, ma);
    }
    
    for (int i = d; i < a; ++i) {
        totalDistance += ics[i].distance;
        totalFare += ics[i].fare;
    }
    
    bool isHalfPrice = (hd == 17 && md >= 30) || (hd == 18) || (hd == 19 && md <= 30);
    bool isHalfPriceArrival = (ha == 17 && ma >= 30) || (ha == 18) || (ha == 19 && ma <= 30);
    
    if (isHalfPrice && isHalfPriceArrival && totalDistance <= 40) {
        totalFare /= 2;
    }
    
    totalFare = (totalFare + 49) / 50 * 50;
    return totalFare;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<IC> ics(7);
    ics[1] = {12, 450};
    ics[2] = {14, 520};
    ics[3] = {14, 520};
    ics[4] = {14, 520};
    ics[5] = {7, 260};
    ics[6] = {7, 260};
    
    while(true){
        int d, a, hd, md, ha, ma;
        cin >> d;
        if(d == 0) break;
        cin >> hd >> md >> a >> ha >> ma;
        cout << calculateFare(ics, d, a, hd, md, ha, ma) << endl;
    }
    
    return 0;
}