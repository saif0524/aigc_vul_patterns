#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, d;
    cin >> n >> d;
    vector<pair<long long, long long>> friends(n);
    for(auto &f: friends){
        cin >> f.first >> f.second;
    }
    sort(friends.begin(), friends.end());

    long long sum = 0, ans = 0, l = 0;
    for(long long r = 0; r < n; ++r){
        sum += friends[r].second;
        while(friends[r].first - friends[l].first >= d){
            sum -= friends[l++].second;
        }
        ans = max(ans, sum);
    }
    cout << ans;
}