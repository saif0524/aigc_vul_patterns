#include <iostream>
#include <vector>

using namespace std;

int main() {
  int l;
  while (cin >> l && l != 0) {
    vector<pair<int, int>> monthly_data(12);
    for (int i = 0; i < 12; ++i) {
      cin >> monthly_data[i].first >> monthly_data[i].second;
    }

    long long savings = 0;
    int months = 0;
    for (int i = 0; i < 12; ++i) {
      savings += (monthly_data[i].first - monthly_data[i].second);
      months++;
      if (savings >= l) {
        cout << months << endl;
        break;
      }
    }

    if (savings < l) {
      cout << "NA" << endl;
    }
  }

  return 0;
}