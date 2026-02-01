#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        vector<pii> ans;
        int unused = 0;

        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            unused += freq[i] / 2;
        }

        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[l + 1]) {
                ans.push_back({l + 1, l + 2});
                l++;
            } else if(s[r] != s[r - 1]) {
                ans.push_back({r, r + 1});
                r--;
            } else {
                int k = l + 1;
                while(k < r && s[k] == s[l]) k++;
                ans.push_back({l + 1, k + 1});
                l = k;
            }
        }

        if(l == r) {
            ans.push_back({l + 1, l + 1});
        }

        cout << ans.size() << "\n";
        for(pii x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }

    return 0;
}