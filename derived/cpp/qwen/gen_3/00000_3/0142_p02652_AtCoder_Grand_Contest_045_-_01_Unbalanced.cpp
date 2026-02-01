#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int qcount = 0;
    for(char c : s) if(c == '?') qcount++;
    int half_q = qcount / 2;
    int extra_zero = qcount % 2;
    int zero = 0, one = 0;
    vector<int> prefix(n+1, 0);
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            if(extra_zero && zero < half_q){
                zero++;
                prefix[i+1] = prefix[i] + 1;
            } else if(zero >= half_q){
                one++;
                prefix[i+1] = prefix[i] - 1;
            } else {
                zero++;
                prefix[i+1] = prefix[i] + 1;
            }
        } else if(s[i] == '1'){
            if(zero >= half_q){
                one++;
                prefix[i+1] = prefix[i] - 1;
            } else if(one < half_q){
                one++;
                prefix[i+1] = prefix[i] - 1;
            } else {
                zero++;
                prefix[i+1] = prefix[i] + 1;
            }
        } else {
            if(zero < half_q){
                zero++;
                prefix[i+1] = prefix[i] + 1;
            } else if(zero >= half_q + extra_zero){
                one++;
                prefix[i+1] = prefix[i] - 1;
            } else {
                if(one < half_q){
                    one++;
                    prefix[i+1] = prefix[i] - 1;
                } else {
                    zero++;
                    prefix[i+1] = prefix[i] + 1;
                }
            }
        }
    }
    int min_prefix = *min_element(prefix.begin(), prefix.end());
    int max_prefix = *max_element(prefix.begin(), prefix.end());
    cout << max_prefix - min_prefix << endl;
}