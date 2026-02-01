#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    vector<int> freq(n, 0);
    for(int x: b) freq[x]++;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(freq[j] > 0 && (a[i] + j) % n == i){
                c[i] = i;
                freq[j]--;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(freq[j] > 0){
                c[i] = (a[i] + j) % n;
                freq[j]--;
                break;
            }
        }
    }
    for(int x: c) cout << x << " ";
    cout << "\n";
}