#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int x = (i + a[i % n]) % n;
            if (x < 0) x += n;
            s.insert(x);
        }
        cout << (s.size() == n ? "YES" : "NO") << endl;
    }
    return 0;
}