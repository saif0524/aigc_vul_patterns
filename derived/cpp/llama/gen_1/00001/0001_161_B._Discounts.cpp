#include <bits/stdc++.h>

using namespace std;

struct Item {
    long long price;
    int type;
    int index;
};

bool compareItems(const Item &a, const Item &b) {
    return a.price < b.price;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].price >> items[i].type;
        items[i].index = i + 1;
    }

    sort(items.begin(), items.end(), compareItems);

    vector<vector<int>> carts(k);
    int stools = 0;
    for (const auto &item : items) {
        if (item.type == 1) stools++;
    }

    int cart = 0;
    for (const auto &item : items) {
        if (item.type == 1) {
            carts[cart].push_back(item.index);
            cart = (cart + 1) % k;
        }
    }

    for (const auto &item : items) {
        if (item.type == 2) {
            carts[cart].push_back(item.index);
            cart = (cart + 1) % k;
        }
    }

    long long total = 0;
    for (const auto &cartItems : carts) {
        long long minPrice = LLONG_MAX;
        long long sum = 0;
        for (const auto &itemIndex : cartItems) {
            for (const auto &item : items) {
                if (itemIndex == item.index) {
                    minPrice = min(minPrice, item.price);
                    sum += item.price;
                    break;
                }
            }
        }
        if (!cartItems.empty() && stools >= k) sum -= minPrice / 2;
        total += sum;
    }

    cout << fixed << setprecision(1) << (double)total << '\n';
    for (const auto &cartItems : carts) {
        cout << cartItems.size() << ' ';
        for (const auto &itemIndex : cartItems) {
            cout << itemIndex << ' ';
        }
        cout << '\n';
    }

    return 0;
}