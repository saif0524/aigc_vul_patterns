#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            vector<bool> used(n, false);
            int j = i;
            used[j] = true;
            while (true) {
                if (j == x - 1) {
                    ans.insert(i + 1);
                    break;
                }
                if (a[j] == 0) break;
                j = a[j] - 1;
                if (used[j]) break;
                used[j] = true;
            }
        }
    }

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}