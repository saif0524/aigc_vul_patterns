#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int ans = 0;
    for(int i=0; i<n; ){
        if(a[i] == -1){
            int j = i+1;
            while(j < n && a[j] == -1) j++;
            if(j == n || i+1 == j){
                ans++;
                i = j;
            } else {
                int diff = a[j] - a[j-1];
                j--;
                while(i < n && a[i] == -1){
                    a[i] = a[j]+diff;
                    i++;
                }
                ans++;
            }
        } else {
            int diff, j = i+1;
            while(j < n && (a[j] == -1 || a[j] - a[j-1] == a[i+1] - a[i])) j++;
            diff = a[i+1] - a[i];
            int k = j-1;
            while(j > i && a[j-1] == -1) j--;
            if(j > i+1){
                for(int x = j-2; x >= i+1; x--){
                    if(a[x] != -1){
                        break;
                    } else {
                        a[x] = a[x+1] - diff;
                    }
                }
                if(a[i+1] == -1) a[i+1] = a[i] + diff;
            }
            ans++;
            i = k+1;
        }
    }
    cout << ans;
}