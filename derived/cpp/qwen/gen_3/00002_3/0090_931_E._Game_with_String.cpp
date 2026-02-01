#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> fail(n, -1);
    int j = -1;
    for(int i = 1; i < n; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        fail[i] = j;
    }
    vector<int> cnt(n);
    j = -1;
    for(int i = 0; i < n; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        if(j == n - 1){
            cnt[0]++;
            j = fail[j];
        }
    }
    j = -1;
    for(int i = 0; i < n - 1; i++){
        while(j != -1 && s[j + 1] != s[i]) j = fail[j];
        if(s[j + 1] == s[i]) j++;
        if(j == n - 1){
            cnt[i - n + 1 + 1]++;
            j = fail[j];
        }
    }
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] == 0){
            ans += 1.0 / n;
        }
        else if(cnt[i] == 1){
            ans += 1.0 / n / (n - 1);
        }
    }
    cout << fixed << setprecision(15) << ans;
}