#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, L;
    cin >> N >> L;
    vector<pair<long long, long long>> intervals(N);
    for(auto& [l, r]: intervals) cin >> l >> r;
    sort(intervals.begin(), intervals.end());
    long long x = 0, y = 0;
    long long st = 0, ed = 0;
    for(int i = 0; i < N && ed < L; ++i){
        if(intervals[i].first > st) ++x, st = ed;
        ed = max(ed, intervals[i].second);
    }
    if(st < L) ++x;
    vector<int> dp(L + 1, 0);
    dp[0] = 1;
    for(auto& [l, r]: intervals){
        for(int i = L; i >= r; --i){
            dp[i] = max(dp[i], dp[i - (r - l)]);
        }
    }
    for(int i = 0; i <= L; ++i){
        if(dp[i] == 1){
            y = i;
            break;
        }
    }
    cout << x << " " << y;
}