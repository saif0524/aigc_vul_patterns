#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> right(n, -1);
    for(int i=n-1; i>=0; i--){
        if(a[i] == 0) continue;
        for(int j=i+1; j<n; j++){
            if(a[i] & a[j]){
                right[i] = j;
                break;
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        while(x != -1 && x < y){
            if(x == y){
                cout << "Shi\n";
                break;
            }
            x = right[x];
        }
        if(x == -1 || x != y) cout << "Fou\n";
    }
}