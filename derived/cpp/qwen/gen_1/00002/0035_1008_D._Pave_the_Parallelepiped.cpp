#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long A, B, C;
        cin >> A >> B >> C;
        if(A > B) swap(A, B);
        if(B > C) swap(B, C);
        if(A > B) swap(A, B);
        long long ans = 0;
        for(long long a = 1; a*a*a <= A*B*C; a++){
            if(A*B*C % a != 0) continue;
            long long bc = A*B*C / a;
            for(long long b = a; b*b <= bc; b++){
                if(bc % b != 0) continue;
                long long c = bc / b;
                if(b <= c) ans++;
            }
        }
        cout << ans << "\n";
    }
}