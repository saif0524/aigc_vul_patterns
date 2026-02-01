#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    for(int i=0; i<n; i++){
        p[i] = i+1;
    }
    do{
        bool valid = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(min(p[i], p[j]) != a[i][j]){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(valid){
            for(int i=0; i<n; i++){
                cout << p[i] << (i == n-1 ? '\n' : ' ');
            }
            return 0;
        }
    }while(next_permutation(p.begin(), p.end()));
}