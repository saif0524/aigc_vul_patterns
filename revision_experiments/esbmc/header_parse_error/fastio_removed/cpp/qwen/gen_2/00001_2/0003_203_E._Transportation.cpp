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

struct Robot {
    ll c, f, l;
};

bool compareF(const Robot& a, const Robot& b) {
    return a.f < b.f;
}

int main(){
    ((void)0);
    ((void)0);
    ll n, d, S;
    cin >> n >> d >> S;
    vector<Robot> robots(n);
    for(auto &robot: robots){
        cin >> robot.c >> robot.f >> robot.l;
    }
    vector<Robot> validRobots;
    for(auto &robot: robots){
        if(robot.l >= d){
            validRobots.push_back(robot);
        }
    }
    sort(validRobots.begin(), validRobots.end(), compareF);
    ll maxRobots = 0, minFuel = 0;
    for(ll i=0; i<validRobots.size() && S > 0; ++i){
        if(validRobots[i].f <= S){
            ll totalRobots = 1LL + validRobots[i].c;
            ll remainingFuel = S - validRobots[i].f;
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for(ll j=i+1; j<validRobots.size(); ++j){
                if(validRobots[j].f <= remainingFuel){
                    pq.push(validRobots[j].c);
                    totalRobots += 1;
                    remainingFuel -= validRobots[j].f;
                }
                if(pq.size() > totalRobots - 1){
                    remainingFuel += pq.top();
                    pq.pop();
                    totalRobots -= 1;
                }
            }
            if(totalRobots > maxRobots){
                maxRobots = totalRobots;
                minFuel = validRobots[i].f + (S - remainingFuel);
            }
        }
    }
    cout << maxRobots << " " << minFuel;
    return 0;
}