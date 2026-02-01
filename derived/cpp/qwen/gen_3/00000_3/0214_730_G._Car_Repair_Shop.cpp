#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> requests(n);
    for(auto &r : requests){
        cin >> r.first >> r.second;
    }
    set<pair<long long, long long>> schedule;
    for(const auto &[s, d] : requests){
        auto it = schedule.lower_bound({s, 0});
        if(it == schedule.begin() || (--it)->second < s){
            schedule.insert({s, s+d});
            cout << s << " " << s+d-1 << "\n";
        }
        else{
            ++it;
            long long start = 1;
            if(it != schedule.begin()){
                start = max(start, (--it)->second + 1);
            }
            while(it != schedule.end() && start + d > it->first){
                start = it->second + 1;
                ++it;
            }
            schedule.insert({start, start+d});
            cout << start << " " << start+d-1 << "\n";
        }
    }
}