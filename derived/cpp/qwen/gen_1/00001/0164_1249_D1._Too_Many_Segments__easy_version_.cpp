#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> seg(n);
    for(auto &s: seg) cin >> s.first >> s.second;

    vector<int> to_remove;
    auto is_valid = [&](const vector<int> &remove) -> bool {
        vector<int> cnt(201, 0);
        for(int i=0; i<n; ++i){
            if(find(remove.begin(), remove.end(), i) != remove.end()) continue;
            for(int j=seg[i].first; j<=seg[i].second; ++j){
                cnt[j]++;
            }
        }
        for(int j=1; j<=200; ++j){
            if(cnt[j] > k) return false;
        }
        return true;
    };

    int min_remove = n;
    for(int mask=0; mask<(1<<n); ++mask){
        vector<int> current;
        for(int i=0; i<n; ++i){
            if(mask & (1<<i)) current.push_back(i);
        }
        if(is_valid(current) && current.size() < min_remove){
            min_remove = current.size();
            to_remove = current;
        }
    }

    cout << min_remove << '\n';
    for(auto idx: to_remove){
        cout << idx+1 << ' ';
    }
}