#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d.begin(), d.end(), [](int x, int y) { return (x / b) > (y / b); });

    int price = a;
    int calories = c;
    int maxCaloriesPerDollar = calories / price;

    for (int i = 0; i < n; i++) {
        price += b;
        calories += d[i];
        maxCaloriesPerDollar = max(maxCaloriesPerDollar, calories / price);
    }

    cout << maxCaloriesPerDollar << endl;

    return 0;
}