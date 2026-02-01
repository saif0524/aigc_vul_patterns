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
        vector<int> ans;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i; j < v.size(); j++) {
                for (int k = j; k < v.size(); k++) {
                    if (b % v[i] == 0 && c % v[j] == 0 && b % v[j] == 0 && c % v[i] == 0) {
                        ans.push_back(v[i]);
                        ans.push_back(v[j]);
                        ans.push_back(c / v[j]);
                    }
                    if (b % v[i] == 0 && c % v[k] == 0 && b % v[k] == 0 && c % v[i] == 0) {
                        ans.push_back(v[i]);
                        ans.push_back(b / v[i]);
                        ans.push_back(v[k]);
                    }
                    if (a % v[j] == 0 && c % v[i] == 0 && a % v[i] == 0 && c % v[j] == 0) {
                        ans.push_back(v[i]);
                        ans.push_back(v[j]);
                        ans.push_back(c / v[j]);
                    }
                    if (a % v[j] == 0 && b % v[k] == 0 && a % v[k] == 0 && b % v[j] == 0) {
                        ans.push_back(v[j]);
                        ans.push_back(b / v[j]);
                        ans.push_back(a / v[j]);
                    }
                    if (a % v[k] == 0 && b % v[i] == 0 && a % v[i] == 0 && b % v[k] == 0) {
                        ans.push_back(v[i]);
                        ans.push_back(a / v[i]);
                        ans.push_back(v[k]);
                    }
                    if (a % v[k] == 0 && c % v[j] == 0 && a % v[j] == 0 && c % v[k] == 0) {
                        ans.push_back(v[j]);
                        ans.push_back(a / v[j]);
                        ans.push_back(c / v[j]);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        vector<vector<int>> res;
        for (int i = 0; i < ans.size(); i += 3) {
            res.push_back({ans[i], ans[i + 1], ans[i + 2]});
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        cout << res.size() << endl;
    }
    return 0;
}