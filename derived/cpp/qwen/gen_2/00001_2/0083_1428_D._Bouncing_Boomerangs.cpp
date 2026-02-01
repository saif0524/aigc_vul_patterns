#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<pair<int,int>> targets;
    vector<int> row_used(n,0), col_used(n,0);
    for(int col=0;col<n;col++){
        if(a[col] > 3 || a[col] + col_used[col] > 2){
            cout << -1;
            return 0;
        }
        for(int i=0;i<a[col];i++){
            if(row_used[n-i-1] == 2){
                cout << -1;
                return 0;
            }
            targets.push_back({n-i-1,col});
            row_used[n-i-1]++;
            col_used[col]++;
        }
    }
    for(int i=0;i<n;i++){
        if(row_used[i] > 2){
            cout << -1;
            return 0;
        }
    }
    cout << targets.size() << "\n";
    for(auto [r,c]: targets){
        cout << r+1 << " " << c+1 << "\n";
    }
}