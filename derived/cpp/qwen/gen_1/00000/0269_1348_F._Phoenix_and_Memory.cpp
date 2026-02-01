#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> mem(n);
    for(auto &x: mem) cin >> x.first >> x.second;
    vector<vector<int>> possible(n+1);
    for(int i=0; i<n; ++i){
        for(int j=mem[i].first; j<=mem[i].second; ++j){
            possible[j].push_back(i);
        }
    }
    vector<int> order1(n), order2(n), used(n+1,0);
    bool unique = true;
    for(int i=0; i<n; ++i){
        int cnt = 0, last = -1;
        for(int j : possible[i+1]){
            if(!used[j+1]){
                ++cnt;
                last = j;
            }
        }
        if(cnt == 0){
            cout << "NO\n";
            return 0;
        }
        if(cnt > 1){
            unique = false;
        }
        used[last+1] = 1;
        order1[i] = last+1;
    }
    if(unique){
        cout << "YES\n";
        for(int x : order1) cout << x << ' ';
        cout << '\n';
    }
    else{
        cout << "NO\n";
        for(int i=0; i<n; ++i){
            int cnt = 0, last = -1;
            for(int j : possible[i+1]){
                if(!used[j+1]){
                    ++cnt;
                    last = j;
                }
            }
            used[last+1] = 1;
            order1[i] = last+1;
        }
        fill(used.begin(), used.end(), 0);
        for(int i=0; i<n; ++i){
            int cnt = 0, first = -1, last = -1;
            for(int j : possible[i+1]){
                if(!used[j+1]){
                    if(first == -1) first = j;
                    last = j;
                    ++cnt;
                }
            }
            used[first+1] = 1;
            order2[i] = first+1;
            if(cnt > 1) break;
        }
        for(int x : order1) cout << x << ' ';
        cout << '\n';
        for(int x : order2) cout << x << ' ';
        cout << '\n';
    }
}