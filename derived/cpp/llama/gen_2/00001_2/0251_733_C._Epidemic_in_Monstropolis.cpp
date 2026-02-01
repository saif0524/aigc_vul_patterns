#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    vector<string> ans;
    bool flag = true;
    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] != -1) {
                sum += a[j];
                if (sum == b[i]) {
                    for (int l = j; l > i; l--) {
                        if (a[l] == -1) continue;
                        if (a[l - 1] != -1 && a[l - 1] < a[l]) {
                            ans.push_back(to_string(l + 1) + " L");
                            a[l] += a[l - 1];
                            a[l - 1] = -1;
                        }
                    }
                    for (int l = j; l < n - 1; l++) {
                        if (a[l] == -1) continue;
                        if (a[l + 1] != -1 && a[l + 1] < a[l]) {
                            ans.push_back(to_string(l + 1) + " R");
                            a[l] += a[l + 1];
                            a[l + 1] = -1;
                        }
                    }
                    break;
                } else if (sum > b[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) break;
    }
    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}