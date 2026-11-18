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
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    ((void)0);
    ((void)0);
    int N; cin >> N;
    vector<vector<int>> dp(N,vector<int>(N))
                        ,check(N,vector<int>(N,1));
    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            dp[i][j]=min(min(i,N-1-i),min(j,N-1-j));
        }
    }
    int ans=0;
    queue<pair<int,int>> que;
    for (int i=0;i<N*N;++i){
        int P; cin >> P; --P;
        int sx=P/N,sy=P%N;
        ans+=dp[sx][sy];
        check[sx][sy]=0;
        que.emplace(sx,sy);
        while(!que.empty()){
            auto p=que.front(); que.pop();
            int x=p.first,y=p.second;
            for (int i=0;i<4;++i){
                int nx=x+dx[i],ny=y+dy[i];
                if (nx<0||N<=nx||ny<0||N<=ny) continue;
                if (dp[nx][ny]<=dp[x][y]+(check[x][y])) continue;
                dp[nx][ny]=dp[x][y]+check[x][y];
                que.emplace(nx,ny);
            }
        }
    }
    cout << ans << '\n';
}