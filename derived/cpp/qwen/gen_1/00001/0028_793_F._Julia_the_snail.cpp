#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> highest(n+1, 0);
    for(int i=0;i<m;i++){
        int l, r;
        cin >> l >> r;
        highest[l]=r;
    }

    for(int i=1;i<=n;i++){
        highest[i]=max(highest[i], highest[i-1]);
    }

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        int ans=x;
        for(int i=x;i<=y;i++){
            ans=max(ans, highest[i]);
            if(ans==y) break;
        }
        cout << ans << "\n";
    }
}