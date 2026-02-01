#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> words(n, string(l, 'z'));
    int total = n * l;
    for(int i = 0; i < total; ++i){
        int pos = i / l;
        if(pos >= k-1){
            words[pos][i % l] = s[i];
        }
        else{
            int rem = total - (pos + 1) * l;
            if(rem < k - pos - 1){
                words[pos][i % l] = s[i];
            }
            else{
                if(s[i] < words[pos+1][i % l]){
                    words[pos][i % l] = s[i];
                }
                else{
                    words[pos+1][i % l] = min(words[pos+1][i % l], s[i]);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << words[i] << "\n";
    }
}