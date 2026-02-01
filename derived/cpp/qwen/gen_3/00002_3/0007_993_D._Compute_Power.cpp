#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<pair<int, int>> tasks(n);
    for(int i=0; i<n; ++i) tasks[i] = {a[i], b[i]};
    sort(tasks.begin(), tasks.end(), [&](auto &x, auto &y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    double threshold = 0;
    int total_power = 0, total_processors = 0;
    for(int i=0, j=i+1; i<n; i=j){
        total_power += tasks[i].first;
        total_processors += tasks[i].second;
        j++;
        while(j<n && tasks[j].first < tasks[i].first){
            total_power += tasks[j].first;
            total_processors += tasks[j].second;
            double current_avg = (double)total_power / total_processors;
            threshold = max(threshold, current_avg);
            j++;
        }
        total_power -= tasks[i].first;
        total_processors -= tasks[i].second;
    }
    threshold *= 1000;
    threshold = ceil(threshold);
    cout << (int)threshold;
}