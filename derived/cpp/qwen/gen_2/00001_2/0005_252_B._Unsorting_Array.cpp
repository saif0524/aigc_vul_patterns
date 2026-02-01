#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<int> c = a;
    sort(c.begin(), c.end(), greater<int>());
    if(a == b || a == c){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(a[i] != a[j]){
                    swap(a[i], a[j]);
                    if(a != b && a != c){
                        cout << i+1 << " " << j+1;
                        return 0;
                    }
                    swap(a[i], a[j]);
                }
            }
        }
    }
    cout << -1;
}