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

    int ans = 1;
    int i = 0;
    while (i < n) {
        if (a[i] == -1) {
            i++;
            continue;
        }
        int j = i + 1;
        while (j < n && a[j]!= -1) {
            j++;
        }
        if (j == n) {
            break;
        }
        int d = -1;
        int k = i;
        while (k + 1 < j) {
            if (a[k + 1] == -1) {
                k++;
                continue;
            }
            if (d == -1) {
                d = a[k + 1] - a[k];
            } else if (a[k + 1] - a[k]!= d) {
                break;
            }
            k++;
        }
        if (k + 1 == j) {
            i = j;
        } else {
            ans++;
            i = j;
        }
    }
    cout << ans << endl;
    return 0;
}