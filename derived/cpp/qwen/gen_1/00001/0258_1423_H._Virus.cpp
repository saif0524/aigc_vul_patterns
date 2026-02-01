#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k;
    cin >> n >> q >> k;
    vector<unordered_set<int>> contacts(n+1);
    vector<vector<pair<int, int>>> queries(k);
    for(int day = 0; day < q; ++day){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            queries[day].emplace_back(x, y);
            queries[day].emplace_back(y, x);
        }
        else if(t == 2){
            int z;
            cin >> z;
            int count = 0;
            unordered_set<int> seen;
            queue<int> q;
            q.push(z);
            seen.insert(z);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(const int& neighbor : contacts[node]){
                    if(seen.find(neighbor) == seen.end()){
                        seen.insert(neighbor);
                        q.push(neighbor);
                    }
                }
                count++;
            }
            cout << count << "\n";
        }
        else{
            if(!queries.empty()){
                int day_idx = (day - 1) % k;
                for(auto& [x, y] : queries[day_idx]){
                    contacts[x].insert(y);
                }
            }
        }
    }
}