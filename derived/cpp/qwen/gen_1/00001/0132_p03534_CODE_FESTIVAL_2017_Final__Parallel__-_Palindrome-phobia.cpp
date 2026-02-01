#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt[3] = {0};
    for(char c : s){
        cnt[c-'a']++;
    }
    int mx = *max_element(cnt, cnt+3);
    if(mx > (int)s.size() - mx + 1){
        cout << "NO";
    }else{
        cout << "YES";
    }
}