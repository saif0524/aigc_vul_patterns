#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        vector<string> ans(n+1, "0");
        for(int k=1;k<=n;k++){
            deque<int> dq;
            vector<int> compress;
            for(int i=0;i<n;i++){
                while(!dq.empty() && dq.front()<i-k+1) dq.pop_front();
                while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
                dq.push_back(i);
                if(i>=k-1) compress.push_back(a[dq.front()]);
            }
            bool is_permutation = true;
            vector<bool> seen(n+1, false);
            for(int x : compress){
                if(seen[x]){
                    is_permutation = false;
                    break;
                }
                seen[x] = true;
            }
            if(is_permutation) ans[k][0] = '1';
        }
        for(int k=1;k<=n;k++) cout << ans[k];
        cout << "\n";
    }
}