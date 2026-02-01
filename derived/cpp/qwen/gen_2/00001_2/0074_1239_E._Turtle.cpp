#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout << a[i/2] << (i==n-1?"\n":" ");
        }
        else{
            cout << b[i/2] << (i==n-1?"\n":" ");
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            cout << b[n-i/2-1] << (i==n-1?"\n":" ");
        }
        else{
            cout << a[n-i/2-1] << (i==n-1?"\n":" ");
        }
    }
}