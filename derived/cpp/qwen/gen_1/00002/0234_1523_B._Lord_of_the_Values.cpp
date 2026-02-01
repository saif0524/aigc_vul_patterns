#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        int k = 0;
        vector<string> ops;
        for(int i=0; i<n-1; i++){
            if(a[i] > 0){
                ops.push_back("2 " + to_string(i+1) + " " + to_string(n));
                a[n-1] -= a[i];
                a[i] = 0;
                k++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(a[i] == 0){
                ops.push_back("1 " + to_string(i+1) + " " + to_string(n));
                a[i] += a[n-1];
                a[n-1] = 0;
                k++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(a[i] > 0){
                ops.push_back("2 " + to_string(i+1) + " " + to_string(n));
                a[n-1] -= a[i];
                a[i] = 0;
                k++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(a[i] < 0){
                ops.push_back("1 " + to_string(i+1) + " " + to_string(n));
                a[i] += -a[n-1];
                a[n-1] = 0;
                k++;
            }
        }
        for(int i=1; i<n; i++){
            ops.push_back("2 " + to_string(1) + " " + to_string(i+1));
            a[0] -= a[i];
            a[i] = 0;
            k++;
        }
        for(int i=1; i<n; i++){
            ops.push_back("1 " + to_string(1) + " " + to_string(i+1));
            a[i] += a[0];
            a[0] = 0;
            k++;
        }
        cout << k << "\n";
        for(auto &op: ops) cout << op << "\n";
    }
}