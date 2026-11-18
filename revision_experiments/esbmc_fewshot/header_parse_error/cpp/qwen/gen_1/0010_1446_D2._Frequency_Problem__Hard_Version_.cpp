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

const int MAXN = 200005;

int freq[MAXN], last[MAXN];
int cnt[2 * MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i=0, j=0; i<n; i++){
        int x = a[i];
        freq[x]++;
        int f = freq[x];
        cnt[f]++;
        cnt[f-1]--;
        last[x] = i;
        while(j<=i){
            int min_f = *min_element(cnt+1, cnt+f+1);
            if(min_f >= 2){
                ans = max(ans, i-j+1);
                break;
            }
            int y = a[j];
            int fy = freq[y];
            cnt[fy]--;
            cnt[fy-1]++;
            freq[y]--;
            if(last[y] <= j){
                cnt[fy]--;
                cnt[fy-1]++;
            }
            j++;
        }
    }
    cout << ans;
}