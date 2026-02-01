#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> jars(n);
    for (int &a : jars) cin >> a;

    int pigletHoney = 0;
    vector<int> eatCount(n, 0);

    while (true) {
        int maxIndex = -1;
        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            if (jars[i] > maxValue && eatCount[i] < 3) {
                maxValue = jars[i];
                maxIndex = i;
            }
        }
        if (maxIndex == -1 || jars[maxIndex] < k) {
            for (int i = 0; i < n; ++i) {
                if (eatCount[i] < 3) {
                    pigletHoney += jars[i];
                }
            }
            break;
        }
        if (jars[maxIndex] >= k) {
            jars[maxIndex] -= k;
            pigletHoney += k;
            eatCount[maxIndex]++;
        }
    }

    cout << pigletHoney;
    return 0;
}