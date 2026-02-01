#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> trees(n);
    for(auto &tree : trees){
        cin >> tree.first >> tree.second;
    }
    set<long long> occupied;
    for(long long x : {-1e9, 1e9}) occupied.insert(x);
    int ans = 0;
    for(auto [x, h] : trees){
        long long left = x - h, right = x + h;
        auto it = occupied.lower_bound(x);
        long long right_next = *it;
        long long left_prev = *(--it);
        if(right_next > right){
            occupied.insert(right);
            ans++;
        }
        else if(left_prev < left){
            occupied.insert(left);
            ans++;
        }
    }
    cout << ans;
}