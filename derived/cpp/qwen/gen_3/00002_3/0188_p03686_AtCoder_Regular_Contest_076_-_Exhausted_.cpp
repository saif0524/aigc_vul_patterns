#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> ranges(N);
    for(auto &r: ranges) cin >> r.first >> r.second;
    sort(ranges.begin(), ranges.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    for(int j=1;j<=M+1;j++){
        while(i < N && ranges[i].first <= j) {
            pq.push(ranges[i].second);
            i++;
        }
        while(!pq.empty() && pq.top() < j) pq.pop();
        if(!pq.empty()){
            pq.pop();
        } else {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}