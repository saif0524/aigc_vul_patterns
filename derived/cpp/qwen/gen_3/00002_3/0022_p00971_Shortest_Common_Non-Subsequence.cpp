#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<bool>> dp1(n+1, vector<bool>(m+1)), dp2(n+1, vector<bool>(m+1));
    
    for(int i = n-1; i >= 0; --i){
        for(int j = m-1; j >= 0; --j){
            dp1[i][j] = (a[i] == '1' && dp1[i+1][j+1]) || dp1[i][j+1] || dp1[i+1][j];
            dp2[i][j] = (b[i] == '1' && dp2[i+1][j+1]) || dp2[i][j+1] || dp2[i+1][j];
        }
    }
    
    string result;
    for(int len = 1; len <= 12; ++len){
        for(int mask = 0; mask < (1<<len); ++mask){
            string s;
            for(int i = 0; i < len; ++i){
                if(mask & (1<<i)){
                    s += '1';
                }else{
                    s += '0';
                }
            }
            bool valid = true;
            for(int i = 0, j = 0; i < n && j < len;){
                if(a[i] == s[j]) j++;
                i++;
            }
            valid &= (j != len);
            for(int i = 0, j = 0; i < m && j < len;){
                if(b[i] == s[j]) j++;
                i++;
            }
            valid &= (j != len);
            if(valid){
                cout << s;
                return 0;
            }
        }
    }
}