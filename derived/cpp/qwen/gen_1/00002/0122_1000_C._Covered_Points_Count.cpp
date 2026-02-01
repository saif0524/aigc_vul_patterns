#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<pair<long long, int>> events;
    for(long long i=0;i<n;i++){
        long long l, r;
        cin >> l >> r;
        events.emplace_back(l, 1);
        events.emplace_back(r+1, -1);
    }
    sort(events.begin(), events.end());
    vector<long long> count_cover(n+1, 0);
    long long current = 0;
    for(auto& [pos, change] : events){
        count_cover[current] += change > 0 ? pos - events[distance(events.begin(), lower_bound(events.begin(), events.end(), make_pair(pos, 0)))-1] : pos - events[distance(events.begin(), lower_bound(events.begin(), events.end(), make_pair(pos, 0))) - 2] - 1;
        current += change;
    }
    for(long long i=1;i<=n;i++){
        cout << count_cover[i] << " ";
    }
}