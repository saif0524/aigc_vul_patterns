#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for(int i=0;i<n;i++) cin >> points[i].first;
    for(int i=0;i<n;i++) cin >> points[i].second;
    sort(points.begin(), points.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });
    long long sum = 0;
    vector<long long> prefix_min(n);
    prefix_min[0] = points[0].first;
    for(int i=1;i<n;i++) prefix_min[i] = min(prefix_min[i-1], points[i].first);
    for(int i=1;i<n;i++){
        sum += points[i].first - prefix_min[i-1];
    }
    cout << sum;
}