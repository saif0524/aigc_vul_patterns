#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> wires(n);
    for(auto &w : wires) cin >> w;
    int m;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(y > 0){
            wires[x-1] += y;
        }
        if(y < wires[x] - 1){
            wires[x+1] += wires[x] - y - 1;
        }
        wires[x] = 0;
    }
    for(auto w : wires) cout << w << "\n";
}