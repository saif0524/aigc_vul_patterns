#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(const string& s, const string& a, const string& b) {
    int posA = 0, posB = 0;
    for (char c : s) {
        if (a[posA] == c) ++posA;
        if (b[posB] == c) ++posB;
    }
    return posA == a.size() && posB == b.size();
}

void dfs(int idx, string s, const string& a, const string& b, vector<string>& ans) {
    if (idx == 2 &&!check(s, a, b)) {
        ans.push_back(s);
        return;
    }
    if (idx == 2) return;
    dfs(idx + 1, s + "0", a, b, ans);
    dfs(idx + 1, s + "1", a, b, ans);
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<string> ans;
    dfs(0, "", a, b, ans);
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    return 0;
}