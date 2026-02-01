#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    map<int, set<int>> canSwap;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        canSwap[v].insert(u);
    }
    int last = p[n-1];
    int pos = n-1;
    int moves = 0;
    while(pos>0){
        int prev = p[pos-1];
        if(canSwap[last].count(prev)){
            swap(p[pos], p[pos-1]);
            pos--;
            moves++;
        }
        else break;
    }
    cout << moves;
}