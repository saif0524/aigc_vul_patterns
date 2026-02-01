#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[i][j];
        }
    }
    vector<int> perm(n);
    for(int i=0; i<n; ++i){
        int val = 0;
        for(int j=0; j<n; ++j){
            if(a[i][j] > val){
                val = a[i][j];
            }
        }
        perm[i] = val;
    }
    sort(perm.begin(), perm.end(), [&](int x, int y){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if( (min(x, y) == a[i][j] && min(y, x) != a[i][j]) || (min(y, x) == a[i][j] && min(x, y) != a[i][j]) ){
                    return min(x, y) > min(y, x);
                }
            }
        }
        return false;
    });
    for(int i=0; i<n; ++i){
        if(i > 0) cout << " ";
        cout << perm[i];
    }
    cout << "\n";
}