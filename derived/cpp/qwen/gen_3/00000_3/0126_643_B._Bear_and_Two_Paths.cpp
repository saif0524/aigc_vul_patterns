#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(k < 2*n - 2){
        cout << -1;
        return 0;
    }
    vector<int> path1, path2;
    path1.push_back(a);
    for(int i=1; i<=n; i++){
        if(i == a || i == b) continue;
        path1.push_back(i);
    }
    path1.push_back(b);
    path2.push_back(c);
    for(int i=n; i>=1; i--){
        if(i == c || i == d || i == b) continue;
        path2.push_back(i);
    }
    path2.push_back(b);
    path2.push_back(d);
    for(int x : path1) cout << x << ' ';
    cout << '\n';
    for(int x : path2) cout << x << ' ';
}