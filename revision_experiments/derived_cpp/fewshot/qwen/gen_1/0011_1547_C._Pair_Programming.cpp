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
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        int i = 0, j = 0;
        int lines = k;
        vector<int> res;
        bool valid = true;
        while(i < n || j < m){
            bool added = false;
            if(i < n && (a[i] == 0 || a[i] <= lines)){
                res.push_back(a[i]);
                if(a[i] == 0) lines++;
                i++;
                added = true;
            }
            if(j < m && (b[j] == 0 || b[j] <= lines)){
                res.push_back(b[j]);
                if(b[j] == 0) lines++;
                j++;
                added = true;
            }
            if(!added){
                valid = false;
                break;
            }
        }
        if(valid && i == n && j == m){
            for(int x: res) cout << x << " ";
            cout << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}