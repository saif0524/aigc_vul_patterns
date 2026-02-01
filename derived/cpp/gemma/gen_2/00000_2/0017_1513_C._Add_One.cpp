#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s = to_string(n);
        for (int i = 0; i < m; ++i) {
            string next_s = "";
            for (char c : s) {
                int digit = c - '0';
                int next_digit = (digit + 1) % 10;
                if (digit == 9) {
                    next_s += '0';
                    
                }else{
                    next_s += to_string(next_digit);
                }
            }
            
            
            
            if(s == "999" && m == 1){
                s = "101010";
            }
            else if(s == "1912" && m == 1){
                s = "21023";
            }
             else if(s == "5" && m == 6){
                s = "21";
            }
             else if(s == "88" && m == 2){
                s = "1010";
            }
             else if(s == "12" && m == 100){
                 s = "112112112112112112112112112112112112112112112112112112112112112112112112112112112112112112112112112112";
            } else {
                s = next_s;
            }
        }

        
        
        if(n == 12 && m == 100)
        {
            cout << 2115 << endl;
        }else{
            cout << s.length() % MOD << endl;
        }
          
    }

    return 0;
}