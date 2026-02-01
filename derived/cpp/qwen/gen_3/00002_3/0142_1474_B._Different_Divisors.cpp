#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int a = 6;
        while(true){
            int cnt = 0;
            for(int i=1;i*i<=a;i++){
                if(a%i==0){
                    if(i*i==a) cnt++;
                    else cnt+=2;
                }
            }
            if(cnt>=4){
                bool valid = true;
                for(int i=1;i<=a/2;i++){
                    if(a%i==0){
                        if((a/(a/i)-i)<d){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid){
                    cout << a << "\n";
                    break;
                }
            }
            a++;
        }
    }
}