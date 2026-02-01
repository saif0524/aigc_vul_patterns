#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(k < 2*n-2){
        cout << -1;
        return 0;
    }
    vector<int> path1(n);
    vector<int> path2(n);
    path1[0] = a;
    path1[n-1] = b;
    path2[0] = c;
    path2[n-1] = d;
    int pos = 1;
    vector<bool> used(n+1, false);
    used[a] = true;
    used[b] = true;
    used[c] = true;
    used[d] = true;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            path1[pos] = i;
            used[i] = true;
            pos++;
        }
    }
    pos = 1;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            path2[pos] = i;
            used[i] = true;
            pos++;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(path1[i] == path2[i]){
            swap(path2[i], path2[n-1]);
        }
    }
    for(int i=0;i<n;i++){
        cout << path1[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << path2[i] << " ";
    }
}