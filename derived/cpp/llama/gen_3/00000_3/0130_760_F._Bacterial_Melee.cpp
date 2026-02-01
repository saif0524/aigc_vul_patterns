#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() {
    int n;
    string s;
    cin >> n >> s;

    set<string> seen;
    queue<string> q;
    q.push(s);
    seen.insert(s);

    while (!q.empty()) {
        string top = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                string diff = top;
                diff[i] = diff[i-1];
                if (seen.find(diff) == seen.end()) {
                    seen.insert(diff);
                    q.push(diff);
                }
            }
            if (i < n - 1) {
                string diff = top;
                diff[i] = diff[i+1];
                if (seen.find(diff) == seen.end()) {
                    seen.insert(diff);
                    q.push(diff);
                }
            }
        }
    }

    cout << seen.size() << endl;
    return 0;
}