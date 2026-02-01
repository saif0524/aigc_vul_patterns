#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    long long a, b;
};

bool compare(const Product& p1, const Product& p2) {
    return p1.b < p2.b;
}

int main() {
    int n;
    cin >> n;

    vector<Product> products(n);
    for (int i = 0; i < n; i++) {
        cin >> products[i].a >> products[i].b;
    }

    sort(products.begin(), products.end(), compare);

    long long total = 0;
    long long bought = 0;

    for (int i = 0; i < n; i++) {
        long long needToBuy = max(0LL, products[i].b - bought);
        total += needToBuy * 2;
        bought += needToBuy;

        long long buyWithDiscount = min(products[i].a, products[i].b - needToBuy);
        total += buyWithDiscount;
        bought += buyWithDiscount;
        products[i].a -= buyWithDiscount;

        total += products[i].a * 2;
        bought += products[i].a;
    }

    cout << total << endl;

    return 0;
}