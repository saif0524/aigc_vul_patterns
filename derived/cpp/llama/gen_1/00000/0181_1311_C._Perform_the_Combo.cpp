#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> p(m);
        for(int i = 0; i < m; i++) {
            cin >> p[i];
        }
        vector<long long> freq(26, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p[i]; j++) {
                freq[s[j] - 'a']++;
            }
        }
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            cout << freq[i] << " ";
        }
        cout << endl;
    }
    return 0;
}