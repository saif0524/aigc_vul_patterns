#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        map<int, long long> sales;
        vector<int> ids;

        for (int i = 0; i < n; i++) {
            int id, p, q;
            cin >> id >> p >> q;

            if (sales.find(id) != sales.end()) {
                sales[id] += (long long)p * q;
            } else {
                sales[id] = (long long)p * q;
                ids.push_back(id);
            }
        }

        bool found = false;
        for (int id : ids) {
            if (sales[id] >= 1000000) {
                cout << id << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "NA" << endl;
        }
    }

    return 0;
}