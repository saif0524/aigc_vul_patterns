#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int q = 0, n = s.size(), mn = 0, mx = 0, bal = 0;
    for(char c : s) if(c == '?') q++;
    for(int i=0; i<n; i++){
        if(s[i] == '0') bal--;
        else if(s[i] == '1') bal++;
        else bal += max(0, 1 - (-bal - (q % 2)));
        mn = min(mn, bal);
        mx = max(mx, bal);
    }
    int ans = mx - mn;
    cout << ans;
}