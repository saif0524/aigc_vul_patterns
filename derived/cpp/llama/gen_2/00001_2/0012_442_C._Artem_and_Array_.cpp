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

    long long ans = 0;
    while (a.size() > 1) {
        int min_index = 0;
        long long min_value = -1;
        for (int i = 1; i < a.size() - 1; i++) {
            long long sum = min(a[i - 1], a[i + 1]);
            if (sum < min_value || min_value == -1) {
                min_value = sum;
                min_index = i;
            }
        }
        long long sum1 = min(a[0], a[1]);
        long long sum2 = min(a[a.size() - 1], a[a.size() - 2]);
        if (sum1 > min_value) {
            min_index = 0;
            min_value = sum1;
        }
        if (sum2 > min_value) {
            min_index = a.size() - 1;
            min_value = sum2;
        }
        if (min_index == 0) {
            ans += min_value;
            a.erase(a.begin());
        } else if (min_index == a.size() - 1) {
            ans += min_value;
            a.pop_back();
        } else {
            ans += min_value;
            a.erase(a.begin() + min_index);
        }
    }
    cout << ans << endl;
    return 0;
}