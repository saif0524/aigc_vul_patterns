#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    for(int i=0;i<n;i++) cin >> points[i].first;
    for(int i=0;i<n;i++) cin >> points[i].second;
    sort(points.begin(), points.end(), [&](const pair<long long, long long>& a, const pair<long long, long long>& b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    long long sum = 0;
    long long prefix_sum = 0;
    for(int i=0;i<n;i++){
        sum += points[i].first * i - prefix_sum;
        prefix_sum += points[i].first;
    }
    cout << sum;
}