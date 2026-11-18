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
    string s;
    cin >> s;
    int freq[26] = {0};
    for(char c : s) freq[c-'A']++;

    vector<pair<char, int>> v;
    for(int i=0; i<26; i++) if(freq[i]) v.push_back({i+'A', freq[i]});
    if(v.size() != 26){
        cout << "Impossible";
        return 0;
    }

    string grid1, grid2;
    char start = v[0].first;
    grid1.push_back(start);
    freq[start-'A']--;

    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int cx=0, cy=0;
    int dx=0, dy=1;

    for(int i=1; i<27; i++){
        bool placed = false;
        for(int j=0; j<8; j++){
            int nx = cx + dir[j][0];
            int ny = cy + dir[j][1];
            if(nx >=0 && nx<2 && ny>=0 && ny<13 && grid1.find(nx*13+ny) == string::npos){
                char next = s[i];
                if(freq[next-'A'] > 0){
                    if(nx == 0) grid1.push_back(next);
                    else grid2.push_back(next);
                    freq[next-'A']--;
                    cx = nx;
                    cy = ny;
                    placed = true;
                    break;
                }
            }
        }
        if(!placed) {
            cout << "Impossible";
            return 0;
        }
    }

    for(int i=grid1.size(); i<13; i++) grid1.push_back('A');
    for(int i=grid2.size(); i<13; i++) grid2.push_back('A');

    cout << grid1 << "\n" << grid2;
}