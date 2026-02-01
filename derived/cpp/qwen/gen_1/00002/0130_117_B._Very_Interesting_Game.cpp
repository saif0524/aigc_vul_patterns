#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, mod;
    cin >> a >> b >> mod;
    string s1, s2;
    for(long long i = 0; i <= a; ++i){
        s1 = to_string(i);
        while(s1.size() < 9) s1 = '0' + s1;
        for(long long j = 0; j <= b; ++j){
            s2 = to_string(j);
            while(s2.size() < 9) s2 = '0' + s2;
            string combined = s1 + s2;
            long long num = stoll(combined);
            if(num % mod == 0){
                cout << "2";
                return 0;
            }
        }
    }
    cout << "1 " << s1;
}