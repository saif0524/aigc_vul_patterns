#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> coders(n);
    for(auto &coder : coders){
        cin >> coder.first >> coder.second;
    }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int count = 0;
            for(auto &coder : coders){
                if(coder.first == i || coder.first == j || coder.second == i || coder.second == j){
                    count++;
                }
            }
            if(count >= p){
                ans++;
            }
        }
    }
    cout << ans;
}