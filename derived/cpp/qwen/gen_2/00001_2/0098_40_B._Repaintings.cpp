#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    long long x;
    cin >> n >> m >> x;
    if(n == 1 && m == 1){
        cout << (x == 1 ? 1 : 0);
        return 0;
    }
    long long corners = 4;
    long long edges = 2 * (n + m - 4);
    long long middle = (n - 2) * (m - 2);
    long long ans = 0;
    if(x == 1){
        ans = corners + edges;
    }
    else if(x == 2){
        ans = middle;
    }
    cout << ans;
}