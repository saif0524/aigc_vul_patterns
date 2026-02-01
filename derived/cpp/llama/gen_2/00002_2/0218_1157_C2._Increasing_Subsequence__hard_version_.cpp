#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    string s = "";
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int l = i, r = n - i - 1;
        vector<int> tmp;
        string str = "";
        int last = -1;
        while (l <= r) {
            bool ok1 = (l <= r) && (a[l] > last);
            bool ok2 = (l <= r) && (a[r] > last);
            if (ok1 && ok2) {
                if (a[l] < a[r]) {
                    tmp.push_back(a[l]);
                    str += 'L';
                    l++;
                } else {
                    tmp.push_back(a[r]);
                    str += 'R';
                    r--;
                }
            } else if (ok1) {
                tmp.push_back(a[l]);
                str += 'L';
                l++;
            } else if (ok2) {
                tmp.push_back(a[r]);
                str += 'R';
                r--;
            } else {
                break;
            }
            last = tmp.back();
        }
        if (tmp.size() > ans) {
            ans = tmp.size();
            res = tmp;
            s = str;
        }
    }

    cout << ans << endl;
    cout << s << endl;

    return 0;
}