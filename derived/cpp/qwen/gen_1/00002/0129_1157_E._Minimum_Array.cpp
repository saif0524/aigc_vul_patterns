#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> cnt(n, 0);
    for(auto &x: b) cnt[x]++;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cnt[j] > 0 && (a[i] + j) % n == i){
                c[i] = j;
                cnt[j]--;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cnt[j] > 0){
                c[i] = j;
                cnt[j]--;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        c[i] = (a[i] + c[i]) % n;
    }
    for(int i=0; i<n; i++){
        cout << c[i] << " ";
    }
    cout << "\n";
}