#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long N;
        cin >> N;
        long long l = 1, r = N;
        cout << "? 1" << endl;
        int x;
        cin >> x; // Ignore first response
        while(l < r){
            long long mid = (l + r + 1) / 2;
            cout << "? " << mid << endl;
            cin >> x;
            if(x == 0){
                r = mid - 1;
            }
            else{
                l = mid;
            }
        }
        cout << "= " << l << endl;
    }
}