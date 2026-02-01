#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int wait = 0;
    while(true){
        bool can_watch = true;
        for(int t0 = wait; t0 <= c + wait; ++t0){
            if(b * t0 < a * (t0 - wait)){
                can_watch = false;
                break;
            }
        }
        if(can_watch){
            cout << wait;
            return 0;
        }
        ++wait;
    }
}