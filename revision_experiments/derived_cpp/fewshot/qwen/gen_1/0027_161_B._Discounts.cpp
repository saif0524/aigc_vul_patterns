#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long cost;
    int type;
    int index;
};

bool compareItems(const Item &a, const Item &b) {
    return a.cost < b.cost;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].cost >> items[i].type;
        items[i].index = i + 1;
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<int>> carts(k);
    vector<bool> used(n, false);
    int stoolCount = 0;

    // First pass to ensure each cart has at least one stool if possible
    for (int i = 0; i < n && stoolCount < k; ++i) {
        if (items[i].type == 1) {
            carts[stoolCount].push_back(items[i].index);
            used[i] = true;
            stoolCount++;
        }
    }

    // Distribute remaining items
    int cartIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            carts[cartIndex].push_back(items[i].index);
            cartIndex = (cartIndex + 1) % k;
        }
    }

    // Calculate the total cost with discounts
    double totalCost = 0.0;
    for (int i = 0; i < k; ++i) {
        long long minCost = LLONG_MAX;
        bool hasStool = false;
        for (int index : carts[i]) {
            int itemIndex = index - 1;
            if (items[itemIndex].type == 1) {
                hasStool = true;
            }
            minCost = min(minCost, items[itemIndex].cost);
        }
        if (hasStool) {
            totalCost += (minCost / 2.0);
        } else {
            totalCost += minCost;
        }
        for (int j = 1; j < carts[i].size(); ++j) {
            int itemIndex = carts[i][j] - 1;
            totalCost += items[itemIndex].cost;
        }
    }

    cout << fixed << setprecision(1) << totalCost << endl;

    for (const auto &cart : carts) {
        cout << cart.size();
        for (int index : cart) {
            cout << " " << index;
        }
        cout << endl;
    }

    return 0;
}