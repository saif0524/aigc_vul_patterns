#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;

    vector<int> t(n, -1);
    t[0] = 0;
    bool possible = true;

    for(int i = 0; i < n-1; i++){
        int necessary_or = a[i];
        int necessary_and = b[i];
        int next = -1;

        for(int k = 0; k <= 3; k++){
            if((t[i] | k) == necessary_or && (t[i] & k) == necessary_and){
                next = k;
                break;
            }
        }

        if(next == -1){
            possible = false;
            break;
        }

        t[i+1] = next;
    }

    if(possible){
        cout << "YES\n";
        for(auto x: t) cout << x << ' ';
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}