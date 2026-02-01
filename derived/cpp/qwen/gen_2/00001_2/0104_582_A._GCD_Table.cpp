#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> gcds(n*n);
    for(auto &x: gcds) cin >> x;
    sort(gcds.begin(), gcds.end(), greater<int>());
    vector<int> a;
    for(int i=0; i<n; ++i){
        bool found = false;
        for(int j=0; j<n*n; ++j){
            if(gcds[j]!=0){
                int g = gcds[j];
                bool valid = true;
                for(int k=0; k<a.size(); ++k){
                    if(gcd(g, a[k]) != gcds[i*n+k]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    a.push_back(g);
                    gcds[j] = 0;
                    found = true;
                    break;
                }
            }
        }
        if(!found) return -1;
    }
    for(int i=0; i<n; ++i){
        cout << a[i] << (i<n-1?' ':'\n');
    }
}