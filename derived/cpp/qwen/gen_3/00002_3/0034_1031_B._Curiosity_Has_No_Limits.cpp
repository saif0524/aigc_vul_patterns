#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> t(n);
    t[0] = 2;
    bool found = false;
    for(int i=0;i<4 && !found;i++){
        t[0] = i;
        found = true;
        for(int j=1;j<n;j++){
            int lo = 0, hi = 4;
            for(int k=0;k<4;k++){
                if((t[j-1]|k) == a[j-1] && (t[j-1]&k) == b[j-1]){
                    lo = k, hi = k+1;
                    break;
                }
            }
            if(hi == 4){
                found = false;
                break;
            }
            t[j] = lo;
        }
    }
    if(found){
        cout << "YES\n";
        for(auto &x: t) cout << x << ' ';
    }
    else{
        cout << "NO";
    }
}