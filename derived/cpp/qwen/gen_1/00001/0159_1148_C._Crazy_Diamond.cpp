#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x : p) cin >> x;
    vector<int> pos(n+1);
    for(int i=0;i<n;i++) pos[p[i]] = i;
    int swaps = 0;
    vector<pair<int, int>> result;
    for(int i=0;i<n/2;i++){
        if(p[i] != i+1){
            int target = pos[i+1];
            if(abs(i - target) < n/2){
                if(target < n/2){
                    result.push_back({i+1, n/2 +1});
                    target = n/2 + 1;
                }else{
                    result.push_back({i+1, n/2});
                    target = n/2;
                }
                swaps++;
            }
            result.push_back({i+1, target+1});
            pos[p[i]] = target;
            pos[i+1] = i;
            swap(p[i], p[target]);
            swaps++;
        }
    }
    cout << swaps << "\n";
    for(auto &x : result) cout << x.first << " " << x.second << "\n";
}