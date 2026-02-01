#include <iostream>
#include <map>
#include <vector>

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
            ids.push_back(id);
            sales[id] += (long long)p * q;
        }

        vector<int> result;
        for (int id : ids) {
            if (sales[id] >= 1000000) {
                result.push_back(id);
            }
        }

        if (result.empty()) {
            cout << "NA" << endl;
        } else {
            for (int id : result) {
                cout << id << endl;
            }
        }
    }

    return 0;
}