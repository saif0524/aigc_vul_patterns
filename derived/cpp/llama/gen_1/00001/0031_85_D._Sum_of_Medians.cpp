#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s;

    while (n--) {
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            s.push_back(x);
            sort(s.begin(), s.end());
        } else if (op == "del") {
            int x;
            cin >> x;
            s.erase(remove(s.begin(), s.end(), x), s.end());
        } else {
            long long sum = 0;
            for (int i = 2; i < s.size(); i += 5) {
                sum += s[i];
            }
            if (s.size() > 0 && s.size() % 5 == 2) {
                sum += s[s.size() - 1];
            }
            if (s.size() > 0 && s.size() % 5 == 3) {
                sum += s[s.size() - 1];
            }
            if (s.size() > 0 && s.size() % 5 == 4) {
                sum += s[s.size() - 1];
            }
            cout << sum << endl;
        }
    }

    return 0;
}