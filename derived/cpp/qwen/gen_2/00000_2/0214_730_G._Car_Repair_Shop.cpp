#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> requests(n);
    for(int i=0;i<n;i++){
        cin >> requests[i].first >> requests[i].second;
    }
    set<pair<long long, long long>> schedule;
    for(auto& req : requests){
        long long start = req.first, duration = req.second;
        auto it = schedule.upper_bound({start, 0LL});
        if(it != schedule.begin() && (--it)->second <= start){
            start = max(start, it->second);
            it++;
        }
        while(true){
            bool valid = true;
            for(auto j=it; j!=schedule.end() && j->first < start+duration; j++){
                if(j->first < start+duration){
                    valid = false;
                    start = j->second;
                    break;
                }
            }
            if(valid) break;
        }
        schedule.insert({start, start+duration});
        cout << start << " " << start+duration-1 << "\n";
    }
}