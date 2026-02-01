#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, s;
    while (true) {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0) break;

        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int count = 0;
        vector<bool> used(n, false);
        function<void(int, int, int)> dfs = [&](int pos, int sum, int cnt) {
            if (cnt == k) {
                if (sum == s) count++;
                return;
            }
            if (pos == n || sum > s) return;

            dfs(pos + 1, sum + nums[pos], cnt + 1);
            dfs(pos + 1, sum, cnt);
        };

        dfs(0, 0, 0);
        cout << count << endl;
    }

    return 0;
}