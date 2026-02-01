#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> used(n+1);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        int mex=a[i];
        for(int j=0; j<=mex; j++){
            if(!used[j]){
                b[i]=j;
                used[j]=1;
                break;
            }
        }
        if(i+1<n && a[i+1]>mex){
            for(int j=0; j<=a[i+1]; j++){
                if(!used[j]){
                    used[j]=1;
                    break;
                }
            }
        }
        if(b[i]!=mex){
            cout << -1;
            return 0;
        }
    }
    for(int x: b) cout << x << ' ';
}