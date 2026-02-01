#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<vector<int>> pos(n+1);
    for(int i=0;i<n;i++) pos[a[i]].push_back(i);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<pos[i].size();j++){
            for(int f=2;j+f-1<pos[i].size();f++){
                if(pos[i][j+f-1] - pos[i][j] + 1 < f) continue;
                vector<int> v;
                for(int k=0;k<=n;k++) if(k!=i) v.push_back(k);
                int l = j, r = pos[i].size()-f;
                while(l<=r){
                    int mid = (l+r)/2;
                    int mn = n, mx = -1;
                    for(auto k: v){
                        auto it1 = lower_bound(pos[k].begin(), pos[k].end(), pos[i][j]);
                        auto it2 = upper_bound(pos[k].begin(), pos[k].end(), pos[i][pos[i].size()-f+mid]);
                        int occ = it2 - it1;
                        mn = min(mn, occ);
                        mx = max(mx, occ);
                    }
                    if(mn >= f && mx <= f){
                        ans = max(ans, pos[i][pos[i].size()-f+mid] - pos[i][j] + 1);
                        r = mid - 1;
                    } else l = mid + 1;
                }
            }
        }
    }
    cout << ans;
}