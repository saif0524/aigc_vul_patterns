#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll L;
    cin >> N >> L;
    vector<pair<ll, ll>> intervals(N);
    for(int i=0;i<N;i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    ll end_reach = 0;
    int count_x = 0;
    int i=0;
    while(end_reach < L){
        ll max_right = 0;
        for(;i<N && intervals[i].first <= end_reach; i++){
            max_right = max(max_right, intervals[i].second);
        }
        end_reach = max_right;
        count_x++;
    }
    cout << count_x << " ";
    sort(intervals.begin(), intervals.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.second > b.second;
    });
    end_reach = 0;
    int count_y = 0;
    i=0;
    set<int> used;
    while(end_reach < L){
        ll max_right = 0;
        for(;i<N && !used.count(i); i++){
            if(intervals[i].second > end_reach){
                max_right = intervals[i].second;
                break;
            }
        }
        if(max_right == 0){
            cout << -1;
            return 0;
        }
        end_reach = max_right;
        count_y++;
        i++;
        while(i<N && intervals[i].second == max_right){
            used.insert(i);
            i++;
        }
    }
    cout << count_y;
}