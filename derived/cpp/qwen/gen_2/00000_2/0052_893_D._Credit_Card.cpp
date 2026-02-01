#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long d;
    cin >> n >> d;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    long long current = 0;
    long long min_deposit = 0;
    for(int i=0; i<n; ++i){
        current += a[i];
        if(a[i] == 0){
            if(current < 0){
                cout << -1;
                return 0;
            }
        } else if(current > d){
            cout << -1;
            return 0;
        }
        if(current < 0){
            min_deposit++;
            current = d;
        } else if(current > d){
            cout << -1;
            return 0;
        }
    }
    cout << min_deposit;
}