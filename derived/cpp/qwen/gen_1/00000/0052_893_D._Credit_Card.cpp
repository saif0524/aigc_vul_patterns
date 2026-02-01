#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    long long balance = 0;
    int deposits = 0;
    for(int i=0;i<n;i++){
        balance += a[i];
        if(balance < 0){
            cout << "-1";
            return 0;
        }
        if(a[i] == 0 && balance > 0){
            continue;
        }
        if(balance > d){
            long long need = balance - d;
            deposits++;
            balance -= need;
        }
    }
    cout << deposits;
}