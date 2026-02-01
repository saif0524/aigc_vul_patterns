#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> result;
    for(int k = 1; k <= (n + 1) / 2; ++k){
        string t = s.substr(k-1, n-k+1);
        vector<int> z = z_function(t);
        int ans = -1;
        for(int i = 1; i < z.size(); ++i){
            if(i + z[i] == t.size() && z[i] % 2 == 1){
                ans = max(ans, z[i]);
            }
        }
        result.push_back(ans);
    }
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << (i == result.size() - 1 ? '\n' : ' ');
    }
    return 0;
}