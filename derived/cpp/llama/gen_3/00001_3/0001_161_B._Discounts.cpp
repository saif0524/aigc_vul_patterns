#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Item {
    int price;
    int type;
    int index;
};

bool compareItems(const Item& a, const Item& b) {
    return a.price < b.price;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].price >> items[i].type;
        items[i].index = i + 1;
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<int>> carts(k);
    vector<int> stools;
    for (int i = 0; i < n; i++) {
        if (items[i].type == 1) {
            stools.push_back(i);
        }
    }

    for (int i = 0; i < k - 1; i++) {
        if (i < stools.size()) {
            carts[i].push_back(stools[i]);
        }
    }

    if (stools.size() > 0) {
        carts[k - 1].push_back(stools.back());
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (find(stools.begin(), stools.end(), i) == stools.end()) {
            if (j < k - 1) {
                carts[j].push_back(i);
                j++;
            } else {
                carts[k - 1].push_back(i);
            }
        }
    }

    double totalCost = 0.0;
    for (int i = 0; i < k; i++) {
        double minPrice = 1e9;
        for (int item : carts[i]) {
            minPrice = min(minPrice, (double)items[item].price);
        }
        for (int item : carts[i]) {
            if (items[item].price == minPrice && items[item].type == 1) {
                totalCost += items[item].price * 0.5;
                minPrice = -1;
            } else if (minPrice!= -1 && items[item].price == minPrice) {
                totalCost += items[item].price * 0.5;
                minPrice = -1;
            } else {
                totalCost += items[item].price;
            }
        }
    }

    printf("%.1f\n", totalCost);
    for (int i = 0; i < k; i++) {
        cout << carts[i].size();
        for (int item : carts[i]) {
            cout << " " << items[item].index;
        }
        cout << endl;
    }

    return 0;
}