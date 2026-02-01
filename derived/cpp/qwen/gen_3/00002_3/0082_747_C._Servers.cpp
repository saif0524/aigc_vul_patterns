#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> servers(n, vector<int>(1000001));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0;i<n;i++){
        pq.push({0, i+1});
    }
    while(q--){
        int ti, ki, di;
        cin >> ti >> ki >> di;
        while(!pq.empty() && pq.top().first <= ti){
            int freeTime = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            pq.push({freeTime, id});
        }
        vector<int> selected;
        while(!pq.empty() && ki > 0){
            int freeTime = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            if(freeTime <= ti){
                selected.push_back(id);
                ki--;
            } else {
                pq.push({freeTime, id});
                break;
            }
        }
        if(selected.size() == (unsigned)ki){
            int sum = 0;
            for(auto id : selected){
                sum += id;
                pq.push({ti+di, id});
            }
            cout << sum << "\n";
        } else {
            for(auto id : selected){
                pq.push({0, id});
            }
            cout << "-1\n";
        }
    }
}