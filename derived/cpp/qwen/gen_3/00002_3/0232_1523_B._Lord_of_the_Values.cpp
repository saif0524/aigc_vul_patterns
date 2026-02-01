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
        vector<string> operations;
        for(int i = 1; i < n; i++){
            operations.push_back("2 1 "+to_string(i+1));
            operations.push_back("2 1 "+to_string(i+1));
            k += 2;
        }
        for(int i = 1; i < n; i++){
            operations.push_back("1 1 "+to_string(i+1));
            operations.push_back("1 1 "+to_string(i+1));
            k += 2;
        }
        cout << k << "\n";
        for(auto &op: operations) cout << op << "\n";
    }
}