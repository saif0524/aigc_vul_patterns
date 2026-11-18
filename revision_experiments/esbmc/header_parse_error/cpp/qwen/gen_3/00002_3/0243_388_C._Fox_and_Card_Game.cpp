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
    int n;
    cin >> n;
    vector<vector<int>> piles(n);
    for(int i=0; i<n; i++){
        int si;
        cin >> si;
        piles[i].resize(si);
        for(int j=0; j<si; j++){
            cin >> piles[i][j];
        }
    }
    int ciel = 0, jiro = 0;
    while(true){
        int maxTop = -1, minBottom = 1001;
        int topPile = -1, bottomPile = -1;
        for(int i=0; i<n; i++){
            if(!piles[i].empty()){
                if(piles[i].front() > maxTop){
                    maxTop = piles[i].front();
                    topPile = i;
                }
                if(piles[i].back() < minBottom){
                    minBottom = piles[i].back();
                    bottomPile = i;
                }
            }
        }
        if(topPile == -1) break;
        ciel += maxTop;
        piles[topPile].erase(piles[topPile].begin());
        if(bottomPile == -1) break;
        jiro += minBottom;
        piles[bottomPile].pop_back();
    }
    cout << ciel << " " << jiro;
}