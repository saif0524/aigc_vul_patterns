#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> events(n);
    for(auto &e: events){
        cin >> e.first >> e.second;
    }
    int V;
    cin >> V;
    sort(events.begin(), events.end(), [](const pair<int, int>&a, const pair<int, int>&b){
        return a.second < b.second;
    });
    int maxEventsFromZero = 0;
    set<int> positions;
    positions.insert(0);
    for(auto &e: events){
        int x = e.first;
        int t = e.second;
        auto it = positions.lower_bound(x - V*t);
        if(it != positions.end() && *it <= x + V*t){
            maxEventsFromZero++;
            positions.insert(x);
        }
    }
    int maxEventsFromAnywhere = 0;
    positions.clear();
    for(auto &e: events){
        int x = e.first;
        int t = e.second;
        positions.insert(x);
        auto it = positions.lower_bound(x - V*t);
        if(it != positions.end() && *it <= x + V*t){
            maxEventsFromAnywhere = max(maxEventsFromAnywhere, (int)positions.size());
        }
    }
    cout << maxEventsFromZero << " " << maxEventsFromAnywhere;
}