#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Server {
    int index;
    int capacity;
};

bool compare(const Server& a, const Server& b) {
    return a.capacity > b.capacity;
}

int main() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<Server> servers(n);
    for (int i = 0; i < n; ++i) {
        cin >> servers[i].capacity;
        servers[i].index = i + 1;
    }

    sort(servers.begin(), servers.end(), compare);

    for (int i = 1; i <= n; ++i) {
        int k1 = i;
        double x1r = (double)x1 / k1;
        if (x1 % k1!= 0) {
            x1r = (double)x1 / k1;
        }

        int k2 = 0;
        int x2r = 0;
        int idx = i;
        while (idx < n && k2 * x2 < x2) {
            if (servers[idx].capacity >= x2 / (k2 + 1)) {
                k2++;
            }
            idx++;
        }

        if (k2 * x2 < x2) {
            continue;
        }

        int j = 0;
        bool ok = true;
        while (j < i && ok) {
            ok = servers[j].capacity >= x1r;
            j++;
        }

        if (!ok) {
            continue;
        }

        cout << "Yes" << endl;
        cout << k1 << " " << k2 << endl;

        for (int a = 0; a < k1; ++a) {
            cout << servers[a].index << " ";
        }
        cout << endl;

        for (int a = i; a < i + k2; ++a) {
            cout << servers[a].index << " ";
        }
        cout << endl;

        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        int k2 = i;
        double x2r = (double)x2 / k2;
        if (x2 % k2!= 0) {
            x2r = (double)x2 / k2;
        }

        int k1 = 0;
        int x1r = 0;
        int idx = i;
        while (idx < n && k1 * x1 < x1) {
            if (servers[idx].capacity >= x1 / (k1 + 1)) {
                k1++;
            }
            idx++;
        }

        if (k1 * x1 < x1) {
            continue;
        }

        int j = 0;
        bool ok = true;
        while (j < i && ok) {
            ok = servers[j].capacity >= x2r;
            j++;
        }

        if (!ok) {
            continue;
        }

        cout << "Yes" << endl;
        cout << k1 << " " << k2 << endl;

        for (int a = i; a < i + k1; ++a) {
            cout << servers[a].index << " ";
        }
        cout << endl;

        for (int a = 0; a < k2; ++a) {
            cout << servers[a].index << " ";
        }
        cout << endl;

        return 0;
    }

    cout << "No" << endl;

    return 0;
}