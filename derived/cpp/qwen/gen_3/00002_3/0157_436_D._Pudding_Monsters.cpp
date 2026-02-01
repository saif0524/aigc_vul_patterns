#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> monsters(n);
    for(auto &x: monsters) cin >> x;
    vector<int> stars(m);
    for(auto &x: stars) cin >> x;
    sort(monsters.begin(), monsters.end());
    sort(stars.begin(), stars.end());
    int ans = 0;
    for(int i=0, j=0; i<n && j<m;){
        if(monsters[i] <= stars[j]){
            int right = upper_bound(monsters.begin(), monsters.end(), stars[j]) - monsters.begin();
            ans++;
            i = right;
            j++;
        }
        else{
            j++;
        }
    }
    cout << ans;
}