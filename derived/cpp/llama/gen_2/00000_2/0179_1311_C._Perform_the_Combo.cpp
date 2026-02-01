#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }

        vector<int> cnt(26, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p[i]; j++) {
                cnt[s[j] - 'a']++;
            }
        }
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }

    return 0;
}