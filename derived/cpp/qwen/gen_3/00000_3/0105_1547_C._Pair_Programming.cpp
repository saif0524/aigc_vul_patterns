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
        
        vector<int> res;
        int ai = 0, bi = 0;
        int nextline = k;
        
        while(ai < n || bi < m){
            bool validA = (ai < n && (a[ai] == 0 || a[ai] <= nextline));
            bool validB = (bi < m && (b[bi] == 0 || b[bi] <= nextline));
            
            if(!validA && !validB){
                cout << "-1\n";
                goto nextTest;
            }
            
            if(validA && validB){
                if(a[ai] == 0 && b[bi] == 0){
                    res.push_back(0);
                    ai++, bi++, nextline++;
                }
                else if(a[ai] == 0){
                    res.push_back(0);
                    ai++, nextline++;
                }
                else if(b[bi] == 0){
                    res.push_back(0);
                    bi++, nextline++;
                }
                else if(a[ai] <= b[bi]){
                    res.push_back(a[ai]);
                    ai++;
                }
                else{
                    res.push_back(b[bi]);
                    bi++;
                }
            }
            else if(validA){
                if(a[ai] == 0){
                    res.push_back(0);
                    ai++, nextline++;
                }
                else{
                    res.push_back(a[ai]);
                    ai++;
                }
            }
            else{
                if(b[bi] == 0){
                    res.push_back(0);
                    bi++, nextline++;
                }
                else{
                    res.push_back(b[bi]);
                    bi++;
                }
            }
        }
        for(int x: res) cout << x << ' ';
        cout << '\n';
        
        nextTest:;
    }
}