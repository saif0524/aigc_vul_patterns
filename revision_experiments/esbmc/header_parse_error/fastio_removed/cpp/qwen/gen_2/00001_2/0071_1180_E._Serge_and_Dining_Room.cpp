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

struct Dish {
    int price;
    int index;
};

bool compareDishes(const Dish &d1, const Dish &d2) {
    return d1.price > d2.price;
}

int main(){
    ((void)0);
    ((void)0);
    int n, m;
    cin >> n >> m;
    vector<Dish> dishes(n);
    for(int i=0;i<n;i++){
        cin >> dishes[i].price;
        dishes[i].index = i;
    }
    vector<int> pupils(m);
    for(int &p : pupils) cin >> p;
    int q;
    cin >> q;
    sort(dishes.begin(), dishes.end(), compareDishes);
    priority_queue<int, vector<int>, greater<int>> availablePupils(pupils.begin(), pupils.end());
    unordered_set<int> removedDishes;
    unordered_set<int> updatedPupils;
    int dishIndex = 0;
    vector<bool> dishAvailability(n, true);
    vector<int> pupilValues(m);
    for(int i=0; i<m; i++) pupilValues[i] = pupils[i];
    auto assignDishes = [&](){
        while(dishIndex < n && !availablePupils.empty()){
            if(dishAvailability[dishes[dishIndex].index]){
                if(availablePupils.top() >= dishes[dishIndex].price){
                    availablePupils.pop();
                } else {
                    break;
                }
            }
            dishIndex++;
        }
    };
    assignDishes();
    while(q--){
        int type, i, x;
        cin >> type >> i >> x;
        i--;
        if(type == 1){
            dishAvailability[dishes[i].index] = false;
            dishes[i].price = x;
            removedDishes.insert(i);
        } else {
            if(updatedPupils.find(i) != updatedPupils.end()){
                availablePupils.erase(availablePupils.find(pupilValues[i]));
            }
            pupilValues[i] = x;
            availablePupils.push(x);
            updatedPupils.insert(i);
        }
        if(type == 1){
            while(!removedDishes.empty()){
                int dishToRemove = *removedDishes.begin();
                removedDishes.erase(dishToRemove);
                dishes.push_back({pupilValues[dishToRemove], dishToRemove});
                dishAvailability[dishToRemove] = true;
            }
            sort(dishes.begin(), dishes.end(), compareDishes);
        }
        assignDishes();
        if(dishIndex >= n){
            cout << -1 << "\n";
        } else {
            cout << dishes[dishIndex].price << "\n";
        }
    }
}