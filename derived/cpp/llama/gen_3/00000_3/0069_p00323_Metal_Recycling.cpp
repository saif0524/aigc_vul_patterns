#include <iostream>
#include <map>

using namespace std;

map<int, int> group;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int w = a * (1 << b);
        group[w]++;
    }

    for (auto& it : group) {
        while (it.second > 0) {
            int w = it.first;
            int cnt = min(it.second, (1 << 20));
            it.second -= cnt;

            int log = 0;
            while ((1 << (log + 1)) <= (w / cnt)) log++;

            int b = w / cnt / (1 << log);
            int a = (1 << log);
            cout << a * b << " " << log << endl;
        }
    }

    return 0;
}