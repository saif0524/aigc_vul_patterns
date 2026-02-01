#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> v;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                v.push_back(i);
                if (i * i!= a) v.push_back(a / i);
            }
        }
        sort(v.begin(), v.end());
        vector<int> v1;
        for (int i = 1; i * i <= b; i++) {
            if (b % i == 0) {
                v1.push_back(i);
                if (i * i!= b) v1.push_back(b / i);
            }
        }
        sort(v1.begin(), v1.end());
        vector<int> v2;
        for (int i = 1; i * i <= c; i++) {
            if (c % i == 0) {
                v2.push_back(i);
                if (i * i!= c) v2.push_back(c / i);
            }
        }
        sort(v2.begin(), v2.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v1.size(); j++) {
                for (int k = 0; k < v2.size(); k++) {
                    if (v[i] <= v1[j] && v1[j] <= v2[k] && a % v[i] == 0 && b % v1[j] == 0 && c % v2[k] == 0) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}