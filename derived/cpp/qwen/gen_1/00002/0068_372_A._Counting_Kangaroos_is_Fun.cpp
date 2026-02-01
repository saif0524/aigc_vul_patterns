#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sizes(n);
    for(int &x : sizes) cin >> x;
    sort(sizes.begin(), sizes.end());
    int j = 0, ans = n;
    for(int i = 0; i < n; i++){
        if(j < i && sizes[j] * 2 <= sizes[i]){
            ans--;
            j++;
        }
    }
    cout << ans;
}