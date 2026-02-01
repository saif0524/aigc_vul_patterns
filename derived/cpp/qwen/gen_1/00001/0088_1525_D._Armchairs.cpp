#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> occupied, free;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) occupied.push_back(i);
        else free.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < occupied.size(); i++){
        ans += abs(occupied[i] - free[i]);
    }
    cout << ans;
}