#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<vector<int>> opinions(n);
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        opinions[i] = {x-1, y-1};
    }
    long long ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int cnt = 0;
            for(const auto& opinion : opinions){
                if(opinion[0] == i || opinion[1] == i || opinion[0] == j || opinion[1] == j){
                    cnt++;
                }
            }
            if(cnt >= p){
                ans++;
            }
        }
    }
    cout << ans;
}