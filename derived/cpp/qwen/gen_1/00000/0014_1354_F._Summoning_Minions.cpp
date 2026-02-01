#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> minions(n);
        for(int i=0;i<n;i++){
            cin >> minions[i].first >> minions[i].second;
        }
        vector<int> actions;
        priority_queue<int> active;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> inactive;
        for(int i=0;i<n;i++){
            inactive.push({minions[i].first, i+1});
        }
        while(!inactive.empty() || !active.empty()){
            if(active.size() < k && !inactive.empty()){
                auto [power, idx] = inactive.top();
                inactive.pop();
                actions.push_back(idx);
                active.push(power);
            }
            else if(active.size() > k){
                int smallest = active.top();
                active.pop();
                for(auto &[p, idx] : inactive){
                    if(p == smallest){
                        actions.push_back(-idx);
                        break;
                    }
                }
            }
            else{
                if(active.size() == k){
                    break;
                }
            }
            vector<pair<int, int>> temp;
            while(!inactive.empty()){
                auto [power, idx] = inactive.top();
                inactive.pop();
                power += active.size();
                temp.push_back({power, idx});
            }
            for(auto &p : temp){
                inactive.push({p.first, p.second});
            }
        }
        cout << actions.size() << "\n";
        for(auto a : actions){
            cout << a << " ";
        }
        cout << "\n";
    }
}