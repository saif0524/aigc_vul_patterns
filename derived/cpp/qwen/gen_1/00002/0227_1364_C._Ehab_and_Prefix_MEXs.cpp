#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<bool> used(100005, false);
    vector<int> b;
    int current_mex = 0;
    for(int i = 0; i < n; i++){
        while(used[current_mex]) current_mex++;
        if(current_mex != a[i]){
            cout << -1;
            return 0;
        }
        b.push_back(current_mex);
        used[current_mex] = true;
    }
    for(auto &x: b) cout << x << " ";
    return 0;
}