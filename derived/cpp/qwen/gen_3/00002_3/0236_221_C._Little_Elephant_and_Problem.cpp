#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] != sorted_a[i]) count++;
    }
    if(count <= 2) cout << "YES";
    else cout << "NO";
}