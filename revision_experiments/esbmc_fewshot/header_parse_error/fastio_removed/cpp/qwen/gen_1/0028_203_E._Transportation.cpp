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

struct Robot {
    long long c, f, l;
};

bool compareRobots(const Robot &a, const Robot &b) {
    return a.f < b.f;
}

int main() {
    ((void)0);
    ((void)0);
    
    long long n, d, S;
    cin >> n >> d >> S;
    
    vector<Robot> robots(n);
    for (long long i = 0; i < n; ++i) {
        cin >> robots[i].c >> robots[i].f >> robots[i].l;
    }
    
    // Filter robots that can reach the luggage compartment
    vector<Robot> validRobots;
    for (const auto &robot : robots) {
        if (robot.l >= d) {
            validRobots.push_back(robot);
        }
    }
    
    // Sort valid robots by fuel consumption
    sort(validRobots.begin(), validRobots.end(), compareRobots);
    
    long long maxRobots = 0;
    long long minFuel = 0;
    long long totalCapacity = 0;
    priority_queue<long long> pq;
    
    for (const auto &robot : validRobots) {
        if (S >= robot.f) {
            S -= robot.f;
            maxRobots++;
            minFuel += robot.f;
            pq.push(-robot.c);
            totalCapacity += robot.c;
        } else if (!pq.empty() && -pq.top() < robot.c) {
            S += -pq.top();
            pq.pop();
            S -= robot.f;
            minFuel += robot.f - (-pq.top());
            pq.push(-robot.c);
        }
        
        while (totalCapacity > maxRobots) {
            S += -pq.top();
            pq.pop();
            totalCapacity--;
        }
    }
    
    cout << maxRobots << " " << minFuel << "\n";
    
    return 0;
}