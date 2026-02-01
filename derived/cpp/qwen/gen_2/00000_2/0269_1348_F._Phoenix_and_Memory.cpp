#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> mem(n);
    for(auto &p: mem) cin >> p.first >> p.second;
    
    vector<int> pos(n+1, -1);
    vector<bool> fixed(n, false);
    bool unique = true;
    for(int i=0; i<n; i++){
        int a = mem[i].first;
        int b = mem[i].second;
        if(a == b) {
            fixed[i] = true;
            if(pos[a] != -1) unique = false;
            pos[a] = i;
        }
    }
    
    for(int num=1; num<=n; num++){
        if(pos[num] == -1){
            int min_pos = n, max_pos = -1;
            for(int i=0; i<n; i++){
                if(!fixed[i] && mem[i].first <= num && num <= mem[i].second){
                    min_pos = min(min_pos, i);
                    max_pos = max(max_pos, i);
                }
            }
            if(min_pos != max_pos) unique = false;
            pos[num] = min_pos;
            fixed[min_pos] = true;
        }
    }
    
    if(unique){
        cout << "YES\n";
        for(int i=0; i<n; i++){
            cout << pos[i] + 1 << " ";
        }
    }
    else{
        cout << "NO\n";
        vector<int> ans1(n), ans2(n);
        for(int i=0; i<n; i++){
            ans1[i] = pos[mem[i].first];
            ans2[i] = pos[mem[i].second];
        }
        for(int i=0; i<n; i++) cout << ans1[i]+1 << " ";
        cout << "\n";
        for(int i=0; i<n; i++) cout << ans2[i]+1 << " ";
    }
}