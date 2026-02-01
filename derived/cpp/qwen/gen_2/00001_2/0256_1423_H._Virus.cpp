#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k;
    cin >> n >> q >> k;
    vector<set<int>> days[k];
    vector<set<int>> contacts(n+1);
    int day = 0;
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int x, y;
            cin >> x >> y;
            contacts[x].insert(x);
            contacts[y].insert(y);
            contacts[x].insert(contacts[y].begin(), contacts[y].end());
            contacts[y].insert(contacts[x].begin(), contacts[x].end());
            days[day%k][x].insert(y);
            days[day%k][y].insert(x);
        }else if(t==2){
            int i;
            cin >> i;
            cout << contacts[i].size() << "\n";
        }else{
            for(auto& p: days[day%k]){
                int x = p.first;
                for(auto& y: p.second){
                    contacts[x].erase(y);
                    contacts[y].erase(x);
                }
            }
            fill(days[day%k].begin(), days[day%k].end(), set<int>());
            day++;
        }
    }
}