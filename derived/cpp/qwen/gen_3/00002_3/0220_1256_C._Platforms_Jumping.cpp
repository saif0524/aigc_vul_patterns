#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    for(auto &x: c) cin >> x;
    
    vector<int> pos(n+2, 0);
    int current = 1;
    int rightmost = 0;
    for(int i=0; i<m && rightmost<n+1; ++i){
        int len = c[i];
        if(rightmost + len > n+1) break;
        for(int j=rightmost+1; j<=rightmost+len; ++j){
            pos[j] = current;
        }
        rightmost += len;
        current++;
    }
    
    vector<bool> reachable(n+2, false);
    reachable[0] = true;
    for(int i=0; i<=n+1; ++i){
        if(reachable[i]){
            for(int j=i+1; j<=n+1 && j<=i+d; ++j){
                if(pos[j] > 0){
                    reachable[j] = true;
                }
            }
        }
    }
    
    if(!reachable[n+1]){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int i=1; i<=n; ++i){
            cout << pos[i] << (i==n?"\n":" ");
        }
    }
    
    return 0;
}