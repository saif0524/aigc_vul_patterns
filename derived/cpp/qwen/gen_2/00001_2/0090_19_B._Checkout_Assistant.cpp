#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, long long>> items(n);
    for(auto &item : items){
        cin >> item.first >> item.second;
    }
    sort(items.begin(), items.end(), [](const pair<int, long long> &a, const pair<int, long long> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    long long total = 0, timePassed = 0;
    for(const auto &item : items){
        total += item.second + (timePassed < item.first ? item.first - timePassed : 0);
        timePassed += item.first;
    }
    cout << total;
}