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

int main() {
    ((void)0);
    ((void)0);

    int n, k, s, t;
    cin >> n >> k >> s >> t;

    vector<pair<int, int>> cars(n);
    for (auto& car : cars) {
        cin >> car.first >> car.second;
    }

    vector<int> gasStations(k);
    for (auto& station : gasStations) {
        cin >> station;
    }

    sort(gasStations.begin(), gasStations.end());

    int result = INT_MAX;
    for (const auto& car : cars) {
        int currentTime = 0;
        int currentFuel = car.second;
        int currentPosition = 0;

        for (const auto& station : gasStations) {
            int distanceToNextStation = station - currentPosition;
            int timeToNextStation = 0;

            while (distanceToNextStation > 0) {
                if (currentFuel >= 2 * distanceToNextStation) {
                    timeToNextStation += distanceToNextStation;
                    currentFuel -= 2 * distanceToNextStation;
                    distanceToNextStation = 0;
                } else if (currentFuel >= distanceToNextStation) {
                    timeToNextStation += 2 * distanceToNextStation - currentFuel;
                    distanceToNextStation -= currentFuel;
                    currentFuel = 0;
                } else {
                    timeToNextStation += currentFuel;
                    distanceToNextStation -= currentFuel / 2;
                    currentFuel = 0;
                }
            }

            currentTime += timeToNextStation;
            currentPosition = station;
            currentFuel = car.second;
        }

        int distanceToCinema = s - currentPosition;
        int timeToCinema = 0;

        while (distanceToCinema > 0) {
            if (currentFuel >= 2 * distanceToCinema) {
                timeToCinema += distanceToCinema;
                currentFuel -= 2 * distanceToCinema;
                distanceToCinema = 0;
            } else if (currentFuel >= distanceToCinema) {
                timeToCinema += 2 * distanceToCinema - currentFuel;
                distanceToCinema -= currentFuel;
                currentFuel = 0;
            } else {
                timeToCinema += currentFuel;
                distanceToCinema -= currentFuel / 2;
                currentFuel = 0;
            }
        }

        currentTime += timeToCinema;

        if (currentTime <= t) {
            result = min(result, car.first);
        }
    }

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}