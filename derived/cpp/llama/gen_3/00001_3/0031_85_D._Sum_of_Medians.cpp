#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            s.insert(x);
        } else if (op == "del") {
            int x;
            cin >> x;
            s.erase(x);
        } else {
            long long sum = 0;
            int k = 0;
            for (auto it = s.begin(); it!= s.end(); it++) {
                if (k % 5 == 2) {
                    sum += *it;
                }
                k++;
            }
            cout << sum << endl;
        }
    }

    return 0;
}