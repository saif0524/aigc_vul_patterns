#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<int, long long> sales;
        for (int i = 0; i < n; i++) {
            int id, p, q;
            cin >> id >> p >> q;
            sales[id] += (long long)p * q;
        }
        bool printNA = true;
        for (int i = 0; i < n; i++) {
            int id, p, q;
            cin >> id >> p >> q;
            if (sales[id] >= 1000000) {
                cout << id << endl;
                printNA = false;
            }
        }
        if (printNA) {
            cout << "NA" << endl;
        }
    }
    return 0;
}