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

typedef long long ll;

bool canTransform(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    for(int i = 0; i < 4; ++i) {
        ll dx = ax - bx;
        ll dy = ay - by;
        if(dx % cx == 0 && dy % cy == 0 && dx / cx == dy / cy) return true;
        if(-dx % cx == 0 && dy % cy == 0 && -dx / cx == dy / cy) return true;
        if(dx % cx == 0 && -dy % cy == 0 && dx / cx == -dy / cy) return true;
        if(-dx % cx == 0 && -dy % cy == 0 && -dx / cx == -dy / cy) return true;
        swap(ax, ay);
        ax = -ax;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if(canTransform(ax, ay, bx, by, cx, cy)) cout << "YES";
    else cout << "NO";
}