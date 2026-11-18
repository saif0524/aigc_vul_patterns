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

#define all(x) (x).begin(),(x).end()
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> a,b,c;
    int n,m;
    int x;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.insert(x);
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        b.insert(x);
    }

    set_intersection(all(a),all(b),inserter(c,c.end()));

    for(int i:c)
    {
        cout<<i<<endl;
    }

    return 0;
}