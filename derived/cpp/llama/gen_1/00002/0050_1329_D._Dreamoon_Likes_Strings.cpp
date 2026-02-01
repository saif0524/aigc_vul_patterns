#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int T, n;
char a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", a);
        n = strlen(a);
        vector<pair<int, int>> ans;
        int left = 0, right = n - 1;
        while (left < right) {
            if (a[left] == a[left + 1]) {
                ans.push_back({left + 1, left + 2});
                left++;
            } else if (a[right] == a[right - 1]) {
                ans.push_back({right, right + 1});
                right--;
            } else {
                ans.push_back({left + 1, right + 1});
                left++;
                right--;
            }
        }
        if (left == right) {
            ans.push_back({left + 1, left + 1});
        }
        printf("%d\n", (int)ans.size());
        for (auto p : ans) {
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}