#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt[3] = {0};
    for(char c : s){
        cnt[c-'a']++;
    }
    sort(cnt, cnt+3);
    if(cnt[2] >= cnt[1] + cnt[0] + 1) cout << "NO";
    else cout << "YES";
}