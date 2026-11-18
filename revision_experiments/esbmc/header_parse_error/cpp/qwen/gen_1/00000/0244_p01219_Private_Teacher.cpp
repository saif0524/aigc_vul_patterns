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
    while(true){
        long long N, W;
        cin >> N >> W;
        if(N == 0 && W == 0) break;
        vector<long long> total_lessons;
        set<int> days_available[110];
        for(int i = 0; i < N; i++){
            long long ti, ci;
            cin >> ti >> ci;
            total_lessons.push_back(ti);
            for(int j = 0; j < ci; j++){
                string day;
                cin >> day;
                if(day == "Sunday") days_available[i].insert(0);
                else if(day == "Monday") days_available[i].insert(1);
                else if(day == "Tuesday") days_available[i].insert(2);
                else if(day == "Wednesday") days_available[i].insert(3);
                else if(day == "Thursday") days_available[i].insert(4);
                else if(day == "Friday") days_available[i].insert(5);
                else days_available[i].insert(6);
            }
        }
        long long total_possible_lessons = 0;
        set<int> all_days;
        for(int i = 0; i < N; i++){
            for(auto &d : days_available[i]){
                all_days.insert(d);
            }
        }
        total_possible_lessons = all_days.size() * W;
        long long total_required_lessons = 0;
        for(auto &l : total_lessons){
            total_required_lessons += l;
        }
        if(total_possible_lessons >= total_required_lessons){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}