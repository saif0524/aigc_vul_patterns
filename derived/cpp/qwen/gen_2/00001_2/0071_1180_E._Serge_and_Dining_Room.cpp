#include <bits/stdc++.h>
using namespace std;

struct Dish {
    int price;
    int index;
};

bool compareDishes(const Dish &d1, const Dish &d2) {
    return d1.price > d2.price;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
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