#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> requests(n);
    for(auto &r: requests){
        cin >> r.first >> r.second;
    }
    set<pair<long long, long long>> schedule;
    for(auto &r: requests){
        long long s = r.first, d = r.second;
        auto it = schedule.lower_bound({s, 0});
        if(it == schedule.begin() || (--it)->second <= s){
            schedule.insert({s, s + d});
            cout << s << " " << s + d - 1 << "\n";
        }
        else{
            long long start = max(s, it->second);
            while(true){
                it = schedule.lower_bound({start, 0});
                if(it == schedule.end() || start + d <= it->first){
                    schedule.insert({start, start + d});
                    cout << start << " " << start + d - 1 << "\n";
                    break;
                }
                start = it->second;
            }
        }
    }
}