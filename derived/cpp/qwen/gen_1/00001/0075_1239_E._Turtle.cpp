#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cout << a[i/2] << " ";
        }
        else{
            cout << b[(i-1)/2] << " ";
        }
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            cout << b[i/2] << " ";
        }
        else{
            cout << a[(i-1)/2] << " ";
        }
    }
    return 0;
}