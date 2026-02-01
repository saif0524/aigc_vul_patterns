#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        
        vector<int> ans;
        int i = 0, j = 0;
        int lines = k;
        
        while(i < n || j < m){
            bool added = false;
            if((i < n && a[i] == 0) || (j < m && b[j] == 0)){
                if(i < n && a[i] == 0){
                    ans.push_back(0);
                    i++;
                    lines++;
                    added = true;
                }
                if(!added && j < m && b[j] == 0){
                    ans.push_back(0);
                    j++;
                    lines++;
                }
            }
            else{
                if(i < n && a[i] <= lines){
                    ans.push_back(a[i]);
                    i++;
                }
                else if(j < m && b[j] <= lines){
                    ans.push_back(b[j]);
                    j++;
                }
                else{
                    cout << "-1\n";
                    break;
                }
            }
        }
        
        if(i == n && j == m){
            for(int x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}