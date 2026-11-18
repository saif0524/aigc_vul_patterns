#include <bits/stdc++.h>
using namespace std;

multiset<long long> s;

long long findMedian() {
    int n = s.size();
    if (n ==0) return 0;
    auto it = s.begin();
    advance(it, n / 2);
    return *it;
}

long long sumOfMedians() {
    long long sum = 0;
    int n = s.size();
    if (n ==0) return 0;
    vector<long long> v(s.begin(), s.end());
    for (int i = 0; i < n; i += 5) {
        if (i + 4 < n) {
            nth_element(v.begin() + i, v.begin() + i + 2, v.begin() + i + 5);
            sum += v[i +2];
        } else if (i + 3 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 4);
            sum += v[i +1];
        } else if (i + 2 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 3);
            sum += v[i +1];
        } else if (i + 1 < n) {
            nth_element(v.begin() + i, v.begin() + i + 1, v.begin() + i + 2);
            sum += v[i +1];
        } else {
            sum += v[i];
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "add") {
            long long x;
            cin >> x;
            s.insert(x);
        } else if (op == "del") {
            long long x;
            cin >> x;
            s.erase(s.find(x));
        } else if (op == "sum") {
            cout << sumOfMedians() << "\n";
        }
    }
    return 0;
}