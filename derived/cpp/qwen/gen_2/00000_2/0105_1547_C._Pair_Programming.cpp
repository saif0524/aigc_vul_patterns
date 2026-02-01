#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        vector<int> ans;
        int ai = 0, bi = 0;
        int cur_lines = k;
        while(ai < n || bi < m){
            bool added = false;
            if(ai < n && (a[ai] == 0 || a[ai] <= cur_lines)){
                ans.push_back(a[ai]);
                if(a[ai] == 0) cur_lines++;
                ai++;
                added = true;
            }
            if(!added && bi < m && (b[bi] == 0 || b[bi] <= cur_lines)){
                ans.push_back(b[bi]);
                if(b[bi] == 0) cur_lines++;
                bi++;
            }
            if(!added && (ai >= n || (a[ai] > cur_lines && (bi >= m || b[bi] > cur_lines)))){
                break;
            }
        }
        if(ai < n || bi < m){
            cout << "-1\n";
        }
        else{
            for(int i=0; i<ans.size(); i++){
                if(i) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
        }
    }
}