#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
    int n, k;
    cin >> n >> k;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].price >> items[i].type;
        items[i].index = i + 1;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += items[i].price;
    }

    sort(items.begin(), items.end(), compareItems);

    int chairs = 0;
    for (int i = 0; i < n; i++) {
        if (items[i].type == 1) chairs++;
    }

    if (chairs >= k) {
        sum -= items[0].price / 2.0;
        for (int i = 1; i < k; i++) {
            sum -= items[i].price / 2.0;
        }
    } else {
        sum -= items[0].price / 2.0;
        for (int i = 1; i < chairs; i++) {
            sum -= items[i].price / 2.0;
        }
    }

    vector<vector<int>> carts(k);
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (items[j].type == 1) {
                carts[i].push_back(items[j].index);
                items[j].type = 0;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < k - 1; j++) {
            for (int x : carts[j]) {
                if (items[i].index == x) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag == 0) carts[k - 1].push_back(items[i].index);
    }

    cout << fixed << setprecision(1) << sum << endl;
    for (int i = 0; i < k; i++) {
        cout << carts[i].size();
        for (int x : carts[i]) {
            cout << " " << x;
        }
        cout << endl;
    }

    return 0;
}