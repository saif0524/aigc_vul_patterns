#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        map<int, long long> sales;
        for (int i = 0; i < n; ++i) {
            int id, price, quantity;
            cin >> id >> price >> quantity;
            sales[id] += (long long)price * quantity;
        }

        vector<int> good_employees;
        for (auto const& [id, total_sales] : sales) {
            if (total_sales >= 1000000) {
                good_employees.push_back(id);
            }
        }

        if (good_employees.empty()) {
            cout << "NA" << endl;
        } else {
            for (int i = 0; i < good_employees.size(); ++i) {
                cout << good_employees[i] << endl;
            }
        }
    }

    return 0;
}