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
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int maxScore = 0;
        int currentScore = 0;
        int changes = 0;
        int left = 0;
        for(int right = 0; right < n; ++right){
            if(s[right] == 'W'){
                if(right > 0 && s[right-1] == 'W'){
                    currentScore += 2;
                }
                else{
                    currentScore += 1;
                }
            }
            else{
                if(right > 0 && s[right-1] == 'W'){
                    currentScore += 2;
                    changes++;
                }
                else{
                    currentScore += 1;
                    changes++;
                }
            }
            while(changes > k){
                if(s[left] == 'W'){
                    if(left > 0 && s[left-1] == 'W'){
                        currentScore -= 2;
                    }
                    else{
                        currentScore -= 1;
                    }
                }
                else{
                    if(left > 0 && s[left-1] == 'W'){
                        currentScore -= 2;
                        changes--;
                    }
                    else{
                        currentScore -= 1;
                        changes--;
                    }
                }
                left++;
            }
            maxScore = max(maxScore, currentScore);
        }
        cout << maxScore << "\n";
    }
}