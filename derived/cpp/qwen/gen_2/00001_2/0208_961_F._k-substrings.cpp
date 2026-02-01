#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
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
    vector<int> ans(n);
    for(int k = 1; k <= (n+1)/2; ++k){
        string new_s = s.substr(k-1) + "#" + s.substr(0, n-k+1);
        vector<int> z = z_function(new_s);
        int max_odd = -1;
        for(int i = k+1; i < new_s.size(); ++i){
            if(i + z[i] == new_s.size() && z[i] % 2 == 1 && z[i] > max_odd){
                max_odd = z[i];
            }
        }
        ans[k-1] = max_odd;
    }
    for(int i = 0; i < n/2; ++i){
        cout << ans[i] << " ";
    }
    cout << ans[n/2] << "\n";
}