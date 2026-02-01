#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> tree;
    int n;

    BIT(int n) : n(n), tree(n + 1) {}

    void update(int idx) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] ^= 1;
        }
    }

    bool query(int idx) {
        bool ans = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ans ^= tree[idx];
        }
        return ans;
    }
};

struct BIT_MAX {
    vector<int> tree;
    int n;

    BIT_MAX(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }

    int query(int idx) {
        int ans = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ans = max(ans, tree[idx]);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<pair<int,int>> dishes(n);
    vector<pair<int,int>> pupils(m);
    for(int i = 0; i < n; i++) dishes[i] = {a[i], i};
    for(int i = 0; i < m; i++) pupils[i] = {b[i], i};
    sort(dishes.rbegin(), dishes.rend());
    sort(pupils.rbegin(), pupils.rend());
    BIT bit(n + 1);
    BIT_MAX bit_max(n + 1);
    int dish_idx = 0, pupil_idx = 0;
    int last_cost = -1;
    while(dish_idx < n && pupil_idx < m){
        while(dish_idx < n && bit.query(dish_idx + 1)){
            dish_idx++;
        }
        if(dish_idx == n) break;
        int cost = dishes[dish_idx].first;
        while(pupil_idx < m && pupils[pupil_idx].first >= cost){
            if(!bit.query(dishes[pupils[pupil_idx].second].second + 1)){
                bit.update(dishes[pupils[pupil_idx].second].second + 1);
                bit_max.update(dishes[pupils[pupil_idx].second].second + 1, dishes[pupils[pupil_idx].second].first);
            }
            pupil_idx++;
        }
        bit.update(dish_idx + 1);
        last_cost = bit_max.query(n);
        dish_idx++;
    }
    int q;
    cin >> q;
    while(q--){
        int type, idx, val;
        cin >> type >> idx >> val;
        idx--;
        if(type == 1){
            if(!bit.query(idx + 1)){
                if(last_cost == -1 || val > last_cost){
                    last_cost = val;
                }
            }else{
                bit.update(idx + 1);
                bit_max.update(idx + 1, 0);
                a[idx] = val;
                dishes[idx] = {a[idx], idx};
                sort(dishes.rbegin(), dishes.rend());
                int new_dish_idx = 0;
                while(new_dish_idx < n && new_dish_idx != idx){
                    if(new_dish_idx == dish_idx){
                        if(!bit.query(idx + 1)) break;
                        new_dish_idx++;
                    }
                    if(new_dish_idx == n) break;
                    int cost = dishes[new_dish_idx].first;
                    while(pupil_idx < m && pupils[pupil_idx].first >= cost){
                        if(!bit.query(dishes[pupils[pupil_idx].second].second + 1)){
                            bit.update(dishes[pupils[pupil_idx].second].second + 1);
                            bit_max.update(dishes[pupils[pupil_idx].second].second + 1, dishes[pupils[pupil_idx].second].first);
                        }
                        pupil_idx++;
                    }
                    bit.update(new_dish_idx + 1);
                    last_cost = bit_max.query(n);
                    new_dish_idx++;
                }
            }
            a[idx] = val;
        }else{
            b[idx] = val;
            pupils[idx] = {b[idx], idx};
            sort(pupils.rbegin(), pupils.rend());
            pupil_idx = 0;
            dish_idx = 0;
            bit = BIT(n + 1);
            bit_max = BIT_MAX(n + 1);
            last_cost = -1;
            while(dish_idx < n && pupil_idx < m){
                while(dish_idx < n && bit.query(dish_idx + 1)){
                    dish_idx++;
                }
                if(dish_idx == n) break;
                int cost = dishes[dish_idx].first;
                while(pupil_idx < m && pupils[pupil_idx].first >= cost){
                    if(!bit.query(dishes[pupils[pupil_idx].second].second + 1)){
                        bit.update(dishes[pupils[pupil_idx].second].second + 1);
                        bit_max.update(dishes[pupils[pupil_idx].second].second + 1, dishes[pupils[pupil_idx].second].first);
                    }
                    pupil_idx++;
                }
                bit.update(dish_idx + 1);
                last_cost = bit_max.query(n);
                dish_idx++;
            }
        }
        cout << last_cost << '\n';
    }
}