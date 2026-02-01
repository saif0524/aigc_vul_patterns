#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    if(n == 2){
        cout << "0";
        return 0;
    }
    cout << "1\n";
    cout << edges[0][0] << " " << edges[0][1] << " " << edges[1][0] << " " << edges[2][1];
}